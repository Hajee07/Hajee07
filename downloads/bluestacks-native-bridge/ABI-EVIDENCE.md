# Inspected ABI

Target file SHA-256:
`09fcc9048aaeb610104110a1cf7a533603e423eb681f2e3db61d601869cd095a`.
Both the Windows runner and the plug-in check this exact file fingerprint.
This restriction is intentional: the BlueStacks fork differs from stock 6.1.

The PE image has preferred base `0x180000000`; addresses below are static
disassembly addresses, never runtime pointers used by this program.

## Plug-in entry

The loader resolves the literal export name `DbgPlugInEntry` (string RVA
`0x410d10`, lookup at VA `0x18005ef96`). At the initialization call:

- VA `0x18005ecdd` calls `VMMR3GetVTable`.
- R8 receives its returned vtable pointer.
- R9D receives `0x60001` at `0x18005ece5`.
- RDX receives the UVM context and ECX receives operation 1.
- VA `0x18005ecf6` dispatches to the resolved entry via the PE CFG dispatcher.

Termination similarly uses operation 2, the UVM, the vtable, and argument zero.
The entry therefore uses four Win64 arguments:

```cpp
int DbgPlugInEntry(uint32_t operation, void* uvm,
                  const void* vtable, uintptr_t version);
```

Stock Oracle 6.1.36 source has a three-argument entry. That declaration was not
used for this build. The plug-in checks the version argument and retains no
unvalidated VM-structure assumptions.

## Registration and reads

| Export | RVA | Contract used |
| --- | --- | --- |
| DBGFR3InfoRegisterExternal | 0x5a2f0 | UVM, name, description, callback, user data |
| DBGFR3InfoDeregisterExternal | 0x59a30 | UVM, exact registered name |
| DBGFR3AddrFromPhys | 0x4d290 | UVM, address output, 64-bit physical address |
| DBGFR3MemRead | 0x5b560 | UVM, CPU ID, address, output buffer, byte count |

Registration stores R9 as the callback and the fifth stack argument as user
data. The external handler receives `(user, helper, arguments)`. Only the
helper's first member, its variadic print callback, is used.

`DBGFR3AddrFromPhys` writes 64-bit fields at offsets 0 and 8 and a DWORD
`0x000c0001` at offset 16 (selector=1, flags=12). The address ABI has two
64-bit fields and two 16-bit fields, with 24-byte size and 8-byte alignment.
`DBGFR3MemRead` inspects flags at offset 18 and forwards the fifth argument as
the byte count to its synchronous EMT worker. The worker's physical branch at
VA `0x18005ad55` calls `PGMPhysSimpleReadGCPhys` at `0x1801ee1d0`; it does not
use the external read path that may invoke MMIO access handlers.

Oracle's checksum-verified 6.1.36 source supplies reference semantics for the
info callback, address type, execution-thread dispatch, loader and cleanup.
The uploaded fork's disassembly independently confirms the contracts used here.
Only runtime execution can establish this package's behavior on the user's PC.

## Prior runtime evidence

The user's diagnostic version 3 confirms the installed BlueStacks type library,
Running=6, Shared=1, successful debugger access and successful `Info("help", "")`.
Both COM memory-read methods return E_NOTIMPL. The `plugins` help handler is
present. Successful custom plug-in loading and native memory reads are pending.
