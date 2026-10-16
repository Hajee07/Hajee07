# V24 zone and protection observations

Run `Run-ProcessMap.ps1 -ProbeZoneProtection` after spawning in Training Ground.
The first verified nonlocal roster member is sampled. Optional `-ZoneRosterIndex N`
selects a nonlocal member from that run's capped roster (0 through 15). Indices
are rediscovered each run, not persistent player identities. Other optional modes
are mutually exclusive and remain available. Live V24 validation is pending.

This establishes original zone/getter predicates and PlayerAttributes.IsInvincible
for one accepted snapshot. It does not establish complete combat eligibility,
hostility, complete damage immunity, weapon restrictions or actual LOS. A false
invincibility predicate alone does not prove the player can take damage.

## Exact original zone path

Player.get_CurrentTrainingZoneType, method 212886 / RVA 0x6f359e4, first checks
IFix gate 0x2558. Its original path calls GameFacade.IsOfflineTrainingMode,
method 35231 / RVA 0x71d6858 / gate 0x2557. That original helper compares the
original GameServerGameMode getter (gate 0x10a) with 301. If equal, the zone getter
returns 3 without reading the player's pool. All other modes, including the
observed mode 23, use the player's replication-data pool.

Player inherits GCommon.ReplicationEntity through AttackableEntity and
COWReplicationEntity. The declared m_PRIDataPool field is instance +0x70 on
ReplicationEntity, not the unrelated static Player event with the same numeric
offset. V24 verifies the full relevant runtime parent chain and declaring field.
A null pool returns original zone zero.

For a non-null pool, original code invokes IRepDataPool.GetDataUInt8(37).
Supported concrete classes are PRIDataPool and PRIDataPoolUnsafe. Both use
IRepDataPool interface offset 49 and slot 60 (49 + interface-method slot 11).
V24 verifies the interface root/record, native interface count/table/uniqueness,
exact metadata interface offset and vtable entry, runtime target, method
registration/metadata/code and the concrete/base class chain. It does not call
an interface function or trigger lazy class initialization. Other implementations
return UNSUPPORTED_POOL_CLASS.

The two inspected getters use signed m_MaxVarCount at pool+0x18. If property 37
is outside that count, they return zero without accessing the data array.
Otherwise the array at +0x10 must cover slot 37. A null entry returns zero.
V24 validates the declared SZARRAY descriptor, resolved element type, runtime
array class/element and capacity before accessing the selected element.

The managed backend requires ReplicationData and reads byte data+0x18. The
unsafe backend requires ReplicationDataUnsafe, reads its Value pointer at +0x18,
then the pointed-to byte. A null unsafe pointer is UNKNOWN rather than zero.
The pointer and byte must be readable and unchanged at endpoint recheck; no
allocator/lifetime guarantee is claimed. Array/count bounds are capped at one
million and never broadened to accommodate an invalid capture.

The original Player.get_IsInBattleZone (RVA 0x6f35990, gate 0x44d2) compares that
zone with 2. get_IsInShootingRange (RVA 0x6f35b14, gate 0x3f0c) compares it with 3.
Each dependent Boolean stays UNKNOWN if its original gate is active. Zone bytes
are not range-clamped; other byte values simply fail these two comparisons.
These are the named getters, not the entire mode's permission-to-damage policy.

## Exact original invincibility predicate

The declared Player field IODLOCEJIOK at +0x768 points to PlayerAttributes.
V24 supports the exact PlayerAttributes class (type 34539), verifies its layout,
field table and owner at +0x20, and requires the owner to be the selected player.
Missing/unsupported attributes return explicit UNKNOWN status.

