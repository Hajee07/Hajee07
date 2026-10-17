# Binding guide and reproducible live experiments

No live provider or actuator is supplied. Do not assign Proof.Yes merely to make
this simulation run against a real process. Historical report text is evidence
data, not a current observation or an executable command source.

## Supplied components

- V52: existing bounded, read-only guest diagnostics; unchanged.
- ObservationPipeline: provider-proof validation and latest measured-head tracking.
- AdvancedController/AimCoordinator: unchanged selection, bounded angle and host coordination.
- Box/Mesh LOS: owned synthetic geometry only. Boxes are closed solids; mesh is
  triangle surfaces, not a solid-volume containment oracle.
- ExpiringCommandLease: local simulation output with atomic local checks and idle expiry.

There is no function converting a V52 log into an authorized live Frame. The
existing strict `Assess-V52Binding.ps1` deliberately reports missing proofs.

## 1. Camera experiment — BLOCKED pending controlled captures

For each stated game build and mode, record process/emulator epoch, match/session,
rendered frame/video time, provider start/finish times and camera/transform identity.
Record initial stationary view, right/left movement, up/down movement, translation,
mode transition, respawn, spectator/cinematic and restart cases. Establish mapping
between rendered movement and sampled position/rotation; compare candidate cameras
rather than selecting one because it is labelled main. Record forward axis,
handedness, units and matrix multiplication/storage convention from experiments.
Test accepted shot direction separately; view direction is not a shot convention.
Use capture intervals to state synchronization uncertainty. Unsupported modes must
return Unknown; a plausible quaternion/controller link does not pass this experiment.
Historical native-pose samples are not a fresh reproduction of these cases.

## 2. Target provider — BLOCKED pending semantic/lifetime contracts

Populate all eleven independent state proofs with evidence, not team-ID inequality
or a single life flag. If dying/revive/spectator semantics are unavailable, their
corresponding proofs stay Unknown. Supply match membership and nonlocal proof.
Define generation/lifetime tokens across despawn, reuse, respawn, match transition,
reconnect, game restart and emulator restart. Capture before/after identities and
uncertainty; reject any mixed snapshot. A raw address is only an observation locator.
Use complete-roster proof only when absence/despawn can be established.

Reproduce each transition with explicit expected identity continuity or invalidation;
log accepted/rejected counts, gaps and reacquisition. The simulation covers these
contracts with synthetic provider proofs, not verified Free Fire semantics.

## 3. Head provider — BLOCKED pending repeated live evidence

Reuse verified head-bone/transform readers only with the identity and state scope
they actually establish. Supply world-space measured head coordinates and capture
intervals. Test stationary, translation, animation, crouch, respawn and restart.
Record sample age, capture uncertainty, rejections, missing intervals and recovery.
Do not reuse a previous sampled head when the current hierarchy is inconsistent.
Keep prediction in separate types if added later; this review adds none.

## 4. LOS provider — BLOCKED, no authoritative live query/world

A live query contract must establish origin/end, coordinate space, layer mask,
trigger policy, observer/target exclusions and current query/world generation.
Alternatively supply demonstrably complete matching static/dynamic collision
geometry with those filters. Test clear/blocked, moving obstacle, thin surface,
endpoint contact, origin inside a solid, excluded observer/target, and each relevant
layer/trigger setting. Unsupported cases return Unknown.

Source audits show IsStreamerVisible can return true or inspect a cached bit.
Neither it nor AimCheckPlayerStreamerVisibility is head LOS. The collision API
signature alone establishes neither engine-thread requirements nor live policy.
The owned synthetic box/mesh fixtures do not reconstruct the game's world.

## 5. Output binding — BLOCKED pending verified engine interface

Missing contract: exact callable/setter identity, parameter/return types and ABI,
ownership, execution thread, orientation/shot conventions, lifecycle, timing and
submission result semantics (queued vs applied vs acknowledged). Existing exports,
field names and source RVAs do not supply that whole contract.

Once independently established in a supported test environment, implement
IAimOutput on the required host thread. Recheck epoch/session/sequence/generation,
eligibility/camera and expiry at actual application, enforce bounded angular change,
provide cancellation/acknowledgement and an actuator-owned watchdog. Check time after
expensive work. A synchronous callback cannot be force-cancelled by elapsed-time
checks. Test disable, loss of observations, rejected output, late queue delivery,
fault, explicit recovery and process restart before any live-game acceptance claim.
The supplied lease is only a simulation example of these local checks.
