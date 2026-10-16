# V35 original local GetAimRotation snapshot

Live Windows validation pending. Run `Run-ProcessMap.ps1 -ProbeAimState` with
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
