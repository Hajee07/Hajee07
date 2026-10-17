# V46 original native camera world rotation

Live V46 source/rotation sampling and cleanup passed. See
CAMERA-POSE-COMPARISON-EVIDENCE.md for the accepted result and V47 experiment. Run `Run-ProcessMap.ps1 -ProbeAimState`
with Free Fire running and camera steady. V46 adds a `CameraWorldRotation` row
for the same native selector Transform intermediate as V45's position sample.
No game calls, synchronization, memory writes or control automation are added.

## Accepted V45 live result

The supplied Windows V45 report for Pie64, HostPID 12744, GuestPID 4228 selected
original native camera 0x70cc1e7abe10, owner 0x70cc1eb14610. Predicate raw byte 1
and complete original native selection were reported. Native Transform
0x70cc3b4e1cb0 had world position (70.0230255,12.7800512,16.5632763), with no
parent. The aim phase used 4550 physical reads, total 24881; final selected
membership and snapshot checks passed. Plugin unload, handler cleanup and
shared-session release passed. These historical addresses are never reused.
The local head's first moving capture was discarded and its second passed;
head and camera samples are separate sequential captures, not one atomic frame.

## Exact source path

The Unity image SHA-256 remains
1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77.
The named icall registration at RVA 0x46ea34 binds string RVA 0x16252a
`UnityEngine.Transform::get_rotation_Injected` to native target 0x45ee7c.
The full 0x108-byte getter resolves the native Transform and calls 0x6965d8
at 0x45ef0c. The complete 0xd8-byte world-rotation routine first calls the
already verified hierarchy access function 0x69304c, then reads the quaternion
at TRS row +0x10, following parent indices through the same hierarchy arrays.

For a root (negative parent index), it returns that sampled quaternion directly.
Otherwise it accounts for sign bits of parent scales, including negative zero,
composes parent quaternion with the child rotation, and repeats. It performs
no normalization. V46 requires the exact sign-mask constant at 0x1847a0 as well
as every instruction in the registration, getter and native world routine.
The generator verifies the registration address pairs, direct call chain and
sign-mask bytes against the SHA-pinned image; runtime snapshots recheck them.

CameraParentRotation preserves the native lane arithmetic order, explicit float
intermediates and XOR sign changes. It does not substitute player aim rotation.
Offline tests also compare scalar results bit-for-bit with independently
simulated ARM64 lane operations, including parent reflections, and exercise
noncommuting rotations, negative-zero scale, invalid quaternion rejection and
changed source/TRS snapshots.

Quaternion norms must remain in [0.98,1.02] with all components finite; otherwise
the tentative pose is discarded. No normalization or smoothing is applied.
The world rotation uses the same bounded, finally rechecked TRS rows as camera
position. Existing source/context/owner/hierarchy/job/backlink checks and
32-parent bound remain. Budgets are unchanged.

PositiveZBasis is calculated using the previously verified Unity quaternion
vector-multiply arithmetic for input (0,0,1). This is a mathematical basis vector,
not proof of rendered camera forward, game camera convention or shot direction.
Sequential rechecks are not atomic and cannot exclude every ABA change.

## Remaining verification

- A fresh Windows V46 capture is required to establish live source, hierarchy,
  position/rotation and cleanup checks for this version.
- V47 manual rotation correlation passed; independent translation and scene-change
  experiments remain pending.
- The actual game camera getter's hotfix/fallback path and managed wrapper
  identity remain unverified. Original Unity Camera.main selection alone does
  not establish that this is the game's rendered/aiming camera.
- LOS, combined target eligibility, aim updates and live end-to-end aiming
  remain incomplete. V46 performs no aim writes and establishes no hit accuracy.
