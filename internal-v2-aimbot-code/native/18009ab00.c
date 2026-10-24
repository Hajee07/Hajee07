/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * recovered_18009ab00(undefined8 param_1,undefined *param_2,undefined *param_3)

{
  code *pcVar1;
  undefined auVar2 [16];
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  undefined *puVar13;
  ulonglong uVar14;
  undefined *puVar15;
  longlong lVar16;
  undefined auStack_28 [4];
  undefined4 uStack_24;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  
  _auStack_28 = ZEXT816(0);
  uStack_10 = 0xf;
  if (param_2 == param_3) {
    uStack_18 = 0;
    auVar2[15] = 0;
    auVar2._0_15_ = stack0xffffffffffffffd9;
    _auStack_28 = auVar2 << 8;
  }
  else {
    uVar14 = (longlong)param_3 - (longlong)param_2 >> 1;
    uStack_18 = 0;
    if (0x7fffffffffffffff < uVar14) {
      func_0x000180052a50();
      pcVar1 = (code *)swi(3);
      puVar13 = (undefined *)(*pcVar1)();
      return puVar13;
    }
    if (uVar14 < 0x10) {
      _auStack_28 = (undefined *)0x0;
      puVar13 = _auStack_28;
    }
    else {
      uVar12 = uVar14 | 0xf;
      if (uVar12 < 0x8000000000000000) {
        if (uVar12 < 0x16) {
          uVar12 = 0x16;
        }
      }
      else {
        uVar12 = 0x7fffffffffffffff;
      }
      puVar13 = (undefined *)func_0x000180024110(uVar12 + 1);
      _auStack_28 = puVar13;
      uStack_10 = uVar12;
    }
    uVar12 = uVar14;
    puVar3 = auStack_28;
    puVar15 = auStack_28;
    if (0xf < uStack_10) {
      puVar3 = puVar13;
      puVar15 = puVar13;
    }
    for (; uVar12 != 0; uVar12 = uVar12 - 1) {
      *puVar3 = *param_2;
      param_2 = param_2 + 2;
      puVar3 = puVar3 + 1;
    }
    uStack_18 = uVar14;
    puVar15[uVar14] = 0;
  }
  uVar11 = uRam0000000181ade2a4;
  uVar10 = _DAT_181ade2a0;
  uVar9 = uRam0000000181ade29c;
  uVar8 = _DAT_181ade298;
  uVar7 = uRam0000000181ade294;
  uVar6 = uRam0000000181ade290;
  uVar5 = uRam0000000181ade28c;
  uVar4 = _DAT_181ade288;
  if (CONCAT44(uRam0000000181ade2a4,_DAT_181ade2a0) < uStack_10) {
    _DAT_181ade288 = auStack_28;
    uRam0000000181ade28c = uStack_24;
    uRam0000000181ade290 = (undefined4)uStack_20;
    uRam0000000181ade294 = uStack_20._4_4_;
    _DAT_181ade298 = (undefined4)uStack_18;
    uRam0000000181ade29c = uStack_18._4_4_;
    _DAT_181ade2a0 = (undefined4)uStack_10;
    uRam0000000181ade2a4 = uStack_10._4_4_;
    uStack_24 = uVar5;
    auStack_28 = (undefined  [4])uVar4;
    uStack_20._0_4_ = uVar6;
    uStack_20._4_4_ = uVar7;
    uStack_18 = CONCAT44(uVar9,uVar8);
    uStack_10 = CONCAT44(uVar11,uVar10);
    puVar13 = &DAT_181ade288;
  }
  else {
    puVar13 = auStack_28;
    if (0xf < uStack_10) {
      puVar13 = _auStack_28;
    }
    puVar13 = (undefined *)recovered_1800676d0(&DAT_181ade288,puVar13,uStack_18);
  }
  if (0xf < uStack_10) {
    lVar16 = (longlong)_auStack_28;
    if ((0xfff < uStack_10 + 1) &&
       (lVar16 = *(longlong *)((longlong)_auStack_28 + -8),
       0x1f < ((longlong)_auStack_28 - lVar16) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      puVar13 = (undefined *)(*pcVar1)();
      return puVar13;
    }
    func_0x000180127e40(lVar16);
  }
  return puVar13;
}

