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

## V15 local native-head sample passed; V16 collection pending

V15 passed on guest PID 8063, host PID 6372. The local-head native sample was
X=58.67942 Y=12.7244778 Z=23.06973, attempt 1, two chunks, nine parents, capacity
230 and 105 native observations. Static object observations: 282. Total physical
calls: 17097. All cleanup stages passed. This is one read-only local-head sample.

V16 adds one exact typed match Player dictionary and bounded object validation
(maximum 16 unique candidates). It also corrects the head-cache version snapshot
from free-list +0x24 to the complete counter header containing version +0x2c.
203 offline checks pass; the V16 Windows collection run remains pending. Other
head positions, enemy/team/alive/visibility semantics and aim writes are not
implemented.

## V16 complete observed collection; V17 other-head samples pending

V16 verified 14 dictionary members (local plus 13 others, including Player_Watching),
with no removed/null entries and 126 collection observations. It discarded the
first moving head pose, then sampled the local head at X=61.1467857,
Y=12.7256794, Z=21.0208225 on attempt two. Total physical calls: 19180. All cleanup
stages passed. This does not establish an enemy list.

V17 adds at most two nonlocal head samples with fresh membership/context checks.
The optional phase has a 6000-call additional cap including reserved final checks;
it uses the same global Reader limits and does not reset counts/time. All 223
offline checks pass. Live V17 sampling, team/alive/visibility semantics and aim
integration remain pending.

## V17 changed pose and collection; V18 bounded retry pending

The V17 report used host PID 6372 and guest PID 9864. Exact ARM64 module and
80 registration checks passed twice. Managed local-head resolution passed via
a 30-entry model cache. Native samples changed on all three attempts (indices
0, then 8, then 8); no position was accepted. The roster snapshot changed on
final recheck at 0x777d85ad3340. That address alone does not identify the field.
No members were accepted and the optional other-head phase performed zero reads.
Total physical calls: 20445; cache hits: 2968. All cleanup stages passed.

V18 preserves exact TRS comparisons and the three-attempt limit while reporting
continued motion as NOT_READY_MOTION. A typed object-snapshot mismatch in the
collection permits one completely fresh retry. Both attempts share an extra
4500-call ceiling, never extending past count 28000; remaining final checks
still share the global 30000-call/120-second limits. Discarded membership proofs
are never merged. Other errors remain failures. Range size/first changed offset
are logged without byte contents. All 229 offline checks pass. Live V18 sampling
and team/alive/visibility/aim integration remain pending.

## V18 reports: context changes before and during other-head capture

After restart, guest PID 2942 / host PID 14916 passed exact module/layout,
local managed/native head and 15 dictionary objects (one local plus 14 others).
The local sample was X=61.3005676 Y=12.7349987 Z=20.563179, attempt one. A
nonlocal model-cache head was resolved, but its enclosing membership snapshot
changed at dictionary+0x20, byte offset 4: the +0x24 free-list field. No other
XYZ was accepted. Other-phase calls=4475; total=23279. V18 printed Attempts=0
for the rejected row because its exception path lost the temporary result;
that zero does not establish that no native attempt occurred (progress shows
one). All cleanup stages passed.

The latest run (guest 3862 / host 14916) passed exact module/layout, managed
local head and 14 dictionary objects (one local plus 13 others). Native local
identity failed at 0x7dccf5f5d010, 8 bytes, first change offset 0; V18 does not
identify the field. Its first nonlocal member was rejected before native
capture because saved collection pointer/counters differed. Other-phase
calls=954; total=18300. All cleanup stages passed. No XYZ was accepted in this
run. An intervening GameIdentity ADB-exit-1 run stopped before plugin loading.

V19 revalidates the phase's exact dictionary/entry-array schema and each selected
member against fresh bounded counters, original exact entry bytes and object
identity. A changed earlier counter snapshot alone is no longer grounds to
reject a currently reverified selected entry. Changes during capture still
reject the pose, and no roster report is refreshed or merged. Native snapshots
add field labels without weakening validation. Rejected rows preserve actual
attempt counts. 241 offline checks pass; live V19 sampling and all team/alive/
visibility/aim integration remain pending.

