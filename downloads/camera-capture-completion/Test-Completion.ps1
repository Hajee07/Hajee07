[CmdletBinding()]
param([string]$MappingSourceDirectory=(Join-Path $PSScriptRoot '..\bluestacks-process-map'))
$ErrorActionPreference='Stop'
# Existing test fixtures are synthetic and source-rebuilt; no native plugin is loaded.
. (Join-Path $MappingSourceDirectory 'Test-CameraPoseCheck.ps1')
$work=Join-Path ([IO.Path]::GetTempPath()) ('camera-completion-tests-'+[guid]::NewGuid().ToString('N'))
New-Item -ItemType Directory -Path $work|Out-Null
$checks=0
function Expect-Completion {param([bool]$Ok,[string]$Name) if(!$Ok){throw "FAIL: $Name"};$script:checks++;Write-Host "PASS-COMPLETION: $Name"}
try{
    foreach($name in @('manifest.json','AimBasisCheck.ps1','CameraPoseCheck.ps1','Run-ProcessMap.ps1')){Copy-Item -LiteralPath (Join-Path $MappingSourceDirectory $name) -Destination $work}
    $names=@();$angles=@(@(0,0),@(-25,0),@(0,0),@(25,0),@(0,0),@(0,20),@(0,0),@(0,-20))
    foreach($a in $angles){$name='process-map-result-'+[guid]::NewGuid().ToString('N')+'.txt';$names+=@($name)
        @(New-PoseFixture $a[0] $a[1]|ForEach-Object {$_ -replace 'ProcessMapVersion=47','ProcessMapVersion=52'})|Set-Content -LiteralPath (Join-Path $work $name)}
    $seed=Join-Path $work 'seed.json';@{Schema=1;ReportNames=@($names[0..5])}|ConvertTo-Json|Set-Content $seed
    $runner=Join-Path $PSScriptRoot 'Complete-CameraCapture.ps1'
    $journal=Join-Path $work 'review.json'
    & $runner -SourceDirectory $work -SeedFile $seed -JournalPath $journal -ReviewOnly
    $r=Get-Content $journal -Raw|ConvertFrom-Json
    Expect-Completion ($r.Accepted -eq 6 -and $r.Status -eq 'INCOMPLETE_SIX_VALIDATED' -and $null -eq $r.Comparison) 'six captures remain incomplete, never promoted to eight'
    Expect-Completion (@($r.Reports|Where-Object TimingScope -ne 'IMPORTED_REPORT_CAPTURE_INTERVAL_UNKNOWN').Count -eq 0) 'imported timestamps remain unknown'
    $journal=Join-Path $work 'complete.json'
    & $runner -SourceDirectory $work -SeedFile $seed -JournalPath $journal -AdditionalReportNames @($names[6..7])
    $r=Get-Content $journal -Raw|ConvertFrom-Json
    Expect-Completion ($r.Accepted -eq 8 -and $r.Status -eq 'REPORTED_NATIVE_CAMERA_TURNS_OBSERVED') 'eight ordered synthetic reports yield correlation only'
    Expect-Completion (!$r.LiveBindingReady -and $r.ActualGameCamera -eq 'UNVERIFIED' -and $r.Comparison.ShotDirection -eq 'UNVERIFIED') 'completion never enables live binding'
    $bad=$false;try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath $journal -ReviewOnly}catch{$bad=$true}
    Expect-Completion $bad 'existing journal is not overwritten'
    $bad=$false;try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath (Join-Path $work 'duplicate.json') -AdditionalReportNames @($names[5],$names[7])}catch{$bad=$true}
    $r=Get-Content (Join-Path $work 'duplicate.json') -Raw|ConvertFrom-Json
    Expect-Completion ($bad -and $r.Accepted -eq 6 -and $null -eq $r.Comparison) 'duplicate report rejected and partial evidence retained'
    $path=Join-Path $work $names[6];$original=Get-Content $path -Raw
    $original.Replace('HostPID=100','HostPID=101')|Set-Content $path -NoNewline
    $bad=$false;try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath (Join-Path $work 'context.json') -AdditionalReportNames @($names[6..7])}catch{$bad=$true}
    Expect-Completion $bad 'process identity change rejects mixed captures'
    $original|Set-Content $path -NoNewline
    $original.Replace('PluginUnload=PASS','PluginUnload=FAIL')|Set-Content $path -NoNewline
    $bad=$false;try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath (Join-Path $work 'cleanup.json') -AdditionalReportNames @($names[6..7])}catch{$bad=$true}
    Expect-Completion $bad 'failed cleanup capture rejected'
    $original|Set-Content $path -NoNewline
    @{Schema=1;ReportNames=@('../outside.txt')+$names[1..5]}|ConvertTo-Json|Set-Content $seed
    $bad=$false;try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath (Join-Path $work 'traversal.json') -ReviewOnly}catch{$bad=$true}
    Expect-Completion $bad 'seed traversal rejected'
    @{Schema=1;ReportNames=@($names[0..5])}|ConvertTo-Json|Set-Content $seed
    # Stub the child command/prompt only in this test process. Production has no
    # injectable native executor; these fixtures exercise the manual-loop branch.
    $global:completionFixtureNames=@($names[6..7]);$global:completionFixtureRoot=$work
    $global:completionFixtureBodies=@((Get-Content (Join-Path $work $names[6]) -Raw),(Get-Content (Join-Path $work $names[7]) -Raw))
    $global:completionFixtureMode=''
    function global:Read-Host {param([string]$Prompt) 'READY'}
    function global:powershell.exe {
        $outcome=$global:completionFixtureQueue[$global:completionFixtureCalls];$global:completionFixtureCalls++
        $global:LASTEXITCODE=$outcome
        if($outcome -ne 0){'FIXTURE_CAPTURE_REJECTED';return}
        if($global:completionFixtureMode -and ($global:completionFixtureCalls -eq 1 -or $global:completionFixtureMode -eq 'NoPoseAlways')){
            $name='process-map-result-'+[guid]::NewGuid().ToString('N')+'.txt'
            $body=[regex]::Replace($global:completionFixtureBodies[0],'(?m)^AimStateSamples.*$','AimStateSamples AdditionalPhysicalReads=0 Attempted=0 Sampled=0 StopReason=PREREQUISITES_UNVERIFIED Detail=')
            $body=$body.TrimEnd()+"`nMatchPlayerDictionary=NOT_READY_COLLECTION_CHANGED Attempts=2`n"
            if($global:completionFixtureMode -eq 'NoPoseBadCleanup'){$body=$body.Replace('PluginUnload=PASS','PluginUnload=FAIL')}
            $path=Join-Path $global:completionFixtureRoot $name
            $body.TrimEnd()|Set-Content -LiteralPath $path
            $body -split '\r?\n';"ResultFile=$path";return
        }
        $name=$global:completionFixtureNames[$global:completionFixtureSuccess]
        $body=$global:completionFixtureBodies[$global:completionFixtureSuccess];$global:completionFixtureSuccess++
        $path=Join-Path $global:completionFixtureRoot $name
        $body.TrimEnd()|Set-Content -LiteralPath $path
        $body -split '\r?\n'
        "ResultFile=$path"
    }
    $global:completionFixtureQueue=@(1,0,0);$global:completionFixtureCalls=0;$global:completionFixtureSuccess=0
    $journal=Join-Path $work 'manual-retry.json'
    & $runner -SourceDirectory $work -SeedFile $seed -JournalPath $journal
    $r=Get-Content $journal -Raw|ConvertFrom-Json
    Expect-Completion ($r.Accepted -eq 8 -and $r.Attempts.Count -eq 3 -and $r.Attempts[0].ExitCode -eq 1) 'one rejected manual attempt can retry without accepting failed data'
    Expect-Completion ($global:completionFixtureCalls -eq 3 -and $r.Status -eq 'REPORTED_NATIVE_CAMERA_TURNS_OBSERVED') 'manual-loop fixture completes only after eight strict samples'
    $global:completionFixtureMode='NoPoseOnce';$global:completionFixtureQueue=@(0,0,0);$global:completionFixtureCalls=0;$global:completionFixtureSuccess=0
    $journal=Join-Path $work 'no-pose-once.json'
    & $runner -SourceDirectory $work -SeedFile $seed -JournalPath $journal
    $r=Get-Content $journal -Raw|ConvertFrom-Json
    Expect-Completion ($r.Accepted -eq 8 -and $r.Attempts.Count -eq 3 -and $r.Attempts[0].Rejection -eq 'NO_CAMERA_SAMPLE_COLLECTION_CHANGED') 'zero-sample exit-zero report is recorded as rejected, then retried'
    Expect-Completion ($r.Reports.Count -eq 8 -and $r.Reports.Name -notcontains $r.Attempts[0].ResultName) 'unavailable report never enters accepted reports'
    $global:completionFixtureMode='NoPoseAlways';$global:completionFixtureQueue=@(0,0);$global:completionFixtureCalls=0;$global:completionFixtureSuccess=0
    $bad=$false;$journal=Join-Path $work 'no-pose-bound.json'
    try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath $journal}catch{$bad=$true}
    $r=Get-Content $journal -Raw|ConvertFrom-Json
    Expect-Completion ($bad -and $r.Accepted -eq 6 -and $global:completionFixtureCalls -eq 2) 'zero samples twice stop at retry bound'
    $global:completionFixtureMode='NoPoseBadCleanup';$global:completionFixtureQueue=@(0);$global:completionFixtureCalls=0;$global:completionFixtureSuccess=0
    $bad=$false;$journal=Join-Path $work 'no-pose-bad-cleanup.json'
    try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath $journal}catch{$bad=$true}
    Expect-Completion ($bad -and $global:completionFixtureCalls -eq 1) 'failed cleanup is not classified as retryable collection churn'
    $global:completionFixtureMode=''
    $global:completionFixtureQueue=@(1,1);$global:completionFixtureCalls=0;$global:completionFixtureSuccess=0
    $bad=$false;$journal=Join-Path $work 'retry-bound.json'
    try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath $journal}catch{$bad=$true}
    $r=Get-Content $journal -Raw|ConvertFrom-Json
    Expect-Completion ($bad -and $global:completionFixtureCalls -eq 2 -and $r.Accepted -eq 6 -and $r.Attempts.Count -eq 2) 'two rejected attempts stop with preserved partial journal'
    $global:completionFixtureNames=@($names)
    $global:completionFixtureBodies=@($names|ForEach-Object {(Get-Content (Join-Path $work $_) -Raw).Replace('HostPID=100','HostPID=777')})
    $global:completionFixtureMode='NoPoseOnce';$global:completionFixtureQueue=@(0,0,0,0,0,0,0,0,0);$global:completionFixtureCalls=0;$global:completionFixtureSuccess=0
    $journal=Join-Path $work 'fresh.json'
    & $runner -SourceDirectory $work -Fresh -JournalPath $journal
    $r=Get-Content $journal -Raw|ConvertFrom-Json
    Expect-Completion ($r.Accepted -eq 8 -and $r.Attempts.Count -eq 9 -and $r.Comparison.Samples[0].HostPid -eq '777') 'fresh mode imports no old PID and retries unavailable initial capture'
    Expect-Completion (($r.Reports.Stage -join ',') -eq '1,2,3,4,5,6,7,8' -and @($r.Reports|Where-Object TimingScope -ne 'HOST_WALL_CLOCK_INTERVAL_NOT_MONOTONIC_SYNC').Count -eq 0) 'fresh stages are newly captured, ordered and labelled'
    $global:completionFixtureBodies[1]=$global:completionFixtureBodies[1].Replace('HostPID=777','HostPID=778')
    $global:completionFixtureMode='';$global:completionFixtureQueue=@(0,0);$global:completionFixtureCalls=0;$global:completionFixtureSuccess=0
    $journal=Join-Path $work 'fresh-context.json';$bad=$false
    try{& $runner -SourceDirectory $work -Fresh -JournalPath $journal}catch{$bad=$true}
    $r=Get-Content $journal -Raw|ConvertFrom-Json
    Expect-Completion ($bad -and $r.Accepted -eq 1 -and $null -eq $r.Comparison) 'fresh experiment still rejects process change mid-capture'
    Remove-Item Function:\powershell.exe;Remove-Item Function:\Read-Host
    $global:LASTEXITCODE=0
    Add-Content (Join-Path $work 'CameraPoseCheck.ps1') '# tampered helper'
    $bad=$false;try{& $runner -SourceDirectory $work -SeedFile $seed -JournalPath (Join-Path $work 'helper.json') -ReviewOnly}catch{$bad=$true}
    Expect-Completion $bad 'helper modification rejected before dot-sourcing'
    Write-Host "CompletionTests=PASS Assertions=$script:checks NativeProcessesInvoked=NONE LiveTest=NOT_RUN"
}finally{Remove-Item Function:\powershell.exe -ErrorAction SilentlyContinue;Remove-Item Function:\Read-Host -ErrorAction SilentlyContinue;Remove-Item -LiteralPath $work -Recurse -Force}
