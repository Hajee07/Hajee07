# V32 original selected-weapon counter

The V32 counter phase passed live, but its head phase failed (mixed report below). Run `Run-ProcessMap.ps1 -ProbeWeaponAmmo`.
This ninth mutually exclusive optional mode replaces the data-ID/reload/firing
phases. Existing modes and read costs remain available. It reads one original
weapon counter used in ammo-related UI; it does not label magazine or reserve.

## Exact getter and semantic evidence

HBIBDMMOOOK.IHBDOPMADIE (method 224776, RVA 0x7457fa4, length 0x48) is an
instance nonvirtual Int32 getter with gate 0x328. Its original inactive-hotfix
branch loads `w0` from weapon +0x610 at 0x7457fdc. Full code, method pointer,
metadata and original selection code are checked initially and finally.
The receiver must have the supported exact HBIBDMMOOOK ancestry and class sizes.
No game getter is called and no custom virtual behavior is substituted.

The exact source contains calls to this getter from:

* UIHudInventoryWeaponSlotItemController.RefreshWeaponAmmo, call 0x4ecd530.
* HippoCrisisInGameItemUIData.get_AmmoNum, call 0x5f437fc.
* Player.GetThrowingKnifeLegMountCount, call 0x6f7c498.

The builder independently checks each BL target and records static caller code
in JSON. These are semantic source references, not reproduced complete UI/game
policies and not runtime call-site claims. Different weapon types, special UI
routes and unlimited-ammo settings can interpret the counter differently.
Therefore output is ORIGINAL_SELECTED_WEAPON_COUNTER, not an asserted universal
magazine count, reserve count, shot capacity or firing-readiness result.
Zero and all signed Int32 bit patterns are preserved without guessed ranges.

## Runtime field binding without guessed field identity

All relevant file field-offset registrations are opaque 0x81818181. The source
contains eleven nonstatic Int32 candidates in HBIBDMMOOOK. Their metadata indices,
names, descriptors, flags, tokens and source registration slots are independently
derived from the SHA256-verified inputs. Their instance offsets are deliberately
unbound in the generated JSON; no candidate is assumed to be the counter field.

The runtime owner field count must equal the exact source count of 253. The
already initialized FieldInfo table is captured in bounded chunks of at most
4096 bytes (8096 bytes total). Exactly one row must have offset +0x610, proven
independently by the native getter. The row must correspond to one of the eleven
nonstatic Int32 candidates and match its exact metadata name pointer, descriptor,
declaring owner and token. Chosen field metadata and descriptor flags must still
match source. Its source registration may only be exact 0x81818181 or resolved
0x610. A duplicate offset invalidates the row. Missing offset, unsupported type
or null table yields an explicit unknown status. No field metadata is initialized.
Only after these checks is weapon+0x610 read and the runtime-bound field identity
reported. This is not an opaque-value decoder or field-order guess.

The field table, source registration, metadata, selected member/context and
counter are rechecked. Changes discard tentative values; final code failure
clears all observations. Original GetActiveWeapon selection, hand fallback,
class ancestry and native cast remain required. There is no nonlocal substitute.
All limits remain: phase 6000 physical calls, 1500 final-check reserve, global
30000 calls / 120 seconds. No VM pause, game method, initialization or write.

## Validation

626 offline checks pass, including 43 new counter cases. Every one of the eleven
candidates is exercised as an unbound runtime choice. Tests cover Int32 bit
boundaries, resolved/opaque registration, A0 selection, unrelated getter gates,
lazy/missing/duplicate/unsupported field bindings, runtime name/type/owner/token,
field count and descriptor mismatches, selection gates, changing counter/table/
gates/membership, final getter code, local-only selection and read bounds.
Direct-field fixture uses 3870 additional reads; A0 fixture 4359. All prior 583
checks and earlier mode costs still pass. References reproduce byte-for-byte;
extracted release checks parse PowerShell, verify nine exclusive modes, compile
as C# 5, execute the full suite and validate runtime source/plugin digests.

Inspect SelectedWeaponAmmoCounter, WeaponAmmoField, WeaponAmmoMembership,
WeaponAmmoSamples and ResultFile. A sampled row can still contain an explicit
unknown counter status. Magazine, reserve, unlimited policy, ballistics, complete
readiness, LOS and aim integration remain unverified. Earlier reports' ID/reload/
firing results are not combined into this capture or an accuracy percentage.

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

## Accepted V33 stable-path live report

Host 11784 / guest 9214 passed module identity and both 80-check layout passes.
Local head sampling passed on attempt one. All 16 active roster objects were
verified on attempt one. The A0 counter phase accepted raw Int32 value 2 and
runtime field 105 NJEENAEMFAO, RESOLVED_OFFSET. Selected membership and counters
were stable. Phase observations=154, additional reads=4284, total=24208. All
cleanup passed, no game-method calls or writes occurred.
There was no job transition in this run, so the new retry branch remains
validated offline only. This confirms the stable head/counter path, not an
atomic cross-phase state or magazine/reserve/readiness/aim integration.
