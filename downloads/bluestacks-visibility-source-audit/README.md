# Visibility source audit (offline)

This step audits the existing model-visibility evidence and candidate visibility
APIs. It does not add or claim a runtime LOS reader. The latest Windows runner
remains V52; another Windows capture is not needed for this source-only audit.

## Results

- Original `Player.IsVisible` loads `Player + 0xad0`, then tail-calls the stored
  visibility-mask conversion. That is model-visibility data; it does not prove an
  unobstructed ray from the selected camera/muzzle to an enemy head.
- `IsVisibleByFlag` delegates to `GCommon.BitArray.HasFlag` on that same storage. An input flag
  is not a verified collision layer mask or LOS result.
- `GameFacade.CheckVisibleByCameraMode` delegates through another controller and
  has a `true` fallback when that manager is missing. The getter is
  `GameFacade.CurrentCameraModeManager`, distinct from the previously inventoried
  camera-controller field. Its delegate resolves to
  `COW.GamePlay.ICCMOIAKHOE.CKHGHGPDGGO` (identity verified; implementation pending). Its result cannot simply
  be promoted to head LOS. The delegated implementation is not established by
  these five inspected source windows.
- The inspected original `CheckVisibleByDis` branch compares position components
  against configured axis ranges. This does not establish a head-obstacle query;
  its nested position/provider behavior is not fully evaluated here.
- The name inventory has 209 matches, including UI visibility, item marking and
  Unity physics methods. These are search candidates, not 209 verified LOS APIs.
  Obfuscated names are omitted; this is not an exhaustive call graph or proof
  that a suitable LOS implementation does not exist.

A useful LOS result still needs a source-verified query origin/end point,
collision/trigger policy, closest-hit/target association, target lifetime and
appropriate live validation. No cached target-head LOS result was established
by this bounded inspection. No game function was invoked, no runtime memory was
read and no aim writes were added.

## Reproduce

Run from a checkout containing the sibling `bluestacks-process-map` folder:

```bash
PYTHONDONTWRITEBYTECODE=1 python3 Audit-VisibilitySources.py \
  /path/to/libil2cpp.so /path/to/global-metadata.dat /tmp/visibility-audit.json
```

The trusted sibling parser verifies the complete pinned SHA-256 of both inputs.
The audit verifies five exact method metadata/registration identities and three delegate identities, records
bounded source bytes and decodes direct B/BL targets. Source windows end at the
next method in metadata order for these pinned cases; this is explicitly not a
general function-size recovery algorithm. Hotfix calls, indirect calls and
nested helper behavior are not silently treated as original LOS semantics.

Validation performed: successful run on the exact reference inputs; a repeat run
produced byte-identical JSON; all 34 direct B/BL transfers across the five source
windows independently matched Capstone 5.0.3 disassembly; a wrong ELF was rejected
by the full-file hash check; a wrong metadata input was also rejected. Runtime C#/PowerShell/native code was unchanged, so
the unrelated full runtime suite was not repeated for this source-only addition.

The JSON includes metadata records, source hex, call targets, input hashes and
scope limitations. No APK, metadata file, vendor DLL or full ELF is included.

## Follow-up: camera-mode delegate and real raycast callers

`Discover-PhysicsCalls.py` and `physics-callers.json` extend the source audit.
They do not add a live reader or change the V52 Windows runner.

The full pinned camera-mode delegate window is 900 bytes. Parameter metadata
identifies its input, and the facade input, as `COW.GamePlay.BEADLMGGGGL` (player
identity), not a ray, a head point or a `Bounds` value. The original delegate
also has a `true` return when its +0x19 byte is zero. It combines other policy
branches and nested helpers. Its result cannot be used as verified head LOS.
No frustum-versus-LOS classification is inferred merely from the method name.

The audit resolves the exact Unity PhysicsModule registration and 53
`Physics`/`PhysicsScene` raycast-named bindings, then records direct B/BL transfer
candidates to those bindings in reference executable loads. Literal/data words,
indirect calls, aliases and cross-image gaps mean that these candidates and the
nearest CSharp method names are not proven function ownership or LOS semantics.
In particular, long gaps can associate foreign-image code with the last CSharp
registration. The JSON explicitly keeps that uncertainty.

Three call sites additionally lie inside inspected, exact registered Player
source windows, rather than relying only on the nearest-name search:

| Source window | Call-site RVA | Physics wrapper RVA |
| --- | --- | --- |
| `Player.UpdateAiming` | `0x6f986c8` | `0xa0481fc` |
| `Player.get_HasAgainstEntities` | `0x6fd85a8` | `0xa0481fc` |
| `Player.HasAgainstEntitesWithSpawnObjectCrossHair` | `0x6fd8928` | `0xa0481fc` |

The target is the registered five-argument `UnityEngine.Physics.Raycast`
overload. These are actual source references to a physics-query API, but they
are not verified camera-to-selected-head LOS queries. One original getter branch builds
a local hit buffer, calls the query and subsequently performs virtual dispatch;
it is not simply a cached boolean field load. Virtual targets, query policy,
closest-hit ownership and any side effects have not been fully established.
Calling it is not part of this read-only probe.

