# V29 local weapon-data ID evidence

V28 weapon selection/reference passed live. V29 ID live validation is pending. Run `Run-ProcessMap.ps1 -ProbeWeaponContext`
with Free Fire running. This mode selects only a verified local roster member
and replaces the other optional phases. No nonlocal member is substituted.

## Exact original paths

The reference builder verifies the established ELF and metadata SHA256 values.
It records seven fields, seven complete method bodies and registrations, 134 exact
class profiles and 106 slot-45 dispatch profiles plus one exact data slot-14 profile. All supported instance sizes
are conventional exact registrations, not opaque values.

* Player.GetActiveWeapon, RVA 0x6f17f74, gate 0x347: test Player+0x608 using
  CDMMCIIFHGM.DEIPJDIGKIP (0x7399188, gate 0x345). This is a managed pointer
  nonnull comparison, not proof of a live native Unity object.
* If null, GetWeaponOnHand (0x6f18290, gate 0x346) reads Player+0x740.
  The supported controller is GMOCOOEIFMK (32430). PDAGHPAOBLP (0x734b8d4,
  gate 0x286) uses CKIKAFHOBDC (0x734b930, gate 0x285): bool +0x148 selects
  +0xa8 or +0xa0. The original native hierarchy cast to HBIBDMMOOOK is checked.
* HBIBDMMOOOK.PLLDNGKJKKF (0x7452a90, gate 0x267b, slot 45) returns +0x98.
  Its exact load instruction at 0x7452ac8 and complete method establish this
  offset. The declared data class is IOKEALMHBKN (31595).

The source field registration for PIILKNEHNLB is opaque 0x81818181. Only this
specific field permits that exact source value or resolved 0x98; both require
verified getter code and matching live FieldInfo offset 0x98. No opaque-field
value decoding or general instance-size relaxation is introduced. Null runtime
field tables remain NOT_READY and are never initialized by the probe.

The direct active field must match declared GEBIDMLCOJO ancestry; alternate
hand storage must match GEJIJAMODGH ancestry. Two recorded virtual overrides
remain unsupported, including GEJIJAMODGH's 0x73ea538 dispatch. A verified
weapon pointer can therefore coexist with UNKNOWN weapon data.

## Capture contract

The probe verifies code, registration, metadata, runtime fields, class ancestry,
actual virtual dispatch, inactive gates and selected roster membership. Captured
reads and endpoint checks must remain consistent. Initial and final code/schema
checks share existing state-reader machinery. Null controller/selected hand or
an original failed weapon cast produces ORIGINAL_NO_ACTIVE_WEAPON; null data,
unknown classes and active hotfixes have explicit distinct statuses.

The phase retains the 6000-read bound, 1500 final-check reserve and global
30000-read/120-second limits. No game method, VM pause, initialization or memory
write occurs. Pointers are observations for the current process only.

509 offline checks pass, including 44 weapon cases. The baseline synthetic
weapon fixture uses 4227 additional physical reads. Tests cover direct/fallback
selection, inactive-path short circuiting, all relevant hotfix gates, native
cast disagreement, virtual overrides, null storage, registration/runtime-field
disagreement, class identity, changes during capture, membership, final code
checks and read limits. Extracted-package checks also compile all earlier modes.

Inspect WeaponContext, WeaponSelection, WeaponDataReference, WeaponDataId and ResultFile.
ObservationStatus=SAMPLED_READ_ONLY alone does not imply a successful typed-data
result: inspect WeaponContext's specific status. Weapon IDs, ammo, ballistics,
firing readiness, damage processing, combat eligibility, LOS and aiming remain
unverified. No accuracy percentage follows from this snapshot.

## Original data GetId path added in V29

IOKEALMHBKN.GetId is method 209340 at RVA 0x6ee2628, length 0x50, virtual
slot 14. Its inactive-hotfix branch (gate 0x21a65) loads UInt32 +0x68 at
0x6ee2668. The registered field is JAOECECKADN, local index 20, offset 0x68,
with a UInt32 descriptor. Metadata, method pointer, full code, field registration,
runtime FieldInfo and actual slot-14 dispatch must agree. GetUIntKey/GetIntKey
are separate methods and are not substituted. Only the exact supported data
class is accepted; this build has no derived supported data class.

The raw value is logged as WeaponDataId with status ORIGINAL_GET_ID_UINT32_SAMPLED.
Zero and UInt32.MaxValue are preserved without a guessed range or weapon-name
mapping. This establishes the data record's original GetId value, not a claim
about a separate network weapon identifier or combat readiness. An active GetId
hotfix leaves the verified reference but reports UNKNOWN ID. A null runtime data
field table remains NOT_READY_DATA_FIELD_TABLE. Changes during capture discard
tentative values. No getter is invoked.

Thirteen additional checks cover original ID sampling, zero/full-width values,
hotfixes, lazy metadata, runtime/source offsets, field type, actual dispatch,
changing ID/gates, final getter code and the live-observed A0 path's budget.
The baseline direct-field fixture uses 4227 additional reads and the A0 fixture
4716, including final checks. All global and per-phase limits remain unchanged.

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
