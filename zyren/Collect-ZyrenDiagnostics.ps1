# Windows PowerShell 5.1+ / PowerShell 7 diagnostic collector.
# Prepared by static review in Linux; NOT executed or validated on Windows here.
# Starts the selected app and reads diagnostic state. It does not clear logs,
# uninstall anything, request root, change settings, or upload collected files.
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [ValidatePattern('^(127\.0\.0\.1|localhost):[0-9]{1,5}$')]
    [string]$AdbAddress,

    [string]$AdbPath,
    [string]$OutputDirectory
)

Set-StrictMode -Version 2.0
$ErrorActionPreference = 'Stop'
$PackageName = 'com.NovaX'
$ActivityName = 'com.NovaX/com.NovaX.MainActivity'
$Utf8 = [System.Text.UTF8Encoding]::new($false)
$CommandResults = New-Object System.Collections.Generic.List[object]
$RunFolder = $null

function Find-AdbExecutable {
    if ($AdbPath) {
        if (-not (Test-Path -LiteralPath $AdbPath -PathType Leaf)) {
            throw 'The supplied -AdbPath does not identify an existing file.'
        }
        return (Resolve-Path -LiteralPath $AdbPath).ProviderPath
    }
    $Candidates = New-Object System.Collections.Generic.List[string]
    foreach ($VariableName in @('ProgramFiles', 'ProgramFiles(x86)')) {
        $BaseFolder = [Environment]::GetEnvironmentVariable($VariableName)
        if ($BaseFolder) {
            $Candidates.Add((Join-Path $BaseFolder 'BlueStacks_nxt\HD-Adb.exe'))
            $Candidates.Add((Join-Path $BaseFolder 'BlueStacks\HD-Adb.exe'))
        }
    }
    foreach ($Candidate in $Candidates) {
        if (Test-Path -LiteralPath $Candidate -PathType Leaf) { return $Candidate }
    }
    foreach ($CommandName in @('adb.exe', 'adb')) {
        $Found = Get-Command $CommandName -CommandType Application -ErrorAction SilentlyContinue |
            Select-Object -First 1
        if ($Found) { return $Found.Source }
    }
    throw 'ADB was not found. Supply -AdbPath pointing to HD-Adb.exe or adb.exe.'
}