PlayerAttributes.IsInvincible, method 246131 / RVA 0x7c2f324 / gate 0x49c2,
reads its KNODCJBPNAB BitArrayBoolean reference at +0x2b0 and directly calls
GetBooleanValue, method 266309 / RVA 0x82796d0. V24 pins that actual getter,
not just the similarly behaving op_Implicit used by model visibility. The exact
BitArrayBoolean and BitArray parent classes/fields must match. A null mask is
UNKNOWN. The original expression is mode == 1 ? mask != 0 : mask == 0xffffffff.
Mask and mode are unsigned 32-bit values, independently captured/rechecked.
An active gate suppresses this semantic result. No setter, method or write runs.

The builder checks the existing complete ELF/metadata SHA-256 values and emits
13 fields, nine methods, 13 class profiles, two pool dispatch/element profiles,
and all code/GOT anchors. Field registrations, metadata, type descriptors and
runtime FieldInfo must agree. Matching method names alone are insufficient.

## Snapshot and limits

V24 uses the existing selected-entry state snapshot. Current game/match/local,
dictionary/array identity and capacity, exact selected 40-byte roster entry,
class/local role, original context gates, mode and new input observations are
checked again. Counter headers require two equal copies at each endpoint.
Changes since the roster or across endpoints are reported separately; the
selected member/fields still must remain exact. No whole-roster stability,
atomic snapshot, VM pause, GC root or lifetime/ABA guarantee is claimed.

A failed row recheck discards all tentative zone/protection values. Final
schema/code failure discards all rows. Known unsupported/not-ready paths can
report independent verified values, but never invent a missing predicate.

The optional phase stays within 6000 additional physical calls, with 1500
reserved for final checks, inside the unchanged global 30000-call/120-second
limits. The baseline unsafe-pool fixture uses 5769 calls. A run with less
remaining budget can return partial/not-ready status instead of increasing
limits. Other-head, combat-state and team-policy phases are not also requested.

## Validation

432 offline checks pass, including 47 new zone/protection cases. They cover
both data backends with bytes 0/1/2/3/255, mask/mode branches, mode-301 and signed
count short circuits, null pool/data/pointers/attributes/masks, each original
gate, owner mismatch, exact managed/unsafe dispatch, metadata interface offset,
array/declared element types, changed zone/protection/member, final schema
rejection, explicit selection and read-budget boundaries. All prior modes are
compiled and tested in the same C# 5 suite.

Reference generation must reproduce byte-for-byte. The extracted release is
checked for PowerShell syntax, five mutually exclusive parameter sets, source
manifest/plugin hashes, ZIP integrity and the same compiled tests. Live Windows
validation is still required. Send the complete V24 report including
ZoneProtectionSamples, TrainingZone, InvincibilityPredicate and ResultFile.

## V24 live results and V25 diagnostics

The first V24 user run retried library traversal after a repeated VMA node.
That run exhausted the optional read allowance before accepting a zone sample:
READ_LIMIT_REACHED, Sampled=0, total calls=29818. A rerun without a library retry
reached array verification, then failed `zone array element type`; Sampled=0,
phase calls=4091, total=23575. The rerun verified all 14 roster candidates and
accepted the local head on attempt one. Both runs completed plugin unload,
handler cleanup and session release. No zone/protection value was accepted.

V25 retains the same acceptance predicate and adds failure-only
ZoneArrayDiagnostic details. It reports the concrete pool type, array and element
class pointers, expected/actual element type indices, array self pointers,
Il2CppType bits and type-data pointers. ElementMatch, SelfMatch, BitsMatch and
TypeDataMatch identify which component failed. Comparisons with the observed
element class/byval-argument addresses are included without accepting either
alternative representation. No unknown pointer is dereferenced to guess its type.

Diagnostics are explicitly labelled Observation=UNVERIFIED_FAILURE_CONTEXT.
They describe the reads that failed validation, not an accepted stable snapshot.
As before, a failed row discards all tentative semantic values and never reads
property 37 through the rejected array. An earlier class-record/layout error can
still stop before this diagnostic. This is instrumentation for the next live
report, not a claimed correction of the array representation.