## V19 live result and V20 selected-entry endpoint observation

V19 guest PID 4356 / host PID 14916 passed exact module/layout (80 checks twice),
managed local head and a native sample on attempt two after rejecting TRS motion
on attempt one. Local XYZ=68.11773,12.7306881,17.23389; hierarchy capacity=236,
parents=9, native observations=105. The dictionary had 14 used slots, 2 removed,
12 active/unique verified objects: one local and 11 others. A Watching object
was among them. Collection observations=122.

The first other member resolved its own 23-entry model-cache head and made one
native attempt, then failed the fresh counter recheck at dictionary+0x20,
first changed byte 4 (global free-list +0x24). CountersChangedSinceRoster was
true as well. This does not establish which entry was affected. No other XYZ
or membership proof was accepted. Optional-phase calls=5089; total=24501;
cache hits=3809. All cleanup stages passed.

V20 changes the optional phase's contract from global-header stability to
selected-entry revalidation with bounded endpoint counter audits. Two identical
16-byte copies are required at each endpoint; both must satisfy count/free-list/
capacity/index bounds. Different endpoint values are reported, while the exact
selected entry, storage pointers/classes/capacity, object and head/native
snapshots remain checked. Selected-member changes still discard the pose. This
is an observation without a lock or lifetime guarantee, not a stable full
collection snapshot. Native code and comparison rules are unchanged. All 248
offline checks pass. Live V20 nonlocal sampling and aim integration are pending.

## V20 first accepted live nonlocal head sample

Guest PID 4930 / host PID 14916 passed kernel/process, exact ARM64 module and
both 80-check runtime metadata rounds. Local native pose attempt one was
rejected for TRS motion; attempt two sampled X=61.3443565 Y=12.7355156
Z=18.2596149 (capacity=236, parent count=9, observations=105).

The observed dictionary had 17 used/active unique non-null candidate pointers,
zero removed slots and 16 validated objects under the cap: one local plus 15
others, including a Watching object. CompleteObjectValidation=False correctly
reported the one remaining unverified candidate. Collection observations=130.

Roster index 1, PlayerNetwork 0x7dccf362a000, resolved its own model-cache head
and passed native sampling and all membership/phase-final checks on attempt one:
X=47.085 Y=9.881877 Z=60.5796623, parents=9, per-object observations=315,
provider=0x7dccf3639d50, managed Transform=0x7dccf3626ce0. Membership proof was
SELECTED_ENTRY_REVALIDATED. Both counter-change flags were false; those endpoint
observations do not establish uninterrupted lifetime or absence of ABA changes.

The second member reached the sampling read ceiling during managed resolution,
with no native attempt or XYZ. Optional-phase reads=5691, stop=READ_LIMIT_REACHED,
accepted samples=1; the first result was retained only after reserved final
checks passed. Total reads=26352, cache hits=3978. Plugin unload, handler cleanup
and shared-session release all passed. This confirms one read-only nonlocal
head observation, not enemy/alive/line-of-sight classification or aim control.

No runtime package changed after this report. Static state-method/field research
is recorded separately in PLAYER-STATE-RESEARCH.md and is not a live state probe.

## V21 optional player-state probe (live validation pending)

The next package adds `-ProbePlayerState`, replacing optional nonlocal-head
sampling for that run. It attempts at most two verified roster members, local
first, reporting signed raw TeamIndex, canonical base-dead/pending-revive flags,
and supported original-branch really-dead/model-visible results. Active hotfixes,
null visibility storage and overridden visibility implementations are explicitly
unknown. Runtime field tables, base classes, code/registration and virtual slots
are validated alongside selected-entry and state snapshot rechecks.

