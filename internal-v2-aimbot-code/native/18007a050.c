/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong recovered_18007a050(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  code *pcVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  
  lVar5 = *param_1;
  lVar8 = param_2 - lVar5 >> 2;
  lVar3 = param_1[1] - lVar5 >> 2;
  if (lVar3 == 0x3fffffffffffffff) {
    recovered_18006aad0();
    pcVar2 = (code *)swi(3);
    lVar5 = (*pcVar2)();
    return lVar5;
  }
  uVar6 = param_1[2] - lVar5 >> 2;
  uVar1 = lVar3 + 1;
  if (0x3fffffffffffffff - (uVar6 >> 1) < uVar6) {
    uVar7 = 0x3fffffffffffffff;
  }
  else {
    uVar6 = (uVar6 >> 1) + uVar6;
    uVar7 = uVar1;
    if (uVar1 <= uVar6) {
      uVar7 = uVar6;
    }
    if (0x3fffffffffffffff < uVar7) {
      func_0x000180003980();
      pcVar2 = (code *)swi(3);
      lVar5 = (*pcVar2)();
      return lVar5;
    }
  }
  lVar4 = func_0x000180024110(uVar7 * 4);
  *(undefined4 *)(lVar4 + lVar8 * 4) = *param_3;
  lVar3 = *param_1;
  lVar5 = lVar4 + lVar8 * 4;
  if (param_2 == param_1[1]) {
    lVar9 = param_1[1] - lVar3;
    lVar8 = lVar4;
    param_2 = lVar3;
  }
  else {
    func_0x0001801ca893(lVar4,lVar3,param_2 - lVar3);
    lVar8 = lVar5 + 4;
    lVar9 = param_1[1] - param_2;
  }
  func_0x0001801ca893(lVar8,param_2,lVar9);
  lVar3 = *param_1;
  if (lVar3 != 0) {
    lVar8 = lVar3;
    if ((0xfff < (param_1[2] - lVar3 & 0xfffffffffffffffcU)) &&
       (lVar8 = *(longlong *)(lVar3 + -8), 0x1f < (lVar3 - lVar8) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      lVar5 = (*pcVar2)();
      return lVar5;
    }
    func_0x000180127e40(lVar8);
  }
  *param_1 = lVar4;
  param_1[1] = lVar4 + uVar1 * 4;
  param_1[2] = uVar7 * 4 + lVar4;
  return lVar5;
}

