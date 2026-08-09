param(
    [string]$Firmware = '',
    [string]$SourceDirectory = '',
    [switch]$AllowUnknown
)

$ErrorActionPreference = 'Stop'
$ResearchRoot = Split-Path -Parent $PSScriptRoot
$WorkspaceRoot = $ResearchRoot

if ([string]::IsNullOrWhiteSpace($Firmware)) {
    $Firmware = Join-Path $ResearchRoot 'firmware\stock.bin'
}
$Firmware = (Resolve-Path -LiteralPath $Firmware -ErrorAction Stop).Path

if ([string]::IsNullOrWhiteSpace($SourceDirectory)) {
    $SourceDirectory = Join-Path $ResearchRoot 'generated\reassembly\sources'
}
else {
    $SourceDirectory = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath(
        $SourceDirectory
    )
}

$Python = Join-Path $ResearchRoot '.venv\Scripts\python.exe'
if (-not (Test-Path -LiteralPath $Python -PathType Leaf)) {
    $Python = (Get-Command python -ErrorAction Stop).Source
}

$PrimarySource = Join-Path $SourceDirectory 'mi5_primary_byte_exact.S'
$SecondarySource = Join-Path $SourceDirectory 'mi5_secondary_byte_exact.S'
$ExistingSources = @($PrimarySource, $SecondarySource) | Where-Object {
    Test-Path -LiteralPath $_
}
if ($ExistingSources.Count -ne 0) {
    $Names = ($ExistingSources | ForEach-Object { Split-Path -Leaf $_ }) -join ', '
    throw "Refusing to overwrite persistent working source(s): $Names. Use a new -SourceDirectory if you need a fresh copy."
}

if (-not (Test-Path -LiteralPath $SourceDirectory -PathType Container)) {
    New-Item -ItemType Directory -Path $SourceDirectory -ErrorAction Stop | Out-Null
}

$MakeArguments = @(
    (Join-Path $PSScriptRoot 'make_reassembly.py'),
    $Firmware,
    $SourceDirectory
)
if ($AllowUnknown) {
    $MakeArguments += '--allow-unknown'
}
& $Python @MakeArguments
if ($LASTEXITCODE -ne 0) {
    throw "source preparation failed with exit code $LASTEXITCODE"
}

foreach ($Source in @($PrimarySource, $SecondarySource)) {
    if (-not (Test-Path -LiteralPath $Source -PathType Leaf)) {
        throw "source preparation did not create expected file: $Source"
    }
}

Write-Host 'Persistent reassembly sources prepared:'
Write-Host "  $PrimarySource"
Write-Host "  $SecondarySource"
Write-Host 'Edit these files directly. build_reassembly.ps1 will never regenerate or overwrite them.'
