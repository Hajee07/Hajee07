Set-StrictMode -Version 2
function Read-CameraCapture([string]$Path) {
    $lines = @(Get-Content -LiteralPath $Path -ErrorAction Stop)
    function One([string]$Pattern) {
        $matchesFound = @($lines | Where-Object { $_ -match $Pattern })
        if ($matchesFound.Count -ne 1) { throw "Missing or duplicate capture field: $Pattern" }
        return [regex]::Match($matchesFound[0], $Pattern)
    }
    if (@($lines | Where-Object { $_ -match '=FAIL\b' }).Count) { throw 'Failed capture cannot be compared.' }
    foreach ($label in @('PluginUnload','HandlerCleanup','SharedSession')) {
        $expected = if ($label -eq 'SharedSession') {'RELEASED'} else {'PASS'}
        [void](One ('^'+$label+'='+$expected+'$'))
    }
    $hostId=(One '^Preflight=PASS .* HostPID=(\d+) ').Groups[1].Value
    $guestId=(One '^GameIdentity=PASS GuestPID=(\d+) ').Groups[1].Value
    $player=(One '^LocalPlayerObjects=PASS .* Player=(0x[0-9a-f]+) ').Groups[1].Value
    $transform=(One '^PlayerCameraPose Status=SAMPLED_READ_ONLY .* ManagedTransform=(0x[0-9a-f]+) ').Groups[1].Value
    $rotation=One '^PlayerCameraWorldRotation X=(\S+) Y=(\S+) Z=(\S+) W=(\S+) '
    $q=@(1..4|ForEach-Object {[double]::Parse($rotation.Groups[$_].Value,[Globalization.CultureInfo]::InvariantCulture)})
    $norm=0.0
    foreach($v in $q){if([double]::IsNaN($v)-or[double]::IsInfinity($v)){throw 'Nonfinite rotation'};$norm+=$v*$v}
    if([Math]::Abs($norm-1.0)-gt 0.02){throw 'Rotation norm outside tolerance'}
    [pscustomobject]@{Path=$Path;Identity="$hostId/$guestId/$player/$transform";Quaternion=$q;NormSquared=$norm}
}
function Compare-CameraCaptures([string[]]$Paths) {
    if($Paths.Count-ne 3){throw 'Exactly three fresh captures required'}
    $samples=@($Paths|ForEach-Object {Read-CameraCapture $_})
    if(@($samples.Identity|Select-Object -Unique).Count-ne 1){throw 'Process, player or transform changed; captures cannot be combined'}
    $deltas=@(1..2|ForEach-Object {
        $i=$_;$dot=0.0
        for($j=0;$j-lt 4;$j++){$dot+=$samples[$i-1].Quaternion[$j]*$samples[$i].Quaternion[$j]}
        $dot=[Math]::Abs($dot)/[Math]::Sqrt($samples[$i-1].NormSquared*$samples[$i].NormSquared)
        2*[Math]::Acos([Math]::Min(1.0,$dot))*180/[Math]::PI
    })
    [pscustomobject]@{Status='OBSERVATIONS_ONLY';RequestedActions=@('INITIAL','RIGHT_TURN','UP_TILT');SuccessiveRotationDegrees=$deltas;Samples=$samples;ActualRenderedCamera='UNVERIFIED';TurnDirection='NOT_INFERRED';ShotDirection='UNVERIFIED';LOS='UNVERIFIED';AimWrites='NONE'}
}
