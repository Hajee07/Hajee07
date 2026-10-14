# BlueStacks native read-only bridge, experimental build 0.1

This package implements a native debugger plug-in for the exact uploaded
`BstkVMM.dll` build 6.1.36.156792. It uses the debugger's `LoadPlugIn` interface to
receive the live VM context, registers a `headbridge` info handler, and reads
through native `DBGFR3AddrFromPhys` / `DBGFR3MemRead` exports. The COM
`readPhysicalMemory` and `readVirtualMemory` stubs are not called.

**The user-reported Windows probe passed:** plug-in loading, one native physical
byte read, unloading, handler cleanup, and shared-session release. See
[runtime results](RUNTIME-RESULTS.md). Player/head/visibility mappings and
aim-control writes remain unimplemented; this is not a completed Free Fire
aim-lock DLL.

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
PluginLoad=PASS Name=VBoxDbgHeadAimBridge
BridgeStatus=READY Protocol=1 ReadOnly=1 MaximumRead=4096
BridgeProbe=PASS BytesRead=1 Contents=OMITTED
PluginUnload=PASS
HandlerCleanup=PASS
SharedSession=RELEASED
```

The supported loader may reject the plug-in; its exact error is reported. The
runner does not change loading policy. Exit code 1 means a stage failed. The
native code is experimental and runs inside HD-Player; repeated runs and
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
  `ABI-EVIDENCE.md`.
- The user ran the Windows probe successfully on Pie64, with matching VMM digest.
  That test read one physical byte; game address translation remains unverified.

## Collect the next mapping prerequisites

Run `Get-GuestMappingContext.ps1` in 64-bit Administrator PowerShell with Pie64
and Free Fire open. It writes `guest-mapping-context-<id>.txt` beside the script.
It collects kernel version/layout-source availability, selected kernel symbol
addresses, game PID, RAM ranges, paging mode, and paging-register samples.
It does not require the plug-in DLL. The user ran version 1: debugger queries and
cleanup passed, but the selected ADB endpoint was disconnected. Version 2 adds
one reconnect attempt to that explicit localhost endpoint and verifies it before
running Android queries. It uses CPU IDs from the debugger paging report,
because that report listed four CPUs while the configured CPU count was two.
The user subsequently ran version 2 successfully through ADB reconnect and all
four CPU queries. Kernel 4.19.195 / Android 9 were identified. Kernel-symbol
access was denied, and BTF/config sources were unavailable. See the runtime
report for the exact remaining gaps.

An unavailable query is recorded and other independent queries continue. Exit
code 1 means at least one query or collection step failed; share the full report
even then. An all-zero symbol address is unusable. CPU CR3 samples have not been
associated with the game process. See `RUNTIME-RESULTS.md` for interpretation.

The original tested ZIP and native DLL are unchanged. This collector and the
updated reports are available separately in the repository.

## Export a kernel image candidate

`Export-KernelCandidate.ps1` searches the installed BlueStacks and selected VM
directories for a standalone x86-64 Linux 4.19.195 kernel image. Run it in 64-bit
Windows PowerShell on the BlueStacks PC. It prints an `ArchiveFile` path after
header/version checks, SHA-256 deduplication, and ZIP content verification.
Share that ZIP for static inspection. A candidate with the same release may
still be a different build or lack the symbol/type data required for mapping.

If no matching image is found, share its `ResultFile` search report. An explicit
image can be selected with `-KernelPath 'C:\path\to\kernel'`. The helper does not
mount VM disks or alter settings. Discovery on the actual Windows installation
has not yet been tested.

Rebuild on Linux with C++17 and a MinGW x64 compiler:

```sh
MINGW_CXX=/path/to/x86_64-w64-mingw32-g++-posix bash build.sh
```

The build regenerates the DLL digest in the manifest. No BlueStacks or Oracle
binaries are redistributed in this package.
