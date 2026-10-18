[CmdletBinding()]
param([string]$AdbPath='C:\Program Files\BlueStacks_nxt\HD-Adb.exe',[ValidatePattern('^(127\.0\.0\.1|localhost):[0-9]{1,5}$')][string]$Device='127.0.0.1:5555',[string]$MachineName='Pie64',[string]$OutputDirectory,[switch]$CollectLandmarkCandidates)
Set-StrictMode -Version 2
$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'ProjectionEvidence.ps1')
if([Environment]::OSVersion.Platform-ne [PlatformID]::Win32NT-or ![Environment]::Is64BitProcess){throw 'Use 64-bit Administrator Windows PowerShell on the BlueStacks PC'}
if(!(Test-Path -LiteralPath $AdbPath -PathType Leaf)){throw 'HD-Adb.exe path does not exist'}
if(!$OutputDirectory){$OutputDirectory=Join-Path $env:USERPROFILE ('Downloads\projection-evidence-'+[guid]::NewGuid().ToString('N'))}
if(Test-Path -LiteralPath $OutputDirectory){throw 'OutputDirectory must be a new folder'}
[void](New-Item -ItemType Directory -Path $OutputDirectory)
$output=(Resolve-Path -LiteralPath $OutputDirectory).Path
function AdbText([string[]]$Arguments){
    $info=[Diagnostics.ProcessStartInfo]::new();$info.FileName=$AdbPath;$info.Arguments=($Arguments -join ' ')
    $info.UseShellExecute=$false;$info.CreateNoWindow=$true;$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true
    $process=[Diagnostics.Process]::new();$process.StartInfo=$info
    try{
        if(!$process.Start()){throw 'Could not start ADB query'}
        $stdout=$process.StandardOutput.ReadToEndAsync();$stderr=$process.StandardError.ReadToEndAsync()
        if(!$process.WaitForExit(15000)){$process.Kill();throw 'ADB query timed out'}
        if($process.ExitCode-ne 0){throw ('ADB query failed: '+$stderr.Result+' '+$stdout.Result)}
        if($stderr.Result.Trim()){Write-Host ('AdbNote='+$stderr.Result.Trim())}
        return $stdout.Result.Trim()
    }finally{$process.Dispose()}
}
function Screenshot([string]$Name){
    $path=Join-Path $output $Name;$started=[DateTimeOffset]::UtcNow
    $info=[Diagnostics.ProcessStartInfo]::new();$info.FileName=$AdbPath;$info.Arguments='-s '+$Device+' exec-out screencap -p'
    $info.UseShellExecute=$false;$info.CreateNoWindow=$true;$info.RedirectStandardOutput=$true;$info.RedirectStandardError=$true
    $process=[Diagnostics.Process]::new();$process.StartInfo=$info;$stream=$null
    try{
        if(!$process.Start()){throw 'Could not start screenshot transport'}
        $errorTask=$process.StandardError.ReadToEndAsync();$stream=[IO.File]::Create($path)
        $copyTask=$process.StandardOutput.BaseStream.CopyToAsync($stream)
        if(!$process.WaitForExit(15000)){$process.Kill();throw 'Screenshot transport timed out'}
        if(!$copyTask.Wait(3000)){throw 'Screenshot stream did not finish'}
        [void]$copyTask.GetAwaiter().GetResult();$stream.Dispose();$stream=$null
        if($process.ExitCode-ne 0){throw ('Screenshot transport failed: '+$errorTask.Result)}
    }finally{if($stream){$stream.Dispose()};$process.Dispose()}
    $ended=[DateTimeOffset]::UtcNow;$file=Get-Item -LiteralPath $path
    if($file.Length-gt 32MB){throw 'Screenshot exceeds 32 MiB bound'}
    $size=Get-PngDimensions ([IO.File]::ReadAllBytes($path))
    [pscustomobject]@{Name=$Name;Width=$size.Width;Height=$size.Height;SHA256=(Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash;StartUtc=$started.ToString('o');EndUtc=$ended.ToString('o');Timing='ADB_REQUEST_INTERVAL_NOT_RENDER_FRAME'}
}
Write-Host 'Keep the Training scene and camera stationary. Capturing screenshots around one V6 probe.'
Write-Host (AdbText -Arguments @('connect',$Device));if((AdbText -Arguments @('-s',$Device,'get-state'))-cne 'device'){throw 'Selected device unavailable'}
$guestBefore=AdbText -Arguments @('-s',$Device,'shell','pidof','com.dts.freefireth');if($guestBefore-cnotmatch '^\d+$'){throw 'Free Fire must be running'}
$before=Screenshot 'view-before.png'
$probeSwitch=if($CollectLandmarkCandidates){'-ProbeLandmarkSources'}else{'-ProbeProjection'}
$probeStart=[DateTimeOffset]::UtcNow
& powershell.exe -NoProfile -ExecutionPolicy Bypass -File (Join-Path $PSScriptRoot 'camera\Run-PlayerCamera.ps1') -MachineName $MachineName -Device $Device $probeSwitch | Tee-Object -Variable probeLines
$exit=$LASTEXITCODE;$probeEnd=[DateTimeOffset]::UtcNow
$after=Screenshot 'view-after.png'
try{$guestAfter=AdbText -Arguments @('-s',$Device,'shell','pidof','com.dts.freefireth')}catch{$guestAfter='UNAVAILABLE'}
$reportLines=@($probeLines|ForEach-Object {[string]$_});$resultLine=Get-UniqueProjectionLine $reportLines 'ResultFile='
$reportPath=$resultLine.Substring('ResultFile='.Length);if(!(Test-Path -LiteralPath $reportPath -PathType Leaf)){throw 'Child report missing'}
Copy-Item -LiteralPath $reportPath -Destination (Join-Path $output 'projection-report.txt')
$reportHash=(Get-FileHash -LiteralPath (Join-Path $output 'projection-report.txt') -Algorithm SHA256).Hash
if((Get-FileHash -LiteralPath $reportPath -Algorithm SHA256).Hash-cne $reportHash){throw 'Report changed while copying'}
$status='PENDING_LANDMARKS';$parsed=$null;$sourceCandidates=$null;$reason=''
try{
    if($exit-ne 0){throw "V6 probe exit=$exit"}
    if($CollectLandmarkCandidates){$sourceCandidates=Get-LandmarkSourceReport (Get-Content -LiteralPath (Join-Path $output 'projection-report.txt'));$validated=$sourceCandidates;$status=if($sourceCandidates.Candidates.Count){'PENDING_CAMERA_AND_LANDMARK_ASSOCIATION'}else{'SOURCE_CANDIDATES_UNAVAILABLE'}}else{$parsed=Get-ProjectionReport (Get-Content -LiteralPath (Join-Path $output 'projection-report.txt'));$validated=$parsed}
    if($guestBefore-cne $guestAfter-or [long]$guestBefore-ne $validated.GuestPID){throw 'Game process identity changed'}
    if($before.Width-ne $after.Width-or $before.Height-ne $after.Height){throw 'Screenshot dimensions changed'}
    $sampleStart=[DateTimeOffset]::Parse($validated.StartUtc);$sampleEnd=[DateTimeOffset]::Parse($validated.EndUtc)
    if($sampleStart-lt $probeStart.AddSeconds(-1)-or $sampleEnd-gt $probeEnd.AddSeconds(1)){throw 'Report method interval is not within child invocation'}
}catch{$status='INCOMPLETE_CAPTURE';$reason=$_.Exception.Message;$parsed=$null;$sourceCandidates=$null}
$config=[pscustomobject]@{Schema=1;Status=$status;Reason=$reason;ReportSHA256=$reportHash;Matrices=$parsed;SourceCandidates=$sourceCandidates;Before=$before;After=$after;ViewportStatus='NOT_MEASURED';Landmarks='MISSING';FrameAlignment='BRACKETED_ONLY_NOT_SYNCHRONIZED';ActualRenderedCamera='UNVERIFIED';AimWrites='NONE'}
if($null-ne $sourceCandidates){[pscustomobject]@{WorldCoordinateSource='RUNTIME_HEAD_TRANSFORMS_NOT_PROJECTION_INVERSION';Status='UNASSOCIATED_CANDIDATES_NOT_VALIDATED_LANDMARKS';Landmarks=@($sourceCandidates.Candidates)}|ConvertTo-Json -Depth 10|Set-Content -LiteralPath (Join-Path $output 'world-candidates.json') -Encoding UTF8}
$json=$config|ConvertTo-Json -Depth 12
$json|Set-Content -LiteralPath (Join-Path $output 'evidence.json') -Encoding UTF8
$template=Get-Content -Raw -LiteralPath (Join-Path $PSScriptRoot 'review-template.html')
$template.Replace('__EVIDENCE_CONFIG__',$json.Replace('<','\u003c').Replace('>','\u003e').Replace('&','\u0026'))|Set-Content -LiteralPath (Join-Path $output 'review.html') -Encoding UTF8
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'projection-core.js') -Destination $output
Copy-Item -LiteralPath (Join-Path $PSScriptRoot 'landmarks-template.json') -Destination $output
$files=@(Get-ChildItem -LiteralPath $output -File|ForEach-Object {[pscustomobject]@{Name=$_.Name;SHA256=(Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash}})
$files|ConvertTo-Json -Depth 4|Set-Content -LiteralPath (Join-Path $output 'files.json') -Encoding UTF8
$zip=$output+'.zip';Compress-Archive -Path (Join-Path $output '*') -DestinationPath $zip
Write-Host "EvidenceDirectory=$output"
Write-Host "EvidenceZip=$zip"
Write-Host "Status=$status Reason=$reason Viewport=NOT_MEASURED Landmarks=MISSING FrameAlignment=UNVERIFIED AimWrites=NONE"
if($status-ceq 'INCOMPLETE_CAPTURE'){exit 1}
