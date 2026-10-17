$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
$source=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'Run-ProcessMap.ps1') -Raw
$start=$source.IndexOf('    $culture = [Globalization.CultureInfo]::InvariantCulture')
$end=$source.IndexOf('    Record "MatchPlayerDictionary=', $start)
if($start -lt 0 -or $end -le $start){throw 'Head report initialization block missing.'}
$head=$source.Substring($start,$end-$start)
$camera=@($source -split '\r?\n' | Where-Object {$_ -match '^\s+Record "(CameraWorldPosition|CameraWorldRotation|GameCameraGetterGate|CameraControllerInventory) '})
if($camera.Count -ne 4){throw 'Expected four actual camera report statements.'}
$fields=@{}
foreach($m in [regex]::Matches(($camera -join "`n"),'\$sample\.(\w+)')){$fields[$m.Groups[1].Value]=[ulong]1}
foreach($name in @('CameraWorldX','CameraWorldY','CameraWorldZ','CameraQX','CameraQY','CameraQZ','CameraQW','CameraRotationNorm','CameraBasisX','CameraBasisY','CameraBasisZ')){$fields[$name]=[single]1.25}
$sample=[pscustomobject]$fields
function Record([string]$line){$script:lines.Add($line)}
$oldCulture=[Threading.Thread]::CurrentThread.CurrentCulture
try{
    [Threading.Thread]::CurrentThread.CurrentCulture=[Globalization.CultureInfo]::GetCultureInfo('fr-FR')
    foreach($status in @('NOT_READY_MOTION','NOT_READY_READ_BUDGET','SAMPLED_READ_ONLY')){
        Remove-Variable culture -ErrorAction SilentlyContinue
        $failed=$false
        $objects=[pscustomobject]@{HeadWorldStatus=$status;HeadSampleAttempts=3;HeadWorldError='motion';HeadWorldX=[single]1.25;HeadWorldY=[single]2.5;HeadWorldZ=[single]3.75;HeadCaptureChunks=2;HeadParentCount=9;HeadHierarchyCapacity=236;HeadWorldObservations=105;NativeHeadTransform=[ulong]65536;UnityLoadBias=[ulong]131072}
        $script:lines=[Collections.Generic.List[string]]::new()
        . ([scriptblock]::Create($head))
        . ([scriptblock]::Create($camera -join "`n"))
        if($lines.Count -ne 5 -or $failed){throw "Report did not finish for $status"}
        if($lines[1] -notmatch ' X=1\.25 Y=1\.25 Z=1\.25 ' -or $lines[2] -notmatch ' X=1\.25 '){throw 'Camera numeric output is not invariant.'}
        if($lines[4] -notmatch '^CameraControllerInventory '){throw 'Controller inventory was not printed.'}
        Write-Host "PASS: actual camera report renders after head status $status under fr-FR and strict mode"
    }
    $sample.CameraWorldX=$null;$sample.CameraQX=$null
    $script:lines.Clear()
    . ([scriptblock]::Create($camera -join "`n"))
    if($lines[0] -notmatch ' X=NA ' -or $lines[1] -notmatch ' X=NA '){throw 'Missing camera components must stay NA.'}
    Write-Host 'PASS: missing camera components render NA without inventing values'
}finally{[Threading.Thread]::CurrentThread.CurrentCulture=$oldCulture}
