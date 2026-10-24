# Recovered local Unix IPC transport

`local_unix_ipc.py` implements the transport consumed by the existing translated
`MenuRuntime` and `LockPlayer` wrapper. This is recovered client connection and
framing logic. It does not supply or start the native game server.

Recovered evidence:

- Socket creation: `socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0)`.
- Abstract name: `b'\x00FHKFKLFLF'.ljust(108, b'\x00')`. The original
  `sockaddr_un` length is110 bytes including the family. Trailing abstract-name
  zeros are significant; using only the printable string is a different address.
- `send` writes a4-byte big-endian payload length, followed by the payload.
- The known menu requests are32 bytes. The response caller capacity is0x2960.
- The initialization request has command1 at offset0, byte4 equal to1, and all
  other bytes zero; it is independently checked against snapshot offset0xB2FA8.

The caller explicitly calls `connect()` before sending. There is no Internet
connection or automatic game injection. This requires the actual Unix server
to exist in the same usable OS/socket namespace. A Python process on Windows
does not gain access to an abstract socket inside the BlueStacks Android guest
just by knowing this name; no guest bridge is recovered here.

The existing interface is preserved:

```python
transport.send(0x100E1020, payload)       # bool
transport.receive(0x100E1020, 0x2960)    # bytes
transport.initialize()                  # optional adapter: reply bytes or None
```

0x100E1020 is a snapshot identity used to select the client, not a live-process
address dereferenced by this Python module. Initialization's return API is a
Python adaptation; the original Java declaration is not claimed recovered.

Explicit adaptations are documented in code: a finite configurable timeout,
input length checks, response-capacity checks, and rejection of truncated
frames. The original native receiver's unchecked capacity/undefined partial
buffer behavior is not reproduced. A bad declared length raises
`IPCProtocolError`; ordinary connection/EOF failures close this client socket
and are available in `last_error`. A failed send returnsFalse. A receive failure
returns empty bytes and marks the connection closed; a legitimate zero-length
frame returns empty bytes while keeping the client state connected.

## Tests

```bash
python3 test_local_unix_ipc.py
python3 test_menu_runtime_integration.py --handlers-dir /path/to/51-control-python-folder
```

Ten synthetic Unix-stream checks passed, including forced one-byte reads,
header/payload EOF, oversized responses, zero-length frames and the exact
LockPlayer command525/target-offset24 packet. An additional integration with
the existing Enable All handler passed: the synthetic peer received command102
and then command3, and the handler set its recovered local flag. These are
host-local synthetic peers, not a real native server or live gameplay test.
