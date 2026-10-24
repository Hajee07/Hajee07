/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800727b0(longlong param_1,ulonglong param_2)

{
  uint *puVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined8 uVar7;
  char cVar8;
  int iVar9;
  longlong lVar10;
  longlong *plVar11;
  ulonglong uVar12;
  longlong lVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  int iStackX_8;
  undefined4 uStackX_c;
  ulonglong uStackX_10;
  int aiStackX_18 [2];
  int aiStackX_20 [2];
  undefined8 auStack_98 [2];
  undefined8 uStack_88;
  float fStack_80;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  undefined8 uStack_68;
  
  puVar1 = (uint *)(param_1 + 0x84);
  uStackX_10 = param_2 & 0xffffffff00000000;
  uStack_88 = 0;
  fStack_80 = 0.0;
  iStackX_8 = 0;
  aiStackX_18[0] = 0;
  aiStackX_20[0] = 0;
  cVar8 = recovered_180067cc0((ulonglong)*puVar1 + _DAT_181a2b148,auStack_98);
  if ((((((cVar8 != '\0') &&
         (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],&iStackX_8,4), iVar9 == 0)) &&
        (iStackX_8 != 0)) &&
       ((cVar8 = recovered_180067cc0(iStackX_8 + 8,auStack_98), cVar8 != '\0' &&
        (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],aiStackX_18,4), iVar9 == 0)))) &&
      ((aiStackX_18[0] != 0 &&
       ((cVar8 = recovered_180067cc0(aiStackX_18[0] + 8,auStack_98), cVar8 != '\0' &&
        (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],aiStackX_20,4), iVar9 == 0)))))) &&
     ((aiStackX_20[0] != 0 &&
      ((((cVar8 = recovered_180067cc0(aiStackX_20[0] + 0x20,auStack_98), cVar8 != '\0' &&
         (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],&uStackX_10,4), iVar9 == 0)) &&
        ((int)uStackX_10 != 0)) &&
       ((cVar8 = recovered_180067cc0((int)uStackX_10 + 0x60,auStack_98), cVar8 != '\0' &&
        (iVar9 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_98[0],&uStack_88,0xc), iVar9 == 0))))))))
  {
    uVar12 = (((((ulonglong)*(byte *)puVar1 ^ 0xcbf29ce484222325) * 0x100000001b3 ^
               (ulonglong)*(byte *)(param_1 + 0x85)) * 0x100000001b3 ^
              (ulonglong)*(byte *)(param_1 + 0x86)) * 0x100000001b3 ^
             (ulonglong)*(byte *)(param_1 + 0x87)) * 0x100000001b3 & _DAT_181b2f490;
    lVar10 = *(longlong *)(_DAT_181b2f478 + 8 + uVar12 * 0x10);
    lVar13 = 0;
    if (lVar10 != _DAT_181b2f468) {
      uVar2 = *(uint *)(lVar10 + 0x10);
      while ((lVar13 = lVar10, *puVar1 != uVar2 &&
             (lVar13 = 0, lVar10 != *(longlong *)(_DAT_181b2f478 + uVar12 * 0x10)))) {
        lVar10 = *(longlong *)(lVar10 + 8);
        uVar2 = *(uint *)(lVar10 + 0x10);
      }
    }
    lVar10 = _DAT_181b2f468;
    if (lVar13 != 0) {
      lVar10 = lVar13;
    }
    if (lVar10 == _DAT_181b2f468) {
      plVar11 = (longlong *)func_0x000180078d00(0x181b2f460,&uStack_68,puVar1);
      lVar10 = *plVar11;
      if ((undefined8 *)(lVar10 + 0x14) != &uStack_88) {
        *(float *)(undefined8 *)(lVar10 + 0x14) = (float)uStack_88;
        *(float *)(lVar10 + 0x18) = uStack_88._4_4_;
        *(float *)(lVar10 + 0x1c) = fStack_80;
      }
    }
    plVar11 = (longlong *)func_0x000180078d00(0x181b2f460,&uStack_68,puVar1);
    fVar6 = _DAT_181b2be98;
    fVar5 = _DAT_181b2be88;
    fVar16 = _DAT_181b2be78;
    fVar3 = *(float *)(*plVar11 + 0x1c);
    auStack_98[0] = *(undefined8 *)(*plVar11 + 0x14);
    fVar14 = _DAT_181b2be78 * _DAT_181b2be78 + _DAT_181b2be88 * _DAT_181b2be88 +
             _DAT_181b2be98 * _DAT_181b2be98;
    if (fVar14 < 0.0) {
      fVar14 = (float)func_0x0001801cb525(fVar14);
    }
    else {
      fVar14 = SQRT(fVar14);
    }
    fVar4 = _DAT_181a032e0;
    if (_DAT_181a0310c <= fVar14) {
      uStack_68 = _DAT_181b2beb0;
      uVar7 = uStack_68;
      uStack_68._4_4_ = (float)((ulonglong)_DAT_181b2beb0 >> 0x20);
      fVar15 = ((float)uStack_88 - (float)_DAT_181b2beb0) * (fVar16 / fVar14) +
               (uStack_88._4_4_ - uStack_68._4_4_) * (fVar5 / fVar14) +
               (fStack_80 - _DAT_181b2beb8) * (fVar6 / fVar14);
      fStack_78 = (fVar16 / fVar14) * fVar15 + (float)_DAT_181b2beb0;
      fStack_74 = (fVar5 / fVar14) * fVar15 + uStack_68._4_4_;
      fStack_70 = (fVar6 / fVar14) * fVar15 + _DAT_181b2beb8;
      fVar16 = fStack_70 - fVar3;
      uStack_68 = uVar7;
      if (_DAT_181a032e0 < (float)((uint)(fStack_78 - (float)auStack_98[0]) & _DAT_181a039d0)) {
        fStack_78 = (float)copysignf(_DAT_181a032e0);
        fStack_78 = fStack_78 + (float)auStack_98[0];
      }
      if (fVar4 < (float)((uint)fVar16 & _DAT_181a039d0)) {
        fStack_70 = (float)copysignf(fVar4);
        fStack_70 = fStack_70 + fVar3;
      }
      fStack_74 = uStack_88._4_4_;
      cVar8 = recovered_180067cc0((int)uStackX_10 + 0x60,&iStackX_8);
      if (cVar8 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(uStackX_c,iStackX_8),&fStack_78,0xc);
      }
    }
  }
  return;
}

