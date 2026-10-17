$ErrorActionPreference = 'Stop'
foreach ($name in @('Run-PlayerCamera.ps1','Run-Checks.ps1')) {
    $source = Get-Content -Raw (Join-Path $PSScriptRoot $name)
    $block = [regex]::Match($source, '(?s)# BEGIN COMPATIBLE COMPILE(.*?)# END COMPATIBLE COMPILE').Groups[1].Value
    if (!$block) { throw 'Compile block missing' }
    foreach ($supported in @($false,$true)) {
        & {
            if ($supported) {
                function Add-Type { [CmdletBinding()] param([string[]]$Path,[string[]]$CompilerOptions) $script:captured=$PSBoundParameters }
            } else {
                function Add-Type { [CmdletBinding()] param([string[]]$Path) $script:captured=$PSBoundParameters }
            }
            foreach ($match in [regex]::Matches($block,'\$(\w+Path)\b')) { Set-Variable $match.Groups[1].Value 'fixture.cs' }
            $files=@('one.cs','two.cs')
            $fixtureRoot = $PSScriptRoot
            & ([scriptblock]::Create($block.Replace('$PSScriptRoot', '$fixtureRoot')))
            $expectedCount = if ($name -eq 'Run-Checks.ps1') { 2 } else { 33 }
            if ($captured.Path.Count -ne $expectedCount) { throw "Source count changed: $($captured.Path.Count)" }
            if ($captured.ContainsKey('CompilerOptions') -ne $supported) { throw 'Compiler option selection failed' }
            if ($supported -and $captured.CompilerOptions[0] -ne '/langversion:5') { throw 'Language option missing' }
            "PASS: $name CompilerOptionsSupported=$supported Sources=$expectedCount"
        }
    }
}
