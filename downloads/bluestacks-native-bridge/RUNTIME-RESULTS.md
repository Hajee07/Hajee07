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
count only when no runtime CPU IDs were reported. The subsequent Windows result
for these changes is recorded below.

Version 2 cloud validation passed syntax parsing and subprocess-fixture checks
for an already connected endpoint, reconnection after a missing-device error,
rejection of a failed connection even when `adb connect` exits zero, and no
implicit switch to another device. CPU enumeration was checked against the
user's actual four-CPU report, configured-count fallback, and an invalid CPU ID.
The fixtures validate runner behavior, not a live BlueStacks connection.

## Mapping context version 2: user-reported Windows result

The user ran version 2 from commit
`c6456283672e1323481e70a9377b1e002fdcb2e5`. The explicit localhost ADB reconnect
succeeded, and the collector queried all four debugger-reported CPU IDs. Shared
session cleanup succeeded. The one unavailable query was `/proc/kallsyms`, which
returned `Permission denied`.

Verified guest observations:

- Kernel: Linux 4.19.195 x86_64, build `#1 SMP PREEMPT Fri Oct 17 10:22:49 IST 2025`.
- Android 9 / SDK 28, guest ABI x86_64, native bridge `libnb.so`.
- Free Fire 1.132.1, package ABI arm64-v8a, PID 3806 at both collection checks.
- `/sys/kernel/btf/vmlinux` and `/proc/config.gz` were not readable/available.
- The two distinct sampled CR3 bases, after removing PCID bits, were
  `0x0220e000` and `0x9e388000`. Neither base is attributed to Free Fire.
- Kernel symbols, process/task layouts, the game's page-table root, game
  entities, and aim-control interfaces remain unestablished.

Repeating these queries will not supply the unavailable kernel layouts. The
next helper, `Export-KernelCandidate.ps1`, searches installed BlueStacks/selected
VM directories and kernel-related SDK path settings for standalone Linux images.
It checks x86-64 boot/ELF headers and release 4.19.195, deduplicates by SHA-256,
and creates a ZIP with a manifest. It then verifies each archived image's length
and SHA-256. The manifest omits full host paths. A release match is a candidate,
not proof of exact identity with the running kernel or presence of debug types.

The helper leaves VM disks and settings unchanged and does not query restricted
guest symbols again. If the image is only inside a VM disk, it reports that no
standalone candidate was found. It does not mount or modify disks. Candidate
images are limited to 128 MiB each and at most four distinct images per export.

Cloud checks passed syntax parsing, Linux boot-header/version extraction, ELF
banner extraction across a read boundary, rejection of the wrong architecture,
archive content verification, and rejection of a source changed before archiving.
Header fields were checked against Linux v4.19.195 `Documentation/x86/boot.txt`.
The user's subsequent discovery and image-inspection results follow.

## Subsequent fastboot image inspection

Standalone image discovery found no candidate. The user listed Pie64's attached
VDI/VHD/VHDX media and supplied the 11 MiB `fastboot.vdi` inside a CRC-valid ZIP.
It contains the matching Linux 4.19.195 boot image and initrd. The full kernel
banner agrees with the live report. Embedded kallsyms recovery produced 87,332
symbols; an independent comparison against 9,889 exported symbols matched.

The derived task/mm fields are now used by a separate
[read-only process-mapping probe](../bluestacks-process-map/README.md). It passed
16 offline reader checks with real kernel anchors and synthetic process/VMA
records. Live process discovery and game-library reads remain unverified.

The user then ran process-mapping version 1. Banner/code-anchor virtual reads
succeeded, and initial-task validation failed after 195 physical read calls.
Cleanup passed. Version 2 corrects its invalid fixed idle `active_mm` assumption;
22 offline checks pass, and a live rerun is pending. See the process mapper's
`LAYOUT-EVIDENCE.md` for source/binary evidence and the exact scope of this result.

## Process mapping version 2: user-reported Windows result

The user then ran version 2. Preflight, ADB game identity, plugin load, paging
context, kernel identity, and process discovery passed. The verified kernel
root was 0x220e000 with slide zero. PID 2942 was found after 150 task-list nodes;
its mm was 0xffff88811d512800 and its physical page-table root was 0xb9cf4000.
These values describe that run and are not hard-coded into the mapper.

