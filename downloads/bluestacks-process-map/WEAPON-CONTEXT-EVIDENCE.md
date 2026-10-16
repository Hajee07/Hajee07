# V28 local weapon-context evidence

Live Windows validation is pending. Run `Run-ProcessMap.ps1 -ProbeWeaponContext`
with Free Fire running. This mode selects only a verified local roster member
and replaces the other optional phases. No nonlocal member is substituted.

## Exact original paths

The reference builder verifies the established ELF and metadata SHA256 values.
It records six fields, six complete method bodies and registrations, 134 exact
class profiles and 106 slot-45 dispatch profiles. All supported instance sizes
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

496 offline checks pass, including 31 new weapon cases. The baseline synthetic
weapon fixture uses 4035 additional physical reads. Tests cover direct/fallback
selection, inactive-path short circuiting, all relevant hotfix gates, native
cast disagreement, virtual overrides, null storage, registration/runtime-field
disagreement, class identity, changes during capture, membership, final code
checks and read limits. Extracted-package checks also compile all earlier modes.

Inspect WeaponContext, WeaponSelection, WeaponDataReference and ResultFile.
ObservationStatus=SAMPLED_READ_ONLY alone does not imply a successful typed-data
result: inspect WeaponContext's specific status. Weapon IDs, ammo, ballistics,
firing readiness, damage processing, combat eligibility, LOS and aiming remain
unverified. No accuracy percentage follows from this snapshot.
