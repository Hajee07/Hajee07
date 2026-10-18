[CmdletBinding()]
param([string]$RuntimeDirectory,[string]$KernelElfPath)
$ErrorActionPreference='Stop'
if(!$RuntimeDirectory){$RuntimeDirectory=Join-Path $PSScriptRoot 'baseline';if(!(Test-Path $RuntimeDirectory)){$RuntimeDirectory=Join-Path $PSScriptRoot '..\bluestacks-process-map'}}
$files=@(Get-ChildItem -LiteralPath $RuntimeDirectory -Filter '*.cs'|Where-Object Name -ne 'GuestProcessMap.cs'|Select-Object -ExpandProperty FullName)
$files+=@('GuestProcessMap.Diagnostics.cs','PlayerCameraReference.cs','PlayerCameraProbe.cs','PlayerCameraTests.cs'|ForEach-Object {Join-Path $PSScriptRoot $_})
# BEGIN COMPATIBLE COMPILE
$compileArguments = @{ Path = $files; ErrorAction = 'Stop' }
if ((Get-Command Add-Type).Parameters.ContainsKey('CompilerOptions')) {
    $compileArguments.CompilerOptions = @('/langversion:5','/warnaserror+')
}
Add-Type @compileArguments
# END COMPATIBLE COMPILE
[HeadBridge.Mapping.Tests.PlayerObjectTests]::RunPlayerCameraChecks()
[HeadBridge.Mapping.Tests.PlayerObjectTests]::RunPlayerCameraIdentityChecks()

if($KernelElfPath){
    [HeadBridge.Mapping.Tests.Checks]::Run($KernelElfPath)
    [HeadBridge.Mapping.Tests.ModuleChecks]::Run()
    [HeadBridge.Mapping.Tests.GameLayoutTests]::Run()
    [HeadBridge.Mapping.Tests.PlayerObjectTests]::Run()
    foreach($test in @('Test-AmmoCounterCheck.ps1','Test-AimBasisCheck.ps1','Test-CameraPoseCheck.ps1','Test-ReportRendering.ps1')){& (Join-Path $RuntimeDirectory $test)}
}
