# Host integration contract

## Runtime flow

1. Create a `TargetingPolicy`, one `IMonotonicClock`, and an `AimCoordinator` with
   host implementations of `IFrameAuthority` and `IAimOutput`.
2. Capture a coherent immutable `Frame` with a session/generation ID, increasing
   sequence, timestamp from that same clock, verified camera origin/forward and
   currently proved target facts. Reused object addresses are not stable IDs;
   include a validated object generation in the host's string identity.
3. Obtain authoritative LOS through `ILineOfSight`, or build `MeshLineOfSight`
   from complete collision geometry associated with that exact observation.
4. Invoke `coordinator.Update(frame, enabled, los)` on the host's serialized
   observation path. It validates, scores, confirms, computes a rate-limited unit
   vector, rechecks authority and dispatches a command. No background thread is
   started by the library.
5. `IAimOutput.TryApply` must atomically revalidate session, sequence, target
   identity/eligibility, relevant camera/LOS observation and expiry at actual
   application time. A successful return means applied, not queued. Coordinate
   conversion belongs to this documented host adapter.
6. On any non-ready update the coordinator calls `Clear`. That operation must
   revoke held/queued output idempotently. `Update(null,false,null)` disables it.
   If observations stop, the host watchdog must revoke/expire the last command;
   no timer thread is supplied here.

Callbacks cannot reenter the coordinator. Exceptions in the authority/output
path latch `OutputFault`; explicit `ResetFault()` clears it only after the host
has recovered. If `Clear` itself fails the library reports that fault; it cannot
guarantee that an external actuator stopped. The host owns actuator recovery.

`AdvancedController.Step` also permits direct use without an output adapter.
Inspect its `AdvancedDecision` to display target/rejection/ray diagnostics in a
panel. `MeshLineOfSight.Inspect` returns geometry diagnostics. Neither requires
loading any native bridge. These classes share the project's `HeadBridge.Mapping`
namespace prefix and C# 5 baseline, but do not alter `Reader` or its checksums.

## What current V49 cannot supply yet

| Required contract | Current evidence gap |
|---|---|
| Coherent frame + generation-aware target identity | Bounded non-atomic read-only observations do not guarantee object lifetime or one synchronized frame |
| Proved attackable hostile target | Raw team/life/model flags are incomplete combat-eligibility evidence |
| Authoritative LOS | No validated engine collision query or complete dynamic collision-world snapshot |
| Current camera/shot convention | Native pose observations do not fully establish active game-camera/shot behavior |
| Aim application adapter | No documented, verified game/host actuator is supplied in V49 |

No live adapter is supplied because filling these contracts with optimistic
constants would silently turn unknown facts into accepted targets. The concrete
adapter in `SimulationDemo.cs` satisfies the contract only inside its own synthetic
world. It must not be presented as a Free Fire adapter.

## Build integration

Reference only `HeadBridge.Targeting.Advanced.dll` in the host, or compile these
four source files together with the host sources:

- Targeting.cs
- MeshLineOfSight.cs
- AdvancedController.cs
- AimCoordinator.cs

Do not include test/demo sources in the production host assembly. The supplied
build script already keeps them out of the library. This managed DLL is neither
a replacement for the native V49 physical-read bridge nor a native injection
payload, and it is not automatically connected to HajeePanel.
