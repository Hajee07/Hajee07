# Read-only local-player and managed head Transform evidence

V10 passed live kernel, process, ARM64 module, runtime metadata header and all
80 registration checks in both rounds, with no mismatches or observed changes.
It used 9692 physical reads, 1121 cache hits, 714 outer VMAs and a 16-VMA module
window. All cleanup steps passed. V12 subsequently passed live local-player validation, with a null head-provider cache. V13's dictionary fallback needs a live run.

## Input provenance and reproduction

Build-ObjectReference.py uses Recover-GameLayout.py to verify the same complete
ELF and metadata SHA-256 inputs. It derives parent relationships, 105 supported
normal class records plus separate String/generic-definition profiles, native type/size data, four type-usage roots and 70 code/GOT
references. The JSON and C# outputs reproduce byte-for-byte. No live PID, object
address, metadata base or module load bias is a runtime constant.

```sh
python3 Build-ObjectReference.py /path/to/libil2cpp.so /path/to/global-metadata.dat output-directory
```

## Original local-player path

Disassembly of CurrentLocalPlayer at RVA 0x71c5838, including its body from
0x71c589c through 0x71c59c8, supports this exact original-code access path:

- GOT 0xa73f0c0 references GameFacade type-usage cell 0xac2f570. The unresolved
  file value 0x20011e3b encodes its native type; it must become a verified class.
- The class static-fields pointer is at +0xb8. CurrentGame is at static offset 0.
- The CurrentGame object must cast to the MatchGame class from GOT 0xa7759c0,
  cell 0xac340a8. Runtime parents must agree with the exact metadata ancestry.
- MatchGame.GetMatch (0x731de48) returns object+0x90 on its original path.
- Match getter 0x720a764 returns object+0xd8 on its original path.
- Player.IsLocalPlayer (0x6eff934) returns the byte at object+0x420. Exact native
  field registration identifies this bool as JKACLOCKKPH. It must equal one.

The probe validates actual class identity, rather than assuming a plausible
pointer identifies one of these objects. It supports metadata-derived subclasses
of MatchGame, the match type JMAGGLCNGIG and Player. Unknown class profiles fail.

## Class representation evidence

The exact constructor at 0xa32b5f0 uses 88-byte type-definition records. Its body
stores metadata name and namespace pointers at class+0x10/+0x18, copies the
native by-value descriptor to +0x20, stores the record at +0x68 and class self
at +0x78. It stores instance size at +0xf8 and the metadata token at +0x11c.
Runtime parent class is stored at +0x58. The counts copied to +0x120 include
vtable count (+0x12a) and interface-offset count (+0x12e). These instruction
samples are included in the generated code anchors.

The reader verifies these identities and the complete selected type records
against the already verified runtime metadata base. Name/namespace pointers
must equal the exact metadata string addresses. It does not follow arbitrary
class-name strings. Derived-class parent walks stop after 16 links.

## Hotfix gate

The original dispatch code at 0x882aa1c uses IFix.ILFixDynamicMethodWrapper,
whose type is resolved via GOT 0xa899b98/cell 0xac30d18. Its verified static
wrapperArray field is at offset zero and has the declared IFix wrapper[] type.
The dispatcher reads array length at +0x18 and entries at +0x20+id*8. Lengths
above 1,000,000 are rejected. An ID outside the array returns inactive, matching
the original dispatcher. Nonzero relevant entries cause the original path to be
reported as overridden; the probe does not call or bypass a hotfix.

Local-player checks require IDs 0x1c6, 0x139, 0x1c5 and 0x12b to be inactive.
The head-getter ID 0x34e is checked separately. Both static class initialization
and class/field identity are required; unresolved usage cells are not followed.

## Managed head Transform

The original HeadBoneTransform getter at 0x6f37be4 loads Player+0xa00. If this
lazy provider is null, its game code can initialize it through a virtual call.
This read-only probe reports NOT_READY and makes no initialization call.
For a non-null provider, the getter dispatches method zero of ITransformNode.
The ITransformNode usage cell is 0xac31400 (GOT 0xa74bec8).

The exact metadata identifies three implementations:

| Type | Type index | get_transform RVA |
| --- | --- | --- |
| TransformNode | 14528 | 0x37987c4 |
| BFOONIGAIFK | 31705 | 0x70e0ba8 |
| GCommon.TransformNode | 36295 | 0x8259e90 |

