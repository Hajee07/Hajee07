/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800802c0(void)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  lVar8 = ((longlong)_DAT_181b2f550 - (longlong)_DAT_181b2f548) / 0x12 +
          ((longlong)_DAT_181b2f550 - (longlong)_DAT_181b2f548 >> 0x3f);
  uVar10 = 25000;
  lVar8 = (lVar8 >> 2) - (lVar8 >> 0x3f);
  uVar1 = (_DAT_181b2f558 - (longlong)_DAT_181b2f548) / 0x48;
  if (0x38e38e38e38e38e - (uVar1 >> 1) < uVar1) {
    uVar10 = 0x38e38e38e38e38e;
  }
  else {
    uVar1 = (uVar1 >> 1) + uVar1;
    if ((24999 < uVar1) && (uVar10 = uVar1, 0x38e38e38e38e38e < uVar1)) {
      func_0x000180003980();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
  }
  lVar6 = func_0x000180024110(uVar10 * 0x48);
  func_0x000180080520(lVar6 + lVar8 * 0x48,25000 - lVar8);
  puVar12 = _DAT_181b2f550;
  if (_DAT_181b2f548 != _DAT_181b2f550) {
    puVar7 = (undefined8 *)(lVar6 + 0x38);
    puVar9 = (undefined8 *)(_DAT_181b2f548 + 0xe);
    puVar11 = _DAT_181b2f548;
    do {
      *(undefined (*) [16])(puVar7 + -7) = ZEXT816(0);
      puVar7[-5] = 0;
      puVar7[-4] = 0;
      uVar3 = puVar11[1];
      uVar4 = puVar11[2];
      uVar5 = puVar11[3];
      *(undefined4 *)(puVar7 + -7) = *puVar11;
      *(undefined4 *)((longlong)puVar7 + -0x34) = uVar3;
      *(undefined4 *)(puVar7 + -6) = uVar4;
      *(undefined4 *)((longlong)puVar7 + -0x2c) = uVar5;
      uVar3 = puVar11[5];
      uVar4 = puVar11[6];
      uVar5 = puVar11[7];
      *(undefined4 *)(puVar7 + -5) = puVar11[4];
      *(undefined4 *)((longlong)puVar7 + -0x24) = uVar3;
      *(undefined4 *)(puVar7 + -4) = uVar4;
      *(undefined4 *)((longlong)puVar7 + -0x1c) = uVar5;
      puVar9[-5] = 0;
      puVar9[-4] = 0xf;
      *(undefined *)puVar11 = 0;
      puVar11 = puVar11 + 0x12;
      *(undefined (*) [16])(puVar7 + -3) = ZEXT816(0);
      puVar7[-1] = 0;
      *puVar7 = 0;
      uVar3 = *(undefined4 *)((longlong)puVar9 + -0x14);
      uVar4 = *(undefined4 *)(puVar9 + -2);
      uVar5 = *(undefined4 *)((longlong)puVar9 + -0xc);
      *(undefined4 *)(puVar7 + -3) = *(undefined4 *)(puVar9 + -3);
      *(undefined4 *)((longlong)puVar7 + -0x14) = uVar3;
      *(undefined4 *)(puVar7 + -2) = uVar4;
      *(undefined4 *)((longlong)puVar7 + -0xc) = uVar5;
      uVar3 = *(undefined4 *)((longlong)puVar9 + -4);
      uVar4 = *(undefined4 *)puVar9;
      uVar5 = *(undefined4 *)((longlong)puVar9 + 4);
      *(undefined4 *)(puVar7 + -1) = *(undefined4 *)(puVar9 + -1);
      *(undefined4 *)((longlong)puVar7 + -4) = uVar3;
      *(undefined4 *)puVar7 = uVar4;
      *(undefined4 *)((longlong)puVar7 + 4) = uVar5;
      puVar9[-1] = 0;
      *puVar9 = 0xf;
      *(undefined *)(puVar9 + -3) = 0;
      *(undefined *)(puVar7 + 1) = *(undefined *)(puVar9 + 1);
      *(undefined *)((longlong)puVar7 + 9) = *(undefined *)((longlong)puVar9 + 9);
      *(undefined *)((longlong)puVar7 + 10) = *(undefined *)((longlong)puVar9 + 10);
      puVar7 = puVar7 + 9;
      puVar9 = puVar9 + 9;
    } while (puVar11 != puVar12);
  }
  puVar11 = _DAT_181b2f550;
  puVar12 = _DAT_181b2f548;
  if (_DAT_181b2f548 != (undefined4 *)0x0) {
    for (; puVar12 != puVar11; puVar12 = puVar12 + 0x12) {
      recovered_180066e40(puVar12 + 8);
      recovered_180066e40(puVar12);
    }
    puVar12 = _DAT_181b2f548;
    if ((0xfff < (ulonglong)(((_DAT_181b2f558 - (longlong)_DAT_181b2f548) / 0x48) * 0x48)) &&
       (puVar12 = *(undefined4 **)(_DAT_181b2f548 + -2),
       (undefined *)0x1f < (undefined *)((longlong)_DAT_181b2f548 + (-8 - (longlong)puVar12)))) {
      _invoke_watson(0,0,0,0,0);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    func_0x000180127e40(puVar12);
  }
  _DAT_181b2f550 = (undefined4 *)(lVar6 + 1800000);
  _DAT_181b2f548 = (undefined4 *)lVar6;
  _DAT_181b2f558 = uVar10 * 0x48 + lVar6;
  return;
}

