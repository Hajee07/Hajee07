[CmdletBinding()]
param([string]$MappingSourceDirectory)
$ErrorActionPreference='Stop'
$manifest=Join-Path $PSScriptRoot 'source-package-manifest.json'
if(Test-Path -LiteralPath $manifest){
    $catalog=Get-Content -LiteralPath $manifest -Raw | ConvertFrom-Json
    foreach($entry in $catalog.files){
        $path=Join-Path (Join-Path $PSScriptRoot '..') $entry.name
        $file=Get-Item -LiteralPath $path
        if($file.Length -ne $entry.bytes -or (Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash -ine $entry.sha256){throw "Source integrity mismatch: $($entry.name)"}
    }
}
$base=Join-Path $PSScriptRoot '..\targeting-offline'
$names=@('Targeting.cs','MeshLineOfSight.cs','AdvancedController.cs','AimCoordinator.cs')
$files=@($names | ForEach-Object {Join-Path $base $_})
$files+=@('ObservationPipeline.cs','ExpiringCommandLease.cs','ReviewTests.cs' | ForEach-Object {Join-Path $PSScriptRoot $_})
if($MappingSourceDirectory){$files+=@(Get-ChildItem -LiteralPath $MappingSourceDirectory -Filter "*.cs" | Where-Object Name -NotLike "*Tests.cs" | Select-Object -ExpandProperty FullName)}
Add-Type -Path $files -CompilerOptions @('/langversion:5','/warnaserror+')
[HeadBridge.IntegrationReview.ReviewTests]::Run()
