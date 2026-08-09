#!/usr/bin/env python3
"""Losslessly rebuild a Mi5 MCU package from fixed-size executable images."""

from __future__ import annotations

import argparse
from pathlib import Path
import sys

from mi5fw import (
    atomic_write_bytes,
    check_all,
    FirmwareFormatError,
    rebuild,
    require_distinct_paths,
    require_known_stock,
    require_valid,
    sha256,
)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path, help="known-good original package used as container")
    parser.add_argument("output", type=Path, help="rebuilt package path")
    parser.add_argument("--primary", type=Path, help="replacement ARMv7E-M-class raw image")
    parser.add_argument("--secondary", type=Path, help="replacement LKS32 Cortex-M0 raw image")
    parser.add_argument(
        "--allow-unknown-base",
        action="store_true",
        help="accept a checksum-valid base other than the researched stock SHA-256",
    )
    parser.add_argument("--force", action="store_true", help="replace an existing output")
    args = parser.parse_args()

    paths = {"original": args.original, "output": args.output}
    if args.primary:
        paths["primary replacement"] = args.primary
    if args.secondary:
        paths["secondary replacement"] = args.secondary
    require_distinct_paths(paths)

    original = args.original.read_bytes()
    require_known_stock(original, allow_unknown=args.allow_unknown_base)
    primary = args.primary.read_bytes() if args.primary else None
    secondary = args.secondary.read_bytes() if args.secondary else None
    output = rebuild(original, primary_payload=primary, secondary_payload=secondary)
    require_valid(output)
    atomic_write_bytes(args.output, output, force=args.force)

    print(f"input SHA-256:  {sha256(original)}")
    print(f"output SHA-256: {sha256(output)}")
    for item in check_all(output):
        print(f"{item.name}: {'OK' if item.ok else 'FAIL'} ({item.computed})")
    if output == original:
        print("round trip: byte-identical")
    else:
        print("round trip: modified, checksums rebuilt")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (FirmwareFormatError, OSError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        raise SystemExit(2)
