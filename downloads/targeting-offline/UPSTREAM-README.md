# Advanced targeting extension for V49

This package extends the previous engine-independent C# library. It adds mesh
LOS, stable target acquisition, bounded direction control, and a host-output
coordinator. The original V49 reader and the previous basic package are preserved.

**Status: implemented and tested offline. Live Free Fire integration is unbound.**
This package does not extract collision geometry, inject a DLL, write game memory,
invoke game methods, or supply an undocumented aim setter. The included output
adapter controls only its own local simulation state.

## What changed

| Component | Implementation |
|---|---|
| Target validation | Affirmative identity/head/alive/hostile/attackable proofs; duplicate IDs, invalid numbers, range, angle and observation age checks |
| LOS | Immutable triangle geometry, median-split BVH, two-sided segment intersections, snapshot matching, work limits and numeric uncertainty reporting |
| Target stability | Weighted angle/distance score, deterministic ID tie-break, switch margin and consecutive observation confirmation |
| Direction control | Unit-vector angular movement limited by degrees/second and observation time; deterministic antiparallel handling |
| Output integration | Authority recheck, command session/sequence/expiry, apply/reject protocol, revocation on invalid update and latched adapter faults |
| Diagnostics | Typed update status; eligible/rejected/ray counts on controller decisions; node/triangle counts and reason on detailed LOS queries |

No stale LOS cache, extrapolated target positions or obstacle penetration is used.
No prediction/ballistics claim is made without measured velocity/projectile data.

## Build and run

Windows PowerShell with the installed .NET Framework x64 compiler:

```powershell
& .\Build.ps1
& .\Test-Advanced.ps1
& .\SimulationDemo.exe
```

The compiler uses C# 5 and treats warnings as errors. The managed library is
`HeadBridge.Targeting.Advanced.dll`; it has no native dependencies. Do not load
the previous library and this library together: the advanced package includes
the earlier types for source compatibility. Prefer `AdvancedController` and
`AimCoordinator` over the preserved basic `Controller`.

The demo runs three observations: confirm acquisition, apply a simulated command,
then introduce an obstruction and revoke the command. A final disable also clears
the simulated output. `SimulationDemo.cs` is the complete host-binding example.

## Verification

See `validation.txt`, `simulation-validation.txt` and `compatibility-validation.txt`.
The suite contains 20 baseline assertions and 259 advanced assertions, including
200 seeded randomized rectangle cases checked against an independent analytical
intersection oracle. Counts are assertions, not independent live scenarios.
Fault, expiry, replay, clock regression, session changes, confirmation interruption,
target death, geometry budgets and output recovery are covered.

The complete reviewed V49 C# source set plus the four runtime extension sources
was compiled together in C# 5. This is source compile compatibility, not proof of
binary drop-in compatibility, V49 runtime integration, or gameplay operation.
The existing V49 test suites and live diagnostics were not run for this package.

## Host contracts and limits

Read `INTEGRATION.md` before implementing an adapter. Inputs marked `Proof.Yes`
are assertions by the host; this library cannot independently establish their
provenance. V49's same-team/model-visibility/raw-life fields must not be promoted
to complete hostility, attackability or LOS proof without validation.

Geometry is a complete, already filtered set of blocking triangle surfaces in
the frame's coordinate space. It is not a solid-volume containment test. Near
parallel/coplanar cases produce Unknown conservatively. Constructor validation
rejects degenerate triangles and coordinates outside +/-100,000,000 units.
Mesh construction is synchronous, capped at 100,000 triangles, and outside the
per-update time budget; do not rebuild large meshes inside a frame callback.

Node/triangle/candidate/ray budgets bound work. Time budgets are checked before
and after queries; they cannot interrupt a synchronous provider or output call
that hangs. A production host needs bounded callbacks and application-time expiry
enforcement. No real-time latency or FPS improvement was measured.

Hysteresis never waives current eligibility or LOS. Confirmation counts accepted
new observations, not rendered game frames. On disable, failure or occlusion the
previous command is revoked. A host must invoke updates on data loss or its own
watchdog must expire the command if observations stop arriving.

The output is a direction vector, not a game-specific quaternion or yaw/pitch.
The angular step begins at the latest observed forward vector and uses elapsed
observation time capped at 50 ms (initial update uses 16 ms). The observed camera
need not exactly follow earlier commands. Session changes require recreation of
the controller/coordinator with a new host session.