The idle task's observed active_mm was also 0xffff88811d512800, confirming the
borrowed-context case handled by version 2. The library scan then exhausted its
30,000 physical-read-call budget. Version 2 did not emit partial VMA totals or
candidates, so this report does not verify any game-library ELF header. Plugin
unload, handler cleanup, and shared-session release all passed.

Version 3 caches page translations while rewalking live page tables after each
data read, deduplicates file-name lookups, and rechecks matched filenames before
success. It preserves partial counters and emits scan progress. Both caches are
bounded; the 30,000-call and 120-second budgets remain unchanged.

Thirty-one offline checks passed. An 1800-VMA fixture with a final ARM64 library
completed in 9663 physical reads; cached mapping changes, unmapping, root
separation, and matched-file renames are covered. These fixture results do not
establish live Windows performance. Version 3's Windows library scan remains
pending, and entity/head/visibility mappings and aim writes are unimplemented.

## Process mapping version 3: user-reported Windows result

Kernel identity and process discovery passed again. Version 3 read ARM64 Unity
and IL2CPP header candidates. The first IL2CPP candidate was observed between
VMAs 768 and 896, starting at 0x7f96b9e6b000 in that run. The probe continued its
full VMA scan and reached its unchanged 30,000-call limit at VMA 3300. It had
inspected 915 file objects, skipped 571 repeated file lookups, and recorded 4877
translation cache hits. Final library rechecks did not execute, so candidates
remained provisional and `GameLibraryRead=FAIL` was correct. Plugin unload,
handler cleanup, and shared-session release passed.

Version 4 revalidates the first IL2CPP target's VMA, neighboring links or list
head, filename, exact header bytes, and process identity before stopping. The
Windows runner then repeats its ADB PID/process checks before final success.
The report explicitly marks that the remaining VMA list was not enumerated.
The native DLL and read/time budgets are unchanged.

Forty-six offline checks passed, including mutation regressions and a 4500-VMA
fixture whose target at VMA 800 is verified in 4372 physical reads. Live version
4 verification remains pending. Head/entity/visibility mapping and aim writes
remain unimplemented.

## Process mapping version 4: user-reported Windows success

Version 4 passed the full kernel/process/targeted-header workflow on Pie64.
Host PID was 23620, game PID 2942, and process discovery visited 147 task nodes.
The IL2CPP VMA at 0x7f96b9e6b000 was revalidated, and GameLibraryRead passed after
808 outer VMAs and 8096 physical reads. It inspected 156 file objects, skipped
217 repeated lookups, and recorded 905 translation-cache hits. Plugin unload,
handler cleanup, and shared-session release all passed.

The first VMA spans 0xaf95000 bytes, exactly the page-rounded size of the APK's
IL2CPP file. It cannot be assumed to be the loaded module base. Version 5 checks
the first segment boundary, all eight PT_LOAD ranges/file offsets, ELF tables,
GNU build ID, and three code samples. A module-local VMA window is bounded to
128 entries; global read/time limits and the native DLL are unchanged.

Sixty-four offline checks pass (46 reader/header plus 18 module checks). The
reference generator reproduces its output and rejects the wrong source SHA-256.
Live version 5 module verification remains pending. Entity/head/visibility
mapping and aim updates remain unimplemented.

## Process mapping version 5: user-reported Windows success

The user reported GameModuleIdentity=PASS at load bias 0x7f96c4e00000, matching
GNU build ID ee8bf32c4483429084fde022704ead01a94b6620. All eight load segments,
28 window VMAs, and four fingerprints passed. The first whole-file-sized mapping
was rejected. The outer scan visited 891 VMAs, inspected 238 file objects, and
skipped 167 repeats. Total physical reads were 10847 with 1266 cache hits. Kernel
identity, process identity (145 tasks visited), and all cleanup steps passed.

Subsequent exact-APK metadata recovery validates 43624 types, 336350 methods,
475669 fields, 278571 parameters, and 56 images. Native registration tables and
method tokens identify nine selected field and nine method candidates. Version 6
adds 80 registration/code comparisons in two rounds after module verification.
Seventy-two offline C# checks and five metadata-negative checks pass; regenerated
reference outputs match. Live version 6 verification remains pending. Player
objects, head world positions, visibility semantics, and aim writes remain
unimplemented/unverified. See the process probe's `GAME-LAYOUT-EVIDENCE.md`.

