"""LOOK / Look 6 - Titan — recovered menu ID 7107.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7107 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_22_look_6_titan(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7107, 1)
