/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800694f0(longlong *param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  code *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  
  puVar6 = (undefined8 *)param_1[1];
  if (puVar6 != (undefined8 *)param_1[2]) {
    *puVar6 = *param_2;
    param_1[1] = param_1[1] + 8;
    return;
  }
  lVar8 = (longlong)puVar6 - *param_1 >> 3;
  if (lVar8 == 0x1fffffffffffffff) {
    recovered_18006aad0();
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  uVar5 = (longlong)(undefined8 *)param_1[2] - *param_1 >> 3;
  uVar1 = lVar8 + 1;
  if (0x1fffffffffffffff - (uVar5 >> 1) < uVar5) {
    uVar7 = 0x1fffffffffffffff;
  }
  else {
    uVar5 = (uVar5 >> 1) + uVar5;
    uVar7 = uVar1;
    if (uVar1 <= uVar5) {
      uVar7 = uVar5;
    }
    if (0x1fffffffffffffff < uVar7) {
      func_0x000180003980();
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
  }
  lVar4 = func_0x000180024110(uVar7 * 8);
  *(undefined8 *)(lVar4 + lVar8 * 8) = *param_2;
  puVar2 = (undefined8 *)*param_1;
  if (puVar6 == (undefined8 *)param_1[1]) {
    lVar9 = (longlong)(undefined8 *)param_1[1] - (longlong)puVar2;
    lVar8 = lVar4;
    puVar6 = puVar2;
  }
  else {
    func_0x0001801ca893(lVar4,puVar2,(longlong)puVar6 - (longlong)puVar2);
    lVar9 = param_1[1] - (longlong)puVar6;
    lVar8 = lVar4 + (lVar8 + 1) * 8;
  }
  func_0x0001801ca893(lVar8,puVar6,lVar9);
  lVar8 = *param_1;
  if (lVar8 != 0) {
    lVar9 = lVar8;
    if ((0xfff < (param_1[2] - lVar8 & 0xfffffffffffffff8U)) &&
       (lVar9 = *(longlong *)(lVar8 + -8), 0x1f < (lVar8 - lVar9) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    func_0x000180127e40(lVar9);
  }
  *param_1 = lVar4;
  param_1[1] = lVar4 + uVar1 * 8;
  param_1[2] = lVar4 + uVar7 * 8;
  return;
}

