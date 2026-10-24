"""Translation of the recovered getEnemyList JNI wrapper, not enemy discovery.

The native wrapper calls FUN_1008c0a0(output,1920,1080), then reads an existing
0x2960-byte response. It does not search a game process or filter teams itself.
Name/ID offsets are verified from ARM instructions at 0x100992D8..0x10099388.
The server implementation producing that response is outside this function.
"""
from collections.abc import Callable
import struct

RESPONSE_BYTES = 0x2960
RECORD_STRIDE = 0xB0
FIRST_NAME_OFFSET = 0x24
FIRST_ID_OFFSET = 0xB0


def decode_modified_utf8(data: bytes) -> str:
    """Adapt valid JNI modified-UTF-8 string bytes to Python Unicode.

    Invalid/truncated encodings raise rather than mimicking unspecified JNI
    handling. getEnemyListRaw can be used to retain the exact pre-JNI bytes.
    """
    value = data.replace(b'\xC0\x80', b'\0').decode('utf-8', 'surrogatepass')
    return value.encode('utf-16-le', 'surrogatepass').decode('utf-16-le', 'surrogatepass')


def getEnemyListRaw(response: bytes) -> list[bytes] | None:
    """Return alternating name bytes and decimal uint64 ID bytes.

    None mirrors the native NULL return when status==0 or count==0. Bounds and
    terminator checks below are explicit Python input-safety additions; the
    recovered native function does not contain equivalent defensive checks.
    """
    if len(response) != RESPONSE_BYTES:
        raise ValueError('Expected the complete 0x2960-byte recovered response')
    count = struct.unpack_from('<I', response, 4)[0]
    if response[0] == 0 or count == 0:
        return None
    if count > 60:
        raise ValueError('Count exceeds the records available in this fixed response')
    output: list[bytes] = []
    for index in range(count):
        name_offset = FIRST_NAME_OFFSET + index * RECORD_STRIDE
        id_offset = FIRST_ID_OFFSET + index * RECORD_STRIDE
        end = response.find(b'\0', name_offset)
        if end < 0:
            raise ValueError('Native name source has no terminator inside the response')
        # snprintf(name_buffer,256,"%s",source) keeps at most 255 bytes.
        name = response[name_offset:min(end, name_offset + 255)]
        target_id = struct.unpack_from('<Q', response, id_offset)[0]
        output.extend((name, str(target_id).encode('ascii')))
    return output


def getEnemyList(fetch_response: Callable[[int, int], bytes]) -> list[str] | None:
    """Caller supplies the actual native response-producing operation."""
    raw = getEnemyListRaw(fetch_response(1920, 1080))
    return None if raw is None else [decode_modified_utf8(value) for value in raw]
