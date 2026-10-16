# Read-only Free Fire process-mapping probe

This probe uses the already tested native physical-read DLL and the kernel
extracted from the user's `fastboot.vdi`. It verifies live kernel bytes before
using the derived task/mm fields, locates the current ADB game PID, discovers
its page table, and walks its VMAs to verify an ARM64 `libil2cpp.so` load layout
against the inspected APK. Other matching Unity/metadata mappings seen before
the target are reported as observations.

**Current version: 28. Optional read-only local weapon-context probe.** Run with
`-ProbeWeaponContext` to reproduce original active/hand weapon selection for one
verified local roster member and inspect a supported typed weapon-data reference.
Hotfixes, overrides and unready storage have explicit unknown statuses. 496
offline checks pass; live V28 validation is pending. Ammo, ballistics, firing
readiness, LOS and aim integration remain unverified.
See [weapon-context evidence](WEAPON-CONTEXT-EVIDENCE.md).

**V27 match damage-policy mode passed live.** `-ProbeMatchDamagePolicy`
accepted the original argument-independent true predicate in mode 23, with both
selected members revalidated, 3513 additional reads and all cleanup passing.
This establishes one match-policy method result, not damage processing or
complete combat eligibility. See [policy evidence](MATCH-DAMAGE-EVIDENCE.md).

**V26 zone/protection mode passed live.** `-ProbeZoneProtection` accepted one
managed-pool sample in mode 23: zone 0, battle-zone/shooting-range false and
invincibility predicate false (mask 0, mode 1). Selected membership revalidated;
phase reads=5759, total=26518, cleanup all PASS. All 15 roster candidates were
verified. This validates the runtime array fix for that snapshot; complete
combat eligibility, damage immunity and LOS remain unverified.
See [zone/protection evidence](ZONE-PROTECTION-EVIDENCE.md).

**V23 combat-state mode remains available.** Use `-ProbeCombatState`, optionally
with `-CombatRosterIndex N`. Two live reports accepted watching/dead/revive/ghost/
IsDieing=False for the same nonlocal player in raw mode 23, using 4736 additional
reads each and all cleanup passing. All 13 and 16 roster candidates respectively
were verified; local-head sampling passed on attempts one and two. These
snapshots do not establish complete combat eligibility or LOS.
See [combat-state evidence](COMBAT-STATE-EVIDENCE.md).

**V22 team-policy mode remains available.** Run `-ProbeTeamPolicy` for one
local/nonlocal pair. The user's V22 Windows run reproduced the original
packed-ID-byte route in raw mode 23: SameTeam=False (bytes 15 and 6), with both
selected entries revalidated and all cleanup passing. This establishes one
observed pair and route, not hostility or attackability. The V22 run's three
local-head attempts were discarded for TRS motion; team validation still passed.
See [team-policy evidence](TEAM-POLICY-EVIDENCE.md).

**V21 player-state mode remains available.** Run with
`-ProbePlayerState` to sample raw team index, dead/revive fields and supported
original model-visibility behavior from at most two verified roster members.
It replaces the optional other-head phase for that run and preserves the same
global limits. Hotfixes, unsupported visibility overrides and null storage yield
explicit unknown statuses. This does not classify enemies, establish full alive
eligibility, or test line of sight. The user's V21 Windows run accepted two
state samples (local plus one nonlocal), using 4711 additional reads and 24097
total reads, with all cleanup passing. Both raw team indices were 0; local
model visibility was true and nonlocal model visibility false. This does not
establish team policy or LOS. 277 offline checks passed before release.
See [state evidence](PLAYER-STATE-EVIDENCE.md). That live report did not change
the V21 runtime ZIP.

**V20 live nonlocal sampling passed.** The user's
latest V20 run sampled the local head on attempt two and one nonlocal
PlayerNetwork head on attempt one, with SELECTED_ENTRY_REVALIDATED and all
phase-final checks/cleanup passing. The nonlocal XYZ was
47.085, 9.881877, 60.5796623. This is one read-only observation.

The dictionary had 17 unique candidate pointers; the configured cap verified
16 (local plus 15 others), so CompleteObjectValidation=False was expected.
The second head attempt stopped at the read ceiling; it produced no XYZ.
Optional-phase calls=5691; total=26352. No limit was exceeded or increased.

