/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


bool recovered_180080860(longlong param_1)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  ulonglong uVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined (*pauVar10) [16];
  longlong lVar11;
  undefined *puVar12;
  undefined auStack_28 [16];
  undefined auStack_18 [16];
  
  uVar1 = *(ulonglong *)(param_1 + 0x30);
  if (uVar1 == 0) {
    return true;
  }
  pauVar10 = (undefined (*) [16])(param_1 + 0x20);
  auStack_28 = ZEXT816(0);
  auStack_18 = ZEXT816(0);
  if (0xf < *(ulonglong *)(param_1 + 0x38)) {
    pauVar10 = *(undefined (**) [16])*pauVar10;
  }
  if (0x7fffffffffffffff < uVar1) {
    func_0x000180052a50();
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return (bool)uVar3;
  }
  if (uVar1 < 0x10) {
    auStack_18._0_8_ = uVar1;
    auStack_18._8_8_ = 0xf;
    auStack_28 = *pauVar10;
  }
  else {
    uVar4 = uVar1 | 0xf;
    uVar7 = 0x7fffffffffffffff;
    if ((uVar4 < 0x8000000000000000) && (uVar7 = uVar4, uVar4 < 0x16)) {
      uVar7 = 0x16;
    }
    uVar5 = func_0x000180024110(uVar7 + 1);
    auStack_28._0_8_ = uVar5;
    auStack_18._0_8_ = uVar1;
    auStack_18._8_8_ = uVar7;
    func_0x0001801ca88d(uVar5,pauVar10,uVar1 + 1);
  }
  puVar12 = auStack_28;
  if (0xf < (ulonglong)auStack_18._8_8_) {
    puVar12 = (undefined *)auStack_28._0_8_;
  }
  puVar9 = puVar12 + auStack_18._0_8_;
  puVar8 = auStack_28;
  if (0xf < (ulonglong)auStack_18._8_8_) {
    puVar8 = (undefined *)auStack_28._0_8_;
  }
  if (puVar8 != puVar9) {
    lVar11 = (longlong)puVar12 - (longlong)puVar8;
    do {
      uVar3 = tolower(*puVar8);
      puVar8[lVar11] = uVar3;
      puVar8 = puVar8 + 1;
    } while (puVar8 != puVar9);
  }
  puVar12 = auStack_28;
  if (0xf < (ulonglong)auStack_18._8_8_) {
    puVar12 = (undefined *)auStack_28._0_8_;
  }
  puVar8 = (undefined *)auStack_28._0_8_;
  if (7 < (ulonglong)auStack_18._0_8_) {
    puVar9 = puVar12 + auStack_18._0_8_;
    puVar6 = (undefined *)func_0x0001801278a0(puVar12,puVar9,&UNK_1819d8270,8);
    puVar8 = (undefined *)auStack_28._0_8_;
    if (puVar6 != puVar9) {
      lVar11 = (longlong)puVar6 - (longlong)puVar12;
      goto LAB_1800809c8;
    }
  }
  lVar11 = -1;
LAB_1800809c8:
  if (0xf < (ulonglong)auStack_18._8_8_) {
    puVar12 = puVar8;
    if ((0xfff < auStack_18._8_8_ + 1) &&
       (puVar12 = *(undefined **)(puVar8 + -8),
       (undefined *)0x1f < puVar8 + (-8 - (longlong)puVar12))) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return (bool)uVar3;
    }
    func_0x000180127e40(puVar12);
  }
  return lVar11 != -1;
}

