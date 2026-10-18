# Camera wrapper binding audit — static only

This continues the projection prerequisite investigation. It is not a new live Windows probe. No extra READY sequence is needed.

For the pinned Free Fire ARM64 IL2CPP image, five registered wrappers (FOV, aspect, pixel rect injected, world-to-camera injected, projection injected) contain a load from a function-pointer cache, a conditional resolution path with cache store, and an indirect tail branch. The checked pattern associates the cache load/store with the tail register and records the shared resolver call site. Full instruction transcripts and wrapper digests are in bindings.json.

**These cache cells contain function pointers, not FOV scalars or matrix arrays.** This audit does not establish their live targets, the resolver's complete semantics, the native implementation's camera data layout, rendered frame identity or matrix conventions. The resolver argument bytes are not ASCII in this pinned image; their decoded text is explicitly UNVERIFIED. Registration-to-method association comes from the earlier pinned Camera method inventory; no readable binding string is invented here.

The bounded disassembly/pattern checks are not a general control-flow or ABI proof. They only characterize these exact pinned wrappers. No getter, resolver, initialization path or supplied binary is executed. Capstone disassembles bytes on the host. No game memory writes occur.

Reproduce with Python 3 and Capstone 5.0.6 installed in a separate environment:

```
python audit_bindings.py PATH_TO_PINNED_libil2cpp.so PATH_TO_Recover-GameLayout.py report.json
python test_audit.py PATH_TO_PINNED_libil2cpp.so PATH_TO_Recover-GameLayout.py
```

Use the existing downloads/bluestacks-process-map/Recover-GameLayout.py from this repository as the trusted mapper. Audit input must match the full SHA256 embedded in audit_bindings.py; mismatches fail before parsing. Do not use Python's optimization flag to bypass mapper assertions. Three tests pass: pinned wrappers, changed tail instruction rejection and changed resolver instruction rejection. Tests are static and do not prove Windows runtime behavior.

## Remaining blocker

A live read-only projection reader still needs a verified native implementation/data source for the exact build, including camera ownership and layout, validity/lifetime rules and frame timing. The current live report supplies pointer identity only. Reading function-cache slots as matrices, guessing offsets/FOV, or invoking unverified native functions would not close that gap. After that source is established, independently measured landmark pixels can be compared using camera-projection-validation. That checker does not itself supply live matrices.
