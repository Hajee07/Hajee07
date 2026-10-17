[CmdletBinding()]
param([ValidateSet('server','client','test','environment')][string]$Mode='test',
      [ValidateSet('geometric','convert')][string]$Policy='geometric',
      [ValidateRange(1024,65535)][int]$Port=5088,[switch]$Wall)
$ErrorActionPreference='Stop'
$project=Join-Path $PSScriptRoot 'HitLab.csproj'
& dotnet build $project -c Release --nologo
if($LASTEXITCODE-ne 0){throw 'Build failed; .NET 8 SDK required'}
$arguments=@('run','--project',$project,'-c','Release','--no-build','--',$Mode)
if($Mode-eq 'server'){$arguments+=@('--policy',$Policy,'--port',"$Port");if($Wall){$arguments+='--wall'}}
if($Mode-eq 'client'){$arguments+=@('--url',"http://127.0.0.1:$Port/",'--report',(Join-Path $PSScriptRoot 'experiment.json'))}
& dotnet @arguments
if($LASTEXITCODE-ne 0){throw 'Lab command failed; see output above'}