function Invoke-AdbCapture {
    param(
        [string]$CaptureName,
        [string[]]$AdbTokens,
        [int]$TimeoutSeconds = 20
    )
    # These are fixed command tokens plus the validated loopback endpoint.
    # Reject whitespace/quotes rather than interpreting arbitrary shell text.
    foreach ($Token in $AdbTokens) {
        if ($Token -notmatch '^[A-Za-z0-9._:/=-]+$') {
            throw "Unexpected command token in capture $CaptureName."
        }
    }
    $StartInfo = New-Object System.Diagnostics.ProcessStartInfo
    $StartInfo.FileName = $AdbExecutable
    $StartInfo.Arguments = [string]::Join(' ', $AdbTokens)
    $StartInfo.UseShellExecute = $false
    $StartInfo.CreateNoWindow = $true
    $StartInfo.RedirectStandardOutput = $true
    $StartInfo.RedirectStandardError = $true
    $StartInfo.StandardOutputEncoding = $Utf8
    $StartInfo.StandardErrorEncoding = $Utf8
    $CommandProcess = New-Object System.Diagnostics.Process
    $CommandProcess.StartInfo = $StartInfo
    $StartedUtc = [DateTime]::UtcNow
    try {
        if (-not $CommandProcess.Start()) { throw 'Unable to start the ADB client.' }
        $OutputTask = $CommandProcess.StandardOutput.ReadToEndAsync()
        $ErrorTask = $CommandProcess.StandardError.ReadToEndAsync()
        $TimedOut = -not $CommandProcess.WaitForExit($TimeoutSeconds * 1000)
        if ($TimedOut) {
            # Stop only this collector's timed-out ADB client, not the ADB server.
            try { $CommandProcess.Kill() } catch { }
            [void]$CommandProcess.WaitForExit(3000)
        }
        $OutputReady = $OutputTask.Wait(3000)
        $ErrorReady = $ErrorTask.Wait(3000)
        $CapturedOutput = if ($OutputReady) { $OutputTask.Result } else { '[stdout capture incomplete]' }
        $CapturedError = if ($ErrorReady) { $ErrorTask.Result } else { '[stderr capture incomplete]' }
        $ExitCode = if ($TimedOut) { 124 } else { $CommandProcess.ExitCode }
        $Capture = [pscustomobject]@{
            Name = $CaptureName
            Arguments = $AdbTokens
            StartedUtc = $StartedUtc.ToString('o')
            ExitCode = $ExitCode
            TimedOut = $TimedOut
            StreamsComplete = ($OutputReady -and $ErrorReady)
            Stdout = $CapturedOutput
            Stderr = $CapturedError
            File = "$CaptureName.txt"
        }
        $Header = "Capture: $CaptureName`r`nStarted UTC: $($Capture.StartedUtc)`r`n" +
            "ADB arguments: $([string]::Join(' ', $AdbTokens))`r`nExit code: $ExitCode`r`n" +
            "Timed out: $TimedOut`r`n`r`n--- stdout ---`r`n"
        [IO.File]::WriteAllText((Join-Path $RunFolder $Capture.File),
            ($Header + $CapturedOutput + "`r`n--- stderr ---`r`n" + $CapturedError), $Utf8)
        $CommandResults.Add($Capture)
        return $Capture
    }
    finally { $CommandProcess.Dispose() }
}

function Save-Summary {
    param([string]$Outcome, [int]$CollectorExitCode, [hashtable]$Details = @{})
    $Summary = [ordered]@{
        Collector = 'ZYREN BlueStacks diagnostic collection'
        ScriptWindowsExecutionVerifiedHere = $false
        Package = $PackageName
        AdbAddress = $AdbAddress
        Outcome = $Outcome
        CollectorExitCode = $CollectorExitCode
        Details = $Details
        Scope = 'App package dump, ABI properties, launch command output, and a bounded recent crash buffer. Crash entries may predate this run; launch-command success does not verify app functionality.'
        Commands = @($CommandResults | ForEach-Object {
            [ordered]@{ Name = $_.Name; ExitCode = $_.ExitCode; TimedOut = $_.TimedOut;
                StreamsComplete = $_.StreamsComplete; File = $_.File }
        })
    }
    [IO.File]::WriteAllText((Join-Path $RunFolder 'SUMMARY.json'),
        ($Summary | ConvertTo-Json -Depth 7), $Utf8)
}

