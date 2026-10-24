/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined4 * recovered_180079e50(longlong *param_1,longlong param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  longlong lVar12;
  
  lVar3 = *param_1;
  lVar12 = (param_1[1] - lVar3) / 0x28;
  if (lVar12 == 0x666666666666666) {
    recovered_18006aad0();
    pcVar4 = (code *)swi(3);
    puVar9 = (undefined4 *)(*pcVar4)();
    return puVar9;
  }
  uVar1 = lVar12 + 1;
  uVar2 = (param_1[2] - lVar3) / 0x28;
  if (0x666666666666666 - (uVar2 >> 1) < uVar2) {
    uVar10 = 0x666666666666666;
  }
  else {
    uVar2 = (uVar2 >> 1) + uVar2;
    uVar10 = uVar1;
    if (uVar1 <= uVar2) {
      uVar10 = uVar2;
    }
    if (0x666666666666666 < uVar10) {
      func_0x000180003980();
      pcVar4 = (code *)swi(3);
      puVar9 = (undefined4 *)(*pcVar4)();
      return puVar9;
    }
  }
  puVar8 = (undefined4 *)func_0x000180024110(uVar10 * 0x28);
  uVar5 = param_3[1];
  uVar6 = param_3[2];
  uVar7 = param_3[3];
  puVar9 = puVar8 + ((param_2 - lVar3) / 0x28) * 10;
  *puVar9 = *param_3;
  puVar9[1] = uVar5;
  puVar9[2] = uVar6;
  puVar9[3] = uVar7;
  uVar5 = param_3[5];
  uVar6 = param_3[6];
  uVar7 = param_3[7];
  puVar9[4] = param_3[4];
  puVar9[5] = uVar5;
  puVar9[6] = uVar6;
  puVar9[7] = uVar7;
  *(undefined8 *)(puVar9 + 8) = *(undefined8 *)(param_3 + 8);
  lVar3 = *param_1;
  if (param_2 == param_1[1]) {
    lVar12 = param_1[1] - lVar3;
    puVar11 = puVar8;
    param_2 = lVar3;
  }
  else {
    func_0x0001801ca893(puVar8,lVar3,param_2 - lVar3);
    puVar11 = puVar9 + 10;
    lVar12 = param_1[1] - param_2;
  }
  func_0x0001801ca893(puVar11,param_2,lVar12);
  lVar3 = *param_1;
  if (lVar3 != 0) {
    lVar12 = lVar3;
    if ((0xfff < (ulonglong)(((param_1[2] - lVar3) / 0x28) * 0x28)) &&
       (lVar12 = *(longlong *)(lVar3 + -8), 0x1f < (lVar3 - lVar12) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar4 = (code *)swi(3);
      puVar9 = (undefined4 *)(*pcVar4)();
      return puVar9;
    }
    func_0x000180127e40(lVar12);
  }
  *param_1 = (longlong)puVar8;
  param_1[1] = (longlong)(puVar8 + uVar1 * 10);
  param_1[2] = (longlong)(puVar8 + uVar10 * 10);
  return puVar9;
}

