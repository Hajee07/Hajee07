# Read-only Free Fire process-mapping probe

This probe uses the already tested native physical-read DLL and the kernel
extracted from the user's `fastboot.vdi`. It verifies live kernel bytes before
using the derived task/mm fields, locates the current ADB game PID, discovers
its page table, walks its VMAs, and attempts to read the ARM64 `libil2cpp.so` ELF
header through that page table. It reports matching Unity/metadata mappings.

**Live Windows validation is pending.** The earlier native one-byte probe passed;
this process-mapping path has passed offline checks only. Entity/head/visibility
layouts and aim-control writes remain unimplemented.

Extract the complete ZIP into a new folder. Start the Pie64 instance and Free
Fire, leave the game running, and run in 64-bit Administrator Windows PowerShell:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-ProcessMap.ps1
```

The selected ADB serial defaults to `127.0.0.1:5555`; `-Device` can select the
endpoint displayed by BlueStacks. An explicit disconnected localhost endpoint
is reconnected once and verified. Other devices are not selected automatically.
The runner discovers the current host/game PIDs; old PIDs are not constants.

The package checks DLL/source digests and the exact loaded VMM fingerprint. It
loads the same native DLL used in the successful probe, uses its read-only info
handler, and unloads and releases its shared session in `finally`. The DLL bytes
are unchanged. No VM pause or memory write is used.

Physical reads are restricted to ranges described by the installed debugger as
RAM; device, BIOS, and other ranges are excluded. Each read is bounded to 4096
bytes. Four-level 48-bit AMD64 translation handles PCID and 4 KiB/2 MiB/1 GiB
pages. Five-level paging is rejected. Translations are rechecked after each data
read; live list/identity inconsistencies fail the run. Reads stop at 30,000 calls
or a 120-second elapsed budget between calls. Those bounds do not interrupt a
COM call already in progress.

Kernel relocation candidates are zero plus a bounded, aligned slide derived
from LSTAR when the installed debugger exposes it. Each candidate must match
the full banner, seven code anchors, and initial task/mm fields. No matching
candidate means no process layout is used. This first implementation may reject
an otherwise valid kernel mapping when its relocation cannot be derived.

The task scan is bounded to 2048 nodes and the VMA scan to 4096 nodes. Only the
selected game's Unity/IL2CPP/metadata mapping names and ranges are logged. Game
object contents are not printed. Multiple read calls are not an atomic snapshot;
the probe does not take guest kernel locks or hold task/mm references. List,
translation, and identity rechecks detect observed changes, but cannot eliminate
all lifetime races. Restart the probe after a reported inconsistency with the
game left running.

A successful result includes `KernelIdentity=PASS`, `ProcessMap=PASS`, and
`GameLibraryRead=PASS Name=libil2cpp.so Architecture=ARM64`. These stages have
not yet been observed on Windows. Exit code 1 means a stage or cleanup failed.
Share the complete `ResultFile` report even after a failure; individual stages
remain distinguishable.

See `LAYOUT-EVIDENCE.md` for derivation and provenance. No uploaded VDI, extracted
kernel, APK, or Oracle/BlueStacks system binaries are included in this package.

## Offline checks

Sixteen checks passed using PowerShell 7.4.6 with C# 5 language compatibility:
page sizes and PCID, cross-page reads, noncanonical/nonpresent addresses, RAM
bounds, changing mappings, malformed replies, matching/mismatching real extracted
kernel anchors, and a synthetic game process/VMA/ARM64 header.

Reproduce with the extracted ELF available locally:

```powershell
.\Run-CoreTests.ps1 -KernelElfPath C:\path\to\vmlinux
```

Tests validate the reader against controlled fixtures. They do not establish
live Windows COM behavior, runtime object lifetime, or a working aim lock.
