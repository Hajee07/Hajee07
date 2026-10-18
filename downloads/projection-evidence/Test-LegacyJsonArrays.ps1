$ErrorActionPreference='Stop'
$rows=@([pscustomobject]@{Name='evidence.json';SHA256=('a'*64)},[pscustomobject]@{Name='view-before.png';SHA256=('b'*64)})
$json=$rows|ConvertTo-Json
$legacy=@($json|Microsoft.PowerShell.Utility\ConvertFrom-Json -NoEnumerate)
$oldHits=@($legacy|Where-Object {$_.Name-ceq 'evidence.json'})
if($oldHits.Count-ne 1-or $oldHits[0].SHA256-isnot [array]){throw 'Legacy root-array failure not reproduced'}
'PASS: legacy JSON root-array nesting reproduces misleading integrity comparison'
function ConvertFrom-Json {
 [CmdletBinding()]
 param([Parameter(ValueFromPipeline=$true)][string]$InputObject)
 process{Microsoft.PowerShell.Utility\ConvertFrom-Json -InputObject $InputObject -NoEnumerate}
}
try{
 & (Join-Path $PSScriptRoot 'Test-Recovery.ps1')
 'PASS: full saved recovery and tamper rejection under emulated Windows PowerShell 5 JSON array semantics'
}finally{Remove-Item Function:\ConvertFrom-Json}
