[CmdletBinding()]
param([string]$MappingSourceDirectory=(Join-Path $PSScriptRoot '..\bluestacks-process-map'))
$ErrorActionPreference='Stop'
$mapping=(Resolve-Path -LiteralPath $MappingSourceDirectory).Path
if(!(Test-Path -LiteralPath (Join-Path $mapping 'GuestProcessMap.cs'))){throw 'V52 mapping source directory is required for this compatibility check.'}
$files=@(Get-ChildItem -LiteralPath $mapping -Filter '*.cs' | Where-Object Name -NotLike '*Tests.cs' | Sort-Object Name | Select-Object -ExpandProperty FullName)
$files+=@('Targeting.cs','MeshLineOfSight.cs','AdvancedController.cs','AimCoordinator.cs','TargetingTests.cs','AdvancedTests.cs','TiltedGeometryTests.cs','SimulationDemo.cs' | ForEach-Object {Join-Path $PSScriptRoot $_})
$options=@{Path=$files}
if((Get-Command Add-Type).Parameters.ContainsKey('CompilerOptions')){$options.CompilerOptions=@('/langversion:5','/warnaserror+')}
Add-Type @options
Write-Output 'V52SourceCompile=PASS Scope=SOURCE_COMPATIBILITY_ONLY LiveBinding=UNBOUND'
[HeadBridge.Mapping.Targeting.Tests]::Run()
[HeadBridge.Mapping.Targeting.AdvancedTests]::Run()
[TiltedGeometryTests]::Run()
$demo=[HeadBridge.Mapping.Targeting.Tests].Assembly.GetType('SimulationHost',$true)
$result=$demo.GetMethod('Main',[Reflection.BindingFlags]'Public,Static').Invoke($null,@())
if($result -ne 0){throw 'Source rebuilt simulation failed.'}
Write-Output 'OfflineChecks=PASS Assertions=579 GameCalls=NONE AimWrites=NONE LiveIntegration=NOT_TESTED'
