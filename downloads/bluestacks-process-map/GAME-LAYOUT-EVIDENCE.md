# Exact-build metadata and native registration recovery

Version 5 passed on the user's Windows/BlueStacks instance. Its selected layout
had load bias 0x7f96c4e00000 and GNU build ID
`ee8bf32c4483429084fde022704ead01a94b6620`. All eight load segments and four
fingerprints passed. This run used 891 outer VMAs, a 28-VMA module window, and
10847 physical reads; plugin unload, handler cleanup, and session release passed.
These addresses are run-specific and are never constants in the runner.

The following work uses the same supplied APK, rather than generic offsets from
another build. `game-layout.json` contains the full selected evidence and exact
runtime-check inputs. `Recover-GameLayout.py` reproduces it using Python's standard
library. No APK, complete native library, or decoded metadata is redistributed.

## Inputs and metadata decoding

| Input | SHA-256 |
| --- | --- |
| ARM64 libil2cpp.so | `549093d79212873f26bc13f8957d06cc7575e92f24b53721eb13e8a0a53cb657` |
| Packaged global-metadata.dat | `e6550955f005877d6daf94f4984892501ad86fe36d52cd1a1c94ceed0dd15aa3` |

The original metadata magic/version do not match the standard IL2CPP header.
The table offsets and selected blocks are XOR-obfuscated with byte 0x66:

- Decode file bytes [0, 0x5000).
- For each subsequent 0x10000-byte block, decode [block+0x1000, block+0x5000),
  clipped to file length. Leave the other bytes unchanged.

After decoding, all 31 offset/size pairs form contiguous sections from 0x100 to
the exact end of the 56,975,108-byte file. The first two words still are not a
standard magic/version and are preserved; the script does not invent a metadata
version or claim compatibility with a generic dumper.

Validation covers all 43,624 type definitions, 336,350 methods, 475,669 fields,
278,571 parameters, and 56 images. UTF-8 names, token kinds, ownership, table
bounds, member/parameter ranges, and per-image token coverage/uniqueness pass.
Nested type rows are not necessarily ordered by token RID; treating row order
as token order would be incorrect. The observed record strides are 88 bytes for
types, 40 for methods, 12 for fields/parameters, and 40 for images. The method
record has an additional integer matching observed hotfix-dispatch IDs.

## Independent native cross-check

The unique ELF relocation to `Assembly-CSharp.dll` identifies its code-module
record at RVA 0xa473a68. Its 289,444 method pointers agree with that image's
metadata method count and tokens. Method addresses are obtained from the
token-RID-indexed pointer array at RVA 0xa98efa8, using actual AArch64 RELATIVE
relocations; metadata row indices are not substituted for tokens.

A unique pair of adjacent 43,624 counts identifies the metadata registration
at RVA 0xa5d8ac0. The native type count is 103,559, with type table 0xa64d6f0,
per-type field-offset pointers 0xa8cfec0, and type-size pointers 0xa925200.
All selected metadata type indices fit these tables. Field attributes and types
come from the corresponding native Il2CppType descriptors. Selected offsets
fit their declared instance/static storage sizes.

## Selected field candidates

These are offsets within the indicated storage, not absolute addresses, live
player pointers, transform coordinates, or a write recipe.

| Owner | Field | Storage | Offset | Declared type |
| --- | --- | --- | --- | --- |
| COW.GameFacade | CurrentGame | Static | 0x0 | GCommon.BaseGame |
| COW.GameFacade | CurrentMatchGame | Static | 0x8 | COW.MatchGame |
| COW.GamePlay.Player | `<AKKPEKIHGAH>k__BackingField` | Instance | 0x614 | UnityEngine.Quaternion |
| COW.GamePlay.Player | BANPEGJEAKE | Instance | 0x738 | UnityEngine.Collider |
| COW.GamePlay.Player | LHICEKMGJOB | Instance | 0xa00 | GCommon.ITransformNode |
| COW.GamePlay.Player | NBIIBJBALJD | Instance | 0xad0 | GCommon.BitArrayBoolean |
| COW.GamePlay.Player | m_CurrentAimRotation | Instance | 0x1a8c | UnityEngine.Quaternion |
| COW.MatchGame | m_Match | Instance | 0x90 | COW.GamePlay.JMAGGLCNGIG |
| COW.GamePlay.JMAGGLCNGIG | MHJCLOPOBAA | Instance | 0xd8 | COW.GamePlay.Player |

