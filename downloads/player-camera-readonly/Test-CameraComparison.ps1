$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'Compare-CameraCaptures.ps1')
$text=@'
Preflight=PASS Machine=Pie64 HostPID=8036 VmmDigest=MATCH
GameIdentity=PASS GuestPID=2962 Name=fixture
LocalPlayerObjects=PASS CurrentGame=0x1 Match=0x2 Player=0x3 Class=fixture
PlayerCameraPose Status=SAMPLED_READ_ONLY Attempts=1 ManagedTransform=0x4 NativeTransform=0x5
PlayerCameraWorldRotation X=0 Y=0 Z=0 W=1 Source=fixture
PluginUnload=PASS
HandlerCleanup=PASS
SharedSession=RELEASED
'@
$dir=Join-Path ([IO.Path]::GetTempPath()) ([guid]::NewGuid().ToString())
[void](New-Item -ItemType Directory $dir)
try {
 $paths=@(0..2|ForEach-Object {Join-Path $dir "sample$_.txt"})
 $rotations=@('0 Y=0 Z=0 W=1','0 Y=0.25881904510252074 Z=0 W=0.9659258262890683','0 Y=-0.25881904510252074 Z=0 W=-0.9659258262890683')
 for($i=0;$i-lt 3;$i++) {($text -replace 'PlayerCameraWorldRotation X=\S+ Y=\S+ Z=\S+ W=\S+',('PlayerCameraWorldRotation X='+$rotations[$i]))|Set-Content $paths[$i]}
 $r=Compare-CameraCaptures $paths
 if([Math]::Abs($r.SuccessiveRotationDegrees[0]-30)-gt .00001 -or $r.SuccessiveRotationDegrees[1]-gt .00001){throw 'Quaternion comparison failed'}
 'PASS: known 30-degree change and quaternion sign equivalence'
 foreach($kind in @('identity','failed','duplicate','nonfinite')) {
  $bad=Get-Content -Raw $paths[2]
  switch($kind){
   identity {$bad=$bad.Replace('GuestPID=2962','GuestPID=9999')}
   failed {$bad+="`nPlayerCameraPose=FAIL"}
   duplicate {$bad+="`nPluginUnload=PASS"}
   nonfinite {$bad=$bad.Replace('PlayerCameraWorldRotation X=0 ','PlayerCameraWorldRotation X=NaN ')}
  }
  $file=Join-Path $dir 'bad.txt';$bad|Set-Content $file
  $rejected=$false;try{Compare-CameraCaptures @($paths[0],$paths[1],$file)|Out-Null}catch{$rejected=$true}
  if(!$rejected){throw "Accepted $kind"};"PASS: reject $kind"
 }
} finally {Remove-Item -LiteralPath $dir -Recurse -Force}
