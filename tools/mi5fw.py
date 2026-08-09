"""Validation and byte-exact rebuilding for the researched Mi5 MCU OTA."""

from __future__ import annotations

from dataclasses import dataclass
import binascii
import hashlib
import os
from pathlib import Path
import struct
import tempfile


PRIMARY_MAGIC = b"DEPRD5C\x00"
SECONDARY_TAG = b"LKS32MC071CBT8FF"
GLOBAL_HEADER_SIZE = 0x800
PRIMARY_LOCAL_HEADER_SIZE = 0x800
SECONDARY_LOCAL_HEADER_SIZE = 0x18
PRIMARY_RUNTIME_BASE = 0x08003000
SECONDARY_RUNTIME_BASE = 0x00002800
PRIMARY_VECTOR_COUNT = 82
SECONDARY_VECTOR_COUNT = 48
KNOWN_STOCK_SHA256 = "58cacc6170cad20718894a439df77e0d54f9262410eecec436fb15ef1ed7673b"


class FirmwareFormatError(ValueError):
    pass


@dataclass(frozen=True)
class Layout:
    file_size: int
    global_body_size: int
    primary_block_size: int
    secondary_block_size: int
    primary_block_offset: int
    primary_payload_offset: int
    primary_payload_size: int
    secondary_block_offset: int
    secondary_payload_offset: int
    secondary_payload_size: int
    secondary_trailer_size: int
    primary_runtime_base: int = PRIMARY_RUNTIME_BASE
    secondary_runtime_base: int = SECONDARY_RUNTIME_BASE

    @property
    def primary_payload_end(self) -> int:
        return self.primary_payload_offset + self.primary_payload_size

    @property
    def primary_block_end(self) -> int:
        return self.primary_block_offset + self.primary_block_size

    @property
    def secondary_payload_end(self) -> int:
        return self.secondary_payload_offset + self.secondary_payload_size

    @property
    def secondary_block_end(self) -> int:
        return self.secondary_block_offset + self.secondary_block_size


@dataclass(frozen=True)
class CheckResult:
    name: str
    ok: bool
    stored: str
    computed: str


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def crc16_xmodem(data: bytes) -> int:
    return binascii.crc_hqx(data, 0)


def crc32_mpeg2(data: bytes, pad_byte: int = 0xFF) -> int:
    pad_len = (-len(data)) % 4
    if pad_len:
        data += bytes([pad_byte]) * pad_len

    crc = 0xFFFFFFFF
    for byte in data:
        crc ^= byte << 24
        for _ in range(8):
            if crc & 0x80000000:
                crc = ((crc << 1) ^ 0x04C11DB7) & 0xFFFFFFFF
            else:
                crc = (crc << 1) & 0xFFFFFFFF
    return crc


def _u16be(data: bytes, offset: int) -> int:
    return struct.unpack_from(">H", data, offset)[0]


def _u24be(data: bytes, offset: int) -> int:
    return int.from_bytes(data[offset : offset + 3], "big")


def _u32be(data: bytes, offset: int) -> int:
    return struct.unpack_from(">I", data, offset)[0]


