# Read the installed COM type library and opt-in guest read/info API checks.
# Requires 64-bit Windows PowerShell. No settings, game memory, or aim writes.
[CmdletBinding()]
param(
    [string] $MachineName = 'Pie64',
    [switch] $ProbeRead,
    [switch] $ProbeVirtual,
    [switch] $ListInfo
)

Set-StrictMode -Version 2.0
$ErrorActionPreference = 'Stop'

function Write-DiagnosticError {
    param([string] $Stage, [System.Exception] $Exception)
    while ($null -ne $Exception.InnerException) {
        $Exception = $Exception.InnerException
    }
    Write-Output "$Stage=FAIL HRESULT=0x$($Exception.HResult.ToString('X8')) $($Exception.Message)"
}

if ([Environment]::OSVersion.Platform -ne [PlatformID]::Win32NT -or
    -not [Environment]::Is64BitProcess) {
    throw 'Use 64-bit Windows PowerShell on the BlueStacks PC.'
}
Write-Output 'DiagnosticVersion=3'

# Avoid activating a separately installed Oracle VirtualBox client.
$classId = (Get-Item -LiteralPath 'Registry::HKEY_CLASSES_ROOT\VirtualBox.VirtualBoxClient\CLSID').GetValue('')
$server = [Environment]::ExpandEnvironmentVariables([string](Get-Item -LiteralPath "Registry::HKEY_CLASSES_ROOT\CLSID\$classId\InprocServer32").GetValue(''))
if ([IO.Path]::GetFileName($server.Trim().Trim('"')) -ine 'BstkC.dll') {
    throw 'Registered COM client is not BstkC.dll; stopping.'
}

