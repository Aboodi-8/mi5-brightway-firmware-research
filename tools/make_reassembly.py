#!/usr/bin/env python3
"""Generate byte-exact, reassemblable GNU Arm source for both Mi5 images."""

from __future__ import annotations

import argparse
import csv
from pathlib import Path
import re
import sys

from mi5fw import (
    atomic_write_bytes,
    FirmwareFormatError,
    parse_int,
    require_distinct_paths,
    require_known_stock,
    sha256,
)


LABEL_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")


def read_labels(path: Path, base: int, size: int) -> dict[int, list[tuple[str, str, str]]]:
    labels: dict[int, list[tuple[str, str, str]]] = {}
    with path.open("r", encoding="utf-8", newline="") as handle:
        for row in csv.DictReader(line for line in handle if not line.startswith("#")):
            address = parse_int(row["address"])
            if not base <= address < base + size:
                continue
            name = row["name"].strip()
            if not LABEL_RE.fullmatch(name):
                raise ValueError(f"invalid assembler label {name!r}")
            labels.setdefault(address - base, []).append(
                (name, row["kind"].strip(), row.get("comment", "").strip())
            )
    return labels


def emit_bytes(lines: list[str], payload: bytes, start: int, end: int) -> None:
    for offset in range(start, end, 16):
        chunk = payload[offset : min(offset + 16, end)]
        values = ", ".join(f"0x{byte:02x}" for byte in chunk)
        lines.append(f"    .byte {values}")


def generate(
    payload: bytes,
    *,
    image: str,
    base: int,
    cpu: str,
    fpu: str | None,
    annotations: Path,
    output: Path,
    force: bool,
) -> None:
    labels = read_labels(annotations, base, len(payload))
    labels.setdefault(0, []).insert(0, (f"mi5_{image}_image_start", "data", "Image start"))
    boundaries = sorted(set(labels) | {len(payload)})

    lines = [
        "/*",
        " * Byte-exact GNU Arm reassembly generated from the verified stock image.",
        " * This preserves bytes and useful labels; it is not recovered manufacturer source.",
        f" * Raw SHA-256: {sha256(payload)}",
        " */",
        ".syntax unified",
        f".cpu {cpu}",
    ]
    if fpu is not None:
        lines.append(f".fpu {fpu}")
    lines.extend(
        [
            ".thumb",
            '.section .firmware, "ax", %progbits',
            ".balign 4",
            "",
        ]
    )

    cursor = 0
    for boundary in boundaries:
        emit_bytes(lines, payload, cursor, boundary)
        if boundary == len(payload):
            break
        lines.append("")
        for name, kind, comment in labels[boundary]:
            if comment:
                lines.append(f"/* {comment.replace('*/', '* /')} */")
            lines.append(f".global {name}")
            if kind == "function":
                lines.append(f".type {name}, %function")
                lines.append(".thumb_func")
            else:
                lines.append(f".type {name}, %object")
            lines.append(f"{name}:")
        cursor = boundary

    lines.extend(
        [
            "",
            f".global mi5_{image}_image_end",
            f"mi5_{image}_image_end:",
            f".size mi5_{image}_image_start, . - mi5_{image}_image_start",
            "",
        ]
    )
    atomic_write_bytes(
        output,
        "\n".join(lines).encode("utf-8"),
        force=force,
    )


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("firmware", type=Path, help="known-good Mi5 package")
    parser.add_argument("output", type=Path, help="output directory")
    parser.add_argument(
        "--annotations",
        type=Path,
        default=Path(__file__).resolve().parents[1] / "annotations",
    )
    parser.add_argument(
        "--allow-unknown",
        action="store_true",
        help="accept a checksum-valid package other than the researched stock SHA-256",
    )
    parser.add_argument("--force", action="store_true", help="replace existing sources")
    args = parser.parse_args()

    data = args.firmware.read_bytes()
    layout = require_known_stock(data, allow_unknown=args.allow_unknown)
    primary = data[layout.primary_payload_offset : layout.primary_payload_end]
    secondary = data[layout.secondary_payload_offset : layout.secondary_payload_end]

    primary_output = args.output / "mi5_primary_byte_exact.S"
    secondary_output = args.output / "mi5_secondary_byte_exact.S"
    require_distinct_paths(
        {
            "firmware": args.firmware,
            "primary source": primary_output,
            "secondary source": secondary_output,
        }
    )
    for output in (primary_output, secondary_output):
        if output.exists() and not args.force:
            parser.error(f"source already exists: {output} (use --force to replace it)")

    generate(
        primary,
        image="primary",
        base=layout.primary_runtime_base,
        cpu="cortex-m4",
        fpu="fpv4-sp-d16",
        annotations=args.annotations / "primary_symbols.csv",
        output=primary_output,
        force=args.force,
    )
    generate(
        secondary,
        image="secondary",
        base=layout.secondary_runtime_base,
        cpu="cortex-m0",
        fpu=None,
        annotations=args.annotations / "secondary_symbols.csv",
        output=secondary_output,
        force=args.force,
    )
    print(f"generated byte-exact GNU Arm sources in {args.output}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (FirmwareFormatError, OSError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        raise SystemExit(2)
