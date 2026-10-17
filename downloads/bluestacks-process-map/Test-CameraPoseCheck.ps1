$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'AimBasisCheck.ps1')
. (Join-Path $PSScriptRoot 'CameraPoseCheck.ps1')
$script:poseChecks=0
function Check-Pose { param([bool]$Ok,[string]$Name) if (-not $Ok) { throw "FAIL: $Name" };$script:poseChecks++;Write-Host "PASS: $Name" }
function Reject-Pose {param([string[]]$Lines,[string]$Name) $bad=$false;try {$null=ConvertFrom-CameraPoseReport $Lines}catch{$bad=$true};Check-Pose $bad $Name}
function New-PoseBaseFixture {
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
function New-PoseFixture {
    param([double]$Yaw=0,[double]$Elevation=0,[switch]$DifferentAim)
    $native=@(New-PoseBaseFixture $Yaw $Elevation)
    $lines=if ($DifferentAim) { @(New-PoseBaseFixture) } else { $native }
    $lines=@($lines | ForEach-Object { $_.Replace('ProcessMapVersion=38','ProcessMapVersion=47') })
    $q=Match-AimReportLine $native 'AimQuaternion' '^AimQuaternion X=(\S+) Y=(\S+) Z=(\S+) W=(\S+) NormSquared=(\S+) NormalizedByProbe=False$'
    $b=Match-AimReportLine $native 'QuaternionPositiveZBasis' '^QuaternionPositiveZBasis X=(\S+) Y=(\S+) Z=(\S+) '
    $lines+="CameraUnityCode Status=REGISTERED_ENTRIES_AND_CODE_VERIFIED LoadBias=0x3200000 BuildId=667862f2d29b22ee ReferenceFileSHA256=1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77 MainRVA=0x41d8c4 ComponentTransformRVA=0x453d04 CodeScope=MAIN_24_COMPONENT_460_BYTES SelectedCamera=UNVERIFIED ManagedCamera=NOT_READ CameraPose=UNVERIFIED FunctionsInvoked=False"
    $lines+='CameraMainSelection Status=ORIGINAL_UNITY_MAIN_SELECTED_READ_ONLY NativeObject=0x71001000 Owner=0x71002000 PredicateRawByte=1 PredicatesEvaluated=1 CompleteSourceSelection=True Scope=ORIGINAL_UNITY_NATIVE_SELECTOR EvaluatedBy=READ_ONLY_SOURCE_EQUIVALENT FunctionsInvoked=False ManagedCamera=NOT_READ CameraPose=UNVERIFIED GameGetterHotfix=NOT_EVALUATED'
    $lines+='CameraWorldPosition Status=ORIGINAL_NATIVE_CAMERA_WORLD_POSITION_READ_ONLY NativeTransform=0x71003000 X=2 Y=3 Z=4 ParentCount=0 Scope=ORIGINAL_UNITY_NATIVE_SELECTOR_TRANSFORM_INTERMEDIATE Rotation=SEE_CAMERA_WORLD_ROTATION ActualGameCamera=UNVERIFIED GameGetterHotfix=NOT_EVALUATED FunctionsInvoked=False AimWrites=NONE'
    $lines+="CameraWorldRotation Status=ORIGINAL_NATIVE_CAMERA_WORLD_ROTATION_READ_ONLY X=$($q.Groups[1].Value) Y=$($q.Groups[2].Value) Z=$($q.Groups[3].Value) W=$($q.Groups[4].Value) NormSquared=$($q.Groups[5].Value) PositiveZBasisX=$($b.Groups[1].Value) PositiveZBasisY=$($b.Groups[2].Value) PositiveZBasisZ=$($b.Groups[3].Value) Scope=ORIGINAL_UNITY_NATIVE_SELECTOR_TRANSFORM_INTERMEDIATE NormalizedByProbe=False CameraConvention=UNVERIFIED ActualGameCamera=UNVERIFIED ShotDirection=UNVERIFIED FunctionsInvoked=False AimWrites=NONE"
    return $lines
}
function New-PoseSequence {
    param([switch]$DifferentAim)
    foreach ($a in @(@(0,0),@(-25,0),@(0,0),@(25,0),@(0,0),@(0,20),@(0,0),@(0,-20))) {
        ConvertFrom-CameraPoseReport (New-PoseFixture $a[0] $a[1] -DifferentAim:$DifferentAim)
    }
}
$valid=@(New-PoseFixture -25 10)
$parsed=ConvertFrom-CameraPoseReport $valid
Check-Pose ([Math]::Abs($parsed.Yaw+25) -lt 0.00001 -and [Math]::Abs($parsed.Elevation-10) -lt 0.00001 -and $parsed.CameraPosition[0] -eq 2 -and $parsed.NativeTransform -eq '71003000') 'native camera parser retains source pose, position and identity'
Check-Pose ($parsed.AimCameraDifferenceDegrees -lt 0.0001 -and $parsed.MeasurementScope -eq 'ORIGINAL_NATIVE_CAMERA_POSITIVE_Z_BASIS') 'matching camera/aim quaternions have a near-zero angle metric only'
Reject-Pose @($valid + @($valid | Where-Object {$_ -match '^CameraWorldRotation '})) 'duplicate native rotation record is rejected'
foreach ($case in @(
    @('NativeTransform=0x71003000','NativeTransform=0x71001000'),@('Owner=0x71002000','Owner=0x71002001'),@('LoadBias=0x3200000','LoadBias=0x3200008'),
    @('PredicateRawByte=1','PredicateRawByte=0'),@('PredicateRawByte=1','PredicateRawByte=256'),@('ParentCount=0','ParentCount=32'),
    @('NativeTransform=0x71003000 X=2','NativeTransform=0x71003000 X=NaN'),@('PositiveZBasisX=','ChangedBasisX='),
    @('NormalizedByProbe=False','NormalizedByProbe=True'),@('FunctionsInvoked=False','FunctionsInvoked=True'),
    @('Status=ORIGINAL_NATIVE_CAMERA_WORLD_ROTATION_READ_ONLY','Status=FAIL'),@('CompleteSourceSelection=True','CompleteSourceSelection=False'),
    @('ProcessMapVersion=47','ProcessMapVersion=45'),@('SharedSession=RELEASED','SharedSession=LOCKED'),@('BuildId=667862f2d29b22ee','BuildId=0000000000000000')
)) { Reject-Pose @($valid | ForEach-Object { $_.Replace($case[0],$case[1]) }) "native pose refuses malformed/unverified report: $($case[1])" }
$badBasis=@($valid | ForEach-Object { if ($_ -match '^CameraWorldRotation ') { $_ -replace 'PositiveZBasisY=\S+','PositiveZBasisY=99' } else { $_ } })
Reject-Pose $badBasis 'native basis must agree with camera quaternion, independently of aim basis'
$badNorm=@($valid | ForEach-Object { if ($_ -match '^CameraWorldRotation ') { $_ -replace 'NormSquared=\S+','NormSquared=2' } else { $_ } })
Reject-Pose $badNorm 'reported native quaternion norm must match raw components'
$sign=@(New-PoseFixture | ForEach-Object { if ($_ -match '^CameraWorldRotation ') { $_ -replace ' W=1 ',' W=-1 ' } else { $_ } })
$signed=ConvertFrom-CameraPoseReport $sign
Check-Pose ($signed.AimCameraDifferenceDegrees -lt 0.00001 -and $signed.CameraQuaternion[3] -eq -1) 'q and minus-q compare as the same orientation while raw quaternion remains unchanged'
$fractional=ConvertFrom-CameraPoseReport (New-PoseFixture 1.25 0 -DifferentAim)
Check-Pose ([Math]::Abs($fractional.AimCameraDifferenceDegrees-1.25) -lt 0.000001) 'subdegree-sensitive angle metric uses floating-point Math overloads without integer rounding'
$quarter=ConvertFrom-CameraPoseReport (New-PoseFixture 90 90)
Check-Pose ([Math]::Abs($quarter.CameraNormSquared-1) -lt 0.00001) 'four fractional quaternion components contribute to a double-precision norm'
$sequence=@(New-PoseSequence);$comparison=Compare-CameraPoseSamples $sequence
Check-Pose ($comparison.Status -eq 'REPORTED_NATIVE_CAMERA_TURNS_OBSERVED' -and $comparison.Yaw.ObservedYawSign -eq 'REPORTED_RIGHT_NEGATIVE_LEFT_POSITIVE' -and $comparison.Pitch.ObservedPitchSign -eq 'REPORTED_UP_POSITIVE_DOWN_NEGATIVE') 'eight native camera captures correlate both reported horizontal and vertical turns'
Check-Pose ($comparison.ActualGameCamera -eq 'UNVERIFIED' -and $comparison.CameraConvention -eq 'UNVERIFIED' -and $comparison.AimWrites -eq 'NONE' -and $comparison.Samples.Count -eq 8) 'manual pose correlation retains all captures and does not assert game camera or aim integration'
$independent=Compare-CameraPoseSamples @(New-PoseSequence -DifferentAim)
Check-Pose ($independent.Status -eq 'REPORTED_NATIVE_CAMERA_TURNS_OBSERVED' -and -not $independent.AimCameraWithinOneDegree -and $independent.MaximumAimCameraDifferenceDegrees -gt 20) 'native camera turn evidence does not substitute an unchanged player aim quaternion'
foreach ($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame','NativeCamera','NativeOwner','NativeTransform','UnityLoadBias')) {
    $changed=@(New-PoseSequence);$changed[7].$key='changed'
    Check-Pose ((Compare-CameraPoseSamples $changed).Status -eq 'INCONCLUSIVE_CONTEXT_CHANGED') "native pose comparison refuses changed $key"
}
$unrestored=@(New-PoseSequence);$unrestored[2]=ConvertFrom-CameraPoseReport (New-PoseFixture 10)
Check-Pose ((Compare-CameraPoseSamples $unrestored).Status -eq 'INCONCLUSIVE_CAMERA_TURNS') 'unrestored native baseline cannot complete the experiment'
$still=@(0..7 | ForEach-Object {ConvertFrom-CameraPoseReport (New-PoseFixture)})
Check-Pose ((Compare-CameraPoseSamples $still).Status -eq 'INCONCLUSIVE_CAMERA_TURNS') 'unchanged native pose never establishes turn correlation'
$short=$false;try{$null=Compare-CameraPoseSamples @($sequence[0..6])}catch{$short=$true};Check-Pose $short 'seven reports cannot complete the eight-capture experiment'
$global:poseHarnessRoot=Join-Path ([IO.Path]::GetTempPath()) ('camera-pose-test-'+[guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $global:poseHarnessRoot | Out-Null
try {
    foreach ($name in @('AimBasisCheck.ps1','CameraPoseCheck.ps1','Run-CameraPoseCheck.ps1','Run-ProcessMap.ps1')) {Copy-Item -LiteralPath (Join-Path $PSScriptRoot $name) -Destination $global:poseHarnessRoot}
    @{aim_basis_comparison_sha256=(Get-FileHash (Join-Path $global:poseHarnessRoot 'AimBasisCheck.ps1')).Hash.ToLowerInvariant();camera_pose_comparison_sha256=(Get-FileHash (Join-Path $global:poseHarnessRoot 'CameraPoseCheck.ps1')).Hash.ToLowerInvariant();runner_sha256=(Get-FileHash (Join-Path $global:poseHarnessRoot 'Run-ProcessMap.ps1')).Hash.ToLowerInvariant()} | ConvertTo-Json | Set-Content (Join-Path $global:poseHarnessRoot 'manifest.json')
    $global:poseHarnessCount=0;$global:poseHarnessMode='OK';$global:poseHarnessPrompts=@()
    function Read-Host {param([string]$Prompt) $global:poseHarnessPrompts+=$Prompt;if($global:poseHarnessMode -eq 'CANCEL'){return 'CANCEL'};return 'READY'}
    function powershell.exe {
        if($args -notcontains '-ProbeAimState'){throw 'Expected read-only aim-state capture.'}
        $global:poseHarnessCount++;$a=@(@(0,0),@(-25,0),@(0,0),@(25,0),@(0,0),@(0,20),@(0,0),@(0,-20))[($global:poseHarnessCount-1)%8]
        $lines=@(New-PoseFixture $a[0] $a[1]);if($global:poseHarnessMode -eq 'BAD'){$lines=@($lines | Where-Object {$_ -notmatch '^CameraWorldRotation '})}
        $path=Join-Path $global:poseHarnessRoot ('process-map-result-'+[guid]::NewGuid().ToString('N')+'.txt');$lines | Set-Content -LiteralPath $path
        if($global:poseHarnessMode -eq 'STALE'){(Get-Item -LiteralPath $path).LastWriteTimeUtc=[DateTime]::UtcNow.AddDays(-1)}
        $global:LASTEXITCODE=if($global:poseHarnessMode -eq 'FAIL'){1}else{0};$lines;"ResultFile=$path"
    }
    $null=& (Join-Path $global:poseHarnessRoot 'Run-CameraPoseCheck.ps1') 6>&1
    $results=@(Get-ChildItem -LiteralPath $global:poseHarnessRoot -Filter 'camera-pose-comparison-*.json');$saved=Get-Content $results[0].FullName -Raw | ConvertFrom-Json
    Check-Pose ($global:poseHarnessCount -eq 8 -and $results.Count -eq 1 -and $saved.SourceReports.Count -eq 8 -and $saved.SourceReportSHA256.Count -eq 8 -and $saved.Status -eq 'REPORTED_NATIVE_CAMERA_TURNS_OBSERVED' -and $global:poseHarnessPrompts[1] -match 'RIGHT' -and $global:poseHarnessPrompts[7] -match 'DOWN') 'manual pose wrapper runs eight explicit stages and saves source reports, hashes and native comparisons'
    foreach($mode in @('CANCEL','FAIL','STALE','BAD')){
        $global:poseHarnessMode=$mode;$global:poseHarnessCount=0;$failed=$false;try{$null=& (Join-Path $global:poseHarnessRoot 'Run-CameraPoseCheck.ps1') 6>&1}catch{$failed=$true}
        Check-Pose ($failed -and $global:poseHarnessCount -le 1 -and @(Get-ChildItem -LiteralPath $global:poseHarnessRoot -Filter 'camera-pose-comparison-*.json').Count -eq 1) "pose wrapper stops on $mode without publishing another comparison"
    }
    $global:poseHarnessMode='OK';$global:poseHarnessCount=0;Add-Content (Join-Path $global:poseHarnessRoot 'CameraPoseCheck.ps1') '# tampered';$failed=$false;try{$null=& (Join-Path $global:poseHarnessRoot 'Run-CameraPoseCheck.ps1') 6>&1}catch{$failed=$true}
    Check-Pose ($failed -and $global:poseHarnessCount -eq 0) 'pose helper checksum mismatch prevents any child capture'
} finally {
    Remove-Item -LiteralPath $global:poseHarnessRoot -Recurse -Force
    Remove-Item Function:Read-Host,Function:powershell.exe -ErrorAction SilentlyContinue
    Remove-Variable -Scope Global -Name poseHarnessRoot,poseHarnessCount,poseHarnessMode,poseHarnessPrompts -ErrorAction SilentlyContinue
}
Write-Host "CAMERA_POSE_COMPARISON_TOTAL=$script:poseChecks"
