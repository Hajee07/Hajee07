[CmdletBinding()]
param([Parameter(Mandatory=$true)][string]$ComparisonFile,[string]$InitialView,[string]$RightView,[string]$UpView,[string]$RecordingJournal)
$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'Assess-CameraEvidence.ps1')
$comparison=Get-Content -LiteralPath $ComparisonFile -Raw|ConvertFrom-Json
if($comparison.Status-ne 'OBSERVATIONS_ONLY'-or @($comparison.Samples).Count-ne 3){throw 'Expected completed three-capture comparison JSON'}
$paths=@($comparison.Samples|ForEach-Object {[string]$_.Path})
$assessment=Get-CameraEvidenceAssessment $paths
$views=@($InitialView,$RightView,$UpView)
$count=@($views|Where-Object {$_}).Count
if($count-ne 0-and $count-ne 3){throw 'Supply all three view screenshots or none'}
$journalHash=$null
if($RecordingJournal){
    $journalHash=(Get-FileHash -LiteralPath $RecordingJournal -Algorithm SHA256).Hash
    $recording=Get-Content -LiteralPath $RecordingJournal -Raw|ConvertFrom-Json
    if($recording.Schema-ne 1-or $recording.Status-ne 'CAPTURES_COMPLETE'-or $recording.SessionId-notmatch '^[0-9a-f]{32}$'-or $recording.RecordingClaim-ne 'USER_CONFIRMED_NOT_VERIFIED'-or $recording.MediaStatus-ne 'NOT_ATTACHED'){throw 'Unsupported or incomplete recording journal'}
    if([IO.Path]::GetFullPath($recording.ComparisonFile)-ine [IO.Path]::GetFullPath($ComparisonFile)-or @($recording.Reports).Count-ne 3){throw 'Journal does not match comparison'}
    $stages=@('INITIAL','RIGHT_TURN','UP_TILT')
    for($i=0;$i-lt 3;$i++){
        $entry=$recording.Reports[$i]
        if($entry.Stage-cne $stages[$i]-or [IO.Path]::GetFullPath($entry.Path)-ine [IO.Path]::GetFullPath($paths[$i])-or $entry.SHA256-cne $assessment.Samples[$i].SHA256){throw 'Journal capture identity/hash mismatch'}
    }
    $lastElapsed=-1L
    foreach($event in @($recording.Events)){
        if([long]$event.ElapsedMs-lt $lastElapsed){throw 'Journal monotonic order invalid'}
        $lastElapsed=[long]$event.ElapsedMs
    }
    foreach($eventName in @('CAPTURE_START','CAPTURE_ACCEPTED')){
        $events=@($recording.Events|Where-Object {$_.Event-ceq $eventName})
        if($events.Count-ne 3-or ($events.Stage-join ',')-cne ($stages-join ',')){throw 'Journal stage sequence invalid'}
    }
    for($i=0;$i-lt 3;$i++){
        $startEvent=@($recording.Events|Where-Object {$_.Event-ceq 'CAPTURE_START'-and $_.Stage-ceq $stages[$i]})[0]
        $endEvent=@($recording.Events|Where-Object {$_.Event-ceq 'CAPTURE_ACCEPTED'-and $_.Stage-ceq $stages[$i]})[0]
        $bracketStart=[DateTimeOffset]::Parse($startEvent.Utc,[Globalization.CultureInfo]::InvariantCulture)
        $bracketEnd=[DateTimeOffset]::Parse($endEvent.Utc,[Globalization.CultureInfo]::InvariantCulture)
        if($bracketEnd-lt $bracketStart-or $assessment.Samples[$i].StartUtc-lt $bracketStart.AddSeconds(-1)-or $assessment.Samples[$i].EndUtc-gt $bracketEnd.AddSeconds(1)){throw 'Capture interval is outside recording-journal bracket'}
    }
}
$output=Join-Path (Split-Path -LiteralPath $ComparisonFile) ('camera-visual-evidence-'+[guid]::NewGuid())
[void](New-Item -ItemType Directory -Path $output)
$entries=@()
for($i=0;$i-lt 3;$i++){
    $name='capture-'+$i+'.txt';$destination=Join-Path $output $name
    Copy-Item -LiteralPath $paths[$i] -Destination $destination
    $digest=(Get-FileHash -LiteralPath $destination -Algorithm SHA256).Hash
    if($digest-cne $assessment.Samples[$i].SHA256){throw 'Source report changed while copying'}
    $entries+=[pscustomobject]@{Role='CAPTURE_'+$i;Name=$name;SHA256=$digest}
    if($count-eq 3){
        $extension=[IO.Path]::GetExtension($views[$i]).ToLowerInvariant()
        if($extension-notin @('.png','.jpg','.jpeg')){throw 'Screenshots must be PNG or JPEG'}
        if((Get-Item -LiteralPath $views[$i]).Length-gt 32MB){throw 'Screenshot exceeds 32 MiB'}
        $viewName='view-'+$i+$extension
        Copy-Item -LiteralPath $views[$i] -Destination (Join-Path $output $viewName)
        $entries+=[pscustomobject]@{Role='USER_SUPPLIED_VIEW_'+$i;Name=$viewName;SHA256=(Get-FileHash -LiteralPath (Join-Path $output $viewName) -Algorithm SHA256).Hash}
    }
}
if($RecordingJournal){
    $journalDestination=Join-Path $output 'recording-journal.json'
    Copy-Item -LiteralPath $RecordingJournal -Destination $journalDestination
    if((Get-FileHash -LiteralPath $journalDestination -Algorithm SHA256).Hash-cne $journalHash){throw 'Journal changed while copying'}
    $entries+=[pscustomobject]@{Role='RECORDING_TIMELINE_USER_ASSERTED';Name='recording-journal.json';SHA256=$journalHash}
    $assessment|Add-Member -NotePropertyName RecordingTimelineStatus -NotePropertyValue 'USER_ASSERTED_RECORDING_NOT_FRAME_ALIGNED'
}
$assessment|Add-Member -NotePropertyName VisualEvidenceStatus -NotePropertyValue $(if($count-eq 3){'SUPPLIED_UNALIGNED_REQUIRES_REVIEW'}else{'MISSING'})
$assessment|ConvertTo-Json -Depth 10|Set-Content -LiteralPath (Join-Path $output 'assessment.json') -Encoding UTF8
$entries|ConvertTo-Json -Depth 4|Set-Content -LiteralPath (Join-Path $output 'files.json') -Encoding UTF8
@'
Visual evidence review — actual camera remains UNVERIFIED

0 = initial, 1 = right-turn, 2 = up-tilt.
Confirm these images/recording correspond to the same live captures and scene.
Record visible static landmarks and how their positions move between views.
Do not treat user-assigned filenames or file timestamps as frame alignment.
The capture intervals bound a memory-reading method, not a rendered frame.
A screenshot taken later cannot retroactively validate an earlier sample.
Review any camera orbit/position changes separately from player movement.
The +Z mathematical basis is explicit; its agreement with game rendering is unverified.
These captures cannot establish shot direction, LOS or server hit acceptance.
For a new recording, keep the whole three-capture sequence and screen views visible;
retain original media, capture reports and UTC timing. Do not edit old reports.
'@ |Set-Content -LiteralPath (Join-Path $output 'REVIEW.txt') -Encoding UTF8
$zip=$output+'.zip'
Compress-Archive -Path (Join-Path $output '*') -DestinationPath $zip
Write-Host "AssessmentFile=$(Join-Path $output 'assessment.json')"
Write-Host "EvidenceZip=$zip"
Write-Host 'Status=VISUAL_REVIEW_PENDING ActualRenderedCamera=UNVERIFIED AimWrites=NONE'