The optional phase is capped at 6000 additional reads with 1500 reserved for
final checks, within the unchanged global 30000-read/120-second limits. Default
other-head sampling remains unchanged. 277 offline checks pass, including 29 new
state checks; there is no live V21 state report yet. Team/enemy policy, complete
alive eligibility, knockout and line of sight remain unverified. No aim writes
or game-function calls were added. See PLAYER-STATE-EVIDENCE.md in the mapper
package for the exact output and endpoint-observation contract.

## V21 first accepted live player-state samples

Host PID 14916 / guest PID 5609 passed exact kernel/process/module and both
80-check layout rounds. Local head attempt one was discarded for TRS motion;
attempt two sampled successfully. The roster verified all 15 unique active
objects (local plus 14 others) from 16 used slots and one removed slot.

The optional state phase accepted two PlayerNetwork rows, each with 128
observations and SELECTED_ENTRY_REVALIDATED. Both TeamIndexRaw values were 0,
and both BaseDeadRaw, PendingReviveRaw and original-branch ReallyDead values
were false. The local original-branch ModelVisible was true (mask 4294967295,
mode 0); the nonlocal value was false (mask 4294966779, mode 0).

CountersChangedSinceRoster was true for both members. During capture it was
false for local and true for nonlocal; selected-entry/object/state comparisons
and phase-final checks nevertheless passed. This remains endpoint evidence.
Stop=SELECTED_OBJECTS_EXHAUSTED, attempted=2, accepted=2, additional reads=4711,
total reads=24097. Plugin unload, handler cleanup and shared-session release
all passed. State mode correctly skipped optional other-head sampling.

Equal team indices do not establish teammate policy, and model visibility does
not establish line of sight. Combat eligibility, knockout, state transitions,
continuous tracking and aim integration remain unverified. No runtime source,
manifest or ZIP was changed for this documentation-only update. The previously
passed 277 offline checks were not rerun.

## V22 team-policy probe

The new `-ProbeTeamPolicy` mode validates the original GameFacade.IsSameTeam
route for one verified local/nonlocal pair. Static evidence shows a mode-58
faction branch and a CurrentMatchGame virtual policy branch. The supported base
MatchGame branch compares policy bytes obtained from player IDs, with an optional
dynamic-team dictionary redirection. Raw TeamIndex equality is not used.

V22 verifies original gates, settings selection/cache, both virtual targets,
runtime class and native hierarchy casts, registration/field tables and both
selected entries. It supports the original packed-byte route and the original
null dynamic-dictionary default. Non-null dynamic dictionaries, faction mode,
custom overrides, distinct CurrentGame/CurrentMatchGame objects and active
hotfixes return explicit unknown statuses. No hostility or attackability claim
is made from SameTeam=false. No game methods, initialization or writes occur.

317 offline checks pass (40 new policy cases). The optional phase retains the
6000-read ceiling with 1500 reserved for final checks within the existing global
30000-call/120-second bounds. Default head and V21 state modes remain available;
optional modes are mutually exclusive. The user's live V22 report subsequently accepted the original packed-byte route
in raw mode 23, with policy bytes 15 and 6 and SameTeam=False. Context and both
selected entries revalidated; counters changed since roster capture but not
during policy capture. Phase reads=5023, total=25950, cleanup all PASS. Fifteen
roster objects were verified. Local-head capture independently stopped with
NOT_READY_MOTION after three TRS changes. No aim write occurred.


## V23 combat-state probe

The optional -ProbeCombatState mode observes one verified nonlocal roster member,
with optional -CombatRosterIndex for an explicit current-run member. It validates
the original Watching Boolean (including the game-family branch without its
counter side effect), dead/revive flags, ghost predicate and IsDieing controller
branches. The selector, class layouts/ancestry, runtime fields/dispatch, code,
metadata, hotfix gates and exact selected entry are rechecked. One member keeps
the phase within the unchanged 6000-read allowance / global 30000-call limit.

