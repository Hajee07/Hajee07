"""LOOK / Look 8 - Bunny Warrior — recovered menu ID 7109.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7109 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_24_look_8_bunny_warrior(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7109, 1)
