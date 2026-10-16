# V40 manual up/down tilt-sign experiment

Live V40 Windows validation pending. `Run-CameraPitchCheck.ps1` guides four
unchanged read-only -ProbeAimState captures: baseline, reported up tilt,
restored baseline, reported down tilt. This complements the accepted manual
V39 yaw experiment without flipping/normalizing source vectors or asserting
camera/shot convention. The original three-stage and yaw comparisons retain
their own criteria and results.

## Manual stages

Stand still in Training with camera roughly level. Put a fixed tree/building at
screen centre, remember its position/height, then type READY. Tilt camera UP a
moderate amount (about 15-30 degrees): landmark moves DOWN on screen. Stop,
type READY and hold still during capture. Return the SAME landmark to its
original centre position and height; stop and type READY. Then tilt camera DOWN
about 15-30 degrees: landmark moves UP on screen. Stop, type READY and hold
still. Keep horizontal direction unchanged during both tilts. Do not move,
fire, aim-down-sights, switch match/character or touch controls during capture.

The tool does not see the screen, track a landmark, observe the actual actions,
or automate controls. Actions remain user reported. No game method calls, VM
pause, initialization, memory writes, target selection or aim control are added.

## Acceptance and scope

The shared parser accepts versions 36..40 and preserves exact module/APK/layout,
original getter/multiply, finite near-unit Quaternion and independent printed
basis math checks, selected-local membership, context/value/gate rechecks and
cleanup. Global roster flags are retained and audited; complete roster stability
is not asserted. Version/machine/host+guest PID/device/build/load bias/game/match/
local player must agree across all four captures. Helper/runner hashes are
checked against the downloaded manifest. Source reports and comparison JSON
persist. Each explicitly requested child keeps its own 30000-call/120-second
global, 6000-call phase and final-check-reserve limits; no polling is introduced.

Basis elevation is defined as atan2(Y,sqrt(X^2+Z^2)), yaw as atan2(X,Z), in degrees.
Elevation differences are not wrapped; horizontal yaw drift wraps into (-180,180].
Each up/down delta must have magnitude 3..60 degrees, opposite signs, and <=5
degrees horizontal drift. Restored baseline elevation AND yaw error must be <=5
degrees. All captures must have absolute elevation <=70 degrees. These are
experimental thresholds, not recovered game rules. Invalid/insufficient/same-sign/
near-vertical/drifting/unrestored captures yield INCONCLUSIVE and UNVERIFIED sign.

Accepted status is REPORTED_OPPOSITE_PITCH_SIGNS_OBSERVED with either
REPORTED_UP_POSITIVE_DOWN_NEGATIVE or REPORTED_UP_NEGATIVE_DOWN_POSITIVE.
Evidence remains MANUAL_CAMERA_TURN_CORRELATION_ONLY, VectorFlipped=False,
CameraConvention=UNVERIFIED, ShotDirection=UNVERIFIED, LOS=UNVERIFIED and
AimIntegration=INCOMPLETE. No camera mode/weapon/character generalization,
projection, actual shot direction or accuracy claim follows from this check.

## Validation

806 offline checks pass (778 previous plus two V40 compatibility and 26 new
pitch-function/wrapper cases). New checks cover both signs, yaw-boundary drift,
all context keys, small/large/same-sign tilts, near-vertical views, landmark
restoration in both axes, horizontal drift, roster flag audit, incomplete runs,
and a simulated four-stage wrapper checking prompt order and saved reports/JSON.
Existing cancellation/checksum/child-failure checks remain passing. C# 5 suite,
PowerShell parsing, ten core modes, all source/helper/plugin hashes, reference
reproduction and extracted-package tests pass. Runtime C# and limits are unchanged.
These checks do not replace live Windows/BlueStacks validation.
