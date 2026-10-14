# Read the installed COM type library; optionally test one guest physical byte.
# Requires 64-bit Windows PowerShell. No settings, game memory, or aim writes.
[CmdletBinding()]
param(
    [string] $MachineName = 'Pie64',
    [switch] $ProbeRead
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

# Avoid activating a separately installed Oracle VirtualBox client.
$classId = (Get-Item -LiteralPath 'Registry::HKEY_CLASSES_ROOT\VirtualBox.VirtualBoxClient\CLSID').GetValue('')
$server = [Environment]::ExpandEnvironmentVariables([string](Get-Item -LiteralPath "Registry::HKEY_CLASSES_ROOT\CLSID\$classId\InprocServer32").GetValue(''))
if ([IO.Path]::GetFileName($server.Trim().Trim('"')) -ine 'BstkC.dll') {
    throw 'Registered COM client is not BstkC.dll; stopping.'
}

if ($null -eq ('BlueStacksSdkTypeLibraryV1' -as [type])) {
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
using TYPEKIND = System.Runtime.InteropServices.ComTypes.TYPEKIND;
using VARKIND = System.Runtime.InteropServices.ComTypes.VARKIND;

[ComImport, Guid("00020400-0000-0000-C000-000000000046")]
[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
public interface IBlueStacksDispatchTypeInfoV1
{
    [PreserveSig] int GetTypeInfoCount(out uint count);
    [PreserveSig] int GetTypeInfo(uint index, uint lcid, out ITypeInfo info);
}

public sealed class BlueStacksSdkEnumV1
{
    public string EnumName { get; set; }
    public string Name { get; set; }
    public long Value { get; set; }
}

public static class BlueStacksSdkTypeLibraryV1
{
    public static BlueStacksSdkEnumV1[] Read(object instance)
    {
        ITypeInfo root = null;
        ITypeLib library = null;
        var rows = new List<BlueStacksSdkEnumV1>();
        try
        {
            var dispatch = (IBlueStacksDispatchTypeInfoV1)instance;
            uint count;
            Marshal.ThrowExceptionForHR(dispatch.GetTypeInfoCount(out count));
            if (count == 0) throw new InvalidOperationException("COM type information is unavailable.");
            Marshal.ThrowExceptionForHR(dispatch.GetTypeInfo(0, 0, out root));
            int containingIndex;
            root.GetContainingTypeLib(out library, out containingIndex);

            for (int i = 0; i < library.GetTypeInfoCount(); ++i)
            {
                TYPEKIND kind;
                library.GetTypeInfoType(i, out kind);
                if (kind != TYPEKIND.TKIND_ENUM) continue;
                string name, documentation, helpFile;
                int helpContext;
                library.GetDocumentation(i, out name, out documentation, out helpContext, out helpFile);
                if (name != "MachineState" && name != "SessionState" && name != "LockType") continue;

                ITypeInfo info = null;
                IntPtr attributes = IntPtr.Zero;
                try
                {
                    library.GetTypeInfo(i, out info);
                    info.GetTypeAttr(out attributes);
                    var type = (System.Runtime.InteropServices.ComTypes.TYPEATTR)Marshal.PtrToStructure(
                        attributes, typeof(System.Runtime.InteropServices.ComTypes.TYPEATTR));
                    for (int j = 0; j < type.cVars; ++j)
                    {
                        IntPtr variable = IntPtr.Zero;
                        try
                        {
                            info.GetVarDesc(j, out variable);
                            var descriptor = (System.Runtime.InteropServices.ComTypes.VARDESC)Marshal.PtrToStructure(
                                variable, typeof(System.Runtime.InteropServices.ComTypes.VARDESC));
                            if (descriptor.varkind != VARKIND.VAR_CONST) continue;
                            string constant;
                            info.GetDocumentation(descriptor.memid, out constant, out documentation, out helpContext, out helpFile);
                            rows.Add(new BlueStacksSdkEnumV1 {
                                EnumName = name,
                                Name = constant,
                                Value = Convert.ToInt64(Marshal.GetObjectForNativeVariant(descriptor.desc.lpvarValue))
                            });
                        }
                        finally { if (variable != IntPtr.Zero) info.ReleaseVarDesc(variable); }
                    }
                }
                finally
                {
                    if (attributes != IntPtr.Zero) info.ReleaseTypeAttr(attributes);
                    if (info != null) Marshal.ReleaseComObject(info);
                }
            }
            return rows.ToArray();
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
$constants = @([BlueStacksSdkTypeLibraryV1]::Read($box))
if ($constants.Count -eq 0) { throw 'Expected enums were not found in the installed type library.' }
$constants | Format-Table EnumName, Name, Value -AutoSize

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

if (-not $ProbeRead) { return }

$shared = @($constants | Where-Object {
    $_.EnumName -eq 'LockType' -and $_.Name -match '(^|_)Shared$'
})
if ($shared.Count -ne 1) { throw 'Could not establish the installed Shared lock value; stopping.' }
$hostProcess = Get-Process -Id ([int]$machine.SessionPID) -ErrorAction Stop
if ($hostProcess.ProcessName -ine 'HD-Player') {
    throw 'The selected VM session does not belong to HD-Player; stopping.'
}

$session = New-Object -ComObject 'VirtualBox.Session'
$locked = $false
try {
    # Attach to the existing session; never launch, pause, resume, or reconfigure.
    $machine.LockMachine($session, [int]$shared[0].Value)
    $locked = $true
    $debugger = $session.Console.Debugger
    if ($null -eq $debugger) { throw 'Console debugger object is unavailable.' }
    Write-Output 'DebuggerObject=AVAILABLE'
    try {
        # Physical address 0 is a capability probe, not a Free Fire address.
        $bytes = @($debugger.ReadPhysicalMemory([long]0, [uint32]1))
        if ($bytes.Count -ne 1 -or $bytes[0] -isnot [byte]) {
            throw 'The API did not return exactly one byte.'
        }
        Write-Output 'PhysicalReadProbe=PASS (one byte returned; contents omitted)'
    } catch {
        Write-DiagnosticError -Stage 'PhysicalReadProbe' -Exception $_.Exception
    }
} catch {
    Write-DiagnosticError -Stage 'DebuggerAttach' -Exception $_.Exception
} finally {
    if ($locked) {
        try {
            $session.UnlockMachine()
            Write-Output 'SharedSession=RELEASED'
        } catch {
            Write-DiagnosticError -Stage 'SharedSessionRelease' -Exception $_.Exception
        }
    }
}