V20 distinguishes selected-entry verification from a whole-collection snapshot.
It audits bounded counters before and after capture, using two identical quick
copies at each endpoint. Differences between those two endpoints are reported
as CountersChangedDuringCapture; they do not alone invalidate the selected
entry. The exact selected 40-byte entry, dictionary/array identity and capacity,
object class/local marker, head provider/Transform and native hierarchy still
must pass all snapshot checks. If the selected member or storage changed, its
pose is discarded. The endpoint headers must both be valid and cover the
selected slot. No full roster is refreshed or claimed stable. See
OTHER-HEAD-EVIDENCE.md for this revised observation contract and its limits.

Accepted membership is labelled SELECTED_ENTRY_REVALIDATED. No lock, GC root,
VM pause or lifetime guarantee is provided. Native comparisons, motion retries,
phase-wide exact schema/code checks and read limits remain unchanged. At most
two nonlocal members are attempted, with a 6000-call outer ceiling and 1000
reserved for final checks, within the same 30000-call/120-second global bounds.
The reported V20 live success covers one nonlocal sample,
not all candidates or continuous tracking. See [the state research](PLAYER-STATE-RESEARCH.md)
for the original static evidence and its unresolved semantics.

Complete team/alive/line-of-sight semantics and aim writes remain unimplemented.
No target classification is inferred from these samples.

Extract the complete ZIP into a new folder. Start the Pie64 instance, enter
Free Fire Training Ground, wait until the character has spawned, and leave it
standing while the probe runs. Run in 64-bit Administrator Windows PowerShell:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-ProcessMap.ps1
```

For the new V21 state probe, use:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-ProcessMap.ps1 -ProbePlayerState
```

