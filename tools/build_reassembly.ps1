param(
    [string]$Firmware = '',
    [string]$SourceDirectory = '',
    [string]$OutputDirectory = '',
    [string]$ToolchainDirectory = '',
    [switch]$VerifyStock,
    [switch]$AllowUnknownBase
)

$ErrorActionPreference = 'Stop'
$ResearchRoot = Split-Path -Parent $PSScriptRoot
$WorkspaceRoot = $ResearchRoot

if ([string]::IsNullOrWhiteSpace($Firmware)) {
    $Firmware = Join-Path $ResearchRoot 'firmware\stock.bin'
}
$Firmware = (Resolve-Path -LiteralPath $Firmware -ErrorAction Stop).Path
if ($VerifyStock -and $AllowUnknownBase) {
    throw '-VerifyStock and -AllowUnknownBase cannot be used together.'
}

if ([string]::IsNullOrWhiteSpace($SourceDirectory)) {
    $SourceDirectory = Join-Path $ResearchRoot 'generated\reassembly\sources'
}
else {
    $SourceDirectory = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath(
        $SourceDirectory
    )
}
if ([string]::IsNullOrWhiteSpace($OutputDirectory)) {
    $OutputDirectory = Join-Path $ResearchRoot 'generated\reassembly\build'
}
else {
    $OutputDirectory = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath(
        $OutputDirectory
    )
}

$PrimarySource = Join-Path $SourceDirectory 'mi5_primary_byte_exact.S'
$SecondarySource = Join-Path $SourceDirectory 'mi5_secondary_byte_exact.S'
foreach ($Source in @($PrimarySource, $SecondarySource)) {
    if (-not (Test-Path -LiteralPath $Source -PathType Leaf)) {
        throw "Persistent source is missing: $Source. Run tools\prepare_reassembly.ps1 once before building."
    }
}

$Python = Join-Path $ResearchRoot '.venv\Scripts\python.exe'
if (-not (Test-Path -LiteralPath $Python -PathType Leaf)) {
    $Python = (Get-Command python -ErrorAction Stop).Source
}

if ([string]::IsNullOrWhiteSpace($ToolchainDirectory)) {
    $Toolchain = Join-Path $WorkspaceRoot '.analysis_deps\arm-gnu-toolchain-15.2.rel1\bin'
}
else {
    $Toolchain = (Resolve-Path -LiteralPath $ToolchainDirectory -ErrorAction Stop).Path
}
$Gcc = Join-Path $Toolchain 'arm-none-eabi-gcc.exe'
$Objcopy = Join-Path $Toolchain 'arm-none-eabi-objcopy.exe'
$Objdump = Join-Path $Toolchain 'arm-none-eabi-objdump.exe'
foreach ($Tool in @($Gcc, $Objcopy, $Objdump)) {
    if (-not (Test-Path -LiteralPath $Tool -PathType Leaf)) {
        throw "Arm GNU Toolchain component is missing: $Tool. Run tools\setup_arm_toolchain.ps1 first."
    }
}

$KnownStockSha256 = '58cacc6170cad20718894a439df77e0d54f9262410eecec436fb15ef1ed7673b'
$KnownPrimarySha256 = '20e93739448e9db26db04a0141239de9b81a686538a470d067b659ec21659371'
$KnownSecondarySha256 = 'f44409bb6e326a770c9173baba66c437000e62e1dff159b8d23e76cba039d08a'

function Assert-Sha256([string]$Path, [string]$Expected, [string]$Name) {
    $Actual = (Get-FileHash -Algorithm SHA256 -LiteralPath $Path).Hash.ToLowerInvariant()
    if ($Actual -ne $Expected) {
        throw "$Name SHA-256 differs: expected $Expected, got $Actual"
    }
    Write-Host "$Name SHA-256 matches stock ($Actual)"
}

