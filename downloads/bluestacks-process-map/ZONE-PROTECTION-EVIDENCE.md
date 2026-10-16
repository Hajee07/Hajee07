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
