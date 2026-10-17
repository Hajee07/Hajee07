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