function Assert-ByteEqual([string]$Expected, [string]$Actual, [string]$Name) {
    $ExpectedBytes = [System.IO.File]::ReadAllBytes($Expected)
    $ActualBytes = [System.IO.File]::ReadAllBytes($Actual)
    if ($ExpectedBytes.Length -ne $ActualBytes.Length) {
        throw "$Name length differs: $($ExpectedBytes.Length) versus $($ActualBytes.Length)"
    }
    for ($Index = 0; $Index -lt $ExpectedBytes.Length; $Index++) {
        if ($ExpectedBytes[$Index] -ne $ActualBytes[$Index]) {
            throw "$Name differs at raw offset 0x$($Index.ToString('X'))"
        }
    }
    Write-Host "$Name is byte-identical ($($ExpectedBytes.Length) bytes)"
}

function Assert-DistinctBuildPaths([hashtable]$Paths) {
    $Seen = @{}
    foreach ($Entry in $Paths.GetEnumerator()) {
        $FullPath = [System.IO.Path]::GetFullPath([string]$Entry.Value)
        $Key = $FullPath.ToLowerInvariant()
        if ($Seen.ContainsKey($Key)) {
            throw "$($Entry.Key) path aliases $($Seen[$Key]): $FullPath"
        }
        $Seen[$Key] = $Entry.Key
    }
}

if ($VerifyStock) {
    Assert-Sha256 $Firmware $KnownStockSha256 'input OTA package'
}

$PrimaryObject = Join-Path $OutputDirectory 'mi5_primary.o'
$SecondaryObject = Join-Path $OutputDirectory 'mi5_secondary.o'
$PrimaryElf = Join-Path $OutputDirectory 'mi5_primary.elf'
$SecondaryElf = Join-Path $OutputDirectory 'mi5_secondary.elf'
$PrimaryBin = Join-Path $OutputDirectory 'mi5_primary_reassembled.bin'
$SecondaryBin = Join-Path $OutputDirectory 'mi5_secondary_reassembled.bin'
$PrimaryDisassemblyPath = Join-Path $OutputDirectory 'mi5_primary_objdump.lst'
$SecondaryDisassemblyPath = Join-Path $OutputDirectory 'mi5_secondary_objdump.lst'
$ReassembledPackage = Join-Path $OutputDirectory 'mi5_full_package_reassembled.bin'
$PrimaryLinker = Join-Path $ResearchRoot 'rebuild\primary.ld'
$SecondaryLinker = Join-Path $ResearchRoot 'rebuild\secondary.ld'

Assert-DistinctBuildPaths @{
    Firmware = $Firmware
    PrimarySource = $PrimarySource
    SecondarySource = $SecondarySource
    PrimaryLinker = $PrimaryLinker
    SecondaryLinker = $SecondaryLinker
    PrimaryObject = $PrimaryObject
    SecondaryObject = $SecondaryObject
    PrimaryElf = $PrimaryElf
    SecondaryElf = $SecondaryElf
    PrimaryBin = $PrimaryBin
    SecondaryBin = $SecondaryBin
    PrimaryDisassembly = $PrimaryDisassemblyPath
    SecondaryDisassembly = $SecondaryDisassemblyPath
    Package = $ReassembledPackage
}

if (-not (Test-Path -LiteralPath $OutputDirectory -PathType Container)) {
    New-Item -ItemType Directory -Path $OutputDirectory -ErrorAction Stop | Out-Null
}
foreach ($Output in @(
    $PrimaryObject, $SecondaryObject, $PrimaryElf, $SecondaryElf,
    $PrimaryBin, $SecondaryBin, $PrimaryDisassemblyPath,
    $SecondaryDisassemblyPath, $ReassembledPackage
)) {
    if (Test-Path -LiteralPath $Output) {
        $Item = Get-Item -LiteralPath $Output -Force -ErrorAction Stop
        if ($Item.PSIsContainer -or
            ($Item.Attributes -band [System.IO.FileAttributes]::ReparsePoint) -ne 0 -or
            $Item.LinkType -eq 'HardLink') {
            throw "Refusing unsafe existing build output: $Output"
        }
    }
}

