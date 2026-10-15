# Read-only Free Fire process-mapping probe

This probe uses the already tested native physical-read DLL and the kernel
extracted from the user's `fastboot.vdi`. It verifies live kernel bytes before
using the derived task/mm fields, locates the current ADB game PID, discovers
its page table, and walks its VMAs to verify an ARM64 `libil2cpp.so` load layout
against the inspected APK. Other matching Unity/metadata mappings seen before
the target are reported as observations.

**Version 5 passed live kernel, process, header, and module verification.** It
selected the second IL2CPP mapping after rejecting the whole-file-sized mapping,
verified all eight load segments and four fingerprints, and completed in 10847
reads with successful cleanup. Version 6 adds registration/code verification for
nine field and nine method candidates recovered from the exact APK metadata.
Its live run is pending. See `GAME-LAYOUT-EVIDENCE.md` and `game-layout.json` for
the recovery and its limits. Live player objects, head world positions, visibility
semantics, and aim-control writes remain unimplemented/unverified.

Extract the complete ZIP into a new folder. Start the Pie64 instance and Free
Fire, leave the game running, and run in 64-bit Administrator Windows PowerShell:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-ProcessMap.ps1
```

The selected ADB serial defaults to `127.0.0.1:5555`; `-Device` can select the
endpoint displayed by BlueStacks. An explicit disconnected localhost endpoint
is reconnected once and verified. Other devices are not selected automatically.
The runner discovers the current host/game PIDs; old PIDs are not constants.

The package checks DLL and all five runtime C# source digests, plus the exact
loaded VMM fingerprint. It
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
For each ARM64 IL2CPP header at file offset zero, the targeted probe rechecks
the process, VMA bounds/file/offset/links, immediate neighbor links (or list head),
filename, and the exact 20 header bytes. It checks the VMA and process again after
the header read. Every virtual read still rewalks the live page tables.
`Revalidated=True` describes this header check; `SelectedModule=True` identifies
the candidate that also passed the module checks. Changes to skipped file objects can cause
a library to be missed in this non-atomic scan, so a missing library is reported
as unverified.

The module check rejects a whole-file-sized mapping as a loaded-layout candidate.
For a candidate whose first VMA matches the first PT_LOAD boundary, it compares
the complete ELF header and program-header table. It reads a local window of at
most 128 VMAs (plus one boundary observation) covering the module's extent.
All eight PT_LOAD file ranges must have the expected file offsets and basename;
memory-only tails must also be mapped. GNU build-ID note bytes and three 64-byte
executable-segment samples must match the APK reference. These bytes, used VMA
fields/links, filenames, and process identity are rechecked before success.

`LibraryScanStop Reason=MODULE_VERIFIED CompleteVmaList=False` means the rest of
the process list was not enumerated. `WindowVmas` counts the separate module
window; `VmasVisited` counts the outer search. A match establishes this observed
layout and these sampled bytes, not a whole-memory hash, currently executing
module copy, decoded metadata, or entity layout. Unmapped pages, runtime-altered
reference bytes, and different loader layouts may prevent verification.

Reaching the list end without a matching module is a failure. The core's separate
`Libraries` and `ProbeLibrary` methods retain the previous enumeration/header
workflows for offline regression checks; the Windows runner uses `ProbeModule`.

The next stage verifies 80 registration/code references twice. It checks the
runtime-relocated pointer values separately from raw data and compares selected
field offsets, type descriptors, type sizes, and method/instruction bytes. These
references come from the exact SHA-256-checked metadata and ELF inputs. It does
not dereference player objects or call any game method. The global budgets are
shared with the preceding scan; process identity is rechecked between rounds.

The task scan is bounded to 2048 nodes and the VMA scan to 4096 nodes. Only the
selected game's Unity/IL2CPP/metadata mapping names and ranges are logged. Game
object contents are not printed. Multiple read calls are not an atomic snapshot;
the probe does not take guest kernel locks or hold task/mm references. List,
translation, and identity rechecks detect observed changes, but cannot eliminate
all lifetime races. Restart the probe after a reported inconsistency with the
game left running.

A successful result includes `KernelIdentity=PASS`, `ProcessMap=PASS`, and
`GameLibraryRead=PASS Name=libil2cpp.so Architecture=ARM64`, followed by
`GameModuleIdentity=PASS`, then `GameLayoutRegistration=PASS`. The first four
stages were observed on Windows with version 5; the registration stage remains
pending. The runner rechecks the ADB PID and process identity before success.
Exit code 1 means a stage or cleanup failed.
Share the complete `ResultFile` report even after a failure; individual stages
remain distinguishable.

See `LAYOUT-EVIDENCE.md`, `MODULE-EVIDENCE.md`, and `GAME-LAYOUT-EVIDENCE.md` for
derivation and provenance.
The generated module reference contains only selected header/sample bytes and
layout constants. No uploaded VDI, extracted kernel, full APK/library, or
Oracle/BlueStacks system binaries are included in this package.

## Offline checks

Seventy-two checks passed using PowerShell 7.4.6 with C# 5 language compatibility.
The original forty-six cover:
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

Eighteen additional module checks use the exact APK reference bytes with synthetic
mappings. They distinguish a whole-file mapping from the PT_LOAD layout, reject
incorrect tables/build ID/code/file offsets/names/gaps, detect changes during
verification, and exercise the 128-VMA window boundary. The normal module fixture
uses 681 reads and nine window VMAs; these are offline measurements. Reference
generation reproduces identical bytes and rejects an incorrect source digest.

Eight registration checks validate matching relocated data and reject altered
field offsets, relative-RVA-as-pointer mistakes, method bytes, between-round
changes, and process/profile mismatches. The registration fixture uses 1018
reads. The metadata decoder validates all recovered records, reproduces the
same JSON/C# reference, and passes five malformed-input checks. These checks do
not establish live object layouts or aim behavior.

Reproduce with the extracted ELF available locally:

```powershell
.\Run-CoreTests.ps1 -KernelElfPath C:\path\to\vmlinux
```

Tests validate the reader against controlled fixtures. They do not establish
live Windows COM behavior, runtime object lifetime, or a working aim lock.