For the new V22 team-policy probe, use this separate mode:

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\Run-ProcessMap.ps1 -ProbeTeamPolicy
```

Use one optional mode per run. `SameTeam=False` does not establish hostility or
combat eligibility. Unknown route results identify the remaining dependency.

The selected ADB serial defaults to `127.0.0.1:5555`; `-Device` can select the
endpoint displayed by BlueStacks. An explicit disconnected localhost endpoint
is reconnected once and verified. Other devices are not selected automatically.
The runner discovers the current host/game PIDs; old PIDs are not constants.

The package checks DLL and all seventeen runtime C# source digests, plus the exact
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
workflows for offline regression checks. The Windows runner uses
`ProbeModuleWithRetry`, which calls the same module verifier at most twice.
A repeated node, inconsistent traversal order or inconsistent backlink in the
outer traversal can trigger one retry. The discarded
attempt's node/mapping counts and cumulative reads are logged. Process identity
is rechecked, the translation cache is cleared, and the next attempt starts at
`mm.mmap` with fresh visited-node and file-name dictionaries. It uses the same
Reader, so the 30,000-read and 120-second budgets are never reset. A repeated
node on attempt two fails. Node limits, invalid ranges/alignment/user bounds, module-window failures,
fingerprint mismatches, read failures, and identity changes are not retried.
The retry does not establish why a node repeated or make the live scan atomic.

The next stage compares 80 registration/code references twice. It checks the
runtime-relocated pointer values separately from raw data and compares selected
field offsets, type descriptors, type sizes, and method/instruction bytes. These
references come from the exact SHA-256-checked metadata and ELF inputs. It does
not dereference player objects or call any game method. The global budgets are
shared with the preceding scan; process identity is rechecked between rounds.

Version 8 keeps 71 exact registration/code comparisons. For the nine type
descriptors it checks all four attribute/kind bytes, validates the runtime user
pointer, and derives a metadata base by subtracting the known type index times
88 and the type-table file offset. All nine descriptors must agree on this base
across both rounds. The 256-byte runtime metadata header must match an explicit
build profile: first words exactly zero and 24 (observed in v9), with bytes
8..255 exactly matching the SHA-256-verified decoded metadata. Each complete
88-byte type record must also match the decoded input reference. The original
file header and source hashes are retained separately; they are not rewritten
or treated as interchangeable with the runtime representation. The
descriptor is reread after its target to reject observed pointer changes.
The shared physical-read/time budgets and page-table/RAM checks apply to these
bounded target reads. No player-object pointer or game method is followed.

Version 7's nine runtime pointers all yield the same candidate metadata base;
its static index-to-pointer comparison was invalid for that representation.
Version 8 does not accept a pointer merely because it looks plausible: wrong
flags, headers, records, inconsistent bases, unresolved indexes, and changed
descriptors fail verification. A successful run verifies the sampled metadata
records, not a whole-runtime metadata SHA-256 or live player objects.

Mismatches are reported while the remaining fixed checks continue in both
rounds. GameLayoutDifference records retain bounded expected/actual bytes;
for descriptors, ReferenceEncoding=ON_DISK_TYPE_INDEX labels the file reference,
while Reason identifies the failed runtime validation. TypeMetadataDifference
reports up to 32 bytes at the first header/record difference. V10 compares the
bounded type record even when its header fails, so both differences can be
reported in one run. This does not allow a mismatched header to pass. Any mismatch still
fails registration verification, even if it later disappears. Read, translation,
identity and budget errors stop immediately. Differences reported before a
failed process recheck are provisional. These are non-atomic samples; identical
rounds do not prove uninterrupted stability.

The task scan is bounded to 2048 nodes and the VMA scan to 4096 nodes. Only the
selected game's Unity/IL2CPP/metadata mapping names and ranges are logged. Game
arbitrary object contents are not printed; the native stage exposes only the sampled local-head XYZ. Multiple read calls are not an atomic snapshot;
the probe does not take guest kernel locks or hold task/mm references. List,
translation, and identity rechecks detect observed changes, but cannot eliminate
all lifetime races. Restart the probe after a reported inconsistency with the
game left running.

A successful result includes `KernelIdentity=PASS`, `ProcessMap=PASS`, and
`GameLibraryRead=PASS Name=libil2cpp.so Architecture=ARM64`, followed by
`GameModuleIdentity=PASS`, `RuntimeTypeMetadata=PASS`, then
`GameLayoutRegistration=PASS`. The first four stages were observed on Windows with version 5; registration
subsequently passed in V10 and the managed-head path passed in V13. The runner rechecks the ADB PID and process identity before success.
Exit code 1 means a stage or cleanup failed.
Share the complete `ResultFile` report even after a failure; individual stages
remain distinguishable.

See `LAYOUT-EVIDENCE.md`, `MODULE-EVIDENCE.md`, and `GAME-LAYOUT-EVIDENCE.md` for
derivation and provenance.
The generated module reference contains only selected header/sample bytes and
layout constants. No uploaded VDI, extracted kernel, full APK/library, or
Oracle/BlueStacks system binaries are included in this package.

## Offline checks

223 checks passed using PowerShell 7.4.6 with C# 5 language compatibility.
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

Thirty-one additional module checks use the exact APK reference bytes with synthetic
mappings. They distinguish a whole-file mapping from the PT_LOAD layout, reject
incorrect tables/build ID/code/file offsets/names/gaps, detect changes during
verification, and exercise the 128-VMA window boundary. The normal module fixture
uses 681 reads and nine window VMAs; these are offline measurements. Reference
generation reproduces identical bytes and rejects an incorrect source digest.
Seven retry assertions cover recovery after a transient repeated node, cumulative
reads and discarded results, persistent repetition, identity changes, no retry
on fingerprint failure, shared budget exhaustion, and the 4096-node outer limit.

Thirty registration checks validate matching relocated data and reject altered
field offsets, relative-RVA-as-pointer mistakes, method bytes, between-round
changes, and process/profile mismatches. The registration fixture uses 1324
reads. Diagnostic regressions cover descriptor byte reporting, stable mismatches
in both rounds, later mismatches after the first, changed observations, and
failure without a logging callback. Runtime metadata tests cover two derived
bases, exact records/headers/flags, unresolved indexes, inconsistent tables,
changed pointers, and rejection of kernel-space pointer values. Five more
assertions reject the decoded file prefix at runtime, a wrong runtime version,
a changed table offset, and a changed final header byte, and verify that header
and type-record differences can both be reported without accepting either. The metadata decoder validates all recovered records, reproduces the
same JSON/C# reference, and passes five malformed-input checks. These checks do
not establish live object layouts or aim behavior.

Reproduce with the extracted ELF available locally:

```powershell
.\Run-CoreTests.ps1 -KernelElfPath C:\path\to\vmlinux
```

The 48 object checks cover exact class/metadata identity, supported derived
Player ancestry, original-path hotfix gates, null/unresolved state, wrong local
flags, changed pointers/mm, code samples, head interface dispatch, Transform
identity, and interface/vtable bounds. The complete valid object fixture uses
2144 physical reads and 114 bounded observations. These are offline measurements.

Tests validate the reader against controlled fixtures. They do not establish
live Windows COM behavior, runtime object lifetime, or a working aim lock.

## Version 11 local-player and managed head Transform stage

After metadata validation, the runner checks 71 additional exact code/GOT
references and follows the original CurrentLocalPlayer path. Four relevant
hotfix entries must be inactive. It validates CurrentGame as MatchGame or a
supported derived class, then the current match and the locally marked Player.
Classes must match exact metadata records, by-value types, names/namespaces,
self pointers, tokens, supported runtime-size rules and runtime parent chains. The supported
profile contains 105 normal class profiles plus String/generic-definition records derived from the exact metadata, not live addresses.

If the head getter's hotfix entry is active, this is reported separately and the
head-provider path is not followed. Otherwise, a non-null provider must match
one of the three exact interface implementations. Its interface entry and
vtable target must resolve to the original eight-byte get_transform function.
That getter returns provider+0x10, which must identify UnityEngine.Transform.
When the lazy provider is null, version 13 also searches the model cache for an
already cached bone_Head entry. A missing cache/key or null Transform is a
distinct NOT_READY status. No managed or
native game function is called to initialize them.

A successful result includes `LocalPlayerObjects=PASS` and, when ready,
`ManagedHeadTransform=MANAGED_TRANSFORM_VERIFIED`. These identify an observed
local-player chain and managed head Transform, not world coordinates, other
players, line-of-sight visibility or working aim updates. All object observations
are reread before returning; code and process identity are also rechecked.
The object snapshots are bounded to 1024 ranges/64 KiB, parent walks to 16 links,
and interface scans to 64 entries and the exact class count. Shared global read
and elapsed-time budgets remain unchanged. The scan remains non-atomic and
holds no GC roots or guest locks; observed changes fail the run.

## Version 12 diagnostics and traversal recovery

Two user v11 runs reached different stages. One stopped at an outer VMA
inconsistency after 945 valid entries. A later run passed module and both metadata
rounds, then failed the combined IFix class token/instance-size comparison.
Neither report establishes the cause of the class mismatch; no object-chain
success was returned.

V12 distinguishes INVALID_RANGE, USER_RANGE, PAGE_ALIGNMENT, VMA_ORDER and
VMA_BACKLINK, with the offending node and range/link fields. Only outer order,
backlink and repeated-node failures can restart once; each new attempt must pass
all original checks under the same cumulative read/time budgets.

V11's reference generator incorrectly treated six opaque initial native-size
values as exact runtime sizes. For IFix the raw initial size is 0x81818099;
that is not a plausible instance size. V12 preserves the raw reference for audit
and marks it untrusted. Plausible native sizes remain exact checks. The six
opaque cases use bounded runtime sizes sufficient for the instance fields that
the probe accesses. IFix's declared instance fields independently require at
least 40 bytes; its runtime size must be between that and 1 MiB. Derived game
classes must cover their verified base storage. The interface type retains its
valid zero instance-size profile because it is not dereferenced as an instance.

For IFix, the runtime field table must independently identify wrapperArray: its
complete field metadata record, name pointer, declaring class, token, array type,
static offset zero and storage extent all have to match. The field table is
indexed with the exact 32-byte field-info stride. Runtime static storage must
cover the eight-byte reference and remain within 64 KiB. No opaque static-size
value is used as an expected allocation size.

Class token and size failures now report separately. ObjectClassSizeObservation
records bounded runtime sizes; ObjectClassLayoutDifference reports expected and
actual class data on failure. This is a reference-generation correction, not
proof by itself that the live object chain passes. The subsequent V12 report
verified the local-player chain, and V13 verified its cached managed head.

## Version 13 model-cache head lookup

The v12 Windows run verified the local PlayerNetwork object and its parent chain,
but Player+0xa00 was null. V13 follows the original getter's underlying cache
read path without calling its initialization code. It verifies virtual slot 29
and the additional hotfix gates, then reads Player+0x1530 (LBJCFPMCLMN) and its
Dictionary<string,BFOONIGAIFK> at +0x10. It validates the exact closed generic
identity/arguments and metadata before scanning at most 512 used entry slots for
an exact UTF-16 bone_Head key. Removed slots are skipped; duplicates fail. Array
capacity is bounded to 8192 and string lengths to 256 characters. Snapshot and
global read/time limits can stop the scan earlier.

A cache hit must identify a BFOONIGAIFK node, after which the existing interface
and managed Transform checks still apply. A miss never invokes Unity lookup,
creates a node, writes either cache, or substitutes the model root. Exact-name
linear lookup does not reproduce custom comparers or prove bucket/hash integrity;
it verifies the observed active entry and its managed Transform. Dictionary data,
version, class context, key and result pointers join the final snapshot recheck.

On success the report includes HeadCacheLookup ... Key=bone_Head Matches=1 and
ManagedHeadTransform=MANAGED_TRANSFORM_VERIFIED Source=MODEL_DICTIONARY.
The former is provisional until the final checks and result line succeed.
Null model/cache, missing key, active lookup hotfix or unsupported virtual target
are distinct statuses. A matching non-null Player cache keeps Source=PLAYER_FIELD.
The synthetic fallback fixture takes 2825 reads and 169 observations. Thirteen
new tests cover the hit/miss path, removed/duplicate entries, bounds, wrong types,
version changes and hotfix/virtual-target guards. The V13 Windows report subsequently passed this lookup and managed-head
verification; native position validation remains pending for V15.

## Native position results

`LocalHeadWorldPosition=SAMPLED_READ_ONLY` reports the local head XYZ and parent
count from a bounded, twice-observed native hierarchy. `NOT_READY_*` means the
corresponding prerequisite was absent; the probe does not initialize an icall,
wait on an engine job or call Unity. `FAIL` includes the failed check and sets
the runner's exit status to 1 while preserving earlier completed observations.
Leave the character standing in Training Ground and share the complete result
file. Character animation can invalidate a position snapshot; a failed sample
does not establish a new layout or authorize weakening identity checks.

There are 223 offline checks: 51 core/kernel, 31 module, 30 metadata and 111
object/native-head checks. These include an independent quaternion matrix
oracle, cross-axis rotations, nonuniform/reflected scales, invalid backlinks,
cycles, bad bindings/code, pending jobs and changing position data. They do not
substitute for the Windows run.

`NativeHeadSampleAttempt` identifies each bounded fresh attempt, and
`NativeHeadSampleMotion ... Discarded=True` identifies a changed selected TRS
record. Only that motion condition is retryable; code/identity, link, read,
translation, numeric and budget failures stop immediately. A failed third
attempt emits no coordinates. Success includes Attempts and CaptureChunks.

Code/identity snapshots are rechecked before and after the two position-data
copies. Each copy reads at most 128 selected 48-byte rows, coalescing gaps of at
most 192 bytes into blocks no larger than 4096 bytes (at most 32 KiB fetched per
pass). Gap bytes are never used as transform data or compared for stability.
Every selected 48-byte row must match exactly between the two passes. There is
no floating-point motion tolerance, stale-pose reuse or VM pause. The position
capture is still non-atomic, and continued animation can exhaust all attempts.

## V16 match collection

The report adds MatchPlayerDictionary with used/removed/active/null counts,
unique candidate pointers, verified players, local membership and
CompleteObjectValidation. At most 16 unique candidates are checked as Player
objects; local is checked first when present. MatchPlayerObject lines report
only objects that passed class/parent/local-marker and final snapshot checks.
Candidate pointers outside the verified subset remain unverified. A full scan
of the used dictionary slots does not mean every candidate object was checked.

The reader checks the original getter's hotfix gate (0x1bf); an override returns
HOTFIX_ACTIVE_COLLECTION_GETTER. Null and empty collections have distinct
statuses. A failed collection stage reports MatchPlayerDictionaryError and exit
code 1, preserving earlier completed observations. No other-player world
position, target selection or aim write is performed. Leave the character
standing in Training Ground and share the complete ResultFile.

## V17 other-head result

OtherHeadSamples reports verified eligible members, attempted rows, successful
coordinate samples and StopReason. At most two objects are attempted; this does
not sample the whole roster. Each OtherHeadWorldPosition line identifies its
roster index, class and object address. XYZ appears only on SAMPLED_READ_ONLY.
NOT_READY, hotfix, context-change and read-limit statuses are distinct. Failed
rows emit no coordinates. Final phase code/process checks must pass before any
other-head rows are returned. Earlier local/collection results remain visible
if this optional phase fails.

The same Reader is used throughout. A nested physical-call scope allows at most
5000 reads for initial checks/sampling and keeps 1000 for final checks, with an
overall additional cap of 6000 or the remaining global allowance, whichever is
smaller. At 29000 total calls or above, the optional phase skips without reading.
Nested scopes cannot expand an existing limit; disposing a scope restores its
previous allowance without resetting counts or the elapsed timer.

The collection counter header, array identity/length and exact saved 40-byte
entry must still match. Game/match/local-player links, the selected class/local
marker and original-path hotfix gates are also checked. All selected context and
managed-head observations are rechecked after native capture. Samples are
separate non-atomic observations; they do not form a synchronized frame and do
not establish team, health, line of sight or suitability as a target.