`Player` is type definition 31824, with instance size 0x2470. `GameFacade` is
type 12418, with static storage size 0x3c0. Exact member indices and tokens are
in the JSON report and remain distinct from native offsets.

## Selected method candidates and code evidence

| Owner / method | RVA | Return / parameters |
| --- | --- | --- |
| GameFacade.CurrentMatch | 0x71c543c | Match object / none |
| GameFacade.CurrentLocalPlayer | 0x71c5838 | Player / none |
| Player.get_HeadCollider | 0x6f333dc | Collider / none |
| Player.SetAimRotation | 0x6f34ec0 | void / Quaternion, bool |
| Player.get_HeadBoneTransform | 0x6f37be4 | Transform / none |
| Player.IsVisible | 0x6f38834 | bool / none |
| Player.IsLocalPlayer | 0x6eff934 | bool / none |
| MatchGame.GetMatch | 0x731de48 | Match object / none |
| JMAGGLCNGIG.IKKLCLKFBHM | 0x720a764 | Player / none |

Disassembly with Capstone 5.0.6 independently agrees with several field-offset
entries. The generated reference includes the corresponding instruction bytes:

- RVA 0x6f37c50 loads the Player+0xa00 transform provider. The getter then uses
  interface dispatch. This pointer is not a head position or a direct Transform.
- RVA 0x6f38874 loads the Player+0xad0 visibility provider before calling another
  method. The meaning is not established as line-of-sight visibility.
- RVAs 0x6f34fdc–0x6f34fe8 store four floats at Player+0x614/618/61c/620 in one
  original-code branch of SetAimRotation. Another branch calls a helper. The
  named `m_CurrentAimRotation` field at 0x1a8c is a different field.
- RVA 0x731de80 loads MatchGame+0x90; RVA 0x720a79c loads Match+0xd8. These support
  an original-code object-chain hypothesis, not a verified live object chain.

The methods contain hotfix-dispatch checks. Static original-code behavior is
not proof that a hotfix override is inactive. The Windows x64 DLL also cannot
directly call an Android ARM64 function using a Windows function pointer.

## Version 6 verification and remaining scope

After the existing module verification, version 6 reads 80 fixed references
twice: registration counts and relocated pointers, selected type/field/size
entries, method pointers, entry bytes, and the instruction samples above. Each
read uses the verified game page table, RAM bounds, translation recheck, and
unchanged global read/time budget. Process identity is rechecked between rounds;
the ADB PID is rechecked before final success. The native plugin remains read-only.

`GameLayoutRegistration=PASS Fields=9 Methods=9 Checks=80 Passes=2` means these
registration/code observations agree with the supplied APK. It does not mean
that player enumeration, active-object lifetime, head world coordinates,
visibility semantics, hotfix behavior, ARM64 calls, or aim writes work.
Live version 6 verification is pending.

Seventy-two offline C# checks pass (46 reader/header, 18 module, 8 registration).
The registration fixture needs 1018 reads. It rejects changed field offsets,
unrelocated method pointers, altered code, between-round mutation, changed
process mm, and the wrong module profile. Metadata recovery reproduces identical
JSON/C# outputs. Five negative Python checks reject wrong input hashes, an
invalid method owner, an out-of-range string index, and an invalid parameter
range. Runner syntax and the established RAM/CPU parsers also pass.

Reproduce the static report/reference:

```sh
python3 Recover-GameLayout.py /path/to/libil2cpp.so /path/to/global-metadata.dat output-directory
```
