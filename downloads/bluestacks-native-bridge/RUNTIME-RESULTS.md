# User-reported Windows native bridge result

The user ran the package published at Git commit
`8d945256f0d03d940747d6a3be5a7ab3654b3bd8` on 2026-10-14.
Archive SHA-256:
`f94889238a94902eeb2a8c13eb8669f957b930ed797aebec7c5d64cc520d1a9e`.
Plug-in DLL SHA-256:
`ff00d9e49cd11f76582b3476b7efd01107f115518fd4dbf9f7be38534a912ee3`.

```text
Preflight=PASS Machine=Pie64 HostPID=11068 VmmDigest=MATCH
PluginLoad=PASS Name=VBoxDbgHeadAimBridge
BridgeStatus=READY Protocol=1 ReadOnly=1 MaximumRead=4096
BridgeProbe=PASS BytesRead=1 Contents=OMITTED
PluginUnload=PASS
HandlerCleanup=PASS
SharedSession=RELEASED
```

This establishes loading through the installed debugger, a native read of one
byte at guest physical address zero, and cleanup in that run. Host PID 11068 is
historical; runners discover the current PID. The returned plug-in identity is
`VBoxDbgHeadAimBridge`, which the runner already uses for unloading.

The following remain unverified: arbitrary game-memory reads, guest process
page-table discovery, virtual-to-physical translation for Free Fire, entity/head/
visibility layouts, aim-control writes, repeated runs and concurrent shutdown.
No player coordinates or working aim-lock were demonstrated by this test.

## Next prerequisite collection

`Get-GuestMappingContext.ps1` records the live kernel version, available kernel
layout sources, a short allowlist of kernel symbols, game PID, physical RAM
ranges, paging mode, and per-CPU paging registers. It verifies the same host VMM
build and releases its shared session in `finally`. It uses ADB at the explicit
device serial; keep the corresponding Pie64 instance and Free Fire running.

It does not load the bridge, write guest memory, pause the VM, or change settings.
It does not retry the unavailable COM memory readers or `/proc/<game>/maps`.
CPU register reads are separate scheduling samples: a CR3 value must not be
assumed to belong to Free Fire. Zero kernel-symbol addresses are redacted, and
unavailable BTF/config/symbol sources are observations, not usable layouts.

The reference Oracle 6.1.36 Linux digger's `dbgDiggerLinuxQueryInterface` returns
only the DMESG interface. PROCESS and THREAD enum names alone do not provide an
implemented process mapper. The BlueStacks fork's support for a process mapper
has not been established.

The collector's report determines which kernel layout and page-table discovery
path can actually be implemented next; it does not establish game mappings by
itself.

Cloud checks using checksum-verified PowerShell 7.4.6 passed: syntax parsing,
continuation after an unavailable query, and rejection of a non-Windows host
with a partial report and exit code 1. These do not validate Windows COM, ADB,
or the actual guest queries.

## Mapping context version 1: user-reported Windows result

The user ran the collector from commit
`f841db10242ae7dc07c625c09768d3db680ed975` against Pie64, host PID 11068.
Host preflight, debugger plugin listing, paging-mode/range queries, register
queries for CPUs 0 and 1, and shared-session release succeeded.

ADB returned `device '127.0.0.1:5555' not found`. All eight ADB-dependent queries
failed for that same reason. Kernel version, kernel layout sources, symbols,
and the current game PID were therefore not collected. This is a missing ADB
transport connection; it does not invalidate the earlier native bridge pass.
`No plug-ins loaded` is consistent with the bridge probe's successful unload.

The debugger paging report lists CPUs 0, 1, 2, and 3, whereas the management
object's configured CPU count is 2. Version 1 used that configured count and
therefore did not sample CPUs 2 and 3. The two sampled CPUs have long-mode
paging and PCID enabled, with LA57 disabled. Their CR3 values are scheduling
samples; neither is identified as Free Fire's process page-table root.

Version 2 reconnects the explicitly selected localhost TCP endpoint once when
needed, then verifies `get-state` independently of the `connect` exit status.
If it remains unavailable, Android queries are skipped and the device list and
port-check guidance are recorded while debugger queries continue. It selects
CPU IDs from the actual debugger paging report, falling back to the configured
count only when no runtime CPU IDs were reported. Live Windows validation of
these changes is pending.

Version 2 cloud validation passed syntax parsing and subprocess-fixture checks
for an already connected endpoint, reconnection after a missing-device error,
rejection of a failed connection even when `adb connect` exits zero, and no
implicit switch to another device. CPU enumeration was checked against the
user's actual four-CPU report, configured-count fallback, and an invalid CPU ID.
The fixtures validate runner behavior, not a live BlueStacks connection.
