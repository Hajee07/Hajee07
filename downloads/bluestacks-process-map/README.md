# Read-only Free Fire process-mapping probe

This probe uses the already tested native physical-read DLL and the kernel
extracted from the user's `fastboot.vdi`. It verifies live kernel bytes before
using the derived task/mm fields, locates the current ADB game PID, discovers
its page table, and walks its VMAs until it can revalidate an ARM64 `libil2cpp.so`
ELF header through that page table. Other matching Unity/metadata mappings seen
before the target are reported as observations.

**Live process discovery passed in version 2.** The user verified the kernel,
found Free Fire PID 2942 and its physical page-table root. Version 3 subsequently
read ARM64 IL2CPP headers before VMA 896, but kept scanning and exhausted the
30,000-read budget at VMA 3300 before final rechecks. Version 4 stops after the
first IL2CPP header passes targeted mapping, filename, header, and process
rechecks. Its Windows run is pending.
Entity/head/visibility layouts and aim-control writes remain unimplemented.

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
pages. Five-level paging is rejected. A bounded 1024-entry translation cache is
keyed by page-table root and virtual page. Every data read, including a cache hit,
is followed by a fresh walk of the live page tables. Observed changes invalidate
the entry and fail the read. Guest bytes and page-table entries are not cached.
Live list/identity inconsistencies fail the run. Reads stop at 30,000 calls
or a 120-second elapsed budget between calls. Those bounds do not interrupt a
COM call already in progress.

Kernel relocation candidates are zero plus a bounded, aligned slide derived
from LSTAR when the installed debugger exposes it. Each candidate must match
the full banner, seven code anchors, and initial task/mm fields. No matching
candidate means no process layout is used. This first implementation may reject
an otherwise valid kernel mapping when its relocation cannot be derived.

The idle task's `active_mm` is reported as an observation; it is not required to
equal `init_mm`. Linux context switching assigns and clears this field. No other
initial-task fields are relaxed. Failure messages identify the individual field.

Filename lookups are deduplicated by the observed file object, with a 1024-entry
bound. Progress is reported every 128 VMAs, and partial scan totals survive an
exception. `LibraryCandidate ... Status=PENDING_RECHECK` is provisional.
For the first ARM64 IL2CPP header at file offset zero, the targeted probe rechecks
the process, VMA bounds/file/offset/links, immediate neighbor links (or list head),
filename, and the exact 20 header bytes. It checks the VMA and process again after
the header read, then returns `StopReason=TARGET_VERIFIED`. Every virtual read
still rewalks the live page tables. Only this candidate gets `Revalidated=True`;
earlier mappings remain observations. Changes to skipped file objects can cause
a library to be missed in this non-atomic scan, so a missing library is reported
as unverified.

`LibraryScanStop Reason=TARGET_VERIFIED CompleteVmaList=False` means the remaining
VMAs were not enumerated. The probe does not collect all load segments, choose a
module load bias, or verify metadata/entity structures. Reaching the list end
without a verified target is a failure at the runner level. The core's separate
`Libraries` method retains full enumeration for offline checks; the Windows
runner uses `ProbeLibrary` and its target rechecks.

The task scan is bounded to 2048 nodes and the VMA scan to 4096 nodes. Only the
selected game's Unity/IL2CPP/metadata mapping names and ranges are logged. Game
object contents are not printed. Multiple read calls are not an atomic snapshot;
the probe does not take guest kernel locks or hold task/mm references. List,
translation, and identity rechecks detect observed changes, but cannot eliminate
all lifetime races. Restart the probe after a reported inconsistency with the
game left running.

A successful result includes `KernelIdentity=PASS`, `ProcessMap=PASS`, and
`GameLibraryRead=PASS Name=libil2cpp.so Architecture=ARM64`. The first two stages
and provisional ARM64 header reads have been observed on Windows. The final
library verification stage remains pending; the runner rechecks the ADB PID and
process identity before reporting it as passed.
Exit code 1 means a stage or cleanup failed.
Share the complete `ResultFile` report even after a failure; individual stages
remain distinguishable.

See `LAYOUT-EVIDENCE.md` for derivation and provenance. No uploaded VDI, extracted
kernel, APK, or Oracle/BlueStacks system binaries are included in this package.

## Offline checks

Forty-six checks passed using PowerShell 7.4.6 with C# 5 language compatibility:
page sizes and PCID, cross-page reads, noncanonical/nonpresent addresses, RAM
bounds, changing mappings, malformed replies, matching/mismatching real extracted
kernel anchors, and a synthetic game process/VMA/ARM64 header. Regression cases
cover borrowed/null/initial idle `active_mm` and continued rejection of invalid
idle pointers, wrong PID/name, and non-null idle `mm`.

The 1800-VMA fixture reaches a library at the end in 9663 physical reads, within
the unchanged 30,000-read budget. Tests also cover cache invalidation, separation
between page-table roots, detection of unmapped pages and renamed target files,
and preservation of partial scan progress. Fixture performance is not a measured
live Windows result.

A second fixture has 4500 VMAs with IL2CPP at VMA 800. The targeted scan finishes
in 4372 physical reads without enumerating the tail, under the unchanged budgets.
Regressions reject filename, VMA file, header, process mm, list-head and neighbor
link changes, including a VMA changed during the final header read. Wrong ELF
architecture, nonzero file offset, and a Unity-only header cannot satisfy the
target. Failed revalidation preserves provisional status and progress.

Reproduce with the extracted ELF available locally:

```powershell
.\Run-CoreTests.ps1 -KernelElfPath C:\path\to\vmlinux
```

Tests validate the reader against controlled fixtures. They do not establish
live Windows COM behavior, runtime object lifetime, or a working aim lock.
