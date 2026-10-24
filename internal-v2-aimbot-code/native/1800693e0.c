/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800693e0(longlong *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lStackX_8;
  
  recovered_180067b80(&lStackX_8);
  lVar1 = *param_1;
  lVar3 = lStackX_8;
  if (0 < lVar1) {
    lVar3 = 0x7fffffffffffffff;
    if (lStackX_8 < lVar1 * -1000000 + 0x7fffffffffffffff) {
      lVar3 = lStackX_8 + lVar1 * 1000000;
    }
  }
  recovered_180067b80(&lStackX_8);
  while (lStackX_8 < lVar3) {
    lVar1 = lVar3 - lStackX_8;
    if (lVar1 < 0x4e94914f0001) {
      uVar2 = lVar1 / 1000000;
      if ((longlong)(uVar2 * 1000000) < lVar1) {
        uVar2 = (ulonglong)((int)uVar2 + 1);
      }
    }
    else {
      uVar2 = 86400000;
    }
    func_0x000180126aac(uVar2 & 0xffffffff);
    recovered_180067b80(&lStackX_8);
  }
  return;
}

