$ErrorActionPreference='Stop'
Set-StrictMode -Version 2
$source=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'Run-PlayerCamera.ps1') -Raw
$proof=[regex]::Match($source,'(?s)# BEGIN IDENTITY PROOF(.*?)# END IDENTITY PROOF').Groups[1].Value
$renderer=[regex]::Match($source,'(?s)# BEGIN IDENTITY RENDER(.*?)# END IDENTITY RENDER').Groups[1].Value
if(!$proof-or !$renderer){throw 'Authored identity blocks missing'}
. ([scriptblock]::Create($proof))
$script:lines=[Collections.Generic.List[string]]::new()
function Record([string]$Text){$script:lines.Add($Text)}
foreach($match in @($true,$false,$null)){
    $sourceData=[pscustomobject]@{CameraSelectionStatus='SOURCE_ONLY';CameraUnityCodeStatus='CODE_VERIFIED';SelectedNativeCamera=[uint64]0x10000;CameraControllerInventoryStatus='FIELD_ONLY';ControllerManagedCamera=[uint64]0x20000;ControllerCachedNative=[uint64]0x10000;ControllerNativeMatchesSelection=$match;GameCameraGateStatus='NOT_READY_GETTER_METADATA_INITIALIZATION';GameCameraGetterInitRaw=0;GameCameraPatchInitRaw=0;GameCameraHotfixSlotPresent=$null;CameraNullPredicateStatus='UNVERIFIED'}
    $identity=[pscustomobject]@{Status='RECHECKED_IDENTITY_INVENTORY_ONLY';AdditionalReads=123;Observations=12;Sources=$sourceData;PlayerManagedTransform=[uint64]0x30000;PlayerNativeTransform=[uint64]0x40000;OriginalMainNativeTransform=[uint64]0x40000;OriginalMainTransformMatchesPlayer=$match}
    $script:lines.Clear();$failed=$false;. ([scriptblock]::Create($renderer))
    $expected=if($null-eq $match){'UNVERIFIED'}else{$match.ToString()}
    if(@($script:lines|Where-Object {$_ -like ('CameraIdentityOriginalMain *TransformMatchesPlayer='+$expected)}).Count-ne 1){throw 'Identity proof rendering mismatch'}
    if(@($script:lines|Where-Object {$_ -like '*HotfixSlot=UNVERIFIED *'}).Count-ne 1){throw 'Unknown getter gate rendered as false'}
    "PASS: identity renderer nullable proof=$expected"
}
$identity.Sources=$null;$identity.Status='NOT_READY_READ_BUDGET';$script:lines.Clear();$failed=$false;. ([scriptblock]::Create($renderer))
if(!$failed-or @($script:lines|Where-Object {$_ -like 'CameraIdentityPlayer *'}).Count-ne 0){throw 'Budget renderer leaked tentative pointers'}
'PASS: identity budget renderer suppresses source pointers'