try {
    $PortNumber = [int]($AdbAddress.Split(':')[-1])
    if ($PortNumber -lt 1 -or $PortNumber -gt 65535) { throw 'ADB port must be 1..65535.' }
    $AdbExecutable = Find-AdbExecutable
    if (-not $OutputDirectory) {
        $OutputDirectory = [Environment]::GetFolderPath('Desktop')
        if (-not $OutputDirectory) { $OutputDirectory = (Get-Location).Path }
    }
    # Always create a new run folder; existing captures and user files are preserved.
    if (-not (Test-Path -LiteralPath $OutputDirectory -PathType Container)) {
        [void](New-Item -ItemType Directory -Path $OutputDirectory -ErrorAction Stop)
    }
    $RunName = 'ZYREN-diagnostics-' + [DateTime]::UtcNow.ToString('yyyyMMdd-HHmmss') +
        '-' + [Guid]::NewGuid().ToString('N').Substring(0, 8)
    $RunFolder = Join-Path $OutputDirectory $RunName
    [void](New-Item -ItemType Directory -Path $RunFolder -ErrorAction Stop)

    $Version = Invoke-AdbCapture '00-adb-version' @('version')
    $Connection = Invoke-AdbCapture '01-connect' @('connect', $AdbAddress)
    $DeviceState = Invoke-AdbCapture '02-device-state' @('-s', $AdbAddress, 'get-state')
    if ($DeviceState.ExitCode -ne 0 -or $DeviceState.Stdout.Trim() -ne 'device') {
        Save-Summary 'Connection unavailable; app commands were not attempted.' 2
        Write-Host "ADB device is unavailable. Captures: $RunFolder"
        exit 2
    }

    $PackageDump = Invoke-AdbCapture '03-package-com.NovaX' @('-s', $AdbAddress, 'shell', 'dumpsys', 'package', $PackageName)
    $CpuAbi = Invoke-AdbCapture '04-cpu-abi' @('-s', $AdbAddress, 'shell', 'getprop', 'ro.product.cpu.abi')
    $CpuAbiList = Invoke-AdbCapture '05-cpu-abilist' @('-s', $AdbAddress, 'shell', 'getprop', 'ro.product.cpu.abilist')
    $Launch = Invoke-AdbCapture '06-launch-com.NovaX' @('-s', $AdbAddress, 'shell', 'am', 'start', '-W', '-n', $ActivityName) 45
    Start-Sleep -Seconds 2
    $CrashLog = Invoke-AdbCapture '07-recent-crash-buffer' @('-s', $AdbAddress, 'logcat', '-b', 'crash', '-d', '-v', 'threadtime', '-t', '200')

    $LaunchText = $Launch.Stdout + "`n" + $Launch.Stderr
    $LaunchErrorText = $LaunchText -match '(?im)^\s*(Error:|Error type [0-9]+|Exception occurred while executing)'
    $LaunchStatus = 'not reported'
    if ($LaunchText -match '(?im)^\s*Status:\s*(.+)$') { $LaunchStatus = $Matches[1].Trim() }
    $PackageMissing = ($PackageDump.Stdout + $PackageDump.Stderr) -match "(?i)(unable to find package|unknown package|package .* not found|can't find service: package)"
    $Partial = $false
    foreach ($Result in $CommandResults) {
        if ($Result.ExitCode -ne 0 -or -not $Result.StreamsComplete) { $Partial = $true }
    }
    if ($LaunchErrorText -or $LaunchStatus -ne 'ok' -or $PackageMissing -or
        -not $PackageDump.Stdout.Trim() -or
        -not $CpuAbi.Stdout.Trim() -or -not $CpuAbiList.Stdout.Trim()) { $Partial = $true }
    $CollectorCode = if ($Partial) { 3 } else { 0 }
    Save-Summary 'Collection finished; inspect captures for the startup failure.' $CollectorCode @{
        LaunchReportedStatus = $LaunchStatus
        LaunchErrorTextDetected = $LaunchErrorText
        PackageMissingTextDetected = $PackageMissing
        LaunchMayHaveReusedRunningActivity = ($LaunchText -match '(?i)Activity not started')
        RecentCrashBufferLineLimit = 200
        AppFunctionalityVerified = $false
    }
    Write-Host "Diagnostic captures saved: $RunFolder"
    Write-Host "Collector exit code: $CollectorCode (0 = collected; app functionality is not verified)."
    exit $CollectorCode
}
catch {
    $CollectorErrorMessage = $_.Exception.Message
    if ($RunFolder -and (Test-Path -LiteralPath $RunFolder -PathType Container)) {
        [IO.File]::WriteAllText((Join-Path $RunFolder 'COLLECTOR-ERROR.txt'),
            $CollectorErrorMessage, $Utf8)
        try { Save-Summary 'Collector failed before completing all captures.' 1 } catch { }
    }
    Write-Error -Message $CollectorErrorMessage -ErrorAction Continue
    if ($RunFolder) { Write-Host "Partial captures: $RunFolder" }
    exit 1
}
