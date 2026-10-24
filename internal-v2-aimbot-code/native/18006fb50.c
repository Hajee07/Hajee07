/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006fb50(longlong param_1,float param_2,float param_3,char param_4)

{
  longlong lVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  float fVar6;
  longlong lVar7;
  int iVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 *puVar11;
  float *pfVar12;
  longlong lVar13;
  int iVar14;
  undefined8 *puVar15;
  undefined *puVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  undefined4 uVar23;
  undefined8 uStackX_8;
  float fStackX_10;
  float fStackX_18;
  undefined4 uStackX_20;
  char acStack_1f8 [8];
  float fStack_1f0;
  float fStack_1ec;
  float fStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  float fStack_1dc;
  undefined4 uStack_1d8;
  float fStack_1d4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float afStack_1a0 [2];
  undefined auStack_198 [16];
  undefined auStack_188 [16];
  undefined auStack_178 [16];
  undefined auStack_168 [16];
  float fStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  float fStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  
  lVar10 = _DAT_181b2f2c0;
  if (param_4 == '\0') {
    return;
  }
  if (DAT_181b302f8 == '\0') {
    return;
  }
  if (_DAT_181b302fc == 0) {
    return;
  }
  uStackX_8 = param_1;
  fStackX_18 = param_3;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar10 = func_0x00018000a880(**(undefined8 **)(lVar10 + 0x4908),1,&UNK_18020ed38);
  if (lVar10 == 0) {
    return;
  }
  if (DAT_181b302f8 == '\0') {
    iVar14 = 0xb4;
  }
  else {
    if (DAT_181b302f9 == '\0') {
      recovered_180067b80(&uStackX_8);
      iVar8 = 0xb4 - (int)((uStackX_8 - _DAT_181b30300) / 1000000000);
      iVar14 = 0;
      if (-1 < iVar8) {
        iVar14 = iVar8;
      }
      if (iVar14 != 0) goto LAB_18006fc63;
    }
    else {
      iVar14 = 0;
    }
    DAT_181b302f9 = '\x01';
  }
LAB_18006fc63:
  auStack_198 = ZEXT816(0);
  auStack_188 = auStack_198;
  auStack_178 = auStack_198;
  auStack_168 = auStack_198;
  if (DAT_181b302f9 == '\0') {
    recovered_18006b2f0(auStack_198,0x40,&UNK_1819d7898,iVar14 / 0x3c,iVar14 % 0x3c);
  }
  else {
    recovered_18006b2f0(auStack_198,0x40,&UNK_1819d78a0);
  }
  uVar23 = _DAT_181a0348c;
  lVar1 = *(longlong *)(_DAT_181b2f2c0 + 0x3c30);
  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 0x40) != 0)) {
    fVar21 = *(float *)(lVar1 + 0x14) * _DAT_181a03240;
    func_0x000180030a70(lVar1,&uStackX_8,fVar21,_DAT_181a03460,_DAT_181a0348c,auStack_198,0);
    fVar4 = _DAT_181a03230;
    fVar18 = _DAT_181a031bc;
    fVar6 = (float)uStackX_8;
    fVar22 = param_2 * _DAT_181a031bc - (float)uStackX_8 * _DAT_181a031bc;
    fStack_148 = _DAT_181a03920;
    uStack_144 = _UNK_181a03924;
    uStack_140 = _UNK_181a03928;
    uStack_13c = _UNK_181a0392c;
    fStack_158 = _DAT_181a03940;
    uStack_154 = _UNK_181a03944;
    uStack_150 = _UNK_181a03948;
    uStack_14c = _UNK_181a0394c;
    fStackX_10 = fVar22;
    uStack_1e4 = func_0x0001801cb4f5((float)*(double *)(_DAT_181b2f2c0 + 0x3e60) * _DAT_181a0320c);
    uStack_1e0 = func_0x0001801cb4f5();
    puVar16 = auStack_198;
    if (auStack_198[0] != '\0') {
      fStack_1e8 = fVar6;
      if (fVar6 <= fVar4) {
        fStack_1e8 = fVar4;
      }
      uStackX_8 = CONCAT44(uStackX_8._4_4_,0x3f800000);
      uStackX_20 = 0;
      acStack_1f8[0] = auStack_198[0];
      do {
        acStack_1f8[1] = 0;
        func_0x000180030a70(lVar1,afStack_1a0,fVar21,_DAT_181a03460,uVar23,acStack_1f8,
                            acStack_1f8 + 1);
        fVar6 = afStack_1a0[0];
        cVar5 = DAT_181b302f9;
        fVar17 = (float)func_0x0001801cb4f5();
        fVar18 = (float)((uint)(fVar17 - fVar18) & _DAT_181a039d0);
        fStackX_18 = fVar4 - (fVar18 + fVar18);
        puVar15 = (undefined8 *)&uStackX_20;
        if (0.0 <= fStackX_18) {
          puVar15 = (undefined8 *)&fStackX_18;
        }
        puVar11 = &uStackX_8;
        if (fStackX_18 <= fVar4) {
          puVar11 = puVar15;
        }
        pfVar12 = &fStack_158;
        if (cVar5 == '\0') {
          pfVar12 = &fStack_148;
        }
        fVar18 = *pfVar12;
        fVar17 = pfVar12[1];
        fVar2 = pfVar12[2];
        fVar3 = pfVar12[3];
        fVar19 = _DAT_181a031f8;
        if (cVar5 != '\0') {
          fVar19 = _DAT_181a03214;
        }
        fVar19 = *(float *)puVar11 * fVar19;
        uVar23 = 0xdc000000;
        if (cVar5 != '\0') {
          uVar23 = 0xaa000000;
        }
        fStack_1ec = _DAT_181a03398;
        fStack_1f0 = fVar22;
        if (cVar5 != '\0') {
          uStack_1d8 = 0x42b80000;
          fStack_1dc = fVar22 - fVar4;
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar20 = fVar21;
            if (fVar21 == 0.0) {
              fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_138 = *(undefined4 *)(lVar10 + 0x88);
            uStack_134 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_130 = *(undefined4 *)(lVar10 + 0x90);
            uStack_12c = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1dc,uVar23,&uStack_138,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
          fStack_1d0 = fStack_1ec;
          fStack_1d4 = fStack_1f0 + fVar4;
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar20 = fVar21;
            if (fVar21 == 0.0) {
              fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_128 = *(undefined4 *)(lVar10 + 0x88);
            uStack_124 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_120 = *(undefined4 *)(lVar10 + 0x90);
            uStack_11c = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1d4,uVar23,&uStack_128,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
          fStack_1cc = fStack_1f0;
          fStack_1c8 = fStack_1ec - fVar4;
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar20 = fVar21;
            if (fVar21 == 0.0) {
              fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_118 = *(undefined4 *)(lVar10 + 0x88);
            uStack_114 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_110 = *(undefined4 *)(lVar10 + 0x90);
            uStack_10c = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1cc,uVar23,&uStack_118,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
          fStack_1c4 = fStack_1f0;
          fStack_1c0 = fStack_1ec + fVar4;
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar20 = fVar21;
            if (fVar21 == 0.0) {
              fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_108 = *(undefined4 *)(lVar10 + 0x88);
            uStack_104 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_100 = *(undefined4 *)(lVar10 + 0x90);
            uStack_fc = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1c4,uVar23,&uStack_108,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
        }
        fStack_1bc = fStack_1f0 + fVar4;
        fStack_1b8 = fStack_1ec + fVar4;
        lVar7 = -1;
        do {
          lVar13 = lVar7;
          lVar7 = lVar13 + 1;
        } while (acStack_1f8[lVar13 + 1] != '\0');
        if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
          fVar20 = fVar21;
          if (fVar21 == 0.0) {
            fVar20 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
          }
          if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
            _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
          }
          uStack_f8 = *(undefined4 *)(lVar10 + 0x88);
          uStack_f4 = *(undefined4 *)(lVar10 + 0x8c);
          uStack_f0 = *(undefined4 *)(lVar10 + 0x90);
          uStack_ec = *(undefined4 *)(lVar10 + 0x94);
          func_0x000180030c90(lVar1,lVar10,fVar20,&fStack_1bc,uVar23,&uStack_f8,acStack_1f8,
                              acStack_1f8 + lVar13 + 1,0,0);
        }
        fStack_1a4 = ((fVar4 - fVar3) * fVar19 + fVar3) * *(float *)(_DAT_181b2f2c0 + 0x37d0);
        fStack_1b0 = (fVar4 - fVar18) * fVar19 + fVar18;
        fStack_1ac = (fVar4 - fVar17) * fVar19 + fVar17;
        fStack_1a8 = (fVar4 - fVar2) * fVar19 + fVar2;
        uVar9 = func_0x000180004f90(&fStack_1b0);
        if ((uVar9 & 0xff000000) != 0) {
          lVar7 = -1;
          do {
            lVar13 = lVar7;
            lVar7 = lVar13 + 1;
          } while (acStack_1f8[lVar13 + 1] != '\0');
          if (acStack_1f8 != acStack_1f8 + lVar13 + 1) {
            fVar18 = fVar21;
            if (fVar21 == 0.0) {
              fVar18 = *(float *)(*(longlong *)(lVar10 + 0x38) + 0x10);
            }
            if (*(longlong *)(*(longlong *)(lVar1 + 0x40) + 8) != *(longlong *)(lVar10 + 0x98)) {
              _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
            }
            uStack_e8 = *(undefined4 *)(lVar10 + 0x88);
            uStack_e4 = *(undefined4 *)(lVar10 + 0x8c);
            uStack_e0 = *(undefined4 *)(lVar10 + 0x90);
            uStack_dc = *(undefined4 *)(lVar10 + 0x94);
            func_0x000180030c90(lVar1,lVar10,fVar18,&fStack_1f0,uVar9,&uStack_e8,acStack_1f8,
                                acStack_1f8 + lVar13 + 1,0,0);
          }
        }
        acStack_1f8[0] = puVar16[1];
        fVar22 = fVar22 + fVar6;
        puVar16 = puVar16 + 1;
        fVar18 = _DAT_181a031bc;
        uVar23 = _DAT_181a0348c;
      } while (acStack_1f8[0] != '\0');
    }
  }
  return;
}

