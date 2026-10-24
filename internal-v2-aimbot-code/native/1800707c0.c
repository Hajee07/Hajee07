/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800707c0(void)

{
  char *pcVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  char *pcVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  ulonglong uVar12;
  char *pcVar13;
  float fVar14;
  longlong lVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  char acStackX_8 [8];
  char cStackX_10;
  uint auStackX_18 [2];
  float fStackX_20;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  undefined8 uStack_1b0;
  float fStack_1a8;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  float fStack_184;
  float fStack_180;
  float fStack_17c;
  uint uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_160;
  float fStack_158;
  undefined8 uStack_150;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  undefined auStack_130 [16];
  longlong lStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_e8;
  
  do {
    do {
      iVar7 = _DAT_181b2becc;
      iVar11 = _DAT_181b2bec8;
      fVar6 = _DAT_181b2be80;
      fVar22 = _DAT_181b2be70;
      fVar5 = _DAT_181b2b428;
      cVar9 = DAT_181b2b406;
      if (DAT_181b4efd2 != '\0') {
        DAT_181b4efd1 = 0;
        return;
      }
    } while ((((DAT_181b2b41d == '\0') || (_DAT_181b2bec8 == -1)) || (_DAT_181b2becc == -1)) ||
            (DAT_181b2bec4 == '\0'));
    fStackX_20 = _DAT_181b2be70;
    fStack_194 = _DAT_181b2be74;
    fStack_184 = _DAT_181b2be7c;
    fStack_198 = _DAT_181b2be84;
    fStack_188 = _DAT_181b2be8c;
    fStack_1a0 = _DAT_181b2be90;
    fStack_190 = _DAT_181b2be94;
    fStack_180 = _DAT_181b2be9c;
    fStack_19c = _DAT_181b2bea0;
    fStack_18c = _DAT_181b2bea4;
    fStack_17c = _DAT_181b2beac;
    uStack_160 = _DAT_181b2beb0;
    fStack_158 = _DAT_181b2beb8;
    fVar25 = (float)_DAT_181b2becc * _DAT_181a031bc;
    fVar24 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
    acStackX_8[0] = DAT_181b2b406;
    uStack_178 = _DAT_181b2bebc;
    cStackX_10 = _DAT_181b2b420 == 2;
    recovered_180070640(auStack_130);
    iVar4 = _DAT_181b2b424;
    fStack_1c8 = 0.0;
    fStack_1c4 = 0.0;
    fStack_1c0 = 0.0;
    bVar3 = false;
    pcVar8 = (char *)auStack_130._8_8_;
    if (auStack_130._0_8_ != auStack_130._8_8_) {
      pcVar13 = (char *)(auStack_130._0_8_ + 0x25);
      fVar23 = _DAT_181a03460;
      do {
        if (((pcVar13[-1] != '\0') && (*pcVar13 == '\0')) &&
           ((cVar9 == '\0' || (pcVar13[1] == '\0')))) {
          if (iVar4 == 1) {
            uStack_f8 = *(undefined8 *)(pcVar13 + -0x19);
            if ((((float)uStack_f8 == 0.0) &&
                (uStack_f8._4_4_ = (float)((ulonglong)uStack_f8 >> 0x20), uStack_f8._4_4_ == 0.0))
               && (*(float *)(pcVar13 + -0x11) == 0.0)) {
              fVar19 = (float)*(undefined8 *)(pcVar13 + -0xd);
              fVar18 = (float)((ulonglong)*(undefined8 *)(pcVar13 + -0xd) >> 0x20);
              fVar14 = *(float *)(pcVar13 + -5);
            }
            else {
              fVar19 = (float)*(undefined8 *)(pcVar13 + -0x19);
              fVar18 = (float)((ulonglong)*(undefined8 *)(pcVar13 + -0x19) >> 0x20);
              fVar14 = *(float *)(pcVar13 + -0x11);
            }
LAB_180070af9:
            uStack_170 = CONCAT44(fVar18,fVar19);
          }
          else {
            uStack_150 = *(undefined8 *)(pcVar13 + -0x25);
            fVar19 = (float)uStack_150;
            fVar14 = *(float *)(pcVar13 + -0x1d);
            uStack_e8._4_4_ = (float)((ulonglong)uStack_150 >> 0x20);
            uStack_e8 = uStack_150;
            if (((fVar19 != 0.0) || (uStack_e8._4_4_ != 0.0)) ||
               (*(float *)(pcVar13 + -0x1d) != 0.0)) {
              fVar18 = uStack_e8._4_4_ + _DAT_181a0315c;
              uStack_150 = CONCAT44(fVar18,fVar19);
              goto LAB_180070af9;
            }
            fVar19 = 0.0;
            fVar14 = 0.0;
            fVar18 = 0.0;
          }
          if (((fVar19 != 0.0) || (fVar18 != 0.0)) || (cVar9 = acStackX_8[0], fVar14 != 0.0)) {
            if (cStackX_10 == '\0') {
              fVar17 = _DAT_181a0348c;
              fVar20 = _DAT_181a0348c;
              if ((0 < iVar11) && (0 < iVar7)) {
                fVar16 = fVar22 * fVar19;
                fVar21 = fStack_188 * fVar18 + fStack_184 * fVar19 + fStack_180 * fVar14 +
                         fStack_17c;
                fVar22 = fStackX_20;
                if (_DAT_181a03124 <= fVar21) {
                  fVar17 = ((fVar6 * fVar18 + fVar16 + fStack_1a0 * fVar14 + fStack_19c) * fVar24) /
                           fVar21 + fVar24;
                  fVar20 = fVar25 - ((fStack_198 * fVar18 + fStack_194 * fVar19 +
                                      fStack_190 * fVar14 + fStack_18c) * fVar25) / fVar21;
                }
              }
              fVar17 = (fVar25 - fVar20) * (fVar25 - fVar20) + (fVar24 - fVar17) * (fVar24 - fVar17)
              ;
              if (fVar17 < 0.0) {
                fVar17 = (float)func_0x0001801cb525(fVar17);
              }
              else {
                fVar17 = SQRT(fVar17);
              }
              if ((0.0 < fVar5) && (cVar9 = acStackX_8[0], fVar5 < fVar17)) goto LAB_180070cdc;
            }
            else {
              fVar17 = (uStack_160._4_4_ - fVar18) * (uStack_160._4_4_ - fVar18) +
                       ((float)uStack_160 - fVar19) * ((float)uStack_160 - fVar19) +
                       (fStack_158 - fVar14) * (fStack_158 - fVar14);
              if (fVar17 < 0.0) {
                fVar17 = (float)func_0x0001801cb525(fVar17);
              }
              else {
                fVar17 = SQRT(fVar17);
              }
            }
            cVar9 = acStackX_8[0];
            if (fVar17 < fVar23) {
              bVar3 = true;
              fVar23 = fVar17;
              fStack_1c0 = fVar14;
              fStack_1c8 = fVar19;
              fStack_1c4 = fVar18;
            }
          }
        }
LAB_180070cdc:
        pcVar1 = pcVar13 + 3;
        pcVar13 = pcVar13 + 0x28;
      } while (pcVar1 != pcVar8);
      if (((bVar3) && (uVar12 = (ulonglong)uStack_178, uStack_178 != 0)) &&
         ((fStack_1c8 != 0.0 || ((fStack_1c4 != 0.0 || (fStack_1c0 != 0.0)))))) {
        acStackX_8[0] = '\0';
        cVar9 = recovered_180067cc0(uVar12 + 0x58c,&uStack_118);
        if ((cVar9 != '\0') &&
           ((((uVar10 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_118,acStackX_8,1), uVar10 == 0 &&
              (acStackX_8[0] != '\0')) &&
             (auStackX_18[0] = uVar10, cVar9 = recovered_180067cc0(uVar12 + 0x9d0,&uStack_110),
             cVar9 != '\0')) &&
            ((iVar11 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_110,auStackX_18,4), iVar11 == 0 &&
             (auStackX_18[0] != 0)))))) {
          uStack_1b0 = 0;
          fStack_1a8 = 0.0;
          cVar9 = recovered_180067cc0((ulonglong)auStackX_18[0] + 0x38,&uStack_108);
          if ((cVar9 != '\0') &&
             (iVar11 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_108,&uStack_1b0,0xc), iVar11 == 0)) {
            fStack_140 = fStack_1c8 - (float)uStack_1b0;
            fStack_13c = fStack_1c4 - uStack_1b0._4_4_;
            fStack_138 = fStack_1c0 - fStack_1a8;
            cVar9 = recovered_180067cc0((ulonglong)auStackX_18[0] + 0x2c,&uStack_100);
            if (cVar9 != '\0') {
              (*_DAT_181b4efa8)(_DAT_181b4ef90,uStack_100,&fStack_140,0xc);
            }
          }
        }
      }
    }
    if (auStack_130._0_8_ != 0) {
      lVar15 = auStack_130._0_8_;
      if ((0xfff < (ulonglong)(((lStack_120 - auStack_130._0_8_) / 0x28) * 0x28)) &&
         (lVar15 = *(longlong *)(auStack_130._0_8_ + -8), 0x1f < (auStack_130._0_8_ - lVar15) - 8U))
      {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      func_0x000180127e40(lVar15);
      auStack_130 = ZEXT816(0);
      lStack_120 = 0;
    }
  } while( true );
}

