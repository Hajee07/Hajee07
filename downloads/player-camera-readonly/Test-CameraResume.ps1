$ErrorActionPreference='Stop'
$fixtureDir=Join-Path ([IO.Path]::GetTempPath()) ([guid]::NewGuid().ToString())
[void](New-Item -ItemType Directory $fixtureDir)
try {
    Copy-Item (Join-Path $PSScriptRoot 'Run-CameraComparison.ps1') $fixtureDir
    Copy-Item (Join-Path $PSScriptRoot 'Compare-CameraCaptures.ps1') $fixtureDir
    $fixture=@'
Preflight=PASS Machine=Pie64 HostPID=1 VmmDigest=MATCH
GameIdentity=PASS GuestPID=2 Name=fixture
LocalPlayerObjects=PASS CurrentGame=0x1 Match=0x2 Player=0x3 Class=fixture
PlayerCameraPose Status=SAMPLED_READ_ONLY Attempts=1 ManagedTransform=0x4 NativeTransform=0x5
PlayerCameraWorldRotation X=0 Y=0 Z=0 W=1 Source=fixture
PluginUnload=PASS
HandlerCleanup=PASS
SharedSession=RELEASED
'@
    $initial=Join-Path $fixtureDir 'initial.txt';$right=Join-Path $fixtureDir 'right.txt';$fresh=Join-Path $fixtureDir 'fresh.txt'
    $fixture|Set-Content $initial;$fixture|Set-Content $right;$fixture|Set-Content $fresh
    $before=(Get-FileHash $initial).Hash
    $global:cameraResumeFixture=@{Calls=0;Fresh=$fresh;Directory=$fixtureDir;Tamper=$false;Code=0}
    function Read-Host {param($Prompt) 'READY'}
    function powershell.exe {
        $global:cameraResumeFixture.Calls++
        $global:LASTEXITCODE=$global:cameraResumeFixture.Code
        if($global:cameraResumeFixture.Tamper){
            $latest=Get-ChildItem -LiteralPath $global:cameraResumeFixture.Directory -Directory -Filter 'camera-seed-*'|Sort-Object CreationTime -Descending|Select-Object -First 1
            Add-Content -LiteralPath (Join-Path $latest.FullName 'initial.txt') -Value 'tampered'
        }
        "ResultFile=$($global:cameraResumeFixture.Fresh)"
    }
    & (Join-Path $fixtureDir 'Run-CameraComparison.ps1') -InitialReport $initial -RightTurnReport $right
    if($global:cameraResumeFixture.Calls-ne 1){throw 'Resume did not capture exactly once'}
    if((Get-FileHash $initial).Hash-ne $before){throw 'Saved report changed'}
    'PASS: resume captures only third report and preserves seed'
    $fixture.Replace('GuestPID=2','GuestPID=99')|Set-Content $fresh
    $rejected=$false;try{& (Join-Path $fixtureDir 'Run-CameraComparison.ps1') -InitialReport $initial -RightTurnReport $right}catch{$rejected=$true}
    if(!$rejected){throw 'Fresh identity mismatch accepted'}
    'PASS: changed live identity rejected'
    $count=$global:cameraResumeFixture.Calls
    $rejected=$false;try{& (Join-Path $fixtureDir 'Run-CameraComparison.ps1') -InitialReport $initial}catch{$rejected=$true}
    if(!$rejected-or $global:cameraResumeFixture.Calls-ne $count){throw 'Invalid seed triggered capture'}
    'PASS: incomplete seeds rejected before capture'
    foreach($case in @('match','native')) {
        $changed=if($case-eq 'match'){$fixture.Replace('Match=0x2','Match=0x9')}else{$fixture.Replace('NativeTransform=0x5','NativeTransform=0x9')}
        $changed|Set-Content $fresh
        $rejected=$false;try{& (Join-Path $fixtureDir 'Run-CameraComparison.ps1') -InitialReport $initial -RightTurnReport $right}catch{$rejected=$true}
        if(!$rejected){throw "Changed $case accepted"};"PASS: changed live $case rejected"
    }
    $seedFiles=@(Get-ChildItem -LiteralPath $fixtureDir -Recurse -Filter 'initial.txt'|Where-Object {$_.Directory.Name -like 'camera-seed-*'})
    if($seedFiles.Count-lt 1-or (Get-FileHash $seedFiles[0].FullName).Hash-ne $before){throw 'Seed copy missing or changed'}
    'PASS: preserved hashed seed copy survives later failures'
    $fixture|Set-Content $fresh
    $global:cameraResumeFixture.Tamper=$true
    $rejected=$false;try{& (Join-Path $fixtureDir 'Run-CameraComparison.ps1') -InitialReport $initial -RightTurnReport $right}catch{$rejected=$_.Exception.Message -like 'Preserved seed changed*'}
    if(!$rejected){throw 'Changed seed was not rejected'}
    'PASS: seed changed during live capture rejected by hash'
    $global:cameraResumeFixture.Tamper=$false;$global:cameraResumeFixture.Code=1
    $rejected=$false;try{& (Join-Path $fixtureDir 'Run-CameraComparison.ps1') -InitialReport $initial -RightTurnReport $right}catch{$rejected=$_.Exception.Message -like 'Capture failed*'}
    if(!$rejected){throw 'Failed fresh capture was accepted'}
    'PASS: failed live capture cannot complete comparison'


} finally {Remove-Item -LiteralPath $fixtureDir -Recurse -Force;Remove-Variable cameraResumeFixture -Scope Global -ErrorAction SilentlyContinue}
