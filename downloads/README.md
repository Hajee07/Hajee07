# Standalone head-direction DLL core

Current process probe: **V32**. Separate `-ProbeWeaponAmmo` mode verifies a
runtime-bound original Int32 weapon counter used by ammo UI. 626 offline checks
pass; live V32 validation pending. Magazine/reserve, unlimited policy, full
readiness, LOS and aiming remain unverified.
See [counter evidence](bluestacks-process-map/WEAPON-AMMO-EVIDENCE.md).

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