if ($null -eq ('BlueStacksSdkTypeLibraryV2' -as [type])) {
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using TYPEKIND = System.Runtime.InteropServices.ComTypes.TYPEKIND;
using VARKIND = System.Runtime.InteropServices.ComTypes.VARKIND;

[ComImport, Guid("00020400-0000-0000-C000-000000000046")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IBlueStacksDispatchTypeInfoV2
{
    [PreserveSig] int GetTypeInfoCount(out uint count);
    [PreserveSig] int GetTypeInfo(uint index, uint lcid, out ITypeInfo info);
}

public sealed class BlueStacksSdkEnumV2
{
    public string EnumName { get; set; }
    public string Name { get; set; }
    public long Value { get; set; }
}

public sealed class BlueStacksSdkTypeV2
{
    public string Name { get; set; }
    public string Kind { get; set; }
}

public sealed class BlueStacksSdkReportV2
{
    public string LibraryName { get; set; }
    public string LibraryGuid { get; set; }
    public string LibraryVersion { get; set; }
    public BlueStacksSdkTypeV2[] Types { get; set; }
    public BlueStacksSdkEnumV2[] Constants { get; set; }
}

public static class BlueStacksSdkTypeLibraryV2
{
    private static void ReadEnum(ITypeInfo info, string sourceName,
        List<BlueStacksSdkEnumV2> rows, int depth)
    {
        if (depth > 8) throw new InvalidOperationException("Type alias nesting exceeded eight levels.");
        IntPtr attributes = IntPtr.Zero;
        ITypeInfo referenced = null;
        try
        {
            info.GetTypeAttr(out attributes);
            var type = (System.Runtime.InteropServices.ComTypes.TYPEATTR)Marshal.PtrToStructure(
                attributes, typeof(System.Runtime.InteropServices.ComTypes.TYPEATTR));
            if (type.typekind == TYPEKIND.TKIND_ALIAS)
            {
                if (type.tdescAlias.vt == (short)VarEnum.VT_USERDEFINED)
                {
                    info.GetRefTypeInfo(unchecked((int)type.tdescAlias.lpValue.ToInt64()), out referenced);
                    ReadEnum(referenced, sourceName, rows, depth + 1);
                }
                return;
            }
            if (type.typekind != TYPEKIND.TKIND_ENUM) return;
            for (int j = 0; j < type.cVars; ++j)
            {
                IntPtr variable = IntPtr.Zero;
                try
                {
                    info.GetVarDesc(j, out variable);
                    var descriptor = (System.Runtime.InteropServices.ComTypes.VARDESC)Marshal.PtrToStructure(
                        variable, typeof(System.Runtime.InteropServices.ComTypes.VARDESC));
                    if (descriptor.varkind != VARKIND.VAR_CONST) continue;
                    string constant, documentation, helpFile;
                    int helpContext;
                    info.GetDocumentation(descriptor.memid, out constant, out documentation, out helpContext, out helpFile);
                    rows.Add(new BlueStacksSdkEnumV2 {
                        EnumName = sourceName,
                        Name = constant,
                        Value = Convert.ToInt64(Marshal.GetObjectForNativeVariant(descriptor.desc.lpvarValue))
                    });
                }
                finally { if (variable != IntPtr.Zero) info.ReleaseVarDesc(variable); }
            }
        }
        finally
        {
            if (referenced != null) Marshal.ReleaseComObject(referenced);
            if (attributes != IntPtr.Zero) info.ReleaseTypeAttr(attributes);
        }
    }

    public static BlueStacksSdkReportV2 Read(object instance)
    {
        ITypeInfo root = null;
        ITypeLib library = null;
        var rows = new List<BlueStacksSdkEnumV2>();
        var types = new List<BlueStacksSdkTypeV2>();
        var report = new BlueStacksSdkReportV2();
        try
        {
            var dispatch = (IBlueStacksDispatchTypeInfoV2)instance;
            uint count;
            Marshal.ThrowExceptionForHR(dispatch.GetTypeInfoCount(out count));
            if (count == 0) throw new InvalidOperationException("COM type information is unavailable.");
            Marshal.ThrowExceptionForHR(dispatch.GetTypeInfo(0, 0, out root));
            int containingIndex;
            root.GetContainingTypeLib(out library, out containingIndex);

            string libraryName, libraryDocumentation, libraryHelpFile;
            int libraryHelpContext;
            library.GetDocumentation(-1, out libraryName, out libraryDocumentation, out libraryHelpContext, out libraryHelpFile);
            report.LibraryName = libraryName;
            IntPtr libraryAttributes = IntPtr.Zero;
            try
            {
                library.GetLibAttr(out libraryAttributes);
                var attributes = (System.Runtime.InteropServices.ComTypes.TYPELIBATTR)Marshal.PtrToStructure(
                    libraryAttributes, typeof(System.Runtime.InteropServices.ComTypes.TYPELIBATTR));
                report.LibraryGuid = attributes.guid.ToString("B");
                report.LibraryVersion = attributes.wMajorVerNum + "." + attributes.wMinorVerNum;
            }
            finally { if (libraryAttributes != IntPtr.Zero) library.ReleaseTLibAttr(libraryAttributes); }

            for (int i = 0; i < library.GetTypeInfoCount(); ++i)
            {
                TYPEKIND kind;
                library.GetTypeInfoType(i, out kind);
                string name, documentation, helpFile;
                int helpContext;
                library.GetDocumentation(i, out name, out documentation, out helpContext, out helpFile);
                types.Add(new BlueStacksSdkTypeV2 { Name = name, Kind = kind.ToString() });
                if (kind != TYPEKIND.TKIND_ENUM && kind != TYPEKIND.TKIND_ALIAS) continue;

                ITypeInfo info = null;
                try
                {
                    library.GetTypeInfo(i, out info);
                    ReadEnum(info, name, rows, 0);
                }
                finally
                {
                    if (info != null) Marshal.ReleaseComObject(info);
                }
            }
            report.Types = types.ToArray();
            report.Constants = rows.ToArray();
            return report;
        }
        finally
        {
            if (library != null) Marshal.ReleaseComObject(library);
            if (root != null) Marshal.ReleaseComObject(root);
        }
    }
}
'@
}

$client = New-Object -ComObject 'VirtualBox.VirtualBoxClient'
$box = $client.VirtualBox
$report = [BlueStacksSdkTypeLibraryV2]::Read($box)
[pscustomobject]@{
    LibraryName    = $report.LibraryName
    LibraryGuid    = $report.LibraryGuid
    LibraryVersion = $report.LibraryVersion
    TypeCount      = $report.Types.Count
    ConstantCount  = $report.Constants.Count
} | Format-List

# MIDL can generate anonymous enum names and named aliases. Match the actual
# constant prefix, or the named enum/alias, without inventing numeric values.
$constants = @($report.Constants | ForEach-Object {
    $row = $_
    foreach ($group in @('MachineState', 'SessionState', 'LockType')) {
        if ($row.Name -match ('^' + $group + '_') -or
            $row.EnumName -match ('^_*' + $group + '(_T)?$')) {
            [pscustomobject]@{
                EnumName = $group
                SourceType = $row.EnumName
                Name = $row.Name
                Value = $row.Value
            }
        }
    }
} | Sort-Object EnumName, Name, Value -Unique)

if ($constants.Count -gt 0) {
    $constants | Format-Table EnumName, SourceType, Name, Value -AutoSize
} else {
    Write-Output 'EnumResolution=UNRESOLVED; actual type-library inventory follows.'
    $report.Types | Format-Table Name, Kind -AutoSize
    $report.Constants | Select-Object -First 30 | Format-Table EnumName, Name, Value -AutoSize
}

$machine = $box.FindMachine($MachineName)
$stateNames = @($constants | Where-Object {
    $_.EnumName -eq 'MachineState' -and $_.Value -eq [long]$machine.State
} | Select-Object -ExpandProperty Name)
[pscustomobject]@{
    Version    = $box.Version
    APIVersion = $box.APIVersion
    Machine    = $machine.Name
    StateValue = $machine.State
    StateNames = $stateNames -join ', '
    SessionPID = $machine.SessionPID
} | Format-List

if (-not $ProbeRead -and -not $ProbeVirtual -and -not $ListInfo) { return }

$shared = @($constants | Where-Object {
    $_.EnumName -eq 'LockType' -and $_.Name -match '(^|_)Shared$'
})
if ($shared.Count -ne 1) {
    Write-Output 'DebuggerChecks=SKIPPED (installed Shared lock value unresolved)'
    if ($constants.Count -gt 0) {
        $report.Types | Format-Table Name, Kind -AutoSize
    }
    exit 2
}
$hostProcess = Get-Process -Id ([int]$machine.SessionPID) -ErrorAction Stop
if ($hostProcess.ProcessName -ine 'HD-Player') {
    throw 'The selected VM session does not belong to HD-Player; stopping.'
}

$session = New-Object -ComObject 'VirtualBox.Session'
$locked = $false
$probeFailed = $false
try {
    # Attach to the existing session; never launch, pause, resume, or reconfigure.
    $machine.LockMachine($session, [int]($shared[0].Value))
    $locked = $true
    $debugger = $session.Console.Debugger
    if ($null -eq $debugger) { throw 'Console debugger object is unavailable.' }
    Write-Output 'DebuggerObject=AVAILABLE'
    if ($ProbeRead) {
        try {
            # Physical address 0 is a capability probe, not a Free Fire address.
            $bytes = @($debugger.ReadPhysicalMemory([long]0, [uint32]1))
            if ($bytes.Count -ne 1 -or $bytes[0] -isnot [byte]) {
                throw 'The API did not return exactly one byte.'
            }
            Write-Output 'PhysicalReadProbe=PASS (one byte returned; contents omitted)'
        } catch {
            $probeFailed = $true
            Write-DiagnosticError -Stage 'PhysicalReadProbe' -Exception $_.Exception
        }
    }
    if ($ProbeVirtual) {
        try {
            # CPU 0 / address 0 tests the declared method, not a game mapping.
            $bytes = @($debugger.ReadVirtualMemory([uint32]0, [long]0, [uint32]1))
            if ($bytes.Count -ne 1 -or $bytes[0] -isnot [byte]) {
                throw 'The API did not return exactly one byte.'
            }
            Write-Output 'VirtualReadProbe=PASS (one byte returned; contents omitted)'
        } catch {
            $probeFailed = $true
            Write-DiagnosticError -Stage 'VirtualReadProbe' -Exception $_.Exception
        }
    }
    if ($ListInfo) {
        try {
            # Upstream DBGF registers help to list handler names/descriptions.
            $items = [string]$debugger.Info('help', '')
            if ([string]::IsNullOrWhiteSpace($items)) {
                throw 'The debugger returned no info-handler list.'
            }
            Write-Output 'DebuggerInfoHelp=AVAILABLE'
            Write-Output $items
        } catch {
            $probeFailed = $true
            Write-DiagnosticError -Stage 'DebuggerInfoHelp' -Exception $_.Exception
        }
    }
} catch {
    $probeFailed = $true
    Write-DiagnosticError -Stage 'DebuggerAttach' -Exception $_.Exception
} finally {
    if ($locked) {
        try {
            $session.UnlockMachine()
            Write-Output 'SharedSession=RELEASED'
        } catch {
            $probeFailed = $true
            Write-DiagnosticError -Stage 'SharedSessionRelease' -Exception $_.Exception
        }
    }
}
if ($probeFailed) { exit 1 }
