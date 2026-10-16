# V37 manual camera-turn comparison

Live Windows experiment pending. Start `Run-AimBasisCheck.ps1` in Administrator
Windows PowerShell with BlueStacks/Free Fire already running. Three separate
child processes use the unchanged read-only -ProbeAimState pipeline. No camera,
mouse, keyboard, game method or memory write is automated.

1. In Training, stand still with camera roughly level; type READY.
2. Manually turn the camera right about 15-45 degrees, keep height unchanged,
   stop and type READY. Hold still throughout capture.
3. From the right-turn position, manually tilt camera upward about 15-30 degrees,
   keep horizontal direction unchanged, stop and type READY. Hold still.

Keep the same character/match and avoid moving, firing, aiming-down-sights or
switching modes. Do not return to the baseline before the third capture. Type
anything other than READY to cancel. These actions are user reported; the tool
does not observe screenshots or prove that the requested movements happened.

## Acceptance and interpretation

Each report requires the exact accepted module/APK/layout, original local getter,
source-verified multiply contract, sampled finite near-unit Quaternion and basis,
unchanged local membership counters, read ceilings and complete cleanup. Duplicate,
missing and unaccepted records are rejected; text is never executed. Printed
basis is independently compared to the Quaternion within 1e-5, allowing report
rounding/native float arithmetic. No source values are normalized.

Machine, host/game PID, device, version, build/load bias, CurrentGame, Match and
Player identities must agree across all three captures. Each child has its own
30000-call/120-second global and 6000-call optional-phase limits; this is three
explicit manual captures, not a continuous polling loop. The helper/child runner
hashes are checked against the downloaded package manifest before execution.
A child failure stops the experiment; a comparison is saved only after all three
accepted reports. Source report paths and parsed values are retained in JSON.

The host defines basis yaw=atan2(X,Z) and elevation=atan2(Y,sqrt(X^2+Z^2)), in
degrees, without asserting these are the game's camera angles. Yaw differences
wrap into (-180,180]. Baseline->right must increase yaw by 3..90 degrees; right->up
must increase elevation by 3..60 degrees. Cross-axis drift must be at most 5
degrees, and all captures must have absolute elevation at most 70 degrees.
These are conservative experimental thresholds, not recovered game rules or
accuracy estimates. Small/reversed/large turns, cross-axis drift or near-vertical
captures yield INCONCLUSIVE, not a new convention or a corrected vector.

A match yields CONSISTENT_WITH_REPORTED_CAMERA_TURNS with
MANUAL_CAMERA_TURN_CORRELATION_ONLY. CameraConvention, ShotDirection, LOS and
actual aim integration remain unverified even after a matching experiment.
Different camera modes and weapon/character behaviors are not generalized.

## Validation

742 offline checks pass: previous 700, one ammo V37 compatibility case and 41
new parser/comparison/wrapper cases. New tests exercise right/up signs, yaw wrap,
no/reversed/excessive turns, drift, vertical degeneracy, all context keys,
duplicate/missing/invalid reports, printed math agreement, bounds, cleanup,
invariant number parsing and incomplete experiments. A simulated child runner
verifies three manual stages, saved reports/JSON, checksum refusal, cancellation
and child failure. This does not replace live Windows/BlueStacks validation.

The existing C# 5 suite, PowerShell parsing, ten exclusive core modes, source/
helper/plugin hashes and extracted-package checks pass. Runtime C# sources,
original getter/math checks and their limits are unchanged from V36.
