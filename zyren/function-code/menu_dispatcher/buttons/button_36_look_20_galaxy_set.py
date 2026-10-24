"""LOOK / Look 20 - Galaxy Set — recovered menu ID 7121.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1154-1179,530-532,2881-2886.
Send command 7121 only when value == 1; otherwise no native action.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_36_look_20_galaxy_set(runtime: MenuRuntime, value: int) -> None:
    # No disable/reset request exists in this recovered branch.
    if u32(value) == 1:
        runtime.request(7121, 1)
