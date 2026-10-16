# V20 bounded nonlocal head samples

The sections below preserve the earlier V17-V19 design and results. The current
V20 selected-entry contract and validation are specified in the final section.
V19 verified a live local position and 12 collection objects, but rejected its
nonlocal result on a global free-list change. No live nonlocal XYZ is yet
accepted. Team/alive/visibility classification and aim writes remain absent.

## Reuse and membership

No new game offsets or guessed method signatures are introduced. The existing
managed head provider/cache/interface checks were moved to one shared private
resolver. The selected member gets its own temporary head result; a missing head
never falls back to the local head. The same exact-build native Unity hierarchy
reader then calculates its sampled position, with the existing strict TRS
comparisons, bounds and at most three motion attempts.

The accepted roster result now retains internal snapshots of the full 16-byte
dictionary counter header, dictionary/entry-array class and pointer identities,
array capacity, and each verified member's original entry index and 40 bytes.
Entry key bytes are not interpreted or printed. Before a nonlocal read:

- Revalidate the current facade/class and game/match/local-player links.
- Require the same typed dictionary, counter header, entry array and capacity.
- Require the exact saved entry bytes, including its key and object pointer.
- Revalidate the supported Player class/parent chain and nonlocal marker.
- Verify the IFix root/field/array and original-path gates, including the
  collection getter and existing head/model/interface gates.

All context and managed-head observations are rechecked after native capture;
the kernel/process context is checked as well. Object/collection code anchors
are compared before and after the optional phase. The runner checks the ADB PID
again before reporting. A membership/context change, unresolved head, override,
unsupported virtual path or native failure produces no coordinates for that row.
Successful rows are not returned if final phase code/process checks fail.

The first two verified nonlocal members are selected in roster order. This
includes supported observing/watching classes rather than inventing enemy
semantics. Membership alone does not establish a live combat target. Other
candidates remain unsampled; success is explicitly per object, not a claim that
the entire roster's heads are known.

## Read budgets

The optional phase uses the same Reader and global physical count/timer. The
Physical method additionally honors a nested temporary call ceiling. Scope
creation/restoration never resets the count or elapsed time, and nested limits
cannot expand a stricter parent limit. The global 30000-call/120-second checks
remain in force on every physical call.

The outer optional ceiling permits at most min(6000, remaining global calls).
The inner sampling ceiling keeps 1000 of that allowance for final code/process
checks, so at most 5000 calls are spent on initial checks and head attempts.
If 1000 or fewer global calls remain, the phase returns READ_BUDGET_RESERVE
without reading. An expensive hierarchy stops with READ_LIMIT_REACHED. Its
partial coordinates are discarded; an earlier successful row may be retained
only if final phase checks pass. Final checks still remain inside the outer
ceiling. A typed scope exception passes through native identity checks without
being mislabeled as a byte mismatch.

The earlier local-head/collection observations are reported before this phase.
The optional phase cannot retroactively make those samples current: all values
are non-atomic observations, with no guest locks/GC roots/VM pause. The two
objects' positions do not represent one synchronized game frame. Lifetime races
and changes returning to the same bytes remain possible despite rereads.

## Output and validation

OtherHeadSamples reports eligible/attempted/sampled counts and a stop reason.
Each OtherHeadWorldPosition line identifies its roster index, object and class;
XYZ is printed only for SAMPLED_READ_ONLY. Context, hotfix, missing-head,
read-limit and failure outcomes are distinct. No aim direction or target choice
is applied from these observations.

223 offline checks pass using PowerShell 7.4.6 and C# 5 compatibility: 51
core/kernel, 31 module, 30 metadata and 111 object/native/collection cases. New
checks cover scope exhaustion/restoration/nesting, a remote object's distinct
head through both direct and model-cache paths, preserved local coordinates,
missing head without substitution, changed
entry key/version/local marker, hotfix overrides, membership mutation during
native capture, independent coordinates for two members, the two-object limit,
a deep hierarchy reaching the read cap, global budget reserve and prerequisite
rejection. The one-object native fixture spends 2774 additional calls including
phase identity checks and records 159 combined observations.

