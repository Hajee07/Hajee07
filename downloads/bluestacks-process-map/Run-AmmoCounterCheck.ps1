[CmdletBinding()]
param([string]$MachineName='Pie64',[ValidatePattern('^[A-Za-z0-9_.:-]+$')][string]$Device='127.0.0.1:5555')
Set-StrictMode -Version 2
$ErrorActionPreference='Stop'
$manifest=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'manifest.json') -Raw | ConvertFrom-Json
$helper=Join-Path $PSScriptRoot 'AmmoCounterCheck.ps1'
$runner=Join-Path $PSScriptRoot 'Run-ProcessMap.ps1'
if ($manifest.ammo_comparison_sha256 -notmatch '^[0-9a-f]{64}$' -or $manifest.runner_sha256 -notmatch '^[0-9a-f]{64}$' -or
    (Get-FileHash -LiteralPath $helper -Algorithm SHA256).Hash -ine $manifest.ammo_comparison_sha256 -or
    (Get-FileHash -LiteralPath $runner -Algorithm SHA256).Hash -ine $manifest.runner_sha256) { throw 'Comparison helper/runner checksum mismatch.' }
. $helper
$samples=@();$hudCounts=@();$reportPaths=@()
$instructions=@(
    'Baseline: equip one firearm in Training, stop moving/firing, then enter the HUD loaded-ammo number',
    'Fire exactly ONE shot manually, stop firing, then enter the new HUD loaded-ammo number',
    'Reload manually and wait until it finishes, then enter the HUD loaded-ammo number'
)
for ($i=0;$i -lt 3;$i++) {
    Write-Host 'Keep the same weapon and character for all three captures. No controls are automated.'
    $inputText=Read-Host $instructions[$i]
    $hud=0
    if ($inputText -notmatch '^[0-9]+$' -or -not [int]::TryParse($inputText,[ref]$hud)) { throw 'Enter a nonnegative Int32 HUD number.' }
    $output=@(& powershell.exe -NoProfile -ExecutionPolicy Bypass -File $runner -MachineName $MachineName -Device $Device -ProbeWeaponAmmo)
    $childCode=$LASTEXITCODE
    $output | ForEach-Object { Write-Host $_ }
    if ($childCode -ne 0) { throw "Capture failed (exit $childCode). Keep the printed ResultFile report." }
    $paths=@($output | Where-Object { $_ -match '^ResultFile=' })
    if ($paths.Count -ne 1) { throw 'Expected one capture result path.' }
    $path=[IO.Path]::GetFullPath(([string]$paths[0]).Substring(11))
    if (-not [string]::Equals([IO.Path]::GetDirectoryName($path),[IO.Path]::GetFullPath($PSScriptRoot),[StringComparison]::OrdinalIgnoreCase) -or
        [IO.Path]::GetFileName($path) -notmatch '^process-map-result-[0-9a-f]{32}\.txt$') { throw 'Unexpected capture result path.' }
    $samples+=ConvertFrom-AmmoCounterReport -Lines @(Get-Content -LiteralPath $path)
    $hudCounts+=$hud;$reportPaths+=$path
}
$result=Compare-AmmoCounterSamples -Samples $samples -ReportedHudCounts $hudCounts
$result | Add-Member -NotePropertyName SourceReports -NotePropertyValue $reportPaths
$resultFile=Join-Path $PSScriptRoot ('ammo-counter-comparison-'+[guid]::NewGuid().ToString('N')+'.json')
$result | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $resultFile -Encoding UTF8
Write-Host "AmmoCounterComparison=$($result.Status) Evidence=$($result.Evidence) ShotDelta=$($result.ShotDelta) ReloadDelta=$($result.ReloadDelta)"
Write-Host 'UniversalMagazineSemantics=UNVERIFIED Reserve=UNVERIFIED UnlimitedPolicy=UNVERIFIED FiringReadiness=UNVERIFIED AimIntegration=INCOMPLETE'
Write-Host "ComparisonResultFile=$resultFile"
