# V38 manual camera-turn comparison

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
revalidated selected local membership, read ceilings and complete cleanup. Duplicate,
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

The initial V37 release had 742 offline checks: previous 700, one ammo V37 compatibility case and 41
new parser/comparison/wrapper cases. New tests exercise right/up signs, yaw wrap,
no/reversed/excessive turns, drift, vertical degeneracy, all context keys,
duplicate/missing/invalid reports, printed math agreement, bounds, cleanup,
invariant number parsing and incomplete experiments. A simulated child runner
verifies three manual stages, saved reports/JSON, checksum refusal, cancellation
and child failure. This does not replace live Windows/BlueStacks validation.

The existing C# 5 suite, PowerShell parsing, ten exclusive core modes, source/
helper/plugin hashes and extracted-package checks pass. Runtime C# sources,
original getter/math checks and their limits are unchanged from V36.

## V38 selected-local membership correction

Two V37 baseline uploads stopped in the comparison helper with Unaccepted
AimStateMembership. The first reported counter flags True/False, the retry
True/True. Both original local rotation/basis captures had selected-entry
revalidation, unchanged-during-read identity checks and passing cleanup; totals
were 24485 and 27284 physical reads. Neither completed a three-stage experiment.

Review of PlayerStateProbe.ReadPlayerState and OtherHeadProbe.OtherCounterAudit
showed that the native reader deliberately audits global headers at bounded,
double-read endpoints while independently rechecking selected entry bytes,
active link, entry-array/dictionary identity, local marker/class, game/match/
local-player pointers, getter bytes, gates and values. Global counter differences
do not by themselves mean that the selected local player changed. V37's text
helper imposed a stronger complete-roster stability rule than this local-only
experiment needs. This was a helper acceptance bug, not a user camera error.

V38 accepts literal True/False counter flags only with the original required
SELECTED_ENTRY_REVALIDATED proof and all existing local/context/math/cleanup
checks. Both flags are retained in each sample and the JSON result.
RosterCounterAudit prints CapturesWithChanges and MembershipScope=
SELECTED_LOCAL_PLAYER_ONLY, CompleteRosterStability=NOT_ASSERTED. No counter is
ignored or changed to False. Invalid flags, missing/unverified selected proof,
changed game/match/player identities, failed cleanup and invalid source values
still fail. No native reader checks, read limits, code anchors or C# are changed.
Blank pasted-output lines are allowed without weakening required record checks.

Both original uploads now parse as accepted LOCAL_ONLY baseline observations in
offline regression checks. Their old experiment remains incomplete; no new live
V38 three-stage result is claimed. 750 offline checks pass (previous 742 plus
8 regression/compatibility cases), including 48 camera comparison/wrapper cases.
New cases cover all changing-counter flag combinations and preservation/audit,
unverified membership refusal, V37 report compatibility, blank lines and ammo
V38 compatibility. The extracted package, PowerShell syntax/ten modes, source/
helper/plugin hashes and unchanged C# 5 suite pass. Matching turns still mean
manual correlation only; camera/shot convention, LOS and aim integration remain
unverified.
