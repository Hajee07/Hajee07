# V47 controlled native camera pose comparison

Live V47 eight-stage manual comparison passed. See
GAME-CAMERA-ENTRY-GATES-EVIDENCE.md for the accepted result and V48 scope. This is a manual experiment, not
camera-control automation or aim integration. Existing native probe logic,
read/time limits and cleanup are unchanged; the core runner reports V47.

## Accepted V46 live sample

The supplied Pie64 report (HostPID 12744, GuestPID 4680) selected native camera
0x70cc37bd5610, owner 0x70cc380ba710, Transform 0x70cc38d83db0. Position was
(63.8740158,12.8711138,23.9988022), parent count 0. Camera quaternion was
(-0.02341957,0.588725567,-0.0170679279,-0.8078134), norm squared
1.0000000824064808. Native source, selected local context, position and rotation
checks passed, 4688 phase reads / 26298 total. Cleanup passed. Two moving head
captures were discarded and the third passed. Printed aim and camera quaternion
values closely agree in this sample; this does not establish a universal
relationship or the game's selected camera. These addresses are historical.
V47's parser also accepts this actual uploaded V46 report.

## Manual stages

Run `Run-CameraPoseCheck.ps1` in Administrator Windows PowerShell with Training
already running. Remain in the same character/match. Do not walk, fire, reload,
switch weapon or aim down sights during the experiment. Keep one tree/building
as a landmark. Every capture starts only after typing READY and keeps its own
existing per-run budgets; there is no polling or automatic input.

1. BASELINE: landmark at screen centre, roughly level.
2. RIGHT: turn camera right; landmark moves left on screen. Stop.
3. RESTORE: same landmark back to its original centre and height. Stop.
4. LEFT: turn camera left; landmark moves right on screen. Stop.
5. BASELINE: return landmark to original centre and height. Stop.
6. UP: tilt camera up; landmark moves down on screen. Stop.
7. RESTORE: same landmark back to original centre and height. Stop.
8. DOWN: tilt camera down; landmark moves up on screen. Stop.

A small clear turn is enough; no angle needs to be entered. The existing
comparison policy accepts absolute yaw changes 3..90 degrees, pitch 3..60,
restoration and cross-axis drift within 5 degrees, and avoids elevations above
70 degrees. Both opposite sign conventions can be reported. Thresholds are
experiment checks, not an accuracy or shot-convention guarantee.

## Validation and scope

The functions-only parser validates the existing aim/local identity, pinned
module/layout proof, budgets and cleanup plus unique native camera source,
selection, position and rotation records. It verifies canonical/aligned native
pointers, bounds, finite values, raw quaternion norm and the printed positive-Z
basis. It preserves raw camera quaternions and records position. Angles come
from the native camera's quaternion-derived basis, not the player aim basis.

All eight captures must retain version, machine/process/device, module, game,
match, local player, Unity bias, native camera/owner/Transform identity. A context
change or failed restoration/turn check yields INCONCLUSIVE. Existing roster
counter changes are retained as an audit with selected-local membership proof.
The wrapper checks helper/runner checksums, explicit READY prompts, child exit
status, unique result paths in its package directory and fresh result files.
Cancellation, child failure, stale/missing or malformed report stops the run.
It saves eight raw source report paths/hashes and one comparison JSON.

A separate abs-normalized-dot angle metric compares camera and aim quaternions,
accounting for q versus -q. The normalized dot is only an angle calculation;
raw data is never normalized, flipped, smoothed or overwritten. Agreement within
one degree is reported as a diagnostic observation and does not gate native
camera turn evidence. Position changes are recorded; orbiting camera movement
is not treated as proof that the character moved or stood still.

Even a successful manual correlation does not verify the actual game camera
getter, managed wrapper, IFix hotfix/fallback, rendered camera or shot direction.
The captures are sequential, not atomic or a continuous stream. Full LOS,
combined target eligibility, aim updates and live end-to-end aiming remain
incomplete. All probes remain read-only and invoke no game/native functions.
