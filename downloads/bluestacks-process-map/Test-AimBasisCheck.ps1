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
        'ProcessMapVersion=38 ReadOnly=1',
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
$old=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=36') })
Check-AimComparison ((ConvertFrom-AimBasisReport $old).Version -eq 36) 'accepted V36 report remains supported'
Check-AimComparison ((ConvertFrom-AimBasisReport (@('')+$fixture+@(''))).Version -eq 38) 'blank pasted-output lines do not invalidate accepted records'
$version44=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=44') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version44).Version -eq 44) 'V44 comparison input remains supported'
$version45=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=45') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version45).Version -eq 45) 'V45 comparison input remains supported'
$version46=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=46') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version46).Version -eq 46) 'V46 comparison input remains supported'
$version43=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=43') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version43).Version -eq 43) 'V43 comparison input remains supported'
$version42=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=42') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version42).Version -eq 42) 'V42 comparison input remains supported'
$version41=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=41') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version41).Version -eq 41) 'V41 comparison input remains supported'
$version40=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=40') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version40).Version -eq 40) 'V40 comparison input remains supported'
$version39=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=39') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version39).Version -eq 39) 'V39 comparison input remains supported'
$version37=@($fixture | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=37') })
Check-AimComparison ((ConvertFrom-AimBasisReport $version37).Version -eq 37) 'V37 comparison input remains supported'
foreach ($flags in @(@('True','False'),@('False','True'),@('True','True'))) {
    $changed=@($fixture | ForEach-Object { $_.Replace('CountersChangedSinceRoster=False','CountersChangedSinceRoster='+$flags[0]).Replace('CountersChangedDuringCapture=False','CountersChangedDuringCapture='+$flags[1]) })
    $parsed=ConvertFrom-AimBasisReport $changed
    Check-AimComparison ($parsed.CountersChangedSinceRoster -eq ($flags[0] -eq 'True') -and $parsed.CountersChangedDuringCapture -eq ($flags[1] -eq 'True') -and $parsed.MembershipScope -eq 'SELECTED_LOCAL_PLAYER_ONLY') "global roster counter flags are retained with verified local membership: $($flags -join ',')"
}
$counterSample=Read-AimFixture 30 20;$counterSample.CountersChangedDuringCapture=$true
$counterResult=Compare-AimBasisSamples @($baseline,$right,$counterSample)
Check-AimComparison ($counterResult.Status -eq 'CONSISTENT_WITH_REPORTED_CAMERA_TURNS' -and $counterResult.CapturesWithRosterCounterChanges -eq 1 -and $counterResult.MembershipScope -eq 'SELECTED_LOCAL_PLAYER_ONLY') 'local-only comparison audits global changes without claiming complete roster stability'
Reject-AimReport @($fixture | ForEach-Object { $_.Replace('Proof=SELECTED_ENTRY_REVALIDATED','Proof=UNVERIFIED') }) 'unverified selected membership still fails despite valid roster flags'
foreach ($pair in @(@('Sampled=1','Sampled=0'),@('CountersChangedDuringCapture=False','CountersChangedDuringCapture=INVALID'),@('IsLocal=True','IsLocal=False'),@('AdditionalPhysicalReads=3407','AdditionalPhysicalReads=6001'),@('PhysicalReadCalls=25377','PhysicalReadCalls=30001'),@('PluginUnload=PASS','PluginUnload=FAIL'),@('SharedSession=RELEASED','SharedSession=LOCKED'),@('NormSquared=1 ','NormSquared=0.5 '),@('Basis X=0','Basis X=0.5'),@('W=1 ','W=NaN '),@('Player=0x700010000000','Player=0x0'),@('GameMethodCalls=NONE','GameMethodCalls=CALLED'))) {
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
# A counterturn is required before reporting either observed yaw-sign convention.
$yn=Compare-CameraYawSamples @((Read-AimFixture),(Read-AimFixture -30),(Read-AimFixture),(Read-AimFixture 25))
Check-AimComparison ($yn.Status -eq 'REPORTED_OPPOSITE_YAW_SIGNS_OBSERVED' -and $yn.ObservedYawSign -eq 'REPORTED_RIGHT_NEGATIVE_LEFT_POSITIVE' -and -not $yn.VectorFlipped -and $yn.CameraConvention -eq 'UNVERIFIED' -and $yn.ShotDirection -eq 'UNVERIFIED') 'negative reported right plus positive left is observed without flipping vectors or asserting camera convention'
$yp=Compare-CameraYawSamples @((Read-AimFixture),(Read-AimFixture 30),(Read-AimFixture),(Read-AimFixture -25))
Check-AimComparison ($yp.Status -eq 'REPORTED_OPPOSITE_YAW_SIGNS_OBSERVED' -and $yp.ObservedYawSign -eq 'REPORTED_RIGHT_POSITIVE_LEFT_NEGATIVE') 'opposite reported yaw-sign pattern is equally supported'
$yw=Compare-CameraYawSamples @((Read-AimFixture 170),(Read-AimFixture -160),(Read-AimFixture 170),(Read-AimFixture 140))
Check-AimComparison ($yw.Status -eq 'REPORTED_OPPOSITE_YAW_SIGNS_OBSERVED' -and [Math]::Abs($yw.RightYawDelta-30) -lt 0.00001) 'four-stage yaw experiment handles 180-degree wrap'
foreach ($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame')) {
    $changed=Read-AimFixture -25;$changed.$key='changed'
    $yr=Compare-CameraYawSamples @($baseline,$right,$baseline,$changed)
    Check-AimComparison ($yr.Status -eq 'INCONCLUSIVE_CONTEXT_CHANGED' -and $yr.ObservedYawSign -eq 'UNVERIFIED') "yaw sign inference refuses changed $key"
}
foreach ($case in @(@(0,-25),@(100,-25),@(30,0),@(30,-100))) {
    Check-AimComparison ((Compare-CameraYawSamples @($baseline,(Read-AimFixture $case[0]),$baseline,(Read-AimFixture $case[1]))).Status -eq 'INCONCLUSIVE_TURN_SIZE') "yaw sign refuses small/large turn pair $($case -join ',')"
}
Check-AimComparison ((Compare-CameraYawSamples @($baseline,$right,$baseline,(Read-AimFixture 25))).Status -eq 'INCONCLUSIVE_TURN_SIGNS_NOT_OPPOSITE') 'same-sign right/left reports remain inconclusive'
Check-AimComparison ((Compare-CameraYawSamples @((Read-AimFixture 0 75),(Read-AimFixture 30 75),(Read-AimFixture 0 75),(Read-AimFixture -25 75))).Status -eq 'INCONCLUSIVE_NEAR_VERTICAL') 'yaw sign remains unverified near vertical'
Check-AimComparison ((Compare-CameraYawSamples @($baseline,$right,(Read-AimFixture 10),(Read-AimFixture -25))).Status -eq 'INCONCLUSIVE_BASELINE_NOT_RESTORED') 'landmark yaw must return close to baseline'
Check-AimComparison ((Compare-CameraYawSamples @($baseline,$right,(Read-AimFixture 0 10),(Read-AimFixture -25 10))).Status -eq 'INCONCLUSIVE_BASELINE_NOT_RESTORED') 'landmark height must return close to baseline'
Check-AimComparison ((Compare-CameraYawSamples @($baseline,(Read-AimFixture 30 10),$baseline,(Read-AimFixture -25))).Status -eq 'INCONCLUSIVE_VERTICAL_DRIFT') 'right turn vertical drift prevents yaw sign inference'
Check-AimComparison ((Compare-CameraYawSamples @($baseline,$right,$baseline,(Read-AimFixture -25 10))).Status -eq 'INCONCLUSIVE_VERTICAL_DRIFT') 'left turn vertical drift prevents yaw sign inference'
$yc=Read-AimFixture -25;$yc.CountersChangedDuringCapture=$true
$ya=Compare-CameraYawSamples @($baseline,$right,$baseline,$yc)
Check-AimComparison ($ya.Status -eq 'REPORTED_OPPOSITE_YAW_SIGNS_OBSERVED' -and $ya.CapturesWithRosterCounterChanges -eq 1 -and $ya.MembershipScope -eq 'SELECTED_LOCAL_PLAYER_ONLY') 'four-stage experiment audits global roster changes with selected local proof'
$thrown=$false;try { $null=Compare-CameraYawSamples @($baseline,$right,$baseline) } catch { $thrown=$true };Check-AimComparison $thrown 'three captures cannot complete four-stage sign experiment'

$pn=Compare-CameraPitchSamples @((Read-AimFixture),(Read-AimFixture 0 20),(Read-AimFixture),(Read-AimFixture 0 -20))
Check-AimComparison ($pn.Status -eq 'REPORTED_OPPOSITE_PITCH_SIGNS_OBSERVED' -and $pn.ObservedPitchSign -eq 'REPORTED_UP_POSITIVE_DOWN_NEGATIVE' -and -not $pn.VectorFlipped -and $pn.CameraConvention -eq 'UNVERIFIED' -and $pn.ShotDirection -eq 'UNVERIFIED') 'reported up-positive/down-negative correlation preserves source vectors and unverified camera convention'
$pp=Compare-CameraPitchSamples @((Read-AimFixture),(Read-AimFixture 0 -20),(Read-AimFixture),(Read-AimFixture 0 20))
Check-AimComparison ($pp.Status -eq 'REPORTED_OPPOSITE_PITCH_SIGNS_OBSERVED' -and $pp.ObservedPitchSign -eq 'REPORTED_UP_NEGATIVE_DOWN_POSITIVE') 'opposite vertical sign pattern is equally supported'
$pw=Compare-CameraPitchSamples @((Read-AimFixture 179),(Read-AimFixture -179 20),(Read-AimFixture 179),(Read-AimFixture 177 -20))
Check-AimComparison ($pw.Status -eq 'REPORTED_OPPOSITE_PITCH_SIGNS_OBSERVED' -and [Math]::Abs($pw.UpYawDrift-2) -lt 0.00001) 'pitch experiment measures yaw drift correctly across 180-degree boundary'
foreach ($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame')) {
    $changed=Read-AimFixture 0 -20;$changed.$key='changed'
    $pr=Compare-CameraPitchSamples @($baseline,(Read-AimFixture 0 20),$baseline,$changed)
    Check-AimComparison ($pr.Status -eq 'INCONCLUSIVE_CONTEXT_CHANGED' -and $pr.ObservedPitchSign -eq 'UNVERIFIED') "pitch sign inference refuses changed $key"
}
foreach ($case in @(@(0,-20),@(65,-20),@(20,0),@(20,-65))) {
    Check-AimComparison ((Compare-CameraPitchSamples @($baseline,(Read-AimFixture 0 $case[0]),$baseline,(Read-AimFixture 0 $case[1]))).Status -eq 'INCONCLUSIVE_TURN_SIZE') "pitch sign refuses small/large tilt pair $($case -join ',')"
}
Check-AimComparison ((Compare-CameraPitchSamples @($baseline,(Read-AimFixture 0 20),$baseline,(Read-AimFixture 0 25))).Status -eq 'INCONCLUSIVE_TURN_SIGNS_NOT_OPPOSITE') 'same-sign up/down reports remain inconclusive'
Check-AimComparison ((Compare-CameraPitchSamples @($baseline,(Read-AimFixture 0 75),$baseline,(Read-AimFixture 0 -20))).Status -eq 'INCONCLUSIVE_NEAR_VERTICAL') 'near-vertical tilt cannot establish pitch sign'
Check-AimComparison ((Compare-CameraPitchSamples @($baseline,(Read-AimFixture 0 20),(Read-AimFixture 10),(Read-AimFixture 10 -20))).Status -eq 'INCONCLUSIVE_BASELINE_NOT_RESTORED') 'pitch experiment requires landmark horizontal restoration'
Check-AimComparison ((Compare-CameraPitchSamples @($baseline,(Read-AimFixture 0 20),(Read-AimFixture 0 10),(Read-AimFixture 0 -20))).Status -eq 'INCONCLUSIVE_BASELINE_NOT_RESTORED') 'pitch experiment requires landmark height restoration'
Check-AimComparison ((Compare-CameraPitchSamples @($baseline,(Read-AimFixture 10 20),$baseline,(Read-AimFixture 0 -20))).Status -eq 'INCONCLUSIVE_HORIZONTAL_DRIFT') 'up tilt horizontal drift prevents pitch sign inference'
Check-AimComparison ((Compare-CameraPitchSamples @($baseline,(Read-AimFixture 0 20),$baseline,(Read-AimFixture 10 -20))).Status -eq 'INCONCLUSIVE_HORIZONTAL_DRIFT') 'down tilt horizontal drift prevents pitch sign inference'
$pc=Read-AimFixture 0 -20;$pc.CountersChangedDuringCapture=$true
$pa=Compare-CameraPitchSamples @($baseline,(Read-AimFixture 0 20),$baseline,$pc)
Check-AimComparison ($pa.Status -eq 'REPORTED_OPPOSITE_PITCH_SIGNS_OBSERVED' -and $pa.CapturesWithRosterCounterChanges -eq 1 -and $pa.MembershipScope -eq 'SELECTED_LOCAL_PLAYER_ONLY') 'pitch experiment audits global changes with local membership proof'
$thrown=$false;try { $null=Compare-CameraPitchSamples @($baseline,$baseline,$baseline) } catch { $thrown=$true };Check-AimComparison $thrown 'three captures cannot complete pitch countertilt experiment'

# Exercise the interactive wrapper using fake child-process output, never a VM.
$global:aimHarnessRoot=Join-Path ([IO.Path]::GetTempPath()) ('aim-wrapper-test-'+[guid]::NewGuid().ToString('N'))
[void](New-Item -ItemType Directory -Path $global:aimHarnessRoot)
try {
    foreach ($name in @('Run-AimBasisCheck.ps1','Run-CameraYawCheck.ps1','Run-CameraPitchCheck.ps1','AimBasisCheck.ps1','Run-ProcessMap.ps1')) { Copy-Item -LiteralPath (Join-Path $PSScriptRoot $name) -Destination $global:aimHarnessRoot }
    @{ aim_basis_comparison_sha256=(Get-FileHash (Join-Path $global:aimHarnessRoot 'AimBasisCheck.ps1')).Hash; runner_sha256=(Get-FileHash (Join-Path $global:aimHarnessRoot 'Run-ProcessMap.ps1')).Hash } | ConvertTo-Json | Set-Content (Join-Path $global:aimHarnessRoot 'manifest.json')
    $global:aimHarnessCount=0;$global:aimHarnessCancel=$false;$global:aimHarnessFail=$false;$global:aimHarnessYaw=$false;$global:aimHarnessPitch=$false;$global:aimHarnessPrompts=@()
    function Read-Host { param([string]$Prompt) $global:aimHarnessPrompts+= $Prompt;if ($global:aimHarnessCancel) { return 'CANCEL' };return 'READY' }
    function powershell.exe {
        if ($args -notcontains '-ProbeAimState') { throw 'Expected aim state child mode.' }
        $global:aimHarnessCount++
        $yaw=0;$elevation=0;if ($global:aimHarnessCount -ge 2) { $yaw=30 };if ($global:aimHarnessCount -ge 3) { $elevation=20 }
        if ($global:aimHarnessYaw) { $elevation=0;$yaw=0;if ($global:aimHarnessCount -eq 2) { $yaw=-30 };if ($global:aimHarnessCount -eq 4) { $yaw=25 } }
        if ($global:aimHarnessPitch) { $yaw=0;$elevation=0;if ($global:aimHarnessCount -eq 2) { $elevation=20 };if ($global:aimHarnessCount -eq 4) { $elevation=-20 } }
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
    $global:aimHarnessFail=$false;$global:aimHarnessYaw=$true;$global:aimHarnessCount=0;$global:aimHarnessPrompts=@()
    $null=& (Join-Path $global:aimHarnessRoot 'Run-CameraYawCheck.ps1') 6>&1
    $yawResults=@(Get-ChildItem -LiteralPath $global:aimHarnessRoot -Filter 'camera-yaw-comparison-*.json')
    $yawSaved=Get-Content -LiteralPath $yawResults[0].FullName -Raw | ConvertFrom-Json
    Check-AimComparison ($global:aimHarnessCount -eq 4 -and $yawSaved.SourceReports.Count -eq 4 -and $yawSaved.ObservedYawSign -eq 'REPORTED_RIGHT_NEGATIVE_LEFT_POSITIVE' -and $global:aimHarnessPrompts[0] -match '^BASELINE:' -and $global:aimHarnessPrompts[1] -match '^RIGHT:' -and $global:aimHarnessPrompts[2] -match '^RESTORE:' -and $global:aimHarnessPrompts[3] -match '^LEFT:') 'four-stage wrapper prompts baseline/right/restore/left and saves all reports plus observed sign'
    $global:aimHarnessYaw=$false;$global:aimHarnessPitch=$true;$global:aimHarnessCount=0;$global:aimHarnessPrompts=@()
    $null=& (Join-Path $global:aimHarnessRoot 'Run-CameraPitchCheck.ps1') 6>&1
    $pitchResults=@(Get-ChildItem -LiteralPath $global:aimHarnessRoot -Filter 'camera-pitch-comparison-*.json')
    $pitchSaved=Get-Content -LiteralPath $pitchResults[0].FullName -Raw | ConvertFrom-Json
    Check-AimComparison ($global:aimHarnessCount -eq 4 -and $pitchSaved.SourceReports.Count -eq 4 -and $pitchSaved.ObservedPitchSign -eq 'REPORTED_UP_POSITIVE_DOWN_NEGATIVE' -and $global:aimHarnessPrompts[0] -match '^BASELINE:' -and $global:aimHarnessPrompts[1] -match '^UP:' -and $global:aimHarnessPrompts[2] -match '^RESTORE:' -and $global:aimHarnessPrompts[3] -match '^DOWN:') 'pitch wrapper prompts baseline/up/restore/down and saves all reports plus observed vertical sign'
} finally {
    Remove-Item -LiteralPath $global:aimHarnessRoot -Recurse -Force
    Remove-Item Function:Read-Host,Function:powershell.exe -ErrorAction SilentlyContinue
    Remove-Variable -Scope Global -Name aimHarnessRoot,aimHarnessCount,aimHarnessCancel,aimHarnessFail,aimHarnessYaw,aimHarnessPitch,aimHarnessPrompts -ErrorAction SilentlyContinue
}
Write-Host "AIM_COMPARISON_WITH_RUNNER_TOTAL=$script:aimChecks"
