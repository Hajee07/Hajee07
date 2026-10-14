[CmdletBinding()]
param([Parameter(Mandatory=$true)][string] $KernelElfPath)
$ErrorActionPreference = 'Stop'
$options = @{ Path = @((Join-Path $PSScriptRoot 'GuestProcessMap.cs'), (Join-Path $PSScriptRoot 'CoreTests.cs')) }
if ((Get-Command Add-Type).Parameters.ContainsKey('CompilerOptions')) { $options.CompilerOptions = '/langversion:5' }
Add-Type @options
[HeadBridge.Mapping.Tests.Checks]::Run($KernelElfPath)
