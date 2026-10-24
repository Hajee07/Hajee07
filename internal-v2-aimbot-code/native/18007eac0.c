/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_18007eac0(undefined (*param_1) [16],undefined2 param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = 0;
  iVar1 = func_0x00018007e9d0(param_2);
  lVar2 = (longlong)iVar1;
  if ((((-1 < iVar1) && (iVar1 < (int)((_DAT_181b2f550 - _DAT_181b2f548) / 0x48))) &&
      (*(char *)(_DAT_181b2f548 + 0x42 + lVar2 * 0x48) == (char)lVar3)) &&
     ((*(longlong *)(_DAT_181b2f548 + 0x10 + lVar2 * 0x48) != lVar3 ||
      (*(char *)(_DAT_181b2f548 + 0x40 + lVar2 * 0x48) != (char)lVar3)))) {
    recovered_180080190(param_1,_DAT_181b2f548 + lVar2 * 0x48);
    return param_1;
  }
  *param_1 = ZEXT816(0);
  *(longlong *)param_1[1] = lVar3;
  *(undefined8 *)(param_1[1] + 8) = 0xf;
  (*param_1)[0] = 0;
  return param_1;
}

