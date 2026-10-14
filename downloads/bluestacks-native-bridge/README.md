# BlueStacks native read-only bridge, experimental build 0.1

This package implements a native debugger plug-in for the exact uploaded
`BstkVMM.dll` build 6.1.36.156792. It uses the debugger's `LoadPlugIn` interface to
receive the live VM context, registers a `headbridge` info handler, and reads
through native `DBGFR3AddrFromPhys` / `DBGFR3MemRead` exports. The COM
`readPhysicalMemory` and `readVirtualMemory` stubs are not called.

**Windows/BlueStacks execution is pending. This is not a completed Free Fire
aim-lock DLL.** It has no player/head/visibility mappings or aim-control writes.
A successful probe establishes one native guest physical read only.

## Run the probe

Extract the complete archive into a new folder. Keep the Pie64 BlueStacks instance
open and running until the probe finishes. In 64-bit Administrator PowerShell:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-BridgeProbe.ps1
```

The runner verifies the DLL against `manifest.json`, verifies the actual loaded
VMM file against the inspected SHA-256, attaches to the existing VM with its
verified Shared lock value, loads this plug-in, asks it to read one byte at guest
physical address zero, then unloads it and releases the shared session. The byte's
contents are omitted. Output is also saved in `bridge-result-<id>.txt`.

Expected successful stages include:

```text
Preflight=PASS ...
PluginLoad=PASS Name=HeadAimBridge
BridgeStatus=READY Protocol=1 ReadOnly=1 MaximumRead=4096
BridgeProbe=PASS BytesRead=1 Contents=OMITTED
PluginUnload=PASS
HandlerCleanup=PASS
SharedSession=RELEASED
```

The supported loader may reject the plug-in; its exact error is reported. The
runner does not change loading policy. Exit code 1 means a stage failed. The
native code is experimental and runs inside HD-Player; live stability and
concurrent shutdown behavior have not been tested.

## Implemented interface

While loaded, `Info("headbridge", command)` accepts:

- `status`: reports protocol 1 and the 4096-byte read limit.
- `probe`: reads one physical byte at zero and reports only status.
- `readphys ADDRESS COUNT`: reads 1–4096 bytes and returns hexadecimal text.
  Addresses and counts may be decimal or `0x` hexadecimal. Malformed requests,
  overflow, zero length, and oversized requests are rejected before the reader
  is called. Negative and nonzero native statuses never report successful data.

The supplied runner uses only `status` and `probe`. Physical addresses are not
Android application virtual addresses. Process address translation, Free Fire
objects, and aim updates require further implementation and validation.

The plug-in holds a borrowed UVM only while registered, does not dereference VM
internals or the vtable, and uses the native debugger read API's execution-thread
dispatch. The runner serializes its calls and unloads after the read returns.
If deregistration fails, the DLL pins itself to keep callback code alive; the
runner's handler-cleanup check reports that failure. Only one VM per loaded
plug-in module is supported in this first build.

## Validation

- Native simulated-host tests passed for lifecycle, failure propagation,
  bounded reads, integer overflow, and omission of probe contents.
- The same tests passed with AddressSanitizer and UndefinedBehaviorSanitizer.
- Windows x64 DLL cross-compiled with warnings treated as errors.
- PE inspection confirms `DbgPlugInEntry` and dependencies on ADVAPI32,
  KERNEL32, and msvcrt only.
- The target ABI was checked against the uploaded DLL's disassembly; see
  `ABI-EVIDENCE.md`. These checks do not replace a Windows runtime test.

Rebuild on Linux with C++17 and a MinGW x64 compiler:

```sh
MINGW_CXX=/path/to/x86_64-w64-mingw32-g++-posix bash build.sh
```

The build regenerates the DLL digest in the manifest. No BlueStacks or Oracle
binaries are redistributed in this package.
