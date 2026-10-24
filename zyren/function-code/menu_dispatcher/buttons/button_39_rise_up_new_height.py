"""BRTL / Rise Up New Height — recovered menu ID 5660.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1180-1185,493-507.
Convert signed 32-bit value to float32; send command 5660. UI declares 15..100 M.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_39_rise_up_new_height(runtime: MenuRuntime, value: int) -> None:
    # UI range is 15..100 M; this native handler itself does not clamp.
    runtime.request(5660, 0, float(s32(value)))
