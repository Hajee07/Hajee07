$ErrorActionPreference='Stop'
$root=Join-Path ([IO.Path]::GetTempPath()) ('recorded-session-test-'+[guid]::NewGuid())
[void](New-Item -ItemType Directory -Path $root)
try {
    foreach($name in @('Run-CameraComparison.ps1','Compare-CameraCaptures.ps1','Assess-CameraEvidence.ps1','New-CameraEvidenceBundle.ps1')){Copy-Item -LiteralPath (Join-Path $PSScriptRoot $name) -Destination $root}
    $template=@'
Preflight=PASS Machine=Pie64 HostPID=1 VmmDigest=MATCH
GameIdentity=PASS GuestPID=2 Name=fixture
LocalPlayerObjects=PASS CurrentGame=0x1 Match=0x2 Player=0x3 Class=fixture
PlayerCameraPose Status=SAMPLED_READ_ONLY Attempts=1 ManagedTransform=0x4 NativeTransform=0x5
PlayerCameraCapture StartUtc=2026-10-18T00:00:0{S}.0000000Z EndUtc=2026-10-18T00:00:0{S}.5000000Z DurationMs=500 TimingScope=METHOD_CALL_INTERVAL_ONLY_RENDER_SYNC_UNKNOWN
PlayerCameraWorldPosition X=0 Y=0 Z=0 Source=REGISTERED_PLAYER_MAIN_CAMERA_TRANSFORM
PlayerCameraWorldRotation X=0 Y=0 Z=0 W=1 Source=fixture
PluginUnload=PASS
HandlerCleanup=PASS
SharedSession=RELEASED
'@
    $paths=@()
    for($i=0;$i-lt 3;$i++){$path=Join-Path $root "capture-$i.txt";$template.Replace('{S}',[string]($i*2))|Set-Content -LiteralPath $path;$paths+=$path}
    $global:recordedSessionFixture=@{Calls=0;Prompts=0;Confirm='NO';CancelAt=-1;FailAt=-1;Paths=$paths}
    function Read-Host {
        param($Prompt)
        $global:recordedSessionFixture.Prompts++
        if($global:recordedSessionFixture.Prompts-eq 1){return $global:recordedSessionFixture.Confirm}
        if($global:recordedSessionFixture.Prompts-eq $global:recordedSessionFixture.CancelAt){return 'CANCEL'}
        return 'READY'
    }
    function powershell.exe {
        $index=$global:recordedSessionFixture.Calls;$global:recordedSessionFixture.Calls++
        $global:LASTEXITCODE=if($global:recordedSessionFixture.Calls-eq $global:recordedSessionFixture.FailAt){1}else{0}
        $report=$global:recordedSessionFixture.Paths[$index]
        $now=[DateTime]::UtcNow.ToString('o')
        $updated=(Get-Content -LiteralPath $report -Raw)-replace '(?m)^PlayerCameraCapture .*$',('PlayerCameraCapture StartUtc='+$now+' EndUtc='+$now+' DurationMs=0 TimingScope=METHOD_CALL_INTERVAL_ONLY_RENDER_SYNC_UNKNOWN')
        $updated|Set-Content -LiteralPath $report
        'ResultFile='+$report
    }
    $runner=Join-Path $root 'Run-CameraComparison.ps1'
    $rejected=$false;try{& $runner -RecordVisualSession}catch{$rejected=$true}
    if(!$rejected-or $global:recordedSessionFixture.Calls-ne 0){throw 'Unconfirmed recording started capture'}
    'PASS: no recording confirmation means no captures'
    $global:recordedSessionFixture.Confirm='RECORDING';$global:recordedSessionFixture.Prompts=0
    & $runner -RecordVisualSession
    if($global:recordedSessionFixture.Calls-ne 3){throw 'Expected exactly three fresh captures'}
    $journalPaths=@(Get-ChildItem -LiteralPath $root -Directory -Filter 'recorded-camera-*'|ForEach-Object {Join-Path $_.FullName 'recording-journal.json'})
    if($journalPaths.Count-ne 1){throw 'Expected one completed journal'}
    $journal=Get-Content -Raw $journalPaths[0]|ConvertFrom-Json
    if($journal.Status-ne 'CAPTURES_COMPLETE'-or @($journal.Reports).Count-ne 3-or $journal.MediaStatus-ne 'NOT_ATTACHED'){throw 'Incorrect recorded-session status'}
    'PASS: three fresh captures and complete journal without media claim'
    $bundles=@(Get-ChildItem -LiteralPath $root -Directory -Filter 'camera-visual-evidence-*')
    $assessment=Get-Content -Raw (Join-Path $bundles[0].FullName 'assessment.json')|ConvertFrom-Json
    $files=@(Get-Content -Raw (Join-Path $bundles[0].FullName 'files.json')|ConvertFrom-Json)
    if($assessment.ActualRenderedCamera-ne 'UNVERIFIED'-or $assessment.VisualEvidenceStatus-ne 'MISSING'-or $files.Count-ne 4){throw 'Journal was promoted to visual proof'}
    foreach($entry in $files){if((Get-FileHash -LiteralPath (Join-Path $bundles[0].FullName $entry.Name) -Algorithm SHA256).Hash-cne $entry.SHA256){throw 'Bundle hash mismatch'}}
    'PASS: journal is hashed in evidence bundle and remains unverified'
    $journal.Reports[0].SHA256='BAD';$tampered=Join-Path $root 'tampered.json';$journal|ConvertTo-Json -Depth 10|Set-Content $tampered
    $rejected=$false;try{& (Join-Path $root 'New-CameraEvidenceBundle.ps1') -ComparisonFile $journal.ComparisonFile -RecordingJournal $tampered}catch{$rejected=$true}
    if(!$rejected){throw 'Tampered journal accepted'}
    'PASS: mismatched recording report hash rejected'
    $journal=Get-Content -Raw $journalPaths[0]|ConvertFrom-Json
    foreach($event in $journal.Events){if($event.Event-in @('CAPTURE_START','CAPTURE_ACCEPTED')){$event.Utc='1990-01-01T00:00:00.0000000Z'}}
    $journal|ConvertTo-Json -Depth 10|Set-Content $tampered
    $rejected=$false;try{& (Join-Path $root 'New-CameraEvidenceBundle.ps1') -ComparisonFile $journal.ComparisonFile -RecordingJournal $tampered}catch{$rejected=$true}
    if(!$rejected){throw 'Capture outside journal bracket accepted'}
    'PASS: capture outside declared recording bracket rejected'

    $global:recordedSessionFixture.Calls=0;$global:recordedSessionFixture.Prompts=0;$global:recordedSessionFixture.CancelAt=3
    $rejected=$false;try{& $runner -RecordVisualSession}catch{$rejected=$true}
    if(!$rejected-or $global:recordedSessionFixture.Calls-ne 1){throw 'Cancellation continued capturing'}
    $partial=@(Get-ChildItem -LiteralPath $root -Directory -Filter 'recorded-camera-*'|ForEach-Object {Get-Content -Raw (Join-Path $_.FullName 'recording-journal.json')|ConvertFrom-Json}|Where-Object {$_.Status-eq 'INCOMPLETE'})
    if($partial.Count-ne 1-or @($partial[0].Reports).Count-ne 1){throw 'Cancelled session did not preserve partial journal'}
    'PASS: stage cancellation preserves incomplete journal'
    $global:recordedSessionFixture.Calls=0;$global:recordedSessionFixture.Prompts=0;$global:recordedSessionFixture.CancelAt=-1;$global:recordedSessionFixture.FailAt=2
    $rejected=$false;try{& $runner -RecordVisualSession}catch{$rejected=$true}
    if(!$rejected-or $global:recordedSessionFixture.Calls-ne 2){throw 'Failed capture continued'}
    $partial=@(Get-ChildItem -LiteralPath $root -Directory -Filter 'recorded-camera-*'|ForEach-Object {Get-Content -Raw (Join-Path $_.FullName 'recording-journal.json')|ConvertFrom-Json}|Where-Object {$_.Status-eq 'INCOMPLETE'})
    if($partial.Count-ne 2){throw 'Failed capture journal missing'}
    'PASS: failed live capture stops and preserves partial timeline'
} finally {Remove-Item -LiteralPath $root -Recurse -Force;Remove-Variable recordedSessionFixture -Scope Global -ErrorAction SilentlyContinue}
