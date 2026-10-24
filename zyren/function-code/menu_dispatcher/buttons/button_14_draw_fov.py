"""ESP / Draw FOV — recovered menu ID 16.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 1775-1777.
Write one byte at snapshot 0x100E3A6C; true only when value == 1.
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_14_draw_fov(runtime: MenuRuntime, value: int) -> None:
    runtime.write_u8(0x100E3A6C, int(u32(value) == 1))
