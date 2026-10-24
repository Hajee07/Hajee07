"""BRTL / Rise Up — recovered menu ID 111.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 2858-2861.
Send command 5657; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_38_rise_up(runtime: MenuRuntime, value: int) -> None:
    runtime.request(5657, int(u32(value) == 1))
