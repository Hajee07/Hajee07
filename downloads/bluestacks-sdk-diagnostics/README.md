# BlueStacks SDK diagnostic

`Test-BlueStacksSdk.ps1` is a diagnostic for the user's already verified BlueStacks
COM registration. Run it in 64-bit Windows PowerShell while the Pie64 instance
is open. It reads the installed COM type library rather than assuming Oracle's
enum values. It also reads SDK/VM metadata.

Version 2 handles MIDL-generated anonymous enum names and named aliases. It
reports the actual library name/GUID/version and type/constant counts. Enum
constants are selected using their documented name prefix or a matching named
alias, and duplicate alias entries are removed. If the Shared lock cannot be
resolved, it prints an inventory and skips the memory probe with exit code 2;
it never substitutes a guessed lock value.

With `-ProbeRead`, it checks that the selected session PID belongs to HD-Player,
attaches using the installed type library's Shared lock value, obtains the console
debugger, and calls its declared guest physical memory read method for one byte
at physical address zero. It releases its shared session in a `finally` block.
An HRESULT is printed if attachment or the read fails. The byte's contents are
not printed.

Example:

```powershell
& .\Test-BlueStacksSdk.ps1 -MachineName Pie64 -ProbeRead
```

Version 3 adds `-ProbeVirtual` (one byte at CPU 0 / guest virtual address zero)
and `-ListInfo` (registered debugger info-handler names/descriptions). Each check
is opt-in. To investigate the remaining declared read route without repeating the
already unimplemented physical read:

```powershell
& .\Test-BlueStacksSdk.ps1 -MachineName Pie64 -ProbeVirtual -ListInfo
```

Exit code 1 means a requested check or session cleanup failed; 2 means the Shared
lock value could not be resolved. Individual output lines identify which check
failed. Even a successful virtual read does not identify the Free Fire address
space. A failed read at zero without E_NOTIMPL may reflect an unmapped address;
it does not by itself prove the whole method is unimplemented.

Oracle VirtualBox 6.1.36 declares this read method but leaves its implementation
as `ReturnComNotImplemented()`. BlueStacks is a fork: this probe distinguishes
a successful SDK metadata query from an actually usable read method. A successful
one-byte read still does not establish guest process address translation, Free
Fire entity/head/visibility mappings, or game aim updates.

The script does not change VM settings, start/stop/pause/resume a VM, query an
internal VM pointer, inject a DLL, or write guest/game memory or aim data.

Validation status: the user ran version 1 on Windows. COM activation, Add-Type
compilation, and type-library enumeration reached the enum-selection step, which
failed because the script assumed exact enum type names. No debugger attachment
or memory probe ran. Version 2 subsequently ran successfully through enum
resolution, metadata, shared attachment, debugger discovery, and session release;
the physical memory read explicitly failed with E_NOTIMPL. See
[runtime results](RUNTIME-RESULTS.md). The user then ran version 3: the virtual
read also explicitly returned E_NOTIMPL, while the info-help listing and shared
session release succeeded. Neither tested COM read method provides a live read.
The cloud workspace is Linux and cannot run the user's installed BlueStacks COM
servers directly.
