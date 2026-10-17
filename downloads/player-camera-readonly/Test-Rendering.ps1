$ErrorActionPreference='Stop'
Set-StrictMode -Version 2
$source=Get-Content -LiteralPath (Join-Path $PSScriptRoot 'Run-PlayerCamera.ps1') -Raw
$start=$source.IndexOf('    Record "PlayerCameraPose Status=')
$end=$source.IndexOf('} catch { $failed = $true; Failure',$start)
if($start -lt 0 -or $end -le $start){throw 'Authored renderer markers changed'}
# Execute only this package's actual rendering block, never the SDK preflight.
$render=[scriptblock]::Create($source.Substring($start,$end-$start))
$script:lines=[Collections.Generic.List[string]]::new()
function Record([string]$line){$script:lines.Add($line)}
$captureTimer=[pscustomobject]@{ElapsedMilliseconds=5};$started='start';$finished='end';$failed=$false
$originalCulture=[Threading.Thread]::CurrentThread.CurrentCulture
try{
    [Threading.Thread]::CurrentThread.CurrentCulture=[Globalization.CultureInfo]::GetCultureInfo('fr-FR')
    foreach($status in @('SAMPLED_READ_ONLY','NOT_READY_JOB_PENDING')){
        $pose=[pscustomobject]@{Status=$status;Attempts=1;AdditionalReads=123;ManagedTransform=[uint64]0x10000;NativeTransform=[uint64]0x20000;UnityLoadBias=[uint64]0x30000;ParentCount=0;Observations=12;Position=$null;Rotation=$null;Detail='pending'}
        if($status -eq 'SAMPLED_READ_ONLY'){$pose.Position=@([double]1.25,[double]2,[double]3);$pose.Rotation=@([double]0,[double]0,[double]0,[double]1)}
        $script:lines.Clear();. $render
        if($status -eq 'SAMPLED_READ_ONLY'){
            if(@($script:lines|Where-Object {$_ -like 'PlayerCameraWorldPosition X=1.25 *'}).Count -ne 1){throw 'Invariant sampled renderer failed'}
        }else{
            if(@($script:lines|Where-Object {$_ -like 'PlayerCameraWorldPosition*'}).Count -ne 0 -or !$failed){throw 'Unready renderer leaked pose'}
        }
        if(@($script:lines|Where-Object {$_ -like 'CameraSemantics ActualRenderedCamera=UNVERIFIED*'}).Count -ne 1){throw 'Missing unknown semantics'}
    }
}finally{[Threading.Thread]::CurrentThread.CurrentCulture=$originalCulture}
Write-Output 'PlayerCameraRenderer=PASS Cases=2 Culture=fr-FR ActualCamera=UNVERIFIED'
