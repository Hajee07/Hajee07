[CmdletBinding()]
param(
    [Parameter(Mandatory=$true)][string]$ReportPath,
    [string]$MappingSourceDirectory=(Join-Path $PSScriptRoot '..\bluestacks-process-map')
)
$ErrorActionPreference='Stop'
Set-StrictMode -Version Latest
$file=Get-Item -LiteralPath $ReportPath
if($file.PSIsContainer -or $file.Length -gt 2097152){throw 'Expected one report file no larger than 2 MiB.'}
$mapping=(Resolve-Path -LiteralPath $MappingSourceDirectory).Path
. (Join-Path $mapping 'AimBasisCheck.ps1')
. (Join-Path $mapping 'CameraPoseCheck.ps1')
$lines=@(Get-Content -LiteralPath $file.FullName)
$pose=ConvertFrom-CameraPoseReport $lines
if($pose.Version -ne 52){throw 'This assessment supports the V52 report contract only.'}
$controller=@($lines | Where-Object {$_ -match '^CameraControllerInventory '})
if($controller.Count -ne 1){throw 'Expected one controller inventory row.'}
$match=[regex]::Match($controller[0],'^CameraControllerInventory Status=(\S+) ')
if(!$match.Success){throw 'Malformed controller inventory status.'}
[pscustomobject]@{
    Assessment='OFFLINE_REPORT_ONLY_LIVE_BINDING_UNBOUND'
    ReportSHA256=(Get-FileHash -LiteralPath $file.FullName -Algorithm SHA256).Hash.ToLowerInvariant()
    RunnerVersion=$pose.Version
    NativePoseReportChecks='PASS'
    ControllerStatusReported=$match.Groups[1].Value
    ReportedAdditionalReads=$pose.AdditionalReads
    CameraVerifiedProof='Unknown'
    CoherentFrameProof='Unknown'
    GenerationAwareTargetIdentityProof='Unknown'
    FullCombatEligibilityProof='Unknown'
    AuthoritativeLosProof='Unknown'
    CompleteCollisionGeometry='Not supplied'
    AimOutputAdapter='Unbound'
    LiveBindingReady=$false
    MissingContracts=@('coherent observation and target lifetime','active game camera and shot convention','full hostility/attackability proof','authoritative collision query or complete matching geometry','verified output adapter with application-time checks')
    GameFunctionsInvoked=$false
    AimWrites='NONE'
} | ConvertTo-Json -Depth 4
