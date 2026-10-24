/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong recovered_18006bd40(int param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int aiStackX_8 [2];
  int aiStackX_10 [2];
  int aiStackX_18 [2];
  int aiStackX_20 [2];
  undefined8 uStack_128;
  undefined8 uStack_120;
  float fStack_118;
  int iStack_110;
  int iStack_10c;
  undefined auStack_108 [8];
  float fStack_100;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  undefined auStack_e8 [16];
  undefined8 uStack_d8;
  undefined8 auStack_d0 [23];
  
  iVar2 = 0;
  if (param_2 != auStack_d0) {
    *param_2 = 0;
    *(undefined4 *)(param_2 + 1) = 0;
  }
  uVar1 = recovered_180067cc0(param_1 + 8,&uStack_128);
  if (((((((char)uVar1 != '\0') &&
         (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,aiStackX_10,4), (int)uVar1 == 0)) &&
        (uVar1 = recovered_180067cc0(aiStackX_10[0] + 0x24,&uStack_128), (char)uVar1 != '\0')) &&
       ((uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,aiStackX_20,4), (int)uVar1 == 0 &&
        (uVar1 = recovered_180067cc0(aiStackX_10[0] + 0x20,&uStack_128), (char)uVar1 != '\0')))) &&
      ((uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,aiStackX_18,4), (int)uVar1 == 0 &&
       ((uVar1 = recovered_180067cc0(aiStackX_18[0] + 0x18,&uStack_128), (char)uVar1 != '\0' &&
        (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,&iStack_110,4), (int)uVar1 == 0))))))
     && ((uVar1 = recovered_180067cc0(aiStackX_18[0] + 0x1c,&uStack_128), (char)uVar1 != '\0' &&
         (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,&iStack_10c,4), (int)uVar1 == 0)))) {
    uStack_120 = 0;
    fStack_118 = 0.0;
    uVar1 = recovered_180067cc0(aiStackX_20[0] * 0x30 + iStack_110,&uStack_128);
    if (((((char)uVar1 != '\0') &&
         (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,&uStack_120,0xc), (int)uVar1 == 0)) &&
        (uVar1 = recovered_180067cc0(iStack_10c + aiStackX_20[0] * 4,&uStack_128),
        (char)uVar1 != '\0')) &&
       (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,aiStackX_8,4), (int)uVar1 == 0)) {
      while( true ) {
        if ((aiStackX_8[0] < 0) || (iVar2 = iVar2 + 1, iVar2 == 0x32)) {
          if (param_2 != &uStack_120) {
            uStack_120._4_4_ = (float)((ulonglong)uStack_120 >> 0x20);
            *(float *)param_2 = (float)uStack_120;
            *(float *)(param_2 + 1) = fStack_118;
            *(float *)((longlong)param_2 + 4) = uStack_120._4_4_;
          }
          return CONCAT71((int7)((ulonglong)&uStack_120 >> 8),iVar2 != 0x32);
        }
        _auStack_108 = ZEXT816(0);
        auStack_e8 = ZEXT816(0);
        fStack_f8 = _DAT_181a03830;
        fStack_f4 = _UNK_181a03834;
        fStack_f0 = _UNK_181a03838;
        fStack_ec = _UNK_181a0383c;
        uVar1 = recovered_180067cc0(aiStackX_8[0] * 0x30 + iStack_110,&uStack_128);
        if (((char)uVar1 == '\0') ||
           (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_128,auStack_108,0x30), (int)uVar1 != 0))
        break;
        fVar11 = (float)auStack_e8._0_4_ * (float)uStack_120;
        fStack_118 = (float)auStack_e8._8_4_ * fStack_118;
        fVar12 = uStack_120._4_4_ * (float)auStack_e8._0_4_;
        fVar5 = fStack_f0 * fStack_f0;
        fVar6 = fStack_f4 * fStack_f8;
        fVar9 = fStack_ec * fStack_f4 * _DAT_181a03498;
        fVar4 = fStack_ec * fStack_f0 * _DAT_181a03498;
        fVar7 = fStack_f0 * fStack_f8;
        fVar10 = fStack_f0 * fStack_f4;
        fVar13 = fStack_f4 * fStack_f4;
        fVar3 = fStack_f8 * fStack_f8;
        fVar8 = fStack_ec * fStack_f8 * _DAT_181a03498;
        uStack_120 = CONCAT44(((fVar6 + fVar6) - fVar4) * fVar11 + fVar12 + (float)auStack_108._4_4_
                              + (fVar5 * _DAT_181a03498 - (fVar3 + fVar3)) * fVar12 +
                              (fVar8 - fVar10 * _DAT_181a03498) * fStack_118,
                              (fVar13 * _DAT_181a03498 - (fVar5 + fVar5)) * fVar11 +
                              fVar11 + (float)auStack_108._0_4_ +
                              (fVar4 - fVar6 * _DAT_181a03498) * fVar12 +
                              ((fVar7 + fVar7) - fVar9) * fStack_118);
        fStack_118 = (fVar9 - fVar7 * _DAT_181a03498) * fVar11 + fStack_118 + fStack_100 +
                     ((fVar10 + fVar10) - fVar8) * fVar12 +
                     (fVar3 * _DAT_181a03498 - (fVar13 + fVar13)) * fStack_118;
        uVar1 = recovered_180067cc0(iStack_10c + aiStackX_8[0] * 4,&uStack_d8);
        if (((char)uVar1 == '\0') ||
           (uVar1 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_d8,aiStackX_8,4), (int)uVar1 != 0))
        break;
      }
    }
  }
  return uVar1 & 0xffffffffffffff00;
}

