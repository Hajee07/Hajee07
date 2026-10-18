[CmdletBinding()]
param([Parameter(Mandatory=$true)][string]$SourceDirectory)
Set-StrictMode -Version 2
$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'ProjectionEvidence.ps1')
$source=(Resolve-Path -LiteralPath $SourceDirectory).Path
# Assign decoded JSON before enumeration: Windows PowerShell 5 does not enumerate JSON root arrays like PowerShell 7.
$decodedManifest=Get-Content -LiteralPath (Join-Path $source 'files.json') -Raw|ConvertFrom-Json
$manifest=@(foreach($entry in $decodedManifest){
    if($entry-is [array]-or $entry.Name-isnot [string]-or $entry.SHA256-isnot [string]){throw 'Manifest must contain scalar file records'}
    $entry
})
Write-Host "ManifestEntries=$($manifest.Count) ParseScope=FLAT_FILE_RECORDS"
foreach($name in @('evidence.json','view-before.png','view-after.png','projection-report.txt')){
    $entries=@($manifest|Where-Object {$_.Name-ceq $name})
    if($entries.Count-ne 1){throw "Manifest entry count mismatch: $name Count=$($entries.Count)"}
    if($entries[0].SHA256-cnotmatch '^[0-9A-Fa-f]{64}$'){throw "Malformed manifest digest: $name"}
    $actual=(Get-FileHash -LiteralPath (Join-Path $source $name) -Algorithm SHA256).Hash
    if($actual-ine $entries[0].SHA256){throw "Original evidence integrity mismatch: $name Expected=$($entries[0].SHA256) Actual=$actual"}
    Write-Host "SavedFileIntegrity=PASS Name=$name"
}
$originalHash=@($manifest|Where-Object {$_.Name-ceq 'evidence.json'})[0].SHA256
$old=Get-Content -LiteralPath (Join-Path $source 'evidence.json') -Raw|ConvertFrom-Json
if($old.Schema-ne 1-or $old.Status-cne 'INCOMPLETE_CAPTURE'-or $old.Reason-notlike "*property 'Width'*"){throw 'Recovery supports only the known screenshot Width metadata failure'}
$reportHash=(Get-FileHash -LiteralPath (Join-Path $source 'projection-report.txt') -Algorithm SHA256).Hash
if($reportHash-ine $old.ReportSHA256){throw 'Original report digest differs from capture metadata'}
$report=Get-ProjectionReport (Get-Content -LiteralPath (Join-Path $source 'projection-report.txt'))
function Recover-Screenshot([object]$Values,[string]$Name){
    # Accept only one complete record. Other entries must have no properties: the known serialized void-task artifact.
    $found=@();$noise=0
    foreach($item in @($Values)){
        if($null-eq $item){$noise++;continue}
        $names=@($item.PSObject.Properties|Select-Object -ExpandProperty Name)
        if($names.Count-eq 0){$noise++;continue}
        foreach($field in @('Name','Width','Height','SHA256','StartUtc','EndUtc','Timing')){if($names-cnotcontains $field){throw "Unexpected screenshot metadata entry: $Name"}}
        if($item.Name-cne $Name){throw 'Screenshot role mismatch'};$found+=,$item
    }
    if($found.Count-ne 1-or $noise-gt 1){throw "Ambiguous screenshot metadata: $Name"}
    $record=$found[0];$path=Join-Path $source $Name
    if((Get-Item -LiteralPath $path).Length-gt 32MB){throw 'Screenshot exceeds bound'}
    $size=Get-PngDimensions ([IO.File]::ReadAllBytes($path))
    if($size.Width-ne $record.Width-or $size.Height-ne $record.Height-or (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash-ine $record.SHA256){throw "Screenshot dimensions/hash mismatch: $Name"}
    $start=[DateTimeOffset]::Parse($record.StartUtc,[Globalization.CultureInfo]::InvariantCulture);$end=[DateTimeOffset]::Parse($record.EndUtc,[Globalization.CultureInfo]::InvariantCulture)
    if($end-lt $start-or $record.Timing-cne 'ADB_REQUEST_INTERVAL_NOT_RENDER_FRAME'){throw 'Screenshot timing profile mismatch'}
    [pscustomobject]@{Name=$Name;Width=$size.Width;Height=$size.Height;SHA256=$record.SHA256;StartUtc=$start.ToString('o');EndUtc=$end.ToString('o');Timing=$record.Timing}
}
$before=Recover-Screenshot $old.Before 'view-before.png';$after=Recover-Screenshot $old.After 'view-after.png'
if($before.Width-ne $after.Width-or $before.Height-ne $after.Height){throw 'Screenshot dimensions changed'}
if([DateTimeOffset]::Parse($before.EndUtc)-gt [DateTimeOffset]::Parse($report.StartUtc)-or [DateTimeOffset]::Parse($report.EndUtc)-gt [DateTimeOffset]::Parse($after.StartUtc)){throw 'Saved screenshot intervals do not bracket the projection method interval'}
$output=$source+'-recovered-'+[guid]::NewGuid().ToString('N');[void](New-Item -ItemType Directory $output)
foreach($name in @('view-before.png','view-after.png','projection-report.txt')){
    Copy-Item -LiteralPath (Join-Path $source $name) -Destination $output
    $expected=if($name-ceq 'view-before.png'){$before.SHA256}elseif($name-ceq 'view-after.png'){$after.SHA256}else{$reportHash}
    if((Get-FileHash -LiteralPath (Join-Path $output $name) -Algorithm SHA256).Hash-ine $expected-or (Get-FileHash -LiteralPath (Join-Path $source $name) -Algorithm SHA256).Hash-ine $expected){throw 'Saved source changed during recovery copy'}
}
Copy-Item -LiteralPath (Join-Path $source 'evidence.json') -Destination (Join-Path $output 'original-evidence.json')
if((Get-FileHash -LiteralPath (Join-Path $output 'original-evidence.json') -Algorithm SHA256).Hash-ine $originalHash){throw 'Original metadata changed during recovery'}
$config=[pscustomobject]@{Schema=1;Status='PENDING_LANDMARKS';Reason='';RecoveryScope='SAVED_FILES_ONLY_NO_NEW_GAME_READS';OriginalStatus=$old.Status;OriginalReason=$old.Reason;OriginalEvidenceSHA256=$originalHash;ReportSHA256=$reportHash;Matrices=$report;Before=$before;After=$after;ViewportStatus='NOT_MEASURED';Landmarks='MISSING';FrameAlignment='BRACKETED_ONLY_NOT_SYNCHRONIZED';ActualRenderedCamera='UNVERIFIED';AimWrites='NONE'}
$json=$config|ConvertTo-Json -Depth 12;$json|Set-Content -LiteralPath (Join-Path $output 'evidence.json') -Encoding UTF8
$template=Get-Content -Raw -LiteralPath (Join-Path $PSScriptRoot 'review-template.html');$template.Replace('__EVIDENCE_CONFIG__',$json.Replace('<','\u003c').Replace('>','\u003e').Replace('&','\u0026'))|Set-Content -LiteralPath (Join-Path $output 'review.html') -Encoding UTF8
foreach($name in @('projection-core.js','landmarks-template.json')){Copy-Item -LiteralPath (Join-Path $PSScriptRoot $name) -Destination $output}
$files=@(Get-ChildItem -LiteralPath $output -File|ForEach-Object {[pscustomobject]@{Name=$_.Name;SHA256=(Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash}})
$files|ConvertTo-Json -Depth 4|Set-Content -LiteralPath (Join-Path $output 'files.json') -Encoding UTF8
Compress-Archive -Path (Join-Path $output '*') -DestinationPath ($output+'.zip')
Write-Host "EvidenceDirectory=$output";Write-Host "EvidenceZip=$output.zip";Write-Host 'Status=PENDING_LANDMARKS Recovery=SAVED_FILES_ONLY Viewport=NOT_MEASURED ActualRenderedCamera=UNVERIFIED AimWrites=NONE'
