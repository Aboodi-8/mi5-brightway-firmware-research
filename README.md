# Xiaomi Electric Scooter 5 MCU decompiled reference

This repository contains static Ghidra exports from one Xiaomi Electric Scooter 5 Brightway MCU firmware package.

Exact researched firmware SHA-256:

```text
58cacc6170cad20718894a439df77e0d54f9262410eecec436fb15ef1ed7673b
```

## Files

- [`mi5_secondary_decompiled.c`](mi5_secondary_decompiled.c) — C-like pseudocode for the LKS32 motor-control MCU.
- [`mi5_secondary_disassembly.lst`](mi5_secondary_disassembly.lst) — exact secondary instruction listing.
- [`mi5_secondary_functions.csv`](mi5_secondary_functions.csv) — discovered secondary functions and research labels.
- [`mi5_primary_decompiled.c`](mi5_primary_decompiled.c) — C-like pseudocode for the supervisory MCU.
- [`mi5_primary_disassembly.lst`](mi5_primary_disassembly.lst) — exact primary instruction listing.
- [`mi5_primary_functions.csv`](mi5_primary_functions.csv) — discovered primary functions and research labels.

The secondary image contains the motor-control peripherals and control loop. The primary image appears to handle battery/SOC estimation, communications, storage and firmware updating.

## Important limitations

The `.c` files are machine-generated pseudocode, not the manufacturer's original source and not directly recompilable. Ghidra cannot recover original names, types, structures, macros, comments or compiler decisions. Check the matching disassembly before relying on pseudocode behavior.

This repository intentionally contains no firmware binaries, patched firmware, flashing tools, patchers, speed/current modifications, region bypasses or safety-protection bypasses.

## Safety and legal notice

This material is provided only as a static research reference. Do not use it to operate a modified vehicle. Follow local laws and review [`NOTICE.md`](NOTICE.md) before publishing or redistributing these manufacturer-firmware derivatives.
