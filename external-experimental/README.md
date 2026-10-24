# NOVA External — experimental native-engine host

**This Windows x64 prototype has not been launched against live Windows, BlueStacks or Free Fire. All original feature behavior is unverified. It is not a confirmed fully working external replacement.**

The original native panel/engine is retained, with the two previously reviewed login-navigation patches and a Kernel32 import-provider redirect. A new host loads that engine and a memory-interface proxy into its own process. The proxy reconstructs selected VM-context/RAM layouts from your uploadedBstkVMM.dll and uses external process-memory reads/writes. It does not load a helper/DLL or create a remote thread in HD-Player.

## Run

1. Start the matching BlueStacks5.22.125.1001 instance and Free Fire.
2. Extract this ZIP and open `NOVA-External-Experimental.exe` on64-bit Windows.
3. Keep the console visible. Startup validates the installed SDK hash, discovers/validates VM metadata and probes an already-mapped RAM page before loading the original engine. If startup fails, the error is shown; no successful game functionality is claimed.

An optional HD-Player PID can be supplied from a terminal:

```console
NOVA-External-Experimental.exe 11616
```

Use the actual current PID, not the example after an emulator restart. Multiple-instance routing remains unverified; use one active game instance for this prototype.

The engine/proxy components are extracted to a private `%TEMP%\NOVA_external_<host-PID>_<tick>` folder and loaded only by the new host. No file is installed into or overwritten in the BlueStacks installation. The original panel/menu code is preserved, including its existing hotkeys and game offsets. Its window belongs to the external host; feature compatibility with the installed game is not established.

## What this changes

- The original launcher/injection stage is replaced with an external host.
- The embedded engine is preserved byte-for-byte except the login changes and import-provider redirect recorded inENGINE-PROVENANCE.json.
- BstkVMM-named proxy exports exist in the host process only; the installed vendor SDK is read solely for its fingerprint and its live metadata is read through the process handle.
- The original engine hooks the proxy's local bootstrap function in its own process. No hook is installed in the emulator by this host/proxy.
- The engine imports its existing Kernel32 APIs through the local proxy, which forwards ordinary APIs and binds critical guards before TLS/DllMain. Guards limit process handles, reject dynamic ordinal lookup and reject common remote code-loading interfaces. New host/proxy imports were audited for remote-injection APIs.

## Tested and still unresolved

21 synthetic-memory C fixture checks passed with address/undefined-behavior sanitizers.13 comparisons passed against bounded x64 emulation of the supplied SDK's getter/selected RAM-mapping machine code. Windows cross-compilation passed with warnings treated as errors. The packaged source recipe was also exercised successfully against the exact original EXE. Embedded engine/proxy bytes and static imports were checked. These are not live process traces or proof of every game feature.

The RAM backend supports selected already-mapped RAM paths and architectural32-bit/PAE/AMD64 page walks. It fails on unsupported mappings instead of running VM handlers inside the emulator. Device/MMIO behavior, COW/page promotion, missing chunk allocations, nested-translation mode2, complete SDK semantics and synchronization with a running VM remain unresolved. External reads are unlocked snapshots and may race changes in VM state. Performance is unmeasured. Original game offsets and every original feature remain unverified.

Initialization errors include:-5(no validated VM found),-7(no supported/readable paging/RAM state), and values below-1000(process-open error; e.g.-1005 is Windows access denied). A LoadLibrary Windows126 error indicates an unresolved native dependency. Engine acknowledgment only confirms the local proxy handshake; it does not prove Aimbot/ESP operation. Zero-length local handshake probes are excluded from read-success statistics.

Only the exact uploaded SDK file is accepted:
`09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a`.
A different SDK is rejected before the engine starts. Restart the host when restarting the emulator/VM. This prototype is not a general VM debugger.

## Source/rebuild

`source/` contains the host, proxy, memory core, tests and Linux/WSL rebuild script. The recipe requires Zig0.13.0, GNUobjcopy, Python3 and your exact original uploadedEXE. It never executes the inputEXE. Pass `--original-exe` and `--zig` to `source/build.py`.

The original C++ source was not recovered. Reusing its native engine retains the original code/controls; it does not establish feature-for-feature equivalence after relocation. No fully working/all-features claim is made.
