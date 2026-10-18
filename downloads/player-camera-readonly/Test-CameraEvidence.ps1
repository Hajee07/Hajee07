$ErrorActionPreference='Stop'
. (Join-Path $PSScriptRoot 'Assess-CameraEvidence.ps1')
$directory=Join-Path ([IO.Path]::GetTempPath()) ('camera-evidence-test-'+[guid]::NewGuid())
[void](New-Item -ItemType Directory -Path $directory)
try {
    $template=@'
Preflight=PASS Machine=Pie64 HostPID=1 VmmDigest=MATCH
GameIdentity=PASS GuestPID=2 Name=fixture
LocalPlayerObjects=PASS CurrentGame=0x1 Match=0x2 Player=0x3 Class=fixture
PlayerCameraPose Status=SAMPLED_READ_ONLY Attempts=1 ManagedTransform=0x4 NativeTransform=0x5
PlayerCameraCapture StartUtc=2026-10-18T00:00:0{SECOND}.0000000Z EndUtc=2026-10-18T00:00:0{SECOND}.5000000Z DurationMs=500 TimingScope=METHOD_CALL_INTERVAL_ONLY_RENDER_SYNC_UNKNOWN
PlayerCameraWorldPosition X=0 Y=0 Z=0 Source=REGISTERED_PLAYER_MAIN_CAMERA_TRANSFORM
PlayerCameraWorldRotation X={X} Y={Y} Z={Z} W={W} Source=fixture
PluginUnload=PASS
HandlerCleanup=PASS
SharedSession=RELEASED
'@
    # Identity -> +30 yaw -> +30 yaw and +20 elevation, independently selected angles.
    $sy=[Math]::Sin([Math]::PI/12);$cy=[Math]::Cos([Math]::PI/12)
    $sp=[Math]::Sin([Math]::PI/18);$cp=[Math]::Cos([Math]::PI/18)
    $q=@(@(0,0,0,1),@(0,$sy,0,$cy),@((-$cy*$sp),($sy*$cp),($sy*$sp),($cy*$cp)))
    $paths=@()
    for($i=0;$i-lt 3;$i++){
        $text=$template.Replace('{SECOND}',[string]($i*2))
        for($j=0;$j-lt 4;$j++){$text=$text.Replace('{'+@('X','Y','Z','W')[$j]+'}',([double]$q[$i][$j]).ToString('R',[Globalization.CultureInfo]::InvariantCulture))}
        $path=Join-Path $directory "capture-$i.txt";$text|Set-Content -LiteralPath $path;$paths+=$path
    }
    $result=Get-CameraEvidenceAssessment $paths
    if([Math]::Abs($result.Changes[0].DeclaredBasisAzimuthDeltaDegrees-30)-gt 0.00001-or [Math]::Abs($result.Changes[1].DeclaredBasisElevationDeltaDegrees-20)-gt 0.00001){throw 'Independent angle oracle failed'}
    'PASS: known +30 azimuth and +20 elevation'
    if($result.ActualRenderedCamera-ne 'UNVERIFIED'-or $result.AimWrites-ne 'NONE'){throw 'Evidence promoted to authority'}
    'PASS: math evidence cannot assert rendering or writes'
    foreach($case in @('duplicate','chronology','nonfinite','identity')) {
        $bad=Get-Content -Raw $paths[2];$testPaths=@($paths)
        switch($case){
            duplicate {$testPaths[2]=$paths[1]}
            chronology {$bad=$bad.Replace('00:00:04.','00:00:00.')}
            nonfinite {$bad=$bad.Replace('WorldPosition X=0','WorldPosition X=NaN')}
            identity {$bad=$bad.Replace('Match=0x2','Match=0x9')}
        }
        if($case-ne 'duplicate'){$badPath=Join-Path $directory 'bad.txt';$bad|Set-Content $badPath;$testPaths[2]=$badPath}
        $rejected=$false;try{Get-CameraEvidenceAssessment $testPaths|Out-Null}catch{$rejected=$true}
        if(!$rejected){throw "Accepted $case"};"PASS: rejected $case"
    }
    $comparison=Join-Path $directory 'comparison.json'
    Compare-CameraCaptures $paths|ConvertTo-Json -Depth 8|Set-Content $comparison
    & (Join-Path $PSScriptRoot 'New-CameraEvidenceBundle.ps1') -ComparisonFile $comparison
    $bundle=@(Get-ChildItem -LiteralPath $directory -Directory -Filter 'camera-visual-evidence-*')
    if($bundle.Count-ne 1){throw 'Expected one bundle'}
    $assessment=Get-Content -Raw (Join-Path $bundle[0].FullName 'assessment.json')|ConvertFrom-Json
    if($assessment.VisualEvidenceStatus-ne 'MISSING'){throw 'Missing visuals promoted'}
    foreach($entry in @(Get-Content -Raw (Join-Path $bundle[0].FullName 'files.json')|ConvertFrom-Json)){
        if((Get-FileHash -LiteralPath (Join-Path $bundle[0].FullName $entry.Name) -Algorithm SHA256).Hash-cne $entry.SHA256){throw 'Bundle integrity failed'}
    }
    'PASS: actual bundle preserves hashed reports and missing visual status'
    $view=Join-Path $directory 'fixture.png'
    [IO.File]::WriteAllBytes($view,[byte[]]@(137,80,78,71,13,10,26,10))
    $rejected=$false;try{& (Join-Path $PSScriptRoot 'New-CameraEvidenceBundle.ps1') -ComparisonFile $comparison -InitialView $view}catch{$rejected=$true}
    if(!$rejected){throw 'Partial screenshots accepted'}
    'PASS: incomplete visual set rejected'
    & (Join-Path $PSScriptRoot 'New-CameraEvidenceBundle.ps1') -ComparisonFile $comparison -InitialView $view -RightView $view -UpView $view
    $provided=@(Get-ChildItem -LiteralPath $directory -Directory -Filter 'camera-visual-evidence-*'|ForEach-Object {Get-Content -Raw (Join-Path $_.FullName 'assessment.json')|ConvertFrom-Json}|Where-Object {$_.VisualEvidenceStatus-eq 'SUPPLIED_UNALIGNED_REQUIRES_REVIEW'})
    if($provided.Count-ne 1-or $provided[0].ActualRenderedCamera-ne 'UNVERIFIED'){throw 'Copied screenshots promoted to proof'}
    'PASS: supplied screenshot bytes remain unaligned and unverified'

} finally {Remove-Item -LiteralPath $directory -Recurse -Force}
