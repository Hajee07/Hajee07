[CmdletBinding()]
param([string]$InitialReport,[string]$RightTurnReport,[switch]$RecordVisualSession)
$ErrorActionPreference='Stop'
if($RecordVisualSession-and ($InitialReport-or $RightTurnReport)){throw 'Recorded visual sessions require three fresh captures; saved seeds cannot be reused.'}
. (Join-Path $PSScriptRoot 'Compare-CameraCaptures.ps1')
$instructions=@(
 'Training-la stationary-ah nillunga. Camera straight-a vechuttu READY type pannunga',
 'Game-ku poi camera-ai konjam RIGHT turn pannunga (15-45 degrees). Move/shoot pannaama stop pannittu inga READY type pannunga',
 'Game-ku poi camera-ai konjam UP tilt pannunga (15-30 degrees). Stop pannittu inga READY type pannunga'
)
$reports=@()
$seed=@()
if ($InitialReport -or $RightTurnReport) {
    if (!$InitialReport -or !$RightTurnReport) { throw 'Resume requires both InitialReport and RightTurnReport.' }
    $first=Read-CameraCapture $InitialReport
    $second=Read-CameraCapture $RightTurnReport
    if ($first.Identity -cne $second.Identity) { throw 'Saved capture identities differ. Start a fresh comparison.' }
    if ([IO.Path]::GetFullPath($InitialReport) -eq [IO.Path]::GetFullPath($RightTurnReport)) { throw 'Two distinct reports required.' }
    $seedDirectory=Join-Path $PSScriptRoot ('camera-seed-'+[guid]::NewGuid())
    [void](New-Item -ItemType Directory -Path $seedDirectory)
    $savedInitial=Join-Path $seedDirectory 'initial.txt'
    $savedRight=Join-Path $seedDirectory 'right.txt'
    Copy-Item -LiteralPath $InitialReport -Destination $savedInitial
    Copy-Item -LiteralPath $RightTurnReport -Destination $savedRight
    if ((Read-CameraCapture $savedInitial).Identity -cne $first.Identity -or
        (Read-CameraCapture $savedRight).Identity -cne $second.Identity) { throw 'Seed changed while copying.' }
    $reports=@($savedInitial,$savedRight)
    $seed=@($reports|ForEach-Object {[pscustomobject]@{Path=$_;SHA256=(Get-FileHash -LiteralPath $_ -Algorithm SHA256).Hash}})
    $seed|ConvertTo-Json -Depth 4|Set-Content -LiteralPath (Join-Path $seedDirectory 'seed.json') -Encoding UTF8
    Write-Host "SeedDirectory=$seedDirectory"
    $instructions=@('Previous UP-tilt position-la innum irundhaal READY type pannunga. Marubadi UP tilt panna vendam. Position/match maari irundhaal CANCEL type panni fresh comparison start pannunga')
    Write-Host 'Resume=UP_TILT_ONLY SavedReports=2 FreshIdentityCheck=REQUIRED'
}
$journal=$null
$journalPath=$null
$stageIndex=0
$labels=@('INITIAL','RIGHT_TURN','UP_TILT')
$clock=[Diagnostics.Stopwatch]::StartNew()
function Save-VisualEvent([string]$Event,[string]$Stage) {
    if($null-eq $journal){return}
    $journal.Events+=@([pscustomobject]@{Event=$Event;Stage=$Stage;Utc=[DateTime]::UtcNow.ToString('o');ElapsedMs=$clock.ElapsedMilliseconds})
    $journal|ConvertTo-Json -Depth 10|Set-Content -LiteralPath ($journalPath+'.tmp') -Encoding UTF8
    Move-Item -LiteralPath ($journalPath+'.tmp') -Destination $journalPath -Force
    Write-Host "VISUAL_MARKER Session=$($journal.SessionId) Stage=$Stage Event=$Event ElapsedMs=$($clock.ElapsedMilliseconds)"
}
if($RecordVisualSession){
    if($InitialReport-or $RightTurnReport){throw 'Recorded visual sessions require three fresh captures; saved seeds cannot be reused.'}
    Write-Host 'Arrange BlueStacks and this PowerShell window side by side. Record a region containing BOTH windows for the full session.'
    Write-Host 'Use Snipping Tool Record or OBS. Start recording before continuing; keep both game view and VISUAL_MARKER lines visible.'
    if((Read-Host 'Recording started-aa? RECORDING type pannunga; illaina CANCEL')-cne 'RECORDING'){throw 'Recording not confirmed; no captures started.'}
    $sessionId=[guid]::NewGuid().ToString('N')
    $journalDirectory=Join-Path $PSScriptRoot ('recorded-camera-'+$sessionId)
    [void](New-Item -ItemType Directory -Path $journalDirectory)
    $journalPath=Join-Path $journalDirectory 'recording-journal.json'
    $journal=[pscustomobject]@{Schema=1;SessionId=$sessionId;Status='IN_PROGRESS';RecordingClaim='USER_CONFIRMED_NOT_VERIFIED';MediaStatus='NOT_ATTACHED';ComparisonFile=$null;Reports=@();Events=@();Failure=$null}
    Save-VisualEvent 'RECORDING_USER_CONFIRMED' 'SESSION'
    Write-Host "JournalFile=$journalPath"
}
try {
foreach($instruction in $instructions){
    Save-VisualEvent 'PROMPT' $labels[$stageIndex]
    if((Read-Host $instruction)-cne 'READY'){throw 'Cancelled; type READY only when positioned'}
    Save-VisualEvent 'CAPTURE_START' $labels[$stageIndex]
    $output=@(& powershell.exe -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot 'Run-PlayerCamera.ps1'))
    $code=$LASTEXITCODE
    $output|ForEach-Object {Write-Host $_}
    if($code-ne 0){throw 'Capture failed. Stop here and share this output.'}
    $result=@($output|Where-Object {$_-match '^ResultFile='})
    if($result.Count-ne 1){throw 'Expected one ResultFile'}
    $path=([string]$result[0]).Substring(11)
    [void](Read-CameraCapture $path)
    $reports+=$path
    if($null-ne $journal){$journal.Reports+=@([pscustomobject]@{Stage=$labels[$stageIndex];Path=$path;SHA256=(Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash})}
    Save-VisualEvent 'CAPTURE_ACCEPTED' $labels[$stageIndex]
    $stageIndex++
}
foreach($stored in $seed){
    if((Get-FileHash -LiteralPath $stored.Path -Algorithm SHA256).Hash -cne $stored.SHA256){throw 'Preserved seed changed after capture; comparison refused.'}
}
$result=Compare-CameraCaptures $reports
$summary=Join-Path $PSScriptRoot ('camera-comparison-'+[guid]::NewGuid()+'.json')
$result|ConvertTo-Json -Depth 8|Set-Content -LiteralPath $summary -Encoding UTF8
Write-Host "ComparisonFile=$summary"
Write-Host ('SuccessiveRotationDegrees='+($result.SuccessiveRotationDegrees-join ','))
Write-Host 'Status=OBSERVATIONS_ONLY ActualRenderedCamera=UNVERIFIED AimWrites=NONE'

if($null-ne $journal){
    $journal.Status='CAPTURES_COMPLETE';$journal.ComparisonFile=$summary
    Save-VisualEvent 'CAPTURES_COMPLETE' 'SESSION'
    & (Join-Path $PSScriptRoot 'New-CameraEvidenceBundle.ps1') -ComparisonFile $summary -RecordingJournal $journalPath
    Write-Host 'Now stop recording. Upload the original recording and EvidenceZip together. Recording/frame correspondence is not automatically verified.'
}
} catch {
    if($null-ne $journal){$journal.Status='INCOMPLETE';$journal.Failure=$_.Exception.Message;Save-VisualEvent 'STOPPED' 'SESSION'}
    throw
}
