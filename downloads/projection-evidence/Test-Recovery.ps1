$ErrorActionPreference='Stop'
$root=Join-Path ([IO.Path]::GetTempPath()) ('projection-recovery-tests-'+[guid]::NewGuid());[void](New-Item -ItemType Directory $root)
function Fixture([string]$case){
 $source=Join-Path $root $case;[void](New-Item -ItemType Directory $source)
 $png=[Convert]::FromBase64String('iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAQAAAC1HAwCAAAAC0lEQVR42mP8/x8AAwMCAO+aR9sAAAAASUVORK5CYII=')
 foreach($name in @('view-before.png','view-after.png')){[IO.File]::WriteAllBytes((Join-Path $source $name),$png)}
 @('PlayerCameraProbeVersion=6 BaseRunner=52 ReadOnly=1','Preflight=PASS Machine=Pie64','GameIdentity=PASS GuestPID=3001 Name=.dts.freefireth','GameModuleIdentity=PASS','GameLayoutRegistration=PASS','LocalPlayerObjects=PASS','CameraProjectionCapture StartUtc=2026-10-18T00:00:10Z EndUtc=2026-10-18T00:00:12Z TimingScope=METHOD_CALL_INTERVAL_ONLY','CameraProjection Status=DERIVED_VIEW_WITH_CLEAN_PROJECTION_READ_ONLY ViewDirty=1 ProjectionDirty=0','CameraViewNativeSequence Values=1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1','CameraProjectionNativeSequence Values=1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1','PluginUnload=PASS','HandlerCleanup=PASS','SharedSession=RELEASED')|Set-Content (Join-Path $source 'projection-report.txt')
 $before=[pscustomobject]@{Name='view-before.png';Width=1;Height=1;SHA256=(Get-FileHash (Join-Path $source 'view-before.png') -Algorithm SHA256).Hash;StartUtc='2026-10-18T00:00:00Z';EndUtc='2026-10-18T00:00:01Z';Timing='ADB_REQUEST_INTERVAL_NOT_RENDER_FRAME'}
 $after=[pscustomobject]@{Name='view-after.png';Width=1;Height=1;SHA256=(Get-FileHash (Join-Path $source 'view-after.png') -Algorithm SHA256).Hash;StartUtc='2026-10-18T00:00:15Z';EndUtc='2026-10-18T00:00:16Z';Timing='ADB_REQUEST_INTERVAL_NOT_RENDER_FRAME'}
 $config=[pscustomobject]@{Schema=1;Status='INCOMPLETE_CAPTURE';Reason="The property 'Width' cannot be found on this object. Verify that the property exists.";ReportSHA256=(Get-FileHash (Join-Path $source 'projection-report.txt') -Algorithm SHA256).Hash;Before=@([pscustomobject]@{},$before);After=@([pscustomobject]@{},$after)}
 if($case-ceq 'ambiguous'){$config.Before=@($before,$before)}
 if($case-ceq 'timing'){$after.StartUtc='2026-10-18T00:00:02Z'}
 if($case-ceq 'unknownnoise'){$config.Before=@([pscustomobject]@{Unknown=1},$before)}
 if($case-ceq 'otherfailure'){$config.Reason='V6 probe exit=1'}
 $config|ConvertTo-Json -Depth 10|Set-Content (Join-Path $source 'evidence.json')
 @(Get-ChildItem $source -File|ForEach-Object {[pscustomobject]@{Name=$_.Name;SHA256=(Get-FileHash $_.FullName -Algorithm SHA256).Hash}})|ConvertTo-Json|Set-Content (Join-Path $source 'files.json')
 if($case-ceq 'tamperedmetadata'){Add-Content (Join-Path $source 'evidence.json') ' '}
 if($case-ceq 'manifestduplicate'){$records=Get-Content (Join-Path $source 'files.json') -Raw|ConvertFrom-Json;$records=@($records)+@($records|Where-Object {$_.Name-ceq 'evidence.json'});$records|ConvertTo-Json|Set-Content (Join-Path $source 'files.json')}
 if($case-ceq 'tampered'){Add-Content (Join-Path $source 'view-before.png') 'changed'}
 return $source
}
try{
 foreach($case in @('ready','ambiguous','timing','unknownnoise','otherfailure','tampered','tamperedmetadata','manifestduplicate')){
  $source=Fixture $case;$beforeHash=(Get-FileHash (Join-Path $source 'evidence.json') -Algorithm SHA256).Hash;$failed=$false
  try{& (Join-Path $PSScriptRoot 'Recover-ProjectionEvidence.ps1') -SourceDirectory $source|Out-Null}catch{$failed=$true}
  $dirs=@(Get-ChildItem $root -Directory|Where-Object {$_.Name-like ($case+'-recovered-*')})
  if($case-ceq 'ready'){
   if($failed-or $dirs.Count-ne 1){throw 'Valid saved Width failure was not recovered'}
   $e=Get-Content (Join-Path $dirs[0].FullName 'evidence.json') -Raw|ConvertFrom-Json
   if($e.Status-cne 'PENDING_LANDMARKS'-or $e.Before.Width-ne 1-or $e.Matrices.View.Count-ne 16-or $e.ActualRenderedCamera-cne 'UNVERIFIED'-or !(Test-Path ($dirs[0].FullName+'.zip'))){throw 'Recovered evidence invalid'}
  }elseif(!$failed-or $dirs.Count-ne 0){throw "Invalid saved evidence accepted: $case"}
  if((Get-FileHash (Join-Path $source 'evidence.json') -Algorithm SHA256).Hash-cne $beforeHash){throw 'Recovery modified source'}
  Write-Host "PASS: saved evidence recovery $case"
 }
 $runner=Get-Content -Raw (Join-Path $PSScriptRoot 'Capture-ProjectionEvidence.ps1')
 $expression=[regex]::Match($runner,'\[void\]\$copyTask\.GetAwaiter\(\)\.GetResult\(\);').Value
 if(!$expression){throw 'Authored task-result suppression missing'}
 Add-Type 'public class ScreenshotTaskFixture { public ScreenshotTaskFixture GetAwaiter(){return this;} public object GetResult(){return new object();} }'
 $copyTask=New-Object ScreenshotTaskFixture
 $old=@(& ([scriptblock]::Create('$copyTask.GetAwaiter().GetResult(); [pscustomobject]@{Width=1;Height=1}')))
 $fixed=@(& ([scriptblock]::Create($expression+' [pscustomobject]@{Width=1;Height=1}')))
 if($old.Count-ne 2-or $fixed.Count-ne 1-or $fixed[0].Width-ne 1){throw 'Task-result leakage regression'}
 'PASS: authored screenshot expression suppresses internal task return object'
}finally{Remove-Item -LiteralPath $root -Recurse -Force}
