/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18008d390(void)

{
  uint uVar1;
  float fVar2;
  code *pcVar3;
  longlong lVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  float fVar10;
  float fVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  longlong lVar18;
  longlong **pplVar19;
  undefined8 uVar20;
  longlong **pplVar21;
  longlong **pplVar22;
  undefined *puVar23;
  int iVar24;
  ulonglong uVar25;
  ulonglong uVar26;
  undefined (*pauVar27) [16];
  longlong lVar28;
  ulonglong uVar29;
  uint *puVar30;
  undefined (*pauVar31) [16];
  float fVar32;
  float fVar33;
  float fVar34;
  float fStackX_20;
  float fStackX_24;
  undefined8 in_stack_fffffffffffffe18;
  undefined4 uVar35;
  undefined8 in_stack_fffffffffffffe20;
  undefined4 uVar36;
  undefined auStack_1c8 [16];
  undefined auStack_1b8 [16];
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  float fStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  float fStack_16c;
  char acStack_168 [296];
  
  lVar18 = _DAT_181b2f2c0;
  if ((DAT_181b2bdd0 != '\0') && (DAT_181b2bec4 != '\0')) {
    if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
      _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
    }
    lVar18 = func_0x00018000a880(**(undefined8 **)(lVar18 + 0x4908),0,&UNK_18020ed28);
    iVar14 = _DAT_181b2becc;
    uVar13 = _DAT_181b2bec8;
    puVar12 = _DAT_181b2bde0;
    fVar11 = _DAT_181a034a0;
    fVar10 = _DAT_181a0348c;
    uVar9 = _DAT_181a03460;
    fVar8 = _DAT_181a03354;
    fVar7 = _DAT_181a03230;
    fVar6 = _DAT_181a03228;
    fVar5 = _DAT_181a031bc;
    if (lVar18 != 0) {
      uVar29 = (ulonglong)_DAT_181b2bec8;
      iVar24 = 0;
      pplVar21 = (longlong **)*_DAT_181b2bdf8;
      if (pplVar21 != _DAT_181b2bdf8) {
        do {
          iVar15 = iVar24 + 1;
          if (*(char *)((longlong)pplVar21 + 0x14) == '\0') {
            iVar15 = iVar24;
          }
          iVar24 = iVar15;
          pplVar21 = (longlong **)*pplVar21;
        } while (pplVar21 != _DAT_181b2bdf8);
        if ((0 < iVar24) && (_DAT_181b2bdd8 != _DAT_181b2bde0)) {
          pauVar31 = (undefined (*) [16])(_DAT_181b2bdd8 + 4);
          pplVar21 = _DAT_181b2bdf8;
          puVar30 = _DAT_181b2bdd8;
          do {
            uVar26 = (ulonglong)*puVar30;
            if (*puVar30 != 0) {
              uVar16 = func_0x000180089860(uVar26);
              uVar25 = (((((ulonglong)(uVar16 & 0xff) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                         (ulonglong)(uVar16 >> 8 & 0xff)) * 0x100000001b3 ^
                        (ulonglong)(uVar16 >> 0x10) & 0xff) * 0x100000001b3 ^
                       (ulonglong)(uVar16 >> 0x18)) * 0x100000001b3 & _DAT_181b2be20;
              pplVar19 = *(longlong ***)(_DAT_181b2be08 + 8 + uVar25 * 0x10);
              if (pplVar19 == pplVar21) {
LAB_18008d5b3:
                pplVar19 = (longlong **)0x0;
              }
              else {
                uVar1 = *(uint *)(pplVar19 + 2);
                while (uVar16 != uVar1) {
                  if (pplVar19 == *(longlong ***)(_DAT_181b2be08 + uVar25 * 0x10))
                  goto LAB_18008d5b3;
                  pplVar19 = (longlong **)pplVar19[1];
                  uVar1 = *(uint *)(pplVar19 + 2);
                }
              }
              pplVar22 = pplVar21;
              if (pplVar19 != (longlong **)0x0) {
                pplVar22 = pplVar19;
              }
              if ((pplVar22 != pplVar21) && (*(char *)((longlong)pplVar22 + 0x14) != '\0')) {
                in_stack_fffffffffffffe18 =
                     CONCAT44((int)((ulonglong)in_stack_fffffffffffffe18 >> 0x20),iVar14);
                recovered_180067e80(&fStack_1a0,&DAT_181b2be70,(uint *)((longlong)pauVar31[-1] + 4))
                ;
                fVar34 = fStack_19c;
                fVar33 = fStack_1a0;
                uVar36 = (undefined4)((ulonglong)in_stack_fffffffffffffe20 >> 0x20);
                uVar35 = (undefined4)((ulonglong)in_stack_fffffffffffffe18 >> 0x20);
                if ((fVar11 <= fStack_1a0) &&
                   (((fVar11 <= fStack_19c && (fStack_1a0 <= (float)(int)uVar29 + fVar8)) &&
                    (fStack_19c <= (float)iVar14 + fVar8)))) {
                  recovered_180089b40(&uStack_188,uVar26 & 0xffffffff);
                  uStack_178 = uStack_188;
                  uStack_174 = uStack_184;
                  uStack_170 = uStack_180;
                  fStack_16c = fStack_17c * *(float *)(_DAT_181b2f2c0 + 0x37d0);
                  uVar17 = func_0x000180004f90(&uStack_178);
                  auStack_1c8 = ZEXT816(0);
                  auStack_1b8 = ZEXT816(0);
                  uVar29 = *(ulonglong *)pauVar31[1];
                  pauVar27 = pauVar31;
                  if (0xf < *(ulonglong *)((longlong)pauVar31[1] + 8)) {
                    pauVar27 = *(undefined (**) [16])*pauVar31;
                  }
                  if (0x7fffffffffffffff < uVar29) {
                    func_0x000180052a50();
                    pcVar3 = (code *)swi(3);
                    (*pcVar3)();
                    return;
                  }
                  if (uVar29 < 0x10) {
                    auStack_1b8._8_8_ = 0xf;
                    auStack_1b8._0_8_ = uVar29;
                    auStack_1c8 = *pauVar27;
                  }
                  else {
                    uVar26 = uVar29 | 0xf;
                    if (uVar26 < 0x8000000000000000) {
                      if (uVar26 < 0x16) {
                        uVar26 = 0x16;
                      }
                    }
                    else {
                      uVar26 = 0x7fffffffffffffff;
                    }
                    uVar20 = func_0x000180024110(uVar26 + 1);
                    auStack_1c8._0_8_ = uVar20;
                    auStack_1b8._8_8_ = uVar26;
                    auStack_1b8._0_8_ = uVar29;
                    func_0x0001801ca88d(uVar20,pauVar27,uVar29 + 1);
                  }
                  if (DAT_181b2bdd2 != '\0') {
                    pauVar27 = pauVar31;
                    if (0xf < *(ulonglong *)((longlong)pauVar31[1] + 8)) {
                      pauVar27 = *(undefined (**) [16])*pauVar31;
                    }
                    uVar20 = CONCAT44(uVar35,(int)*(float *)pauVar31[2]);
                    recovered_18006b2f0(acStack_168,0x80,&UNK_1819d89e0,pauVar27,uVar20);
                    uVar35 = (undefined4)((ulonglong)uVar20 >> 0x20);
                    lVar28 = -1;
                    do {
                      lVar4 = lVar28 + 1;
                      lVar28 = lVar28 + 1;
                    } while (acStack_168[lVar4] != '\0');
                    recovered_1800676d0(auStack_1c8,acStack_168);
                  }
                  puVar23 = auStack_1c8;
                  if (0xf < (ulonglong)auStack_1b8._8_8_) {
                    puVar23 = (undefined *)auStack_1c8._0_8_;
                  }
                  if (puVar23 == (undefined *)0x0) {
                    fVar2 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
                    fVar32 = 0.0;
                  }
                  else {
                    uVar20 = CONCAT44(uVar35,fVar10);
                    func_0x000180030a70(*(undefined8 *)(_DAT_181b2f2c0 + 0x3c30),&fStack_1a8,
                                        *(float *)(_DAT_181b2f2c0 + 0x3c38),uVar9,uVar20,puVar23,0);
                    uVar35 = (undefined4)((ulonglong)uVar20 >> 0x20);
                    uVar36 = (undefined4)((ulonglong)puVar23 >> 0x20);
                    fStack_1a8 = (float)(int)(fStack_1a8 + fVar6);
                    fVar2 = fStack_1a4;
                    fVar32 = fStack_1a8;
                  }
                  fStackX_24 = (fVar34 - fVar2) - _DAT_181a032a8;
                  fStackX_20 = fVar33 - fVar32 * fVar5;
                  fStack_198 = fStackX_20 - _DAT_181a032dc;
                  fStack_194 = fVar2 * fVar5 + fStackX_24;
                  in_stack_fffffffffffffe20 = CONCAT44(uVar36,9);
                  in_stack_fffffffffffffe18 = CONCAT44(uVar35,_DAT_181a032b8);
                  func_0x0001800272e0(lVar18,&fStack_198,_DAT_181a03298,0,in_stack_fffffffffffffe18,
                                      in_stack_fffffffffffffe20);
                  func_0x000180026810(lVar18,*(undefined8 *)(lVar18 + 0x80),
                                      *(undefined4 *)(lVar18 + 0x78),0xffffffff);
                  *(undefined4 *)(lVar18 + 0x78) = 0;
                  fVar33 = fVar10;
                  puVar23 = auStack_1c8;
                  fVar34 = fVar10;
                  if (0xf < (ulonglong)auStack_1b8._8_8_) {
                    puVar23 = (undefined *)auStack_1c8._0_8_;
                  }
                  do {
                    if ((fVar34 != 0.0) || (fVar33 != 0.0)) {
                      fStack_190 = fVar34 + fStackX_20;
                      fStack_18c = fVar33 + fStackX_24;
                      func_0x000180028900(lVar18,&fStack_190,0xdc000000,puVar23);
                    }
                    fVar33 = fVar33 + fVar7;
                  } while ((fVar33 <= fVar7) ||
                          (fVar34 = fVar34 + fVar7, fVar33 = fVar10, fVar34 <= fVar7));
                  func_0x000180028900(lVar18,&fStackX_20,uVar17,puVar23);
                  if (0xf < (ulonglong)auStack_1b8._8_8_) {
                    if ((0xfff < auStack_1b8._8_8_ + 1) &&
                       (0x1f < (auStack_1c8._0_8_ - *(longlong *)(auStack_1c8._0_8_ + -8)) - 8U)) {
                      _invoke_watson(0,0,0,0,0);
                      pcVar3 = (code *)swi(3);
                      (*pcVar3)();
                      return;
                    }
                    func_0x000180127e40();
                  }
                  uVar29 = (ulonglong)uVar13;
                  pplVar21 = _DAT_181b2bdf8;
                }
              }
            }
            puVar30 = puVar30 + 0xe;
            pauVar31 = (undefined (*) [16])((longlong)pauVar31[3] + 8);
          } while (puVar30 != puVar12);
        }
      }
    }
  }
  return;
}

