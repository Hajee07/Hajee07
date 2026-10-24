/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
recovered_18006a2a0(undefined8 param_1,undefined8 *param_2,longlong *param_3,undefined4 param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  float fVar11;
  float fVar12;
  
  uVar8 = (((((((((ulonglong)*(byte *)param_3 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                (ulonglong)*(byte *)((longlong)param_3 + 1)) * 0x100000001b3 ^
               (ulonglong)*(byte *)((longlong)param_3 + 2)) * 0x100000001b3 ^
              (ulonglong)*(byte *)((longlong)param_3 + 3)) * 0x100000001b3 ^
             (ulonglong)*(byte *)((longlong)param_3 + 4)) * 0x100000001b3 ^
            (ulonglong)*(byte *)((longlong)param_3 + 5)) * 0x100000001b3 ^
           (ulonglong)*(byte *)((longlong)param_3 + 6)) * 0x100000001b3 ^
          (ulonglong)*(byte *)((longlong)param_3 + 7)) * 0x100000001b3;
  uVar6 = uVar8 & _DAT_181b2bf50;
  puVar7 = (undefined8 *)(uVar6 * 2);
  puVar4 = *(undefined8 **)(_DAT_181b2bf38 + 8 + uVar6 * 0x10);
  puVar9 = _DAT_181b2bf28;
  if (puVar4 != _DAT_181b2bf28) {
    puVar7 = *(undefined8 **)(_DAT_181b2bf38 + uVar6 * 0x10);
    lVar5 = puVar4[2];
    puVar9 = puVar4;
    while( true ) {
      if (*param_3 == lVar5) {
        *param_2 = puVar9;
        *(undefined *)(param_2 + 1) = 0;
        return param_2;
      }
      if (puVar9 == puVar7) break;
      puVar9 = (undefined8 *)puVar9[1];
      lVar5 = puVar9[2];
    }
  }
  if (_DAT_181b2bf30 == 0x7ffffffffffffff) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d77d8);
    pcVar2 = (code *)swi(3);
    puVar4 = (undefined8 *)(*pcVar2)();
    return puVar4;
  }
  puVar4 = (undefined8 *)func_0x000180127a94(0x20,puVar7,param_3,param_4,&DAT_181b2bf28,0);
  puVar4[2] = *param_3;
  puVar4[3] = 0;
  uVar3 = _DAT_181b2bf58;
  uVar6 = _DAT_181b2bf30 + 1;
  if ((longlong)uVar6 < 0) {
    fVar11 = (float)(uVar6 >> 1 | (ulonglong)((uint)uVar6 & 1));
    fVar11 = fVar11 + fVar11;
  }
  else {
    fVar11 = (float)uVar6;
  }
  if ((longlong)_DAT_181b2bf58 < 0) {
    fVar12 = (float)(_DAT_181b2bf58 >> 1 | (ulonglong)((uint)_DAT_181b2bf58 & 1));
    fVar12 = fVar12 + fVar12;
  }
  else {
    fVar12 = (float)_DAT_181b2bf58;
  }
  if (_DAT_181b2bf20 < fVar11 / fVar12) {
    fVar11 = (float)func_0x0001801cb4e3(fVar11 / _DAT_181b2bf20);
    lVar5 = 0;
    if ((_DAT_181a03458 <= fVar11) && (fVar11 = fVar11 - _DAT_181a03458, fVar11 < _DAT_181a03458)) {
      lVar5 = -0x8000000000000000;
    }
    uVar6 = 8;
    if (8 < (ulonglong)((longlong)fVar11 + lVar5)) {
      uVar6 = (longlong)fVar11 + lVar5;
    }
    uVar10 = uVar3;
    if ((uVar3 < uVar6) && ((0x1ff < uVar3 || (uVar10 = uVar3 * 8, uVar3 * 8 < uVar6)))) {
      uVar10 = uVar6;
    }
    func_0x00018006af60(uVar6,uVar10);
    puVar7 = *(undefined8 **)(_DAT_181b2bf38 + 8 + (_DAT_181b2bf50 & uVar8) * 0x10);
    puVar9 = _DAT_181b2bf28;
    if (puVar7 != _DAT_181b2bf28) {
      lVar5 = puVar7[2];
      puVar9 = puVar7;
      while (puVar4[2] != lVar5) {
        if (puVar9 == *(undefined8 **)(_DAT_181b2bf38 + (_DAT_181b2bf50 & uVar8) * 0x10))
        goto LAB_18006a520;
        puVar9 = (undefined8 *)puVar9[1];
        lVar5 = puVar9[2];
      }
      puVar9 = (undefined8 *)*puVar9;
    }
  }
LAB_18006a520:
  puVar7 = (undefined8 *)puVar9[1];
  _DAT_181b2bf30 = _DAT_181b2bf30 + 1;
  *puVar4 = puVar9;
  puVar4[1] = puVar7;
  *puVar7 = puVar4;
  puVar9[1] = puVar4;
  lVar5 = _DAT_181b2bf38;
  uVar8 = _DAT_181b2bf50 & uVar8;
  puVar1 = *(undefined8 **)(_DAT_181b2bf38 + uVar8 * 0x10);
  if (puVar1 == _DAT_181b2bf28) {
    *(undefined8 **)(_DAT_181b2bf38 + uVar8 * 0x10) = puVar4;
  }
  else {
    if (puVar1 == puVar9) {
      *(undefined8 **)(_DAT_181b2bf38 + uVar8 * 0x10) = puVar4;
      goto LAB_18006a57f;
    }
    if (*(undefined8 **)(_DAT_181b2bf38 + 8 + uVar8 * 0x10) != puVar7) goto LAB_18006a57f;
  }
  *(undefined8 **)(lVar5 + 8 + uVar8 * 0x10) = puVar4;
LAB_18006a57f:
  *param_2 = puVar4;
  *(undefined *)(param_2 + 1) = 1;
  return param_2;
}

