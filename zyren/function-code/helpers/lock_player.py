"""Translation of the recovered LockPlayer request wrapper.

This constructs a target-ID request; it does not implement game-side aim lock.
ARM source initializes command525 and puts the two 32-bit JNI argument words
at packet offsets24 and28. A 64-bit integer is used here to preserve those bits;
the protected original Java method declaration has not been recovered.
"""
from typing import Protocol
import operator
import struct

SNAPSHOT_CHANNEL = 0x100E1020


class NativeTransport(Protocol):
    def send(self, channel: int, payload: bytes) -> bool: ...
    def receive(self, channel: int, max_bytes: int) -> bytes: ...


def LockPlayer(target_id: int, transport: NativeTransport) -> None:
    payload = bytearray(32)
    struct.pack_into('<I', payload, 0, 525)
    struct.pack_into('<Q', payload, 24, operator.index(target_id) & 0xFFFFFFFFFFFFFFFF)
    if transport.send(SNAPSHOT_CHANNEL, bytes(payload)):
        # The recovered wrapper requests a reply, then discards its contents.
        transport.receive(SNAPSHOT_CHANNEL, 0x2960)
