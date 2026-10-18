# Dirty view-cache derivation: verified arithmetic feasibility

**Result:** the pinned dirty view-cache arithmetic can be reproduced on the host without calling a live game getter or modifying game memory. This is verified against isolated ARM64 arithmetic on synthetic hierarchies. It is not an implemented live fallback and is not proof of the currently rendered frame.

The latest user V5 run returned ViewDirty=1 and ProjectionDirty=0. V5 correctly withheld matrices. Repeating the same capture is not requested by this investigation. V5 code/package remains unchanged.

## Traced source path

For full-SHA256-pinned libunity.so:

1. The view helper at 0xb797e8 checks the dirty byte. On the dirty path it builds a diagonal matrix with x/y=+1 and z=-1.
2. It finds the owner's native Transform through the component lookup at 0x52aeac, using the runtime native type descriptor.
3. The arithmetic routine at 0x696884 accesses the hierarchy and index through 0x69304c, composes world position and a parent-scale-sign-adjusted world quaternion, and constructs a rigid inverse matrix.
4. The multiply at 0x53a844, reached through 0xc0e700, computes the first matrix times the second using column vectors/column-major storage for this traced arithmetic.

The derived formula is:

```
view = diag(1, 1, -1, 1) * rigid_inverse(world_position, adjusted_world_rotation)
```

This is NOT the full inverse of a scaled local-to-world matrix. Parent scale magnitudes affect world position. Parent scale sign bits affect quaternion composition, including negative zero. The camera Transform's own scale magnitudes do not become inverse scale factors in this arithmetic. The source order contains float/SIMD operations; the provided independent mathematical model uses higher precision and is checked within explicit tolerances, not claimed bit-for-bit equivalent.

The view helper's traced path writes its synthetic cache but does not contain a store clearing the view dirty byte. Consequently, waiting for that byte to clear is not itself an established completion strategy. This observation does not determine what other game/render code does to it.

## Evidence and tests

verification.json contains source-window hashes/instruction transcripts and all 137 deterministic differential cases. Cases include translation, axis rotations, nonuniform local/parent scales, eight reflection masks, negative zero, 120 seeded random hierarchies and depth 32. The measured maximum absolute matrix-element difference was approximately 1.958e-5. Acceptance is abs(error) <= 0.001 + 0.0001*abs(reference element). These are matrix-element numerical errors, not screen-pixel or aim-accuracy measurements.

Five additional tests cover identity/Z flip, rejecting a full-scaled-inverse assumption, invalid model inputs, a simple differential result, and detection of deliberately corrupted arithmetic code. The corruption test invalidates the emulator translation cache both after patching and after restoring bytes.

Unicorn executes the pinned dirty-path arithmetic in isolated synthetic address space. Two interfaces are deliberately substituted: component lookup returns a synthetic Transform; transform access returns a synthetic clean hierarchy/index. The real component lookup and hierarchy synchronization routines are traced statically but are not exercised dynamically by those substituted interfaces. The synthetic machine permits writes to its own simulated cache/output memory. It does not connect to BlueStacks, read the live game, invoke any live game function, or write live game memory. This distinction is part of the report.

Reproduce with Python 3 in an isolated environment:

```
python -m pip install -r requirements.txt
python verify_dirty_view.py PINNED_libunity.so TRUSTED_Recover-GameLayout.py verification.json
python test_dirty_view.py PINNED_libunity.so TRUSTED_Recover-GameLayout.py
```

Use the existing downloads/bluestacks-process-map/Recover-GameLayout.py. The full Unity input SHA256 is checked before disassembly/emulation. No game DLL is loaded as host executable code. The test mapper also checks the input hash. The provided files are sufficient for the host-side model; the pinned proprietary Unity image is not bundled here.

## What a live implementation still needs

Reuse the existing finally rechecked player/main/controller identity and bounded native hierarchy reader. Establish the source-derived component type descriptor/range and the chosen Transform's owner/backlink before derivation; the emulated lookup substitution is not a live validation. Read only when hierarchy job state is idle; preserve depth/capacity/cycle/backlink checks. Capture the same hierarchy/TRS twice in opposite order, reject changes, and recheck identity, code, parents, jobs and projection-cache state before publishing. No forced job completion or getter execution is needed for a successful idle/stable observation; busy/moving state must remain NOT_READY.

A future result must be labeled DERIVED_FROM_RECHECKED_TRS, rather than a clean view-cache sample. Derivation must not clear the game's dirty flag. Projection dirty state, projection variant/convention, viewport, camera authority, source age and atomic render-frame alignment remain independent gates. A same-frame independent landmark comparison is still necessary for rendered screen-pixel validation.

The current V5 log contains no raw TRS rows or derived matrix, so this research cannot retroactively compute or validate that particular frame. The arithmetic source profile applies to the pinned Free Fire build, not Free Fire MAX or future versions by inference. No LOS, aim output or hit registration behavior is established here.