Each getter consists of `ldr x0,[x0,#0x10]; ret`. V11 validates the runtime
interface entry, exact class/count bounds and vtable target before reading that
field. It validates the returned object as UnityEngine.Transform (type 41116).
It does not dereference the native engine Transform or compute world positions.

## Consistency, bounds and scope

The object stage rechecks process identity and code anchors and rereads every
observed object/class/field value before returning. Samples are bounded to 1024
ranges/64 KiB, parent chains to 16 and interface entries to 64 and the exact
metadata count. All reads retain the global 30,000-call/120-second budgets,
verified RAM bounds and fresh page-table walks. No game functions, object writes,
VM pause, GC rooting or guest locks are used. These checks detect observed
changes but cannot eliminate all object-lifetime races in a non-atomic scan.

155 offline checks pass: 46 kernel/reader, 31 module, 30 registration and 48
object checks. The synthetic valid object fixture takes 2144 reads and 114
observations. Negatives cover wrong identities/flags, metadata records and
sizes, active hotfixes, null/unresolved states, changed chains/processes, wrong
interface/getter targets and bounds. These fixtures do not prove Windows object
lifetimes or that the selected original paths are active in the user's match.

A live LocalPlayerObjects PASS establishes the checked original-path chain and
local marker. ManagedHeadTransform=MANAGED_TRANSFORM_VERIFIED additionally
establishes the managed head Transform observation. Other-player enumeration,
world coordinates, visibility semantics and aim updates remain unimplemented.
Run in Training Ground after the character spawns and share the complete report.

## V11 user result and V12 class-layout diagnostics

A user run for PID 5553 stopped in the outer VMA scan after 945 entries with the
old combined order/bounds/backlink failure. Another run for PID 5886 passed
module verification at load bias 0x777da4e00000 and both 80-check metadata rounds
at metadata base 0x777da17aa000. The root observations identified GameFacade,
MatchGame and IFix type indexes, but the IFix class failed the combined token /
instance-size check. Physical reads=12854, cache hits=1631, outer VMAs=1019;
all cleanup stages passed. Local player and head Transform were not reached.

The old message omitted actual token and size values. Inspection then found a
reference-generation defect: six native size records contain opaque values,
including IFix instance size 0x81818099 and static size 0x81818181. V11 copied
these into exact class expectations, which is invalid. No generic XOR decoding
or guessed replacement size is used by V12. The raw words remain in the JSON
with instance_size_exact=false and an explicit minimum-size rule.

The affected type indexes are 12644, 12654, 12655, 33936, 33941 and 37332.
Five are game-derived types; their objects must cover the verified base storage
(592, 1592 or 9328 bytes). IFix's three declared nonstatic fields have offsets
0x10, 0x18 and 0x20 and reference/int32/reference widths. They independently
require at least 40 bytes. Runtime sizes must also be at most 1 MiB. All other
profile sizes retain exact checks, including the legitimate zero-size interface
profile. Class record, token, name, by-value type and parent checks still apply.

The native class setup code writes class+0xf8 after computing layout (RVAs
0xa3817d4 and 0xa381908). The new generated anchors include those instructions,
static allocation from class+0x10c, and the field-offset helper. They establish
that initial native table words are not a universal immutable class-size rule.
Actual IFix runtime size remains a live observation to collect, not a constant.

Before reading IFix static storage, V12 independently validates the runtime
FieldInfo entry for wrapperArray: four declared fields; a valid field table at
class+0x80; index three with a 32-byte stride; full 12-byte field metadata record;
exact name address, declaring class and token; the original array descriptor
pointer and flags; static offset zero; and runtime static extent of at least
8 bytes and at most 64 KiB. The type is the declared IFix wrapper array, as also
checked by the generator. Unrelated fields or undersized storage fail. All new
observations participate in the final recheck.

142 offline checks pass (46 reader, 31 module, 30 registration, 35 object).
New cases reject opaque exact-size expectations, undersized IFix instances,
insufficient static storage and incorrect runtime field offsets/tokens. A
synthetic 48-byte IFix instance is accepted only with all independent field
identity checks satisfied; that fixture size is not a claimed Windows result.
V12 also reports exact class difference values. Live local-player and managed
head Transform success still requires the Windows run.

## V12 live success and V13 uncached-head read path

