/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180071ae0(uint param_1)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  float fVar6;
  char cVar7;
  short sVar8;
  undefined2 uVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  longlong *plVar13;
  ulonglong uVar14;
  longlong lVar15;
  longlong lVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  int aiStackX_10 [2];
  int iStackX_18;
  undefined4 uStackX_1c;
  undefined8 uStackX_20;
  undefined8 uStack_118;
  float fStack_110;
  undefined8 uStack_108;
  float fStack_100;
  undefined8 uStack_f8;
  float fStack_f0;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  
  if (DAT_181b2b61d == '\0') {
    if (_DAT_181b2f4b0 != 0) {
      recovered_180071340();
    }
    _DAT_181ade200 = 0xffffffff;
    return;
  }
  if (_DAT_181b2bec8 < 1) {
    return;
  }
  if (_DAT_181b2becc < 1) {
    return;
  }
  if (DAT_181b2bec4 == '\0') {
    return;
  }
  if (param_1 == 0) {
    return;
  }
  uVar10 = (uint)(_DAT_181b2b620 == 1);
  if (_DAT_181ade200 != uVar10) {
    _DAT_181ade200 = uVar10;
    if (_DAT_181b2f4b0 != 0) {
      recovered_180071340();
    }
    _DAT_181b2f8cc = 0;
  }
  cVar7 = func_0x000180077db0((ulonglong)param_1 + _DAT_181b2bf70);
  sVar8 = GetAsyncKeyState(1);
  if ((cVar7 == '\0') && (-1 < sVar8)) {
    if (_DAT_181b2f4b0 != 0) {
      recovered_180071340();
    }
    _DAT_181b2f8cc = 0;
    return;
  }
  if (_DAT_181b2f8cc == 0) {
LAB_180071cae:
    lVar15 = func_0x000180071690();
    if (lVar15 == 0) {
      return;
    }
    _DAT_181b2f8cc = *(uint *)(lVar15 + 0x84);
  }
  else {
    uVar14 = (((((ulonglong)_DAT_181b2f8cc & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^
               (ulonglong)(_DAT_181b2f8cc >> 8) & 0xff) * 0x100000001b3 ^
              (ulonglong)(_DAT_181b2f8cc >> 0x10 & 0xff)) * 0x100000001b3 ^
             (ulonglong)(_DAT_181b2f8cc >> 0x18)) * 0x100000001b3 & _DAT_181b2be60;
    lVar12 = *(longlong *)(_DAT_181b2be48 + 8 + uVar14 * 0x10);
    if (lVar12 == _DAT_181b2be38) {
LAB_180071c81:
      lVar12 = 0;
    }
    else {
      uVar10 = *(uint *)(lVar12 + 0x10);
      while (_DAT_181b2f8cc != uVar10) {
        if (lVar12 == *(longlong *)(_DAT_181b2be48 + uVar14 * 0x10)) goto LAB_180071c81;
        lVar12 = *(longlong *)(lVar12 + 8);
        uVar10 = *(uint *)(lVar12 + 0x10);
      }
    }
    lVar15 = _DAT_181b2be38;
    if (lVar12 != 0) {
      lVar15 = lVar12;
    }
    if (lVar15 == _DAT_181b2be38) goto LAB_180071cae;
    lVar15 = lVar15 + 0x18;
    cVar7 = recovered_180071610(lVar15,_DAT_181b2bebc);
    if ((cVar7 == '\0') || (lVar15 == 0)) goto LAB_180071cae;
  }
  aiStackX_10[0] = 0;
  puVar1 = (uint *)(lVar15 + 0x84);
  cVar7 = recovered_180067cc0((ulonglong)*puVar1 + _DAT_181a2b148,&iStackX_18);
  if (cVar7 == '\0') {
    return;
  }
  iVar11 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),aiStackX_10,4);
  if (iVar11 != 0) {
    return;
  }
  if (aiStackX_10[0] == 0) {
    return;
  }
  uStack_118 = 0;
  fStack_110 = 0.0;
  cVar7 = recovered_180067cc0(aiStackX_10[0] + 8,&uStackX_20);
  if (cVar7 == '\0') {
    return;
  }
  iVar11 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_20,&iStackX_18,4);
  if (iVar11 != 0) {
    return;
  }
  cVar7 = recovered_18006bd40(iStackX_18,&uStack_118);
  fVar20 = fStack_110;
  if (cVar7 == '\0') {
    return;
  }
  uVar14 = (((((ulonglong)*(byte *)puVar1 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
             (ulonglong)*(byte *)(lVar15 + 0x85)) * 0x100000001b3 ^
            (ulonglong)*(byte *)(lVar15 + 0x86)) * 0x100000001b3 ^
           (ulonglong)*(byte *)(lVar15 + 0x87)) * 0x100000001b3 & _DAT_181b2f4d0;
  lVar12 = *(longlong *)(_DAT_181b2f4b8 + 8 + uVar14 * 0x10);
  lVar16 = 0;
  if (lVar12 != _DAT_181b2f4a8) {
    uVar10 = *(uint *)(lVar12 + 0x10);
    while ((lVar16 = lVar12, *puVar1 != uVar10 &&
           (lVar16 = 0, lVar12 != *(longlong *)(_DAT_181b2f4b8 + uVar14 * 0x10)))) {
      lVar12 = *(longlong *)(lVar12 + 8);
      uVar10 = *(uint *)(lVar12 + 0x10);
    }
  }
  fVar21 = uStack_118._4_4_;
  fVar22 = (float)uStack_118;
  lVar12 = _DAT_181b2f4a8;
  if (lVar16 != 0) {
    lVar12 = lVar16;
  }
  if (lVar12 == _DAT_181b2f4a8) {
    plVar13 = (longlong *)func_0x000180078d00(0x181b2f4a0,&uStack_f8,puVar1);
    lVar12 = *plVar13;
    if ((undefined8 *)(lVar12 + 0x14) != &uStack_118) {
      *(float *)(undefined8 *)(lVar12 + 0x14) = fVar22;
      *(float *)(lVar12 + 0x18) = fVar21;
      *(float *)(lVar12 + 0x1c) = fVar20;
    }
  }
  plVar13 = (longlong *)func_0x000180078d00(0x181b2f4a0,&uStack_f8,puVar1);
  uStack_108 = *(undefined8 *)(*plVar13 + 0x14);
  fStack_100 = *(float *)(*plVar13 + 0x1c);
  recovered_180071430(&uStack_f8,lVar15);
  fVar4 = _DAT_181b2be98;
  fVar3 = _DAT_181b2be88;
  fVar2 = _DAT_181b2be78;
  fVar19 = (float)uStack_f8;
  fVar6 = uStack_f8._4_4_;
  if ((((float)uStack_f8 == 0.0) && (uStack_f8._4_4_ == 0.0)) && (fStack_f0 == 0.0)) {
    return;
  }
  fVar22 = fVar22 - (float)uStack_f8;
  fVar21 = fVar21 - uStack_f8._4_4_;
  fVar18 = _DAT_181b2be78 * _DAT_181b2be78 + _DAT_181b2be88 * _DAT_181b2be88 +
           _DAT_181b2be98 * _DAT_181b2be98;
  if (fVar18 < 0.0) {
    fVar18 = (float)func_0x0001801cb525(fVar18);
  }
  else {
    fVar18 = SQRT(fVar18);
  }
  if (fVar18 < _DAT_181a0310c) {
    return;
  }
  uStack_f8 = _DAT_181b2beb0;
  uVar5 = uStack_f8;
  fVar17 = (float)((ulonglong)_DAT_181b2beb0 >> 0x20);
  uStack_f8._0_4_ = (float)_DAT_181b2beb0;
  fVar19 = (fVar6 - fVar17) * (fVar3 / fVar18) + (fVar19 - (float)uStack_f8) * (fVar2 / fVar18) +
           (fStack_f0 - _DAT_181b2beb8) * (fVar4 / fVar18);
  fStack_e8 = fVar19 * (fVar2 / fVar18) + (float)uStack_f8 + fVar22;
  fStack_e4 = fVar19 * (fVar3 / fVar18) + fVar17 + fVar21;
  fStack_e0 = fVar19 * (fVar4 / fVar18) + _DAT_181b2beb8 + (fVar20 - fStack_f0);
  fVar20 = _DAT_181b2b628;
  if (_DAT_181b2b628 <= 0.0) {
    fVar20 = _DAT_181a032e0;
  }
  fVar22 = _DAT_181b2b62c;
  if (_DAT_181b2b62c <= 0.0) {
    fVar22 = _DAT_181a03230;
  }
  uStack_f8 = uVar5;
  if (fVar22 < (float)((uint)(fStack_e4 - uStack_108._4_4_) & _DAT_181a039d0)) {
LAB_18007209c:
    func_0x0001800710b0(*puVar1,&uStack_108);
  }
  else {
    if (0.0 < fVar20) {
      fVar22 = (uStack_108._4_4_ - fStack_e4) * (uStack_108._4_4_ - fStack_e4) +
               ((float)uStack_108 - fStack_e8) * ((float)uStack_108 - fStack_e8) +
               (fStack_100 - fStack_e0) * (fStack_100 - fStack_e0);
      if (fVar22 < 0.0) {
        fVar22 = (float)func_0x0001801cb525(fVar22);
      }
      else {
        fVar22 = SQRT(fVar22);
      }
      if (fVar20 < fVar22) goto LAB_18007209c;
    }
    func_0x0001800710b0(*puVar1,&fStack_e8);
    uVar9 = recovered_18006e7e0((ulonglong)param_1);
    cVar7 = func_0x00018006e8c0(uVar9);
    if (cVar7 != '\0') {
      uVar10 = *puVar1;
      if (uVar10 != 0) {
        iStackX_18 = recovered_180069360((ulonglong)uVar10 + 0x4e8);
        if ((iStackX_18 != 0) &&
           (cVar7 = recovered_180067cc0((ulonglong)uVar10 + 0x54,&uStackX_20), cVar7 != '\0')) {
          (*_DAT_181b4efa8)(_DAT_181b4ef90,uStackX_20,&iStackX_18,4);
        }
      }
    }
  }
  return;
}

