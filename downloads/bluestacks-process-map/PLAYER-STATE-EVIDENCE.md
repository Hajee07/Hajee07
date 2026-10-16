# V21 bounded player-state observations

Use `Run-ProcessMap.ps1 -ProbePlayerState` after spawning in Training Ground.
This selects state sampling instead of the optional nonlocal-head phase.
Kernel, process, module, metadata, local head and roster checks still run first.
Default invocation retains V20's other-head behavior. V21 has no live Windows
state result yet; its new state cases are synthetic offline checks.

## Output contract

At most two verified roster members are selected, prioritizing the local member
and then the first other member. If the local member was absent from the capped
roster, at most two others are used; their IsLocal values remain false.

- TeamIndexRaw is the signed 32-bit value read by Player.get_TeamIndex. Neither
  equality nor inequality is reported as teammate/enemy classification.
- BaseDeadRaw and PendingReviveRaw are the two verified Boolean fields. The
  original IsReallyDead expression is BaseDeadRaw && !PendingReviveRaw only when
  both relevant hotfix gates are inactive. Otherwise ReallyDead is UNKNOWN.
- ModelVisible reproduces the original Player.IsVisible branch only for the
  verified virtual target and an inactive visibility hotfix gate. The exact
  BitArrayBoolean and BitArray classes, inherited mask field and mode field
  are checked. Mode 1 uses mask != 0; other modes use mask == 0xffffffff.
- Null visibility storage and subclass overrides produce explicit unsupported
  or not-ready statuses and UNKNOWN, never a fabricated false value.

ReallyDead=false does not establish combat eligibility. ModelVisible=true does
not establish wall/obstacle line of sight. Team policy, knockout, complete alive
policy, LOS, tracking and aim integration remain unverified. No managed/native
game function is invoked and no memory is written.

## Exact-build evidence

Build-PlayerStateReference.py independently verifies the existing full ELF and
metadata hashes through Recover-GameLayout.py. It emits player-state-reference.json
and PlayerStateReference.cs: six fields, six methods, three additional class
profiles, 31 Player visibility dispatch profiles and 14 code anchors. The
original disassembly rationale is retained in PLAYER-STATE-RESEARCH.md.

At runtime the new phase checks method metadata and relocated registration
pointers, field metadata/offset registrations/type flags, resolved type records,
and full native code anchors. Each sampled object additionally requires exact
class ancestry and runtime FieldInfo name/type/declaring-class/offset/token data.
The Player base, AttackableEntity parent and BitArrayBoolean/BitArray chain must
match. Visibility requires metadata slot 70 and the actual native virtual target
to agree. Player_Watching's override is explicitly unsupported. Primitive bool
bytes must be 0 or 1. Raw TeamIndex is not range-clamped or classified.

The three original-path gates are IsReallyDead 0x4dd8, AttackableEntity.get_IsDead
0x447 and Player.IsVisible 0x21bf3. Original context/roster gates remain required.
Hotfix array identity, length, tested entries and relevant static initialization
flags are sampled and rechecked; an active state gate suppresses its semantic
result while allowing verified raw fields to be reported.

## Snapshot and resource boundaries

The current game/match/local pointers, dictionary/storage identity and capacity,
exact selected 40-byte entry, object ancestry/local marker, state fields and
method gates are read and compared again. Bounded counter headers use two equal
copies before and after each member. Changes between those endpoints are logged
but do not by themselves invalidate unchanged selected-entry bytes. Every
accepted row reports SELECTED_ENTRY_REVALIDATED. This provides endpoint evidence,
not an atomic snapshot, lifetime guarantee or protection against ABA changes.

A changed observation or member discards that entire tentative row; no earlier
field values leak from it. Phase-wide final code/schema failure discards all
rows. Earlier completed core/head results remain separately reported. A prior
row can remain accepted if a later row exhausts its budget and final phase checks
pass; the samples are not asserted to be simultaneous.

The phase permits at most 6000 additional physical calls, reserving 1500 for
final checks. This fits within the existing global 30000-call/120-second limit.
No counter/timer reset, VM pause, GC root or increased global bound is used.

## Offline validation

The combined suite has 277 checks, including 29 new state checks. They cover
separate local/nonlocal values, all dead/revive combinations, mask/mode branches,
each hotfix gate, Watching's override, null storage, signed team values, invalid
Booleans, registration and runtime field mismatches, invalid class extent and
virtual target, mid-capture state/member/hotfix changes, final schema invalidation,
missing prerequisites, reserve behavior and global budget exhaustion.

The generated C# and JSON must reproduce byte-for-byte from the exact inputs.
The release is validated after extraction with C# language version 5, PowerShell
syntax checks, the suite above, ZIP integrity and manifest digest checks.
These checks do not replace a live V21 Windows run or prove gameplay semantics.
