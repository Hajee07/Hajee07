# V23 bounded combat-state observations

Run `Run-ProcessMap.ps1 -ProbeCombatState` after spawning in Training Ground.
This mode selects the first verified nonlocal roster member. To examine a
specific member from the current run's capped roster, add `-CombatRosterIndex N`
(0 through 15); a missing/local member is rejected. Indices are rediscovered on
every run and are not persistent player IDs. The output includes the selected
class/address and revalidates that selected entry. One member is sampled to fit
the unchanged read budget. Optional modes are mutually exclusive.

V23 observes original watching, dead/revive, ghost and IsDieing predicates.
It does not establish combat eligibility. Team policy, hostility, invulnerability,
mode-specific zones, weapon restrictions and actual LOS are separate dependencies.
No player is selected for aiming, and no game method or memory write is performed.
V23 has two accepted live Windows reports (below).

## Exact original branches

The reference builder verifies the full ELF/metadata SHA-256 values already used
by V22. It emits eight fields, nine common methods, 27 additional class profiles,
55 virtual dispatch entries and 21 conditional movement implementations.
Selected movement implementations include method registration, metadata and all
80 native bytes; their complete instruction template is checked by the builder
before extracting the gate and return constant. Unused movement implementations
are not read from the live process.

### Watching

Player.IsWatching, method 210413 / RVA 0x6f39994 / slot 144, returns false on its
original branch (gate 0x3c6a). Player_Watching overrides that slot with method
247110 / RVA 0x7c698e4 / gate 0x25c3c. That implementation checks whether
CurrentGame casts to the KMLICIEHMHC family (type 34107); its Boolean is true only
when that cast succeeds. Thus a Watching class name alone does not establish
the original predicate. V23 verifies the actual native dispatch, metadata slot,
complete current-game ancestry, resolved class root and native hierarchy cast.

The original Watching implementation also increments CurrentGame+0x29c on its
true branch. V23 reproduces only the Boolean, never invokes the implementation,
and never performs that increment. Output explicitly states BooleanOnly=True
and CounterWrites=NONE. Unsupported implementations/hotfixes yield UNKNOWN.
This predicate is not an exhaustive semantic classification of every observer role.

### Death and revive

The existing V21 fields and gates are retained. BaseDeadRaw is AttackableEntity
+0x7c, PendingReviveRaw is Player+0xa6c. Original IsReallyDead is
BaseDeadRaw && !PendingReviveRaw only with gates 0x447 and 0x4dd8 inactive.
A false value is not a complete alive/attackable decision.

### Ghost

Player.IsInAnyJSGhost, method 212529 / RVA 0x70461d0 / gate 0x21f84, compares
Player+0x1bb0 with zero. The int32 field is CINHNHDNFMF, declared enum
COW.GamePlay.JCNDFEPGCJO. V23 verifies its field metadata, resolved type,
registration and runtime FieldInfo; GhostKindRaw preserves the signed integer.
With the original gate inactive, IsInAnyGhost is exactly raw != 0, including
values outside the named enum members. No extra meaning is assigned to them.

### IsDieing

Player.get_IsDieing, method 210197 / RVA 0x6f1deec / gate 0x49b, delegates through
Player+0x1d48 (GBJCJJNPPEC) to GFLBFKKDAMK.ACDCHOCBLMK, method 214090 /
RVA 0x70e2fcc / gate 0x49a. V23 currently supports the exact GFLBFKKDAMK controller
(type 31716), validates its extent and runtime fields, and requires controller
owner +0x10 to be the selected player. Null/unsupported controllers yield UNKNOWN.

The original helper directly calls the base dead getter. If dead, it returns
false without reading movement/state. Otherwise it calls PJCCKDLGAPB at
0x70e2d5c (gate 0x1d6). The initialized GameVarDef static Boolean
EnableGetPhysXStateOpt at +0x41fe selects:

- true: controller+0x18 is the movement state;
- false: null controller+0x20 yields zero; otherwise slot 4 of that state object
  returns a movement constant on a supported original implementation.

