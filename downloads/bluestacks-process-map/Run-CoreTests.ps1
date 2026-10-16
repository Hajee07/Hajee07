[CmdletBinding()]
param([Parameter(Mandatory=$true)][string] $KernelElfPath)
$ErrorActionPreference = 'Stop'
$options = @{ Path = @('GuestProcessMap.cs', 'ModuleProbe.cs', 'ModuleReference.cs', 'GameLayoutProbe.cs', 'GameLayoutReference.cs', 'PlayerObjectProbe.cs', 'HeadCacheProbe.cs', 'NativeTransformProbe.cs', 'NativeTransformReference.cs', 'RosterProbe.cs', 'RosterReference.cs', 'OtherHeadProbe.cs', 'PlayerStateProbe.cs', 'PlayerStateReference.cs', 'PlayerStateTests.cs', 'TeamPolicyProbe.cs', 'TeamPolicyReference.cs', 'TeamPolicyTests.cs', 'CombatStateProbe.cs', 'CombatStateReference.cs', 'CombatStateTests.cs', 'ZoneProtectionProbe.cs', 'ZoneProtectionReference.cs', 'ZoneProtectionTests.cs', 'MatchDamageProbe.cs', 'MatchDamageReference.cs', 'MatchDamageTests.cs', 'WeaponContextProbe.cs', 'WeaponContextReference.cs', 'WeaponContextTests.cs', 'WeaponFiringProbe.cs', 'WeaponFiringReference.cs', 'WeaponFiringTests.cs', 'WeaponAmmoProbe.cs', 'WeaponAmmoReference.cs', 'WeaponAmmoTests.cs', 'NativeJobRetryTests.cs', 'AimStateProbe.cs', 'AimStateReference.cs', 'AimStateTests.cs', 'ObjectReference.cs', 'PlayerObjectTests.cs', 'CoreTests.cs', 'ModuleTests.cs', 'GameLayoutTests.cs' | ForEach-Object { Join-Path $PSScriptRoot $_ }) }
if ((Get-Command Add-Type).Parameters.ContainsKey('CompilerOptions')) { $options.CompilerOptions = '/langversion:5' }
Add-Type @options
[HeadBridge.Mapping.Tests.Checks]::Run($KernelElfPath)
[HeadBridge.Mapping.Tests.ModuleChecks]::Run()
[HeadBridge.Mapping.Tests.GameLayoutTests]::Run()
[HeadBridge.Mapping.Tests.PlayerObjectTests]::Run()

& (Join-Path $PSScriptRoot 'Test-AmmoCounterCheck.ps1')
