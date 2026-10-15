[CmdletBinding()]
param(
    [string] $MachineName = 'Pie64',
    [ValidatePattern('^[A-Za-z0-9_.:-]+$')]
    [string] $Device = '127.0.0.1:5555'
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
Record 'ProcessMapVersion=14 ReadOnly=1'
try {
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
        $manifest.native_transform_reference_sha256 -notmatch '^[0-9a-fA-F]{64}$') { throw 'Package manifest is invalid.' }
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
        (Get-FileHash -LiteralPath $nativeTransformReferencePath -Algorithm SHA256).Hash -ine $manifest.native_transform_reference_sha256) {
        throw 'Package DLL or mapper source checksum mismatch.'
    }
    Add-Type -Path @($sourcePath, $modulePath, $referencePath, $layoutPath, $layoutReferencePath, $objectPath, $objectReferencePath, $headCachePath, $nativeTransformPath, $nativeTransformReferencePath) -ErrorAction Stop
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
        Record "LocalHeadWorldPosition=SAMPLED_READ_ONLY X=$($objects.HeadWorldX.ToString('R', $culture)) Y=$($objects.HeadWorldY.ToString('R', $culture)) Z=$($objects.HeadWorldZ.ToString('R', $culture)) ParentCount=$($objects.HeadParentCount) HierarchyCapacity=$($objects.HeadHierarchyCapacity) Observations=$($objects.HeadWorldObservations) NativeTransform=0x$($objects.NativeHeadTransform.ToString('x')) UnityLoadBias=0x$($objects.UnityLoadBias.ToString('x'))"
    } else {
        Record "LocalHeadWorldPosition=$($objects.HeadWorldStatus) Detail=$($objects.HeadWorldError)"
        if ($objects.HeadWorldStatus -ceq 'FAIL') { $failed = $true }
    }
    Record "AimIntegration=INCOMPLETE LocalPlayerObjects=VERIFIED LocalHeadWorldPosition=$($objects.HeadWorldStatus) OtherPlayers=UNVERIFIED VisibilitySemantics=UNVERIFIED AimWrites=NONE"
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
