"""AIM / Auto Target — recovered menu ID 34834.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 438-443.
Send command 34834; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_06_auto_target(runtime: MenuRuntime, value: int) -> None:
    runtime.request(34834, int(u32(value) == 1))
