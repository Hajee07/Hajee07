# V30 selected-weapon reload predicate

V28 weapon selection/reference and V29 original data GetId passed live (reports
below). V30 reload-predicate validation also passed live (report below). Run
`Run-ProcessMap.ps1 -ProbeWeaponContext` with Free Fire and an equipped weapon.
The phase selects only a verified local roster member; it never substitutes a
nonlocal player. Existing optional modes remain mutually exclusive.

## Selection and data-ID proof retained

The builder verifies the established ELF/metadata SHA256 values. It records ten
fields, eleven complete method bodies/registrations, 209 exact class profiles,
106 data slot-45 profiles, one exact data slot-14 profile and 106 reload slot-216
profiles. Supported instance sizes are conventional exact registrations.

Player.GetActiveWeapon (0x6f17f74, gate 0x347) first tests Player+0x608 with
DEIPJDIGKIP (0x7399188, gate 0x345), a managed pointer comparison. Its fallback
GetWeaponOnHand (0x6f18290, gate 0x346) uses Player+0x740. The supported controller
GMOCOOEIFMK uses PDAGHPAOBLP (0x734b8d4, gate 0x286) and CKIKAFHOBDC
(0x734b930, gate 0x285): bool +0x148 selects +0xa8 or +0xa0. The original native
cast to HBIBDMMOOOK must agree with metadata ancestry. Direct active storage
must match GEBIDMLCOJO ancestry; alternate hand storage GEJIJAMODGH ancestry.

HBIBDMMOOOK.PLLDNGKJKKF (0x7452a90, gate 0x267b, slot 45) returns data +0x98.
Its instruction at 0x7452ac8 and full method establish the offset; the declared
data class is IOKEALMHBKN (31595). Unsupported dispatch overrides remain UNKNOWN.
The exact data GetId (method 209340, 0x6ee2628, length 0x50, slot 14, gate
0x21a65) reads UInt32 +0x68, JAOECECKADN local field 20. Actual dispatch, code,
registration, type flags and runtime FieldInfo must agree. GetUIntKey/GetIntKey
are separate methods and are not substituted. Zero and UInt32.MaxValue are
preserved without a guessed range or weapon-name mapping. The raw data record
ID does not establish a separate network weapon identifier.

## Reload predicate added in V30

Player.IsReloading (method 210849, 0x6f20e00) selects GetWeaponOnHand and invokes
slot 216. The base HBIBDMMOOOK method NNHIONEDFJP (225208, 0x74819c4, length
0x5c, gate 0x4c7) reads the weapon's OABOHNENNOA state machine at +0x90.
A null machine returns false. A nonnull machine calls MPJPIANCJAP (226517,
0x74e301c, length 0x50, gate 0x4b5): current state +0x18 must be nonnull, then
its state ID at +0x10 is loaded. NNHIONEDFJP compares that ID to 8.
The state getter GMAKPBMBIDP (226238, 0x74d846c, length 8) independently reads
+0x10. The enum KBEFFMEJNBE has Int32 underlying storage.

V30 reports only this original predicate for the independently selected active
weapon. It does not claim Player.IsReloading: GetActiveWeapon can return a
different item from GetWeaponOnHand. Scope is explicitly SELECTED_WEAPON_PREDICATE.
The actual slot-216 dispatch and registered metadata must match the selected
class. Only the base 0x74819c4 implementation is reproduced; custom overrides
(including GEJIJAMODGH's 0x73e9d80) remain unsupported. No virtual method is called.
The machine must be exact class 32884. Current states require supported 32859
ancestry, class identity/size and matching native parents. There are 74 supported
state classes plus one machine class. A null current state remains NOT_READY,
because the original state getter would fail; it is not interpreted as false.

Four specific opaque field registrations permit only their exact source value
0x81818181 or the proven resolved offset, with matching runtime FieldInfo:

| Owner / local field | Resolved offset | Native proof |
| --- | --- | --- |
| HBIBDMMOOOK / 18 PIILKNEHNLB | 0x98 | data getter 0x7452ac8 |
| HBIBDMMOOOK / 17 MCKDHCLGKLC | 0x90 | reload method 0x74819fc |
| OABOHNENNOA / 1 NEDIHEOKFLG | 0x18 | state getter 0x74e3054 |
| EPLELGNGHIM / 0 backing field | 0x10 | 0x74e305c and 0x74d846c |

No opaque value decoding or instance-size relaxation is introduced. Lazy field
tables remain NOT_READY and are never initialized. Reload and ID gates/statuses
are independent: an unknown reload result need not suppress a verified ID.
A hard inconsistency or a change during capture discards the tentative row.

## Bounds and validation

Code, metadata, registration, runtime fields, class ancestry, selected roster
membership and recorded reads are checked before acceptance. Initial and final
checks retain the phase's 6000-read limit, 1500 final-check reserve and global
30000-read/120-second limits. No VM pause, initialization, game-method invocation
or memory write occurs. Pointers apply only to the current process observation.

526 offline checks pass (17 new reload cases; all previous modes included).
The synthetic baseline uses 4988 additional physical reads; the live-observed
A0 route fixture uses 5477, including final checks. New cases cover state 8,
other/signed states, null machine versus null state, both hotfix gates, wrong
classes, lazy FieldInfo, exact offsets, actual virtual dispatch, derived/native
ancestry, changing state/gates and final code. Earlier tests retain selection,
ID, membership and global/phase budget coverage. References reproduce byte-for-byte.
Extracted-package checks verify C# 5 compilation/tests, PowerShell syntax and
seven exclusive modes, package integrity and all source/plugin digests.

Inspect WeaponContext, WeaponDataId, SelectedWeaponReloading and ResultFile.
SAMPLED_READ_ONLY alone does not imply every optional semantic is known: inspect
its specific status. Reloading=False is not a firing-readiness result. Ammo,
ballistics, firing state, readiness, damage processing, complete combat eligibility,
LOS and aiming remain unverified. No accuracy percentage follows from this probe.

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
