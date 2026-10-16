# V22 bounded original team-policy probe

Run `Run-ProcessMap.ps1 -ProbeTeamPolicy` after spawning in Training Ground.
This mode replaces the optional state/other-head phase for that run. Existing
kernel, process, module, layout, local-head and roster checks still run first.
The two optional switches are mutually exclusive; default head mode and
`-ProbePlayerState` remain available. V22 awaits a live Windows policy report.

## What it establishes

The probe observes one verified local/nonlocal roster pair and the original
`GameFacade.IsSameTeam(local, other)` route. It does not invoke that function.
It never uses raw Player.TeamIndex equality to classify the pair. It also does
not reproduce the spectator-aware IsLocalTeammate wrapper or classify hostility.
SameTeam=false alone is not an enemy, attackability or aim-selection decision.

For this exact build, GameFacade.IsSameTeam first checks the infection/faction
route. The original IsTeammateOfSameFaction calls IsUGCInfectionMode, which
compares the original GameServerGameMode getter with 58. Mode 58 is explicitly
unsupported here. For other modes, the facade delegates to CurrentMatchGame's
virtual slot 92 when present. V22 validates that metadata slot and the actual
runtime function pointer, and supports the original MatchGame implementation.
Absent, distinct or overridden match-game paths return explicit unknown status.

The supported MatchGame implementation checks native object validity and
compares two bytes produced from the players' 24-byte IDs. The ID getter copies
Player+0x408 on its original path; its policy helper usually reads inline byte 8.
However, EnableDynamicTeamID and a specific current-game subclass can redirect
that helper to a runtime dictionary. Raw TeamIndex at +0x430 is not involved.

## Settings and dynamic policy

The original CurrentGameModeSetting has a GameVar selector: either use
CurrentMatchGame, or cast CurrentGame to MatchGame. V22 requires these two object
pointers to be equal and validates their class ancestry and native cast table,
so both paths select the same virtual getter. The GameVar class must already be
initialized, its static storage must cover the selector, and the selector is
included in the snapshot. Slot 75 must be the original cached-settings getter.
Null settings return NOT_READY_CACHED_SETTINGS_NULL without running initialization.

The exact GameModeSetting class and EnableDynamicTeamID field at +0xa55 are
verified. If the flag is false, or the verified current-game class fails the
specific KMLICIEHMHC cast as expected, the original helper returns ID byte 8.
V22 checks the relevant metadata and runtime FieldInfo records, resolved ID
type and initialization, then compares those two unsigned bytes.

If the flag is true and the current-game subclass matches, the original helper
uses its dictionary field at +0x330. A verified null reference returns byte 255
for each player; V22 labels that narrow result ORIGINAL_DYNAMIC_NULL_DEFAULT.
A non-null reference returns UNSUPPORTED_DYNAMIC_TEAM_DICTIONARY and UNKNOWN:
its hashing, comparer, contents and lookup semantics have not been validated
by this probe. In particular, a failed TryGetValue on a non-null dictionary would
produce a different default from a null dictionary; no generic default is guessed.

## Read-only verification and outputs

Build-TeamPolicyReference.py verifies full ELF/metadata hashes and emits seven
field references, ten method references, four additional class profiles, 126
virtual-slot references (75 and 92 across supported MatchGame classes), and 56
code/GOT anchors. Runtime checks cover registration pointers, metadata records,
field offsets/types, runtime FieldInfo, class layouts/ancestry, native hierarchy
cast entries, static initialization, slot counts and dispatch targets. Original
Unity object validity is checked through the inspected native-pointer != 0 path.
No complete player ID or account identifier is printed.

Original-path gates include 0x4f5, 0x149, 0x148, 0x10a, 0x4f4, 0x138, 0x15e,
0x15c and 0x15b; dynamic-null handling additionally requires 0x15d inactive.
Existing context/roster gates remain required. Active gates produce UNKNOWN.

| Output | Meaning |
| --- | --- |
| ORIGINAL_PREDICATE_SAMPLED | Original packed-ID-byte predicate reproduced for this snapshot |
| ORIGINAL_DYNAMIC_NULL_DEFAULT | Original null-dictionary 255 defaults compared |
| UNSUPPORTED_DYNAMIC_TEAM_DICTIONARY | Dynamic non-null dictionary requires further implementation |
| UNSUPPORTED_FACTION_POLICY | Mode 58 selects a separate faction predicate |
| UNSUPPORTED_*_OVERRIDE | A different virtual implementation is active |
| UNVERIFIED_HOTFIX_ACTIVE | A required original-code path is overridden |
| NOT_READY_* | A prerequisite or stable observation was unavailable |
| FAIL | Exact-build, schema, dispatch or other validation failed |

ContextVerified=true and BOTH_SELECTED_ENTRIES_REVALIDATED describe accepted
endpoint observations; they do not imply SameTeam is known. Unsupported routes
still report verified mode/settings information when the final checks pass.

Both selected 40-byte entries, game/match/local pointers, storage identities,
class/role markers, policy inputs and gate entries are captured and rechecked.
Counter headers are double-read before and after each member. Unrelated global
counter changes are audited separately; selected entries must stay exact.
Any observation failure discards all tentative team values. Final schema/code
checks must pass before any predicate is published. This is not an atomic
snapshot or a lifetime/ABA guarantee, and the two players are not locked.

The phase uses at most 6000 additional reads, with 1500 reserved for final
checks, inside the unchanged global 30000-call/120-second limits. It invokes
no game method, initializes no game object, pauses no VM and writes no memory.

## Validation and next live evidence

317 offline checks pass, including 40 new policy checks: unequal/equal unsigned
policy bytes independent of raw TeamIndex, original gates, faction/custom routes,
both settings selectors, static initialization, null/populated dynamic dictionaries,
subclass casts, invalid flags/class extents/dispatch, native-null players, changed
IDs/mode/membership, unrelated counter changes, final schema rejection and budgets.
The generated references reproduce byte-for-byte. The extracted package is
compiled with C# language version 5, its PowerShell syntax and parameter sets
are checked, and its ZIP/source/plugin digests are verified.

The next Windows report must show TeamPolicy, TeamPolicyObservation and
SameTeamPredicate. A supported predicate result establishes only that observed
pair and route. A populated dynamic dictionary, faction mode or custom override
is a concrete remaining dependency, not a reason to relax checks. Hostility,
combat eligibility, LOS, continuous tracking and aim integration remain unfinished.
