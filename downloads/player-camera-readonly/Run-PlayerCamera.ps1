[CmdletBinding()]
param([string]$MachineName='Pie64',[ValidatePattern('^[A-Za-z0-9_.:-]+$')][string]$Device='127.0.0.1:5555',[string]$RuntimeDirectory,[switch]$ProbeCameraIdentity)
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
# BEGIN IDENTITY PROOF
function Identity-Proof([object]$Value){if($null-eq $Value){return 'UNVERIFIED'};return ([bool]$Value).ToString()}
# END IDENTITY PROOF
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
if(!$RuntimeDirectory){$RuntimeDirectory=Join-Path $PSScriptRoot 'baseline';if(!(Test-Path -LiteralPath $RuntimeDirectory)){$RuntimeDirectory=Join-Path $PSScriptRoot '..\bluestacks-process-map'}}
$runtimeRoot=(Resolve-Path -LiteralPath $RuntimeDirectory).Path
Record 'PlayerCameraProbeVersion=4 BaseRunner=52 ReadOnly=1'
try {
    if ([Environment]::OSVersion.Platform -ne [PlatformID]::Win32NT -or -not [Environment]::Is64BitProcess) {
        throw 'Use 64-bit Windows PowerShell on the BlueStacks PC.'
    }
    $principal = [Security.Principal.WindowsPrincipal]::new([Security.Principal.WindowsIdentity]::GetCurrent())
    if (-not $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) { throw 'Use Administrator PowerShell.' }
    $manifest = Get-Content -LiteralPath (Join-Path $runtimeRoot 'manifest.json') -Raw | ConvertFrom-Json
    if((Get-FileHash -LiteralPath (Join-Path $runtimeRoot 'manifest.json') -Algorithm SHA256).Hash -ine '03a3d4fc4b719d1481f67a5eaea901e34db5f1a87ebd710ce160e01c171b854a'){throw 'Expected immutable V52 baseline manifest.'}
    $extension=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'manifest.json') -Raw|ConvertFrom-Json
    foreach($name in @('Run-PlayerCamera.ps1','PlayerCameraReference.cs','PlayerCameraProbe.cs','GuestProcessMap.Diagnostics.cs')){
        $entry=@($extension.files|Where-Object name -CEQ $name)
        if($entry.Count -ne 1 -or (Get-FileHash -LiteralPath (Join-Path $PSScriptRoot $name) -Algorithm SHA256).Hash -ine $entry[0].sha256){throw "Player-camera source integrity mismatch: $name"}
    }

    $pluginPath = Join-Path $runtimeRoot 'VBoxDbgHeadAimBridge.dll'
    $sourcePath = Join-Path $runtimeRoot 'GuestProcessMap.cs'
    $modulePath = Join-Path $runtimeRoot 'ModuleProbe.cs'
    $referencePath = Join-Path $runtimeRoot 'ModuleReference.cs'
    $layoutPath = Join-Path $runtimeRoot 'GameLayoutProbe.cs'
    $layoutReferencePath = Join-Path $runtimeRoot 'GameLayoutReference.cs'
    $objectPath = Join-Path $runtimeRoot 'PlayerObjectProbe.cs'
    $objectReferencePath = Join-Path $runtimeRoot 'ObjectReference.cs'
    $headCachePath = Join-Path $runtimeRoot 'HeadCacheProbe.cs'
    $nativeTransformPath = Join-Path $runtimeRoot 'NativeTransformProbe.cs'
    $nativeTransformReferencePath = Join-Path $runtimeRoot 'NativeTransformReference.cs'
    $rosterPath = Join-Path $runtimeRoot 'RosterProbe.cs'
    $rosterReferencePath = Join-Path $runtimeRoot 'RosterReference.cs'
    $otherHeadPath = Join-Path $runtimeRoot 'OtherHeadProbe.cs'
    $statePath = Join-Path $runtimeRoot 'PlayerStateProbe.cs'
    $stateReferencePath = Join-Path $runtimeRoot 'PlayerStateReference.cs'
    $teamPath = Join-Path $runtimeRoot 'TeamPolicyProbe.cs'
    $teamReferencePath = Join-Path $runtimeRoot 'TeamPolicyReference.cs'
    $combatPath = Join-Path $runtimeRoot 'CombatStateProbe.cs'
    $combatReferencePath = Join-Path $runtimeRoot 'CombatStateReference.cs'
    $zonePath = Join-Path $runtimeRoot 'ZoneProtectionProbe.cs'
    $zoneReferencePath = Join-Path $runtimeRoot 'ZoneProtectionReference.cs'
    $damagePath = Join-Path $runtimeRoot 'MatchDamageProbe.cs'
    $damageReferencePath = Join-Path $runtimeRoot 'MatchDamageReference.cs'
    $weaponPath = Join-Path $runtimeRoot 'WeaponContextProbe.cs'
    $weaponReferencePath = Join-Path $runtimeRoot 'WeaponContextReference.cs'
    $firingPath = Join-Path $runtimeRoot 'WeaponFiringProbe.cs'
    $firingReferencePath = Join-Path $runtimeRoot 'WeaponFiringReference.cs'
    $ammoPath = Join-Path $runtimeRoot 'WeaponAmmoProbe.cs'
    $ammoReferencePath = Join-Path $runtimeRoot 'WeaponAmmoReference.cs'
    $aimStatePath = Join-Path $runtimeRoot 'AimStateProbe.cs'
    $aimStateReferencePath = Join-Path $runtimeRoot 'AimStateReference.cs'
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
    # BEGIN COMPATIBLE COMPILE
    $compileArguments = @{ Path = @((Join-Path $PSScriptRoot 'GuestProcessMap.Diagnostics.cs'), $modulePath, $referencePath, $layoutPath, $layoutReferencePath, $objectPath, $objectReferencePath, $headCachePath, $nativeTransformPath, $nativeTransformReferencePath, $rosterPath, $rosterReferencePath, $otherHeadPath, $statePath, $stateReferencePath, $teamPath, $teamReferencePath, $combatPath, $combatReferencePath, $zonePath, $zoneReferencePath, $damagePath, $damageReferencePath, $weaponPath, $weaponReferencePath, $firingPath, $firingReferencePath, $ammoPath, $ammoReferencePath, $aimStatePath, $aimStateReferencePath, (Join-Path $PSScriptRoot 'PlayerCameraProbe.cs'), (Join-Path $PSScriptRoot 'PlayerCameraReference.cs')); ErrorAction = 'Stop' }
    if ((Get-Command Add-Type).Parameters.ContainsKey('CompilerOptions')) {
        $compileArguments.CompilerOptions = @('/langversion:5')
    }
    Add-Type @compileArguments
    # END COMPATIBLE COMPILE
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
    $stage='PlayerCameraContext'
    $objects=$reader.VerifyPlayerCameraContext($kernel,$game,$module,$layout,$progress)
    Record "LocalPlayerObjects=PASS CurrentGame=0x$($objects.CurrentGame.ToString('x')) Match=0x$($objects.Match.ToString('x')) Player=0x$($objects.LocalPlayer.ToString('x')) Class=$($objects.PlayerClass) Scope=ORIGINAL_LOCAL_CONTEXT_ONLY FullRoster=NOT_REQUESTED"
    if($ProbeCameraIdentity){
        $stage='CameraIdentity'
        $identity=$reader.InspectPlayerCameraIdentity($kernel,$game,$module,$layout,$objects,$progress)
        if((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId){throw 'Game PID changed during identity inventory.'}
        $reader.Recheck($kernel,$game)
        # BEGIN IDENTITY RENDER
        Record "CameraIdentity Status=$($identity.Status) AdditionalReads=$($identity.AdditionalReads) Observations=$($identity.Observations)"
        if($null-eq $identity.Sources){$failed=$true}else{
            $source=$identity.Sources
            Record "CameraIdentityPlayer ManagedTransform=0x$($identity.PlayerManagedTransform.ToString('x')) NativeTransform=0x$($identity.PlayerNativeTransform.ToString('x'))"
            Record "CameraIdentityOriginalMain Selection=$($source.CameraSelectionStatus) UnityCode=$($source.CameraUnityCodeStatus) NativeCamera=0x$($source.SelectedNativeCamera.ToString('x')) NativeTransform=0x$($identity.OriginalMainNativeTransform.ToString('x')) TransformMatchesPlayer=$(Identity-Proof $identity.OriginalMainTransformMatchesPlayer)"
            Record "CameraIdentityController Inventory=$($source.CameraControllerInventoryStatus) ManagedCamera=0x$($source.ControllerManagedCamera.ToString('x')) CachedNative=0x$($source.ControllerCachedNative.ToString('x')) MatchesOriginalMain=$(Identity-Proof $source.ControllerNativeMatchesSelection)"
            Record "CameraIdentityGetter Gate=$($source.GameCameraGateStatus) GetterInit=$($source.GameCameraGetterInitRaw) PatchInit=$($source.GameCameraPatchInitRaw) HotfixSlot=$(Identity-Proof $source.GameCameraHotfixSlotPresent) NullPredicate=$($source.CameraNullPredicateStatus)"
        }
        # END IDENTITY RENDER
        Record 'CameraIdentityLimits Projection=UNVERIFIED_NOT_READ FOV=UNVERIFIED_NOT_READ RenderFrame=UNVERIFIED GameGetterExecuted=False FunctionsInvoked=False AimWrites=NONE'
    }else{
    $stage='PlayerCameraPose'
    $started=[DateTime]::UtcNow.ToString('o')
    $captureTimer=[Diagnostics.Stopwatch]::StartNew()
    $pose=$reader.SamplePlayerCameraPose($kernel,$game,$module,$layout,$objects,$progress)
    $captureTimer.Stop()
    $finished=[DateTime]::UtcNow.ToString('o')
    if((Shell 'pidof com.dts.freefireth').Trim() -cne $gameProcessId){throw 'Game PID changed during camera sampling.'}
    $reader.Recheck($kernel,$game)
    # BEGIN POSE RENDER
    Record "PlayerCameraPose Status=$($pose.Status) Attempts=$($pose.Attempts) AdditionalReads=$($pose.AdditionalReads) ManagedTransform=0x$($pose.ManagedTransform.ToString('x')) NativeTransform=0x$($pose.NativeTransform.ToString('x')) UnityLoadBias=0x$($pose.UnityLoadBias.ToString('x')) ParentCount=$($pose.ParentCount) Observations=$($pose.Observations)"
    Record "PlayerCameraCapture StartUtc=$started EndUtc=$finished DurationMs=$($captureTimer.ElapsedMilliseconds) TimingScope=METHOD_CALL_INTERVAL_ONLY_RENDER_SYNC_UNKNOWN"
    if($pose.Status -ceq 'SAMPLED_READ_ONLY'){
        $culture=[Globalization.CultureInfo]::InvariantCulture
        $v=@($pose.Position|ForEach-Object {$_.ToString('R',$culture)});$q=@($pose.Rotation|ForEach-Object {$_.ToString('R',$culture)})
        Record "PlayerCameraWorldPosition X=$($v[0]) Y=$($v[1]) Z=$($v[2]) Source=REGISTERED_PLAYER_MAIN_CAMERA_TRANSFORM"
        Record "PlayerCameraWorldRotation X=$($q[0]) Y=$($q[1]) Z=$($q[2]) W=$($q[3]) Normalized=False Source=VERIFIED_UNITY_TRANSFORM_MATH"
    }else{$failed=$true;Record "PlayerCameraDetail=$($pose.Detail)"}
    # END POSE RENDER
    }
    Record 'CameraSemantics ActualRenderedCamera=UNVERIFIED ShotDirection=UNVERIFIED LOS=UNVERIFIED GlobalAtomicFrame=NOT_ASSERTED FunctionsInvoked=False AimWrites=NONE'
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
        $report = Join-Path $PSScriptRoot ('player-camera-result-' + [guid]::NewGuid().ToString('N') + '.txt')
        $lines | Set-Content -LiteralPath $report -Encoding UTF8
        Write-Host "ResultFile=$report"
    } catch { $failed = $true; Write-Host "ResultFile=UNAVAILABLE $($_.Exception.Message)" }
}
if ($failed) { exit 1 }
