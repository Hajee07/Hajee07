# Feasibility and compatibility assessment

## Conclusion

**Controlled game/server: feasible and implemented. Free Fire MAX body-hit-to-server-headshot conversion: unestablished and cannot be guaranteed.** Owning the adjudication rule makes conversion straightforward. Observing or changing a client-side location does not grant authority over a remote server. A protocol that accepts unchecked claims could behave differently, but no such behavior has been demonstrated here. No commercial-server protocol experiments or modifications are part of this lab.

“100% workable” is meaningful only for explicitly bounded fixtures: these six valid static sphere intersections can all be awarded Head under the owned server's conversion rule. It is not an accuracy, uptime, damage or anti-cheat guarantee. The same conversion policy rejects misses and blocked shots.

## What was actually reviewed

V48 was recovered from Git commit `b09fbf00cfd4461b1fd4b8700bf284060b0355b2`, not inferred from a filename. Its runner prints `ProcessMapVersion=48 ReadOnly=1`. Source inventory hashes are in `evidence/v48-source-inventory.json`. V48's entire mapper C# source/test set compiled as a separate .NET 8 library with zero warnings/errors; this is source compatibility, not Windows COM execution or ABI verification. Its native C++ was inspected, not rebuilt or loaded in this step.

The current checkout also contains V52 descendants, separately reviewed offline targeting sources and the source-rebuilt PlayerCamera reader. These versions must not be presented as identical to V48. Existing pending camera-resume edits were preserved separately.

| Component | Observed role | Relevance and reuse decision |
|---|---|---|
| Native `bridge.cpp/.hpp`, `plugin.cpp` | Windows x64 debugger plug-in using verified borrowed VM context and physical-read API; explicit ownership/unload rules | Useful for optional read-only emulator diagnostics. Not needed by this lab; not linked, loaded or redistributed. It is a plug-in inside HD-Player, so the overall existing system is not purely external/no-injection. |
| `GuestProcessMap.cs` | Bounded guest-physical reads, x86-64 guest page-table walk, kernel/task/mm/VMA verification | Reuse verification and bounds design. No server hit authority; build-specific VM/kernel assumptions. Keep production lab independent. |
| `ModuleProbe.cs`, `GameLayoutProbe.cs`, generated references | ARM64 ELF/IL2CPP registration/build verification | Useful compatibility evidence. Generated offsets cannot transfer across game builds or editions without revalidation. Not a hit-validation API. |
| `PlayerObjectProbe.cs`, roster/head/transform probes | Typed object chains, rechecked identities, transform hierarchy and world-coordinate samples | Useful read-only observations. Head coordinates are not a complete hurtbox, collider identity, shot collision or server rewind state. |
| V48 `AimStateProbe.cs` and camera evidence | Getter-entry and metadata-guard observations; no getter invocation or aim writes | Useful architecture diagnostics; getter/active-camera semantics remain limited. V48 README explicitly leaves actual camera unestablished. |
| Later PlayerCamera V3 | User-supplied log reports registered Player.MainCameraTransform position/rotation; current-map checks and cleanup pass | Evidence of one local field pose, not rendered-camera identity, projectile origin, LOS or remote hit acceptance. Three-stage follow-up has two valid samples and a third read-budget failure. |
| `targeting-offline/Targeting.cs`, `MeshLineOfSight.cs` | Engine-independent vectors, bounds/mesh occlusion and target geometry | Reusable **concepts** and test patterns. Their current target-acquisition/control output is not hit registration. New lab uses separate analytic ray-sphere code with independent oracles; old controller isn't linked. |
| `integration-review` | Simulation, explicit unknown proofs, adapter/lifecycle validation | Useful separation of evidence and control ownership. It supplies no verified live server authority. |
| Phoenix uploaded DLLs | Prior static PE/CLR reports only | Managed V48-named assembly needs matching transport/context; native DLL has no established callable contract for this lab. Neither is loaded. Their names/exports do not prove functionality. |
| AOB signatures and offsets | Build-dependent discovery/reference material | No portable semantic guarantee and no mapping to server logic. Not consumed by local game or server. |

## Data types and architecture