385 offline checks pass (68 new cases). Baseline synthetic phase calls=4805.
Two live reports (host 11784 / guest 4901) accepted the same nonlocal player's
original watching, dead/revive, ghost and IsDieing=False in raw mode 23. Each
used 4736 additional reads. Totals were 23896 and 25519; all cleanup passed.
The rosters verified all 13 and 16 candidates, and local heads sampled on
attempts one and two respectively. This does not establish hostility, complete
combat eligibility, mode-zone rules, invulnerability, LOS or aiming. Existing
head, player-state and team-policy modes remain available and mutually exclusive.


## V24 zone/protection probe

The optional -ProbeZoneProtection mode samples one nonlocal member's original
CurrentTrainingZoneType, IsInBattleZone/IsInShootingRange and PlayerAttributes
IsInvincible predicate. It validates exact managed/unsafe replication-pool
interface dispatch, metadata and array/data types, attributes ownership,
mask/mode and original gates, then rechecks selected membership and inputs.

432 offline checks pass (47 new cases); baseline phase reads=5769 within the
unchanged 6000-phase/30000-global limits. V23 live evidence is preserved above.
Live V24 validation is pending. Complete damage immunity, combat eligibility,
hostility, LOS and aim integration remain unverified; no game write occurs.


## V24 live rejection and V25 array diagnostics

The first V24 report retried a repeated-node library traversal and exhausted the
read allowance (29818 total), accepting no zone/protection row. Its rerun reached
array verification, then rejected `zone array element type` (4091 phase calls,
23575 total, zero accepted rows). The rerun verified 14 roster members and
sampled the local head. Both reports completed all cleanup steps. No zone or
invincibility value is established by these reports.

V25 retains the predicate and adds failure-only expected/actual element indices,
array self/type flags/type-data pointers and four independent match indicators.
The details are UNVERIFIED_FAILURE_CONTEXT; they do not authorize property reads
or semantic output through a rejected array. 437 offline checks pass, including
five diagnostic cases. Baseline reads remain 5769 and all existing bounds remain
unchanged. Live V25 diagnostics are pending; no array-representation fix is claimed.


## V25 diagnosis and V26 runtime array correction

The V25 report isolated TypeDataMatch=False: managed pool type 36651 and element
36644 matched, with correct array self/type flags, while actual type data was
elementClass+0x20 rather than the expected ELF descriptor. It accepted no row,
used 22468 total reads and completed all cleanup.

The exact IL2CPP constructor at 0xa336514 establishes that runtime representation:
its SZARRAY branch stores the element class's embedded byval_arg in the array
class's type data. V26 pins the relevant constructor code/dataflow and requires
that exact pointer, with independent element metadata/class verification. The
old ELF expectation is rejected; declared pool-field ELF type validation remains
separate and unchanged. No alternate pointer fallback is added.

441 offline checks pass, covering both backends, pointer/descriptor failures and
constructor changes before/during capture. Baseline optional reads=5833, within
all existing limits. Extracted-package verification and reference reproduction
pass. Live V26 validation is pending; zone/protection, complete combat eligibility,
LOS and aiming are not claimed from the rejected V25 report.


## Accepted V26 zone/protection report and V27 policy probe

The user's accepted V26 run (host 11784 / guest 7882) verified all 15 roster
members and sampled the local head on attempt two. It accepted one mode-23
managed PRIDataPool sample: TrainingZone=0, InBattleZone=False,
InShootingRange=False, IsInvincible=False (mask 0, mode 1), with selected entry
revalidated and 240 observations. Counters changed during capture but selected
endpoint checks passed. Phase calls=5759, total=26518, all cleanup PASS. This
establishes the corrected array representation for one accepted snapshot.

V27 adds optional -ProbeMatchDamagePolicy. The original base MatchGame
CanTakeDamage implementation returns true without reading its three arguments
when gate 0x853d is inactive. The probe verifies actual slot-91 dispatch, metadata,
code, original gates, game/match/local context and both selected roster entries.
The custom MDHAFBELMFD override remains UNKNOWN; no game method is called.

