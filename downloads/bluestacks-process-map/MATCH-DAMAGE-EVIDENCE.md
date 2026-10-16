# V27 original match damage-policy observation

Run `Run-ProcessMap.ps1 -ProbeMatchDamagePolicy` after spawning in Training Ground.
It selects the verified local member and first verified nonlocal member for
context/membership revalidation. Optional modes are mutually exclusive; head,
state, team, combat-state and zone/protection modes remain available. V27 awaits
a live Windows report.

The probe reproduces only a supported original CurrentMatchGame.CanTakeDamage
method predicate. Its true result is not full combat eligibility, hostility,
damage immunity, a weapon-context decision or LOS. It does not invoke the method,
construct weapon data, simulate a hit, prove a call site executes this method,
select an aim target or write memory. Results from separate earlier probes are
not merged into one simultaneous eligibility claim.

## Exact implementation and dispatch

Metadata method 35677 is COW.MatchGame.CanTakeDamage, RVA 0x7327e50, virtual
slot 91. Its three parameters are attacker (Player), victim (OGKFEMJNCGM) and
weaponData (IOKEALMHBKN). The original method first tests IFix gate 0x853d.
When inactive, the complete non-hotfix block at 0x7327eb0 restores registers,
sets w0=1 and returns. It reads none of those arguments and performs no call or
write on that branch. An active hotfix can replace this with argument-dependent
behavior and therefore yields UNKNOWN.

The reference builder verifies full ELF/metadata hashes, the method's registered
pointer/40-byte record, slot and parameter count/names, and the exact return-block
instruction words. It emits five context fields, three method records, the full
base method and mode-getter code anchors, and slot-91 metadata/target profiles
for all 63 supported MatchGame-family classes. Those profiles contain two targets:
base MatchGame and MDHAFBELMFD.CanTakeDamage, method 242331 / RVA 0x7b10f2c.
The latter override remains explicitly unsupported; V27 never applies the base
constant to it. The observed mode-23 class MNDPBJMLABJ (34188) inherits the base
slot in this inspected build, but actual runtime dispatch still must match.

V27 requires CurrentGame and CurrentMatchGame to refer to the same validated
MatchGame-family object. Null or distinct CurrentMatchGame objects return explicit
not-ready/unsupported statuses. Runtime class ancestry, slot count, metadata
vtable entry and actual native function pointer must agree. GameModeRaw is
observed separately with its getter-gate status (0x10a); a raw mode alone never
selects a policy target. No current-game class is inferred from its numeric mode.

## Context verification

The facade static initialization/extent, declared CurrentGame/CurrentMatchGame/
mode fields, MatchGame.m_Match and Match local-player fields require exact
metadata, type descriptors, offset registrations and runtime FieldInfo. The game,
match and local-player objects are revalidated, including the relevant class
families and local role. Original context gates must remain inactive.

Both selected 40-byte roster entries, dictionary/array identity/capacity and player
class/local markers are captured and checked again. Bounded counter headers use
two equal reads before and after each member. Unrelated counter changes are
reported; selected membership/inputs must still match. This is endpoint evidence,
not an atomic snapshot, whole-roster stability or a lifetime/ABA guarantee.

All captured pointers, class/dispatch metadata, context inputs and gates are
rechecked; final schema/code/process checks must pass. Any exception clears the
entire tentative result, including mode and predicate. ContextVerified can be
true with an UNKNOWN unsupported predicate. Only ORIGINAL_ARGUMENT_INDEPENDENT_TRUE
sets MatchDamagePredicate=True and ArgumentIndependent=True. No false value is
invented from an unsupported path.

The phase uses at most 6000 additional physical calls, reserves 1500 for final
checks, and retains the global 30000-call/120-second bounds. The baseline fixture
uses 3402 additional calls. No VM pause, game-method call, initialization or
memory write is performed.

## Validation and live output

465 offline checks pass, including 24 new policy cases. They cover the observed
mode class and base path, argument independence, base hotfix, custom override,
null/distinct game pointers, mode-getter hotfix, actual dispatch/vtable extent,
field registration/static initialization, changed context/membership/gates/mode,
code/schema failures at final verification, unrelated roster counters, missing
pairs/prerequisites and reserve/global read boundaries. All existing modes are
compiled and tested in the same C# 5 suite.

Reference outputs must reproduce byte-for-byte. Release checks cover extracted
package compilation/tests, PowerShell parsing and six exclusive parameter sets,
ZIP integrity and runtime source/plugin hashes. Offline verification does not
replace the live Windows run.

Send the complete report, especially MatchDamagePolicy, MatchDamageObservation,
MatchDamagePredicate and ResultFile. Even an accepted true result leaves actual
weapon/damage processing, full combat eligibility, hostility, complete immunity,
LOS and continuous aim integration unverified.

## Accepted V27 live report

The user's report (host 11784 / guest 7882) passed module identity and both
80-check layout comparisons. All 13 active roster objects were verified; the
local head was sampled on attempt two. In raw mode 23 the selected original
CurrentMatchGame slot-91 method returned ORIGINAL_ARGUMENT_INDEPENDENT_TRUE.
Both selected roster entries revalidated. Counters changed since the earlier
roster snapshot but stayed unchanged during this capture. There were 154
observations, 3513 additional reads and 24286 total reads. Plugin unload,
handler cleanup and shared-session release all passed. No game method was called.
This is one match-policy predicate, not damage-processing or eligibility proof.
Separate reports are not combined into a simultaneous state observation.
