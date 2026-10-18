$ErrorActionPreference='Stop'
$source=Get-Content -Raw -LiteralPath (Join-Path $PSScriptRoot 'Capture-ProjectionEvidence.ps1')
$tokens=$null;$errors=$null;$ast=[Management.Automation.Language.Parser]::ParseInput($source,[ref]$tokens,[ref]$errors)
$adb=$ast.Find({param($n)$n-is [Management.Automation.Language.FunctionDefinitionAst]-and $n.Name-ceq 'AdbText'},$true)
$shot=$ast.Find({param($n)$n-is [Management.Automation.Language.FunctionDefinitionAst]-and $n.Name-ceq 'Screenshot'},$true)
if(!$adb-or !$shot){throw 'Authored transport functions missing'}
$mockAdb=@'
function AdbText([string[]]$Arguments){
 if($Arguments[-1]-ceq 'get-state'){return 'device'}
 if($Arguments[-1]-ceq 'com.dts.freefireth'){$script:queries++;if($script:queries-gt 1-and $script:case-ceq 'pidchange'){return '4000'};return '3001'}
 return 'connected'
}
'@
$mockShot=@'
function Screenshot([string]$Name){
 $now=[DateTimeOffset]::UtcNow.ToString('o');$path=Join-Path $output $Name
 [IO.File]::WriteAllBytes($path,[Convert]::FromBase64String('iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAQAAAC1HAwCAAAAC0lEQVR42mP8/x8AAwMCAO+aR9sAAAAASUVORK5CYII='))
 $width=if($script:case-ceq 'resize'-and $Name-ceq 'view-after.png'){2}else{1}
 [pscustomobject]@{Name=$Name;Width=$width;Height=1;SHA256=(Get-FileHash $path -Algorithm SHA256).Hash;StartUtc=$now;EndUtc=$now;Timing='SYNTHETIC_TRANSPORT'}
}
'@
$mockProbe=@'
$script:queries=0
function Invoke-FixtureProbe {
 $now=[DateTimeOffset]::UtcNow.ToString('o')
 $status=if($script:case-ceq 'notready'){'NOT_READY_DIRTY_CACHE'}else{'SAMPLED_CLEAN_CACHE_READ_ONLY'}
 $lines=@('PlayerCameraProbeVersion=6 BaseRunner=52 ReadOnly=1','Preflight=PASS Machine=Pie64','GameIdentity=PASS GuestPID=3001 Name=.dts.freefireth','GameModuleIdentity=PASS','GameLayoutRegistration=PASS','LocalPlayerObjects=PASS',"CameraProjectionCapture StartUtc=$now EndUtc=$now TimingScope=METHOD_CALL_INTERVAL_ONLY","CameraProjection Status=$status ViewDirty=0 ProjectionDirty=0",'CameraViewNativeSequence Values=1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1','CameraProjectionNativeSequence Values=1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1','PluginUnload=PASS','HandlerCleanup=PASS','SharedSession=RELEASED')
 if($script:case-ceq 'source'){
  $lines=@('PlayerCameraProbeVersion=7 BaseRunner=52 ReadOnly=1','Preflight=PASS Machine=Pie64','GameIdentity=PASS GuestPID=3001 Name=.dts.freefireth','GameModuleIdentity=PASS','GameLayoutRegistration=PASS','LocalPlayerObjects=PASS',"LandmarkSourceCapture StartUtc=$now EndUtc=$now TimingScope=STAGED_METHOD_INTERVAL_NOT_CAMERA_FRAME",'LandmarkSourceCandidates Count=1 StopReason=SELECTED_OBJECTS_EXHAUSTED MaximumObjects=2 WorldSource=VERIFIED_HEAD_TRANSFORM_MEMBERSHIP Static=UNVERIFIED ScreenAssociation=UNVERIFIED','LandmarkWorldCandidate Id=roster-1-head X=31.5 Y=32 Z=33 Membership=SELECTED_ENTRY_REVALIDATED Source=DIRECT_PROVIDER Static=UNVERIFIED ScreenAssociation=UNVERIFIED','PluginUnload=PASS','HandlerCleanup=PASS','SharedSession=RELEASED')
 }
 $path=Join-Path $output 'child-report.txt';$lines|Set-Content $path;$lines;"ResultFile=$path";$global:LASTEXITCODE=0
}
'@
$source=$source.Replace($adb.Extent.Text,$mockAdb).Replace($shot.Extent.Text,$mockShot)
$source=$source.Replace("if([Environment]::OSVersion.Platform-ne [PlatformID]::Win32NT-or ![Environment]::Is64BitProcess){throw 'Use 64-bit Administrator Windows PowerShell on the BlueStacks PC'}",'# Mock host platform; transport replaced only in this generated test script')
$command="& powershell.exe -NoProfile -ExecutionPolicy Bypass -File (Join-Path `$PSScriptRoot 'camera\Run-PlayerCamera.ps1') -MachineName `$MachineName -Device `$Device `$probeSwitch"
if(!$source.Contains($command)){throw 'Authored child invocation changed'}
$source=$source.Replace($command,'Invoke-FixtureProbe')
$root=Join-Path ([IO.Path]::GetTempPath()) ('projection-orchestration-'+[guid]::NewGuid())
[void](New-Item -ItemType Directory $root)
try{
 foreach($name in @('ProjectionEvidence.ps1','review-template.html','projection-core.js','landmarks-template.json')){Copy-Item (Join-Path $PSScriptRoot $name) $root}
 $fake=Join-Path $root 'fake-adb';[IO.File]::WriteAllText($fake,'fixture only')
 $pwsh=Join-Path $PSHOME 'pwsh';if(!(Test-Path $pwsh)){$pwsh=Join-Path $PSHOME 'pwsh.exe'}
 foreach($case in @('ready','pidchange','resize','notready','source')){
  $path=Join-Path $root ('run-'+$case+'.ps1');$out=Join-Path $root ('output-'+$case)
  $assignment="`$script:case='$case'`n"
  $variant=$source.Replace($mockAdb,($assignment+$mockAdb)).Replace("Write-Host 'Keep the Training",$mockProbe+"`nWrite-Host 'Keep the Training")
  $variant|Set-Content $path
  $arguments=@('-NoProfile','-File',$path,'-AdbPath',$fake,'-OutputDirectory',$out);if($case-ceq 'source'){$arguments+='-CollectLandmarkCandidates'}
  & $pwsh @arguments > (Join-Path $root ('log-'+$case+'.txt')) 2>&1
  $exit=$LASTEXITCODE
  if(!(Test-Path (Join-Path $out 'evidence.json'))){throw (Get-Content (Join-Path $root ('log-'+$case+'.txt')) -Raw)}
  $e=Get-Content (Join-Path $out 'evidence.json') -Raw|ConvertFrom-Json
  $expected=if($case-ceq 'ready'){'PENDING_LANDMARKS'}elseif($case-ceq 'source'){'PENDING_CAMERA_AND_LANDMARK_ASSOCIATION'}else{'INCOMPLETE_CAPTURE'}
  if($e.Status-cne $expected-or $e.ActualRenderedCamera-cne 'UNVERIFIED'-or !(Test-Path ($out+'.zip'))){throw "Capture orchestration $case failed"}
  if($case-cnotin @('ready','source')-and ($null-ne $e.Matrices-or $exit-eq 0)){throw 'Incomplete capture leaked matrices or success exit'}
  if($case-ceq 'source'-and ($null-ne $e.Matrices-or $e.SourceCandidates.Candidates.Count-ne 1-or !(Test-Path (Join-Path $out 'world-candidates.json'))-or $exit-ne 0)){throw 'Source mode fabricated camera or lost candidates'}
  if($case-ceq 'ready'-and $exit-ne 0){throw 'Ready capture failed'}
  Write-Host "PASS: mocked collector $case status=$expected"
 }
}finally{Remove-Item -LiteralPath $root -Recurse -Force}
