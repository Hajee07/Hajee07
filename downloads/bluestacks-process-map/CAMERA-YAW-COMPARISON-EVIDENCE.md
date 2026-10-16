# V39 manual right/left yaw-sign experiment

Live V39 Windows validation pending. `Run-CameraYawCheck.ps1` performs four
separate unchanged read-only -ProbeAimState captures with explicit manual READY
prompts. It checks both possible observed yaw-sign patterns without changing the
original Quaternion/vector or the prior three-stage experiment's criteria.

1. In Training, stand still, camera roughly level. Put a fixed tree/building at
   screen centre and remember its position/height. Type READY.
2. Manually turn camera right a moderate amount (about 15-45 degrees): the
   landmark moves left on screen. Stop, type READY and hold still during capture.
3. Restore that same landmark to its original centre position and height. Stop,
   type READY and hold still. Do not move the character.
4. From the restored baseline, turn camera left about 15-45 degrees: the landmark
   moves right on screen. Stop, type READY and hold still.

The tool does not observe the screen, identify a landmark, automate controls or
prove the requested camera actions happened. Inputs are user-reported actions.
No game method calls, VM pause, initialization, writes, target selection or aim
control are added. Use the same match/character and avoid movement/fire/ADS.

## Acceptance and reporting

The shared parser retains exact accepted source/runtime getter/math/layout,
finite near-unit values, independent printed-basis math check, selected-local
membership proof and endpoint identities, original hard failures/read ceilings
and cleanup. It accepts versions 36 through 39. Global roster counter changes
are retained and audited; complete roster stability is not asserted.
All four captures must have identical version/machine/host+guest PID/device/
build/load bias/game/match/local-player context. Helpers/runner hashes are checked
against the downloaded manifest; child reports and final comparison JSON persist.
Each capture keeps its own original global 30000-call/120-second and optional
6000-call bounds. This is four manually staged runs, not a polling loop.

Basis yaw is defined as atan2(X,Z); elevation as atan2(Y,sqrt(X^2+Z^2)). Yaw deltas
wrap into (-180,180]. Restored baseline yaw AND elevation error must be <=5 degrees.
Right and left deltas each require magnitude 3..90 degrees and opposite signs;
right/left vertical drift must be <=5 degrees, and all elevations <=70 in absolute
value. These are experimental thresholds, not recovered game rules. Insufficient,
large, same-sign, near-vertical, drifting or unrestored captures are INCONCLUSIVE;
ObservedYawSign stays UNVERIFIED. No sample or vector is flipped or normalized.

Accepted reports use status REPORTED_OPPOSITE_YAW_SIGNS_OBSERVED and either
REPORTED_RIGHT_NEGATIVE_LEFT_POSITIVE or REPORTED_RIGHT_POSITIVE_LEFT_NEGATIVE.
Evidence remains MANUAL_CAMERA_TURN_CORRELATION_ONLY. This observes a relationship
for the reported movements/session; CameraConvention and ShotDirection remain
UNVERIFIED. No universal sign, camera projection, shot trajectory, LOS, aim
accuracy or complete integration is claimed.

## Validation

778 offline checks pass (750 prior plus ammo/aim V39 compatibility and 26 new
yaw-function/wrapper checks). Tests cover both observed signs, 180-degree wrap,
all context identities, missing/restored baseline, vertical drift/degeneracy,
small/large/same-sign turns, global counter audits, incomplete captures, and a
simulated four-stage wrapper verifying actual prompt order and saved report/sign
JSON. Existing cancellation/checksum/child-failure wrapper tests remain passing.
C# 5 suite, PowerShell parsing, ten core modes, source/helper/plugin hashes,
reference reproduction and extracted package tests pass. These do not replace
live Windows/BlueStacks verification. No runtime C# changes from V38.
