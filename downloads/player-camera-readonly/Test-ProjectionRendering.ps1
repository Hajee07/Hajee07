$ErrorActionPreference='Stop'
Set-StrictMode -Version 2
$source=Get-Content -Raw -LiteralPath (Join-Path $PSScriptRoot 'Run-PlayerCamera.ps1')
$block=[regex]::Match($source,'(?s)# BEGIN PROJECTION RENDER(.*?)# END PROJECTION RENDER').Groups[1].Value
if(!$block){throw 'Projection render block missing'}
$script:lines=[Collections.Generic.List[string]]::new()
function Record([string]$Text){$script:lines.Add($Text)}
$captureStart='2026-10-18T00:00:00Z';$captureEnd='2026-10-18T00:00:01Z'
$original=[Threading.Thread]::CurrentThread.CurrentCulture
try{
    [Threading.Thread]::CurrentThread.CurrentCulture=[Globalization.CultureInfo]::GetCultureInfo('fr-FR')
    foreach($status in @('SAMPLED_CLEAN_CACHE_READ_ONLY','NOT_READY_DIRTY_CACHE','NOT_READY_BINDING_UNINITIALIZED','NOT_READY_INVALID_MATRIX')){
        $values=[double[]]@(1.25,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1)
        $identity=[pscustomobject]@{Status='RECHECKED_CAMERA_CACHE_INVENTORY';Projection=[pscustomobject]@{Status=$status;ViewDirty=0;ProjectionDirty=0;ViewNativeSequence=$values;ProjectionNativeSequence=$values}}
        if($status -ceq 'NOT_READY_BINDING_UNINITIALIZED'){$identity.Projection.ViewDirty=$null;$identity.Projection.ProjectionDirty=$null}
        $failed=$false;$script:lines.Clear();. ([scriptblock]::Create($block))
        if($status -ceq 'NOT_READY_BINDING_UNINITIALIZED' -and @($script:lines|Where-Object {$_ -like '*ViewDirty=UNVERIFIED ProjectionDirty=UNVERIFIED*'}).Count-ne 1){throw 'Unknown flags rendered incorrectly'}
        $matrixLines=@($script:lines|Where-Object {$_ -match '^Camera(View|Projection)NativeSequence '})
        if($status -ceq 'SAMPLED_CLEAN_CACHE_READ_ONLY'){
            if($failed -or $matrixLines.Count-ne 2 -or $matrixLines[0] -notmatch 'Values=1\.25,'){throw 'Projection successful rendering/culture mismatch'}
            if(($matrixLines[0].Split('=')[1].Split(',')).Count-ne 16){throw 'Projection sequence length mismatch'}
        }elseif(!$failed -or $matrixLines.Count-ne 0){throw 'Unready projection leaked values'}
        if(@($script:lines|Where-Object {$_ -like 'CameraProjectionLimits *MatrixConvention=UNVERIFIED*FrameSynchronization=UNVERIFIED*'}).Count-ne 1){throw 'Projection limits missing'}
        "PASS: projection renderer status=$status"
    }
    $identity=[pscustomobject]@{Status='NOT_READY_SOURCE_CHANGED';Projection=$null};$failed=$false;$script:lines.Clear();. ([scriptblock]::Create($block))
    if(!$failed -or @($script:lines|Where-Object {$_ -like '*NativeSequence*'}).Count-ne 0 -or @($script:lines|Where-Object {$_ -like '*Values=WITHHELD'}).Count-ne 1){throw 'Missing projection must withhold data'}
    'PASS: projection renderer missing result suppresses values'
}finally{[Threading.Thread]::CurrentThread.CurrentCulture=$original}
