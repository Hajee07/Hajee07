# Functions only; report text is never executed.
Set-StrictMode -Version 2
function Match-AimReportLine {
    param([string[]]$Lines,[string]$Key,[string]$Pattern)
    $hits=@($Lines | Where-Object { $_ -match ('^'+[regex]::Escape($Key)+'(?:=| )') })
    if ($hits.Count -ne 1) { throw "Expected one $Key record." }
    $m=[regex]::Match([string]$hits[0],$Pattern)
    if (-not $m.Success) { throw "Unaccepted $Key record." }
    return $m
}
function Read-AimNumber {
    param([string]$Text)
    $v=[double]::Parse($Text,[Globalization.CultureInfo]::InvariantCulture)
    if ([double]::IsNaN($v) -or [double]::IsInfinity($v)) { throw 'Nonfinite aim report value.' }
    return $v
}
function ConvertFrom-AimBasisReport {
    param([Parameter(Mandatory=$true)][AllowEmptyString()][string[]]$Lines)
    $version=Match-AimReportLine $Lines 'ProcessMapVersion' '^ProcessMapVersion=(36|37|38|39|40|41|42|43|44|45|46|47|48|49|50|51|52) ReadOnly=1$'
    $hostInfo=Match-AimReportLine $Lines 'Preflight' '^Preflight=PASS Machine=(\S+) HostPID=([1-9][0-9]*) VmmDigest=MATCH$'
    $deviceInfo=Match-AimReportLine $Lines 'SelectedDevice' '^SelectedDevice=(\S+) State=device$'
    $gameInfo=Match-AimReportLine $Lines 'GameIdentity' '^GameIdentity=PASS GuestPID=([1-9][0-9]*) Name=(?:com)?\.dts\.freefireth$'
    $moduleInfo=Match-AimReportLine $Lines 'GameModuleIdentity' '^GameModuleIdentity=PASS LoadBias=(0x[0-9a-fA-F]+) BuildId=(ee8bf32c4483429084fde022704ead01a94b6620) '
    [void](Match-AimReportLine $Lines 'ApkReferenceSHA256' '^ApkReferenceSHA256=549093d79212873f26bc13f8957d06cc7575e92f24b53721eb13e8a0a53cb657 RuntimeVerification=ELF_TABLES_SEGMENT_OFFSETS_BUILD_ID_AND_CODE_SAMPLES$')
    [void](Match-AimReportLine $Lines 'GameLayoutComparisonSummary' '^GameLayoutComparisonSummary Checks=80 Passes=2 DistinctMismatches=0 MismatchObservations=0 ChangedBetweenPasses=0$')
    [void](Match-AimReportLine $Lines 'GameLayoutRegistration' '^GameLayoutRegistration=PASS Fields=9 Methods=9 Checks=80 Passes=2$')
    $phase=Match-AimReportLine $Lines 'AimStateSamples' '^AimStateSamples AdditionalPhysicalReads=([0-9]+) Attempted=1 Sampled=1 StopReason=SELECTED_OBJECTS_EXHAUSTED Detail=$'
    [void](Match-AimReportLine $Lines 'LocalAimRotation' '^LocalAimRotation=ORIGINAL_LOCAL_GET_AIM_ROTATION_SAMPLED GetterRVA=0x6f249ac BackingFieldOffset=0x614 Scope=ORIGINAL_LOCAL_GETTER CurrentAimRotationField=NOT_REQUESTED CameraOrientation=UNVERIFIED$')
    $n='([-+]?(?:[0-9]+(?:\.[0-9]*)?|\.[0-9]+)(?:[eE][-+]?[0-9]+)?)'
    $q=Match-AimReportLine $Lines 'AimQuaternion' ('^AimQuaternion X='+$n+' Y='+$n+' Z='+$n+' W='+$n+' NormSquared='+$n+' NormalizedByProbe=False$')
    $b=Match-AimReportLine $Lines 'QuaternionPositiveZBasis' ('^QuaternionPositiveZBasis X='+$n+' Y='+$n+' Z='+$n+' InputBasis=0,0,1 Math=VERIFIED_UNITY_QUATERNION_VECTOR_MULTIPLY NormalizedByProbe=False CameraConvention=UNVERIFIED ShotDirection=UNVERIFIED$')
    $objects=Match-AimReportLine $Lines 'LocalPlayerObjects' '^LocalPlayerObjects=PASS CurrentGame=(0x[0-9a-fA-F]+) Match=(0x[0-9a-fA-F]+) Player=(0x[0-9a-fA-F]+) Class=(\S+) Observations=([1-9][0-9]*) OriginalPathHotfixSlots=INACTIVE$'
    $member=Match-AimReportLine $Lines 'AimStateMembership' '^AimStateMembership RosterIndex=([0-9]+) Player=(0x[0-9a-fA-F]+) IsLocal=True Proof=SELECTED_ENTRY_REVALIDATED CountersChangedSinceRoster=(True|False) CountersChangedDuringCapture=(True|False) Observations=([1-9][0-9]*)$'
    [void](Match-AimReportLine $Lines 'AimStateSemantics' '^AimStateSemantics TargetDirection=NOT_REQUESTED CameraConvention=UNVERIFIED FiringReadiness=UNVERIFIED LineOfSight=UNVERIFIED GameMethodCalls=NONE AimWrites=NONE$')
    $total=Match-AimReportLine $Lines 'PhysicalReadCalls' '^PhysicalReadCalls=([0-9]+) TranslationCacheHits=[0-9]+$'
    foreach ($key in @('PluginUnload','HandlerCleanup')) { [void](Match-AimReportLine $Lines $key ('^'+$key+'=PASS$')) }
    [void](Match-AimReportLine $Lines 'SharedSession' '^SharedSession=RELEASED$')
    if ([long]$phase.Groups[1].Value -gt 6000 -or [long]$total.Groups[1].Value -gt 30000 -or [long]$member.Groups[1].Value -gt 15) { throw 'Aim report exceeds bounds.' }
    $player=[Convert]::ToUInt64($member.Groups[2].Value.Substring(2),16)
    $bias=[Convert]::ToUInt64($moduleInfo.Groups[1].Value.Substring(2),16)
    $matchPointer=[Convert]::ToUInt64($objects.Groups[2].Value.Substring(2),16)
    $currentGame=[Convert]::ToUInt64($objects.Groups[1].Value.Substring(2),16)
    if ($player -ne [Convert]::ToUInt64($objects.Groups[3].Value.Substring(2),16)) { throw 'Local player identity disagrees with membership.' }
    foreach ($p in @($player,$bias,$matchPointer,$currentGame)) { if ($p -lt 65536 -or $p -ge 0x0000800000000000L) { throw 'Invalid aim report pointer.' } }
    $x=Read-AimNumber $q.Groups[1].Value;$y=Read-AimNumber $q.Groups[2].Value;$z=Read-AimNumber $q.Groups[3].Value;$w=Read-AimNumber $q.Groups[4].Value
    $norm=$x*$x+$y*$y+$z*$z+$w*$w
    if ($norm -lt 0.98 -or $norm -gt 1.02 -or [Math]::Abs($norm-(Read-AimNumber $q.Groups[5].Value)) -gt 0.00001) { throw 'Quaternion norm mismatch.' }
    $bx=Read-AimNumber $b.Groups[1].Value;$by=Read-AimNumber $b.Groups[2].Value;$bz=Read-AimNumber $b.Groups[3].Value
    if ([Math]::Abs($bx-2*($x*$z+$w*$y)) -gt 0.00001 -or [Math]::Abs($by-2*($y*$z-$w*$x)) -gt 0.00001 -or [Math]::Abs($bz-(1-2*($x*$x+$y*$y))) -gt 0.00001) { throw 'Printed basis disagrees with quaternion.' }
    $horizontal=[Math]::Sqrt($bx*$bx+$bz*$bz)
    [pscustomobject]@{ Version=[int]$version.Groups[1].Value; Machine=$hostInfo.Groups[1].Value; HostPid=$hostInfo.Groups[2].Value
        Device=$deviceInfo.Groups[1].Value; GuestPid=$gameInfo.Groups[1].Value; BuildId=$moduleInfo.Groups[2].Value; LoadBias=$bias.ToString('x'); Player=$player.ToString('x'); Match=$matchPointer.ToString('x'); CurrentGame=$currentGame.ToString('x')
        BasisX=$bx; BasisY=$by; BasisZ=$bz; Yaw=[Math]::Atan2($bx,$bz)*180/[Math]::PI; Elevation=[Math]::Atan2($by,$horizontal)*180/[Math]::PI
        CountersChangedSinceRoster=($member.Groups[3].Value -ceq 'True'); CountersChangedDuringCapture=($member.Groups[4].Value -ceq 'True'); MembershipScope='SELECTED_LOCAL_PLAYER_ONLY'
        AdditionalReads=[long]$phase.Groups[1].Value; TotalReads=[long]$total.Groups[1].Value }
}
function Get-AimYawDelta {
    param([double]$From,[double]$To)
    $d=$To-$From
    while ($d -gt 180) { $d-=360 };while ($d -le -180) { $d+=360 }
    return $d
}
function Compare-AimBasisSamples {
    param([Parameter(Mandatory=$true)][object[]]$Samples)
    if ($Samples.Count -ne 3) { throw 'Exactly three ordered captures are required.' }
    $status='CONSISTENT_WITH_REPORTED_CAMERA_TURNS'
    foreach ($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame')) {
        if ([string]$Samples[0].$key -cne [string]$Samples[1].$key -or [string]$Samples[0].$key -cne [string]$Samples[2].$key) { $status='INCONCLUSIVE_CONTEXT_CHANGED';break }
    }
    $rightYaw=Get-AimYawDelta $Samples[0].Yaw $Samples[1].Yaw
    $rightElevation=$Samples[1].Elevation-$Samples[0].Elevation
    $upYaw=Get-AimYawDelta $Samples[1].Yaw $Samples[2].Yaw
    $upElevation=$Samples[2].Elevation-$Samples[1].Elevation
    if ($status -eq 'CONSISTENT_WITH_REPORTED_CAMERA_TURNS') {
        if (@($Samples | Where-Object { [Math]::Abs($_.Elevation) -gt 70 }).Count) { $status='INCONCLUSIVE_NEAR_VERTICAL' }
        elseif ($rightYaw -lt 3 -or $rightYaw -gt 90 -or $upElevation -lt 3 -or $upElevation -gt 60) { $status='INCONCLUSIVE_TURN_DIRECTION_OR_SIZE' }
        elseif ([Math]::Abs($rightElevation) -gt 5 -or [Math]::Abs($upYaw) -gt 5) { $status='INCONCLUSIVE_CROSS_AXIS_MOVEMENT' }
    }
    [pscustomobject]@{ Status=$status; Evidence='MANUAL_CAMERA_TURN_CORRELATION_ONLY'; Actions=@('USER_REPORTED_BASELINE','USER_REPORTED_RIGHT_TURN','USER_REPORTED_UP_TURN_FROM_RIGHT_CAPTURE')
        CapturesWithRosterCounterChanges=@($Samples | Where-Object { $_.CountersChangedSinceRoster -or $_.CountersChangedDuringCapture }).Count; MembershipScope='SELECTED_LOCAL_PLAYER_ONLY'
        RightYawDelta=$rightYaw; RightElevationDrift=$rightElevation; UpYawDrift=$upYaw; UpElevationDelta=$upElevation; Samples=$Samples
        CameraConvention='UNVERIFIED'; ShotDirection='UNVERIFIED'; LineOfSight='UNVERIFIED'; AimWrites='NONE'; AimIntegration='INCOMPLETE' }
}
function Compare-CameraYawSamples {
    param([Parameter(Mandatory=$true)][object[]]$Samples)
    if ($Samples.Count -ne 4) { throw 'Four ordered captures are required: baseline, right, restored baseline, left.' }
    $status='REPORTED_OPPOSITE_YAW_SIGNS_OBSERVED';$sign='UNVERIFIED'
    foreach ($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame')) {
        foreach ($i in 1..3) { if ([string]$Samples[0].$key -cne [string]$Samples[$i].$key) { $status='INCONCLUSIVE_CONTEXT_CHANGED' } }
    }
    $right=Get-AimYawDelta $Samples[0].Yaw $Samples[1].Yaw
    $restore=Get-AimYawDelta $Samples[0].Yaw $Samples[2].Yaw
    $left=Get-AimYawDelta $Samples[2].Yaw $Samples[3].Yaw
    $rightDrift=$Samples[1].Elevation-$Samples[0].Elevation
    $restoreDrift=$Samples[2].Elevation-$Samples[0].Elevation
    $leftDrift=$Samples[3].Elevation-$Samples[2].Elevation
    if ($status -eq 'REPORTED_OPPOSITE_YAW_SIGNS_OBSERVED') {
        if (@($Samples | Where-Object { [Math]::Abs($_.Elevation) -gt 70 }).Count) { $status='INCONCLUSIVE_NEAR_VERTICAL' }
        elseif ([Math]::Abs($restore) -gt 5 -or [Math]::Abs($restoreDrift) -gt 5) { $status='INCONCLUSIVE_BASELINE_NOT_RESTORED' }
        elseif ([Math]::Abs($right) -lt 3 -or [Math]::Abs($right) -gt 90 -or [Math]::Abs($left) -lt 3 -or [Math]::Abs($left) -gt 90) { $status='INCONCLUSIVE_TURN_SIZE' }
        elseif ([Math]::Abs($rightDrift) -gt 5 -or [Math]::Abs($leftDrift) -gt 5) { $status='INCONCLUSIVE_VERTICAL_DRIFT' }
        elseif ($right*$left -ge 0) { $status='INCONCLUSIVE_TURN_SIGNS_NOT_OPPOSITE' }
        elseif ($right -lt 0) { $sign='REPORTED_RIGHT_NEGATIVE_LEFT_POSITIVE' }
        else { $sign='REPORTED_RIGHT_POSITIVE_LEFT_NEGATIVE' }
    }
    [pscustomobject]@{ Status=$status; ObservedYawSign=$sign; Evidence='MANUAL_CAMERA_TURN_CORRELATION_ONLY'
        Actions=@('USER_REPORTED_LANDMARK_BASELINE','USER_REPORTED_RIGHT_TURN','USER_REPORTED_RESTORED_LANDMARK_BASELINE','USER_REPORTED_LEFT_TURN')
        RightYawDelta=$right; RestoredBaselineYawError=$restore; LeftYawDelta=$left
        RightElevationDrift=$rightDrift; RestoredBaselineElevationError=$restoreDrift; LeftElevationDrift=$leftDrift
        CapturesWithRosterCounterChanges=@($Samples | Where-Object { $_.CountersChangedSinceRoster -or $_.CountersChangedDuringCapture }).Count
        MembershipScope='SELECTED_LOCAL_PLAYER_ONLY'; Samples=$Samples; VectorFlipped=$false
        CameraConvention='UNVERIFIED'; ShotDirection='UNVERIFIED'; LineOfSight='UNVERIFIED'; AimWrites='NONE'; AimIntegration='INCOMPLETE' }
}