- Windows x64 host pointers, Android guest virtual addresses and guest physical addresses are different address spaces. A host DLL address is not an Android object address. The original bridge uses `uint64_t`, bounded `size_t` and a 24-byte native Address structure with static offset assertions; these native declarations apply only to its verified ABI.
- BlueStacks's x86-64 guest kernel and a game containing ARM64 libraries can coexist via its translation environment. Existing logs report x86_64 guest ABI and arm64-v8a application ABI. This does not make host x64 code directly callable as ARM64 Unity code. Exact translation internals were not reverse-engineered here.
- Original mapper uses `ulong` guest addresses and explicit little-endian byte decoding; generated field offsets/token/type IDs are not native C# struct layouts. Neither IntPtr size nor process bitness proves an IL2CPP object layout. Unity runtime metadata differs by build.
- Geometry in this lab uses **double** scalars, three doubles per Vec and four per quaternion. Units are documented meters; axes are +X right, +Y up, +Z forward in the owned scene. JSON is a semantic wire format: no raw struct casting, `Marshal`, `Pack` or inherited ABI. Enum names are strings on the wire; unknown/invalid inputs fail validation.
- Quaternion inputs must be unit length for geometry transforms. Raw camera quaternions from older probes are not silently reinterpreted as this scene's view/shot direction. q and -q represent the same rotation. Transform scale/shear and Unity conventions require separate adapters; this lab has rigid translation/rotation only.
- The new net8.0 application is separate from C# 5/Add-Type and .NET Framework runners. Installing .NET 8 does not make old binaries ABI-compatible. The original source compatibility compile is recorded, not used as proof of live interoperability.

## Facts, hypotheses and unknowns

| Evidence level | Statement |
|---|---|
| Confirmed by source/build/owned experiments | Owned server computes nearest finite ray-sphere collision, rejects wall intersections/replays and applies either geometric or conversion policy. Client claims are logged independently. |
| Reported by user's live logs | Previous physical bridge/module/layout/local-player and PlayerCamera V3 pose sampling passed for specified Free Fire build; later comparison third capture exhausted its read budget. These logs were not independently rerun on Windows here. |
| General architecture fact | Server-authoritative designs compute/validate accepted outcomes on the server. Client prediction and local UI may diverge from those outcomes. |
| Hypothesis to test only in an authorized owned implementation | A server trusting an unvalidated client hit-region field could accept false Head claims. This lab deliberately does not trust it. |
| Unknown | Free Fire/MAX's exact hit protocol, body-region encoding, rewind/hitbox rules, headshot acceptance implementation and tolerance. No server source/logs, documented authority interface or authorized remote test endpoint was supplied. |
| Not established | That any client data edit, external memory interface, AOB match, injection, head-coordinate read or local visual headshot results in a server-accepted headshot. |

The old APK/metadata evidence is for package `com.dts.freefireth`, version 1.132.1. A **Free Fire MAX** installation is not established by those artifacts. Package/edition/build/architecture verification would be a prerequisite even for a read-only MAX adapter; this project makes no such compatibility claim.

## Research topics and constraints

Player skeletal transforms place bones; hurtboxes can be separate primitives/meshes with animation, pose, stance and server history. Bullet collision may use hitscan, swept projectiles or more complex rules. Camera forward is not necessarily muzzle direction; weapon spread, recoil, obstruction and interpolation may alter the shot. This lab exposes only the declared static model, and its offline ballistic solver is a time-step approximation, not an undocumented recreation of Free Fire ballistics.

Server experimentation must distinguish client claim, client prediction, geometric collision, server awarded region and actual authoritative receipt/damage. A changed kill-feed or hitmarker alone is insufficient. In this lab every receipt carries actual collision region, award and claim comparison. Server policy is configured at process startup; it is never supplied by a shot.

## General technical references

These explain general contracts, not Free Fire implementation details:

- Unity IL2CPP overview: https://docs.unity3d.com/Manual/IL2CPP.html
- Unity Quaternion: https://docs.unity3d.com/ScriptReference/Quaternion.html
- Unity Physics.Raycast: https://docs.unity3d.com/ScriptReference/Physics.Raycast.html
- Unity Netcode authority: https://mp-docs.dl.it.unity3d.com/netcode/current/basics/ownership/
- Microsoft process architecture: https://learn.microsoft.com/dotnet/api/system.runtime.interopservices.runtimeinformation.processarchitecture
- Microsoft HttpListener: https://learn.microsoft.com/dotnet/api/system.net.httplistener
- Microsoft System.Text.Json: https://learn.microsoft.com/dotnet/standard/serialization/system-text-json/overview
- Android ADB: https://developer.android.com/tools/adb

The build/source inventory, not these general references, establishes this repository's observed behavior. Exact private-game semantics remain unknown.
