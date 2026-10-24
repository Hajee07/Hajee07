"""BRTL / TeleSpot [AUTO] — recovered menu ID 59912.

Python translation of the supplied recovered dispatcher branch.
Source: evidence/Java_com_NovaX_Menu_ChangesID.c, lines 302-305,311.
Send command 59912; byte is int(u32(value) == 1).
Native game-side execution is not implemented or verified here.
"""
from runtime import MenuRuntime, u32, s32


def button_42_telespot_auto(runtime: MenuRuntime, value: int) -> None:
    runtime.request(59912, int(u32(value) == 1))
