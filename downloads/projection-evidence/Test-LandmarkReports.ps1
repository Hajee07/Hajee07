$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'ProjectionEvidence.ps1')
function SourceFixture {
 @('PlayerCameraProbeVersion=7 BaseRunner=52 ReadOnly=1','Preflight=PASS Machine=Pie64','GameIdentity=PASS GuestPID=3001 Name=.dts.freefireth','GameModuleIdentity=PASS','GameLayoutRegistration=PASS','LocalPlayerObjects=PASS','LandmarkSourceCapture StartUtc=2026-10-18T00:00:00Z EndUtc=2026-10-18T00:00:01Z TimingScope=STAGED_METHOD_INTERVAL_NOT_CAMERA_FRAME','LandmarkSourceCandidates Count=1 StopReason=SELECTED_OBJECTS_EXHAUSTED MaximumObjects=2 WorldSource=VERIFIED_HEAD_TRANSFORM_MEMBERSHIP Static=UNVERIFIED ScreenAssociation=UNVERIFIED','LandmarkWorldCandidate Id=roster-1-head X=31.5 Y=32 Z=33 Membership=SELECTED_ENTRY_REVALIDATED Source=DIRECT_PROVIDER Static=UNVERIFIED ScreenAssociation=UNVERIFIED','PluginUnload=PASS','HandlerCleanup=PASS','SharedSession=RELEASED')
}
$sample=Get-LandmarkSourceReport (SourceFixture)
if($sample.Candidates.Count-ne 1-or $sample.Candidates[0].World[0]-ne 31.5-or $sample.CameraMatrices-cne 'NOT_CAPTURED_IN_SOURCE_MODE'-or $sample.ScreenAssociation-cne 'UNVERIFIED'){throw 'Source parser changed scope'}
'PASS: independent source report preserves candidate-only status'
foreach($case in @('duplicate','count','nonfinite','membership','reversed','four')){
 $lines=SourceFixture
 switch($case){
  duplicate {$lines+=@($lines|Where-Object {$_ -clike 'LandmarkWorldCandidate *'})}
  count {$lines=$lines-replace 'Count=1 StopReason','Count=2 StopReason'}
  nonfinite {$lines=$lines-replace 'X=31.5','X=NaN'}
  membership {$lines=$lines-replace 'Membership=SELECTED_ENTRY_REVALIDATED','Membership=UNVERIFIED'}
  reversed {$lines=$lines-replace 'EndUtc=2026-10-18T00:00:01Z','EndUtc=2026-10-17T00:00:00Z'}
  four {$lines=$lines-replace 'Count=1 StopReason','Count=4 StopReason'}
 }
 $failed=$false;try{Get-LandmarkSourceReport $lines|Out-Null}catch{$failed=$true};if(!$failed){throw "Source parser accepted $case"};"PASS: reject invalid source $case"
}
$empty=@(SourceFixture|Where-Object {$_-cnotlike 'LandmarkWorldCandidate *'}) -replace 'Count=1 StopReason=SELECTED_OBJECTS_EXHAUSTED','Count=0 StopReason=NO_VERIFIED_OTHER_OBJECTS'
$none=Get-LandmarkSourceReport $empty
if($none.Candidates.Count-ne 0-or $none.StopReason-cne 'NO_VERIFIED_OTHER_OBJECTS'){throw 'Empty source report fabricated points'}
'PASS: zero-source report stays empty without fabricated coordinates'
$failed=$false;try{Get-ProjectionReport (SourceFixture)|Out-Null}catch{$failed=$true};if(!$failed){throw 'Source report accepted as camera matrices'}
'PASS: source-only report cannot be reused as camera projection evidence'
