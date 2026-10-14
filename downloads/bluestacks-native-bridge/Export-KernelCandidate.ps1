[CmdletBinding()]
param(
    [ValidatePattern('^[A-Za-z0-9_.-]+$')]
    [string] $MachineName = 'Pie64',
    [string] $KernelPath = '',
    [string] $ExpectedRelease = '4.19.195'
)
Set-StrictMode -Version 2
$ErrorActionPreference = 'Stop'
$log = [Collections.Generic.List[string]]::new()
function Record([string] $Text) { $log.Add($Text); Write-Host $Text }
function Read-KernelHeader([string] $Path, [string] $Release) {
    $file = Get-Item -LiteralPath $Path -ErrorAction Stop
    if ($file.PSIsContainer -or $file.Length -lt 512 -or $file.Length -gt 128MB) {
        throw 'Candidate must be a regular image between 512 bytes and 128 MiB.'
    }
    $stream = [IO.File]::Open($file.FullName, [IO.FileMode]::Open, [IO.FileAccess]::Read, [IO.FileShare]::Read)
    try {
        $header = [byte[]]::new([int][Math]::Min($file.Length, 131072))
        $used = 0
        while ($used -lt $header.Length) {
            $got = $stream.Read($header, $used, $header.Length - $used)
            if ($got -eq 0) { throw 'Unexpected end of image.' }
            $used += $got
        }
        $format = ''
        $architecture = ''
        $version = ''
        if ($header.Length -ge 0x238 -and [Text.Encoding]::ASCII.GetString($header, 0x202, 4) -ceq 'HdrS' -and
            $header[0x1fe] -eq 0x55 -and $header[0x1ff] -eq 0xaa) {
            $format = 'LinuxBootImage'
            $protocol = [BitConverter]::ToUInt16($header, 0x206)
            if ($protocol -ge 0x20c -and ([BitConverter]::ToUInt16($header, 0x236) -band 1)) {
                $architecture = 'x86_64'
            } else { $architecture = 'UNVERIFIED' }
            $versionPointer = [BitConverter]::ToUInt16($header, 0x20e)
            $offset = 0x200 + $versionPointer
            if ($versionPointer -ne 0 -and $offset -lt $header.Length) {
                $end = $offset
                while ($end -lt $header.Length -and $end -lt ($offset + 512) -and $header[$end] -ne 0) { $end++ }
                $version = [Text.Encoding]::ASCII.GetString($header, $offset, $end - $offset)
            }
        } elseif ($header[0] -eq 0x7f -and [Text.Encoding]::ASCII.GetString($header, 1, 3) -ceq 'ELF' -and
                  $header[4] -eq 2 -and $header[5] -eq 1 -and [BitConverter]::ToUInt16($header, 18) -eq 62) {
            $format = 'ELF64'
            $architecture = 'x86_64'
            [void]$stream.Seek(0, [IO.SeekOrigin]::Begin)
            $chunk = [byte[]]::new(1MB)
            $tail = ''
            while (($got = $stream.Read($chunk, 0, $chunk.Length)) -gt 0) {
                $text = $tail + [Text.Encoding]::ASCII.GetString($chunk, 0, $got)
                $banner = [regex]::Match($text, 'Linux version ([^\x00\r\n]{1,512})[\x00\r\n]')
                if ($banner.Success) { $version = $banner.Groups[1].Value; break }
                $tail = $text.Substring([Math]::Max(0, $text.Length - 1024))
            }
        } else { throw 'No supported x86-64 Linux kernel image header found.' }
        $releaseMatches = $version -match ('^' + [regex]::Escape($Release) + '(?:\s|$)')
        [pscustomobject]@{
            Path = $file.FullName; Name = $file.Name; Length = $file.Length
            Format = $format; Architecture = $architecture; Version = $version
            ReleaseMatches = $releaseMatches
        }
    } finally { $stream.Dispose() }
}
function Write-KernelArchive([object[]] $Candidates, [string] $Destination, [string] $Release) {
    Add-Type -AssemblyName System.IO.Compression.FileSystem
    $manifest = [Collections.Generic.List[object]]::new()
    $archive = [IO.Compression.ZipFile]::Open($Destination, [IO.Compression.ZipArchiveMode]::Create)
    try {
        $index = 0
        foreach ($candidate in $Candidates) {
            $index++
            $entryName = 'kernel-' + $index + '.bin'
            [void][IO.Compression.ZipFileExtensions]::CreateEntryFromFile($archive, $candidate.Path, $entryName, [IO.Compression.CompressionLevel]::Optimal)
            $manifest.Add([pscustomobject]@{
                Entry = $entryName; OriginalName = $candidate.Name; Length = $candidate.Length
                SHA256 = $candidate.SHA256; Format = $candidate.Format
                Architecture = $candidate.Architecture; Version = $candidate.Version
            })
        }
        $entry = $archive.CreateEntry('manifest.json')
        $writer = [IO.StreamWriter]::new($entry.Open())
        try {
            $writer.Write(([pscustomobject]@{
                CandidateOnly = $true; ExpectedRelease = $Release; Images = @($manifest.ToArray())
            } | ConvertTo-Json -Depth 5))
        } finally { $writer.Dispose() }
    } finally { $archive.Dispose() }
    # Verify the archived bytes, not only the source files or ZIP filenames.
    $archive = [IO.Compression.ZipFile]::OpenRead($Destination)
    try {
        foreach ($item in $manifest) {
            $entry = $archive.GetEntry($item.Entry)
            if ($null -eq $entry -or $entry.Length -ne $item.Length) { throw 'Archive length verification failed.' }
            $stream = $entry.Open()
            $sha = [Security.Cryptography.SHA256]::Create()
            try { $digest = ([BitConverter]::ToString($sha.ComputeHash($stream))).Replace('-', '').ToLowerInvariant() }
            finally { $sha.Dispose(); $stream.Dispose() }
            if ($digest -cne $item.SHA256) { throw 'Archive content verification failed; the source may have changed.' }
        }
    } finally { $archive.Dispose() }
}
$failed = $false
$outputRoot = ''
Record 'KernelExportVersion=1'
try {
    if ([Environment]::OSVersion.Platform -ne [PlatformID]::Win32NT -or -not [Environment]::Is64BitProcess) {
        throw 'Run this helper in 64-bit Windows PowerShell on the BlueStacks PC.'
    }
    $outputRoot = Join-Path $env:TEMP ('kernel-export-' + [guid]::NewGuid().ToString('N'))
    [void](New-Item -ItemType Directory -Path $outputRoot)
    $roots = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    $paths = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    if ($KernelPath) { [void]$paths.Add((Get-Item -LiteralPath $KernelPath).FullName) }
    else {
        $classId = (Get-Item -LiteralPath 'Registry::HKEY_CLASSES_ROOT\VirtualBox.VirtualBoxClient\CLSID').GetValue('')
        $server = [Environment]::ExpandEnvironmentVariables([string](Get-Item -LiteralPath "Registry::HKEY_CLASSES_ROOT\CLSID\$classId\InprocServer32").GetValue('')).Trim().Trim('"')
        if ([IO.Path]::GetFileName($server) -ine 'BstkC.dll') { throw 'COM client is not the installed BlueStacks server.' }
        $install = Split-Path -Parent $server
        [void]$roots.Add($install)
        try {
            $client = New-Object -ComObject 'VirtualBox.VirtualBoxClient'
            $machine = $client.VirtualBox.FindMachine($MachineName)
            $settings = [string]$machine.SettingsFilePath
            if ($settings) { [void]$roots.Add((Split-Path -Parent $settings)) }
            foreach ($key in @($machine.GetExtraDataKeys())) {
                if ($key -match '(?i)kernel|vmlinuz|vmlinux|bzimage') {
                    $value = [Environment]::ExpandEnvironmentVariables([string]$machine.GetExtraData($key)).Trim().Trim('"')
                    if ($value -and (Test-Path -LiteralPath $value -PathType Leaf)) { [void]$paths.Add((Get-Item -LiteralPath $value).FullName) }
                }
            }
        } catch { Record "MachineMetadataSearch=UNAVAILABLE $($_.Exception.Message)" }
        if ($env:ProgramData) { [void]$roots.Add((Join-Path $env:ProgramData "BlueStacks_nxt\Engine\$MachineName")) }
        $registry = Get-ItemProperty -LiteralPath 'HKLM:\SOFTWARE\BlueStacks_nxt' -ErrorAction SilentlyContinue
        if ($null -ne $registry) {
            foreach ($propertyName in @('UserDefinedDir', 'DataDir')) {
                $property = $registry.PSObject.Properties[$propertyName]
                if ($null -ne $property -and $property.Value) {
                    $dataRoot = [Environment]::ExpandEnvironmentVariables([string]$property.Value)
                    [void]$roots.Add((Join-Path $dataRoot "Engine\$MachineName"))
                }
            }
        }
        foreach ($root in $roots) {
            if (-not (Test-Path -LiteralPath $root -PathType Container)) { continue }
            Record "SearchRoot=$root Depth=3"
            $searchErrors = @()
            Get-ChildItem -LiteralPath $root -File -Recurse -Depth 3 -ErrorAction SilentlyContinue -ErrorVariable searchErrors |
                Where-Object { $_.Name -match '^(?i:kernel(?:[-_.0-9a-z]*)|vmlinuz(?:[-_.0-9a-z]*)|vmlinux(?:[-_.0-9a-z]*)|bzimage)$' } |
                ForEach-Object { [void]$paths.Add($_.FullName) }
            if ($searchErrors.Count) { Record "SearchErrors=$($searchErrors.Count) Root=$root" }
        }
    }
    $candidates = [Collections.Generic.List[object]]::new()
    $digests = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    foreach ($path in $paths) {
        Record "Inspect=$path"
        try {
            $candidate = Read-KernelHeader -Path $path -Release $ExpectedRelease
            Record "ImageFormat=$($candidate.Format) Architecture=$($candidate.Architecture) Version=$($candidate.Version)"
            if (-not $candidate.ReleaseMatches -or $candidate.Architecture -ne 'x86_64') {
                Record 'Candidate=SKIPPED Reason=Release or architecture not verified'
                continue
            }
            $digest = (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
            if ($digests.Add($digest)) {
                $candidate | Add-Member -NotePropertyName SHA256 -NotePropertyValue $digest
                $candidates.Add($candidate)
            }
        } catch { Record "Candidate=SKIPPED $($_.Exception.Message)" }
    }
    Record "CandidateCount=$($candidates.Count)"
    if ($candidates.Count -eq 0) { throw 'No matching standalone kernel image found. Share this search report; the kernel may be stored inside a VM disk.' }
    if ($candidates.Count -gt 4) { throw 'More than four distinct candidates found. Share the report to select the image belonging to Pie64.' }
    $zip = Join-Path $outputRoot 'bluestacks-kernel-candidates.zip'
    Write-KernelArchive -Candidates $candidates.ToArray() -Destination $zip -Release $ExpectedRelease
    Record 'ArchiveVerification=PASS'
    Record 'LiveKernelIdentity=NOT_PROVEN Release match alone does not prove identical runtime build'
    Record "ArchiveFile=$zip"
    Record "ArchiveSHA256=$((Get-FileHash -LiteralPath $zip -Algorithm SHA256).Hash.ToLowerInvariant())"
    if ((Get-Item -LiteralPath $zip).Length -gt 30MB) { Record 'ArchiveSize=OVER_30_MIB Share the report first.' }
} catch { $failed = $true; Record "ExportError=$($_.Exception.Message)" }
finally {
    if ($outputRoot) {
        $report = Join-Path $outputRoot 'kernel-export-report.txt'
        try { $log | Set-Content -LiteralPath $report -Encoding UTF8; Write-Host "ResultFile=$report" }
        catch { $failed = $true; Write-Host "ResultFile=UNAVAILABLE $($_.Exception.Message)" }
    }
}
if ($failed) { exit 1 }
