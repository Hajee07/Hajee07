Set-StrictMode -Version 2
. (Join-Path $PSScriptRoot 'Compare-CameraCaptures.ps1')
function Get-CameraEvidenceAssessment([string[]]$Reports) {
    $ErrorActionPreference='Stop'
    $comparison=Compare-CameraCaptures $Reports
    if(@($Reports|ForEach-Object {[IO.Path]::GetFullPath($_).ToLowerInvariant()}|Select-Object -Unique).Count-ne 3){throw 'Distinct capture reports required'}
    $samples=@()
    foreach($path in $Reports){
        $lines=@(Get-Content -LiteralPath $path)
        $time=@($lines|Where-Object {$_-match '^PlayerCameraCapture '})
        $position=@($lines|Where-Object {$_-match '^PlayerCameraWorldPosition '})
        if($time.Count-ne 1-or $position.Count-ne 1){throw 'Exactly one capture interval and position required'}
        $m=[regex]::Match($time[0],'^PlayerCameraCapture StartUtc=(\S+) EndUtc=(\S+) DurationMs=(\d+) TimingScope=METHOD_CALL_INTERVAL_ONLY_RENDER_SYNC_UNKNOWN$')
        if(!$m.Success){throw 'Unsupported capture interval'}
        $culture=[Globalization.CultureInfo]::InvariantCulture
        $start=[DateTimeOffset]::ParseExact($m.Groups[1].Value,'o',$culture)
        $end=[DateTimeOffset]::ParseExact($m.Groups[2].Value,'o',$culture)
        if($start.Offset-ne [TimeSpan]::Zero-or $end.Offset-ne [TimeSpan]::Zero-or $end-lt $start){throw 'Invalid UTC capture interval'}
        if($samples.Count-gt 0-and $start-lt $samples[-1].EndUtc){throw 'Capture intervals overlap or are out of order'}
        $p=[regex]::Match($position[0],'^PlayerCameraWorldPosition X=(\S+) Y=(\S+) Z=(\S+) Source=REGISTERED_PLAYER_MAIN_CAMERA_TRANSFORM$')
        if(!$p.Success){throw 'Unsupported position source'}
        $xyz=@(1..3|ForEach-Object {[double]::Parse($p.Groups[$_].Value,$culture)})
        foreach($v in $xyz){if([double]::IsNaN($v)-or [double]::IsInfinity($v)){throw 'Nonfinite position'}}
        $capture=Read-CameraCapture $path;$q=$capture.Quaternion;$n=$capture.NormSquared
        # Explicit mathematical +Z basis. This is not an inferred rendering or shot convention.
        $basis=@((2*($q[0]*$q[2]+$q[3]*$q[1])/$n),(2*($q[1]*$q[2]-$q[3]*$q[0])/$n),(1-2*($q[0]*$q[0]+$q[1]*$q[1])/$n))
        $azimuth=[Math]::Atan2($basis[0],$basis[2])*180/[Math]::PI
        $elevation=[Math]::Asin([Math]::Max(-1.0,[Math]::Min(1.0,$basis[1])))*180/[Math]::PI
        $samples+=[pscustomobject]@{Path=$path;SHA256=(Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash;StartUtc=$start;EndUtc=$end;ReportedMethodDurationMs=[long]$m.Groups[3].Value;Position=$xyz;RawQuaternion=$q;RawNormSquared=$n;NormalizedForMathPositiveZBasis=$basis;BasisAzimuthDegrees=$azimuth;BasisElevationDegrees=$elevation}
    }
    $changes=@(1..2|ForEach-Object {
        $i=$_;$distanceSquared=0.0
        for($j=0;$j-lt 3;$j++){$difference=$samples[$i].Position[$j]-$samples[$i-1].Position[$j];$distanceSquared+=$difference*$difference}
        $yaw=$samples[$i].BasisAzimuthDegrees-$samples[$i-1].BasisAzimuthDegrees
        while($yaw-gt 180){$yaw-=360};while($yaw-lt -180){$yaw+=360}
        [pscustomobject]@{FromIndex=$i-1;ToIndex=$i;RotationDegrees=$comparison.SuccessiveRotationDegrees[$i-1];TransformPositionDistance=[Math]::Sqrt($distanceSquared);DeclaredBasisAzimuthDeltaDegrees=$yaw;DeclaredBasisElevationDeltaDegrees=$samples[$i].BasisElevationDegrees-$samples[$i-1].BasisElevationDegrees}
    })
    [pscustomobject]@{Schema=1;Status='VISUAL_EVIDENCE_REQUIRED';Identity=$comparison.Samples[0].Identity;Samples=$samples;Changes=$changes;BasisConvention='MATHEMATICAL_POSITIVE_Z_ONLY_RENDER_CONVENTION_UNVERIFIED';TimingScope='METHOD_INTERVAL_ONLY_NO_RENDER_FRAME_ALIGNMENT';TransformPositionMeaning='CAMERA_TRANSFORM_POSITION_NOT_PLAYER_MOVEMENT';ActualRenderedCamera='UNVERIFIED';ShotDirection='UNVERIFIED';LOS='UNVERIFIED';AimWrites='NONE'}
}
