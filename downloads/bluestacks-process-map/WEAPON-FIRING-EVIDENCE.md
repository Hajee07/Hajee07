# V31 selected-weapon firing predicate

The cache branch passed live (report below); the state-ID branch remains
offline-tested only. Run `Run-ProcessMap.ps1 -ProbeWeaponFiring`.
This is an eighth, mutually exclusive optional mode. It replaces the data-ID /
reload phase rather than accumulating another phase near the read ceiling.
The previously accepted `-ProbeWeaponContext` remains available and unchanged
in observed read cost (baseline 4988; A0 fixture 5477).

## Exact original evidence

The reference builder checks the established ELF and metadata SHA256 inputs.
It independently derives ten field registrations/types and nine full methods,
and records actual slot-218 targets for 106 supported weapon classes. Runtime
class profiles are the same exact-build selection/state profiles used in V30;
GameVarDef identity uses the already verified team reference profile.

Player.IsFiring (method 211035, RVA 0x6f20e7c, length 0x84, gate 0x22fb) calls
GetWeaponOnHand and invokes weapon slot 218. The supported base method
HBIBDMMOOOK.NGGBEDBDEPA (225210, 0x7481a84, length 0xf4, gate 0x4c1) is the
predicate reproduced here. Actual runtime dispatch must match metadata and the
selected class profile. Custom overrides remain unsupported, not treated as
base behavior. No game method is invoked.

V31 selects the verified local player's GetActiveWeapon result using the
established original selection path. That can differ from GetWeaponOnHand;
therefore the result is only SELECTED_WEAPON_PREDICATE and PlayerIsFiring remains
UNVERIFIED. Player.IsFiring's own hotfix gate is not interpreted or bypassed to
claim its result. Its complete code records the semantic call-site evidence.

The base weapon predicate reads its state machine at +0x90; null returns false.
For a nonnull exact OABOHNENNOA machine, it reads COW.GameVarDef's static
EnableIsFiringCache (field 2021, Boolean +0x191d). The GameVar type cell is
0xac2f618, reached through GOT 0xa73f5a8. Class initialization must already be
complete; static extent and runtime FieldInfo must cover the field. The reader
never initializes metadata or invokes a static constructor.

* Cache enabled: return the machine's Boolean backing field at +0x20. A null
  current state and active state-getter gate do not affect this original branch.
* Cache disabled: gate 0x4b5 must be inactive. MPJPIANCJAP (0x74e301c) reads
  the nonnull current state +0x18 and its state ID +0x10. Supported class identity,
  exact sizes and native/metadata ancestry to EPLELGNGHIM must agree.
  GMAKPBMBIDP (0x74d846c) independently proves the +0x10 load.

The original state predicate is reproduced with UInt32 arithmetic:
`d = unchecked(raw - 3); (d < 13 && ((0x1f9f >> d) & 1) != 0) ||
(raw & 0xfffffffe) == 0x10`.
It is true for IDs 3,4,5,6,7,10,11,12,13,14,15,16,17. Other values are
preserved as raw Int32 bits without an invented state name. Cached storage is
accepted only for canonical Boolean bytes; other encodings invalidate the row.

Only four explicit opaque source registrations in this mode may remain
0x81818181 or become the proven exact offset: weapon local field 17 (+0x90),
machine local fields 1 (+0x18) and 2 (+0x20), and state local field 0 (+0x10).
Each requires exact metadata, descriptor flags, complete getter code and live
FieldInfo offset/name/type/owner/token agreement. No general opaque decoder or
instance-size relaxation exists. Null runtime tables remain NOT_READY.

## Capture and validation

The mode reuses current game/match/local, selected roster entry, class identity,
original selection gates/native cast, endpoint audits and repeated-read checks.
Code/schema are checked initially and finally. Changing membership, storage,
route, gates, metadata or code prevents accepting tentative values.
Bounds remain 6000 additional physical calls, with 1500 reserved for final
checks, and global 30000 calls / 120 seconds. No VM pause, initialization,
game-method invocation or memory write occurs.

583 offline checks pass, including 57 new firing cases. They cover every state
0..19, negative/full-width boundaries, both cache Boolean values, short circuits,
A0 selection, original/custom dispatch, nulls, hotfixes, lazy metadata, Boolean
encoding, wrong classes, derived ancestry, static extent, opaque/runtime offsets,
changing storage/routes/gates, final code, selected-member removal and budget /
prerequisite boundaries. Direct-field fixture additional calls=4803; A0=5292.
All 526 previous checks still pass, including unchanged V30 read costs.
Generated references must reproduce byte-for-byte. Release checks parse the
PowerShell runners, verify eight exclusive modes, compile as C# 5, execute the
full suite from the extracted ZIP and verify source/plugin digests.

Inspect WeaponFiringSamples, SelectedWeaponFiring, WeaponFiringMembership,
WeaponSelection and ResultFile. A sampled row may still contain an explicit
unknown predicate status. A true firing predicate does not prove ammunition,
shot completion, damage, full firing readiness, LOS or accuracy. ID/reload
results from earlier reports are not combined into a simultaneous observation.

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