465 offline checks pass (24 new cases); baseline phase calls=3402. Existing
limits, plugin and optional modes remain available. Live V27 validation is
pending. This method observation is not proof of a damage call site, complete
combat eligibility, hostility, weapon context, complete immunity, LOS or aiming.

## Accepted V27 live report

The user's report (host 11784 / guest 7882) passed module identity and both
80-check layout comparisons. All 13 active roster objects were verified; the
local head was sampled on attempt two. In raw mode 23 the selected original
CurrentMatchGame slot-91 method returned ORIGINAL_ARGUMENT_INDEPENDENT_TRUE.
Both selected roster entries revalidated. Counters changed since the earlier
roster snapshot but stayed unchanged during this capture. There were 154
observations, 3513 additional reads and 24286 total reads. Plugin unload,
handler cleanup and shared-session release all passed. No game method was called.
This is one match-policy predicate, not damage-processing or eligibility proof.
Separate reports are not combined into a simultaneous state observation.

## V28 local weapon-context probe

Optional -ProbeWeaponContext reproduces original active/hand selection and a
supported typed weapon-data reference for one verified local member. 496 offline
checks pass; baseline additional reads=4035. Existing plugin and limits remain
unchanged. Live validation pending; see ../bluestacks-process-map/WEAPON-CONTEXT-EVIDENCE.md.

## Accepted V28 live weapon-context report

The user's report (host 11784 / guest 7882) passed module identity and both
80-check layout comparisons. All 13 active roster objects (local plus 12 other
players) were verified. WeaponContext accepted ORIGINAL_WEAPON_DATA_REFERENCE_SAMPLED
through ON_HAND_CONTROLLER_A0, class COW.GamePlay.HBIBDMMOOOK, AlternateHand=False.
The data class was COW.GamePlay.IOKEALMHBKN with RESOLVED_OFFSET registration.
Selected local membership revalidated. Counters changed since roster capture,
but not during this weapon capture; 164 observations were recorded.
Phase reads=4430, total=26286; plugin unload, handler cleanup and session release
all passed. No game method was called or memory written.

All three local-head samples were discarded for TRS motion (NOT_READY_MOTION).
The accepted weapon reference does not imply an accepted head coordinate in
this run. V28 did not read a weapon-data ID, ammo, ballistics or firing readiness.

## V29 local weapon-data ID probe

-ProbeWeaponContext now checks the supported data record's original UInt32
GetId, including actual slot-14 dispatch, hotfix 0x21a65 and runtime +0x68 field.
509 offline checks pass. Live V29 ID validation pending. Plugin/global limits
unchanged; no method invocation or writes. No weapon-name/readiness inference.

## Accepted V29 live data-ID report

The user's report (host 11784 / guest 7882) passed module identity and both
80-check layout comparisons. All 15 active roster objects (local plus 14 others)
were verified. The local head sampled on attempt one. The weapon phase accepted
ON_HAND_CONTROLLER_A0 with HBIBDMMOOOK and typed IOKEALMHBKN data, resolved
registration, and WeaponDataId=41, ORIGINAL_GET_ID_UINT32_SAMPLED.
The selected local member revalidated; roster counters changed since the earlier
capture but not during the weapon capture. There were 172 observations,
4622 additional reads and 24342 total reads. Plugin unload, handler cleanup and
shared-session release all passed. No game method or write occurred.
This proves the raw data-ID path for that snapshot, not a weapon-name mapping,
ammo, reloading, firing readiness, LOS or aim integration. Head/roster/weapon
phases are sequential observations, not one atomic simultaneous snapshot.

## V30 selected-weapon reload predicate

-ProbeWeaponContext now verifies the selected weapon's original slot-216 reload
predicate through exact state-machine/current-state fields. 526 offline checks
pass; baseline additional reads=4988, A0 fixture=5477. Live validation pending.
This predicate does not establish Player.IsReloading, firing readiness or ammo.
Plugin and global limits unchanged; no game calls or writes.

## Accepted V30 live reload-predicate report

