## Owned hit-registration laboratory

[Source and Windows instructions](hit-registration-lab/README.md) · [Standalone source + portable .NET 8 app ZIP](hit-registration-lab.zip) · [Feasibility and V48 audit](hit-registration-lab/FEASIBILITY.md) · [Validation](hit-registration-lab/validation.json)

Independent local game/server with geometric or all-validated-hits-as-headshots policies. 86 automated checks and three separate-process HTTP experiments passed on Linux. Windows run and Free Fire MAX/server compatibility are unverified. No commercial-game adapter or writes. ZIP SHA-256: `1c6acbc5344c8a44427dc4616490c32585cf3156a05a37197ef902dca135c469`.

## Single-capture Player.MainCameraTransform reader

[Source and instructions](player-camera-readonly/README.md) ·
[Download standalone ZIP](player-camera-readonly.zip) ·
[Package validation](player-camera-readonly-validation.json)

Separate read-only source integration; no eight-stage prompts or saved captures.
27 camera checks and 1028 inherited checks pass offline. Original V52 baseline
bytes preserved. Actual rendered camera, LOS, shot direction and live aim output
remain unverified; this new Windows reader path still needs a user capture.
ZIP SHA-256: `b04b55088a09e71e17c1c14b6f14ab47b47cca5659616129fb439d849bcd1e17`.

## Uploaded Phoenix DLL reference review

[Static inspection and pinned field crosscheck](phoenix-reference-review/README.md).
Managed MainCameraTransform reference constants match the pinned game inputs;
neither DLL was loaded. Restarted processes require the capture helper's -Fresh
mode. Export names do not establish a live output adapter contract.

## Interrupted V52 camera capture completion

[Capture helper and assessment](camera-capture-completion/README.md) ·
[Download helper ZIP](camera-capture-completion.zip)

Preserves six valid saved pose reports and requests the two remaining manual
stages. Same context required; native V52 validations and budgets unchanged.
54 existing pose checks and 20 helper checks passed offline; Windows launch and
live aim binding are not validated by those checks.
ZIP SHA-256: `dc4168bd42d10365acf6ec5d9aa439fa5b25ba00adfd5f0f1d9ec15da199b20d`.

## Integration review source package (owned simulation)

[Guide and five-task evidence matrix](integration-review/README.md) ·
[Download source ZIP](integration-review-source.zip)

V52 baseline preserved. Adds provider-proof validation, generation-aware measured
head tracking and an expiring local command lease. 144 review assertions, 579
existing targeting assertions and the 1028-check V52 suite passed in the cloud.
Live camera/target/LOS providers and the game output adapter remain BLOCKED.
ZIP SHA-256: `75db396fdc09dbba1c32df6bb8eeb49f864b7f458c7d01114ce3a5063a146a20`.

