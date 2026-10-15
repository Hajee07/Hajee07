[CmdletBinding()]
param([Parameter(Mandatory=$true)][string] $KernelElfPath)
$ErrorActionPreference = 'Stop'
$options = @{ Path = @('GuestProcessMap.cs', 'ModuleProbe.cs', 'ModuleReference.cs', 'CoreTests.cs', 'ModuleTests.cs' | ForEach-Object { Join-Path $PSScriptRoot $_ }) }
if ((Get-Command Add-Type).Parameters.ContainsKey('CompilerOptions')) { $options.CompilerOptions = '/langversion:5' }
Add-Type @options
[HeadBridge.Mapping.Tests.Checks]::Run($KernelElfPath)
[HeadBridge.Mapping.Tests.ModuleChecks]::Run()