$PrimarySourceHashBefore = (Get-FileHash -Algorithm SHA256 -LiteralPath $PrimarySource).Hash
$SecondarySourceHashBefore = (Get-FileHash -Algorithm SHA256 -LiteralPath $SecondarySource).Hash

& $Gcc -c -x assembler-with-cpp -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 `
    -mfloat-abi=softfp -mthumb $PrimarySource -o $PrimaryObject
if ($LASTEXITCODE -ne 0) { throw "primary assembly failed with exit code $LASTEXITCODE" }

& $Gcc -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb `
    -nostdlib '-Wl,--build-id=none' '-Wl,--fatal-warnings' `
    -T $PrimaryLinker $PrimaryObject -o $PrimaryElf
if ($LASTEXITCODE -ne 0) { throw "primary link failed with exit code $LASTEXITCODE" }

& $Objcopy -O binary -j .firmware $PrimaryElf $PrimaryBin
if ($LASTEXITCODE -ne 0) { throw "primary objcopy failed with exit code $LASTEXITCODE" }

& $Gcc -c -x assembler-with-cpp -mcpu=cortex-m0 -mthumb `
    $SecondarySource -o $SecondaryObject
if ($LASTEXITCODE -ne 0) { throw "secondary assembly failed with exit code $LASTEXITCODE" }

& $Gcc -mcpu=cortex-m0 -mthumb -nostdlib '-Wl,--build-id=none' '-Wl,--fatal-warnings' `
    -T $SecondaryLinker $SecondaryObject -o $SecondaryElf
if ($LASTEXITCODE -ne 0) { throw "secondary link failed with exit code $LASTEXITCODE" }

& $Objcopy -O binary -j .firmware $SecondaryElf $SecondaryBin
if ($LASTEXITCODE -ne 0) { throw "secondary objcopy failed with exit code $LASTEXITCODE" }

if ($VerifyStock) {
    Assert-Sha256 $PrimaryBin $KnownPrimarySha256 'primary image'
    Assert-Sha256 $SecondaryBin $KnownSecondarySha256 'secondary image'
}

$RebuildArguments = @(
    (Join-Path $PSScriptRoot 'rebuild_mi5.py'),
    $Firmware,
    $ReassembledPackage,
    '--primary',
    $PrimaryBin,
    '--secondary',
    $SecondaryBin,
    '--force'
)
if ($AllowUnknownBase) {
    $RebuildArguments += '--allow-unknown-base'
}
& $Python @RebuildArguments
if ($LASTEXITCODE -ne 0) { throw "package rebuild failed with exit code $LASTEXITCODE" }

if ($VerifyStock) {
    Assert-ByteEqual $Firmware $ReassembledPackage 'complete OTA package'
}
else {
    Write-Host 'Stock identity comparison skipped. The rebuilt checksums do not make modified firmware safe to flash.'
}

$PrimaryDisassembly = & $Objdump -d $PrimaryElf
if ($LASTEXITCODE -ne 0) { throw "primary objdump failed with exit code $LASTEXITCODE" }
$PrimaryDisassembly | Set-Content -Encoding utf8 $PrimaryDisassemblyPath

$SecondaryDisassembly = & $Objdump -d $SecondaryElf
if ($LASTEXITCODE -ne 0) { throw "secondary objdump failed with exit code $LASTEXITCODE" }
$SecondaryDisassembly | Set-Content -Encoding utf8 $SecondaryDisassemblyPath

$PrimarySourceHashAfter = (Get-FileHash -Algorithm SHA256 -LiteralPath $PrimarySource).Hash
$SecondarySourceHashAfter = (Get-FileHash -Algorithm SHA256 -LiteralPath $SecondarySource).Hash
if ($PrimarySourceHashAfter -ne $PrimarySourceHashBefore -or
    $SecondarySourceHashAfter -ne $SecondarySourceHashBefore) {
    throw 'A persistent source changed during the build; refusing to report success.'
}

Write-Host "Reassembly build completed without changing working sources: $OutputDirectory"
