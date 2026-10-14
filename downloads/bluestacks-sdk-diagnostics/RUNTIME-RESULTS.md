# User-reported BlueStacks runtime results

The user executed diagnostic version 2 in Administrator, 64-bit Windows
PowerShell against their existing Pie64 BlueStacks instance.

| Check | Result |
| --- | --- |
| SDK version / API version | `6.1.36` / `6_1` |
| Installed type library | `BlueStacks`, version `1.3` |
| Type library GUID | `{f2417bb0-086e-4e0d-9437-15f877a323e0}` |
| Types scanned | 494 |
| Constants scanned, including named aliases | 2,106 |
| `MachineState_Running` / `MachineState_Paused` | 6 / 7 |
| `SessionState_Locked` | 2 |
| `LockType_Shared` | 1 |
| Selected VM | `Pie64`, State 6 |
| Selected host process | Session PID 26080, previously identified as HD-Player |
| Console debugger object | Available |
| Guest physical read | **Failed**, HRESULT `0x80004001` |
| Failure text | `Method MachineDebugger::readPhysicalMemory is not implemented` |
| Shared session cleanup | Released |

The fork's `MachineState_AbortedSaved=5` shifts its Running/Paused values relative
to the upstream Oracle 6.1.36 reference. `MachineState_FirstOnline=6` is an enum
boundary alias; the VM's execution state is Running. MIDL anonymous enum names
and named aliases explain why version 1's exact type-name filter found nothing.

The physical-read error is `E_NOTIMPL`, not a missing administrator permission
or an invalid read address. Repeating the same physical call with a different
address cannot implement that method.

The management and debugger connections work, but no live guest memory read has
been demonstrated. Native VMM export names are separate from this unimplemented
COM method; invoking them still requires valid process-local contexts and a
matching ABI/lifetime/thread contract. Free Fire entity/head/visibility mappings
and game aim writes remain unimplemented and unverified.

Version 3 adds independently selectable `-ProbeVirtual` and `-ListInfo` checks.
The former calls the other declared read method once (CPU 0, virtual address 0,
one byte). The latter calls `Info("help", "")` to list registered info-handler
names/descriptions. It does not collect full VM dumps or query internal VM
pointers. These new checks have not yet been run on the user's Windows machine.
Upstream 6.1.36 leaves the virtual-read method unimplemented too, while it
implements the info dispatch and registers the help handler. The fork's actual
result is still needed; method declarations alone do not establish support.
