#!/usr/bin/env python3
"""Validate a Mi5 MCU package and print its exact image/checksum map."""

from __future__ import annotations

import argparse
from pathlib import Path
import sys

from mi5fw import FirmwareFormatError, KNOWN_STOCK_SHA256, check_all, parse_layout, sha256


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("firmware", type=Path)
    args = parser.parse_args()

    data = args.firmware.read_bytes()
    layout = parse_layout(data)
    results = check_all(data, layout)

    print(f"file size: 0x{len(data):X}")
    digest = sha256(data)
    print(f"SHA-256: {digest}")
    print(f"known researched stock: {'yes' if digest == KNOWN_STOCK_SHA256 else 'NO'}")
    if digest != KNOWN_STOCK_SHA256:
        print(
            "warning: structural/checksum results do not prove that stock-specific "
            "addresses or annotations apply to this candidate"
        )
    print(
        f"primary: file 0x{layout.primary_payload_offset:X}..0x{layout.primary_payload_end - 1:X}, "
        f"runtime 0x{layout.primary_runtime_base:08X}"
    )
    print(
        f"secondary: file 0x{layout.secondary_payload_offset:X}..0x{layout.secondary_payload_end - 1:X}, "
        f"runtime 0x{layout.secondary_runtime_base:08X}"
    )
    for result in results:
        print(
            f"{result.name}: {'OK' if result.ok else 'FAIL'} "
            f"(stored {result.stored}, computed {result.computed})"
        )
    return 0 if all(result.ok for result in results) else 1


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (FirmwareFormatError, OSError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        raise SystemExit(2)