The follow-up therefore identifies concrete source paths to investigate and
avoids turning model visibility or crosshair query results into head LOS.
Runtime LOS and automatic aim remain unimplemented/unverified.

Reproduce with the same pinned inputs and sibling parser:

```bash
PYTHONDONTWRITEBYTECODE=1 python3 Discover-PhysicsCalls.py \
  /path/to/libil2cpp.so /path/to/global-metadata.dat /tmp/physics-callers.json
```

No engine/native function invocation, DLL injection, memory write or live test is
performed by either audit. The source windows are bounded evidence for this
exact reference image, not a general function-boundary or disassembly algorithm.

Follow-up validation: a repeated run produced byte-identical JSON; all 150 recorded
B/BL target decodings matched independent Capstone 5.0.3 decoding. The five primary
source windows matched the pinned ELF, both player-identity parameter types were
checked, and all three primary raycast transfers lay within their recorded
windows. A wrong ELF input was rejected. No live LOS test was performed.

## Follow-up: hit-query contract and cached reference layouts

`Build-HitQueryContract.py` generates `hit-query-contract.json` from the exact
pinned ELF and metadata inputs. It records six inspected source windows, the
three Player cache-field registrations, and three type layouts. This is source
reference preparation, not a new live probe or a completed game binding.

The five-argument query signature is `origin`, `direction`, output `hitInfo`,
`maxDistance`, `layerMask`, returning a Boolean. It does not take a selected
player or head identity. The wrapper passes a raw zero trigger argument to the
six-argument PhysicsScene overload. That overload is represented by its method
identity/signature and a **partial 64-byte prefix**, not a fully evaluated body.
The current global physics setting is not captured.

A first attempt to interpret trigger enum default storage as fixed-width Int32
failed. The report therefore retains the raw default records/prefixes and
`UNVERIFIED_DEFAULT_DATA_ENCODING`; it does not force a numeric enum mapping or
claim `UseGlobal` was established. Raw zero forwarding is verified separately
from interpretation of those metadata values. Earlier informal speculation
about the enum label is not part of the verified result.

`RaycastHit.m_Collider` is an **Int32 ID**, not a managed Player pointer. Its
property body loads a 32-bit value at payload offset `0x28`. Its on-disk field
registration contains an uninterpreted marker, so no agreement with a decoded
runtime field offset is claimed. The markers are retained with a null source
offset candidate and `live_offset_verified=false`; they must not be used as
addresses. The collider
property calls the registered `Object.FindObjectFromInstanceID` resolver and
checks the resolved object type. The resolver identity and prefix are recorded;
its implementation, lifetime rules and a read-only resolver binding remain
unestablished. No resolver or game function was invoked.

| Registered Player field | Declared type | What this establishes |
| --- | --- | --- |
| `FDMIEDDNCEC` at `0xe50` | `CGKJLKPMGDJ` | Typed cache field registration only |
| `PKIOAMDCOPB` at `0xe58` | `CGKJLKPMGDJ` | Another field of that declared cache type |
| `<JMPDDMAMFML>k__BackingField` at `0xe68` | `OGKFEMJNCGM` interface | Reference contract, not a concrete Player layout |

The custom cache type declares GameObject/Collider references and Vector3 fields;
its declared parent is ObjectPoolCallbackBase. Coordinate meaning, cache age,
lease/generation, dynamic target identity and head association have not been
validated. Its vectors must not be renamed head positions merely because their
storage type is Vector3. The interface declaration has no concrete instance
layout to follow as a Player object.

The target-resolution helper at RVA `0x6f99220` is recorded using an explicitly
inspected 512-byte window. Its next metadata-order method does not provide a
valid function bound, so that larger range is not read or presented as its body.
All its conditional branch targets were independently checked to lie inside the
chosen window. Other source windows can include associated adjustor thunks;
none is a general-purpose function-boundary recovery claim.

Reproduce with the pinned inputs and the sibling parser:

```bash
PYTHONDONTWRITEBYTECODE=1 python3 Build-HitQueryContract.py \
  /path/to/libil2cpp.so /path/to/global-metadata.dat /tmp/hit-query-contract.json
```

Remaining requirements are an authoritative query/scene policy or complete
matching geometry, verified object-ID/target association, correct head/camera
coordinates, freshness/lifetime checks and the actual output adapter. The
existing offline targeting module cannot supply those by assigning Proof.Yes.
The Windows runner remains V52; no new Windows capture is required for this
source-only contract extraction.

Validation: all six recorded windows matched the pinned ELF bytes. An independent
Capstone check verified 19 conditional targets within the helper window and the
collider payload load/resolver call. Uninterpreted offset markers and unknown
trigger mapping remained explicit. Regeneration was byte-identical; a wrong ELF
was rejected. These are source checks, not live LOS or aim integration tests.
