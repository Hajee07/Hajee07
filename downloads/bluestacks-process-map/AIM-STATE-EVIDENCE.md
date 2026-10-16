# V35 original local GetAimRotation snapshot

V35 Windows validation passed; V36 validation pending. Run `Run-ProcessMap.ps1 -ProbeAimState` with
Free Fire running and hold the camera steady during capture. This tenth mutually
exclusive mode replaces other optional phases. It does not invoke an aim method
or write to the game.

## Source and runtime identity

Player.GetAimRotation is method 210726, RVA 0x6f249ac, length 0x54, inactive-hotfix
gate 0x4b9. It is an instance nonvirtual getter. Its original branch loads four
floats into s0/s1/s2/s3 from Player+0x614/+0x618/+0x61c/+0x620.
The registered field is Player local 280, <AKKPEKIHGAH>k__BackingField, Quaternion
+0x614. This is distinct from m_CurrentAimRotation at +0x1a8c, which is not read
or substituted. No setter is called.

The builder derives and checks the exact getter instructions, registered pointer,
metadata, field name/type/offset, Quaternion type identity and component order
from SHA256-verified inputs. Quaternion is value type 40980: boxed size 32,
unboxed size 16, x/y/z/w float fields at boxed offsets 16/20/24/28. The native
four-float getter agrees with that unboxed component order.

Runtime checks cover complete getter code initially/finally, method registration
and metadata, the actual Player FieldInfo (count/index/name/descriptor/owner/
offset/token), source field/component registrations, component descriptors,
Quaternion metadata record and resolved getter return type. Original gate 0x4b9
must be inactive. The selected verified roster member must be local.

Only finite values with squared norm in [0.98,1.02] are exposed. Values are not
normalized, smoothed or converted to angles. Nonfinite/nonunit values yield
explicit NOT_READY statuses with no quaternion components. The sign of a valid
Quaternion is preserved. Recorded bytes, context/membership and gate are
rechecked; changes discard tentative values. Final code/schema failure clears
the phase. Other shared state prerequisites remain strict.

This is a snapshot of the original GetAimRotation value, not an asserted camera
orientation, screen projection, target direction, predicted shot trajectory or
current-aim-field mapping. Head/roster/aim phases are sequential, not atomic.
No Quaternion-to-camera convention, target selection, LOS, aim accuracy or aim
write is claimed from this snapshot.

## Bounds and validation

Phase bounds remain 6000 additional physical calls and 1500 final-check reserve;
global bounds remain 30000 calls / 120 seconds. The fixture uses 3237 additional
reads. Earlier weapon, firing and ammo mode costs remain unchanged. No VM pause,
initialization, native method invocation or memory write occurs.

684 offline checks pass: all previous 659, 24 new aim cases and one comparison
compatibility case for version 35. New cases cover original backing-field identity,
component order/sign, nonfinite/nonunit values, hotfixes, source/runtime field
mismatches, return/value-type/component layout, changing quaternion/gates/member,
final code, local-only selection, prerequisites and call reserves/ceilings.
Generated references reproduce byte-for-byte. Extracted release checks compile
C# 5, parse PowerShell, verify ten exclusive modes and all source/helper/plugin
digests, and execute the complete suite. The existing manual HUD comparison
workflow accepts the unchanged version-35 counter contract.

Inspect LocalAimRotation, AimQuaternion, AimStateMembership, AimStateSamples,
cleanup and ResultFile. A sampled row with a NOT_READY/hotfix status does not
establish a usable aim rotation. Full readiness, camera convention, LOS and aim
integration remain incomplete.

## Accepted V35 Windows snapshot

The uploaded V35 report verified the exact module and both 80-check layout
passes, all 12 roster objects (local plus 11 others), and the local Quaternion.
X=0.002605755, Y=0.5796037, Z=0.001853381, W=-0.8148922;
NormSquared=0.999999964012677. The original local getter and selected membership
were verified without normalization. Aim phase used 3297 additional reads;
total reads=22754. Plugin unload, handler cleanup and session release passed.
This proves a local original-getter snapshot, not an actual shot/camera direction.

## V36 derived positive-Z basis

Live V36 validation pending. `Run-ProcessMap.ps1 -ProbeAimState` additionally
reports QuaternionPositiveZBasis: the verified Quaternion applied to the
explicit input vector (0,0,1). CameraConvention and ShotDirection remain
UNVERIFIED. No target, LOS, screen projection or firing readiness is inferred.

The exact ELF/metadata builder verifies Quaternion.op_Multiply(Quaternion,Vector3),
method 317467, RVA 0x9fddc4c, length 0xa4. UnityEngine.CoreModule.dll has its own
code module at 0xa729470, 4752 methods, pointer table 0xaf5a718. Assembly-CSharp's
method table is not used for Unity methods. Full multiply instructions, module
name/count/table, method registration and runtime metadata are verified before
and after capture. These checks extend the existing original getter checks.

The host calculation follows the native scalar float multiply/add/subtract
order, including zero terms. It does not call the native method, normalize the
Quaternion/vector or write memory. For unit q=(x,y,z,w), the positive-Z basis
has mathematical components (2xz+2wy, 2yz-2wx, 1-2xx-2yy). This algebra does not
establish which direction the game's camera, weapon or projectile uses.
Tentative basis values are discarded with any failed snapshot/final identity
check. Nonfinite/nonunit/hotfix statuses publish no basis.

700 offline checks pass (684 previous, 15 new basis/identity cases, one comparison
version-36 compatibility case). Cases cover identity, sign, half turns, yaw,
pitch, mixed axes, preserving source values without normalization, initial/final
code and module/method/metadata mismatches, and shared invalidation. The existing
mutation tests also require no basis after nonfinite or changing snapshots.
Fixture phase cost is 3347 reads; limits remain 6000 additional / 1500 final
reserve, 30000 global / 120 seconds. C# 5 compilation, PowerShell parsing,
exclusive modes, extracted-package suite and all source/helper hashes pass.
Previous weapon/ammo workflows remain available. No live V36 claim is made.

## Accepted V36 Windows capture

The uploaded V36 run passed module/layout identity and sampled the original local
Quaternion (0.01869106, 0.05843848, -0.001094339, 0.9981154), squared norm
1.00000000109373, without normalization. Source-verified positive-Z basis:
(0.1166158, -0.03743957, 0.9924712). The original getter, runtime registration,
Unity multiply and local membership rechecks passed. There were 14 verified
roster objects (local plus 13 others). A moving TRS sample was discarded on
attempt 1; the second independent head capture passed. Aim phase reads=3407;
total=25377. Plugin unload, handler cleanup and session release passed.
The V37 comparison parser independently accepted the uploaded V36 report and
checked its printed Quaternion/basis agreement. This remains a derived basis,
not camera convention or shot direction evidence.