The state object must belong to the verified EIILAKAAIOP hierarchy (type 31737).
Every inspected concrete slot-4 implementation has an independently pinned IFix
gate and constant return. V23 validates the selected class chain, metadata slot,
actual virtual target, registration, method record, code bytes and gate. It does
not execute a virtual function. An abstract/unsupported implementation is UNKNOWN.

A nonzero movement value returns false immediately. For zero movement, original
OILOHAELLEC at 0x70e2e2c (gate 0x27a) returns zero for null state or delegates to
EIILAKAAIOP.JHBPLBBCOHG at 0x70e5648 (gate 0x279), which reads state+0x10.
The final IsDieing comparison is that int32 value == 8. Original short circuits
are preserved: dead and nonzero direct movement do not require unused state data.
This reproduces the named getter; it is not a comprehensive knockout or combat
eligibility policy.

GameModeRaw is the facade static mode field at +0x114. GameModeStatus tells
whether its original getter (gate 0x10a) is active. A raw value from an overridden
getter is not used to infer a game-mode rule. Mode-zone evaluation remains open:
Player.get_IsInBattleZone calls a separate mode/interface property path, so mode
23 and a false team predicate alone do not prove damage eligibility.

## Snapshot and resource contract

The existing state snapshot checks current game/match/local pointers, exact
selected 40-byte entry, dictionary/array identity and capacity, class ancestry,
local marker, field values and original context gates. Bounded counter headers
are audited with two equal reads before and after the member. Global changes
are reported independently; selected bytes must still agree at recheck.

New mode, role, controller/state pointers and class chains, dispatch entries,
static selector, original gates, conditional code and field bytes are recorded
in that same row and rechecked. A changed observation discards all tentative
values for the row. Phase-final schema/code failure discards the entire result.
No atomic snapshot, lifetime guarantee, VM pause or GC root is claimed.

The phase permits at most 6000 additional physical calls, with 1500 reserved for
final checks, inside the existing global 30000-call / 120-second limits. The
baseline synthetic fixture uses 4805 additional reads. Exhaustion publishes no
unverified predicates and never increases/resets those bounds.

## Verification

385 offline checks pass, including 68 new combat-state cases. Coverage includes
both Watching class/game branches without counter writes, all ghost comparisons,
death/movement short circuits, final state-ID branches, all 21 movement targets,
original and virtual hotfix gates, null/unknown controllers, controller owner and
class extent, native hierarchy and actual dispatch, runtime fields, selector
validation, changed state/membership/hotfix, conditional code changes, final
schema invalidation, explicit selection and read-budget boundaries. Existing
head, state and team modes are included in the same C# 5 compilation/test suite.

The generated reference files must reproduce byte-for-byte; package validation
checks PowerShell parsing/parameter sets, source/plugin manifest hashes, ZIP
integrity and extracted-package compilation/tests. Offline checks do not prove
live gameplay behavior. Send the complete V23 output, particularly CombatState,
WatchingPredicate, GhostPredicate, DyingPredicate and ResultFile contents.

## Accepted V23 live reports

Both user runs used host PID 11784 / guest PID 4901 and sampled the same first
nonlocal PlayerNetwork in raw mode 23. Each accepted SELECTED_ENTRY_REVALIDATED,
173 observations, and original watching=False, ghost=False (raw 0),
BaseDead=False, PendingRevive=False, ReallyDead=False and IsDieing=False.
The controller was NKJMAMAFCNB, direct movement selector=True, movement=0,
state ID=0. Each combat phase used 4736 additional physical reads.

The first roster verified all 13 candidates (local plus 12 others), total reads
23896, and local head sampled on attempt one. The second verified all 16
candidates (local plus 15 others), total reads 25519, and local head sampled on
attempt two after discarding a changed TRS observation. Both had counters changed
since roster capture but unchanged during the combat capture, and all plugin
unload/handler cleanup/session release steps passed. These are two endpoint
snapshots, not continuous tracking or transition/eligibility/LOS validation.