## Process mapping version 6: registration mismatch

User-reported game PID 5132 was discovered independently (151 tasks visited).
Kernel, process, and ARM64 module identity passed. The module window contained
16 VMAs; eight segments and four fingerprints matched the same build ID as v5.
The outer scan visited 778 VMAs, inspected 188 files, and skipped 167 repeats.
The first failed check was COW.GameFacade.CurrentGame.type_descriptor at RVA
0xadabba0 in pass one. PhysicalReadCalls=9123, TranslationCacheHits=1074.
Plugin unload, handler cleanup, and shared-session release all passed.

V6 did not report actual bytes, so descriptor conversion is an unconfirmed
hypothesis. V7 collects bounded exact differences over both rounds without
weakening comparisons or following observed pointers. It still fails on any
mismatch and immediately stops on read/translation/identity/budget errors.
79 offline C# checks pass. The V7 Windows report is required to diagnose the
mismatch; active objects, head world positions, and aim updates remain pending.

## Process mapping version 7: stable descriptor pointer representation

User-reported PID 6053 was found after 152 tasks. InitialActiveMM=0 was accepted
as the valid idle-task state. Kernel/process/module verification passed: eight
load segments, 16 window VMAs and four fingerprints. The outer scan visited 840
VMAs, inspected 196 files and skipped 167 repeats. PhysicalReadCalls=10636,
TranslationCacheHits=1241. All cleanup steps passed.

Both comparison rounds matched 71 checks and differed on exactly nine type
descriptors, with no changes between rounds. The descriptors' four flag/kind
bytes match, while their eight-byte payloads are addresses. All nine resolve to
one metadata base via the exact type-index/88-byte-stride relationship documented
in GAME-LAYOUT-EVIDENCE.md. V8 corrects the representation check by requiring
exact header and record contents at these derived addresses, not merely plausible
pointers. 89 offline checks pass. V8 target reads remain unverified on Windows;
player objects, head world positions, and aim writes remain incomplete.

## Process mapping version 8: outer VMA traversal repeated a node

Host PID 6372 and game PID 3775 passed preflight/process discovery (162 tasks).
Kernel identity passed with InitialActiveMM=0. The outer scan stopped at 349
visited nodes with the old combined bound/cycle error. Because this is below
4096, the failed condition was a repeated node. Concurrent list changes are a
possible cause, not established by this report. Module and metadata validation
were not reached successfully. Physical reads=4816, cache hits=404, inspected
files=100, skipped repeats=116. All cleanup stages passed.

V9 separates repeated-node and node-limit diagnostics. One repeated-node failure
can restart from the list head after rechecking process identity. Partial results
are discarded; caches/dictionaries are refreshed; read/time budgets are shared.
A second repetition still fails. Other failures are not retried. 96 offline
checks pass. Live v9 recovery and v8's metadata-target validation remain pending.

## Process mapping version 9: first-attempt scan, runtime header prefix mismatch

The supplied report passed kernel/process checks for PID 3775, then module
verification on attempt one. Load bias was 0x777d99a00000, with the same build ID,
eight segments, 16 window VMAs and four fingerprints. It visited 702 outer VMAs,
inspected 170 files and skipped 179 repeats. Physical reads=9298, cache hits=1066.
All cleanup stages passed. No repeated-node retry was needed in this run.

Both rounds matched 71 checks and failed all nine descriptor header comparisons.
The 18 bounded header observations consistently show words 0 and 24 instead of
the decoded file's custom first words; the following 24 reported bytes match.
Unreported header bytes and type-record contents remain unverified. V10 pins
that observed runtime prefix while still comparing the remaining 248 header
bytes and every selected 88-byte type record. 101 offline checks pass; live
v10 metadata validation and player/head/aim integration remain pending.

## Process mapping version 10: live runtime metadata success

