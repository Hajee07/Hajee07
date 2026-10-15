# Exact-build native local-head position sample (V15)

V13 established the cached managed head Transform, not its world position. V14
added a bounded read-only calculation for that one verified local-head object.
Live validation is pending. It does not enumerate enemies, test visibility or
apply aim changes.

## Inputs and code provenance

The existing SHA-verified IL2CPP ELF and metadata references remain unchanged.
The Unity input is the exact ARM64 `libunity.so` extracted from the same APK:
SHA-256 `1029519376944ff6310fcbbe84356976a839e080da67da716b3aae470f80dd77`,
GNU build ID `667862f2d29b22ee`. The library itself is not bundled.
`Build-TransformReference.py` reproduces `transform-reference.json` and
`NativeTransformReference.cs` from the two exact ELF inputs. It uses only the
Python standard library and verifies full input hashes.

The CoreModule codegen record at RVA 0xa729470 names
UnityEngine.CoreModule.dll; its method table is 0xaf5a718. Metadata type 41116 is
UnityEngine.Transform. Its get_position (method 318429, token 0x06000e5d) maps to
0x9ff5f40; get_position_Injected (318499) maps to 0x9ff5f9c and
get_localPosition_Injected (318501) to 0x9ff6078. The exact wrapper instructions
resolve named internal calls and cache the targets at IL2CPP RVAs 0xafb9e00 and
0xafb9e10. No resolver is invoked by the probe.

In the Unity binary, registration stubs 0x46e9e4 and 0x46ea0c pass the exact
position/local-position injected names to the registration routine with native
targets 0x45ea4c and 0x45ec64. A non-null cached target gives the candidate Unity
load bias by subtraction; both cached bindings must agree when present. The
probe checks that bias's exact ELF header, all ten program headers, build-ID
note and 29 code/constant anchors, and rechecks all captured bytes. This is
binding/code identity verification; it does not claim a second full VMA segment
coverage scan. An unresolved pair returns NOT_READY without initialization.

## Native layout derived from these functions

The injected wrappers obtain the native engine object through 0x71f7d0:
`managedObject+0x10`. The world wrapper then calls 0x691584; the local wrapper
calls 0x690da4. Both use 0x69304c, which loads hierarchy data from native+0x38
and the transform index from native+0x40. If hierarchy+0 contains a job, the
engine would synchronize it and clear its job record. This reader instead
requires hierarchy+0 and +8 already zero and returns NOT_READY otherwise.
It makes no engine calls or memory writes.

The exact world-position loop reads hierarchy+0x18 as a TRS array (48-byte
records: translation float4, quaternion float4, scale float4) and +0x20 as signed
parent indices. Native routines 0x693cfc and 0x693698 read +0x10 as the allocation
capacity; the latter compares it before resizing. This is a capacity, not a
claim that every slot is live. Capacity is bounded to 1..65536. For each visited
slot, hierarchy+0x30 must point back to its native Transform and the Transform's
+0x38/+0x40 must point back to the same hierarchy/index. The assignment routine
0x693d54 independently establishes these relationships. Native+0x90 must match
the next parent's native object, or be null at the -1 root sentinel.

The calculation starts with the head's local XYZ, then applies every parent's
scale, quaternion rotation and translation in the exact order of the native
SIMD loop. Its three constant vectors are verified at 0x185040, 0x182650 and
0x185bc0. The C# scalar reproduction preserves the native multiplication and
addition ordering; it is not a Unity function call or a promise of bitwise
identity across floating-point implementations. Position/scale padding lanes
are captured but not interpreted as XYZ values. Quaternion lanes must be finite
and parent squared norms within 0.98..1.02; non-unit inputs outside this narrow
validation envelope fail rather than being normalized. Output XYZ must be
finite and within +/-10,000,000. These are acceptance bounds, not game units or
claims about map extents.

## Bounds and reporting

At most 128 hierarchy nodes are visited; repeated indices, invalid indices,
backlink disagreements and bad root sentinels fail. Native code/identity observations have a separate
1024-range/64-KiB snapshot bound and are reread before and after the two TRS
copies. The earlier local-player/model-cache/managed-object observations are
also rechecked before returning. All work shares the existing global
30,000-read and 120-second budgets. No VM pause, engine synchronization, guest allocation or memory
write is performed.

`LocalHeadWorldPosition=SAMPLED_READ_ONLY` is emitted only after these checks.
Failed native sampling retains the earlier managed-object result, reports the
check, emits no XYZ and sets the runner exit status to 1. NOT_READY identifies
an absent prerequisite. The sampled native chain can change after the probe;
there is no GC root, engine lock or atomic guest snapshot. Reverse rereads do
not rule out changes that return to the same bytes between observations.

## User V14 result and V15 capture correction

The user's V14 report (guest PID 7265, host PID 6372) passed all 80 registration
checks twice, the exact module identity, local-player identity and managed head
Transform. The native stage reached its final snapshot comparison, which failed
at address 0x777d5b3d4150. It reported no coordinates. Total physical calls were
15449; plugin unload, handler cleanup and shared-session release passed. The
combined V14 snapshot did not identify the failed observation's kind, so that
report does not prove which field changed or establish a stable world position.

V14 kept TRS observations in the same snapshot collection as code/identity
observations. V15 first builds and validates the native index/parent/backlink
chain without capturing TRS data. It rechecks identities, then copies the
selected TRS rows twice in immediate succession (second pass reverses chunk
order). Nearby rows are grouped into at most 4096-byte reads, with gaps limited
to 192 bytes. At most 128 rows are selected, and at most 32 KiB is fetched per
pass. Only the selected 48-byte records are compared and used in the calculation;
unused gap bytes may change without affecting the sample.

Every selected record must match byte-for-byte across both copies. There is no
numeric movement tolerance and no reuse of an earlier pose. Code/identity
snapshots are rechecked after the copies, including when TRS changed; a
simultaneous identity change fails immediately. Only a dedicated TRS_CHANGED
exception qualifies for up to three fresh native attempts using the same Reader
and its remaining global budgets. Each attempt revalidates bindings, code,
hierarchy and backlinks. Other errors and pending/unresolved prerequisites do
not enter the motion retry path. Continued motion on attempt three fails with
no coordinates. Motion diagnostics include the selected row index/address;
identity snapshot failures are labelled separately.

181 offline checks pass, including an independent general quaternion matrix
oracle, noncommuting X/Y rotations, nonuniform and negative scale, null/unresolved
prerequisites, pending jobs, wrong Unity bindings/code, invalid capacity/links,
cycles and nonfinite coordinates. Capture tests cover continuous motion failing
on exactly the third attempt, a new stable pose on attempt two, coalesced and
sparse rows, ignored gap bytes, and immediate failure for identity/read errors
including a simultaneous identity and TRS mutation. The stable synthetic native
fixture uses 3144 total physical calls including earlier stages and records 63
native observations. These tests validate implementation/error handling; V15
live native-head sampling remains pending on the user's Windows PC.