437 offline checks pass (five new diagnostic cases). Independent changes to each
of the four checked components remain rejected, expected/actual details survive
in the failure message, semantic values are discarded, and the alternative
byval pointer remains rejected. The successful baseline still uses 5769 calls.
The five existing modes, bounds and reference files remain unchanged. V25's
extracted package is checked with the same syntax, manifest and compiled suite.
Send the full output, especially the ZoneArrayDiagnostic failure detail.

## V25 live diagnosis and V26 correction

The V25 live report identified exactly one failed component. For managed
PRIDataPool (type 36651), element type 36644, class identity, self pointer and
SZARRAY bits matched. TypeDataMatch alone failed: the observed type-data pointer
was elementClass+0x20 (TypeDataEqualsElementByvalArg=True), rather than the ELF
Il2CppType descriptor address V24/V25 expected. No row was accepted. Total reads
were 22468 and all cleanup passed.

V26 corrects that probe expectation using the inspected IL2CPP array constructor
at RVA 0xa336514. Its entry saves element-class argument x0 as x21 (0xa336544).
The constructor loads its array-class allocation from sp into x23 (0xa3366c4),
computes x22=x21+0x20 (0xa336710), and stores x21 as the array element_class at
arrayClass+0x40 (0xa33675c). On the SZARRAY branch it writes type 0x1d at +0x2a
(0xa3367ac/0xa3367b0), reloads the same allocation as x19, and stores x22 at
arrayClass+0x20 (0xa3367b8). Thus this array's runtime Il2CppType.data points to
the validated element class's embedded byval_arg, not the ELF descriptor.

The builder verifies the key instructions against exact words after the full
input SHA checks and emits six additional live code anchors for the argument,
allocation alias and constructor dataflow/branch. These anchors are checked
before capture and at phase end. The new rule requires typeData ==
elementClass+0x20; it does not accept both representations or bypass other checks.
The element class's own embedded byval data/flags, metadata record, name/token,
self identity and extent remain independently verified by ZoneClass. Expected/
actual diagnostics remain available and now name ELEMENT_CLASS_BYVAL_ARG.

The ELF element descriptor still correctly describes the declared pool array
field. ZoneSchema continues to validate that distinct field descriptor and its
resolved element metadata. It is only the runtime array class's type-data
expectation that changes. Rank/type flags, interface dispatch, data element,
owner, masks, code/schema and snapshot checks remain required.

441 offline checks pass. Both managed and unsafe positive fixtures now use the
constructor-established representation. The old ELF pointer, an element class
pointer, neighboring byref member, invalid embedded descriptor, incorrect type/
self/flags and changed constructor code remain rejected. A constructor-code
change during capture discards all tentative values at final verification.
The baseline optional phase uses 5833 calls inside the unchanged 6000 limit;
global 30000-call/120-second bounds and the 1500-call final reserve remain.
Reference outputs reproduce byte-for-byte, and the extracted package is parsed,
compiled/tested and hash-checked. Live V26 zone/protection validation is pending;
no combat eligibility, damage-immunity or LOS result is claimed.

## Accepted live V26 report

The user report (host PID 11784 / guest PID 7882) passed exact module/layout and
all 15 roster candidates (local plus 14 others). Local head sampled on attempt
two after a discarded TRS change. The zone/protection phase accepted one
PlayerNetwork at roster index 1 in raw mode 23, with managed PRIDataPool.
TrainingZone=0, InBattleZone=False, InShootingRange=False and original
PlayerAttributes.IsInvincible=False (mask 0, mode 1). Both original getter/
predicate statuses and SELECTED_ENTRY_REVALIDATED passed with 240 observations.

Counters changed since roster capture and during the optional capture, but the
selected entry/input endpoint comparisons passed. The phase used 5759 additional
reads and 26518 total, with plugin unload, handler cleanup and session release
all PASS. This validates V26's corrected runtime array representation in one
accepted managed-pool snapshot. It does not establish complete combat eligibility,
damage immunity, LOS or continuous tracking; no aim write occurred.
