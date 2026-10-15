# V17 bounded nonlocal head samples

V16 verified the observed match dictionary's 14 objects (local plus 13 others),
including Player_Watching. It also repeated the live local-head sample after
rejecting one moving pose. V17 adds at most two nonlocal head samples. Its live
Windows validation remains pending. No enemy/team/alive/visibility classification
or aim-control write is implemented.

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
