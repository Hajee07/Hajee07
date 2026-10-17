[CmdletBinding()]
param()
$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'Compare-CameraCaptures.ps1')
$instructions=@(
 'Training-la stationary-ah nillunga. Camera straight-a vechuttu READY type pannunga',
 'Game-ku poi camera-ai konjam RIGHT turn pannunga (15-45 degrees). Move/shoot pannaama stop pannittu inga READY type pannunga',
 'Game-ku poi camera-ai konjam UP tilt pannunga (15-30 degrees). Stop pannittu inga READY type pannunga'
)
$reports=@()
foreach($instruction in $instructions){
    if((Read-Host $instruction)-cne 'READY'){throw 'Cancelled; type READY only when positioned'}
    $output=@(& powershell.exe -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot 'Run-PlayerCamera.ps1'))
    $code=$LASTEXITCODE
    $output|ForEach-Object {Write-Host $_}
    if($code-ne 0){throw 'Capture failed. Stop here and share this output.'}
    $result=@($output|Where-Object {$_-match '^ResultFile='})
    if($result.Count-ne 1){throw 'Expected one ResultFile'}
    $path=([string]$result[0]).Substring(11)
    [void](Read-CameraCapture $path)
    $reports+=$path
}
$result=Compare-CameraCaptures $reports
$summary=Join-Path $PSScriptRoot ('camera-comparison-'+[guid]::NewGuid()+'.json')
$result|ConvertTo-Json -Depth 8|Set-Content -LiteralPath $summary -Encoding UTF8
Write-Host "ComparisonFile=$summary"
Write-Host ('SuccessiveRotationDegrees='+($result.SuccessiveRotationDegrees-join ','))
Write-Host 'Status=OBSERVATIONS_ONLY ActualRenderedCamera=UNVERIFIED AimWrites=NONE'