The user reported LocalPlayerObjects=PASS for game PID 6313, class
COW.GamePlay.PlayerNetwork (type 32360), with 128 observations and inactive
original-path hotfix slots. IFix's runtime instance size was 40. The derived
match class EPPMGCJDEDC was 1664 bytes against the required base extent 1592.
Player+0xa00 was zero, so no managed head Transform was obtained. Metadata/module
checks and all cleanup stages passed. Total reads=12410, cache hits=1675.

The original lazy getter at 0x6f37c58 reads usage cell 0xad7e5b8 through GOT
0xa753ac0. Its on-disk value 0xa001562d has usage kind 5 (StringLiteral), index
43798. The exact decoded literal is bone_Head, nine UTF-8 characters. This is a
string argument, not MethodInfo. The getter invokes virtual slot 29 before
writing the returned provider into Player+0xa00; the probe does not execute it.

The metadata vtable entries for Player and PlayerNetwork both encode 0x600677bf,
method-definition index 211935 after removing the usage tag/low flag bit. Its
method token maps to GetTransformNode at RVA 0x7013344. The original branch
returns the result of LBJCFPMCLMN.GetTransformNode at 0x70e1318 using Player's
NJMKOAOGOIF field at +0x1530. That method first queries its cache field
FCHOLNKBLGH at +0x10, declared Dictionary<string,BFOONIGAIFK>. A hit returns the
cached node. On a miss the game may search Unity's hierarchy and allocate/write
a node. V13 implements only the existing-entry read path.

The generator cross-checks all these metadata/registration relationships and
preserves complete input hashes. It emits the String and Dictionary definition
records separately: primitive String and closed generic classes do not use the
same by-value data representation as a normal class. String's opaque initial
size is not used as a runtime expectation.

V13 verifies the Player vtable metadata and function pointer, plus inactive
hotfix slots 0x21f1a and 0x4f35. It validates the model class, dictionary metadata
record/token/name, closed generic class/cached-class relationship, argument count
and String/BFOONIGAIFK arguments against the declared descriptor. The dictionary
entry-array pointer is at +0x18, used count at +0x20 and version at +0x24. The
exact lookup code uses 24-byte entries: signed hash at 0, link at 4, key at 8
and node value at 16, after the array header +0x20. These instruction bytes are
included in the new references. Negative hashes mark removed entries.

The reader bounds used entries to 512, capacity to 8192 and key lengths to 256,
checks String metadata identity and compares exactly nine UTF-16 characters.
It scans the bounded payload in blocks of at most 4096 bytes and rejects duplicate
active head keys. It does not reproduce hash buckets/custom comparer behavior.
The result identifies an observed exact-name cache entry, not a simulated method
invocation. A node must have the exact BFOONIGAIFK class and pass the existing
head interface/getter/Transform checks. A miss returns NOT_READY and does not
follow the default node, invoke Unity, allocate, initialize or write anything.
All cache/context/key/node observations are included in the final reread and
unchanged global budgets. Identical samples still are not an atomic GC snapshot.

155 offline checks pass, with 13 new cache cases. The synthetic fallback uses
2825 reads and 169 observations. Live cache availability and the fallback
representation still require the v13 Windows run. Head world coordinates,
other-player enumeration and aim updates remain unimplemented.

## User V13 result and V14 follow-up

V13 passed on guest PID 6727 with host PID 6372. All 80 registration checks
matched twice, metadata base was 0x777da15aa000, and the model cache had 29 used
entries with exactly one active `bone_Head` key. The returned BFOONIGAIFK node
passed its exact interface/getter/class checks, and its returned managed object
passed UnityEngine.Transform identity. Final static snapshots covered 280
observations. Total physical reads were 15040. Plugin unload, handler cleanup and
shared-session release all passed. The head source was MODEL_DICTIONARY; no
cache initialization or writes occurred. This verifies the managed head
Transform observation; V13 did not obtain world coordinates.

V14 adds the separately checked native position sample documented in
`TRANSFORM-EVIDENCE.md`. The earlier object snapshots are still rechecked after
this stage. Native-stage failure is reported separately and does not relabel
the managed Transform as unverified. Live V14 validation remains pending.

## User V14 snapshot rejection and V15

V14 again passed the local-player chain and cached managed head Transform. Its
native position stage rejected a changed snapshot and emitted no XYZ; all
cleanup stages passed. V15 retains these object checks and makes two short,
strict TRS copies separately from native identity snapshots, with at most three
fresh attempts for selected TRS motion alone. See TRANSFORM-EVIDENCE.md. No new
offsets, game calls or aim writes are introduced. V15 live validation is pending.
