/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18008c0f0(uint param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  code *pcVar3;
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined4 uVar6;
  undefined auVar7 [16];
  undefined auVar8 [16];
  undefined auVar9 [16];
  undefined auVar10 [16];
  float fVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  char cVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  int *piVar21;
  undefined (*pauVar22) [16];
  undefined8 *puVar23;
  int *piVar24;
  undefined4 *puVar25;
  int iVar26;
  undefined8 *puVar27;
  undefined8 *puVar28;
  longlong lVar29;
  longlong lVar30;
  int iVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  int iStackX_18;
  undefined4 uStackX_1c;
  int aiStackX_20 [2];
  int iStack_218;
  int iStack_214;
  undefined8 uStack_210;
  float fStack_208;
  int iStack_200;
  uint uStack_1fc;
  int aiStack_1f8 [2];
  undefined auStack_1f0 [16];
  int *piStack_1e0;
  int iStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1cc;
  int iStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  int iStack_1bc;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  int iStack_178;
  undefined8 uStack_174;
  float fStack_16c;
  undefined auStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_158;
  int iStack_154;
  int iStack_150;
  int iStack_14c;
  float fStack_148;
  int iStack_140;
  undefined8 uStack_13c;
  float fStack_134;
  undefined auStack_130 [4];
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  int iStack_120;
  int iStack_11c;
  int iStack_118;
  int iStack_114;
  float fStack_110;
  undefined auStack_f8 [192];
  
  lVar30 = _DAT_181b2bde0;
  if ((DAT_181b2bdd0 == '\0') || (param_1 == 0)) {
    lVar29 = _DAT_181b2bdd8;
    if (_DAT_181b2bdd8 != _DAT_181b2bde0) {
      do {
        recovered_180066e40(lVar29 + 0x10);
        lVar29 = lVar29 + 0x38;
      } while (lVar29 != lVar30);
      _DAT_181b2bde0 = _DAT_181b2bdd8;
    }
  }
  else {
    auStack_1f0 = ZEXT816(0);
    iVar31 = 0;
    piStack_1e0 = (int *)0x0;
    puVar20 = (undefined4 *)func_0x000180024110(0x1c00);
    puVar28 = (undefined8 *)auStack_1f0._8_8_;
    if (auStack_1f0._0_8_ != auStack_1f0._8_8_) {
      puVar23 = (undefined8 *)(puVar20 + 10);
      puVar25 = puVar20;
      puVar27 = (undefined8 *)(auStack_1f0._0_8_ + 0x28);
      do {
        *puVar25 = *(undefined4 *)(puVar27 + -5);
        *(undefined8 *)((longlong)puVar23 + -0x24) = *(undefined8 *)((longlong)puVar27 + -0x24);
        *(undefined4 *)((longlong)puVar23 + -0x1c) = *(undefined4 *)((longlong)puVar27 + -0x1c);
        *(undefined (*) [16])(puVar23 + -3) = ZEXT816(0);
        puVar23[-1] = 0;
        *puVar23 = 0;
        uVar6 = *(undefined4 *)((longlong)puVar27 + -0x14);
        uVar38 = *(undefined4 *)(puVar27 + -2);
        uVar39 = *(undefined4 *)((longlong)puVar27 + -0xc);
        *(undefined4 *)(puVar23 + -3) = *(undefined4 *)(puVar27 + -3);
        *(undefined4 *)((longlong)puVar23 + -0x14) = uVar6;
        *(undefined4 *)(puVar23 + -2) = uVar38;
        *(undefined4 *)((longlong)puVar23 + -0xc) = uVar39;
        uVar6 = *(undefined4 *)((longlong)puVar27 + -4);
        uVar38 = *(undefined4 *)puVar27;
        uVar39 = *(undefined4 *)((longlong)puVar27 + 4);
        *(undefined4 *)(puVar23 + -1) = *(undefined4 *)(puVar27 + -1);
        *(undefined4 *)((longlong)puVar23 + -4) = uVar6;
        *(undefined4 *)puVar23 = uVar38;
        *(undefined4 *)((longlong)puVar23 + 4) = uVar39;
        puVar27[-1] = 0;
        *puVar27 = 0xf;
        *(undefined *)(puVar27 + -3) = 0;
        *(undefined4 *)(puVar23 + 1) = *(undefined4 *)(puVar27 + 1);
        puVar25 = puVar25 + 0xe;
        puVar23 = puVar23 + 7;
        puVar1 = puVar27 + 2;
        puVar27 = puVar27 + 7;
      } while (puVar1 != (undefined8 *)auStack_1f0._8_8_);
    }
    if ((undefined8 *)auStack_1f0._0_8_ != (undefined8 *)0x0) {
      puVar23 = (undefined8 *)auStack_1f0._0_8_;
      if (auStack_1f0._0_8_ != auStack_1f0._8_8_) {
        do {
          recovered_180066e40(puVar23 + 2);
          puVar23 = puVar23 + 7;
        } while (puVar23 != puVar28);
      }
      puVar28 = (undefined8 *)auStack_1f0._0_8_;
      if ((0xfff < (ulonglong)((((longlong)piStack_1e0 - auStack_1f0._0_8_) / 0x38) * 0x38)) &&
         (puVar28 = *(undefined8 **)(auStack_1f0._0_8_ + -8),
         0x1f < (ulonglong)(auStack_1f0._0_8_ + (-8 - (longlong)puVar28)))) {
        _invoke_watson(0,0,0,0,0);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      func_0x000180127e40(puVar28);
    }
    auStack_1f0._8_8_ = puVar20;
    auStack_1f0._0_8_ = puVar20;
    piStack_1e0 = puVar20 + 0x700;
    iStack_1bc = 500;
    iStack_1c0 = 0x14;
    piVar24 = &iStack_1c0;
    if (0x13 < _DAT_181b2bdd4) {
      piVar24 = (int *)&DAT_181b2bdd4;
    }
    piVar21 = &iStack_1bc;
    if (_DAT_181b2bdd4 < 0x1f5) {
      piVar21 = piVar24;
    }
    iVar2 = *piVar21;
    iStack_1c8 = 0;
    iStack_1c4 = 0;
    cVar16 = recovered_180067cc0((ulonglong)param_1 + 0x60,&iStackX_18);
    if (cVar16 != '\0') {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_1c8,4);
    }
    cVar16 = recovered_180067cc0((ulonglong)param_1 + 100,&iStackX_18);
    if (cVar16 != '\0') {
      (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_1c4,4);
    }
    lVar30 = _DAT_181b2bde0;
    iVar15 = _UNK_181a0353c;
    iVar14 = _UNK_181a03538;
    iVar13 = _UNK_181a03534;
    iVar12 = _DAT_181a03530;
    fVar11 = _DAT_181a0313c;
    if ((iStack_1c8 == 0) && (iStack_1c4 == 0)) {
      lVar29 = _DAT_181b2bdd8;
      if (_DAT_181b2bdd8 != _DAT_181b2bde0) {
        do {
          recovered_180066e40(lVar29 + 0x10);
          lVar29 = lVar29 + 0x38;
        } while (lVar29 != lVar30);
        _DAT_181b2bde0 = _DAT_181b2bdd8;
      }
    }
    else {
      if (iStack_1c8 != 0) {
        iStack_200 = 0;
        cVar16 = recovered_180067cc0(iStack_1c8 + 0xc,&iStackX_18);
        if (((cVar16 != '\0') &&
            (iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_200,4
                                       ), iVar17 == 0)) && (iStack_200 != 0)) {
          iStack_218 = 0;
          cVar16 = recovered_180067cc0(iStack_200 + 0x10,&iStackX_18);
          if (((cVar16 != '\0') &&
              (iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_218
                                          ,4), iVar17 == 0)) && (iStack_218 - 1U < 200)) {
            iStack_214 = 0;
            cVar16 = recovered_180067cc0(iStack_200 + 0xc,&iStackX_18);
            if (((cVar16 != '\0') &&
                (iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),
                                            &iStack_214,4), iVar17 == 0)) &&
               ((iStack_214 != 0 &&
                (iStack_214 = iStack_214 + 0x10, iVar17 = iVar31, 0 < iStack_218)))) {
              do {
                if (0x1c1 < (ulonglong)((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38))
                break;
                iVar26 = iVar17 * 0x10 + iStack_214;
                iStack_1d8 = 0;
                cVar16 = recovered_180067cc0(iVar26,&uStack_1b8);
                if (((cVar16 != '\0') &&
                    (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b8,&iStack_1d8,4),
                    iVar18 == 0)) && (-1 < iStack_1d8)) {
                  iStack_1d4 = 0;
                  cVar16 = recovered_180067cc0(iVar26 + 0xc,&uStack_1b0);
                  if (((cVar16 != '\0') &&
                      (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b0,&iStack_1d4,4),
                      iVar26 = iStack_1d4, iVar18 == 0)) && (iStack_1d4 != 0)) {
                    if ((ulonglong)((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38) <
                        0x1c2) {
                      iStackX_18 = 0;
                      cVar16 = recovered_180067cc0(iStack_1d4 + 0x10,&uStack_1a8);
                      if (((cVar16 != '\0') &&
                          (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1a8,&iStackX_18,4),
                          iVar18 == 0)) && (iStackX_18 - 1U < 800)) {
                        aiStackX_20[0] = 0;
                        cVar16 = recovered_180067cc0(iVar26 + 0xc,&uStack_1a0);
                        if ((((cVar16 != '\0') &&
                             (iVar26 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1a0,aiStackX_20,4),
                             iVar26 == 0)) && (aiStackX_20[0] != 0)) &&
                           (aiStackX_20[0] = aiStackX_20[0] + 0x10, iVar26 = iVar31, 0 < iStackX_18)
                           ) {
                          do {
                            if (0x1c1 < (ulonglong)
                                        ((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38))
                            break;
                            iVar18 = iVar26 * 0x10 + aiStackX_20[0];
                            iStack_1d0 = 0;
                            cVar16 = recovered_180067cc0(iVar18,&uStack_198);
                            if (((cVar16 != '\0') &&
                                (iVar19 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_198,&iStack_1d0,4)
                                , iVar19 == 0)) && (-1 < iStack_1d0)) {
                              uStack_1fc = 0;
                              cVar16 = recovered_180067cc0(iVar18 + 0xc,&uStack_190);
                              if (((cVar16 != '\0') &&
                                  (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_190,&uStack_1fc,
                                                              4), iVar18 == 0)) && (uStack_1fc != 0)
                                 ) {
                                iStack_1cc = 0;
                                cVar16 = recovered_18008bca0(uStack_1fc,&iStack_1cc);
                                if (cVar16 != '\0') {
                                  uStack_210 = 0;
                                  fStack_208 = 0.0;
                                  aiStack_1f8[0] = 0;
                                  cVar16 = recovered_180067cc0((ulonglong)uStack_1fc + 0x3c,
                                                               &uStack_188);
                                  if ((((cVar16 != '\0') &&
                                       (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_188,
                                                                   aiStack_1f8,4), iVar18 == 0)) &&
                                      (aiStack_1f8[0] != 0)) &&
                                     (((cVar16 = recovered_18006bd40(aiStack_1f8[0],&uStack_210),
                                       cVar16 != '\0' &&
                                       (((fVar34 = (float)uStack_210, (float)uStack_210 != 0.0 ||
                                         (uStack_210._4_4_ != 0.0)) || (fStack_208 != 0.0)))) ||
                                      (((cVar16 = recovered_180067cc0(aiStack_1f8[0] + 0x3c,
                                                                      &uStack_180), cVar16 != '\0'
                                        && (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_180,
                                                                       &uStack_210,0xc), iVar18 == 0
                                           )) && ((fVar34 = (float)uStack_210,
                                                  (float)uStack_210 != 0.0 ||
                                                  ((uStack_210._4_4_ != 0.0 || (fStack_208 != 0.0)))
                                                  ))))))) {
                                    fVar32 = (float)*param_2 - fVar34;
                                    fVar33 = (float)((ulonglong)*param_2 >> 0x20) - uStack_210._4_4_
                                    ;
                                    fVar32 = fVar33 * fVar33 + fVar32 * fVar32 +
                                             (*(float *)(param_2 + 1) - fStack_208) *
                                             (*(float *)(param_2 + 1) - fStack_208);
                                    if (fVar32 < 0.0) {
                                      fVar32 = (float)func_0x0001801cb525(fVar32);
                                    }
                                    else {
                                      fVar32 = SQRT(fVar32);
                                    }
                                    iVar18 = iStack_1cc;
                                    fVar33 = fStack_208;
                                    if ((fVar32 <= (float)iVar2) && (fVar11 <= fVar32)) {
                                      iStack_158 = iVar12;
                                      iStack_154 = iVar13;
                                      iStack_150 = iVar14;
                                      iStack_14c = iVar15;
                                      stack0xfffffffffffffe99 = SUB1615(ZEXT816(0),1);
                                      auVar7[15] = 0;
                                      auVar7._0_15_ = stack0xfffffffffffffe99;
                                      _auStack_168 = auVar7 << 8;
                                      iStack_178 = iStack_1cc;
                                      uVar6 = uStack_210._4_4_;
                                      uStack_174 = CONCAT44(uStack_210._4_4_,fVar34);
                                      fStack_16c = fStack_208;
                                      fStack_148 = fVar32;
                                      pauVar22 = (undefined (*) [16])
                                                 recovered_1800898f0(auStack_f8,iStack_1cc);
                                      if ((undefined (*) [16])auStack_168 == pauVar22) {
                                        uVar38 = auStack_168;
                                        uVar39 = uStack_164;
                                        uVar40 = uStack_160;
                                        uVar41 = uStack_15c;
                                        iVar19 = iVar12;
                                        iVar35 = iVar13;
                                        iVar36 = iVar14;
                                        iVar37 = iVar15;
                                      }
                                      else {
                                        uVar38 = *(undefined4 *)*pauVar22;
                                        uVar39 = *(undefined4 *)(*pauVar22 + 4);
                                        uVar40 = *(undefined4 *)(*pauVar22 + 8);
                                        uVar41 = *(undefined4 *)(*pauVar22 + 0xc);
                                        _auStack_168 = *pauVar22;
                                        iStack_158 = *(int *)pauVar22[1];
                                        iStack_154 = *(int *)(pauVar22[1] + 4);
                                        iStack_150 = *(int *)(pauVar22[1] + 8);
                                        iStack_14c = *(int *)(pauVar22[1] + 0xc);
                                        *(undefined8 *)pauVar22[1] = 0;
                                        *(undefined8 *)(pauVar22[1] + 8) = 0xf;
                                        (*pauVar22)[0] = 0;
                                        iVar19 = iStack_158;
                                        iVar35 = iStack_154;
                                        iVar36 = iStack_150;
                                        iVar37 = iStack_14c;
                                      }
                                      recovered_180066e40(auStack_f8);
                                      if ((int *)auStack_1f0._8_8_ == piStack_1e0) {
                                        recovered_18008d1e0(auStack_1f0,auStack_1f0._8_8_,
                                                            &iStack_178);
                                      }
                                      else {
                                        *(int *)auStack_1f0._8_8_ = iVar18;
                                        uStack_174 = CONCAT44(uVar6,fVar34);
                                        *(ulonglong *)(auStack_1f0._8_8_ + 4) =
                                             CONCAT44(uVar6,fVar34);
                                        *(float *)(auStack_1f0._8_8_ + 0xc) = fVar33;
                                        auVar4._4_4_ = uVar39;
                                        auVar4._0_4_ = uVar38;
                                        auVar4._8_4_ = uVar40;
                                        auVar4._12_4_ = uVar41;
                                        *(undefined (*) [16])(auStack_1f0._8_8_ + 0x10) = auVar4;
                                        *(int *)(auStack_1f0._8_8_ + 0x20) = iVar19;
                                        *(int *)(auStack_1f0._8_8_ + 0x24) = iVar35;
                                        *(int *)(auStack_1f0._8_8_ + 0x28) = iVar36;
                                        *(int *)(auStack_1f0._8_8_ + 0x2c) = iVar37;
                                        iStack_158 = iVar12;
                                        iStack_154 = iVar13;
                                        iStack_150 = iVar14;
                                        iStack_14c = iVar15;
                                        auVar8[15] = 0;
                                        auVar8._0_15_ = stack0xfffffffffffffe99;
                                        _auStack_168 = auVar8 << 8;
                                        *(float *)(auStack_1f0._8_8_ + 0x30) = fVar32;
                                        auStack_1f0._8_8_ = (int *)(auStack_1f0._8_8_ + 0x38);
                                      }
                                      recovered_180066e40(auStack_168);
                                    }
                                  }
                                }
                              }
                            }
                            iVar26 = iVar26 + 1;
                          } while (iVar26 < iStackX_18);
                        }
                      }
                    }
                  }
                }
                iVar17 = iVar17 + 1;
              } while (iVar17 < iStack_218);
            }
          }
        }
      }
      if ((iStack_1c4 != 0) && (iStack_1c4 != iStack_1c8)) {
        aiStack_1f8[0] = 0;
        cVar16 = recovered_180067cc0(iStack_1c4 + 0xc,&iStackX_18);
        if ((cVar16 != '\0') &&
           ((iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),aiStack_1f8,4
                                       ), iVar17 == 0 && (aiStack_1f8[0] != 0)))) {
          iStack_214 = 0;
          cVar16 = recovered_180067cc0(aiStack_1f8[0] + 0x10,&iStackX_18);
          if ((cVar16 != '\0') &&
             ((iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),&iStack_214
                                          ,4), iVar17 == 0 && (iStack_214 - 1U < 200)))) {
            iStack_218 = 0;
            cVar16 = recovered_180067cc0(aiStack_1f8[0] + 0xc,&iStackX_18);
            if ((cVar16 != '\0') &&
               (((iVar17 = (*_DAT_181b4ef88)(_DAT_181b4ef90,CONCAT44(uStackX_1c,iStackX_18),
                                             &iStack_218,4), iVar17 == 0 && (iStack_218 != 0)) &&
                (iStack_218 = iStack_218 + 0x10, iVar17 = iVar31, 0 < iStack_214)))) {
              do {
                if (0x1c1 < (ulonglong)((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38))
                break;
                iVar26 = iVar17 * 0x10 + iStack_218;
                iStack_1cc = 0;
                cVar16 = recovered_180067cc0(iVar26,&uStack_180);
                if (((cVar16 != '\0') &&
                    (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_180,&iStack_1cc,4),
                    iVar18 == 0)) && (-1 < iStack_1cc)) {
                  iStack_1d0 = 0;
                  cVar16 = recovered_180067cc0(iVar26 + 0xc,&uStack_188);
                  if (((cVar16 != '\0') &&
                      (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_188,&iStack_1d0,4),
                      iVar26 = iStack_1d0, iVar18 == 0)) && (iStack_1d0 != 0)) {
                    if ((ulonglong)((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38) <
                        0x1c2) {
                      iStackX_18 = 0;
                      cVar16 = recovered_180067cc0(iStack_1d0 + 0x10,&uStack_190);
                      if (((cVar16 != '\0') &&
                          (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_190,&iStackX_18,4),
                          iVar18 == 0)) && (iStackX_18 - 1U < 800)) {
                        aiStackX_20[0] = 0;
                        cVar16 = recovered_180067cc0(iVar26 + 0xc,&uStack_198);
                        if (((cVar16 != '\0') &&
                            (iVar26 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_198,aiStackX_20,4),
                            iVar26 == 0)) &&
                           ((aiStackX_20[0] != 0 &&
                            (aiStackX_20[0] = aiStackX_20[0] + 0x10, iVar26 = iVar31, 0 < iStackX_18
                            )))) {
                          do {
                            if (0x1c1 < (ulonglong)
                                        ((longlong)(auStack_1f0._8_8_ - auStack_1f0._0_8_) / 0x38))
                            break;
                            iVar18 = iVar26 * 0x10 + aiStackX_20[0];
                            iStack_1d4 = 0;
                            cVar16 = recovered_180067cc0(iVar18,&uStack_1a0);
                            if (((cVar16 != '\0') &&
                                (iVar19 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1a0,&iStack_1d4,4)
                                , iVar19 == 0)) && (-1 < iStack_1d4)) {
                              uStack_1fc = 0;
                              cVar16 = recovered_180067cc0(iVar18 + 0xc,&uStack_1a8);
                              if (((cVar16 != '\0') &&
                                  (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1a8,&uStack_1fc,
                                                              4), iVar18 == 0)) && (uStack_1fc != 0)
                                 ) {
                                iStack_1d8 = 0;
                                cVar16 = recovered_18008bca0(uStack_1fc,&iStack_1d8);
                                if (cVar16 != '\0') {
                                  uStack_210 = 0;
                                  fStack_208 = 0.0;
                                  iStack_200 = 0;
                                  cVar16 = recovered_180067cc0((ulonglong)uStack_1fc + 0x3c,
                                                               &uStack_1b0);
                                  if (((cVar16 != '\0') &&
                                      (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b0,
                                                                  &iStack_200,4), iVar18 == 0)) &&
                                     ((iStack_200 != 0 &&
                                      (((cVar16 = recovered_18006bd40(iStack_200,&uStack_210),
                                        cVar16 != '\0' &&
                                        (((fVar34 = (float)uStack_210, (float)uStack_210 != 0.0 ||
                                          (uStack_210._4_4_ != 0.0)) || (fStack_208 != 0.0)))) ||
                                       (((cVar16 = recovered_180067cc0(iStack_200 + 0x3c,&uStack_1b8
                                                                      ), cVar16 != '\0' &&
                                         (iVar18 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_1b8,
                                                                     &uStack_210,0xc), iVar18 == 0))
                                        && ((fVar34 = (float)uStack_210, (float)uStack_210 != 0.0 ||
                                            ((uStack_210._4_4_ != 0.0 || (fStack_208 != 0.0)))))))))
                                      ))) {
                                    fVar32 = (float)*param_2 - fVar34;
                                    fVar33 = (float)((ulonglong)*param_2 >> 0x20) - uStack_210._4_4_
                                    ;
                                    fVar32 = fVar33 * fVar33 + fVar32 * fVar32 +
                                             (*(float *)(param_2 + 1) - fStack_208) *
                                             (*(float *)(param_2 + 1) - fStack_208);
                                    if (fVar32 < 0.0) {
                                      fVar32 = (float)func_0x0001801cb525(fVar32);
                                    }
                                    else {
                                      fVar32 = SQRT(fVar32);
                                    }
                                    iVar18 = iStack_1d8;
                                    fVar33 = fStack_208;
                                    if ((fVar32 <= (float)iVar2) && (fVar11 <= fVar32)) {
                                      iStack_120 = iVar12;
                                      iStack_11c = iVar13;
                                      iStack_118 = iVar14;
                                      iStack_114 = iVar15;
                                      stack0xfffffffffffffed1 = SUB1615(ZEXT816(0),1);
                                      auVar9[15] = 0;
                                      auVar9._0_15_ = stack0xfffffffffffffed1;
                                      _auStack_130 = auVar9 << 8;
                                      iStack_140 = iStack_1d8;
                                      uVar6 = uStack_210._4_4_;
                                      uStack_13c = CONCAT44(uStack_210._4_4_,fVar34);
                                      fStack_134 = fStack_208;
                                      fStack_110 = fVar32;
                                      pauVar22 = (undefined (*) [16])
                                                 recovered_1800898f0(auStack_f8,iStack_1d8);
                                      if ((undefined (*) [16])auStack_130 == pauVar22) {
                                        uVar38 = auStack_130;
                                        uVar39 = uStack_12c;
                                        uVar40 = uStack_128;
                                        uVar41 = uStack_124;
                                        iVar19 = iVar12;
                                        iVar35 = iVar13;
                                        iVar36 = iVar14;
                                        iVar37 = iVar15;
                                      }
                                      else {
                                        uVar38 = *(undefined4 *)*pauVar22;
                                        uVar39 = *(undefined4 *)(*pauVar22 + 4);
                                        uVar40 = *(undefined4 *)(*pauVar22 + 8);
                                        uVar41 = *(undefined4 *)(*pauVar22 + 0xc);
                                        _auStack_130 = *pauVar22;
                                        iStack_120 = *(int *)pauVar22[1];
                                        iStack_11c = *(int *)(pauVar22[1] + 4);
                                        iStack_118 = *(int *)(pauVar22[1] + 8);
                                        iStack_114 = *(int *)(pauVar22[1] + 0xc);
                                        *(undefined8 *)pauVar22[1] = 0;
                                        *(undefined8 *)(pauVar22[1] + 8) = 0xf;
                                        (*pauVar22)[0] = 0;
                                        iVar19 = iStack_120;
                                        iVar35 = iStack_11c;
                                        iVar36 = iStack_118;
                                        iVar37 = iStack_114;
                                      }
                                      recovered_180066e40(auStack_f8);
                                      if ((int *)auStack_1f0._8_8_ == piStack_1e0) {
                                        recovered_18008d1e0(auStack_1f0,auStack_1f0._8_8_,
                                                            &iStack_140);
                                      }
                                      else {
                                        *(int *)auStack_1f0._8_8_ = iVar18;
                                        uStack_13c = CONCAT44(uVar6,fVar34);
                                        *(ulonglong *)(auStack_1f0._8_8_ + 4) =
                                             CONCAT44(uVar6,fVar34);
                                        *(float *)(auStack_1f0._8_8_ + 0xc) = fVar33;
                                        auVar5._4_4_ = uVar39;
                                        auVar5._0_4_ = uVar38;
                                        auVar5._8_4_ = uVar40;
                                        auVar5._12_4_ = uVar41;
                                        *(undefined (*) [16])(auStack_1f0._8_8_ + 0x10) = auVar5;
                                        *(int *)(auStack_1f0._8_8_ + 0x20) = iVar19;
                                        *(int *)(auStack_1f0._8_8_ + 0x24) = iVar35;
                                        *(int *)(auStack_1f0._8_8_ + 0x28) = iVar36;
                                        *(int *)(auStack_1f0._8_8_ + 0x2c) = iVar37;
                                        iStack_120 = iVar12;
                                        iStack_11c = iVar13;
                                        iStack_118 = iVar14;
                                        iStack_114 = iVar15;
                                        auVar10[15] = 0;
                                        auVar10._0_15_ = stack0xfffffffffffffed1;
                                        _auStack_130 = auVar10 << 8;
                                        *(float *)(auStack_1f0._8_8_ + 0x30) = fVar32;
                                        auStack_1f0._8_8_ = (int *)(auStack_1f0._8_8_ + 0x38);
                                      }
                                      recovered_180066e40(auStack_130);
                                    }
                                  }
                                }
                              }
                            }
                            iVar26 = iVar26 + 1;
                          } while (iVar26 < iStackX_18);
                        }
                      }
                    }
                  }
                }
                iVar17 = iVar17 + 1;
              } while (iVar17 < iStack_214);
            }
          }
        }
      }
      recovered_180066d80(&DAT_181b2bdd8);
      _DAT_181b2bdd8 = auStack_1f0._0_8_;
      _DAT_181b2bde0 = auStack_1f0._8_8_;
      _DAT_181b2bde8 = piStack_1e0;
      auStack_1f0 = ZEXT816(0);
      piStack_1e0 = (int *)0x0;
    }
    if (auStack_1f0._0_8_ != 0) {
      lVar30 = auStack_1f0._8_8_;
      lVar29 = auStack_1f0._0_8_;
      if (auStack_1f0._0_8_ != auStack_1f0._8_8_) {
        do {
          recovered_180066e40(lVar29 + 0x10);
          lVar29 = lVar29 + 0x38;
        } while (lVar29 != lVar30);
      }
      lVar30 = auStack_1f0._0_8_;
      if ((0xfff < (ulonglong)((((longlong)piStack_1e0 - auStack_1f0._0_8_) / 0x38) * 0x38)) &&
         (lVar30 = *(longlong *)(auStack_1f0._0_8_ + -8), 0x1f < (auStack_1f0._0_8_ - lVar30) - 8U))
      {
        _invoke_watson(0,0,0,0,0);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      func_0x000180127e40(lVar30);
    }
  }
  return;
}

