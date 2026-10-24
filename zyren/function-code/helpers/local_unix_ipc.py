"""Recovered local AF_UNIX client framing, adapted to Python sockets.

Evidence: native functions 1009d7bc/1009d7f4 create/connect an abstract Unix
stream; 1009d8f4/1009d9fc send/receive a BE32 length followed by payload bytes.
The fresh menu snapshot resolves the original abstract name below. Trailing
zeros are part of an abstract socket address, not ignorable string padding.

No server, game injection, Internet connection or Android bridge is implemented.
Connections occur only after an explicit connect() call. These are host-local
Unix sockets; this does not connect from Windows into a BlueStacks guest.
"""
from __future__ import annotations

import socket
import struct

SNAPSHOT_CHANNEL = 0x100E1020
NATIVE_ENDPOINT = b'\x00FHKFKLFLF'.ljust(108, b'\x00')
MAX_REPLY_BYTES = 0x2960
INITIALIZE_PAYLOAD = struct.pack('<IB27x', 1, 1)


class IPCProtocolError(ValueError):
    """An explicitly bounded Python protocol check failed."""


class IPCConnectionClosed(ConnectionError):
    pass


class LocalUnixIPCTransport:
    """One synchronous recovered client connection.

    send(channel,payload)->bool and receive(channel,max_bytes)->bytes implement
    the existing MenuRuntime/LockPlayer transport interface. The channel number
    is an analysis snapshot identifier, never dereferenced as process memory.

    A finite timeout, request-size validation, response capacity check and
    rejection of partial frames are deliberate Python safety adaptations.
    The original receive helper can write the declared length without checking
    its caller's buffer capacity; that unsafe behavior is not reproduced.
    """

    def __init__(self, endpoint: bytes = NATIVE_ENDPOINT, timeout: float | None = 5.0,
                 connected_socket: socket.socket | None = None):
        if not isinstance(endpoint, bytes) or len(endpoint) != 108 or endpoint[0] != 0:
            raise ValueError('Expected an exact 108-byte abstract Unix socket name')
        if timeout is not None and timeout <= 0:
            raise ValueError('Timeout must be positive or None')
        self.endpoint = endpoint
        self.timeout = timeout
        self._socket = connected_socket
        self.last_error: Exception | None = None
        if connected_socket is not None:
            connected_socket.settimeout(timeout)
            connected_socket.set_inheritable(False)

    @property
    def connected(self) -> bool:
        return self._socket is not None

    def connect(self) -> bool:
        if self._socket is not None:
            return True
        if not hasattr(socket, 'AF_UNIX'):
            raise RuntimeError('This host does not support Unix-domain sockets')
        stream = None
        self.last_error = None
        try:
            flags = socket.SOCK_STREAM | getattr(socket, 'SOCK_CLOEXEC', 0)
            stream = socket.socket(socket.AF_UNIX, flags, 0)
            stream.set_inheritable(False)
            stream.settimeout(self.timeout)
            stream.connect(self.endpoint)
            self._socket = stream
            return True
        except OSError as error:
            self.last_error = error
            if stream is not None:
                stream.close()
            return False

    def close(self) -> None:
        stream, self._socket = self._socket, None
        if stream is not None:
            stream.close()

    @staticmethod
    def _check_channel(channel: int) -> None:
        if channel != SNAPSHOT_CHANNEL:
            raise ValueError('Channel does not identify the recovered menu client')

    def _fail(self, error: Exception) -> None:
        self.last_error = error
        self.close()

    def _read_exact(self, count: int) -> bytes:
        if self._socket is None:
            raise IPCConnectionClosed('No connected local native server')
        result = bytearray()
        while len(result) < count:
            block = self._socket.recv(count - len(result))
            if not block:
                raise IPCConnectionClosed('Peer closed before the complete frame arrived')
            result.extend(block)
        return bytes(result)

    def send(self, channel: int, payload: bytes) -> bool:
        self._check_channel(channel)
        if not isinstance(payload, bytes) or len(payload) != 32:
            raise ValueError('Recovered menu requests must contain exactly 32 bytes')
        if self._socket is None:
            self.last_error = IPCConnectionClosed('No connected local native server')
            return False
        try:
            self._socket.sendall(struct.pack('>I', len(payload)) + payload)
            return True
        except OSError as error:
            self._fail(error)
            return False

    def receive(self, channel: int, max_bytes: int) -> bytes:
        self._check_channel(channel)
        if not isinstance(max_bytes, int) or not 0 <= max_bytes <= MAX_REPLY_BYTES:
            raise ValueError('Response capacity must be in 0..0x2960')
        try:
            length = struct.unpack('>I', self._read_exact(4))[0]
            if length > max_bytes:
                error = IPCProtocolError('Declared response length exceeds the supplied capacity')
                self._fail(error)
                raise error
            return self._read_exact(length)
        except OSError as error:
            # Explicit adapter behavior: discard partial data rather than
            # presenting a truncated response as a valid completed frame.
            self._fail(error)
            return b''

    def initialize(self) -> bytes | None:
        """Send the recovered command1/byte4=1 packet, then consume its reply.

        The packet is verified from snapshot offset0xB2FA8. Returning reply bytes
        or None is this adapter's API, not a claim about the original Init JNI
        declaration. Call connect() explicitly first.
        """
        if not self.send(SNAPSHOT_CHANNEL, INITIALIZE_PAYLOAD):
            return None
        response = self.receive(SNAPSHOT_CHANNEL, MAX_REPLY_BYTES)
        return response if self.connected else None

    def __enter__(self):
        return self

    def __exit__(self, exception_type, exception, traceback):
        self.close()
