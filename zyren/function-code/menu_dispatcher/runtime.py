"""Support for the translated, recovered menu dispatcher.

The addresses below identify locations in the supplied analysis snapshot.
They are NOT addresses in a live BlueStacks process. No process is opened.
Native game implementations and an Android/JNI bridge are not recovered here.
"""
from __future__ import annotations

import operator
import struct
from typing import Protocol


SNAPSHOT_CHANNEL = 0x100E1020
MAX_REPLY_BYTES = 0x2960


def u32(value: int) -> int:
    """Reproduce the original 32-bit integer argument."""
    return operator.index(value) & 0xFFFFFFFF


def s32(value: int) -> int:
    number = u32(value)
    return number if number < 0x80000000 else number - 0x100000000


class NativeBackendRequired(RuntimeError):
    pass


class UnknownInitialState(RuntimeError):
    pass


class Transport(Protocol):
    """Caller-provided implementation of the recovered native send/receive calls."""

    def send(self, channel: int, payload: bytes) -> bool: ...

    def receive(self, channel: int, max_bytes: int) -> bytes: ...


class RecordingTransport:
    """Analysis-only transport. Records bytes; it does not connect to a game."""

    def __init__(self, send_ok: bool = True):
        self.send_ok = send_ok
        self.packets: list[tuple[int, bytes]] = []
        self.receives: list[int] = []

    def send(self, channel: int, payload: bytes) -> bool:
        self.packets.append((channel, payload))
        return self.send_ok

    def receive(self, channel: int, max_bytes: int) -> bytes:
        self.receives.append(channel)
        return b""


class MenuRuntime:
    """Byte-addressed state model plus explicit, caller-supplied native backend.

    Pure local handlers update this model. Request handlers require a Transport.
    The model is useful for inspecting the recovered logic; it is not a game
    memory accessor. Initial state is never silently assumed for toggle handlers.
    """

    def __init__(self, transport: Transport | None = None,
                 initial_bytes: dict[int, int] | None = None):
        self.transport = transport
        self.memory: dict[int, int] = {}
        for address, byte in (initial_bytes or {}).items():
            if not 0 <= byte <= 255:
                raise ValueError("Initial bytes must be in 0..255")
            self.memory[address] = byte
        self.events: list[dict] = []

    def read_u8(self, address: int) -> int:
        try:
            return self.memory[address]
        except KeyError:
            raise UnknownInitialState(
                f"Supply the existing byte at snapshot location {address:#x}; "
                "its initial value has not been established."
            ) from None

    def write_u8(self, address: int, value: int) -> None:
        byte = operator.index(value) & 0xFF
        self.memory[address] = byte
        self.events.append({"type": "write", "address": address,
                            "size": 1, "value": byte})

    def write_f32(self, address: int, value: float) -> None:
        data = struct.pack("<f", value)
        for offset, byte in enumerate(data):
            self.memory[address + offset] = byte
        self.events.append({"type": "write", "address": address, "size": 4,
                            "value": struct.unpack("<I", data)[0]})

    def request(self, command_id: int, enabled_byte: int = 0,
                float_value: float = 0.0) -> bool:
        """Reproduce the recovered 32-byte request and conditional reply read.

        Offset 0: little-endian uint32 command. Offset 4: one byte.
        Offset 8: little-endian float32. Other bytes are zero in these handlers.
        FUN_1009d8f4 adds a big-endian uint32 length before writing the payload;
        that framing belongs to the caller's native Transport implementation.
        """
        if self.transport is None:
            raise NativeBackendRequired(
                "This handler calls the original native backend. Supply a real "
                "Transport, or use RecordingTransport only to inspect requests."
            )
        packet = struct.pack("<IB3xf20x", u32(command_id),
                             operator.index(enabled_byte) & 0xFF, float_value)
        self.events.append({"type": "send", "channel": SNAPSHOT_CHANNEL,
                            "payload": packet.hex()})
        sent = self.transport.send(SNAPSHOT_CHANNEL, packet)
        if sent:
            self.events.append({"type": "receive", "channel": SNAPSHOT_CHANNEL})
            self.transport.receive(SNAPSHOT_CHANNEL, MAX_REPLY_BYTES)
        return sent


def frame_payload(payload: bytes) -> bytes:
    """Length framing recovered from FUN_1009d8f4; no connection is created."""
    return struct.pack(">I", len(payload)) + payload
