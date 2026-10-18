# Native projection source investigation

The pinned Unity image now has a reproducible static registration-to-entry-to-helper audit for five Camera methods. This extends the earlier IL2CPP wrapper inventory. It does not add a live provider.

## Confirmed from pinned bytes

- Each exact UnityEngine.Camera name is passed with its native entry address by the expected ARM64 registration stub. All five stubs branch to a common registrar address. Names, argument registers, executable address membership and helper calls are checked.
- The aspect helper is a scalar float load followed by return in the observed instruction window.
- The FOV helper has conditional paths, external calls and state checks; it is not demonstrated to be a single unconditional scalar load.
- The world-to-camera helper checks a state byte and has a conditional path containing calls before returning a matrix-address intermediate.
- The projection helper likewise checks state and contains conditional paths/calls before reaching a cached result. Its supplied-data cache cannot automatically be treated as current render projection.
- Fixed instruction windows and SHA256 values are retained in native-sources.json. Those windows may include adjacent code and do not assert complete function boundaries or complete control-flow coverage.

## Still unverified

The live wrapper cache targets have not been compared against these pinned native entries. The relevant live native Camera ownership, cache validity and update semantics, exact matrix element convention, projection variant used by the render pipeline, viewport and frame alignment remain unverified. Static registration alone does not prove execution by the active camera.

There is a concrete source path to investigate now, but a safe read-only provider cannot claim current matrices from cached fields until those conditions are validated. Calling a getter to trigger recomputation would execute game code and is not part of this read-only tool. No runtime getter/resolver is invoked and no memory is written.

## Reproduction

Install Capstone 5.0.6 in an isolated Python environment, then:

```
python audit_native_sources.py PINNED_libunity.so TRUSTED_Recover-GameLayout.py native-sources.json
python test_native_sources.py PINNED_libunity.so TRUSTED_Recover-GameLayout.py
```

The mapper is the existing downloads/bluestacks-process-map/Recover-GameLayout.py. The audit verifies the full pinned Unity SHA256 before parsing. Two test methods pass, covering the pinned profile and four independent corruptions: name bytes, registration address construction, registration branch and expected helper call. These are host-side static tests; live Windows execution has not been performed for this change.

No new Windows capture is requested yet. The prior identity probe is unchanged. This evidence applies to the pinned Free Fire image, not Free Fire MAX or another version by inference.
