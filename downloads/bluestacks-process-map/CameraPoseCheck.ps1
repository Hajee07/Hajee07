# Functions only. Report text is parsed, never executed.
Set-StrictMode -Version 2
function Read-CameraPosePointer {
    param([string]$Text,[switch]$Page)
    $n=[Convert]::ToUInt64($Text.Substring(2),16)
    if ($n -lt 65536 -or $n -ge 0x0000800000000000L -or ($n -band 7) -ne 0 -or ($Page -and ($n -band 4095) -ne 0)) { throw 'Invalid native camera pose pointer.' }
    return $n.ToString('x')
}
function ConvertFrom-CameraPoseReport {
    param([Parameter(Mandatory=$true)][string[]]$Lines)
    $sample=ConvertFrom-AimBasisReport $Lines
    if ($sample.Version -lt 46) { throw 'Native camera rotation requires V46 or later.' }
    $unity=Match-AimReportLine $Lines 'CameraUnityCode' '^CameraUnityCode Status=REGISTERED_ENTRIES_AND_CODE_VERIFIED LoadBias=(0x[0-9a-fA-F]+) BuildId=667862f2d29b22ee ReferenceFileSHA256=1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77 MainRVA=0x41d8c4 ComponentTransformRVA=0x453d04 CodeScope=MAIN_24_COMPONENT_460_BYTES SelectedCamera=UNVERIFIED ManagedCamera=NOT_READ CameraPose=UNVERIFIED FunctionsInvoked=False$'
    $selection=Match-AimReportLine $Lines 'CameraMainSelection' '^CameraMainSelection Status=ORIGINAL_UNITY_MAIN_SELECTED_READ_ONLY NativeObject=(0x[0-9a-fA-F]+) Owner=(0x[0-9a-fA-F]+) PredicateRawByte=([0-9]+) PredicatesEvaluated=([12]) CompleteSourceSelection=True Scope=ORIGINAL_UNITY_NATIVE_SELECTOR EvaluatedBy=READ_ONLY_SOURCE_EQUIVALENT FunctionsInvoked=False ManagedCamera=NOT_READ CameraPose=UNVERIFIED GameGetterHotfix=NOT_EVALUATED$'
    if ([long]$selection.Groups[3].Value -lt 1 -or [long]$selection.Groups[3].Value -gt 255) { throw 'Native camera predicate did not select a camera.' }
    $position=Match-AimReportLine $Lines 'CameraWorldPosition' '^CameraWorldPosition Status=ORIGINAL_NATIVE_CAMERA_WORLD_POSITION_READ_ONLY NativeTransform=(0x[0-9a-fA-F]+) X=(\S+) Y=(\S+) Z=(\S+) ParentCount=([0-9]+) Scope=ORIGINAL_UNITY_NATIVE_SELECTOR_TRANSFORM_INTERMEDIATE Rotation=SEE_CAMERA_WORLD_ROTATION ActualGameCamera=UNVERIFIED GameGetterHotfix=NOT_EVALUATED FunctionsInvoked=False AimWrites=NONE$'
    $rotation=Match-AimReportLine $Lines 'CameraWorldRotation' '^CameraWorldRotation Status=ORIGINAL_NATIVE_CAMERA_WORLD_ROTATION_READ_ONLY X=(\S+) Y=(\S+) Z=(\S+) W=(\S+) NormSquared=(\S+) PositiveZBasisX=(\S+) PositiveZBasisY=(\S+) PositiveZBasisZ=(\S+) Scope=ORIGINAL_UNITY_NATIVE_SELECTOR_TRANSFORM_INTERMEDIATE NormalizedByProbe=False CameraConvention=UNVERIFIED ActualGameCamera=UNVERIFIED ShotDirection=UNVERIFIED FunctionsInvoked=False AimWrites=NONE$'
    $camera=Read-CameraPosePointer $selection.Groups[1].Value;$owner=Read-CameraPosePointer $selection.Groups[2].Value
    $transform=Read-CameraPosePointer $position.Groups[1].Value;$unityBias=Read-CameraPosePointer $unity.Groups[1].Value -Page
    if ($camera -eq $transform -or [long]$position.Groups[5].Value -gt 31) { throw 'Invalid native camera Transform identity/bound.' }
    $pos=@();foreach ($i in 2..4) { $v=Read-AimNumber $position.Groups[$i].Value;if ([Math]::Abs($v) -gt 10000000) { throw 'Camera position exceeds bound.' };$pos+=$v }
    $q=@();foreach ($i in 1..4) { $q+=Read-AimNumber $rotation.Groups[$i].Value }
    [double]$norm=0;foreach ($v in $q) { $norm+=$v*$v }
    if ($norm -lt 0.98 -or $norm -gt 1.02 -or [Math]::Abs($norm-(Read-AimNumber $rotation.Groups[5].Value)) -gt 0.00001) { throw 'Native camera quaternion norm mismatch.' }
    $basis=@();foreach ($i in 6..8) { $basis+=Read-AimNumber $rotation.Groups[$i].Value }
    $x=$q[0];$y=$q[1];$z=$q[2];$w=$q[3]
    if ([Math]::Abs($basis[0]-2*($x*$z+$w*$y)) -gt 0.00001 -or [Math]::Abs($basis[1]-2*($y*$z-$w*$x)) -gt 0.00001 -or [Math]::Abs($basis[2]-(1-2*($x*$x+$y*$y))) -gt 0.00001) { throw 'Native camera printed basis disagrees with quaternion.' }
    $aim=Match-AimReportLine $Lines 'AimQuaternion' '^AimQuaternion X=(\S+) Y=(\S+) Z=(\S+) W=(\S+) NormSquared=(\S+) NormalizedByProbe=False$'
    [double]$dot=0;[double]$aimNorm=0;for ($i=0;$i -lt 4;$i++) { $v=Read-AimNumber $aim.Groups[$i+1].Value;$dot+=$v*$q[$i];$aimNorm+=$v*$v }
    # Normalized dot is an angle metric only; raw quaternions are never modified.
    $agreement=2*[Math]::Acos([Math]::Min(1.0,[Math]::Abs($dot)/[Math]::Sqrt($aimNorm*$norm)))*180/[Math]::PI
    $sample | Add-Member -NotePropertyMembers @{ NativeCamera=$camera;NativeOwner=$owner;NativeTransform=$transform;UnityLoadBias=$unityBias
        CameraPosition=$pos;CameraQuaternion=$q;CameraNormSquared=$norm;AimYaw=$sample.Yaw;AimElevation=$sample.Elevation
        AimCameraDifferenceDegrees=$agreement;MeasurementScope='ORIGINAL_NATIVE_CAMERA_POSITIVE_Z_BASIS';ParentCount=[int]$position.Groups[5].Value }
    $sample.BasisX=$basis[0];$sample.BasisY=$basis[1];$sample.BasisZ=$basis[2]
    $sample.Yaw=[Math]::Atan2($basis[0],$basis[2])*180/[Math]::PI
    $sample.Elevation=[Math]::Atan2($basis[1],[Math]::Sqrt($basis[0]*$basis[0]+$basis[2]*$basis[2]))*180/[Math]::PI
    return $sample
}
function Compare-CameraPoseSamples {
    param([Parameter(Mandatory=$true)][object[]]$Samples)
    if ($Samples.Count -ne 8) { throw 'Eight ordered captures are required: baseline/right/restore/left, baseline/up/restore/down.' }
    $status='REPORTED_NATIVE_CAMERA_TURNS_OBSERVED'
    foreach ($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame','NativeCamera','NativeOwner','NativeTransform','UnityLoadBias')) {
        foreach ($i in 1..7) { if ([string]$Samples[0].$key -cne [string]$Samples[$i].$key) { $status='INCONCLUSIVE_CONTEXT_CHANGED' } }
    }
    $yaw=Compare-CameraYawSamples @($Samples[0..3]);$pitch=Compare-CameraPitchSamples @($Samples[4..7])
    if ($status -ne 'INCONCLUSIVE_CONTEXT_CHANGED' -and ($yaw.Status -ne 'REPORTED_OPPOSITE_YAW_SIGNS_OBSERVED' -or $pitch.Status -ne 'REPORTED_OPPOSITE_PITCH_SIGNS_OBSERVED')) { $status='INCONCLUSIVE_CAMERA_TURNS' }
    [double]$maximum=0;foreach ($sample in $Samples) { $maximum=[Math]::Max($maximum,$sample.AimCameraDifferenceDegrees) }
    [pscustomobject]@{Status=$status;Evidence='MANUAL_NATIVE_CAMERA_TURN_CORRELATION_ONLY';Yaw=$yaw;Pitch=$pitch;Samples=$Samples
        MaximumAimCameraDifferenceDegrees=$maximum;AimCameraWithinOneDegree=($maximum -le 1);AngleMetric='ABS_NORMALIZED_DOT_ONLY_RAW_QUATERNIONS_UNCHANGED'
        CameraPositionMotion='RECORDED_NOT_A_STATIONARY_CHARACTER_PROOF';ActualGameCamera='UNVERIFIED';CameraConvention='UNVERIFIED';ShotDirection='UNVERIFIED';LineOfSight='UNVERIFIED';AimWrites='NONE';AimIntegration='INCOMPLETE'}
}
