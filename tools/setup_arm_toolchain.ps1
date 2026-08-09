param()

$ErrorActionPreference = 'Stop'
$ResearchRoot = Split-Path -Parent $PSScriptRoot
$WorkspaceRoot = $ResearchRoot
$Dependencies = Join-Path $WorkspaceRoot '.analysis_deps'
$ArchiveName = 'arm-gnu-toolchain-15.2.rel1-mingw-w64-x86_64-arm-none-eabi.zip'
$Archive = Join-Path $Dependencies $ArchiveName
$Destination = Join-Path $Dependencies 'arm-gnu-toolchain-15.2.rel1'
$ExpectedSha256 = '7936cac895611023ffb22a64b8e426098c7104cb689778c1894572ca840b9ece'
$DownloadUrl = 'https://developer.arm.com/-/media/Files/downloads/gnu/15.2.rel1/binrel/arm-gnu-toolchain-15.2.rel1-mingw-w64-x86_64-arm-none-eabi.zip'

if (-not (Test-Path -LiteralPath $Dependencies)) {
    New-Item -ItemType Directory -Path $Dependencies -ErrorAction Stop | Out-Null
}
if (-not (Test-Path -LiteralPath $Archive)) {
    Write-Host "Downloading official Arm GNU Toolchain 15.2.rel1..."
    curl.exe -L --fail --retry 3 --output $Archive $DownloadUrl
}

$ActualSha256 = (Get-FileHash -Algorithm SHA256 -LiteralPath $Archive).Hash.ToLowerInvariant()
if ($ActualSha256 -ne $ExpectedSha256) {
    throw "Arm toolchain checksum mismatch: $ActualSha256"
}

$Compiler = Join-Path $Destination 'bin\arm-none-eabi-gcc.exe'
if (-not (Test-Path -LiteralPath $Compiler)) {
    if ((Test-Path -LiteralPath $Destination) -and
        (Get-ChildItem -LiteralPath $Destination -Force | Select-Object -First 1)) {
        throw "Toolchain destination exists but is incomplete: $Destination"
    }
    if (-not (Test-Path -LiteralPath $Destination)) {
        New-Item -ItemType Directory -Path $Destination -ErrorAction Stop | Out-Null
    }
    Expand-Archive -LiteralPath $Archive -DestinationPath $Destination
}

& $Compiler --version | Select-Object -First 1
Write-Host "Verified Arm toolchain: $Destination"
