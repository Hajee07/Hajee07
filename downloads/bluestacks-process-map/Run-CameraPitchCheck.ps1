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
$samples=@();$reportPaths=@()
$instructions=@(
    'BASELINE: stand still in Training. Put one fixed tree/building at screen centre, camera roughly level. Remember its height. Type READY',
    'UP: tilt camera a little UP so the landmark moves DOWN on screen. Keep horizontal direction unchanged. Stop and type READY',
    'RESTORE: return that SAME landmark to the SAME centre position and height. Stop and type READY',
    'DOWN: tilt camera a little DOWN so the landmark moves UP on screen. Keep horizontal direction unchanged. Stop and type READY'
)
for ($i=0;$i -lt 4;$i++) {
    Write-Host 'Keep the same character and match. Do not move, fire or aim-down-sights. Hold the camera still during each capture. No controls are automated.'
    $inputText=Read-Host $instructions[$i]
    if ($inputText.Trim() -cne 'READY') { throw 'Capture cancelled: type READY only after completing the requested manual action.' }
    $output=@(& powershell.exe -NoProfile -ExecutionPolicy Bypass -File $runner -MachineName $MachineName -Device $Device -ProbeAimState)
    $childCode=$LASTEXITCODE
    $output | ForEach-Object { Write-Host $_ }
    if ($childCode -ne 0) { throw "Capture failed (exit $childCode). Keep the printed ResultFile report." }
    $paths=@($output | Where-Object { $_ -match '^ResultFile=' })
    if ($paths.Count -ne 1) { throw 'Expected one capture result path.' }
    $path=[IO.Path]::GetFullPath(([string]$paths[0]).Substring(11))
    if (-not [string]::Equals([IO.Path]::GetDirectoryName($path),[IO.Path]::GetFullPath($PSScriptRoot),[StringComparison]::OrdinalIgnoreCase) -or
        [IO.Path]::GetFileName($path) -notmatch '^process-map-result-[0-9a-f]{32}\.txt$') { throw 'Unexpected capture result path.' }
    $samples+=ConvertFrom-AimBasisReport -Lines @(Get-Content -LiteralPath $path)
    $reportPaths+=$path
}
$result=Compare-CameraPitchSamples -Samples $samples
$result | Add-Member -NotePropertyName SourceReports -NotePropertyValue $reportPaths
$resultFile=Join-Path $PSScriptRoot ('camera-pitch-comparison-'+[guid]::NewGuid().ToString('N')+'.json')
$result | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $resultFile -Encoding UTF8
Write-Host "CameraPitchComparison=$($result.Status) ObservedPitchSign=$($result.ObservedPitchSign) Evidence=$($result.Evidence)"
Write-Host "CameraElevationDeltas Up=$($result.UpElevationDelta) RestoredBaselineError=$($result.RestoredBaselineElevationError) Down=$($result.DownElevationDelta)"
Write-Host "CameraYawDrifts Up=$($result.UpYawDrift) RestoredBaselineError=$($result.RestoredBaselineYawError) Down=$($result.DownYawDrift)"
Write-Host 'VectorFlipped=False CameraControls=MANUAL_ONLY'
Write-Host "RosterCounterAudit CapturesWithChanges=$($result.CapturesWithRosterCounterChanges) MembershipScope=$($result.MembershipScope) CompleteRosterStability=NOT_ASSERTED"
Write-Host 'CameraConvention=UNVERIFIED ShotDirection=UNVERIFIED LineOfSight=UNVERIFIED AimWrites=NONE AimIntegration=INCOMPLETE'
Write-Host "ComparisonResultFile=$resultFile"
