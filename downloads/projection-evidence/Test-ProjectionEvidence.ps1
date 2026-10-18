$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'ProjectionEvidence.ps1')
function Assert([bool]$Ok,[string]$Name){if(!$Ok){throw $Name};Write-Host "PASS: $Name"}
function Fixture {
    @('PlayerCameraProbeVersion=6 BaseRunner=52 ReadOnly=1','Preflight=PASS Machine=Pie64','GameIdentity=PASS GuestPID=3001 Name=.dts.freefireth','GameModuleIdentity=PASS','GameLayoutRegistration=PASS','LocalPlayerObjects=PASS','CameraProjectionCapture StartUtc=2026-10-18T00:00:00Z EndUtc=2026-10-18T00:00:01Z TimingScope=METHOD_CALL_INTERVAL_ONLY','CameraProjection Status=DERIVED_VIEW_WITH_CLEAN_PROJECTION_READ_ONLY ViewDirty=1 ProjectionDirty=0','CameraViewNativeSequence Values=1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1','CameraProjectionNativeSequence Values=1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1','PluginUnload=PASS','HandlerCleanup=PASS','SharedSession=RELEASED')
}
$r=Get-ProjectionReport (Fixture);Assert ($r.View.Count-eq 16-and $r.GuestPID-eq 3001-and $r.FrameAlignment-ceq 'UNVERIFIED') 'ready report remains saved-data-only'
foreach($which in @('duplicate','failure','notready','nan','short','backwards')){
    $lines=Fixture
    switch($which){
        duplicate {$lines+=@('CameraViewNativeSequence Values=1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1')}
        failure {$lines=$lines -replace '^PluginUnload=PASS$','PluginUnload=FAIL'}
        notready {$lines=$lines -replace 'Status=DERIVED_VIEW_WITH_CLEAN_PROJECTION_READ_ONLY','Status=NOT_READY_SOURCE_CHANGED'}
        nan {$lines=$lines -replace 'Values=1,','Values=NaN,'}
        short {$lines=$lines -replace 'Values=1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1','Values=1,0'}
        backwards {$lines=$lines -replace 'EndUtc=2026-10-18T00:00:01Z','EndUtc=2026-10-17T00:00:00Z'}
    }
    $rejected=$false;try{Get-ProjectionReport $lines|Out-Null}catch{$rejected=$true};Assert $rejected "reject report $which"
}
$png=[byte[]]@(137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,6,64,0,0,3,132)
$size=Get-PngDimensions $png;Assert ($size.Width-eq 1600-and $size.Height-eq 900) 'PNG big-endian screenshot dimensions'
$png[0]=0;$rejected=$false;try{Get-PngDimensions $png|Out-Null}catch{$rejected=$true};Assert $rejected 'invalid PNG header rejected'
foreach($name in @('Capture-ProjectionEvidence.ps1','ProjectionEvidence.ps1')){$tokens=$null;$errors=$null;[void][Management.Automation.Language.Parser]::ParseFile((Join-Path $PSScriptRoot $name),[ref]$tokens,[ref]$errors);Assert ($errors.Count-eq 0) "PowerShell syntax $name"}
