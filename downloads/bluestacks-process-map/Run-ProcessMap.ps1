[CmdletBinding(DefaultParameterSetName='Heads')]
param(
    [Parameter(ParameterSetName='Heads')]
    [Parameter(ParameterSetName='PlayerState')]
    [Parameter(ParameterSetName='TeamPolicy')]
    [Parameter(ParameterSetName='CombatState')]
    [Parameter(ParameterSetName='ZoneProtection')]
    [Parameter(ParameterSetName='MatchDamagePolicy')]
    [Parameter(ParameterSetName='WeaponContext')]
    [Parameter(ParameterSetName='WeaponFiring')]
    [Parameter(ParameterSetName='WeaponAmmo')]
    [Parameter(ParameterSetName='AimState')]
    [string] $MachineName = 'Pie64',
    [ValidatePattern('^[A-Za-z0-9_.:-]+$')]
    [string] $Device = '127.0.0.1:5555',
    [Parameter(ParameterSetName='PlayerState')]
    [switch] $ProbePlayerState,
    [Parameter(ParameterSetName='TeamPolicy')]
    [switch] $ProbeTeamPolicy,
    [Parameter(ParameterSetName='CombatState')]
    [switch] $ProbeCombatState,
    [Parameter(ParameterSetName='CombatState')]
    [ValidateRange(-1, 15)]
    [int] $CombatRosterIndex = -1,
    [Parameter(ParameterSetName='ZoneProtection')]
    [switch] $ProbeZoneProtection,
    [Parameter(ParameterSetName='ZoneProtection')]
    [ValidateRange(-1, 15)]
    [int] $ZoneRosterIndex = -1,
    [Parameter(ParameterSetName='MatchDamagePolicy')]
    [switch] $ProbeMatchDamagePolicy,
    [Parameter(ParameterSetName='WeaponContext')]
    [switch] $ProbeWeaponContext,
    [Parameter(ParameterSetName='WeaponFiring')]
    [switch] $ProbeWeaponFiring,
    [Parameter(ParameterSetName='WeaponAmmo')]
    [switch] $ProbeWeaponAmmo,
    [Parameter(ParameterSetName='AimState')]
    [switch] $ProbeAimState
)
Set-StrictMode -Version 2
$ErrorActionPreference = 'Stop'
$lines = [Collections.Generic.List[string]]::new()
$session = $null
$debugger = $null
$reader = $null
$locked = $false
$loaded = $false
$loadedName = ''
$failed = $false
$stage = 'Preflight'
$adb = $null
function Record([string] $Text) { $lines.Add($Text); Write-Host $Text }
function Failure([string] $Stage, [Exception] $Exception) {
    while ($null -ne $Exception.InnerException) { $Exception = $Exception.InnerException }
    Record "$Stage=FAIL HRESULT=0x$($Exception.HResult.ToString('X8')) $($Exception.Message)"
}
function Adb([string] $Tail, [switch] $HostCommand) {
    $start = [Diagnostics.ProcessStartInfo]::new()
    $start.FileName = $adb
    $start.Arguments = if ($HostCommand) { $Tail } else { '-s ' + $Device + ' ' + $Tail }
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
function Ensure-AdbDevice {
    $state = ''
    try { $state = Adb 'get-state' }
    catch { Record "AdbInitialState=UNAVAILABLE $($_.Exception.Message)" }
    if ($state -ne 'device') {
        $endpoint = [regex]::Match($Device, '^(127\.0\.0\.1|localhost):([0-9]{1,5})$')
        if (-not $endpoint.Success -or [int]$endpoint.Groups[2].Value -lt 1 -or [int]$endpoint.Groups[2].Value -gt 65535) {
            throw 'Selected device is offline. Automatic reconnect requires an explicit localhost TCP endpoint.'
        }
        Record "AdbReconnect=ATTEMPT Endpoint=$Device"
        Record (Adb -Tail ('connect ' + $Device) -HostCommand)
        # adb connect may exit zero even when its text reports a failed connection.
        $state = Adb 'get-state'
    }
    if ($state -ne 'device') { throw "Selected ADB endpoint is unavailable: $state" }
    "SelectedDevice=$Device State=device"
}

function Shell([string] $Command) {
    # Fixed commands below contain no embedded Windows double quotes or backslashes.
    # A validated decimal PID is the only value interpolated into a guest command.
    if ($Command.Contains('"') -or $Command.Contains('\')) { throw 'Unsupported command quoting.' }
    return (Adb ('shell "' + $Command + '"'))
}
function RegisterValue([int] $Cpu, [string] $Name) {
    $value = [string]$debugger.GetRegister([uint32]$Cpu, $Name)
    if ($value -notmatch '^0x[0-9a-fA-F]{1,16}$') { throw "Unexpected register representation for CPU$Cpu.$Name" }
    [Convert]::ToUInt64($value.Substring(2), 16)
}
Record 'ProcessMapVersion=45 ReadOnly=1'
Record "PlayerStateMode=$($ProbePlayerState.IsPresent)"
Record "TeamPolicyMode=$($ProbeTeamPolicy.IsPresent)"
Record "CombatStateMode=$($ProbeCombatState.IsPresent) RequestedRosterIndex=$CombatRosterIndex"
Record "ZoneProtectionMode=$($ProbeZoneProtection.IsPresent) RequestedRosterIndex=$ZoneRosterIndex"
Record "MatchDamagePolicyMode=$($ProbeMatchDamagePolicy.IsPresent)"
Record "WeaponContextMode=$($ProbeWeaponContext.IsPresent)"
Record "WeaponFiringMode=$($ProbeWeaponFiring.IsPresent)"
Record "WeaponAmmoMode=$($ProbeWeaponAmmo.IsPresent)"
Record "AimStateMode=$($ProbeAimState.IsPresent)"
try {
    if ($PSBoundParameters.ContainsKey('ZoneRosterIndex') -and -not $ProbeZoneProtection.IsPresent) { throw 'Use -ProbeZoneProtection with -ZoneRosterIndex.' }
    if ($PSBoundParameters.ContainsKey('CombatRosterIndex') -and -not $ProbeCombatState.IsPresent) { throw 'Use -ProbeCombatState with -CombatRosterIndex.' }
    if ([Environment]::OSVersion.Platform -ne [PlatformID]::Win32NT -or -not [Environment]::Is64BitProcess) {
        throw 'Use 64-bit Windows PowerShell on the BlueStacks PC.'
    }
    $principal = [Security.Principal.WindowsPrincipal]::new([Security.Principal.WindowsIdentity]::GetCurrent())
    if (-not $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) { throw 'Use Administrator PowerShell.' }
    $manifest = Get-Content -LiteralPath (Join-Path $PSScriptRoot 'manifest.json') -Raw | ConvertFrom-Json
    $pluginPath = Join-Path $PSScriptRoot 'VBoxDbgHeadAimBridge.dll'
    $sourcePath = Join-Path $PSScriptRoot 'GuestProcessMap.cs'
    $modulePath = Join-Path $PSScriptRoot 'ModuleProbe.cs'
    $referencePath = Join-Path $PSScriptRoot 'ModuleReference.cs'
    $layoutPath = Join-Path $PSScriptRoot 'GameLayoutProbe.cs'
    $layoutReferencePath = Join-Path $PSScriptRoot 'GameLayoutReference.cs'
    $objectPath = Join-Path $PSScriptRoot 'PlayerObjectProbe.cs'
    $objectReferencePath = Join-Path $PSScriptRoot 'ObjectReference.cs'
    $headCachePath = Join-Path $PSScriptRoot 'HeadCacheProbe.cs'
    $nativeTransformPath = Join-Path $PSScriptRoot 'NativeTransformProbe.cs'
    $nativeTransformReferencePath = Join-Path $PSScriptRoot 'NativeTransformReference.cs'
    $rosterPath = Join-Path $PSScriptRoot 'RosterProbe.cs'
    $rosterReferencePath = Join-Path $PSScriptRoot 'RosterReference.cs'
    $otherHeadPath = Join-Path $PSScriptRoot 'OtherHeadProbe.cs'
    $statePath = Join-Path $PSScriptRoot 'PlayerStateProbe.cs'
    $stateReferencePath = Join-Path $PSScriptRoot 'PlayerStateReference.cs'
    $teamPath = Join-Path $PSScriptRoot 'TeamPolicyProbe.cs'
    $teamReferencePath = Join-Path $PSScriptRoot 'TeamPolicyReference.cs'
    $combatPath = Join-Path $PSScriptRoot 'CombatStateProbe.cs'
    $combatReferencePath = Join-Path $PSScriptRoot 'CombatStateReference.cs'
    $zonePath = Join-Path $PSScriptRoot 'ZoneProtectionProbe.cs'
    $zoneReferencePath = Join-Path $PSScriptRoot 'ZoneProtectionReference.cs'
    $damagePath = Join-Path $PSScriptRoot 'MatchDamageProbe.cs'
    $damageReferencePath = Join-Path $PSScriptRoot 'MatchDamageReference.cs'
    $weaponPath = Join-Path $PSScriptRoot 'WeaponContextProbe.cs'
    $weaponReferencePath = Join-Path $PSScriptRoot 'WeaponContextReference.cs'
    $firingPath = Join-Path $PSScriptRoot 'WeaponFiringProbe.cs'
    $firingReferencePath = Join-Path $PSScriptRoot 'WeaponFiringReference.cs'
    $ammoPath = Join-Path $PSScriptRoot 'WeaponAmmoProbe.cs'
    $ammoReferencePath = Join-Path $PSScriptRoot 'WeaponAmmoReference.cs'
    $aimStatePath = Join-Path $PSScriptRoot 'AimStateProbe.cs'
    $aimStateReferencePath = Join-Path $PSScriptRoot 'AimStateReference.cs'
    if ($manifest.plugin -cne 'VBoxDbgHeadAimBridge.dll' -or $manifest.sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.mapping_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.module_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.module_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.layout_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.layout_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.object_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.object_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.head_cache_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.native_transform_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.native_transform_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.roster_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.roster_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.other_head_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.state_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.state_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.team_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.team_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.combat_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.combat_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.zone_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.zone_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.damage_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.damage_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.weapon_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.weapon_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.firing_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.firing_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.ammo_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.ammo_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.aim_state_source_sha256 -notmatch '^[0-9a-fA-F]{64}$' -or
        $manifest.aim_state_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$') { throw 'Package manifest is invalid.' }
    if ((Get-FileHash -LiteralPath $pluginPath -Algorithm SHA256).Hash -ine $manifest.sha256 -or
        (Get-FileHash -LiteralPath $sourcePath -Algorithm SHA256).Hash -ine $manifest.mapping_source_sha256 -or
        (Get-FileHash -LiteralPath $modulePath -Algorithm SHA256).Hash -ine $manifest.module_source_sha256 -or
        (Get-FileHash -LiteralPath $referencePath -Algorithm SHA256).Hash -ine $manifest.module_reference_sha256 -or
        (Get-FileHash -LiteralPath $layoutPath -Algorithm SHA256).Hash -ine $manifest.layout_source_sha256 -or
        (Get-FileHash -LiteralPath $layoutReferencePath -Algorithm SHA256).Hash -ine $manifest.layout_reference_sha256 -or
        (Get-FileHash -LiteralPath $objectPath -Algorithm SHA256).Hash -ine $manifest.object_source_sha256 -or
        (Get-FileHash -LiteralPath $objectReferencePath -Algorithm SHA256).Hash -ine $manifest.object_reference_sha256 -or
        (Get-FileHash -LiteralPath $headCachePath -Algorithm SHA256).Hash -ine $manifest.head_cache_source_sha256 -or
        (Get-FileHash -LiteralPath $nativeTransformPath -Algorithm SHA256).Hash -ine $manifest.native_transform_source_sha256 -or
        (Get-FileHash -LiteralPath $nativeTransformReferencePath -Algorithm SHA256).Hash -ine $manifest.native_transform_reference_sha256 -or
        (Get-FileHash -LiteralPath $rosterPath -Algorithm SHA256).Hash -ine $manifest.roster_source_sha256 -or
        (Get-FileHash -LiteralPath $rosterReferencePath -Algorithm SHA256).Hash -ine $manifest.roster_reference_sha256 -or
        (Get-FileHash -LiteralPath $otherHeadPath -Algorithm SHA256).Hash -ine $manifest.other_head_source_sha256 -or
        (Get-FileHash -LiteralPath $statePath -Algorithm SHA256).Hash -ine $manifest.state_source_sha256 -or
        (Get-FileHash -LiteralPath $stateReferencePath -Algorithm SHA256).Hash -ine $manifest.state_reference_sha256 -or
        (Get-FileHash -LiteralPath $teamPath -Algorithm SHA256).Hash -ine $manifest.team_source_sha256 -or
        (Get-FileHash -LiteralPath $teamReferencePath -Algorithm SHA256).Hash -ine $manifest.team_reference_sha256 -or
        (Get-FileHash -LiteralPath $combatPath -Algorithm SHA256).Hash -ine $manifest.combat_source_sha256 -or
        (Get-FileHash -LiteralPath $combatReferencePath -Algorithm SHA256).Hash -ine $manifest.combat_reference_sha256 -or
        (Get-FileHash -LiteralPath $zonePath -Algorithm SHA256).Hash -ine $manifest.zone_source_sha256 -or
        (Get-FileHash -LiteralPath $zoneReferencePath -Algorithm SHA256).Hash -ine $manifest.zone_reference_sha256 -or
        (Get-FileHash -LiteralPath $damagePath -Algorithm SHA256).Hash -ine $manifest.damage_source_sha256 -or
        (Get-FileHash -LiteralPath $damageReferencePath -Algorithm SHA256).Hash -ine $manifest.damage_reference_sha256 -or
        (Get-FileHash -LiteralPath $weaponPath -Algorithm SHA256).Hash -ine $manifest.weapon_source_sha256 -or
        (Get-FileHash -LiteralPath $weaponReferencePath -Algorithm SHA256).Hash -ine $manifest.weapon_reference_sha256 -or
        (Get-FileHash -LiteralPath $firingPath -Algorithm SHA256).Hash -ine $manifest.firing_source_sha256 -or
        (Get-FileHash -LiteralPath $firingReferencePath -Algorithm SHA256).Hash -ine $manifest.firing_reference_sha256 -or
        (Get-FileHash -LiteralPath $ammoPath -Algorithm SHA256).Hash -ine $manifest.ammo_source_sha256 -or
        (Get-FileHash -LiteralPath $ammoReferencePath -Algorithm SHA256).Hash -ine $manifest.ammo_reference_sha256 -or
        (Get-FileHash -LiteralPath $aimStatePath -Algorithm SHA256).Hash -ine $manifest.aim_state_source_sha256 -or
        (Get-FileHash -LiteralPath $aimStateReferencePath -Algorithm SHA256).Hash -ine $manifest.aim_state_reference_sha256) {
        throw 'Package DLL or mapper source checksum mismatch.'
    }
    Add-Type -Path @($sourcePath, $modulePath, $referencePath, $layoutPath, $layoutReferencePath, $objectPath, $objectReferencePath, $headCachePath, $nativeTransformPath, $nativeTransformReferencePath, $rosterPath, $rosterReferencePath, $otherHeadPath, $statePath, $stateReferencePath, $teamPath, $teamReferencePath, $combatPath, $combatReferencePath, $zonePath, $zoneReferencePath, $damagePath, $damageReferencePath, $weaponPath, $weaponReferencePath, $firingPath, $firingReferencePath, $ammoPath, $ammoReferencePath, $aimStatePath, $aimStateReferencePath) -ErrorAction Stop
    $classId = (Get-Item -LiteralPath 'Registry::HKEY_CLASSES_ROOT\VirtualBox.VirtualBoxClient\CLSID').GetValue('')
    $server = [Environment]::ExpandEnvironmentVariables([string](Get-Item -LiteralPath "Registry::HKEY_CLASSES_ROOT\CLSID\$classId\InprocServer32").GetValue(''))
    if ([IO.Path]::GetFileName($server.Trim().Trim('"')) -ine 'BstkC.dll') { throw 'COM client is not the verified BlueStacks server.' }
    $client = New-Object -ComObject 'VirtualBox.VirtualBoxClient'
    $box = $client.VirtualBox
    if ($box.Version -ne '6.1.36' -or $box.APIVersion -ne '6_1') { throw 'Unexpected BlueStacks SDK version.' }
    $machine = $box.FindMachine($MachineName)
    if ($machine.State -ne 6 -or $machine.SessionState -ne 2) { throw 'Open Pie64 and Free Fire and leave them running.' }
    $hostProcess = Get-Process -Id ([int]$machine.SessionPID) -ErrorAction Stop
    if ($hostProcess.ProcessName -ine 'HD-Player') { throw 'VM session is not owned by HD-Player.' }
    $vmm = @(Get-Process -Id $hostProcess.Id -Module -ErrorAction Stop | Where-Object { $_.ModuleName -ieq 'BstkVMM.dll' })
    if ($vmm.Count -ne 1) { throw 'Could not identify exactly one loaded VMM module.' }
    if ((Get-FileHash -LiteralPath $vmm[0].FileName -Algorithm SHA256).Hash -ine '09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a') {
        throw 'Loaded VMM differs from the inspected build.'
    }
    Record "Preflight=PASS Machine=$($machine.Name) HostPID=$($hostProcess.Id) VmmDigest=MATCH"
    $adb = Join-Path (Split-Path -Parent $vmm[0].FileName) 'HD-Adb.exe'
    if (-not (Test-Path -LiteralPath $adb -PathType Leaf)) { throw 'HD-Adb.exe was not found beside the VMM.' }
    $stage = 'GameIdentity'
    Record (Ensure-AdbDevice)
    $gameProcessId = (Shell 'pidof com.dts.freefireth').Trim()
    if ($gameProcessId -notmatch '^\d+$') { throw 'Exactly one running Free Fire PID is required.' }
    $gameName = (Shell "cat /proc/$gameProcessId/comm").Trim()
    $package = Shell "dumpsys package com.dts.freefireth | grep -E 'versionName=|primaryCpuAbi='"
    if ($package -notmatch '(?m)^\s*versionName=1\.132\.1\s*$' -or $package -notmatch '(?m)^\s*primaryCpuAbi=arm64-v8a\s*$') {
        throw 'This probe targets Free Fire 1.132.1 with the ARM64 package ABI.'
    }
    Record "GameIdentity=PASS GuestPID=$gameProcessId Name=$gameName"
    $stage = 'SharedSession'
    $session = New-Object -ComObject 'VirtualBox.Session'
    $machine.LockMachine($session, [int]1)
    $locked = $true
    $debugger = $session.Console.Debugger
    if ($null -eq $debugger) { throw 'The debugger object is unavailable.' }
    if ([string]$debugger.Info('help', '') -match '(?im)^\s*headbridge\s') { throw 'An existing headbridge handler will not be replaced.' }
    $stage = 'PluginLoad'
    $loadedName = [string]$debugger.LoadPlugIn($pluginPath)
    if ([string]::IsNullOrWhiteSpace($loadedName) -or $loadedName -ieq 'all') { throw 'Invalid plugin identity returned by the SDK.' }
    $loaded = $true
    Record "PluginLoad=PASS Name=$loadedName"
    $status = [string]$debugger.Info('headbridge', 'status')
    if ($status -notmatch '(?m)^BridgeStatus=READY Protocol=1 ReadOnly=1 MaximumRead=4096\s*$') { throw 'Bridge protocol differs from the expected read-only interface.' }
    Record $status.TrimEnd()
    $stage = 'PagingContext'
    $physicalInfo = [string]$debugger.Info('phys', '')
    $ranges = [Collections.Generic.List[HeadBridge.Mapping.RamRange]]::new()
    $rangeMatches = [regex]::Matches($physicalInfo, '(?m)^([0-9a-fA-F]{16})-([0-9a-fA-F]{16})\s+[0-9a-fA-F]{16}\s+(Conventional RAM|Extended RAM, [^\r\n]+|Above 4GB Base RAM)\s*$')
    foreach ($item in $rangeMatches) {
        $ranges.Add([HeadBridge.Mapping.RamRange]::new([Convert]::ToUInt64($item.Groups[1].Value, 16), [Convert]::ToUInt64($item.Groups[2].Value, 16)))
    }
    if ($ranges.Count -eq 0) { throw 'No verified RAM ranges were reported; no physical reads will be attempted.' }
    $mode = [string]$debugger.Info('mode', '')
    $cpuIds = @([regex]::Matches($mode, '(?m)^Guest paging mode \(VCPU #([0-9]+)\):') | ForEach-Object { [int]$_.Groups[1].Value } | Sort-Object -Unique)
    if ($cpuIds.Count -eq 0 -or $cpuIds[-1] -gt 63) { throw 'No valid runtime CPU IDs were reported.' }
    $roots = [Collections.Generic.HashSet[uint64]]::new()
    $slides = [Collections.Generic.HashSet[uint64]]::new()
    [void]$slides.Add([uint64]0)
    foreach ($cpuIndex in $cpuIds) {
        $cr0 = RegisterValue $cpuIndex 'cr0'
        $cr4 = RegisterValue $cpuIndex 'cr4'
        $efer = RegisterValue $cpuIndex 'efer'
        if (($cr0 -band 0x80000000L) -eq 0 -or ($cr4 -band 0x20) -eq 0 -or ($efer -band 0x400) -eq 0 -or ($cr4 -band 0x1000) -ne 0) {
            throw 'Guest paging is not the supported four-level AMD64 mode.'
        }
        [void]$roots.Add((RegisterValue $cpuIndex 'cr3'))
        try {
            $lstar = RegisterValue $cpuIndex 'lstar'
            foreach ($slide in [HeadBridge.Mapping.Reader]::SlidesFromLstar($lstar)) { [void]$slides.Add($slide) }
        } catch { Record "RelocationRegister=UNAVAILABLE CPU=$cpuIndex $($_.Exception.Message)" }
    }
    Record "PagingContext=PASS CPUIds=$($cpuIds -join ',') RAMRanges=$($ranges.Count)"
    $transport = [Func[uint64,int,string]]{
        param([uint64]$address, [int]$count)
        [string]$debugger.Info('headbridge', ('readphys 0x' + $address.ToString('x') + ' ' + $count))
    }
    $reader = [HeadBridge.Mapping.Reader]::new($transport, $ranges.ToArray())
    $stage = 'KernelIdentity'
    $kernel = $null
    foreach ($root in $roots) {
        foreach ($slide in $slides) {
            try { $kernel = $reader.VerifyKernel($root, $slide); break }
            catch { Record "KernelCandidate=REJECTED Root=0x$($root.ToString('x')) Slide=0x$($slide.ToString('x')) $($_.Exception.GetBaseException().Message)" }
        }
        if ($null -ne $kernel) { break }
    }
    if ($null -eq $kernel) { throw 'No sampled kernel mapping matched the extracted image; no process layouts were used.' }
    Record "KernelIdentity=PASS Root=0x$($kernel.Root.ToString('x')) Slide=0x$($kernel.Slide.ToString('x')) InitialActiveMM=0x$($kernel.InitialActiveMm.ToString('x'))"
    $stage = 'ProcessMap'
    $game = $reader.FindProcess($kernel, [int]$gameProcessId, $gameName)
    Record "ProcessMap=PASS GuestPID=$($game.Pid) Task=0x$($game.Task.ToString('x')) MM=0x$($game.Mm.ToString('x')) CR3=0x$($game.Root.ToString('x')) TasksVisited=$($game.TasksVisited)"
    $stage = 'GameModuleIdentity'
    Record 'LibraryScanMode=TARGETED_MODULE Target=libil2cpp.so'
    $progress = [Action[string]]{ param([string]$message) Record $message }
    $module = $reader.ProbeModuleWithRetry($kernel, $game, $progress)
    $libraries = $reader.LastLibraries
    $il2cpp = $false
    foreach ($mapping in $libraries.Mappings) {
        $selected = $mapping.Start -eq $module.LoadBias
        Record "LibraryMapping Name=$($mapping.Name) Start=0x$($mapping.Start.ToString('x')) End=0x$($mapping.End.ToString('x')) FilePageOffset=$($mapping.FilePageOffset) Arm64ElfHeader=$($mapping.Arm64ElfHeader) Revalidated=$($mapping.Revalidated) SelectedModule=$selected"
        if ($selected -and $mapping.Name -ceq 'libil2cpp.so' -and $mapping.Arm64ElfHeader -and $mapping.Revalidated) { $il2cpp = $true }
    }
    Record "VmasVisited=$($libraries.VmasVisited)"
    if (-not $il2cpp -or $libraries.StopReason -cne 'MODULE_VERIFIED') { throw 'The selected ARM64 IL2CPP module was not revalidated.' }
    if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during the probe.' }
    $reader.Recheck($kernel, $game)
    Record 'GameLibraryRead=PASS Name=libil2cpp.so Architecture=ARM64'
    Record "GameModuleIdentity=PASS LoadBias=0x$($module.LoadBias.ToString('x')) BuildId=$($module.BuildId) LoadSegments=$($module.LoadSegments) WindowVmas=$($module.WindowVmas) Fingerprints=$($module.Fingerprints)"
    Record "ApkReferenceSHA256=$($module.ReferenceFileSha256) RuntimeVerification=ELF_TABLES_SEGMENT_OFFSETS_BUILD_ID_AND_CODE_SAMPLES"
    $stage = 'GameLayoutRegistration'
    $layout = $reader.VerifyGameLayout($kernel, $game, $module, $progress)
    if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during layout verification.' }
    $reader.Recheck($kernel, $game)
    Record "RuntimeTypeMetadata=PASS Base=0x$($layout.RuntimeMetadataBase.ToString('x')) Descriptors=$($layout.TypeDescriptors) RecordBytes=88 HeaderProfile=OBSERVED_ZERO_VERSION24"
    Record "GameLayoutRegistration=PASS Fields=$($layout.FieldCandidates) Methods=$($layout.MethodCandidates) Checks=$($layout.Checks) Passes=2"
    Record "MetadataReferenceSHA256=$($layout.MetadataSha256)"
    $stage = 'PlayerObjectProbe'
    $objects = $reader.VerifyPlayerObjects($kernel, $game, $module, $layout, $progress)
    if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during object verification.' }
    $reader.Recheck($kernel, $game)
    Record "LocalPlayerObjects=PASS CurrentGame=0x$($objects.CurrentGame.ToString('x')) Match=0x$($objects.Match.ToString('x')) Player=0x$($objects.LocalPlayer.ToString('x')) Class=$($objects.PlayerClass) Observations=$($objects.Observations) OriginalPathHotfixSlots=INACTIVE"
    Record "ManagedHeadTransform=$($objects.HeadStatus) Source=$($objects.HeadSource) Model=0x$($objects.HeadModel.ToString('x')) CacheEntries=$($objects.HeadCacheEntries) Provider=0x$($objects.HeadProvider.ToString('x')) Transform=0x$($objects.HeadTransform.ToString('x'))"
    if ($objects.HeadWorldStatus -ceq 'SAMPLED_READ_ONLY') {
        $culture = [Globalization.CultureInfo]::InvariantCulture
        Record "LocalHeadWorldPosition=SAMPLED_READ_ONLY X=$($objects.HeadWorldX.ToString('R', $culture)) Y=$($objects.HeadWorldY.ToString('R', $culture)) Z=$($objects.HeadWorldZ.ToString('R', $culture)) Attempts=$($objects.HeadSampleAttempts) CaptureChunks=$($objects.HeadCaptureChunks) ParentCount=$($objects.HeadParentCount) HierarchyCapacity=$($objects.HeadHierarchyCapacity) Observations=$($objects.HeadWorldObservations) NativeTransform=0x$($objects.NativeHeadTransform.ToString('x')) UnityLoadBias=0x$($objects.UnityLoadBias.ToString('x'))"
    } else {
        Record "LocalHeadWorldPosition=$($objects.HeadWorldStatus) Attempts=$($objects.HeadSampleAttempts) Detail=$($objects.HeadWorldError)"
        if ($objects.HeadWorldStatus -ceq 'FAIL') { $failed = $true }
    }
    Record "MatchPlayerDictionary=$($objects.RosterStatus) Attempts=$($objects.RosterAttempts) Dictionary=0x$($objects.RosterDictionary.ToString('x')) UsedSlots=$($objects.RosterUsed) RemovedSlots=$($objects.RosterRemoved) ActiveEntries=$($objects.RosterActive) NullValues=$($objects.RosterNullValues) UniqueCandidatePointers=$($objects.RosterCandidates) VerifiedPlayers=$($objects.MatchPlayers.Length) VerifiedOtherPlayers=$($objects.RosterOtherVerified) LocalPresent=$($objects.RosterLocalPresent) CompleteObjectValidation=$($objects.RosterComplete) Observations=$($objects.RosterObservations)"
    for ($index = 0; $index -lt $objects.MatchPlayers.Length; $index++) {
        $entry = $objects.MatchPlayers[$index]
        Record "MatchPlayerObject Index=$index Address=0x$($entry.Address.ToString('x')) Class=$($entry.Class) IsLocal=$($entry.IsLocal)"
    }
    if ($objects.RosterStatus -ceq 'FAIL') { $failed = $true }
    if ($objects.RosterError) { Record "MatchPlayerDictionaryError=$($objects.RosterError)" }
    $otherHeads = [HeadBridge.Mapping.OtherHeadResult]::new()
    $teamSummary = 'NOT_REQUESTED'
    $combatSummary = 'NOT_REQUESTED'
    $zoneSummary = 'NOT_REQUESTED'
    $damageSummary = 'NOT_REQUESTED'
    $weaponSummary = 'NOT_REQUESTED'
    $firingSummary = 'NOT_REQUESTED'
    $ammoSummary = 'NOT_REQUESTED'
    $aimStateSummary = 'NOT_REQUESTED'
    if ($ProbeAimState) {
        $stage = 'AimState'
        $aimStart = $reader.PhysicalCalls
        $aimState = $reader.SampleAimState($kernel, $game, $module, $layout, $objects, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during aim-state sampling.' }
        $aimStateSummary = $aimState.StopReason
        Record "AimStateSamples AdditionalPhysicalReads=$($reader.PhysicalCalls - $aimStart) Attempted=$($aimState.Samples.Length) Sampled=$($aimState.Sampled) StopReason=$($aimState.StopReason) Detail=$($aimState.Detail)"
        foreach ($sample in $aimState.Samples) {
            if ($sample.Status -ceq 'SAMPLED_READ_ONLY') {
                Record "LocalAimRotation=$($sample.AimRotationStatus) GetterRVA=0x6f249ac BackingFieldOffset=0x614 Scope=ORIGINAL_LOCAL_GETTER CurrentAimRotationField=NOT_REQUESTED CameraOrientation=UNVERIFIED"
                if ($null -ne $sample.AimW) {
                    Record "AimQuaternion X=$($sample.AimX) Y=$($sample.AimY) Z=$($sample.AimZ) W=$($sample.AimW) NormSquared=$($sample.AimNormSquared) NormalizedByProbe=False"
                    Record "QuaternionPositiveZBasis X=$($sample.BasisX) Y=$($sample.BasisY) Z=$($sample.BasisZ) InputBasis=0,0,1 Math=VERIFIED_UNITY_QUATERNION_VECTOR_MULTIPLY NormalizedByProbe=False CameraConvention=UNVERIFIED ShotDirection=UNVERIFIED"
                    Record "CameraNativeBindings Status=$($sample.CameraBindingStatus) MainFunction=0x$($sample.CameraMainICall.ToString('x')) ComponentTransformFunction=0x$($sample.ComponentTransformICall.ToString('x')) Scope=ICALL_FUNCTION_POINTERS_ONLY SelectedCamera=UNVERIFIED ManagedCamera=NOT_READ CameraPose=UNVERIFIED GameGetterHotfix=NOT_EVALUATED FunctionsInvoked=False"
                    Record "CameraUnityCode Status=$($sample.CameraUnityCodeStatus) LoadBias=0x$($sample.CameraUnityLoadBias.ToString('x')) BuildId=667862f2d29b22ee ReferenceFileSHA256=1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77 MainRVA=0x41d8c4 ComponentTransformRVA=0x453d04 CodeScope=MAIN_24_COMPONENT_460_BYTES SelectedCamera=UNVERIFIED ManagedCamera=NOT_READ CameraPose=UNVERIFIED FunctionsInvoked=False"
                    Record "NativeCameraCandidate Status=$($sample.CameraCandidateStatus) NativeObject=0x$($sample.CameraCandidateObject.ToString('x')) Owner=0x$($sample.CameraCandidateOwner.ToString('x')) PredicateFunction=0x$($sample.CameraPredicateFunction.ToString('x')) PredicateRVA=0x$($sample.CameraPredicateRva.ToString('x')) TagProbes=$($sample.CameraTagProbes) NodesVisited=$($sample.CameraNodesVisited) PredicateEvaluated=$($null -ne $sample.CameraPredicateRaw) GameGetterCamera=UNVERIFIED ManagedCamera=NOT_READ CameraPose=UNVERIFIED"
                    Record "CameraMainSelection Status=$($sample.CameraSelectionStatus) NativeObject=0x$($sample.SelectedNativeCamera.ToString('x')) Owner=0x$($sample.SelectedNativeCameraOwner.ToString('x')) PredicateRawByte=$($sample.CameraPredicateRaw) PredicatesEvaluated=$($sample.CameraPredicatesEvaluated) CompleteSourceSelection=$($sample.CameraSelectionComplete) Scope=ORIGINAL_UNITY_NATIVE_SELECTOR EvaluatedBy=READ_ONLY_SOURCE_EQUIVALENT FunctionsInvoked=False ManagedCamera=NOT_READ CameraPose=UNVERIFIED GameGetterHotfix=NOT_EVALUATED"
                    Record "CameraWorldPosition Status=$($sample.CameraPositionStatus) NativeTransform=0x$($sample.CameraNativeTransform.ToString('x')) X=$(if ($null -ne $sample.CameraWorldX) { $sample.CameraWorldX.ToString('R',$culture) } else { 'NA' }) Y=$(if ($null -ne $sample.CameraWorldY) { $sample.CameraWorldY.ToString('R',$culture) } else { 'NA' }) Z=$(if ($null -ne $sample.CameraWorldZ) { $sample.CameraWorldZ.ToString('R',$culture) } else { 'NA' }) ParentCount=$($sample.CameraParentCount) Scope=ORIGINAL_UNITY_NATIVE_SELECTOR_TRANSFORM_INTERMEDIATE Rotation=UNVERIFIED ActualGameCamera=UNVERIFIED GameGetterHotfix=NOT_EVALUATED FunctionsInvoked=False AimWrites=NONE"
                }
                Record "AimStateMembership RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) IsLocal=$($sample.IsLocal) Proof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Observations=$($sample.Observations)"
            } else {
                Record "AimState=$($sample.Status) RosterIndex=$($sample.RosterIndex) Detail=$($sample.Detail)"
                if ($sample.Status -ceq 'FAIL') { $failed = $true }
            }
        }
        if ($aimState.StopReason -in @('FAIL', 'FINAL_CONTEXT_FAILED')) { $failed = $true }
        Record 'AimStateSemantics TargetDirection=NOT_REQUESTED CameraConvention=UNVERIFIED FiringReadiness=UNVERIFIED LineOfSight=UNVERIFIED GameMethodCalls=NONE AimWrites=NONE'
        Record 'OtherOptionalPhases=NOT_REQUESTED_AIM_STATE_MODE'
    } elseif ($ProbeWeaponAmmo) {
        $stage = 'WeaponAmmo'
        $ammoStart = $reader.PhysicalCalls
        $ammo = $reader.SampleWeaponAmmo($kernel, $game, $module, $layout, $objects, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during ammo sampling.' }
        $ammoSummary = $ammo.StopReason
        Record "WeaponAmmoSamples AdditionalPhysicalReads=$($reader.PhysicalCalls - $ammoStart) Attempted=$($ammo.Samples.Length) Sampled=$($ammo.Sampled) StopReason=$($ammo.StopReason) Detail=$($ammo.Detail)"
        foreach ($sample in $ammo.Samples) {
            if ($sample.Status -ceq 'SAMPLED_READ_ONLY') {
                $weaponPointer = if ($null -eq $sample.Weapon) { 'UNKNOWN' } else { '0x' + $sample.Weapon.ToString('x') }
                $ammoValue = if ($null -eq $sample.WeaponAmmoRaw) { 'UNKNOWN' } else { [string]$sample.WeaponAmmoRaw }
                $fieldIndex = if ($null -eq $sample.WeaponAmmoFieldIndex) { 'UNKNOWN' } else { [string]$sample.WeaponAmmoFieldIndex }
                Record "WeaponSelection Status=$($sample.WeaponStatus) Path=$($sample.WeaponSelectionPath) Weapon=$weaponPointer Class=$($sample.WeaponClass)"
                Record "SelectedWeaponAmmoCounter=$ammoValue Status=$($sample.WeaponAmmoStatus) DataType=Int32 GetterRVA=0x7457fa4 Scope=ORIGINAL_SELECTED_WEAPON_COUNTER Magazine=UNVERIFIED Reserve=UNVERIFIED UnlimitedPolicy=UNVERIFIED"
                Record "WeaponAmmoField LocalIndex=$fieldIndex Name=$($sample.WeaponAmmoFieldName) Registration=$($sample.WeaponAmmoRegistration) Binding=UNIQUE_RUNTIME_OFFSET_AND_NATIVE_GETTER"
                Record "WeaponAmmoMembership RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) IsLocal=$($sample.IsLocal) Proof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Observations=$($sample.Observations)"
            } else {
                Record "WeaponAmmo=$($sample.Status) RosterIndex=$($sample.RosterIndex) Detail=$($sample.Detail)"
                if ($sample.Status -ceq 'FAIL') { $failed = $true }
            }
        }
        if ($ammo.StopReason -in @('FAIL', 'FINAL_CONTEXT_FAILED')) { $failed = $true }
        Record 'WeaponAmmoSemantics DataId=NOT_REQUESTED ReloadPredicate=NOT_REQUESTED FiringPredicate=NOT_REQUESTED Ballistics=UNVERIFIED FiringReadiness=UNVERIFIED LineOfSight=UNVERIFIED GameMethodCalls=NONE Writes=NONE'
        Record 'OtherOptionalPhases=NOT_REQUESTED_WEAPON_AMMO_MODE'
    } elseif ($ProbeWeaponFiring) {
        $stage = 'WeaponFiring'
        $firingStart = $reader.PhysicalCalls
        $firing = $reader.SampleWeaponFiring($kernel, $game, $module, $layout, $objects, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during firing sampling.' }
        $firingSummary = $firing.StopReason
        Record "WeaponFiringSamples AdditionalPhysicalReads=$($reader.PhysicalCalls - $firingStart) Attempted=$($firing.Samples.Length) Sampled=$($firing.Sampled) StopReason=$($firing.StopReason) Detail=$($firing.Detail)"
        foreach ($sample in $firing.Samples) {
            if ($sample.Status -ceq 'SAMPLED_READ_ONLY') {
                $weaponPointer = if ($null -eq $sample.Weapon) { 'UNKNOWN' } else { '0x' + $sample.Weapon.ToString('x') }
                $firingValue = if ($null -eq $sample.WeaponFiring) { 'UNKNOWN' } else { [string]$sample.WeaponFiring }
                $cacheEnabled = if ($null -eq $sample.WeaponFiringCacheEnabled) { 'UNKNOWN' } else { [string]$sample.WeaponFiringCacheEnabled }
                $stateRaw = if ($null -eq $sample.WeaponStateRaw) { 'UNKNOWN' } else { [string]$sample.WeaponStateRaw }
                Record "WeaponSelection Status=$($sample.WeaponStatus) Path=$($sample.WeaponSelectionPath) Weapon=$weaponPointer Class=$($sample.WeaponClass)"
                Record "SelectedWeaponFiring=$firingValue Status=$($sample.WeaponFiringStatus) Route=$($sample.WeaponFiringRoute) CacheEnabled=$cacheEnabled StateRaw=$stateRaw Scope=SELECTED_WEAPON_PREDICATE PlayerIsFiring=UNVERIFIED FiringReadiness=UNVERIFIED"
                Record "WeaponFiringMembership RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) IsLocal=$($sample.IsLocal) Proof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Observations=$($sample.Observations)"
            } else {
                Record "WeaponFiring=$($sample.Status) RosterIndex=$($sample.RosterIndex) Detail=$($sample.Detail)"
                if ($sample.Status -ceq 'FAIL') { $failed = $true }
            }
        }
        if ($firing.StopReason -in @('FAIL', 'FINAL_CONTEXT_FAILED')) { $failed = $true }
        Record 'WeaponFiringSemantics DataId=NOT_REQUESTED ReloadPredicate=NOT_REQUESTED Ammo=UNVERIFIED Ballistics=UNVERIFIED FiringReadiness=UNVERIFIED LineOfSight=UNVERIFIED GameMethodCalls=NONE Writes=NONE'
        Record 'OtherOptionalPhases=NOT_REQUESTED_WEAPON_FIRING_MODE'
    } elseif ($ProbeWeaponContext) {
        $stage = 'WeaponContext'
        $weaponStart = $reader.PhysicalCalls
        $weapons = $reader.SampleWeaponContext($kernel, $game, $module, $layout, $objects, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during weapon-context sampling.' }
        $weaponSummary = $weapons.StopReason
        Record "WeaponContextSamples AdditionalPhysicalReads=$($reader.PhysicalCalls - $weaponStart) Attempted=$($weapons.Samples.Length) Sampled=$($weapons.Sampled) StopReason=$($weapons.StopReason) Detail=$($weapons.Detail)"
        foreach ($sample in $weapons.Samples) {
            if ($sample.Status -ceq 'SAMPLED_READ_ONLY') {
                $weaponPointer = if ($null -eq $sample.Weapon) { 'UNKNOWN' } else { '0x' + $sample.Weapon.ToString('x') }
                $dataPointer = if ($null -eq $sample.WeaponData) { 'UNKNOWN' } else { '0x' + $sample.WeaponData.ToString('x') }
                $alternate = if ($null -eq $sample.AlternateHand) { 'NOT_REQUESTED' } else { [string]$sample.AlternateHand }
                Record "WeaponContext=$($sample.WeaponStatus) ObservationStatus=$($sample.Status) RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) IsLocal=$($sample.IsLocal) MembershipProof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Observations=$($sample.Observations)"
                Record "WeaponSelection Path=$($sample.WeaponSelectionPath) Weapon=$weaponPointer Class=$($sample.WeaponClass) AlternateHand=$alternate"
                Record "WeaponDataReference=$dataPointer Class=$($sample.WeaponDataClass) Registration=$($sample.WeaponDataRegistration) GameMethodCalls=NONE"
                $weaponId = if ($null -eq $sample.WeaponIdRaw) { 'UNKNOWN' } else { [string]$sample.WeaponIdRaw }
                Record "WeaponDataId=$weaponId Status=$($sample.WeaponIdStatus) DataType=UInt32 NameMapping=UNVERIFIED GameMethodCalls=NONE"
                $reloading = if ($null -eq $sample.WeaponReloading) { 'UNKNOWN' } else { [string]$sample.WeaponReloading }
                $weaponState = if ($null -eq $sample.WeaponStateRaw) { 'UNKNOWN' } else { [string]$sample.WeaponStateRaw }
                Record "SelectedWeaponReloading=$reloading Status=$($sample.WeaponReloadStatus) StateRaw=$weaponState Scope=SELECTED_WEAPON_PREDICATE PlayerIsReloading=UNVERIFIED FiringReadiness=UNVERIFIED"
            } else {
                Record "WeaponContext=$($sample.Status) RosterIndex=$($sample.RosterIndex) Class=$($sample.Class) Detail=$($sample.Detail)"
                if ($sample.Status -ceq 'FAIL') { $failed = $true }
            }
        }
        if ($weapons.StopReason -in @('FAIL', 'FINAL_CONTEXT_FAILED')) { $failed = $true }
        Record 'WeaponSemantics Ammo=UNVERIFIED Ballistics=UNVERIFIED FiringReadiness=UNVERIFIED DamageProcessing=UNVERIFIED CombatEligibility=UNVERIFIED LineOfSight=UNVERIFIED Writes=NONE'
        Record 'OtherHeadSamples=NOT_REQUESTED_WEAPON_MODE'
        Record 'CombatStateSamples=NOT_REQUESTED_WEAPON_MODE'
        Record 'ZoneProtectionSamples=NOT_REQUESTED_WEAPON_MODE'
        Record 'PlayerStateSamples=NOT_REQUESTED_WEAPON_MODE'
        Record 'TeamPolicy=NOT_REQUESTED_WEAPON_MODE'
        Record 'MatchDamagePolicy=NOT_REQUESTED_WEAPON_MODE'
    } elseif ($ProbeMatchDamagePolicy) {
        $stage = 'MatchDamagePolicy'
        $damageStart = $reader.PhysicalCalls
        $damage = $reader.SampleMatchDamagePolicy($kernel, $game, $module, $layout, $objects, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during match-damage policy sampling.' }
        $damageSummary = $damage.Status
        Record "MatchDamagePolicy=$($damage.Status) ContextVerified=$($damage.ContextVerified) AdditionalPhysicalReads=$($reader.PhysicalCalls - $damageStart) Detail=$($damage.Detail)"
        if ($damage.ContextVerified) {
            $predicate = if ($null -eq $damage.Predicate) { 'UNKNOWN' } else { [string]$damage.Predicate }
            Record "MatchDamageObservation GameModeRaw=$($damage.GameModeRaw) GameModeStatus=$($damage.GameModeStatus) GameClass=$($damage.GameClass) CurrentMatchGame=0x$($damage.CurrentMatchGame.ToString('x')) MethodRVA=0x$($damage.MethodRva.ToString('x')) LocalPlayer=0x$($damage.LocalPlayer.ToString('x')) OtherPlayer=0x$($damage.OtherPlayer.ToString('x')) OtherRosterIndex=$($damage.OtherRosterIndex) MembershipProof=$($damage.MembershipProof) CountersChangedSinceRoster=$($damage.CountersChangedSinceRoster) CountersChangedDuringCapture=$($damage.CountersChangedDuringCapture) Observations=$($damage.Observations)"
            Record "MatchDamagePredicate=$predicate ArgumentIndependent=$($damage.ArgumentIndependent) Predicate=CurrentMatchGame.CanTakeDamage Scope=MATCH_POLICY_ONLY GameMethodCalls=NONE"
        }
        if ($damage.Status -ceq 'FAIL') { $failed = $true }
        Record 'MatchDamageSemantics CombatEligibility=UNVERIFIED Hostility=UNVERIFIED WeaponContext=UNVERIFIED CompleteDamageImmunity=UNVERIFIED LineOfSight=UNVERIFIED Writes=NONE'
        Record 'OtherHeadSamples=NOT_REQUESTED_DAMAGE_POLICY_MODE'
        Record 'CombatStateSamples=NOT_REQUESTED_DAMAGE_POLICY_MODE'
        Record 'ZoneProtectionSamples=NOT_REQUESTED_DAMAGE_POLICY_MODE'
        Record 'PlayerStateSamples=NOT_REQUESTED_DAMAGE_POLICY_MODE'
        Record 'TeamPolicy=NOT_REQUESTED_DAMAGE_POLICY_MODE'
    } elseif ($ProbeZoneProtection) {
        $stage = 'ZoneProtectionSamples'
        $zoneStart = $reader.PhysicalCalls
        $zone = $reader.SampleZoneProtection($kernel, $game, $module, $layout, $objects, $ZoneRosterIndex, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during zone/protection sampling.' }
        $zoneSummary = $zone.StopReason
        Record "ZoneProtectionSamples AdditionalPhysicalReads=$($reader.PhysicalCalls - $zoneStart) Attempted=$($zone.Samples.Length) Sampled=$($zone.Sampled) StopReason=$($zone.StopReason) Detail=$($zone.Detail)"
        foreach ($sample in $zone.Samples) {
            if ($sample.Status -ceq 'SAMPLED_READ_ONLY') {
                $trainingZone = if ($null -eq $sample.TrainingZone) { 'UNKNOWN' } else { [string]$sample.TrainingZone }
                $battleZone = if ($null -eq $sample.InBattleZone) { 'UNKNOWN' } else { [string]$sample.InBattleZone }
                $shootingRange = if ($null -eq $sample.InShootingRange) { 'UNKNOWN' } else { [string]$sample.InShootingRange }
                $invincible = if ($null -eq $sample.Invincible) { 'UNKNOWN' } else { [string]$sample.Invincible }
                $mask = if ($null -eq $sample.InvincibilityMask) { 'UNKNOWN' } else { [string]$sample.InvincibilityMask }
                $maskMode = if ($null -eq $sample.InvincibilityMode) { 'UNKNOWN' } else { [string]$sample.InvincibilityMode }
                Record "ZoneProtection=$($sample.Status) RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) Class=$($sample.Class) GameModeRaw=$($sample.GameModeRaw) GameModeStatus=$($sample.GameModeStatus) MembershipProof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Observations=$($sample.Observations)"
                Record "TrainingZone=$trainingZone Status=$($sample.ZoneStatus) InBattleZone=$battleZone InShootingRange=$shootingRange PoolClass=$($sample.PoolClass)"
                Record "InvincibilityPredicate=$invincible Status=$($sample.ProtectionStatus) Mask=$mask MaskMode=$maskMode Predicate=PlayerAttributes.IsInvincible"
            } else {
                Record "ZoneProtection=$($sample.Status) RosterIndex=$($sample.RosterIndex) Class=$($sample.Class) Detail=$($sample.Detail)"
                if ($sample.Status -ceq 'FAIL') { $failed = $true }
            }
        }
        if ($zone.StopReason -in @('FAIL', 'FINAL_CONTEXT_FAILED')) { $failed = $true }
        Record 'ZoneProtectionSemantics CombatEligibility=UNVERIFIED Hostility=UNVERIFIED CompleteDamageImmunity=UNVERIFIED LineOfSight=UNVERIFIED Writes=NONE'
        Record 'OtherHeadSamples=NOT_REQUESTED_ZONE_MODE'
        Record 'CombatStateSamples=NOT_REQUESTED_ZONE_MODE'
        Record 'PlayerStateSamples=NOT_REQUESTED_ZONE_MODE'
        Record 'TeamPolicy=NOT_REQUESTED_ZONE_MODE'
    } elseif ($ProbeCombatState) {
        $stage = 'CombatStateSamples'
        $combatStart = $reader.PhysicalCalls
        $combat = $reader.SampleCombatState($kernel, $game, $module, $layout, $objects, $CombatRosterIndex, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during combat-state sampling.' }
        $combatSummary = $combat.StopReason
        Record "CombatStateSamples AdditionalPhysicalReads=$($reader.PhysicalCalls - $combatStart) Attempted=$($combat.Samples.Length) Sampled=$($combat.Sampled) StopReason=$($combat.StopReason) Detail=$($combat.Detail)"
        foreach ($sample in $combat.Samples) {
            if ($sample.Status -ceq 'SAMPLED_READ_ONLY') {
                $watching = if ($null -eq $sample.IsWatching) { 'UNKNOWN' } else { [string]$sample.IsWatching }
                $ghost = if ($null -eq $sample.IsInAnyGhost) { 'UNKNOWN' } else { [string]$sample.IsInAnyGhost }
                $dying = if ($null -eq $sample.IsDieing) { 'UNKNOWN' } else { [string]$sample.IsDieing }
                $reallyDead = if ($null -eq $sample.ReallyDead) { 'UNKNOWN' } else { [string]$sample.ReallyDead }
                $movement = if ($null -eq $sample.MovementStateRaw) { 'UNKNOWN' } else { [string]$sample.MovementStateRaw }
                $stateId = if ($null -eq $sample.ControllerStateRaw) { 'UNKNOWN' } else { [string]$sample.ControllerStateRaw }
                $selector = if ($null -eq $sample.DirectMovementSelector) { 'UNKNOWN' } else { [string]$sample.DirectMovementSelector }
                Record "CombatState=$($sample.Status) RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) Class=$($sample.Class) IsLocal=$($sample.IsLocal) GameModeRaw=$($sample.GameModeRaw) GameModeStatus=$($sample.GameModeStatus) BaseDeadRaw=$($sample.BaseDeadRaw) PendingReviveRaw=$($sample.PendingReviveRaw) ReallyDead=$reallyDead ReallyDeadStatus=$($sample.ReallyDeadStatus) MembershipProof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Observations=$($sample.Observations)"
                Record "WatchingPredicate=$watching Status=$($sample.WatchingStatus) GameClass=$($sample.WatchingGameClass) BooleanOnly=True CounterWrites=NONE"
                Record "GhostPredicate=$ghost Status=$($sample.GhostStatus) GhostKindRaw=$($sample.GhostKindRaw)"
                Record "DyingPredicate=$dying Status=$($sample.DyingStatus) DirectMovementSelector=$selector MovementStateRaw=$movement ControllerStateRaw=$stateId ControllerStateClass=$($sample.ControllerStateClass)"
            } else {
                Record "CombatState=$($sample.Status) RosterIndex=$($sample.RosterIndex) Class=$($sample.Class) Detail=$($sample.Detail)"
                if ($sample.Status -ceq 'FAIL') { $failed = $true }
            }
        }
        if ($combat.StopReason -in @('FAIL', 'FINAL_CONTEXT_FAILED')) { $failed = $true }
        Record 'CombatSemantics CombatEligibility=UNVERIFIED Hostility=UNVERIFIED ModeZoneRules=UNVERIFIED Invulnerability=UNVERIFIED LineOfSight=UNVERIFIED Writes=NONE'
        Record 'OtherHeadSamples=NOT_REQUESTED_COMBAT_MODE'
        Record 'PlayerStateSamples=NOT_REQUESTED_COMBAT_MODE'
        Record 'TeamPolicy=NOT_REQUESTED_COMBAT_MODE'
    } elseif ($ProbeTeamPolicy) {
        $stage = 'TeamPolicy'
        $teamStart = $reader.PhysicalCalls
        $team = $reader.SampleTeamPolicy($kernel, $game, $module, $layout, $objects, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during team-policy sampling.' }
        $teamSummary = $team.Status
        Record "TeamPolicy=$($team.Status) ContextVerified=$($team.ContextVerified) AdditionalPhysicalReads=$($reader.PhysicalCalls - $teamStart) Detail=$($team.Detail)"
        if ($team.ContextVerified) {
            $sameTeam = if ($null -eq $team.SameTeam) { 'UNKNOWN' } else { [string]$team.SameTeam }
            $dynamicTeams = if ($null -eq $team.EnableDynamicTeamID) { 'UNKNOWN' } else { [string]$team.EnableDynamicTeamID }
            $dynamicDictionary = if ($null -eq $team.DynamicDictionaryPresent) { 'UNKNOWN' } else { [string]$team.DynamicDictionaryPresent }
            $localTeamByte = if ($null -eq $team.LocalTeamByte) { 'UNKNOWN' } else { [string]$team.LocalTeamByte }
            $otherTeamByte = if ($null -eq $team.OtherTeamByte) { 'UNKNOWN' } else { [string]$team.OtherTeamByte }
            Record "TeamPolicyObservation Route=$($team.Route) GameModeRaw=$($team.GameModeRaw) GameClass=$($team.GameClass) EnableDynamicTeamID=$dynamicTeams DynamicDictionaryPresent=$dynamicDictionary LocalPlayer=0x$($team.LocalPlayer.ToString('x')) OtherPlayer=0x$($team.OtherPlayer.ToString('x')) OtherRosterIndex=$($team.OtherRosterIndex) MembershipProof=$($team.MembershipProof) CountersChangedSinceRoster=$($team.CountersChangedSinceRoster) CountersChangedDuringCapture=$($team.CountersChangedDuringCapture) Observations=$($team.Observations)"
            Record "SameTeamPredicate=$sameTeam Predicate=GameFacade.IsSameTeam(local,other) LocalPolicyByte=$localTeamByte OtherPolicyByte=$otherTeamByte"
        }
        if ($team.Status -ceq 'FAIL') { $failed = $true }
        Record 'TeamPolicySemantics Hostility=UNVERIFIED CombatEligibility=UNVERIFIED LineOfSight=UNVERIFIED Writes=NONE'
        Record 'OtherHeadSamples=NOT_REQUESTED_TEAM_MODE'
        Record 'PlayerStateSamples=NOT_REQUESTED_TEAM_MODE'
    } elseif ($ProbePlayerState) {
        $stage = 'PlayerStateSamples'
        $stateStart = $reader.PhysicalCalls
        $states = $reader.SamplePlayerStates($kernel, $game, $module, $layout, $objects, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during state sampling.' }
        Record "PlayerStateSamples AdditionalPhysicalReads=$($reader.PhysicalCalls - $stateStart) Attempted=$($states.Samples.Length) Sampled=$($states.Sampled) StopReason=$($states.StopReason) Detail=$($states.Detail)"
        foreach ($sample in $states.Samples) {
            if ($sample.Status -ceq 'SAMPLED_READ_ONLY') {
                $reallyDead = if ($null -eq $sample.ReallyDead) { 'UNKNOWN' } else { [string]$sample.ReallyDead }
                $modelVisible = if ($null -eq $sample.ModelVisible) { 'UNKNOWN' } else { [string]$sample.ModelVisible }
                $visibilityMask = if ($null -eq $sample.VisibilityMask) { 'UNKNOWN' } else { [string]$sample.VisibilityMask }
                $visibilityMode = if ($null -eq $sample.VisibilityMode) { 'UNKNOWN' } else { [string]$sample.VisibilityMode }
                Record "PlayerState=$($sample.Status) RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) Class=$($sample.Class) IsLocal=$($sample.IsLocal) TeamIndexRaw=$($sample.TeamIndex) BaseDeadRaw=$($sample.BaseDeadRaw) PendingReviveRaw=$($sample.PendingReviveRaw) ReallyDeadStatus=$($sample.ReallyDeadStatus) ReallyDead=$reallyDead ModelVisibilityStatus=$($sample.ModelVisibilityStatus) ModelVisible=$modelVisible VisibilityMask=$visibilityMask VisibilityMode=$visibilityMode MembershipProof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Observations=$($sample.Observations)"
            } else {
                Record "PlayerState=$($sample.Status) RosterIndex=$($sample.RosterIndex) Class=$($sample.Class) Detail=$($sample.Detail)"
                if ($sample.Status -ceq 'FAIL') { $failed = $true }
            }
        }
        if ($states.StopReason -in @('FAIL', 'FINAL_CONTEXT_FAILED')) { $failed = $true }
        Record 'StateSemantics TeamPolicy=UNVERIFIED CombatEligibility=UNVERIFIED Knockout=UNVERIFIED LineOfSight=UNVERIFIED Writes=NONE'
        Record 'OtherHeadSamples=NOT_REQUESTED_STATE_MODE'
    } else {
        $stage = 'OtherHeadSamples'
        $otherHeadStart = $reader.PhysicalCalls
        $otherHeads = $reader.SampleOtherPlayerHeads($kernel, $game, $module, $layout, $objects, $progress)
        if ((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId) { throw 'Game PID changed during other-head sampling.' }
        Record "OtherHeadSamples AdditionalPhysicalReads=$($reader.PhysicalCalls - $otherHeadStart) Eligible=$($otherHeads.Eligible) Attempted=$($otherHeads.Samples.Length) Sampled=$($otherHeads.Sampled) StopReason=$($otherHeads.StopReason) Detail=$($otherHeads.Detail)"
        $culture = [Globalization.CultureInfo]::InvariantCulture
        foreach ($sample in $otherHeads.Samples) {
            if ($sample.Status -ceq 'SAMPLED_READ_ONLY') {
                Record "OtherHeadWorldPosition=$($sample.Status) RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) Class=$($sample.Class) MembershipProof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Source=$($sample.Source) X=$($sample.X.ToString('R', $culture)) Y=$($sample.Y.ToString('R', $culture)) Z=$($sample.Z.ToString('R', $culture)) Attempts=$($sample.Attempts) ParentCount=$($sample.ParentCount) Observations=$($sample.Observations) Provider=0x$($sample.Provider.ToString('x')) Transform=0x$($sample.Transform.ToString('x'))"
            } else {
                Record "OtherHeadWorldPosition=$($sample.Status) RosterIndex=$($sample.RosterIndex) Player=0x$($sample.Player.ToString('x')) Class=$($sample.Class) MembershipProof=$($sample.MembershipProof) CountersChangedSinceRoster=$($sample.CountersChangedSinceRoster) CountersChangedDuringCapture=$($sample.CountersChangedDuringCapture) Attempts=$($sample.Attempts) Detail=$($sample.Detail)"
                if ($sample.Status -ceq 'FAIL') { $failed = $true }
            }
        }
        if ($otherHeads.StopReason -in @('FAIL', 'FINAL_CONTEXT_FAILED')) { $failed = $true }
    }
    Record "AimIntegration=INCOMPLETE LocalPlayerObjects=VERIFIED LocalHeadWorldPosition=$($objects.HeadWorldStatus) OtherPlayerObjectsVerified=$($objects.RosterOtherVerified) OtherHeadPositionsSampled=$($otherHeads.Sampled) TeamPolicy=$teamSummary CombatState=$combatSummary ZoneProtection=$zoneSummary MatchDamagePolicy=$damageSummary WeaponContext=$weaponSummary WeaponFiring=$firingSummary WeaponAmmo=$ammoSummary AimState=$aimStateSummary TeamAliveVisibilitySemantics=UNVERIFIED AimWrites=NONE"
} catch { $failed = $true; Failure $stage $_.Exception }
finally {
    if ($null -ne $reader) {
        Record "PhysicalReadCalls=$($reader.PhysicalCalls) TranslationCacheHits=$($reader.TranslationCacheHits)"
        if ($null -ne $reader.LastLibraries) {
            Record "LibraryScanTotals VmasVisited=$($reader.LastLibraries.VmasVisited) FilesInspected=$($reader.LastLibraries.FilesInspected) RepeatedFilesSkipped=$($reader.LastLibraries.RepeatedFilesSkipped)"
            Record "LibraryScanStop Reason=$($reader.LastLibraries.StopReason) CompleteVmaList=$($reader.LastLibraries.CompleteVmaList)"
        }
    }
    if ($loaded) {
        try {
            $debugger.UnloadPlugIn($loadedName)
            Record 'PluginUnload=PASS'
            if ([string]$debugger.Info('help', '') -match '(?im)^\s*headbridge\s') { throw 'Handler remains after unload.' }
            Record 'HandlerCleanup=PASS'
        } catch { $failed = $true; Failure 'PluginUnload' $_.Exception }
    }
    if ($locked) {
        try { $session.UnlockMachine(); Record 'SharedSession=RELEASED' }
        catch { $failed = $true; Failure 'SharedSessionRelease' $_.Exception }
    }
    try {
        $report = Join-Path $PSScriptRoot ('process-map-result-' + [guid]::NewGuid().ToString('N') + '.txt')
        $lines | Set-Content -LiteralPath $report -Encoding UTF8
        Write-Host "ResultFile=$report"
    } catch { $failed = $true; Write-Host "ResultFile=UNAVAILABLE $($_.Exception.Message)" }
}
if ($failed) { exit 1 }