function Compare-CameraPitchSamples {
    param([Parameter(Mandatory=$true)][object[]]$Samples)
    if ($Samples.Count -ne 4) { throw 'Four ordered captures are required: baseline, up, restored baseline, down.' }
    $status='REPORTED_OPPOSITE_PITCH_SIGNS_OBSERVED';$sign='UNVERIFIED'
    foreach ($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame')) {
        foreach ($i in 1..3) { if ([string]$Samples[0].$key -cne [string]$Samples[$i].$key) { $status='INCONCLUSIVE_CONTEXT_CHANGED' } }
    }
    $up=$Samples[1].Elevation-$Samples[0].Elevation
    $restore=$Samples[2].Elevation-$Samples[0].Elevation
    $down=$Samples[3].Elevation-$Samples[2].Elevation
    $upDrift=Get-AimYawDelta $Samples[0].Yaw $Samples[1].Yaw
    $restoreDrift=Get-AimYawDelta $Samples[0].Yaw $Samples[2].Yaw
    $downDrift=Get-AimYawDelta $Samples[2].Yaw $Samples[3].Yaw
    if ($status -eq 'REPORTED_OPPOSITE_PITCH_SIGNS_OBSERVED') {
        if (@($Samples | Where-Object { [Math]::Abs($_.Elevation) -gt 70 }).Count) { $status='INCONCLUSIVE_NEAR_VERTICAL' }
        elseif ([Math]::Abs($restore) -gt 5 -or [Math]::Abs($restoreDrift) -gt 5) { $status='INCONCLUSIVE_BASELINE_NOT_RESTORED' }
        elseif ([Math]::Abs($up) -lt 3 -or [Math]::Abs($up) -gt 60 -or [Math]::Abs($down) -lt 3 -or [Math]::Abs($down) -gt 60) { $status='INCONCLUSIVE_TURN_SIZE' }
        elseif ([Math]::Abs($upDrift) -gt 5 -or [Math]::Abs($downDrift) -gt 5) { $status='INCONCLUSIVE_HORIZONTAL_DRIFT' }
        elseif ($up*$down -ge 0) { $status='INCONCLUSIVE_TURN_SIGNS_NOT_OPPOSITE' }
        elseif ($up -lt 0) { $sign='REPORTED_UP_NEGATIVE_DOWN_POSITIVE' }
        else { $sign='REPORTED_UP_POSITIVE_DOWN_NEGATIVE' }
    }
    [pscustomobject]@{ Status=$status; ObservedPitchSign=$sign; Evidence='MANUAL_CAMERA_TURN_CORRELATION_ONLY'
        Actions=@('USER_REPORTED_LANDMARK_BASELINE','USER_REPORTED_UP_TILT','USER_REPORTED_RESTORED_LANDMARK_BASELINE','USER_REPORTED_DOWN_TILT')
        UpElevationDelta=$up; RestoredBaselineElevationError=$restore; DownElevationDelta=$down
        UpYawDrift=$upDrift; RestoredBaselineYawError=$restoreDrift; DownYawDrift=$downDrift
        CapturesWithRosterCounterChanges=@($Samples | Where-Object { $_.CountersChangedSinceRoster -or $_.CountersChangedDuringCapture }).Count
        MembershipScope='SELECTED_LOCAL_PLAYER_ONLY'; Samples=$Samples; VectorFlipped=$false
        CameraConvention='UNVERIFIED'; ShotDirection='UNVERIFIED'; LineOfSight='UNVERIFIED'; AimWrites='NONE'; AimIntegration='INCOMPLETE' }
}