The user's report (host 11784 / guest 7882) passed module identity and both
80-check layout comparisons. Local head sampling passed on attempt one. The
first roster capture was discarded for a changed observation; the second
verified all 15 active objects (local plus 14 others). The A0 hand path accepted
HBIBDMMOOOK, typed IOKEALMHBKN data and original UInt32 data ID 41.
SelectedWeaponReloading=False accepted with StateRaw=2 and the original
selected-weapon predicate status. Selected membership revalidated; counters
were unchanged since roster and during capture. The phase recorded 226
observations, 5583 additional reads and 25735 total reads. All three cleanup
checks passed; no method invocation or writes occurred.
Reloading=False does not establish full readiness, firing state or ammo. The
head/roster/weapon phases remain sequential observations, not an atomic snapshot.

## V31 separate selected-weapon firing predicate

-ProbeWeaponFiring replaces other optional phases and verifies original slot 218
through the actual GameVar cache/state-ID branch. 583 offline checks pass; live
validation pending. Fixture additional reads=4803 (direct), 5292 (A0).
V30's mode/read costs remain available. All global limits/plugin unchanged.
No Player.IsFiring, readiness, ammo, LOS or aiming claim; no calls or writes.

## Accepted V31 live firing-predicate report

The user's report (host 11784 / guest 7882) passed module identity and both
80-check layout comparisons. Local head sampling passed on attempt three after
two discarded motion samples. The first roster capture was discarded for a
changed observation; the second verified all 14 active objects (local plus 13
others). A0 hand selection accepted HBIBDMMOOOK. SelectedWeaponFiring=False
accepted with the original selected-weapon status, Route=CACHE_BOOLEAN and
CacheEnabled=True. StateRaw=UNKNOWN is expected for this branch, which does not
read a state ID. The state-ID branch remains offline-tested, not live-validated.
Selected membership revalidated; roster counters were unchanged since roster
and during firing capture. There were 185 observations, 5030 additional reads
and 28692 total reads. Plugin unload, handler cleanup and shared-session release
passed. No methods or writes occurred. This is one selected-weapon predicate,
not Player.IsFiring, ammo, full readiness, LOS or aim integration. Separate
head/roster/firing phases are not an atomic simultaneous snapshot.

## V32 separate original weapon-counter probe

-ProbeWeaponAmmo verifies the nonvirtual Int32 +0x610 getter after unique runtime
FieldInfo binding among eleven unbound source candidates. 626 offline checks
pass; fixture additional reads=3870 (direct), 4359 (A0). Live validation pending.
All earlier modes, plugin and limits remain available. No magazine/reserve,
readiness, LOS or aiming claim. No calls, initialization or writes.

## V32 mixed live result: accepted counter, rejected head sample

Host 11784 / guest 9214 passed module identity and both 80-check layout passes.
All 15 active roster objects were verified on attempt one. The counter phase
accepted value 2, original Int32 getter, A0 hand path and unique runtime field
105 NJEENAEMFAO with RESOLVED_OFFSET. Selected membership and both counter audits
were stable. Phase observations=154, additional reads=4284, total reads=26986.
All cleanup checks passed; no calls or writes occurred.

The head phase did not pass: two TRS-motion attempts were discarded, then
Hierarchy.JobHandle changed during final identity verification on attempt three.
HeadWorldStatus=FAIL and no head coordinate was accepted. This report is not an
overall PASS. V33 changes the bounded retry/status handling for job-only changes;
it does not retroactively accept the rejected pose. Counter 2 remains a generic
original weapon counter, not a proven magazine/reserve or readiness value.

## V33 bounded native job-transition handling

Native-only rechecks defer precise job changes until every other identity has
been checked. A job-only transition discards the attempt; three shared attempts
and all call/time ceilings remain unchanged. Persistent changes are NOT_READY;
hard identity and transport errors still fail immediately. No coordinates from
discarded attempts are accepted. 635 offline checks pass; live validation pending.
