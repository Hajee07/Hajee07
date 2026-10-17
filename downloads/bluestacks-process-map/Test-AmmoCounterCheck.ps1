$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'AmmoCounterCheck.ps1')
$script:checkCount=0
function Check-Comparison($Condition,$Message) { if (-not $Condition) { throw $Message };$script:checkCount++;Write-Host "PASS: $Message" }
function Reject-Comparison([scriptblock]$Action,$Message) { $rejected=$false;try { & $Action | Out-Null } catch { $rejected=$true };Check-Comparison $rejected $Message }
$fixture=@(
'ProcessMapVersion=34 ReadOnly=1',
'Preflight=PASS Machine=Pie64 HostPID=11784 VmmDigest=MATCH',
'SelectedDevice=127.0.0.1:5555 State=device',
'GameIdentity=PASS GuestPID=9214 Name=.dts.freefireth',
'GameModuleIdentity=PASS LoadBias=0x77f244e00000 BuildId=ee8bf32c4483429084fde022704ead01a94b6620 LoadSegments=8',
'ApkReferenceSHA256=549093d79212873f26bc13f8957d06cc7575e92f24b53721eb13e8a0a53cb657 RuntimeVerification=ELF_TABLES_SEGMENT_OFFSETS_BUILD_ID_AND_CODE_SAMPLES',
'GameLayoutComparisonSummary Checks=80 Passes=2 DistinctMismatches=0 MismatchObservations=0 ChangedBetweenPasses=0',
'GameLayoutRegistration=PASS Fields=9 Methods=9 Checks=80 Passes=2',
'WeaponAmmoSamples AdditionalPhysicalReads=4284 Attempted=1 Sampled=1 StopReason=SELECTED_OBJECTS_EXHAUSTED Detail=',
'WeaponSelection Status=ORIGINAL_SELECTED_WEAPON_VERIFIED Path=ON_HAND_CONTROLLER_A0 Weapon=0x77f1b406a000 Class=COW.GamePlay.HBIBDMMOOOK',
'SelectedWeaponAmmoCounter=2 Status=ORIGINAL_SELECTED_WEAPON_INT32_COUNTER_SAMPLED DataType=Int32 GetterRVA=0x7457fa4 Scope=ORIGINAL_SELECTED_WEAPON_COUNTER Magazine=UNVERIFIED Reserve=UNVERIFIED UnlimitedPolicy=UNVERIFIED',
'WeaponAmmoField LocalIndex=105 Name=NJEENAEMFAO Registration=RESOLVED_OFFSET Binding=UNIQUE_RUNTIME_OFFSET_AND_NATIVE_GETTER',
'WeaponAmmoMembership RosterIndex=0 Player=0x77f1c2835000 IsLocal=True Proof=SELECTED_ENTRY_REVALIDATED CountersChangedSinceRoster=False CountersChangedDuringCapture=False Observations=154',
'PhysicalReadCalls=24208 TranslationCacheHits=3472','PluginUnload=PASS','HandlerCleanup=PASS','SharedSession=RELEASED'
)
$version44=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=44") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version44).Version -eq 44) "comparison workflow accepts unchanged counter contract from V44"
$version45=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=45") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version45).Version -eq 45) "comparison workflow accepts unchanged counter contract from V45"
$version46=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=46") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version46).Version -eq 46) "comparison workflow accepts unchanged counter contract from V46"
$version47=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=47") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version47).Version -eq 47) "comparison workflow accepts unchanged counter contract from V47"
$version48=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=48") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version48).Version -eq 48) "comparison workflow accepts unchanged counter contract from V48"
$version49=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=49") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version49).Version -eq 49) "comparison workflow accepts unchanged counter contract from V49"
$version43=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=43") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version43).Version -eq 43) "comparison workflow accepts unchanged counter contract from V43"
$version42=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=42") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version42).Version -eq 42) "comparison workflow accepts unchanged counter contract from V42"
$version41=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=41") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version41).Version -eq 41) "comparison workflow accepts unchanged counter contract from V41"
$version40=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=40") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version40).Version -eq 40) "comparison workflow accepts unchanged counter contract from V40"
$version39=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=39") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version39).Version -eq 39) "comparison workflow accepts unchanged counter contract from V39"
$version38=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=38") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version38).Version -eq 38) "comparison workflow accepts unchanged counter contract from V38"
$version37=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=37") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version37).Version -eq 37) "comparison workflow accepts unchanged counter contract from V37"
$version36=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=36") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version36).Version -eq 36) "comparison workflow accepts unchanged counter contract from V36"
$version35=@($fixture | ForEach-Object { $_.Replace("ProcessMapVersion=34","ProcessMapVersion=35") })
Check-Comparison ((ConvertFrom-AmmoCounterReport $version35).Version -eq 35) "comparison workflow accepts unchanged counter contract from V35"
$parsed=ConvertFrom-AmmoCounterReport $fixture
Check-Comparison ($parsed.RawCounter -eq 2 -and $parsed.FieldIndex -eq 105) 'comparison parser accepts the exact counter contract'
foreach ($key in @('PluginUnload','HandlerCleanup','SharedSession','WeaponAmmoField','GameLayoutRegistration')) {
    $bad=@($fixture | Where-Object { $_ -notmatch ('^'+$key+'(?:=| )') })
    Reject-Comparison { ConvertFrom-AmmoCounterReport $bad } "missing $key cannot establish an accepted comparison sample"
}
Reject-Comparison { ConvertFrom-AmmoCounterReport ($fixture+@($fixture[10])) } 'duplicate counter records are rejected'
foreach ($replacement in @(@('PhysicalReadCalls=24208','PhysicalReadCalls=30001'),@('AdditionalPhysicalReads=4284','AdditionalPhysicalReads=6001'),@('IsLocal=True','IsLocal=False'),@('Scope=ORIGINAL_SELECTED_WEAPON_COUNTER','Scope=OTHER'),@('Counter=2 ','Counter=2147483648 '))) {
    $bad=@($fixture | ForEach-Object { $_.Replace($replacement[0],$replacement[1]) })
    Reject-Comparison { ConvertFrom-AmmoCounterReport $bad } "invalid report contract is rejected: $($replacement[1])"
}
function Sample-WithCounter([int]$Value) { $s=ConvertFrom-AmmoCounterReport $fixture;$s.RawCounter=$Value;return $s }
$samples=@((Sample-WithCounter 2),(Sample-WithCounter 1),(Sample-WithCounter 2))
$ok=Compare-AmmoCounterSamples $samples @(2,1,2)
Check-Comparison ($ok.Status -eq 'CONSISTENT_WITH_REPORTED_MAGAZINE_COUNTER' -and $ok.Evidence -eq 'MANUAL_HUD_CORRELATION_ONLY' -and $ok.FiringReadiness -eq 'UNVERIFIED') 'matching one-shot/reload pattern remains empirical HUD correlation only'
Check-Comparison ((Compare-AmmoCounterSamples $samples @(3,1,2)).Status -eq 'INCONCLUSIVE_HUD_MISMATCH') 'a HUD mismatch cannot be accepted as magazine correlation'
foreach ($key in @('GuestPid','Weapon','Player','FieldName','LoadBias','Device')) {
    $changed=@((Sample-WithCounter 2),(Sample-WithCounter 1),(Sample-WithCounter 2));$changed[1].$key='CHANGED'
    Check-Comparison ((Compare-AmmoCounterSamples $changed @(2,1,2)).Status -eq 'INCONCLUSIVE_CONTEXT_CHANGED') "changed $key prevents combining captures"
}
Check-Comparison ((Compare-AmmoCounterSamples @((Sample-WithCounter 2),(Sample-WithCounter 2),(Sample-WithCounter 2)) @(2,2,2)).Status -eq 'INCONCLUSIVE_ONE_SHOT_CHANGE') 'unchanged counter after the reported shot remains inconclusive'
Check-Comparison ((Compare-AmmoCounterSamples @((Sample-WithCounter 2),(Sample-WithCounter 1),(Sample-WithCounter 1)) @(2,1,1)).Status -eq 'INCONCLUSIVE_RELOAD_CHANGE') 'a reload without an increase remains inconclusive'
Reject-Comparison { Compare-AmmoCounterSamples $samples @(-1,1,2) } 'negative HUD input is rejected without reinterpreting sentinel values'
Reject-Comparison { Compare-AmmoCounterSamples @($samples[0]) @(2) } 'incomplete experiments cannot establish correlation'
Write-Host "COMPARISON_TOTAL=$script:checkCount"