These are synthetic implementation checks. The next Windows report is needed
to establish a live other-head sample for this BlueStacks/game build.

## V18 motion classification

After three TRS-only mismatches, local and other-head callers return
NOT_READY_MOTION with no coordinates. The native reader's byte comparisons,
identity checks and attempt limit are unchanged. Other-head managed/context
snapshots are still rechecked before reporting that unavailable status. An
identity or membership mutation remains a failure and cannot be hidden by
motion classification. The optional phase can run after an unavailable local
pose if the independent typed collection was accepted. No stale local XYZ is
substituted. V18's 229 offline checks include these motion and independence
cases; a live other-head sample is still unverified.

## V19 fresh selected-entry membership and field diagnostics

Two V18 reports demonstrated distinct windows: one changed the dictionary's
free-list during capture; the latest rejected earlier collection context before
native capture. Its combined pointer/counters message does not identify which. A saved roster is an observation from a previous phase, not a lock.
V19 replaces only the requirement that current counters equal that old header.
It still requires the same current game/match/local pointer chain, dictionary
pointer/class, entry-array pointer/class/capacity and selected original 40-byte
entry at the same slot. No object is substituted or newly enumerated.

At phase entry, a separate bounded ObjectReads snapshot verifies the exact
closed dictionary and entry generic contexts, metadata/key/value types,
array element descriptor/runtime entry size, dictionary size, field registration
and the saved storage identities. This shared schema is rechecked at phase end,
inside the existing reserved final allowance. Keeping immutable schema checks
once per phase avoids repeating them for each selected member. If final schema,
code or process checks fail, all tentative rows are discarded.

Each selected member captures a fresh 16-byte header. Used slots must be <=256,
free count <=used, and the signed free-list head must be -1 or a bounded slot.
Capacity must cover used and remain <=8192. The original selected index must
still be inside the fresh used range. Its 40 bytes must equal the saved proof,
its signed hash must be active and its next index bounded by the fresh count.
Class/parent and nonlocal marker are revalidated. Exact entry bytes include the
key and value; neither is printed as an account ID. Fresh counters and all
selected context/entry bytes are reread after native capture. A during-capture
change returns NOT_READY_CONTEXT_CHANGED with no XYZ or accepted membership
proof. Before-capture changes to other entries do not require a new full roster
scan if this selected proof can be re-established.

This proves only the selected entry's observed membership, not current global
collection consistency or a fresh full roster. Historical roster counts and
objects are never rewritten or merged. CountersChangedSinceRoster explicitly
reports header differences. MembershipProof=FRESH_SELECTED_ENTRY is assigned
only after per-object final checks. Lifetime/ABA races are still possible;
there is no GC root, lock, engine call, VM pause or synchronized frame.

Only snapshot mismatches labelled OtherMembership.* receive the context-change
classification. Other managed/native/code/type/transport failures retain their
failure behavior. Native diagnostics label bindings, managed/native links,
hierarchy job handle/tag/capacity and parent/index/backlinks; an unknown prior
address is not retrospectively mapped to a field. No native identity change
gets a new retry. The TRS-only three-attempt rule remains unchanged. Rejected
other rows preserve provider/Transform provenance and attempted native count,
but never assign XYZ before all per-object checks pass.

The 6000-call outer phase / 1000-call final reserve and global count/time
budgets are unchanged. The expensive fixture stops sampling at 5000 calls and
completes reserved final checks at 5699 total additional calls. A simple single
other-head fixture uses 3354 additional calls, with 159 per-object observations
and separate phase-wide schema observations.

