[CmdletBinding()]
param([string] $MachineName = 'Pie64')
Set-StrictMode -Version 2.0
$ErrorActionPreference = 'Stop'
$lines = [Collections.Generic.List[string]]::new()
$session = $null
$debugger = $null
$locked = $false
$loaded = $false
$loadedName = ''
$failed = $false
$stage = 'Preflight'
function Record([string] $Text) { $lines.Add($Text); Write-Host $Text }
function Failure([string] $Stage, [Exception] $Exception) {
    while ($null -ne $Exception.InnerException) { $Exception = $Exception.InnerException }
    Record "$Stage=FAIL HRESULT=0x$($Exception.HResult.ToString('X8')) $($Exception.Message)"
}
try {
    if ([Environment]::OSVersion.Platform -ne [PlatformID]::Win32NT -or -not [Environment]::Is64BitProcess) {
        throw 'Use 64-bit Windows PowerShell on the BlueStacks PC.'
    }
    $principal = [Security.Principal.WindowsPrincipal]::new([Security.Principal.WindowsIdentity]::GetCurrent())
    if (-not $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {
        throw 'Run this script in Administrator PowerShell so the loaded VMM module can be verified.'
    }
    $manifest = Get-Content -LiteralPath (Join-Path $PSScriptRoot 'manifest.json') -Raw | ConvertFrom-Json
    if ($manifest.plugin -cne 'VBoxDbgHeadAimBridge.dll' -or $manifest.sha256 -notmatch '^[0-9a-fA-F]{64}$') {
        throw 'Package manifest is invalid.'
    }
    $pluginPath = Join-Path $PSScriptRoot 'VBoxDbgHeadAimBridge.dll'
    if ((Get-FileHash -LiteralPath $pluginPath -Algorithm SHA256).Hash -ine $manifest.sha256) {
        throw 'Plugin digest differs from this package manifest.'
    }
    $classId = (Get-Item -LiteralPath 'Registry::HKEY_CLASSES_ROOT\VirtualBox.VirtualBoxClient\CLSID').GetValue('')
    $server = [Environment]::ExpandEnvironmentVariables([string](Get-Item -LiteralPath "Registry::HKEY_CLASSES_ROOT\CLSID\$classId\InprocServer32").GetValue(''))
    if ([IO.Path]::GetFileName($server.Trim().Trim('"')) -ine 'BstkC.dll') {
        throw 'The registered COM client is not the verified BlueStacks server.'
    }
    $client = New-Object -ComObject 'VirtualBox.VirtualBoxClient'
    $box = $client.VirtualBox
    if ($box.Version -ne '6.1.36' -or $box.APIVersion -ne '6_1') {
        throw 'This package targets the inspected BlueStacks 6.1.36 / 6_1 API only.'
    }
    $machine = $box.FindMachine($MachineName)
    if ($machine.State -ne 6 -or $machine.SessionState -ne 2) {
        throw 'Open the Pie64 BlueStacks instance and leave it running during this probe.'
    }
    $hostProcess = Get-Process -Id ([int]$machine.SessionPID) -ErrorAction Stop
    if ($hostProcess.ProcessName -ine 'HD-Player') { throw 'VM session is not owned by HD-Player.' }
    $vmm = @(Get-Process -Id $hostProcess.Id -Module -ErrorAction Stop | Where-Object { $_.ModuleName -ieq 'BstkVMM.dll' })
    if ($vmm.Count -ne 1) { throw 'Could not identify exactly one loaded BstkVMM module.' }
    $expectedVmm = '09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a'
    if ((Get-FileHash -LiteralPath $vmm[0].FileName -Algorithm SHA256).Hash -ine $expectedVmm) {
        throw 'Installed BstkVMM differs from the inspected build; the native ABI is not verified for this file.'
    }
    Record "Preflight=PASS Machine=$($machine.Name) HostPID=$($hostProcess.Id) VmmDigest=MATCH"
    $stage = 'SharedSession'
    $session = New-Object -ComObject 'VirtualBox.Session'
    $machine.LockMachine($session, [int]1) # Actual installed LockType_Shared=1, verified by diagnostic v2/v3.
    $locked = $true
    $debugger = $session.Console.Debugger
    if ($null -eq $debugger) { throw 'The debugger object is unavailable.' }
    $priorHelp = [string]$debugger.Info('help', '')
    if ($priorHelp -match '(?im)^\s*headbridge\s') {
        throw 'A headbridge handler already exists; this run will not replace or unload it.'
    }
    $stage = 'PluginLoad'
    $loadedName = [string]$debugger.LoadPlugIn($pluginPath)
    if ([string]::IsNullOrWhiteSpace($loadedName) -or $loadedName -ieq 'all') {
        throw 'The SDK returned an invalid plugin identity; automatic unload cannot be safely selected.'
    }
    $loaded = $true
    Record "PluginLoad=PASS Name=$loadedName"
    $stage = 'BridgeStatus'
    $status = [string]$debugger.Info('headbridge', 'status')
    Record $status.TrimEnd()
    if ($status -notmatch '(?m)^BridgeStatus=READY Protocol=1 ReadOnly=1 MaximumRead=4096\s*$') {
        throw 'The plugin did not report the expected bridge protocol.'
    }
    $stage = 'BridgeProbe'
    $result = [string]$debugger.Info('headbridge', 'probe')
    Record $result.TrimEnd()
    if ($result -notmatch '(?m)^BridgeProbe=PASS BytesRead=1 Contents=OMITTED\s*$') {
        throw 'The native one-byte read did not pass; see the reported VBox status.'
    }
} catch {
    $failed = $true
    Failure $stage $_.Exception
} finally {
    if ($loaded) {
        try {
            $debugger.UnloadPlugIn($loadedName)
            Record 'PluginUnload=PASS'
            $remaining = [string]$debugger.Info('help', '')
            if ($remaining -match '(?im)^\s*headbridge\s') { throw 'The info handler remains after unload.' }
            Record 'HandlerCleanup=PASS'
        } catch { $failed = $true; Failure 'PluginUnload' $_.Exception }
    }
    if ($locked) {
        try { $session.UnlockMachine(); Record 'SharedSession=RELEASED' }
        catch { $failed = $true; Failure 'SharedSessionRelease' $_.Exception }
    }
    try {
        $log = Join-Path $PSScriptRoot ('bridge-result-' + [guid]::NewGuid().ToString('N') + '.txt')
        $lines | Set-Content -LiteralPath $log -Encoding UTF8
        Write-Host "ResultFile=$log"
    } catch { Write-Host "ResultFile=UNAVAILABLE $($_.Exception.Message)" }
}
if ($failed) { exit 1 }
