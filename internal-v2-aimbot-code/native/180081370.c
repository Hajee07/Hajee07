/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180081370(short param_1,undefined8 param_2,undefined8 param_3,float param_4,
                        char param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  longlong lVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  undefined8 uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined8 uStack_108;
  float afStack_100 [4];
  float fStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  
  lVar5 = _DAT_181b2f2c0;
  uStack_108 = param_3;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar5 = func_0x00018000a880(**(undefined8 **)(lVar5 + 0x4908),0,&UNK_18020ed28);
  fVar1 = _DAT_181a03230;
  if (lVar5 != 0) {
    afStack_100[2] = 1.0;
    afStack_100[0] = 0.0;
    afStack_100[1] = (float)(int)param_1 / _DAT_181a033d8;
    pfVar7 = afStack_100;
    if (0.0 <= afStack_100[1]) {
      pfVar7 = afStack_100 + 1;
    }
    pfVar6 = afStack_100 + 2;
    if (afStack_100[1] <= _DAT_181a03230) {
      pfVar6 = pfVar7;
    }
    fVar13 = *pfVar6;
    fVar16 = fVar13 * param_4;
    if (param_5 == '\0') {
      fStack_118 = _DAT_181a03850;
      fStack_114 = (float)_UNK_181a03854;
      uStack_110 = _UNK_181a03858;
      uStack_10c = _UNK_181a0385c;
      fStack_e0 = _DAT_181a03840;
      uStack_dc = _UNK_181a03844;
      uStack_d8 = _UNK_181a03848;
      uStack_d4 = _UNK_181a0384c;
      fStack_f0 = _DAT_181a03860;
      uStack_ec = _UNK_181a03864;
      uStack_e8 = _UNK_181a03868;
      uStack_e4 = _UNK_181a0386c;
      if (fVar13 <= _DAT_181a031bc) {
        fStack_120 = (_DAT_181a031bc - fVar13) + (_DAT_181a031bc - fVar13);
        fStack_124 = _DAT_181a03230 - fStack_120;
        fStack_120 = fStack_120 * 0.0;
        fStack_128 = fStack_120 + _DAT_181a03230;
        fStack_11c = fStack_128;
      }
      else {
        fStack_120 = (_DAT_181a03230 - fVar13) + (_DAT_181a03230 - fVar13);
        fStack_128 = fStack_120 + 0.0;
        fStack_120 = fStack_120 * 0.0;
        fStack_124 = fStack_120 + _DAT_181a03230;
        fStack_11c = fStack_124;
      }
      fStack_120 = fStack_120 + 0.0;
      if (fVar13 <= _DAT_181a031bc) {
        pfVar7 = &fStack_f0;
        if (fVar13 <= _DAT_181a03184) {
          pfVar7 = &fStack_e0;
        }
      }
      else {
        pfVar7 = &fStack_118;
      }
      fVar13 = *pfVar7;
      fVar15 = pfVar7[1];
      fVar14 = pfVar7[2];
    }
    else {
      fStack_128 = _DAT_181b2b568;
      fStack_124 = _DAT_181b2b56c;
      fStack_120 = _DAT_181b2b570;
      fStack_11c = _DAT_181b2b574;
      fVar13 = _DAT_181b2b568;
      fVar14 = _DAT_181b2b570;
      fVar15 = _DAT_181b2b56c;
    }
    uVar4 = func_0x000180004f90(&fStack_128);
    fVar3 = (float)uStack_108;
    fVar12 = uStack_108._4_4_;
    fVar17 = (float)uStack_108 + _DAT_181a03284;
    fVar10 = uStack_108._4_4_ + param_4;
    fStack_128 = (float)uStack_108;
    fStack_124 = uStack_108._4_4_;
    uVar9 = 0x80000000;
    if (param_5 != '\0') {
      uVar9 = 0xb4000050;
    }
    fStack_118 = fVar17;
    fStack_114 = fVar10;
    func_0x000180027d60(lVar5,&fStack_128,&fStack_118,uVar9,0,0);
    fVar2 = _DAT_181a032ec;
    fStack_118 = fVar3;
    if (DAT_181b2bc70 == '\0') {
      fVar14 = fVar14 * _DAT_181a033ec;
      iVar8 = 10;
      fVar15 = fVar15 * _DAT_181a033ec;
      fVar13 = fVar13 * _DAT_181a033ec;
      fVar3 = (float)uStack_108;
      do {
        fVar11 = (float)iVar8;
        fStack_128 = fVar11 + fVar17;
        fStack_124 = fVar11 + fVar10;
        fStack_118 = fVar3 - fVar11;
        fStack_114 = ((param_4 - fVar16) + fVar12) - fVar11;
        func_0x000180027d60(lVar5,&fStack_118,&fStack_128,
                            (((int)((fVar1 - fVar11 / fVar2) * _DAT_181a0330c) << 8 | (int)fVar14)
                             << 8 | (int)fVar15) << 8 | (int)fVar13,0,0);
        iVar8 = iVar8 + -1;
      } while (0 < iVar8);
      fStack_118 = (float)uStack_108;
    }
    if (param_5 == '\0') {
      fVar12 = (param_4 - fVar16) + fVar12;
      param_4 = fVar16;
    }
    fStack_124 = param_4 + fVar12;
    fStack_128 = fVar17;
    fStack_114 = fVar12;
    func_0x000180027d60(lVar5,&fStack_118,&fStack_128,uVar4,0,0);
  }
  return;
}

