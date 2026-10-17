# V44 original native camera-selector sampling

Live V44 Windows output confirmed one selected original native camera with
predicate byte 1, complete source selection and cleanup PASS. See
CAMERA-POSITION-EVIDENCE.md for the accepted observation and V45 scope.
This extends V43's bounded native candidate walk with read-only evaluation of
its one verified virtual predicate and source-order native selection. It does
not call the function, resolve managed wrappers, read camera pose or control aim.

## Complete predicate source proof

The V43 observed predicate target RVA 0x50700c is exactly four ARM64 instructions:

```
ldrb w8, [x0, #0x38]
cmp  w8, #0
cset w0, ne
ret
```

Build-TransformReference.py verifies the exact four instruction words against
the SHA256-pinned Unity ELF, derives byte offset 0x38, emits the full 16-byte
CameraPredicateAnchors and target/offset constants. Any byte value 1..255 is
true; imposing a canonical 0/1 field restriction would not match this source.
Zero is false. No broader enabled/alive/visible semantics are inferred.

The existing verified selector at 0x608a98 walks tag-5 nodes in source order,
finds the first type-range component on each object, dispatches vtable+0xd0,
and returns the first component whose predicate has bit 0 set. The supported
predicate always returns 0 or 1. After false, source advances to the next tagged
object, not to a later component on the same object. V44 preserves this order.

## Strict selection behavior

Only predicate dispatch exactly equal to verified Unity bias+0x50700c is supported.
Its complete code is read and snapshotted before reading candidate+0x38. The
predicate byte, code, dispatch, type/range/array/owner/list roots and links, source
selector code, module and local game/player/Quaternion context participate in
exact rechecks. A false sample continues within the existing two-node bound.
Unknown in-image overrides stop at UNVERIFIED_PREDICATE_OVERRIDE; no target or
truth value is guessed, executed or skipped in favor of a later candidate.
Existing out-of-range/null/noncanonical dispatch refusal remains unchanged.

ORIGINAL_UNITY_MAIN_SELECTED_READ_ONLY means the verified original native
selector's sampled inputs identify SelectedNativeCamera/owner as its first true
result, with CompleteSourceSelection=True. A positive result needs the relevant
source-order prefix, not a scan of later nodes. ORIGINAL_UNITY_MAIN_NULL_READ_ONLY
requires the list to reach its sentinel with no true or unknown predicate. A
node/probe/component/type/root bound or unknown override cannot prove null.
These are bounded sequential snapshots with exact rechecks, not an atomic game
frame or a guarantee of what a concurrent game call returns at another instant.

CameraMainSelection records result/status, native object/owner, last raw predicate
byte, number evaluated, completion, Scope=ORIGINAL_UNITY_NATIVE_SELECTOR and
EvaluatedBy=READ_ONLY_SOURCE_EQUIVALENT. NativeCameraCandidate remains a separate
candidate record. The native selector's result is an intermediate of the managed
Camera.main icall; managed wrapper conversion/availability is not established.
The game-specific runtime getter's IFix/hotfix/fallback route is not evaluated.
Actual rendered/game camera, managed camera, pose, projection, shot direction,
LOS/eligibility and aim integration remain unverified. No writes, pause,
initialization, native calls or control automation are introduced.

## Validation

876 offline checks pass: previous 858, 16 predicate/source-order/mutation cases
and two V44 compatibility cases. New tests cover raw 1/2/255, false/exhausted null,
unknown overrides, predicate-code changes, byte/dispatch changes during capture,
false-first/true-second, two false predicates, first true short-circuit, ignoring
later components on a false object's component list, unknown-first refusal,
partial traversal and unresolved bindings. Existing two-node sentinel exhaustion
now verifies sampled null; candidate, collision, source identity and limits remain.

The restored V43 suite passed before changes. C# 5 compilation, PowerShell parsing,
ten exclusive core modes, all source/helper/plugin hashes, byte-for-byte reference
reproduction and the extracted-package suite pass. Candidate fixture phase=4003
reads; null-manager fixture=3843. Other mode phase costs remain unchanged. Global
30000-call/120-second, optional 6000-call and 1500 final-reserve bounds are unchanged.
Live V44 Windows/BlueStacks validation still requires the user's machine; no new
live result is claimed from cloud tests.
