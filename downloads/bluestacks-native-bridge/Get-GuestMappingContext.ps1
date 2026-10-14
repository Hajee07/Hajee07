[CmdletBinding()]
param(
    [string] $MachineName = 'Pie64',
    [ValidatePattern('^[A-Za-z0-9_.:-]+$')]
    [string] $Device = '127.0.0.1:5555'
)
Set-StrictMode -Version 2.0
$ErrorActionPreference = 'Stop'
$lines = [Collections.Generic.List[string]]::new()
$session = $null
$locked = $false
$issues = 0
$completed = $false
$adb = $null
function Record([string] $Text) { $lines.Add($Text); Write-Host $Text }
function Query([string] $Label, [scriptblock] $Action) {
    Record "[$Label]"
    try {
        $value = (& $Action | Out-String).Trim()
        if ($value.Length -gt 16384) { throw 'Unexpectedly large metadata response; not included.' }
        if ($value.Length -eq 0) { Record 'QueryStatus=EMPTY' }
        else { Record $value; Record 'QueryStatus=OK' }
    } catch {
        $script:issues++
        $errorObject = $_.Exception
        while ($null -ne $errorObject.InnerException) { $errorObject = $errorObject.InnerException }
        Record "QueryStatus=UNAVAILABLE HRESULT=0x$($errorObject.HResult.ToString('X8')) $($errorObject.Message)"
    }
}
function Adb([string] $Tail) {
    $start = [Diagnostics.ProcessStartInfo]::new()
    $start.FileName = $adb
    $start.Arguments = '-s ' + $Device + ' ' + $Tail
    $start.UseShellExecute = $false
    $start.CreateNoWindow = $true
    $start.RedirectStandardOutput = $true
    $start.RedirectStandardError = $true
    $process = [Diagnostics.Process]::new()
    $process.StartInfo = $start
    try {
        if (-not $process.Start()) { throw 'Could not start HD-Adb.' }
        $stdout = $process.StandardOutput.ReadToEndAsync()
        $stderr = $process.StandardError.ReadToEndAsync()
        if (-not $process.WaitForExit(15000)) {
            $process.Kill()
            [void]$process.WaitForExit(3000)
            throw 'HD-Adb query timed out after 15 seconds.'
        }
        $outputText = $stdout.Result.Trim()
        $errorText = $stderr.Result.Trim()
        if ($process.ExitCode -ne 0) {
            throw "HD-Adb exit=$($process.ExitCode): $errorText $outputText"
        }
        if ($errorText) { Record "AdbNote=$errorText" }
        return $outputText
    } finally { $process.Dispose() }
}
function Shell([string] $Command) {
    # Fixed commands below contain no embedded Windows double quotes or backslashes.
    # A validated decimal PID is the only value interpolated into a guest command.
    if ($Command.Contains('"') -or $Command.Contains('\')) { throw 'Unsupported command quoting.' }
    return (Adb ('shell "' + $Command + '"'))
}
Record 'MappingContextVersion=1'
Record 'Purpose=Kernel-layout and paging prerequisites; no game object mappings established'
try {
    if ([Environment]::OSVersion.Platform -ne [PlatformID]::Win32NT -or -not [Environment]::Is64BitProcess) {
        throw 'Use 64-bit Windows PowerShell on the BlueStacks PC.'
    }
    $principal = [Security.Principal.WindowsPrincipal]::new([Security.Principal.WindowsIdentity]::GetCurrent())
    if (-not $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {
        throw 'Use Administrator PowerShell to verify the loaded VMM module.'
    }
    $classId = (Get-Item -LiteralPath 'Registry::HKEY_CLASSES_ROOT\VirtualBox.VirtualBoxClient\CLSID').GetValue('')
    $server = [Environment]::ExpandEnvironmentVariables([string](Get-Item -LiteralPath "Registry::HKEY_CLASSES_ROOT\CLSID\$classId\InprocServer32").GetValue(''))
    if ([IO.Path]::GetFileName($server.Trim().Trim('"')) -ine 'BstkC.dll') {
        throw 'Registered COM client is not the verified BlueStacks server.'
    }
    $client = New-Object -ComObject 'VirtualBox.VirtualBoxClient'
    $box = $client.VirtualBox
    if ($box.Version -ne '6.1.36' -or $box.APIVersion -ne '6_1') { throw 'Unexpected BlueStacks management API version.' }
    $machine = $box.FindMachine($MachineName)
    if ($machine.State -ne 6 -or $machine.SessionState -ne 2) { throw 'Leave the selected BlueStacks instance running.' }
    $hostProcess = Get-Process -Id ([int]$machine.SessionPID) -ErrorAction Stop
    if ($hostProcess.ProcessName -ine 'HD-Player') { throw 'The selected VM session is not owned by HD-Player.' }
    $vmm = @(Get-Process -Id $hostProcess.Id -Module -ErrorAction Stop | Where-Object { $_.ModuleName -ieq 'BstkVMM.dll' })
    if ($vmm.Count -ne 1) { throw 'Could not identify exactly one loaded VMM module.' }
    if ((Get-FileHash -LiteralPath $vmm[0].FileName -Algorithm SHA256).Hash -ine '09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a') {
        throw 'Installed VMM differs from the inspected build.'
    }
    $adb = Join-Path (Split-Path -Parent $vmm[0].FileName) 'HD-Adb.exe'
    if (-not (Test-Path -LiteralPath $adb -PathType Leaf)) { throw 'HD-Adb.exe was not found beside the verified VMM.' }
    Record "Preflight=PASS Machine=$($machine.Name) HostPID=$($hostProcess.Id)"

    Query 'ADB' {
        $state = Adb 'get-state'
        if ($state -ne 'device') { throw "Selected ADB endpoint is unavailable: $state" }
        "SelectedDevice=$Device"
    }
    Query 'Kernel' { Shell 'uname -srvm; cat /proc/version' }
    Query 'Android' {
        'Release=' + (Shell 'getprop ro.build.version.release')
        'SDK=' + (Shell 'getprop ro.build.version.sdk')
        'GuestABI=' + (Shell 'getprop ro.product.cpu.abi')
        'NativeBridge=' + (Shell 'getprop ro.dalvik.vm.native.bridge')
    }
    Query 'KernelLayoutSources' {
        Shell 'for p in /sys/kernel/btf/vmlinux /proc/config.gz; do if [ -r $p ]; then ls -ln $p; else echo Unavailable=$p; fi; done'
    }
    Query 'KernelConfig' {
        # Output only settings that determine address translation and layout sources.
        Shell "if [ -r /proc/config.gz ]; then zcat /proc/config.gz | grep -E '^(CONFIG_(X86_64|X86_5LEVEL|RANDOMIZE_BASE|RANDOMIZE_MEMORY|KALLSYMS|KALLSYMS_ALL|KALLSYMS_BASE_RELATIVE|DEBUG_INFO|DEBUG_INFO_BTF|DEBUG_INFO_REDUCED|GCC_PLUGIN_RANDSTRUCT|PAGE_TABLE_ISOLATION|IKCONFIG|IKCONFIG_PROC))='; else echo Config=UNAVAILABLE; fi"
    }
    Query 'SelectedKernelSymbols' {
        # Address zero means redacted/unusable, even when the symbol name is present.
        Shell "grep -E '[[:space:]](linux_banner|init_task|init_mm|swapper_pg_dir|init_top_pgt|init_level4_pgt|page_offset_base|phys_base|__per_cpu_offset)$' /proc/kallsyms"
    }
    $gameProcessId = $null
    Query 'GameProcess' {
        $script:gameProcessId = (Shell 'pidof com.dts.freefireth').Trim()
        if ($gameProcessId -notmatch '^\d+$') { throw 'Exactly one running Free Fire PID is required.' }
        "GuestGamePID=$gameProcessId"
        Shell "cat /proc/$gameProcessId/comm"
    }
    Query 'Package' {
        Shell "dumpsys package com.dts.freefireth | grep -E 'versionName=|primaryCpuAbi=|secondaryCpuAbi='"
    }

    $session = New-Object -ComObject 'VirtualBox.Session'
    $machine.LockMachine($session, [int]1)
    $locked = $true
    $debugger = $session.Console.Debugger
    if ($null -eq $debugger) { throw 'The debugger object is unavailable.' }
    Query 'DebuggerPlugins' { $debugger.Info('plugins', '') }
    Query 'PagingMode' { $debugger.Info('mode', '') }
    Query 'PhysicalRanges' { $debugger.Info('phys', '') }
    $cpuCount = [int]$machine.CPUCount
    if ($cpuCount -lt 1 -or $cpuCount -gt 64) { throw 'Unexpected virtual CPU count.' }
    Record "VirtualCPUCount=$cpuCount"
    Record 'RegisterScope=Scheduling samples; no sampled CR3 is identified as the Free Fire page table'
    for ($cpuIndex = 0; $cpuIndex -lt $cpuCount; $cpuIndex++) {
        foreach ($registerName in @('cr0', 'cr3', 'cr4', 'efer')) {
            Query "CPU$cpuIndex.$registerName" { $debugger.GetRegister([uint32]$cpuIndex, $registerName) }
        }
    }
    if ($gameProcessId -match '^\d+$') {
        Query 'GameProcessEnd' {
            $after = (Shell 'pidof com.dts.freefireth').Trim()
            if ($after -cne $gameProcessId) { throw 'Game PID changed during collection; treat the report as inconsistent.' }
            "GuestGamePID=$after PIDUnchanged=True"
        }
    }
    Record 'AddressMapping=NOT_ESTABLISHED'
    $completed = $true
} catch {
    $issues++
    Record "CollectionError=$($_.Exception.Message)"
} finally {
    if ($locked) {
        try { $session.UnlockMachine(); Record 'SharedSession=RELEASED' }
        catch { $issues++; Record "SharedSessionRelease=FAIL $($_.Exception.Message)" }
    }
    Record "CollectionComplete=$completed UnavailableQueries=$issues"
    try {
        $report = Join-Path $PSScriptRoot ('guest-mapping-context-' + [guid]::NewGuid().ToString('N') + '.txt')
        $lines | Set-Content -LiteralPath $report -Encoding UTF8
        Write-Host "ResultFile=$report"
    } catch { $issues++; Write-Host "ResultFile=UNAVAILABLE $($_.Exception.Message)" }
}
if ($issues -gt 0) { exit 1 }