def _u32le(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def _validate_vector(
    data: bytes,
    offset: int,
    name: str,
    ram_start: int,
    ram_end: int,
    runtime_base: int,
    image_size: int,
    vector_count: int,
) -> None:
    stack_pointer, reset_vector = struct.unpack_from("<II", data, offset)
    if not ram_start < stack_pointer <= ram_end:
        raise FirmwareFormatError(
            f"{name} initial SP 0x{stack_pointer:08X} is outside expected RAM"
        )
    if stack_pointer % 8:
        raise FirmwareFormatError(
            f"{name} initial SP 0x{stack_pointer:08X} is not 8-byte aligned"
        )
    if not reset_vector & 1:
        raise FirmwareFormatError(f"{name} reset vector is not a Thumb address")
    reset_target = reset_vector & ~1
    if not runtime_base <= reset_target < runtime_base + image_size:
        raise FirmwareFormatError(
            f"{name} reset target 0x{reset_target:08X} lies outside its image"
        )

    for index in range(2, vector_count):
        vector = _u32le(data, offset + index * 4)
        if vector == 0:
            continue
        if not vector & 1:
            raise FirmwareFormatError(
                f"{name} vector {index} is not a Thumb address: 0x{vector:08X}"
            )
        target = vector & ~1
        if not runtime_base <= target < runtime_base + image_size:
            raise FirmwareFormatError(
                f"{name} vector {index} target 0x{target:08X} lies outside its image"
            )


def parse_layout(data: bytes) -> Layout:
    minimum = GLOBAL_HEADER_SIZE + PRIMARY_LOCAL_HEADER_SIZE + SECONDARY_LOCAL_HEADER_SIZE
    if len(data) < minimum:
        raise FirmwareFormatError("file is too short to contain the Mi5 OTA structure")

    global_body_size = _u32be(data, 0x00)
    secondary_block_size = _u16be(data, 0x08)
    primary_block_size = _u32be(data, 0x0C)
    primary_block_offset = GLOBAL_HEADER_SIZE
    secondary_block_offset = primary_block_offset + primary_block_size
    expected_size = GLOBAL_HEADER_SIZE + primary_block_size + secondary_block_size

    if expected_size != len(data):
        raise FirmwareFormatError(
            f"block sizes imply 0x{expected_size:X} bytes, file has 0x{len(data):X}"
        )
    if global_body_size != len(data) - GLOBAL_HEADER_SIZE:
        raise FirmwareFormatError("global body size does not match the package length")
    if data[primary_block_offset : primary_block_offset + len(PRIMARY_MAGIC)] != PRIMARY_MAGIC:
        raise FirmwareFormatError("primary DEPRD5C marker is missing")

    primary_payload_size = _u24be(data, primary_block_offset + 0x08)
    primary_payload_offset = primary_block_offset + PRIMARY_LOCAL_HEADER_SIZE
    if primary_payload_size < PRIMARY_VECTOR_COUNT * 4:
        raise FirmwareFormatError("primary payload is too short for its vector table")
    if primary_payload_offset + primary_payload_size != secondary_block_offset:
        raise FirmwareFormatError("primary payload does not end at the secondary block")

    tag_start = secondary_block_offset + 0x08
    if data[tag_start : tag_start + len(SECONDARY_TAG)] != SECONDARY_TAG:
        raise FirmwareFormatError("secondary LKS32 tag is missing")

    secondary_payload_size = _u32le(data, secondary_block_offset)
    secondary_payload_offset = secondary_block_offset + SECONDARY_LOCAL_HEADER_SIZE
    secondary_payload_end = secondary_payload_offset + secondary_payload_size
    secondary_block_end = secondary_block_offset + secondary_block_size
    if secondary_payload_size < SECONDARY_VECTOR_COUNT * 4:
        raise FirmwareFormatError("secondary payload is too short for its vector table")
    if secondary_payload_end > secondary_block_end:
        raise FirmwareFormatError("secondary payload exceeds its fixed-size block")

    layout = Layout(
        file_size=len(data),
        global_body_size=global_body_size,
        primary_block_size=primary_block_size,
        secondary_block_size=secondary_block_size,
        primary_block_offset=primary_block_offset,
        primary_payload_offset=primary_payload_offset,
        primary_payload_size=primary_payload_size,
        secondary_block_offset=secondary_block_offset,
        secondary_payload_offset=secondary_payload_offset,
        secondary_payload_size=secondary_payload_size,
        secondary_trailer_size=secondary_block_end - secondary_payload_end,
    )

    _validate_vector(
        data,
        layout.primary_payload_offset,
        "primary",
        0x20000000,
        0x20005000,
        layout.primary_runtime_base,
        layout.primary_payload_size,
        PRIMARY_VECTOR_COUNT,
    )
    _validate_vector(
        data,
        layout.secondary_payload_offset,
        "secondary",
        0x20000000,
        0x20003000,
        layout.secondary_runtime_base,
        layout.secondary_payload_size,
        SECONDARY_VECTOR_COUNT,
    )
    return layout


def check_all(data: bytes, layout: Layout | None = None) -> list[CheckResult]:
    layout = layout or parse_layout(data)
    primary_payload = data[layout.primary_payload_offset : layout.primary_payload_end]
    primary_block = data[layout.primary_block_offset : layout.primary_block_end]
    secondary_payload = data[layout.secondary_payload_offset : layout.secondary_payload_end]
    secondary_block = data[layout.secondary_block_offset : layout.secondary_block_end]
    values = [
        (
            "primary_payload_crc16",
            _u16be(data, layout.primary_block_offset + 0x0B),
            crc16_xmodem(primary_payload),
            4,
        ),
        ("primary_block_crc16", _u16be(data, 0x10), crc16_xmodem(primary_block), 4),
        (
            "secondary_payload_crc32",
            _u32le(data, layout.secondary_block_offset + 0x04),
            crc32_mpeg2(secondary_payload),
            8,
        ),
        ("secondary_block_crc16", _u16be(data, 0x0A), crc16_xmodem(secondary_block), 4),
    ]
    return [
        CheckResult(name, stored == computed, f"{stored:0{width}X}", f"{computed:0{width}X}")
        for name, stored, computed, width in values
    ]


def require_valid(data: bytes, layout: Layout | None = None) -> Layout:
    parsed_layout = parse_layout(data)
    if layout is not None and layout != parsed_layout:
        raise FirmwareFormatError("supplied layout does not match the current package")
    failures = [result for result in check_all(data, parsed_layout) if not result.ok]
    if failures:
        details = ", ".join(
            f"{item.name}: stored {item.stored}, computed {item.computed}"
            for item in failures
        )
        raise FirmwareFormatError(f"checksum validation failed ({details})")
    return parsed_layout


def require_known_stock(data: bytes, *, allow_unknown: bool = False) -> Layout:
    layout = require_valid(data)
    actual_sha = sha256(data)
    if not allow_unknown and actual_sha != KNOWN_STOCK_SHA256:
        raise FirmwareFormatError(
            f"expected researched stock SHA-256 {KNOWN_STOCK_SHA256}; input is {actual_sha}"
        )
    return layout


def rebuild(
    original: bytes,
    *,
    primary_payload: bytes | None = None,
    secondary_payload: bytes | None = None,
) -> bytes:
    layout = require_valid(original)
    output = bytearray(original)

    if primary_payload is not None:
        if len(primary_payload) != layout.primary_payload_size:
            raise FirmwareFormatError(
                f"primary payload must remain exactly 0x{layout.primary_payload_size:X} bytes"
            )
        output[layout.primary_payload_offset : layout.primary_payload_end] = primary_payload
        struct.pack_into(
            ">H",
            output,
            layout.primary_block_offset + 0x0B,
            crc16_xmodem(primary_payload),
        )
        primary_block = bytes(output[layout.primary_block_offset : layout.primary_block_end])
        struct.pack_into(">H", output, 0x10, crc16_xmodem(primary_block))

    if secondary_payload is not None:
        if len(secondary_payload) != layout.secondary_payload_size:
            raise FirmwareFormatError(
                f"secondary payload must remain exactly 0x{layout.secondary_payload_size:X} bytes"
            )
        output[layout.secondary_payload_offset : layout.secondary_payload_end] = secondary_payload
        struct.pack_into(
            "<I",
            output,
            layout.secondary_block_offset + 0x04,
            crc32_mpeg2(secondary_payload),
        )
        secondary_block = bytes(output[layout.secondary_block_offset : layout.secondary_block_end])
        struct.pack_into(">H", output, 0x0A, crc16_xmodem(secondary_block))

    rebuilt = bytes(output)
    require_valid(rebuilt)
    return rebuilt


def parse_int(value: int | str) -> int:
    if isinstance(value, bool):
        raise FirmwareFormatError("boolean values are not valid addresses")
    if isinstance(value, int):
        return value
    if not isinstance(value, str):
        raise FirmwareFormatError("address values must be integers or base-prefixed strings")
    try:
        return int(value, 0)
    except ValueError as exc:
        raise FirmwareFormatError(f"invalid integer value {value!r}") from exc


def require_distinct_paths(paths: dict[str, Path]) -> None:
    seen: dict[str, tuple[str, Path]] = {}
    for label, path in paths.items():
        resolved = path.expanduser().resolve(strict=False)
        key = os.path.normcase(str(resolved))
        if key in seen:
            previous_label, previous_path = seen[key]
            raise FirmwareFormatError(
                f"{label} path {path} aliases {previous_label} path {previous_path}"
            )
        seen[key] = (label, path)


def atomic_write_bytes(path: Path, data: bytes, *, force: bool = False) -> None:
    target = path.expanduser().resolve(strict=False)
    target.parent.mkdir(parents=True, exist_ok=True)
    if target.exists() and not force:
        raise FirmwareFormatError(f"output already exists: {target} (use --force to replace it)")
    if target.exists() and target.is_dir():
        raise FirmwareFormatError(f"output path is a directory: {target}")

    temporary_name: str | None = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="wb",
            prefix=f".{target.name}.",
            suffix=".tmp",
            dir=target.parent,
            delete=False,
        ) as handle:
            temporary_name = handle.name
            handle.write(data)
            handle.flush()

        if force:
            os.replace(temporary_name, target)
        else:
            try:
                if os.name == "nt":
                    os.rename(temporary_name, target)
                else:
                    os.link(temporary_name, target)
            except FileExistsError as exc:
                raise FirmwareFormatError(f"output appeared while building: {target}") from exc
            if os.name != "nt":
                Path(temporary_name).unlink()
        temporary_name = None
    finally:
        if temporary_name is not None:
            try:
                Path(temporary_name).unlink()
            except FileNotFoundError:
                pass
