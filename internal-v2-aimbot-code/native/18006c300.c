/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x00018006d893) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006c300(uint param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  ulonglong uVar2;
  undefined auVar3 [12];
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined auVar7 [16];
  undefined auVar8 [16];
  undefined auVar9 [16];
  undefined auVar10 [16];
  undefined8 *puVar11;
  undefined4 *puVar12;
  undefined (*pauVar13) [16];
  undefined (*pauVar14) [16];
  undefined8 *******pppppppuVar15;
  uint uVar16;
  longlong lVar17;
  ulonglong uVar18;
  char *pcVar19;
  char *pcVar20;
  longlong lVar21;
  undefined *puVar22;
  undefined8 *******pppppppuVar23;
  undefined auStackX_18 [16];
  undefined auStack_1d8 [16];
  undefined auStack_1c8 [16];
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined auStack_198 [6];
  undefined auStack_192 [3];
  undefined auStack_18f [2];
  undefined5 uStack_18d;
  undefined8 uStack_188;
  ulonglong uStack_180;
  undefined8 *******apppppppuStack_178 [2];
  longlong lStack_168;
  ulonglong uStack_160;
  undefined8 *******apppppppuStack_158 [2];
  longlong lStack_148;
  ulonglong uStack_140;
  undefined8 *******apppppppuStack_138 [2];
  longlong lStack_128;
  ulonglong uStack_120;
  undefined (*pauStack_118) [16];
  longlong lStack_108;
  ulonglong uStack_100;
  undefined8 *******apppppppuStack_f8 [2];
  longlong lStack_e8;
  ulonglong uStack_e0;
  undefined8 *******apppppppuStack_d8 [2];
  longlong lStack_c8;
  ulonglong uStack_c0;
  undefined8 *******apppppppuStack_b8 [2];
  longlong lStack_a8;
  ulonglong uStack_a0;
  undefined8 *******apppppppuStack_98 [2];
  longlong lStack_88;
  ulonglong uStack_80;
  undefined auStack_78 [32];
  undefined auStack_58 [32];
  
  pauVar14 = (undefined (*) [16])&pauStack_118;
  param_3[2] = 0;
  puVar11 = param_3;
  if (0xf < (ulonglong)param_3[3]) {
    puVar11 = (undefined8 *)*param_3;
  }
  *(undefined *)puVar11 = 0;
  uStack_180 = 0xf;
  _auStack_192 = SUB1610(ZEXT816(0),6);
  auVar3._2_10_ = _auStack_192;
  auVar3._0_2_ = _DAT_18020e774;
  auStack_198 = (undefined  [6])(auVar3._0_6_ << 0x20);
  _auStack_198 = CONCAT16(DAT_18020e776,auStack_198);
  if ((int)param_1 < 0x514) {
    lVar21 = 6;
    uStack_188 = 6;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d782c,_DAT_1819d7828);
    _auStack_198 = ZEXT616((uint6)auStack_198);
    recovered_180078780(apppppppuStack_178,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_160 - lStack_168 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_178,3,lStack_168,0,&UNK_1819d7834,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_178;
      if (0xf < uStack_160) {
        pppppppuVar15 = apppppppuStack_178[0];
      }
      if ((&UNK_1819d7836 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_168) < &UNK_1819d7834)) {
        puVar22 = (undefined *)0x3;
      }
      else if (&UNK_1819d7834 < pppppppuVar15) {
        puVar22 = (undefined *)((longlong)pppppppuVar15 + -0x1819d7834);
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_168 + 1;
      lStack_168 = lStack_168 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7834,puVar22);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)puVar22),
                          &UNK_1819d7837 + (longlong)puVar22,3 - (longlong)puVar22);
      pauVar14 = (undefined (*) [16])apppppppuStack_178;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    recovered_180066e40(&uStack_1b8);
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar4[15] = 0;
    auVar4._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar4 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_178;
  }
  else if ((int)param_1 < 0x640) {
    lVar21 = 6;
    uStack_188 = 6;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d783c,_DAT_1819d7838);
    _auStack_198 = ZEXT616((uint6)auStack_198);
    recovered_180078780(apppppppuStack_158,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_140 - lStack_148 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_158,3,lStack_148,0,&UNK_1819d7840,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_158;
      if (0xf < uStack_140) {
        pppppppuVar15 = apppppppuStack_158[0];
      }
      if ((&UNK_1819d7842 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_148) < &UNK_1819d7840)) {
        pppppppuVar23 = (undefined8 *******)0x3;
      }
      else if (&UNK_1819d7840 < pppppppuVar15) {
        pppppppuVar23 = pppppppuVar15 + -0x3033af08;
      }
      else {
        pppppppuVar23 = (undefined8 *******)0x0;
      }
      lVar17 = lStack_148 + 1;
      lStack_148 = lStack_148 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7840,pppppppuVar23);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)pppppppuVar23),
                          &UNK_1819d7843 + (longlong)pppppppuVar23,3 - (longlong)pppppppuVar23);
      pauVar14 = (undefined (*) [16])apppppppuStack_158;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    recovered_180066e40(&uStack_1b8);
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar5[15] = 0;
    auVar5._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar5 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_158;
  }
  else if ((int)param_1 < 0x834) {
    lVar21 = 4;
    uStack_188 = 4;
    stack0xfffffffffffffe6d = ZEXT211((ushort)(_auStack_198 >> 0x28));
    auStack_198._0_5_ = 0x646c6f47;
    recovered_180078780(apppppppuStack_138,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_120 - lStack_128 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_138,3,lStack_128,0,&UNK_1819d7844,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_138;
      if (0xf < uStack_120) {
        pppppppuVar15 = apppppppuStack_138[0];
      }
      if ((&UNK_1819d7846 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_128) < &UNK_1819d7844)) {
        puVar22 = (undefined *)0x3;
      }
      else if (&UNK_1819d7844 < pppppppuVar15) {
        puVar22 = (undefined *)((longlong)pppppppuVar15 + -0x1819d7844);
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_128 + 1;
      lStack_128 = lStack_128 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7844,puVar22);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)puVar22),
                          &UNK_1819d7847 + (longlong)puVar22,3 - (longlong)puVar22);
      pauVar14 = (undefined (*) [16])apppppppuStack_138;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    recovered_180066e40(&uStack_1b8);
    recovered_180066e40(auStack_1d8);
    pauVar14 = (undefined (*) [16])apppppppuStack_138;
  }
  else if ((int)param_1 < 0xa28) {
    lVar21 = 8;
    uStack_188 = 8;
    _auStack_198 = (unkuint9)0x6d756e6974616c50;
    _auStack_18f = 0;
    recovered_180078780(pauVar14,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_100 - lStack_108 < 3) {
      pauVar13 = (undefined (*) [16])recovered_1800678e0(pauVar14,3,lStack_108,0,&UNK_1819d7848,3);
    }
    else {
      pauVar13 = pauVar14;
      if (0xf < uStack_100) {
        pauVar13 = pauStack_118;
      }
      if (((undefined (*) [16])&UNK_1819d784a < pauVar13) ||
         (*pauVar13 + lStack_108 < &UNK_1819d7848)) {
        puVar22 = (undefined *)0x3;
      }
      else if ((undefined (*) [16])&UNK_1819d7848 < pauVar13) {
        puVar22 = pauVar13[-0x1819d785] + 8;
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_108 + 1;
      lStack_108 = lStack_108 + 3;
      func_0x0001801ca893(*pauVar13 + 3,pauVar13,lVar17);
      func_0x0001801ca88d(pauVar13,&UNK_1819d7848,puVar22);
      func_0x0001801ca88d(puVar22 + (longlong)*pauVar13,puVar22 + 0x1819d784b,3 - (longlong)puVar22)
      ;
      pauVar13 = pauVar14;
    }
    auStack_1d8 = *pauVar13;
    auStack_1c8 = pauVar13[1];
    *(undefined8 *)pauVar13[1] = 0;
    *(undefined8 *)(pauVar13[1] + 8) = 0xf;
    (*pauVar13)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar6[15] = 0;
    auVar6._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar6 << 8;
  }
  else if ((int)param_1 < 0xc80) {
    lVar21 = 7;
    uStack_188 = 7;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d7854,_DAT_1819d7850);
    _auStack_198 = CONCAT16(DAT_1819d7856,auStack_198);
    _auStack_198 = ZEXT716(_auStack_198);
    recovered_180078780(apppppppuStack_f8,&uStack_1a4,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_e0 - lStack_e8 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_f8,3,lStack_e8,0,&UNK_1819d7858,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_f8;
      if (0xf < uStack_e0) {
        pppppppuVar15 = apppppppuStack_f8[0];
      }
      if ((&UNK_1819d785a < pppppppuVar15) ||
         ((undefined *)(lStack_e8 + (longlong)pppppppuVar15) < &UNK_1819d7858)) {
        pppppppuVar23 = (undefined8 *******)0x3;
      }
      else if (&UNK_1819d7858 < pppppppuVar15) {
        pppppppuVar23 = pppppppuVar15 + -0x3033af0b;
      }
      else {
        pppppppuVar23 = (undefined8 *******)0x0;
      }
      lVar17 = lStack_e8 + 1;
      lStack_e8 = lStack_e8 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7858,pppppppuVar23);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)pppppppuVar23),
                          &UNK_1819d785b + (longlong)pppppppuVar23,3 - (longlong)pppppppuVar23);
      pauVar14 = (undefined (*) [16])apppppppuStack_f8;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar7[15] = 0;
    auVar7._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar7 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_f8;
  }
  else if ((int)param_1 < 0x1194) {
    uVar16 = (int)(param_1 - 0xc80) / 0x104 + 1;
    lVar21 = 6;
    uStack_188 = 6;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d7860,_DAT_1819d785c);
    _auStack_198 = ZEXT616((uint6)auStack_198);
    if ((int)uVar16 < 1) {
      uVar18 = 1;
    }
    else {
      if (5 < (int)uVar16) {
        uVar16 = 5;
      }
      uVar18 = (ulonglong)uVar16;
    }
    pcVar20 = (char *)((longlong)&uStack_1a4 + 1);
    if ((int)uVar18 < 0) {
      uVar16 = -(int)uVar18;
      do {
        pcVar19 = pcVar20;
        pcVar20 = pcVar19 + -1;
        *pcVar20 = (char)uVar16 + (char)((ulonglong)uVar16 / 10) * -10 + '0';
        uVar16 = (uint)((ulonglong)uVar16 / 10);
      } while (uVar16 != 0);
      pcVar20 = pcVar19 + -2;
      *pcVar20 = '-';
    }
    else {
      do {
        pcVar20 = pcVar20 + -1;
        uVar2 = uVar18 / 10;
        *pcVar20 = (char)uVar18 + (char)uVar2 * -10 + '0';
        uVar18 = uVar2;
      } while ((int)uVar2 != 0);
    }
    recovered_180078780(apppppppuStack_d8,pcVar20,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_c0 - lStack_c8 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_d8,3,lStack_c8,0,&UNK_1819d7864,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_d8;
      if (0xf < uStack_c0) {
        pppppppuVar15 = apppppppuStack_d8[0];
      }
      if ((&UNK_1819d7866 < pppppppuVar15) ||
         ((undefined *)(lStack_c8 + (longlong)pppppppuVar15) < &UNK_1819d7864)) {
        puVar22 = (undefined *)0x3;
      }
      else if (&UNK_1819d7864 < pppppppuVar15) {
        puVar22 = (undefined *)((longlong)pppppppuVar15 + -0x1819d7864);
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_c8 + 1;
      lStack_c8 = lStack_c8 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7864,puVar22);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)puVar22),
                          &UNK_1819d7867 + (longlong)puVar22,3 - (longlong)puVar22);
      pauVar14 = (undefined (*) [16])apppppppuStack_d8;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar8[15] = 0;
    auVar8._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar8 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_d8;
  }
  else if ((int)param_1 < 6000) {
    uVar16 = (int)(param_1 - 0x1194) / 300 + 1;
    lVar21 = 6;
    uStack_188 = 6;
    auStack_198 = (undefined  [6])CONCAT24(_DAT_1819d786c,_DAT_1819d7868);
    _auStack_198 = ZEXT616((uint6)auStack_198);
    if ((int)uVar16 < 1) {
      uVar18 = 1;
    }
    else {
      if (5 < (int)uVar16) {
        uVar16 = 5;
      }
      uVar18 = (ulonglong)uVar16;
    }
    pcVar20 = (char *)((longlong)&uStack_1a4 + 1);
    if ((int)uVar18 < 0) {
      uVar16 = -(int)uVar18;
      do {
        pcVar19 = pcVar20;
        pcVar20 = pcVar19 + -1;
        *pcVar20 = (char)uVar16 + (char)((ulonglong)uVar16 / 10) * -10 + '0';
        uVar16 = (uint)((ulonglong)uVar16 / 10);
      } while (uVar16 != 0);
      pcVar20 = pcVar19 + -2;
      *pcVar20 = '-';
    }
    else {
      do {
        pcVar20 = pcVar20 + -1;
        uVar2 = uVar18 / 10;
        *pcVar20 = (char)uVar18 + (char)uVar2 * -10 + '0';
        uVar18 = uVar2;
      } while ((int)uVar2 != 0);
    }
    recovered_180078780(apppppppuStack_b8,pcVar20,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_a0 - lStack_a8 < 3) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_b8,3,lStack_a8,0,&UNK_1819d7870,3);
    }
    else {
      pppppppuVar15 = apppppppuStack_b8;
      if (0xf < uStack_a0) {
        pppppppuVar15 = apppppppuStack_b8[0];
      }
      if ((&UNK_1819d7872 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_a8) < &UNK_1819d7870)) {
        pppppppuVar23 = (undefined8 *******)0x3;
      }
      else if (&UNK_1819d7870 < pppppppuVar15) {
        pppppppuVar23 = pppppppuVar15 + -0x3033af0e;
      }
      else {
        pppppppuVar23 = (undefined8 *******)0x0;
      }
      lVar17 = lStack_a8 + 1;
      lStack_a8 = lStack_a8 + 3;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 3),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7870,pppppppuVar23);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)pppppppuVar23),
                          &UNK_1819d7873 + (longlong)pppppppuVar23,3 - (longlong)pppppppuVar23);
      pauVar14 = (undefined (*) [16])apppppppuStack_b8;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar9[15] = 0;
    auVar9._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar9 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_b8;
  }
  else {
    uVar16 = (int)(param_1 - 6000) / 800 + 1;
    lVar21 = 0xb;
    uStack_188 = 0xb;
    stack0xfffffffffffffe70 = _DAT_1819d7880;
    _auStack_198 = _DAT_1819d7878;
    auStack_18f[1] = DAT_1819d7882;
    uStack_18d = 0;
    if ((int)uVar16 < 1) {
      uVar18 = 1;
    }
    else {
      uVar18 = (ulonglong)uVar16;
      if (6 < (int)uVar16) {
        uVar18 = 6;
      }
    }
    pcVar20 = (char *)((longlong)&uStack_1a4 + 1);
    if ((int)uVar18 < 0) {
      uVar16 = -(int)uVar18;
      do {
        pcVar19 = pcVar20;
        pcVar20 = pcVar19 + -1;
        *pcVar20 = (char)uVar16 + (char)((ulonglong)uVar16 / 10) * -10 + '0';
        uVar16 = (uint)((ulonglong)uVar16 / 10);
      } while (uVar16 != 0);
      pcVar20 = pcVar19 + -2;
      *pcVar20 = '-';
    }
    else {
      do {
        pcVar20 = pcVar20 + -1;
        uVar2 = uVar18 / 10;
        *pcVar20 = (char)uVar18 + (char)uVar2 * -10 + '0';
        uVar18 = uVar2;
      } while ((int)uVar2 != 0);
    }
    recovered_180078780(apppppppuStack_98,pcVar20,(longlong)&uStack_1a4 + 1,auStackX_18);
    if (uStack_80 - lStack_88 < 4) {
      pauVar14 = (undefined (*) [16])
                 recovered_1800678e0(apppppppuStack_98,4,lStack_88,0,&UNK_1819d7884,4);
    }
    else {
      pppppppuVar15 = apppppppuStack_98;
      if (0xf < uStack_80) {
        pppppppuVar15 = apppppppuStack_98[0];
      }
      if ((&UNK_1819d7887 < pppppppuVar15) ||
         ((undefined *)((longlong)pppppppuVar15 + lStack_88) < &UNK_1819d7884)) {
        puVar22 = (undefined *)0x4;
      }
      else if (&UNK_1819d7884 < pppppppuVar15) {
        puVar22 = (undefined *)((longlong)pppppppuVar15 + -0x1819d7884);
      }
      else {
        puVar22 = (undefined *)0x0;
      }
      lVar17 = lStack_88 + 1;
      lStack_88 = lStack_88 + 4;
      func_0x0001801ca893((undefined *)((longlong)pppppppuVar15 + 4),pppppppuVar15,lVar17);
      func_0x0001801ca88d(pppppppuVar15,&UNK_1819d7884,puVar22);
      func_0x0001801ca88d((undefined *)((longlong)pppppppuVar15 + (longlong)puVar22),
                          &UNK_1819d7888 + (longlong)puVar22,4 - (longlong)puVar22);
      pauVar14 = (undefined (*) [16])apppppppuStack_98;
    }
    auStack_1d8 = *pauVar14;
    auStack_1c8 = pauVar14[1];
    *(undefined8 *)pauVar14[1] = 0;
    *(undefined8 *)(pauVar14[1] + 8) = 0xf;
    (*pauVar14)[0] = 0;
    puVar12 = (undefined4 *)recovered_180066ec0(auStack_1d8,&UNK_1819d7830,1);
    uStack_1b8 = *puVar12;
    uStack_1b4 = puVar12[1];
    uStack_1b0 = puVar12[2];
    uStack_1ac = puVar12[3];
    uStack_1a8 = puVar12[4];
    uStack_1a4 = puVar12[5];
    uStack_1a0 = puVar12[6];
    uStack_19c = puVar12[7];
    *(undefined8 *)(puVar12 + 4) = 0;
    *(undefined8 *)(puVar12 + 6) = 0xf;
    *(undefined *)puVar12 = 0;
    recovered_1800785e0(param_3,&uStack_1b8);
    if (0xf < CONCAT44(uStack_19c,uStack_1a0)) {
      if ((0xfff < CONCAT44(uStack_19c,uStack_1a0) + 1) &&
         (0x1f < (CONCAT44(uStack_1b4,uStack_1b8) -
                 *(longlong *)(CONCAT44(uStack_1b4,uStack_1b8) + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_1c8._8_8_) {
      if ((0xfff < auStack_1c8._8_8_ + 1) &&
         (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40();
    }
    auStack_1c8._8_8_ = _UNK_181a03538;
    auStack_1c8._0_8_ = _DAT_181a03530;
    auVar10[15] = 0;
    auVar10._0_15_ = auStack_1d8._1_15_;
    auStack_1d8 = auVar10 << 8;
    pauVar14 = (undefined (*) [16])apppppppuStack_98;
  }
  recovered_180066e40(pauVar14);
  pcVar20 = (char *)((longlong)&uStack_1a4 + 1);
  uVar18 = (ulonglong)param_1;
  if ((int)param_1 < 0) {
    param_1 = -param_1;
    do {
      pcVar19 = pcVar20;
      pcVar20 = pcVar19 + -1;
      *pcVar20 = (char)param_1 + (char)((ulonglong)param_1 / 10) * -10 + '0';
      param_1 = (uint)((ulonglong)param_1 / 10);
    } while (param_1 != 0);
    pcVar20 = pcVar19 + -2;
    *pcVar20 = '-';
  }
  else {
    do {
      pcVar20 = pcVar20 + -1;
      uVar2 = uVar18 / 10;
      *pcVar20 = (char)uVar18 + (char)uVar2 * -10 + '0';
      uVar18 = uVar2;
    } while ((int)uVar2 != 0);
  }
  recovered_180078780(auStack_58,pcVar20,(longlong)&uStack_1a4 + 1,auStackX_18);
  if (0x7fffffffffffffffU - lVar21 < 2) {
    func_0x000180052a50();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  recovered_180067040(&uStack_1b8,auStackX_18[0],auStack_198,auStack_198,lVar21,&UNK_1819d788c,2);
  recovered_180079c40(auStack_78,auStackX_18[0],&uStack_1b8,auStack_58);
  pauVar14 = (undefined (*) [16])recovered_180066ec0(auStack_78,&UNK_1819d7830,1);
  auStack_1d8 = *pauVar14;
  auStack_1c8 = pauVar14[1];
  *(undefined8 *)pauVar14[1] = 0;
  *(undefined8 *)(pauVar14[1] + 8) = 0xf;
  (*pauVar14)[0] = 0;
  recovered_1800785e0(param_2,auStack_1d8);
  if (0xf < (ulonglong)auStack_1c8._8_8_) {
    if ((0xfff < auStack_1c8._8_8_ + 1) &&
       (0x1f < (auStack_1d8._0_8_ - *(longlong *)(auStack_1d8._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  recovered_180066e40(auStack_78);
  recovered_180066e40(&uStack_1b8);
  recovered_180066e40(auStack_58);
  if (0xf < uStack_180) {
    if ((0xfff < uStack_180 + 1) && (0x1f < (_auStack_198 - *(longlong *)(_auStack_198 + -8)) - 8U))
    {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  return;
}