The [hit-query/cache contract](bluestacks-visibility-source-audit/README.md#follow-up-hit-query-contract-and-cached-reference-layouts) now records the exact query signature, collider-ID distinction and declared cache/interface layouts. These source references do not establish live head LOS or a game adapter.

The uploaded advanced targeting sources are now [reviewed as a separate offline module](targeting-offline/README.md): V52 source compile compatibility, 579 synthetic assertions and a source-rebuilt simulation passed. Live geometry, target proofs and game output remain unbound.

The [physics-query follow-up](bluestacks-visibility-source-audit/README.md#follow-up-camera-mode-delegate-and-real-raycast-callers) identifies registered Player raycast call sites and distinguishes them from verified selected-head LOS. This remains offline source evidence; Windows runner V52 is unchanged.

An [offline visibility source audit](bluestacks-visibility-source-audit/README.md) now documents model visibility versus unverified target-head LOS. The Windows diagnostic runner remains V52; this source-only step needs no fresh Windows capture.

V52 adds source-verified Unity Object null-comparison data and metadata/class readiness gates for the registered camera reference. No functions invoked or writes added; actual game getter/camera selection remains unverified. See [null predicate evidence](bluestacks-process-map/CAMERA-NULL-PREDICATE-EVIDENCE.md).

V51 fixes camera report formatting when the local head sample is unavailable. V50 completed the live aim-state sample at 4920 reads but its report stopped before pose/controller output; those results remain unverified.

V50 reduces aim-state final recheck transport calls while preserving every observed-byte comparison and existing budgets. Offline full-chain fixture: 5572 → 4752 reads. Live Windows verification pending; aim integration remains incomplete. See [batching evidence](bluestacks-process-map/AIM-RECHECK-BATCHING-EVIDENCE.md).

V49 adds registered camera-controller/camera field inventory and native-reference
comparison. Getter invocation and actual game-camera selection remain unverified.
See [inventory evidence](bluestacks-process-map/CAMERA-CONTROLLER-INVENTORY-EVIDENCE.md).

V48 adds a read-only game camera getter entry-gate audit. One `-ProbeAimState`
capture reports metadata guards and IFix slot presence; full managed camera and
fallback selection remain unverified. See
[entry-gate evidence](bluestacks-process-map/GAME-CAMERA-ENTRY-GATES-EVIDENCE.md).

V47 adds a manual eight-capture native camera pose experiment with source report
validation, identity checks and yaw/pitch comparison. The native probe remains
read-only; game-camera identity, LOS and aim updates remain unverified. See
[pose experiment](bluestacks-process-map/CAMERA-POSE-COMPARISON-EVIDENCE.md).

V46 adds source-checked original native camera world rotation and its mathematical
positive-Z basis, without game calls, synchronization or writes. Live V46 and
actual game-camera verification are pending. See
[rotation evidence](bluestacks-process-map/CAMERA-ROTATION-EVIDENCE.md).

V45 process-map package adds a source-checked, read-only world-position sample
for the original Unity native camera selector's Transform intermediate.
Live Windows V45 results, camera rotation/game getter identity, LOS/eligibility,
aim updates and end-to-end integration remain pending. See
[remaining gates](bluestacks-process-map/CAMERA-POSITION-EVIDENCE.md).

# Standalone head-direction DLL core

Current package: **V44**. `-ProbeAimState` verifies the full native camera predicate
and evaluates its data equivalently without function calls, preserving source
selection order and unknown/bounded statuses. 876 offline checks pass; live V44
pending. Managed/game camera, actual pose, LOS and aiming remain unverified.
See [selection evidence](bluestacks-process-map/CAMERA-SELECTION-EVIDENCE.md).

V34 comparison matched two per-experiment HUD/counter patterns (2->1->2,
7->6->7). Model names were not captured; evidence remains manual HUD correlation.
The comparison workflow remains available in V44.

V33 stable head/counter path passed live: 16 roster objects, counter 2 / field 105,
all cleanup PASS. No job transition was observed; retries remain offline-tested.

V32 accepted counter 2 / runtime field 105 with stable membership and cleanup,
but rejected the head sample after a changed job handle. It was a mixed result,
not a full PASS. Magazine/reserve, full readiness, LOS and aiming remain unverified.

V31's cache branch passed live: selected Firing=False, CacheEnabled=True,
selected membership and all cleanup PASS. State-ID route remains offline-tested.

V30's `-ProbeWeaponContext` passed live: ID 41, selected Reloading=False,
StateRaw=2, selected membership and all cleanup PASS. Existing mode remains
available with unchanged read cost; it is not combined with the firing phase.

V29 passed live: raw UInt32 data ID 41, A0 hand path, selected membership and all
cleanup PASS. Ammo, ballistics, LOS and aim integration remain unverified.

V28 weapon selection/reference passed live through the A0 hand path, within
budget and with all cleanup passing. Local-head samples were discarded for
motion; no head coordinate or ID was accepted in that run.

V27's match-policy mode passed live: mode 23, original argument-independent true
predicate, both selected entries revalidated, within budget and all cleanup PASS.
That method result alone does not establish complete combat eligibility.

V26's zone/protection mode passed live for one selected player: mode 23, zone 0,
battle-zone/shooting-range false and invincibility predicate false. Its array
fix, selected membership, budget and cleanup all passed for that snapshot.

V23's combat-state mode remains available. Two live reports accepted its original
watching/dead/revive/ghost/IsDieing predicates for the selected player, within the
read budget and with all cleanup passing.

V22's `-ProbeTeamPolicy` remains available. The user's live run verified the
original packed-ID-byte predicate in raw mode 23, SameTeam=False, within the
read budget and with all cleanup passing. No hostility/attackability follows
from that predicate alone.

V21's optional `-ProbePlayerState` samples raw team
index, dead/revive flags and supported original model visibility from at most
two verified roster objects, with unknown statuses for active hotfixes or
unsupported visibility paths. 277 offline checks passed before release. The
user's V21 run accepted local and nonlocal state samples within the read budget,
with all cleanup passing. The earlier V20 local and one nonlocal head sample
also passed live. That live report did not change the V21 runtime ZIP.
Continuous tracking, complete enemy/team/alive/line-of-sight semantics and aim
control remain incomplete.
See [the probe instructions](bluestacks-process-map/README.md) and
[state evidence](bluestacks-process-map/PLAYER-STATE-EVIDENCE.md).

Download `head-aim-dll-x64.zip` and extract it on Windows. The archive contains C++ source, a Windows x64 DLL, and an own-process DLL smoke loader.

This is a mathematical core that accepts caller-supplied head positions and calculates directions. It has no live Free Fire data provider or aim-control integration. It is not a working Free Fire aim-lock.

Validation: 57 native tests passed; native shared-library C ABI loading passed; Windows x64 cross-compilation and export inspection passed. The user subsequently ran the Windows smoke loader successfully. Game integration remains incomplete.

The separate [native BlueStacks bridge](bluestacks-native-bridge/README.md) has
now passed its Windows one-byte guest physical read probe, including plug-in
loading and cleanup. See its [runtime results](bluestacks-native-bridge/RUNTIME-RESULTS.md).

[Get-GuestMappingContext.ps1](bluestacks-native-bridge/Get-GuestMappingContext.ps1)
collects kernel-layout and paging prerequisites on the user's Windows PC.
Aim-control writes remain unimplemented.

The uploaded fastboot disk subsequently supplied the matching kernel image and
87,332 recoverable kernel symbols. A [read-only process-mapping probe](bluestacks-process-map/README.md)
now implements kernel identity checks, process page-table discovery, and a
bounded ARM64 IL2CPP header read. Version 4 passed live kernel/process and final
header verification after 808 VMAs and 8096 reads. Version 5 subsequently passed
live module segment/build-ID/code verification in 10847 reads, with cleanup.
The exact metadata now yields validated type/method/field records and selected
native registrations. Version 6 verifies nine field and nine method candidates
against live memory. Seventy-two offline checks passed. Live registration checks,
player-object/head-position integration, and aim updates remain pending.

Version 7 isolated nine stable type-descriptor differences while the other 71
checks matched. Every differing payload points into one candidate metadata type
table. Version 8 checks the descriptor flags, derived metadata base, exact header
and complete type records. 89 offline checks pass; live version 8 verification
and player/head/aim integration remain pending.

The v8 run stopped on a repeated VMA node before module/metadata verification.
V9 adds one bounded fresh scan for this specific condition, preserves the global
budgets and all validation checks, and reports node limits separately. 96 offline
checks pass. Live metadata verification and aim integration remain incomplete.

V9 subsequently passed module verification on its first attempt and exposed a
runtime header prefix of zero/version 24. V10 validates that exact observed
prefix, the remaining 248 header bytes and complete type records. Input hashes
remain unchanged. 101 offline checks pass; live metadata validation is pending.

V10 then passed all 80 runtime registration checks in both rounds, including the
complete header and nine type records. V11 adds read-only local-player and managed
head Transform verification with class/parent/hotfix/interface checks. 127 offline
checks pass. Run after spawning in Training Ground; live object validation is
pending. Other-player enumeration, world coordinates and aim updates are pending.

V11 user reports exposed a traversal inconsistency and, on a later successful
module/metadata scan, an IFix class-layout mismatch. V12 corrects the generator's
use of opaque native-size words as exact expectations. It verifies bounded
runtime sizes and IFix's actual static-field metadata/layout, and adds a bounded
fresh scan for outer order/backlink inconsistencies. 142 offline checks pass.
Live player/head validation and aim integration still require further work.

V12 verified the live local PlayerNetwork chain, including the corrected IFix
runtime layout. Its head-provider cache was null. V13 adds a bounded exact-name
bone_Head lookup in the already populated model dictionary, with generic type,
vtable/hotfix, String and node checks. 155 offline checks pass. No initialization
or memory writes are used; live head Transform and world-position work is pending.
