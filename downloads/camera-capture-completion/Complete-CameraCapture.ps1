[CmdletBinding(DefaultParameterSetName='Seeded')]
param(
    [Parameter(Mandatory=$true)][string]$SourceDirectory,
    [Parameter(Mandatory=$true,ParameterSetName='Seeded')][string]$SeedFile,
    [Parameter(Mandatory=$true,ParameterSetName='Fresh')][switch]$Fresh,
    [string]$JournalPath,
    [Parameter(ParameterSetName='Seeded')][switch]$ReviewOnly,
    [Parameter(ParameterSetName='Seeded')][string[]]$AdditionalReportNames
)
Set-StrictMode -Version 2
$ErrorActionPreference='Stop'
$source=(Resolve-Path -LiteralPath $SourceDirectory).Path
$pins=@{
    'manifest.json'='03a3d4fc4b719d1481f67a5eaea901e34db5f1a87ebd710ce160e01c171b854a'
    'AimBasisCheck.ps1'='1ec0e989feac0df2d16e72e8a363e62499729b254c6a0acd650dffc0c884e10f'
    'CameraPoseCheck.ps1'='af12695d77057bfe3a3c277a3763c2753248c002e7a0e75c69c71ac2f6764781'
    'Run-ProcessMap.ps1'='948319e26293182f13cec030c776cb79180488057480692834c6efd1f47778d5'
}
foreach($name in $pins.Keys){if((Get-FileHash -LiteralPath (Join-Path $source $name) -Algorithm SHA256).Hash -ine $pins[$name]){throw "Pinned V52 source mismatch: $name"}}
. (Join-Path $source 'AimBasisCheck.ps1')
. (Join-Path $source 'CameraPoseCheck.ps1')
if(!$Fresh){
    $seedInfo=Get-Item -LiteralPath $SeedFile
    if($seedInfo.PSIsContainer -or $seedInfo.Length -gt 65536){throw 'Seed size/type invalid.'}
    $seed=Get-Content -LiteralPath $SeedFile -Raw | ConvertFrom-Json
    if($seed.Schema -ne 1 -or @($seed.ReportNames).Count -ne 6){throw 'Exactly six ordered seed reports required.'}
}
if($ReviewOnly -and $AdditionalReportNames){throw 'ReviewOnly cannot add captures.'}
if($AdditionalReportNames -and @($AdditionalReportNames).Count -ne 2){throw 'Exactly two additional reports required in offline completion mode.'}
if(!$JournalPath){$JournalPath=Join-Path $source ('camera-completion-'+[guid]::NewGuid().ToString('N')+'.json')}
if(Test-Path -LiteralPath $JournalPath){throw 'Journal already exists; use a new path to preserve prior evidence.'}
$script:completionSamples=@();$script:completionRecords=@();$script:completionSeen=@();$script:completionAttempts=@()
function Save-Completion {
    param([string]$Status,[object]$Comparison=$null)
    $record=[pscustomobject]@{Schema=1;Status=$Status;Mode=$(if($Fresh){'FRESH_NO_IMPORT'}else{'SIX_SAVED_REPORTS'});Scope='SAVED_REPORT_CORRELATION_ONLY';Accepted=$script:completionSamples.Count;
        Reports=$script:completionRecords;Attempts=$script:completionAttempts;Comparison=$Comparison;
        ActualGameCamera='UNVERIFIED';ShotDirection='UNVERIFIED';LineOfSight='UNVERIFIED';AimWrites='NONE';LiveBindingReady=$false}
    # Publish a complete document via a sibling temporary file.
    $temporary=$JournalPath+'.'+[guid]::NewGuid().ToString('N')+'.tmp'
    try{$record|ConvertTo-Json -Depth 14|Set-Content -LiteralPath $temporary -Encoding UTF8;Move-Item -LiteralPath $temporary -Destination $JournalPath -Force}
    finally{if(Test-Path -LiteralPath $temporary){Remove-Item -LiteralPath $temporary}}
}
function Test-UnavailablePoseReport {
    param([string]$Path)
    $file=Get-Item -LiteralPath $Path
    if($file.PSIsContainer -or $file.Length -gt 2097152){throw 'Report size/type invalid.'}
    $lines=@(Get-Content -LiteralPath $Path)
    foreach($pattern in @(
        '^AimStateSamples AdditionalPhysicalReads=0 Attempted=0 Sampled=0 StopReason=PREREQUISITES_UNVERIFIED Detail=$',
        '^MatchPlayerDictionary=NOT_READY_COLLECTION_CHANGED ',
        '^PluginUnload=PASS$','^HandlerCleanup=PASS$','^SharedSession=RELEASED$')){
        if(@($lines|Where-Object {$_ -match $pattern}).Count -ne 1){return $false}
    }
    # This result permits a bounded manual retry only; it never accepts a sample.
    return $true
}
function Add-CompletionReport {
    param([string]$Name,[int]$Stage,[string]$CaptureStart,[string]$CaptureEnd)
    if($Name -notmatch '^process-map-result-[0-9a-f]{32}\.txt$' -or $script:completionSeen -contains $Name){throw 'Invalid or repeated report basename.'}
    $path=Join-Path $source $Name;$file=Get-Item -LiteralPath $path
    if($file.PSIsContainer -or $file.Length -gt 2097152){throw 'Report size/type invalid.'}
    if($CaptureStart -and $file.LastWriteTimeUtc -lt ([datetime]::Parse($CaptureStart)).ToUniversalTime().AddSeconds(-2)){throw 'New capture result is stale.'}
    $before=(Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant()
    $sample=ConvertFrom-CameraPoseReport @([IO.File]::ReadAllLines($path))
    if($sample.Version -ne 52){throw 'Only pinned V52 reports are accepted.'}
    if((Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash -ine $before){throw 'Report changed during parsing.'}
    if($script:completionSamples.Count){foreach($key in @('Version','Machine','HostPid','Device','GuestPid','BuildId','LoadBias','Player','Match','CurrentGame','NativeCamera','NativeOwner','NativeTransform','UnityLoadBias')){
        if([string]$script:completionSamples[0].$key -cne [string]$sample.$key){throw "Capture context changed: $key. Restart the full experiment."}
    }}
    $script:completionSamples+=@($sample);$script:completionSeen+=@($Name)
    $script:completionRecords+=@([pscustomobject]@{Stage=$Stage;Name=$Name;SHA256=$before;LastWriteUtc=$file.LastWriteTimeUtc.ToString('o');
        CaptureStartUtc=$CaptureStart;CaptureEndUtc=$CaptureEnd;TimingScope=$(if($CaptureStart){'HOST_WALL_CLOCK_INTERVAL_NOT_MONOTONIC_SYNC'}else{'IMPORTED_REPORT_CAPTURE_INTERVAL_UNKNOWN'})})
}
try {
    if($Fresh){
        Save-Completion 'INCOMPLETE_FRESH_START'
        Write-Host "FreshCapture=STARTED ImportedReports=0 Journal=$JournalPath"
    }else{
        foreach($name in @($seed.ReportNames)){Add-CompletionReport $name ($script:completionSamples.Count+1) $null $null}
        Save-Completion 'INCOMPLETE_SIX_VALIDATED'
        Write-Host "SeedReports=VALIDATED Count=6 Journal=$JournalPath"
    }
    if($ReviewOnly){return}
    if($AdditionalReportNames){
        foreach($name in $AdditionalReportNames){Add-CompletionReport $name ($script:completionSamples.Count+1) $null $null;Save-Completion 'INCOMPLETE'}
    }else{
        $instructions=@(
            'BASELINE: fixed landmark at screen centre, camera roughly level; remember centre/height',
            'RIGHT: turn camera right; landmark moves LEFT',
            'RESTORE: same landmark to stage-1 centre/height',
            'LEFT: turn camera left; landmark moves RIGHT',
            'BASELINE: same landmark back to original centre/height; remember this pitch baseline',
            'UP: tilt camera up; landmark moves DOWN; keep horizontal heading',
            'RESTORE: same landmark to stage-5 centre/height; keep character position',
            'DOWN: tilt camera down; landmark moves UP; keep horizontal heading'
        )
        foreach($stage in ($script:completionSamples.Count+1)..8){
            $accepted=$false
            for($attempt=1;$attempt -le 2;$attempt++){
                $instruction=$instructions[$stage-1]
                $answer=Read-Host "Stage $stage attempt $attempt/2: $instruction. Same Training session; no character movement/fire/ADS. Stop camera, then READY"
                if($answer.Trim() -cne 'READY'){throw 'Capture cancelled.'}
                $start=[DateTime]::UtcNow.ToString('o')
                $output=@(& powershell.exe -NoProfile -ExecutionPolicy Bypass -File (Join-Path $source 'Run-ProcessMap.ps1') -ProbeAimState)
                $code=$LASTEXITCODE;$end=[DateTime]::UtcNow.ToString('o');$output|ForEach-Object {Write-Host $_}
                $script:completionAttempts+=@([pscustomobject]@{Stage=$stage;Attempt=$attempt;StartUtc=$start;EndUtc=$end;ExitCode=$code})
                Save-Completion 'INCOMPLETE_ATTEMPT_RECORDED'
                if($code -ne 0){Write-Host 'Capture rejected; no sample accepted. Existing validations remain unchanged.';continue}
                $paths=@($output|Where-Object {$_ -match '^ResultFile='})
                if($paths.Count -ne 1){throw 'Expected exactly one ResultFile.'}
                $path=[IO.Path]::GetFullPath(([string]$paths[0]).Substring(11))
                if([IO.Path]::GetDirectoryName($path) -cne $source){throw 'Unexpected result directory.'}
                if([IO.Path]::GetFileName($path) -notmatch '^process-map-result-[0-9a-f]{32}\.txt$'){throw 'Invalid result basename.'}
                if((Get-Item -LiteralPath $path).LastWriteTimeUtc -lt ([datetime]::Parse($start)).ToUniversalTime().AddSeconds(-2)){throw 'New capture result is stale.'}
                if(Test-UnavailablePoseReport $path){
                    $script:completionAttempts[-1]|Add-Member -NotePropertyName Rejection -NotePropertyValue 'NO_CAMERA_SAMPLE_COLLECTION_CHANGED'
                    $script:completionAttempts[-1]|Add-Member -NotePropertyName ResultName -NotePropertyValue ([IO.Path]::GetFileName($path))
                    $script:completionAttempts[-1]|Add-Member -NotePropertyName SHA256 -NotePropertyValue ((Get-FileHash -LiteralPath $path -Algorithm SHA256).Hash.ToLowerInvariant())
                    Save-Completion 'INCOMPLETE_NO_CAMERA_SAMPLE'
                    Write-Host 'Roster changed: zero camera samples. Nothing accepted; hold the same pose for the next manual attempt.'
                    continue
                }
                Add-CompletionReport ([IO.Path]::GetFileName($path)) $stage $start $end
                Save-Completion 'INCOMPLETE';$accepted=$true;break
            }
            if(!$accepted){throw "Stage $stage remains rejected after two manually requested attempts. Journal preserved."}
        }
    }
    if($script:completionSamples.Count -ne 8){throw 'Eight valid captures required.'}
    $comparison=Compare-CameraPoseSamples $script:completionSamples
    Save-Completion $comparison.Status $comparison
    Write-Host "CameraPoseComparison=$($comparison.Status) Scope=MANUAL_CORRELATION_ONLY"
    Write-Host "ComparisonResultFile=$JournalPath"
} catch {
    Save-Completion ('INCOMPLETE_REJECTED: '+$_.Exception.Message)
    Write-Host "PartialJournal=$JournalPath"
    throw
}
