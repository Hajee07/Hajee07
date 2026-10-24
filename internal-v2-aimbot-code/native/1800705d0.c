/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int recovered_1800705d0(longlong param_1)

{
  longlong alStackX_8 [4];
  
  if (DAT_181b302f8 == '\0') {
    return 0xb4;
  }
  if (DAT_181b302f9 != '\0') {
    return 0;
  }
  alStackX_8[0] = param_1;
  recovered_180067b80(alStackX_8);
  return 0xb4 - (int)((alStackX_8[0] - _DAT_181b30300) / 1000000000);
}

