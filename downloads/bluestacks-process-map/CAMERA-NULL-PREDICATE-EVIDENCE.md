## V52 original Unity Object null-comparison data

V51 live verification accepted the registered controller -> managed Camera ->
cached native pointer link to the original Unity native selector. Camera position
and rotation were reported, with a 4920-read aim phase and successful cleanup.
The Player camera getter metadata guard was still zero; actual game getter
execution and active aiming/rendering-camera selection remain unestablished.

V52 adds CameraObjectNullCheck for the independently registered managed camera
field. Exact CoreModule method registration, metadata records and source bytes
are verified for Object.op_Equality, op_Inequality, CompareBaseObjects,
IsNativeObjectAlive and GetCachedPtr, plus the IntPtr inequality tail target.
The exact source for this build tests m_CachedPtr against zero; it does not call
a native instance-ID existence lookup on this path.

For this typed non-null managed Camera, V52 records the nonzero cached-pointer
data predicate, three operator/helper metadata guard bytes and the Object class
initialization gate. Operator equality results are withheld unless all three
metadata bit-zero gates are set, the source class-usage cell equals the verified
Object parent class, and its source-tested +0xe0 word is nonzero. No metadata or
class initialization is requested. Tagged/unresolved class usage and zero flags
produce explicit NOT_READY statuses. Wrong resolved class usage rejects the sample.

When ready, ORIGINAL_NULL_COMPARISON_DATA_VERIFIED gives EqualsNull / NotEqualsNull
for that original source branch. This is data/source equivalence only: no operator,
getter, native function, class constructor or IFix method is invoked. No lifetime
or atomic-frame guarantee is inferred. The managed reference comes from the
registered controller field; native-to-managed Camera.main wrapper conversion,
full game getter/fallback execution, LOS and aim-update integration remain pending.

Every new guard, class usage and initialization observation participates in final
snapshot rechecks; mismatch discards the tentative sample. Existing time/read/
observation limits and all read-only restrictions remain unchanged. Unknown or
missing typed cameras retain NOT_EVALUATED_NO_TYPED_CAMERA rather than guessed
null semantics. Live V52 verification is pending.
