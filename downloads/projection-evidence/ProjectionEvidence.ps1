# Pure parsing helpers; no game/process access.
function Get-UniqueProjectionLine([string[]]$Lines,[string]$Prefix){
    $hits=@($Lines|Where-Object {$_ -cmatch ('^'+[regex]::Escape($Prefix))})
    if($hits.Count-ne 1){throw "Expected exactly one report line: $Prefix"};return $hits[0]
}
function Get-ProjectionReport([string[]]$Lines){
    $version=Get-UniqueProjectionLine $Lines 'PlayerCameraProbeVersion='
    if($version-cne 'PlayerCameraProbeVersion=6 BaseRunner=52 ReadOnly=1'){throw 'Expected V6 read-only projection report'}
    foreach($prefix in @('Preflight=','GameIdentity=','GameModuleIdentity=','GameLayoutRegistration=','LocalPlayerObjects=','PluginUnload=','HandlerCleanup=','SharedSession=')){
        $line=Get-UniqueProjectionLine $Lines $prefix
        $expected=if($prefix-ceq 'SharedSession='){'RELEASED'}else{'PASS'}
        if($line -cnotmatch ('^'+[regex]::Escape($prefix+$expected)+'(?: |$)')){throw "Report gate failed: $prefix"}
    }
    if(@($Lines|Where-Object {$_ -cmatch '(?:^| )\w+=FAIL(?: |$)|^\w+=NOT_READY'}).Count){throw 'Failed report cannot be projection evidence'}
    $status=Get-UniqueProjectionLine $Lines 'CameraProjection Status='
    if($status -cnotmatch '^CameraProjection Status=(SAMPLED_CLEAN_CACHE_READ_ONLY|DERIVED_VIEW_WITH_CLEAN_PROJECTION_READ_ONLY) '){throw 'Projection matrices not ready'}
    $capture=Get-UniqueProjectionLine $Lines 'CameraProjectionCapture '
    if($capture -cnotmatch '^CameraProjectionCapture StartUtc=(\S+) EndUtc=(\S+) TimingScope=METHOD_CALL_INTERVAL_ONLY$'){throw 'Capture timing missing'}
    $start=[DateTimeOffset]::Parse($Matches[1],[Globalization.CultureInfo]::InvariantCulture)
    $end=[DateTimeOffset]::Parse($Matches[2],[Globalization.CultureInfo]::InvariantCulture)
    if($end-lt $start){throw 'Invalid capture interval'}
    $matrices=@()
    foreach($prefix in @('CameraViewNativeSequence Values=','CameraProjectionNativeSequence Values=')){
        $line=Get-UniqueProjectionLine $Lines $prefix
        $tokens=$line.Substring($prefix.Length).Split(',');if($tokens.Count-ne 16){throw 'Expected 16 matrix elements'}
        $values=@();foreach($token in $tokens){
            if($token-cnotmatch '^[+-]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][+-]?\d+)?$'){throw 'Invalid matrix numeric token'}
            $number=[double]::Parse($token,[Globalization.NumberStyles]::Float,[Globalization.CultureInfo]::InvariantCulture)
            if([double]::IsNaN($number)-or [double]::IsInfinity($number)-or [Math]::Abs($number)-gt 1e12){throw 'Invalid matrix magnitude'};$values+=,$number
        };$matrices+=,@($values)
    }
    $game=Get-UniqueProjectionLine $Lines 'GameIdentity='
    if($game-cnotmatch ' GuestPID=(\d+) '){throw 'Missing guest identity'};$guest=[long]$Matches[1]
    [pscustomobject]@{Status='SAVED_REPORT_MATRICES_ONLY';GuestPID=$guest;StartUtc=$start.ToString('o');EndUtc=$end.ToString('o');View=@($matrices[0]);Projection=@($matrices[1]);ActualRenderedCamera='UNVERIFIED';FrameAlignment='UNVERIFIED'}
}
function Get-PngDimensions([byte[]]$Bytes){
    if($Bytes.Length-lt 24-or $Bytes[8]-ne 0-or $Bytes[9]-ne 0-or $Bytes[10]-ne 0-or $Bytes[11]-ne 13-or [BitConverter]::ToString($Bytes[0..7])-cne '89-50-4E-47-0D-0A-1A-0A'-or [Text.Encoding]::ASCII.GetString($Bytes,12,4)-cne 'IHDR'){throw 'Invalid PNG header'}
    $width=[long]$Bytes[16]*16777216+[long]$Bytes[17]*65536+[long]$Bytes[18]*256+$Bytes[19]
    $height=[long]$Bytes[20]*16777216+[long]$Bytes[21]*65536+[long]$Bytes[22]*256+$Bytes[23]
    if($width-lt 1-or $height-lt 1-or $width-gt 16384-or $height-gt 16384){throw 'PNG dimensions outside bound'}
    [pscustomobject]@{Width=$width;Height=$height;Scope='PNG_IHDR_DIMENSIONS_ONLY'}
}
