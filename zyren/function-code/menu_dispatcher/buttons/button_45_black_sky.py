"""BRTL / Black Sky — recovered menu ID 7001.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 2326-2329.
Send command 7001; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_45_black_sky(runtime: MenuRuntime, value: int) -> None:
    runtime.request(7001, int(u32(value) == 1))
