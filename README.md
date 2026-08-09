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

## Byte-exact rebuild workflow

The included scripts do not compile the Ghidra pseudocode. They generate byte-preserving GNU Arm assembly from a user-supplied stock OTA package, assemble both fixed-size MCU images, rebuild all four checksums and verify that the untouched result is identical to stock.

Requirements:

- Windows PowerShell
- Python 3
- the researched stock OTA package
- internet access for the pinned Arm GNU Toolchain download

Place your own stock package at `firmware/stock.bin`, or pass its path using `-Firmware`.

First verify the package:

```powershell
python .\tools\verify_mi5.py .\firmware\stock.bin
```

Install the checksum-pinned Arm toolchain and generate the persistent assembly sources once:

```powershell
.\tools\setup_arm_toolchain.ps1
.\tools\prepare_reassembly.ps1 -Firmware .\firmware\stock.bin
```

Then perform the strict byte-exact stock round trip:

```powershell
.\tools\build_reassembly.ps1 -Firmware .\firmware\stock.bin -VerifyStock
```

The expected result is a 141,312-byte package with SHA-256 `58cacc6170cad20718894a439df77e0d54f9262410eecec436fb15ef1ed7673b`. Generated assembly, objects, ELFs and firmware packages are written under `generated/` and excluded from Git.

If the Arm toolchain is already installed elsewhere, pass its `bin` directory with `-ToolchainDirectory` instead of running the setup script.

Normal build mode accepts intentional fixed-size assembly edits:

```powershell
.\tools\build_reassembly.ps1 -Firmware .\firmware\stock.bin
```

A successful build only proves the container layout, vector tables, image lengths and checksums are mechanically valid. It does not prove that edited firmware is accepted by the updater or safe to run. This repository does not provide a flashing method.

## Safety and legal notice

This material is provided only as a static research reference. Do not use it to operate a modified vehicle. Follow local laws and review [`NOTICE.md`](NOTICE.md) before publishing or redistributing these manufacturer-firmware derivatives.
