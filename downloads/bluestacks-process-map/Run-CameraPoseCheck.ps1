[CmdletBinding()]
param([string]$MachineName='Pie64',[ValidatePattern('^[A-Za-z0-9_.:-]+$')][string]$Device='127.0.0.1:5555')
Set-StrictMode -Version 2
$ErrorActionPreference='Stop'
$manifest=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'manifest.json') -Raw | ConvertFrom-Json
$helper=Join-Path $PSScriptRoot 'AimBasisCheck.ps1'
$runner=Join-Path $PSScriptRoot 'Run-ProcessMap.ps1'
if ($manifest.aim_basis_comparison_sha256 -notmatch '^[0-9a-f]{64}$' -or $manifest.runner_sha256 -notmatch '^[0-9a-f]{64}$' -or
    (Get-FileHash -LiteralPath $helper -Algorithm SHA256).Hash -ine $manifest.aim_basis_comparison_sha256 -or
    (Get-FileHash -LiteralPath $runner -Algorithm SHA256).Hash -ine $manifest.runner_sha256) { throw 'Comparison helper/runner checksum mismatch.' }
. $helper
$poseHelper=Join-Path $PSScriptRoot 'CameraPoseCheck.ps1'
if ($manifest.camera_pose_comparison_sha256 -notmatch '^[0-9a-f]{64}$' -or (Get-FileHash -LiteralPath $poseHelper -Algorithm SHA256).Hash -ine $manifest.camera_pose_comparison_sha256) { throw 'Camera pose helper checksum mismatch.' }
. $poseHelper
$samples=@();$reportPaths=@()
$instructions=@(
    '1 BASELINE: Training-la stationary-ah nillunga. Oru tree/building-ai screen centre-la vechuttu READY',
    '2 RIGHT: camera right pakkam konjam thiruppunga; landmark screen-la LEFT poganum. Stop pannittu READY',
    '3 RESTORE: adhe landmark-ai original centre/height-ku kondu vandhu stop pannittu READY',
    '4 LEFT: camera left pakkam konjam thiruppunga; landmark screen-la RIGHT poganum. Stop pannittu READY',
    '5 BASELINE: landmark-ai thirumba original centre/height-ku kondu vandhu stop pannittu READY',
    '6 UP: camera konjam mela tilt pannunga; landmark screen-la DOWN poganum. Stop pannittu READY',
    '7 RESTORE: adhe landmark-ai original centre/height-ku kondu vandhu stop pannittu READY',
    '8 DOWN: camera konjam keezha tilt pannunga; landmark screen-la UP poganum. Stop pannittu READY'
)
for ($i=0;$i -lt 8;$i++) {
    Write-Host 'Keep the same character and match. Do not move, fire or aim-down-sights. Hold the camera still during each capture. No controls are automated.'
    $inputText=Read-Host $instructions[$i]
    if ($inputText.Trim() -cne 'READY') { throw 'Capture cancelled: type READY only after completing the requested manual action.' }
    $captureStarted=[DateTime]::UtcNow
    $output=@(& powershell.exe -NoProfile -ExecutionPolicy Bypass -File $runner -MachineName $MachineName -Device $Device -ProbeAimState)
    $childCode=$LASTEXITCODE
    $output | ForEach-Object { Write-Host $_ }
    if ($childCode -ne 0) { throw "Capture failed (exit $childCode). Keep the printed ResultFile report." }
    $paths=@($output | Where-Object { $_ -match '^ResultFile=' })
    if ($paths.Count -ne 1) { throw 'Expected one capture result path.' }
    $path=[IO.Path]::GetFullPath(([string]$paths[0]).Substring(11))
    if (-not [string]::Equals([IO.Path]::GetDirectoryName($path),[IO.Path]::GetFullPath($PSScriptRoot),[StringComparison]::OrdinalIgnoreCase) -or
        [IO.Path]::GetFileName($path) -notmatch '^process-map-result-[0-9a-f]{32}\.txt$') { throw 'Unexpected capture result path.' }
    if ($reportPaths -contains $path -or -not (Test-Path -LiteralPath $path) -or (Get-Item -LiteralPath $path).LastWriteTimeUtc -lt $captureStarted.AddSeconds(-2)) { throw 'Missing, repeated or stale capture result file.' }
    $samples+=ConvertFrom-CameraPoseReport -Lines @(Get-Content -LiteralPath $path)
    $reportPaths+=$path
}
$result=Compare-CameraPoseSamples -Samples $samples
$result | Add-Member -NotePropertyName SourceReports -NotePropertyValue $reportPaths
$result | Add-Member -NotePropertyName SourceReportSHA256 -NotePropertyValue @($reportPaths | ForEach-Object { (Get-FileHash -LiteralPath $_ -Algorithm SHA256).Hash.ToLowerInvariant() })
$resultFile=Join-Path $PSScriptRoot ('camera-pose-comparison-'+[guid]::NewGuid().ToString('N')+'.json')
$result | ConvertTo-Json -Depth 10 | Set-Content -LiteralPath $resultFile -Encoding UTF8
Write-Host "CameraPoseComparison=$($result.Status) Evidence=$($result.Evidence)"
Write-Host "NativeCameraYaw=$($result.Yaw.Status) Sign=$($result.Yaw.ObservedYawSign) Right=$($result.Yaw.RightYawDelta) Left=$($result.Yaw.LeftYawDelta)"
Write-Host "NativeCameraPitch=$($result.Pitch.Status) Sign=$($result.Pitch.ObservedPitchSign) Up=$($result.Pitch.UpElevationDelta) Down=$($result.Pitch.DownElevationDelta)"
Write-Host "AimCameraAngle MaximumDegrees=$($result.MaximumAimCameraDifferenceDegrees) WithinOneDegree=$($result.AimCameraWithinOneDegree) RawQuaternionsModified=False"
Write-Host 'CameraControls=MANUAL_ONLY ActualGameCamera=UNVERIFIED ShotDirection=UNVERIFIED LineOfSight=UNVERIFIED AimWrites=NONE AimIntegration=INCOMPLETE'
Write-Host "ComparisonResultFile=$resultFile"
