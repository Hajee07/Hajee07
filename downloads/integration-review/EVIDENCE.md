# Evidence matrix

Statuses describe separate scopes. IMPLEMENTED does not imply live validation;
OFFLINE_VALIDATED does not imply LIVE_VALIDATED_FOR_STATED_SCOPE.

| Task | Implemented / tested scope | Status | Missing live dependency |
| --- | --- | --- | --- |
| Active camera | Existing V52 parser/camera source checks; new pipeline rejects unproved camera/coherence; experiment protocol supplied | OFFLINE_VALIDATED for rejection logic; LIVE_OBSERVED for historical pose data only; BLOCKED for active-camera acceptance | Synchronized rendered-view/shot observations and identity/conventions for each stated mode |
| Target validation | Eleven independent provider facts; per-target tri-state outcomes; bounded complete batches; session/sequence/epoch checks | IMPLEMENTED, OFFLINE_VALIDATED; BLOCKED for live provider | Authoritative identity/generation, life/hostility/attackability/membership semantics and coherent observations |
| Head tracking | Latest measured sample, capture interval/age; generation-specific keys; stale/rejected/despawn gaps and explicit restart reset | IMPLEMENTED, OFFLINE_VALIDATED; BLOCKED for live tracking acceptance | Repeated verified nonlocal head samples across movement/animation/respawn/restart with lifetime evidence |
| Actual LOS | Existing geometry library retained; closed-solid box fixtures and inherited rotated triangle oracle; Unknown on incomplete/mismatched worlds | OFFLINE_VALIDATED for owned geometry; BLOCKED for actual LOS | Authoritative query or complete filtered current static/dynamic collision world |
| Aim-update | Existing bounded controller + new expiring local lease, enable/revoke, application checks, replay rejection, clock faults/recovery, timer/host polling | IMPLEMENTED, OFFLINE_VALIDATED for owned simulation; NOT_IMPLEMENTED / BLOCKED for live actuator | Verified engine interface/ABI/thread/conventions/lifecycle and applied acknowledgement contract |

No task is marked LIVE_VALIDATED_FOR_STATED_SCOPE in this review. Source-level
IsStreamerVisible/config identification is not a live LOS test. Earlier success
reports remain historical user-supplied data, not observations of today's runtime.

## Input scope and integrity

- `evidence/baseline.json`: actual runtime runner **52**, pinned runtime archive hash,
  48 source-manifest entries, uploaded extension SHA and 16 internal file entries;
  four library sources byte-identical to the uploaded archive.
- The archive's V49 label describes its original extension baseline. It does not
  downgrade the verified V52 runtime or make it a new live adapter.
- Native binaries in the upload were not loaded. No new DLL injection, game calls,
  process-memory writes, security bypasses or settings changes occurred.

## Tests run now

- `evidence/baseline-v52.txt`: existing full V52 checks, **1028 PASS lines**, process
  exit 0. Line-end whitespace is normalized for Git; raw/normalized hashes are
  retained in `evidence/log-normalization.json`. Expected negative fixtures are PASS results; they are not runtime failures.
- `evidence/baseline-targeting.txt`: **579 assertions** (20 baseline, 259 advanced,
  300 seeded rotated geometry checks), source compatibility plus local simulation.
- `evidence/review-tests.txt`: review validation/lifecycle/geometry/adapter assertions
  with source compiled together with V52 using C# 5 and warnings treated as errors.
  The final assertion count and observed watchdog timing are recorded in that log.
- `evidence/historical-v52-assessment.json`: fresh parser assessment of a **historical**
  complete user V52 report. It still reports LiveBindingReady=false and the exact
  missing contracts. This is not a new capture or end-to-end test.
- `evidence/package-checks.txt` (repository-only, outside the archive to avoid self-reference): the review source archive extracted and its own
  standalone runner executed; source manifest file lengths/hashes checked.

Tests use synthetic provider Proof.Yes assertions solely for the owned world.
For each of the eleven facts, Unknown and No exclude the candidate and retain
that proof in the outcome. Camera/coherence/complete-roster uncertainty prevents
frame publication. Cases include candidate bounds, invalid/future/stale times,
post-validation budget overrun, duplicate/replayed identities/sequences, generation
replacement, movement, despawn, process reset/reacquisition and clock failure.

Geometry fixtures specify their complete owned closed-box world: clear, thin solid,
origin inside, endpoint contact, tangency, off-ray solid, changed snapshot, incomplete
world and wrong world sequence. Layer/trigger filtering and actual game collision
freshness are unsupported, not implicitly satisfied by these fixtures.

The simulation's recorded sequence is Acquiring -> Applied (local lease) ->
NoVisibleTarget (revoked), followed by generation reacquisition, expiry with no
new observations, context loss/disable and explicit recovery. The timer test
waits for ExpirationCount without calling Snapshot or Poll: this verifies that
the scheduled watchdog itself revokes the held local command. Timing is observed,
not a hard real-time bound or a performance improvement claim.

## Acceptance still requiring live evidence

Follow INTEGRATION.md procedures and retain build/mode, timestamps, identities,
uncertainty, expected/observed outcomes and rejection/recovery counts. Acceptance
must include rendered camera agreement, nonlocal head continuity, actual clear/
blocked/layer/trigger/dynamic collision cases and real engine acknowledgement.
None can be inferred from a mock sink or a native pointer's plausible contents.
The cloud has no connection to the user's running Windows emulator.
