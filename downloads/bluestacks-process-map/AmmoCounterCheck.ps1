# Functions only. Input reports are parsed as text and never evaluated as code.
Set-StrictMode -Version 2
function Get-AmmoReportLine {
    param([string[]]$Lines,[string]$Key)
    $hits = @($Lines | Where-Object { $_ -match ('^' + [regex]::Escape($Key) + '(?:=| )') })
    if ($hits.Count -ne 1) { throw "Expected one $Key record; found $($hits.Count)." }
    return [string]$hits[0]
}
function Match-AmmoReportLine {
    param([string[]]$Lines,[string]$Key,[string]$Pattern)
    $match = [regex]::Match((Get-AmmoReportLine $Lines $Key),$Pattern)
    if (-not $match.Success) { throw "Invalid or unaccepted $Key record." }
    return $match
}
function ConvertFrom-AmmoCounterReport {
    param([Parameter(Mandatory=$true)][string[]]$Lines)
    $version = Match-AmmoReportLine $Lines 'ProcessMapVersion' '^ProcessMapVersion=(32|33|34|35|36|37|38|39|40|41|42|43|44|45|46) ReadOnly=1$'
    $hostInfo = Match-AmmoReportLine $Lines 'Preflight' '^Preflight=PASS Machine=(\S+) HostPID=([1-9][0-9]*) VmmDigest=MATCH$'
    $deviceInfo = Match-AmmoReportLine $Lines 'SelectedDevice' '^SelectedDevice=(\S+) State=device$'
    $gameInfo = Match-AmmoReportLine $Lines 'GameIdentity' '^GameIdentity=PASS GuestPID=([1-9][0-9]*) Name=(?:com)?\.dts\.freefireth$'
    $moduleInfo = Match-AmmoReportLine $Lines 'GameModuleIdentity' '^GameModuleIdentity=PASS LoadBias=(0x[0-9a-fA-F]+) BuildId=(ee8bf32c4483429084fde022704ead01a94b6620) '
    [void](Match-AmmoReportLine $Lines 'ApkReferenceSHA256' '^ApkReferenceSHA256=549093d79212873f26bc13f8957d06cc7575e92f24b53721eb13e8a0a53cb657 RuntimeVerification=ELF_TABLES_SEGMENT_OFFSETS_BUILD_ID_AND_CODE_SAMPLES$')
    [void](Match-AmmoReportLine $Lines 'GameLayoutComparisonSummary' '^GameLayoutComparisonSummary Checks=80 Passes=2 DistinctMismatches=0 MismatchObservations=0 ChangedBetweenPasses=0$')
    [void](Match-AmmoReportLine $Lines 'GameLayoutRegistration' '^GameLayoutRegistration=PASS Fields=9 Methods=9 Checks=80 Passes=2$')
    $phase = Match-AmmoReportLine $Lines 'WeaponAmmoSamples' '^WeaponAmmoSamples AdditionalPhysicalReads=([0-9]+) Attempted=1 Sampled=1 StopReason=SELECTED_OBJECTS_EXHAUSTED Detail=$'
    $selection = Match-AmmoReportLine $Lines 'WeaponSelection' '^WeaponSelection Status=ORIGINAL_SELECTED_WEAPON_VERIFIED Path=(ACTIVE_PLAYER_FIELD|ON_HAND_CONTROLLER_A0|ON_HAND_CONTROLLER_A8) Weapon=(0x[0-9a-fA-F]+) Class=(\S+)$'
    $counter = Match-AmmoReportLine $Lines 'SelectedWeaponAmmoCounter' '^SelectedWeaponAmmoCounter=(-?[0-9]+) Status=ORIGINAL_SELECTED_WEAPON_INT32_COUNTER_SAMPLED DataType=Int32 GetterRVA=0x7457fa4 Scope=ORIGINAL_SELECTED_WEAPON_COUNTER Magazine=UNVERIFIED Reserve=UNVERIFIED UnlimitedPolicy=UNVERIFIED$'
    $field = Match-AmmoReportLine $Lines 'WeaponAmmoField' '^WeaponAmmoField LocalIndex=([0-9]+) Name=(\S+) Registration=(RESOLVED_OFFSET|OPAQUE_SOURCE_RUNTIME_FIELD_VERIFIED) Binding=UNIQUE_RUNTIME_OFFSET_AND_NATIVE_GETTER$'
    $member = Match-AmmoReportLine $Lines 'WeaponAmmoMembership' '^WeaponAmmoMembership RosterIndex=([0-9]+) Player=(0x[0-9a-fA-F]+) IsLocal=True Proof=SELECTED_ENTRY_REVALIDATED CountersChangedSinceRoster=(True|False) CountersChangedDuringCapture=(True|False) Observations=([1-9][0-9]*)$'
    $total = Match-AmmoReportLine $Lines 'PhysicalReadCalls' '^PhysicalReadCalls=([0-9]+) TranslationCacheHits=[0-9]+$'
    foreach ($key in @('PluginUnload','HandlerCleanup')) { [void](Match-AmmoReportLine $Lines $key ('^' + $key + '=PASS$')) }
    [void](Match-AmmoReportLine $Lines 'SharedSession' '^SharedSession=RELEASED$')
    if ([long]$phase.Groups[1].Value -gt 6000 -or [long]$total.Groups[1].Value -gt 30000 -or
        [long]$field.Groups[1].Value -gt 252 -or [long]$member.Groups[1].Value -gt 15) { throw 'Report bounds are invalid.' }
    $weapon = [Convert]::ToUInt64($selection.Groups[2].Value.Substring(2),16)
    $playerValue = [Convert]::ToUInt64($member.Groups[2].Value.Substring(2),16)
    $bias = [Convert]::ToUInt64($moduleInfo.Groups[1].Value.Substring(2),16)
    foreach ($pointer in @($weapon,$playerValue,$bias)) { if ($pointer -lt 65536 -or $pointer -ge 0x0000800000000000L) { throw 'Report pointer is invalid.' } }
    $raw = [int]::Parse($counter.Groups[1].Value,[Globalization.CultureInfo]::InvariantCulture)
    [pscustomobject]@{
        Version=[int]$version.Groups[1].Value; Machine=$hostInfo.Groups[1].Value; HostPid=$hostInfo.Groups[2].Value
        Device=$deviceInfo.Groups[1].Value; GuestPid=$gameInfo.Groups[1].Value; BuildId=$moduleInfo.Groups[2].Value
        LoadBias=$bias.ToString('x'); Weapon=$weapon.ToString('x'); WeaponClass=$selection.Groups[3].Value
        Player=$playerValue.ToString('x'); FieldIndex=[int]$field.Groups[1].Value; FieldName=$field.Groups[2].Value
        RawCounter=$raw; AdditionalReads=[long]$phase.Groups[1].Value; TotalReads=[long]$total.Groups[1].Value
    }
}
function Compare-AmmoCounterSamples {
    param([object[]]$Samples,[int[]]$ReportedHudCounts)
    if ($Samples.Count -ne 3 -or $ReportedHudCounts.Count -ne 3) { throw 'Exactly three ordered samples and HUD counts are required.' }
    foreach ($n in $ReportedHudCounts) { if ($n -lt 0) { throw 'Reported HUD counts must be nonnegative Int32 values.' } }
    $status='CONSISTENT_WITH_REPORTED_MAGAZINE_COUNTER'
    foreach ($key in @('Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Weapon','WeaponClass','Player','FieldIndex','FieldName')) {
        if ([string]$Samples[0].$key -cne [string]$Samples[1].$key -or [string]$Samples[0].$key -cne [string]$Samples[2].$key) { $status='INCONCLUSIVE_CONTEXT_CHANGED';break }
    }
    if ($status -eq 'CONSISTENT_WITH_REPORTED_MAGAZINE_COUNTER') {
        for ($i=0;$i -lt 3;$i++) { if ($Samples[$i].RawCounter -ne $ReportedHudCounts[$i]) { $status='INCONCLUSIVE_HUD_MISMATCH';break } }
    }
    $shotDelta=[long]$Samples[0].RawCounter - [long]$Samples[1].RawCounter
    $reloadDelta=[long]$Samples[2].RawCounter - [long]$Samples[1].RawCounter
    if ($status -eq 'CONSISTENT_WITH_REPORTED_MAGAZINE_COUNTER' -and $shotDelta -ne 1) { $status='INCONCLUSIVE_ONE_SHOT_CHANGE' }
    if ($status -eq 'CONSISTENT_WITH_REPORTED_MAGAZINE_COUNTER' -and $reloadDelta -le 0) { $status='INCONCLUSIVE_RELOAD_CHANGE' }
    [pscustomobject]@{ Status=$status; Evidence='MANUAL_HUD_CORRELATION_ONLY'; ShotAction='USER_REPORTED_ONE_SHOT'; ReloadAction='USER_REPORTED_RELOAD'
        ShotDelta=$shotDelta; ReloadDelta=$reloadDelta; ReportedHudCounts=$ReportedHudCounts; Samples=$Samples
        UniversalMagazineSemantics='UNVERIFIED'; Reserve='UNVERIFIED'; UnlimitedPolicy='UNVERIFIED'; FiringReadiness='UNVERIFIED'; AimIntegration='INCOMPLETE' }
}