The user reported game PID 3775 with kernel/process/module verification passing.
Module load bias was 0x777d99a00000 with the same GNU build ID, eight load segments,
16 window VMAs and four fingerprints. Both rounds matched all 80 checks with
zero mismatches and no changes. Runtime metadata base 0x777dac7aa000, all nine
descriptors and complete 88-byte records passed the observed zero/version24
header profile. Physical reads=9692, cache hits=1121, outer VMAs=714, inspected
files=178, skipped repeats=183. Plugin unload, handler cleanup and session
release all passed. No live player/head/aim verification was claimed by v10.

V11 adds a metadata-derived local-player chain and managed head Transform probe.
It checks class identities/ancestry, original-path hotfix entries, local-player
marker and supported head interface dispatch. 127 offline checks pass; new live
object verification remains pending. Other players, head world positions,
visibility semantics and aim writes are still unimplemented.

## V11 reports: traversal interruption and IFix class-layout mismatch

First report (PID 5553): kernel/process checks passed, but outer VMA validation
failed after 945 valid nodes; 8837 physical reads and 985 cache hits. It did not
reach module/metadata/object success. Second report (PID 5886): kernel/process,
module identity and both 80-check metadata rounds passed. Module load bias was
0x777da4e00000, metadata base 0x777da17aa000, with eight load segments and 16 window
VMAs. After GameFacade/MatchGame/IFix root type observations, the IFix combined
class token/instance-size assertion failed. Reads=12854, cache hits=1631,
outer VMAs=1019, inspected files=255, skipped repeats=165. Both reports completed
all cleanup stages.

Inspection found the V11 generator had treated opaque native size values as
exact runtime class sizes. IFix's source instance word is 0x81818099. V12 marks
six affected profiles as untrusted initial sizes, uses verified field/base
storage minima and hard runtime bounds, and independently validates IFix's
actual static wrapperArray field metadata/type/token/offset/storage extent.
Plausible native-size profiles and all class identity checks remain exact.
It also adds one bounded rescan for outer order/backlink inconsistencies and
precise diagnostics. 142 offline checks pass. Live object/head validation and
aim integration remain pending; actual IFix token/size values were not in v11.

## V12 report: local-player success, head-provider cache null

PID 6313 passed all kernel/process/module and both 80-check metadata rounds.
Runtime metadata base was 0x777da17aa000. IFix actual instance size=40 and derived
match EPPMGCJDEDC size=1664 passed the corrected bounds. The runtime ancestry
34188 -> 34109 -> 34107 -> 12425 and 33936 -> 32133 was observed; local player
32360 -> 31824 passed with its local marker. LocalPlayerObjects=PASS reported
128 observations. ManagedHeadTransform=NOT_READY_PROVIDER_NULL: no head Transform
or world position was verified. Physical reads=12410, cache hits=1675, outer
VMAs=886, inspected files=180, skipped repeats=205. All cleanup stages passed.

V13 adds a bounded read-only exact-name bone_Head lookup in the underlying model
cache when the player cache is null. It verifies the original virtual/hotfix
path, closed generic dictionary identity, String key and returned node before
using the existing managed Transform checks. 155 offline checks pass. A cache
miss remains NOT_READY; live fallback validation and aim integration are pending.

## V13 managed local-head observation; V14 native sample pending

The user's V13 run passed the exact module and runtime metadata checks, live
local-player chain and cached managed head Transform. The model cache had 29
entries and one `bone_Head` match; 280 static observations were rechecked. Total
physical calls: 15040. All cleanup stages passed. No coordinates or aim writes
were produced by that run.

Process-map V14 adds exact Unity icall/code identity and a bounded native local
head hierarchy calculation. All 174 offline checks pass. Its live Windows
position validation remains pending, along with other-player enumeration,
visibility semantics and aim integration.

## V14 native sample rejected; V15 bounded capture pending

The V14 user report passed exact module/metadata, local-player and managed-head
verification, then failed the native stage's combined snapshot at
0x777d5b3d4150. No XYZ was reported; 15449 physical calls and all cleanup stages
completed. That generic snapshot error does not identify which native field
changed. V15 separates immutable identity validation and short coalesced TRS
copies, and retries only selected TRS motion (at most three fresh attempts).
All 181 offline checks pass. Live V15 sampling, other players, visibility and
aim integration remain pending.
