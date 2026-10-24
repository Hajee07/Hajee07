"""Read the two recovered timer-status integers without inventing a timer.

JNI slots 0x2CC and 0x34C are NewIntArray and SetIntArrayRegion respectively.
The native wrapper copies the two 32-bit globals below into a Java int[2].
Their gameplay meanings are not established by this wrapper alone.
"""
from collections.abc import Callable
import struct

TIMER_STATUS_ADDRESSES = (0x100E3A60, 0x100E1000)


def update_timer_status_from_response(response: bytes,
                                      write_bytes: Callable[[int, bytes], None]) -> None:
    """Translate only OnDrawLoad's two response-trailer assignments.

    ARM 0x1009948C..0x10099494 makes r9=response+0x2948. Instructions
    0x10099550..0x10099564 copy the following two 32-bit words to the globals.
    This does not implement the rest of OnDrawLoad's Android rendering.
    """
    if len(response) != 0x2960:
        raise ValueError('Expected a complete recovered 0x2960-byte response')
    for index, address in enumerate(TIMER_STATUS_ADDRESSES):
        offset = 0x2948 + index * 4
        write_bytes(address, response[offset:offset + 4])


def getMatchTimerStatus(read_bytes: Callable[[int, int], bytes]) -> list[int]:
    """Translate the successful Java int-array allocation path.

    read_bytes must read actual supplied native-state data. These addresses are
    snapshot-model addresses, not automatically valid live-process addresses.
    No elapsed-time computation, countdown or Android connection is invented.
    Native Java allocation failure (NULL/OOM) is not modeled by this adapter.
    """
    return [struct.unpack('<i', read_bytes(address, 4))[0]
            for address in TIMER_STATUS_ADDRESSES]
