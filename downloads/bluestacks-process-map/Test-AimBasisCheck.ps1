$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'AimBasisCheck.ps1')
$script:aimChecks=0
function Check-AimComparison { param([bool]$Ok,[string]$Name) if (-not $Ok) { throw "FAIL: $Name" };$script:aimChecks++;Write-Host "PASS: $Name" }
function Reject-AimReport { param([string[]]$Lines,[string]$Name) $rejected=$false;try { $null=ConvertFrom-AimBasisReport $Lines } catch { $rejected=$true };Check-AimComparison $rejected $Name }
function New-AimFixture {
    param([double]$Yaw=0,[double]$Elevation=0)
    $yr=$Yaw*[Math]::PI/360;$pr=$Elevation*[Math]::PI/360
    $x=-[Math]::Sin($pr)*[Math]::Cos($yr);$y=[Math]::Sin($yr)*[Math]::Cos($pr);$z=[Math]::Sin($yr)*[Math]::Sin($pr);$w=[Math]::Cos($yr)*[Math]::Cos($pr)
    $bx=2*($x*$z+$w*$y);$by=2*($y*$z-$w*$x);$bz=1-2*($x*$x+$y*$y)
    $culture=[Globalization.CultureInfo]::InvariantCulture
    @(
        'ProcessMapVersion=37 ReadOnly=1',
        'Preflight=PASS Machine=Pie64 HostPID=100 VmmDigest=MATCH',
        'SelectedDevice=127.0.0.1:5555 State=device',
        'GameIdentity=PASS GuestPID=200 Name=.dts.freefireth',
        'GameModuleIdentity=PASS LoadBias=0x700000000000 BuildId=ee8bf32c4483429084fde022704ead01a94b6620 LoadSegments=8 WindowVmas=16 Fingerprints=4',
        'ApkReferenceSHA256=549093d79212873f26bc13f8957d06cc7575e92f24b53721eb13e8a0a53cb657 RuntimeVerification=ELF_TABLES_SEGMENT_OFFSETS_BUILD_ID_AND_CODE_SAMPLES',
        'GameLayoutComparisonSummary Checks=80 Passes=2 DistinctMismatches=0 MismatchObservations=0 ChangedBetweenPasses=0',
        'GameLayoutRegistration=PASS Fields=9 Methods=9 Checks=80 Passes=2',
        'AimStateSamples AdditionalPhysicalReads=3407 Attempted=1 Sampled=1 StopReason=SELECTED_OBJECTS_EXHAUSTED Detail=',
        'LocalAimRotation=ORIGINAL_LOCAL_GET_AIM_ROTATION_SAMPLED GetterRVA=0x6f249ac BackingFieldOffset=0x614 Scope=ORIGINAL_LOCAL_GETTER CurrentAimRotationField=NOT_REQUESTED CameraOrientation=UNVERIFIED',
        ('AimQuaternion X='+$x.ToString('R',$culture)+' Y='+$y.ToString('R',$culture)+' Z='+$z.ToString('R',$culture)+' W='+$w.ToString('R',$culture)+' NormSquared=1 NormalizedByProbe=False'),
        ('QuaternionPositiveZBasis X='+$bx.ToString('R',$culture)+' Y='+$by.ToString('R',$culture)+' Z='+$bz.ToString('R',$culture)+' InputBasis=0,0,1 Math=VERIFIED_UNITY_QUATERNION_VECTOR_MULTIPLY NormalizedByProbe=False CameraConvention=UNVERIFIED ShotDirection=UNVERIFIED'),
        'LocalPlayerObjects=PASS CurrentGame=0x700020000000 Match=0x700030000000 Player=0x700010000000 Class=COW.GamePlay.PlayerNetwork Observations=281 OriginalPathHotfixSlots=INACTIVE',
        'AimStateMembership RosterIndex=0 Player=0x700010000000 IsLocal=True Proof=SELECTED_ENTRY_REVALIDATED CountersChangedSinceRoster=False CountersChangedDuringCapture=False Observations=98',
        'AimStateSemantics TargetDirection=NOT_REQUESTED CameraConvention=UNVERIFIED FiringReadiness=UNVERIFIED LineOfSight=UNVERIFIED GameMethodCalls=NONE AimWrites=NONE',
        'PhysicalReadCalls=25377 TranslationCacheHits=3721',
        'PluginUnload=PASS','HandlerCleanup=PASS','SharedSession=RELEASED'
    )
}
function Read-AimFixture { param([double]$Yaw=0,[double]$Elevation=0) ConvertFrom-AimBasisReport (New-AimFixture $Yaw $Elevation) }
$baseline=Read-AimFixture;$right=Read-AimFixture 30 0;$up=Read-AimFixture 30 20
$result=Compare-AimBasisSamples @($baseline,$right,$up)
Check-AimComparison ($result.Status -eq 'CONSISTENT_WITH_REPORTED_CAMERA_TURNS' -and [Math]::Abs($result.RightYawDelta-30) -lt 0.00001 -and [Math]::Abs($result.UpElevationDelta-20) -lt 0.00001) 'manual camera correlation recognizes independent right and upward changes'
Check-AimComparison ($result.Evidence -eq 'MANUAL_CAMERA_TURN_CORRELATION_ONLY' -and $result.CameraConvention -eq 'UNVERIFIED' -and $result.ShotDirection -eq 'UNVERIFIED' -and $result.AimWrites -eq 'NONE') 'matching turns do not assert camera or shot convention'
Check-AimComparison ((Compare-AimBasisSamples @((Read-AimFixture 170), (Read-AimFixture -160), (Read-AimFixture -160 20))).Status -eq 'CONSISTENT_WITH_REPORTED_CAMERA_TURNS') 'yaw crossing plus/minus 180 wraps correctly'
foreach ($case in @(@(0,0),@(-30,0),@(100,0))) {
    Check-AimComparison ((Compare-AimBasisSamples @($baseline,(Read-AimFixture $case[0] $case[1]),$up)).Status -eq 'INCONCLUSIVE_TURN_DIRECTION_OR_SIZE') "absent reversed or excessive horizontal turn remains inconclusive: $($case[0])"
}
Check-AimComparison ((Compare-AimBasisSamples @($baseline,$right,(Read-AimFixture 30 -20))).Status -eq 'INCONCLUSIVE_TURN_DIRECTION_OR_SIZE') 'downward turn cannot satisfy upward instruction'
Check-AimComparison ((Compare-AimBasisSamples @($baseline,(Read-AimFixture 30 10),(Read-AimFixture 30 30))).Status -eq 'INCONCLUSIVE_CROSS_AXIS_MOVEMENT') 'elevation drift during horizontal turn remains inconclusive'
Check-AimComparison ((Compare-AimBasisSamples @($baseline,$right,(Read-AimFixture 45 20))).Status -eq 'INCONCLUSIVE_CROSS_AXIS_MOVEMENT') 'yaw drift during upward turn remains inconclusive'
Check-AimComparison ((Compare-AimBasisSamples @((Read-AimFixture 0 75),(Read-AimFixture 30 75),(Read-AimFixture 30 80))).Status -eq 'INCONCLUSIVE_NEAR_VERTICAL') 'near-vertical captures avoid unstable yaw inference'
foreach ($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame')) {
    $changed=Read-AimFixture 30 20;$changed.$key='changed'
    Check-AimComparison ((Compare-AimBasisSamples @($baseline,$right,$changed)).Status -eq 'INCONCLUSIVE_CONTEXT_CHANGED') "changed $key prevents combining camera captures"
}
$fixture=New-AimFixture
$old=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=37','ProcessMapVersion=36') })
Check-AimComparison ((ConvertFrom-AimBasisReport $old).Version -eq 36) 'accepted V36 report remains supported'
foreach ($pair in @(@('Sampled=1','Sampled=0'),@('CountersChangedDuringCapture=False','CountersChangedDuringCapture=True'),@('IsLocal=True','IsLocal=False'),@('AdditionalPhysicalReads=3407','AdditionalPhysicalReads=6001'),@('PhysicalReadCalls=25377','PhysicalReadCalls=30001'),@('PluginUnload=PASS','PluginUnload=FAIL'),@('SharedSession=RELEASED','SharedSession=LOCKED'),@('NormSquared=1 ','NormSquared=0.5 '),@('Basis X=0','Basis X=0.5'),@('W=1 ','W=NaN '),@('Player=0x700010000000','Player=0x0'),@('GameMethodCalls=NONE','GameMethodCalls=CALLED'))) {
    Reject-AimReport @($fixture | ForEach-Object { $_.Replace($pair[0],$pair[1]) }) "reject invalid camera report: $($pair[0])"
}
Reject-AimReport @($fixture+$fixture[0]) 'duplicate version record is rejected'
Reject-AimReport @($fixture | Where-Object { $_ -notmatch '^QuaternionPositiveZBasis ' }) 'missing basis record is rejected'
$oldCulture=[Threading.Thread]::CurrentThread.CurrentCulture
try {
    [Threading.Thread]::CurrentThread.CurrentCulture=[Globalization.CultureInfo]::GetCultureInfo('fr-FR')
    Check-AimComparison ([Math]::Abs((ConvertFrom-AimBasisReport (New-AimFixture 30 20)).Elevation-20) -lt 0.00001) 'dot decimal report parsing is independent of host culture'
} finally { [Threading.Thread]::CurrentThread.CurrentCulture=$oldCulture }
$thrown=$false;try { $null=Compare-AimBasisSamples @($baseline,$right) } catch { $thrown=$true };Check-AimComparison $thrown 'incomplete manual experiment cannot establish correlation'
Write-Host "AIM_COMPARISON_TOTAL=$script:aimChecks"
# Exercise the interactive wrapper using fake child-process output, never a VM.
$global:aimHarnessRoot=Join-Path ([IO.Path]::GetTempPath()) ('aim-wrapper-test-'+[guid]::NewGuid().ToString('N'))
[void](New-Item -ItemType Directory -Path $global:aimHarnessRoot)
try {
    foreach ($name in @('Run-AimBasisCheck.ps1','AimBasisCheck.ps1','Run-ProcessMap.ps1')) { Copy-Item -LiteralPath (Join-Path $PSScriptRoot $name) -Destination $global:aimHarnessRoot }
    @{ aim_basis_comparison_sha256=(Get-FileHash (Join-Path $global:aimHarnessRoot 'AimBasisCheck.ps1')).Hash; runner_sha256=(Get-FileHash (Join-Path $global:aimHarnessRoot 'Run-ProcessMap.ps1')).Hash } | ConvertTo-Json | Set-Content (Join-Path $global:aimHarnessRoot 'manifest.json')
    $global:aimHarnessCount=0;$global:aimHarnessCancel=$false;$global:aimHarnessFail=$false
    function Read-Host { param([string]$Prompt) if ($global:aimHarnessCancel) { return 'CANCEL' };return 'READY' }
    function powershell.exe {
        if ($args -notcontains '-ProbeAimState') { throw 'Expected aim state child mode.' }
        $global:aimHarnessCount++
        $yaw=0;$elevation=0;if ($global:aimHarnessCount -ge 2) { $yaw=30 };if ($global:aimHarnessCount -ge 3) { $elevation=20 }
        $lines=New-AimFixture $yaw $elevation
        $path=Join-Path $global:aimHarnessRoot ('process-map-result-'+[guid]::NewGuid().ToString('N')+'.txt')
        $lines | Set-Content -LiteralPath $path
        if ($global:aimHarnessFail) { $global:LASTEXITCODE=1 } else { $global:LASTEXITCODE=0 }
        $lines;"ResultFile=$path"
    }
    $null=& (Join-Path $global:aimHarnessRoot 'Run-AimBasisCheck.ps1') 6>&1
    $results=@(Get-ChildItem -LiteralPath $global:aimHarnessRoot -Filter 'aim-basis-comparison-*.json')
    $saved=Get-Content -LiteralPath $results[0].FullName -Raw | ConvertFrom-Json
    Check-AimComparison ($global:aimHarnessCount -eq 3 -and $results.Count -eq 1 -and $saved.SourceReports.Count -eq 3 -and $saved.Status -eq 'CONSISTENT_WITH_REPORTED_CAMERA_TURNS') 'wrapper performs three explicit manual stages and saves separate child reports plus comparison'
    Add-Content -LiteralPath (Join-Path $global:aimHarnessRoot 'AimBasisCheck.ps1') -Value '# tampered'
    $failed=$false;try { $null=& (Join-Path $global:aimHarnessRoot 'Run-AimBasisCheck.ps1') 6>&1 } catch { $failed=$_.Exception.Message -like '*checksum mismatch*' }
    Check-AimComparison ($failed -and $global:aimHarnessCount -eq 3) 'wrapper rejects helper checksum mismatch before any child capture'
    Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'AimBasisCheck.ps1') -Destination $global:aimHarnessRoot -Force
    $global:aimHarnessCancel=$true;$failed=$false;try { $null=& (Join-Path $global:aimHarnessRoot 'Run-AimBasisCheck.ps1') 6>&1 } catch { $failed=$_.Exception.Message -like '*Capture cancelled*' }
    Check-AimComparison ($failed -and $global:aimHarnessCount -eq 3) 'manual cancellation launches no child capture'
    $global:aimHarnessCancel=$false;$global:aimHarnessFail=$true;$failed=$false;try { $null=& (Join-Path $global:aimHarnessRoot 'Run-AimBasisCheck.ps1') 6>&1 } catch { $failed=$_.Exception.Message -like '*Capture failed*' }
    Check-AimComparison ($failed -and $global:aimHarnessCount -eq 4 -and @(Get-ChildItem -LiteralPath $global:aimHarnessRoot -Filter 'aim-basis-comparison-*.json').Count -eq 1) 'child failure stops the experiment without saving a new successful comparison'
} finally {
    Remove-Item -LiteralPath $global:aimHarnessRoot -Recurse -Force
    Remove-Item Function:Read-Host,Function:powershell.exe -ErrorAction SilentlyContinue
    Remove-Variable -Scope Global -Name aimHarnessRoot,aimHarnessCount,aimHarnessCancel,aimHarnessFail -ErrorAction SilentlyContinue
}
Write-Host "AIM_COMPARISON_WITH_RUNNER_TOTAL=$script:aimChecks"