241 offline checks pass: 51 core/kernel, 31 module, 30 metadata, 129 object/
native/collection checks. New cases cover changed old counters, another entry
removed before capture, the selected entry removed, a shrunken used count,
invalid fresh counters and changed field registration, capture-time version/
free-list/selected-key changes, final schema invalidation, precise native field
labels and accurate rejected-row attempt counts. Existing distinct two-head,
model-cache, motion, identity-failure and read-budget tests still pass. Live V19
head sampling remains pending; no target classification or aim write is added.

## V20 selected-entry revalidation with endpoint counter audits

V19's latest failure was Field=OtherMembership.Counters, FirstChangedOffset=4,
a global free-list change during capture. That does not identify which entry
changed. A single dictionary's version/free-list is collection-wide state;
selected entry identity and supported Player/Transform ancestry are separate
checks. V20 reports this distinction instead of requiring unrelated header
bytes to stay constant throughout a long native read.

The optional observation contract is now SELECTED_ENTRY_REVALIDATED:

- The existing exact typed schema and field/code registration are still
  captured at phase start and rechecked at phase end.
- The same current game/match/local player, dictionary/class, entry array/class
  and exact capacity must match the previously verified storage and remain
  identical in the per-member snapshot recheck.
- Before capture, read the 16-byte counter header twice via the existing live
  virtual reader. Both copies must match. Used <=256, free <=used, the signed
  free-list is -1 or an index below used, capacity covers used and stays <=8192,
  and the selected slot must be inside used. An unstable endpoint stops with
  NOT_READY_CONTEXT_CHANGED; malformed counters fail.
- The exact original 40-byte selected entry must match, with active signed
  hash, bounded next link and the same stored key/value bytes. Supported object
  class/parents, nonlocal marker, original hotfix path and own managed/native
  head are still independently checked.
- After the native observation, perform another pair of matching counter
  reads and repeat the bounds/index checks. The selected next link must fit
  this final used count as well. Then recheck all selected entry, object,
  provider/Transform and other managed snapshots plus process context.
- Only after all per-member checks pass is the proof assigned and XYZ copied
  into a successful output row. Phase-wide final checks can still discard all
  tentative rows. Removed/changed selected entries, replaced storage, capacity
  changes and native identity errors are not excused by the counter audit.

CountersChangedSinceRoster compares the first audit with the historical roster
header. CountersChangedDuringCapture compares the before/after audited headers.
The latter reports observed endpoint differences, not every intervening update;
false does not prove that no change or ABA occurred. On a rejected row an audit
may not have completed, so flags alone are never a membership proof. Counter
contents and account/key data are not printed. The historical roster result is
never rewritten or claimed current.

A version/free-list change during the interval may accompany an accepted
selected-entry observation if both audited endpoints are bounded and the exact
selected entry and identities pass. It does not establish that only other
entries changed or that the selected object stayed continuously present. There
is no root, lock, pause or atomic transaction; selected removal/reinsertion or
address reuse returning to identical bytes can escape rereads, as can other
ABA/lifetime races. This output is a bounded read-only observation, not a safe
handle, synchronized frame or permission to dereference the pointer later.

The global 30000-call/120-second limits and optional 6000-call phase / 1000-call
final reserve are unchanged. Only four bounded 16-byte header reads per completed
member are used; no polling/retry loop is added. Native offsets/math/comparisons
and three TRS-only attempts are unchanged. The simple fixture uses 3364 extra
physical calls and 158 per-object snapshot observations plus separate counter/
schema checks. The deep fixture still stops at its read cap and completes final
checks at 5699 extra calls.

248 offline checks pass: 51 core/kernel, 31 module, 30 metadata and 136 object/
native/collection cases. The changed contract is explicitly tested: another
entry's removal or a global version change during capture can preserve the
selected observation, while selected removal/key changes, a shrunken final
used range, invalid final counts, unstable before/after header copies, replaced
dictionary, changed capacity/schema and native identity failures reject it.
Existing two-head, model-cache, motion and shared-budget cases still pass. Live
V20 nonlocal validation remains pending; no enemy/visibility or aim-write path
has been introduced.
