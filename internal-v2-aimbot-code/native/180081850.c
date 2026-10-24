/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180081850(short param_1,undefined8 param_2,float param_3,float param_4,float param_5,
                        float param_6,char param_7)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  longlong lVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStackX_10;
  float afStack_128 [4];
  float fStack_118;
  float fStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  
  lVar4 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar4 = func_0x00018000a880(**(undefined8 **)(lVar4 + 0x4908),0,&UNK_18020ed28);
  fVar10 = _DAT_181a03230;
  fVar8 = _DAT_181a031bc;
  if (lVar4 != 0) {
    afStack_128[2] = 1.0;
    afStack_128[0] = 0.0;
    afStack_128[1] = (float)(int)param_1 / _DAT_181a033d8;
    pfVar6 = afStack_128;
    if (0.0 <= afStack_128[1]) {
      pfVar6 = afStack_128 + 1;
    }
    pfVar5 = afStack_128 + 2;
    if (afStack_128[1] <= _DAT_181a03230) {
      pfVar5 = pfVar6;
    }
    fVar9 = *pfVar5;
    if (param_7 == '\0') {
      fStackX_10 = fVar9 * param_5;
      fStack_118 = _DAT_181a03850;
      fStack_114 = (float)_UNK_181a03854;
      uStack_110 = _UNK_181a03858;
      uStack_10c = _UNK_181a0385c;
      fStack_f8 = _DAT_181a03860;
      uStack_f4 = _UNK_181a03864;
      uStack_f0 = _UNK_181a03868;
      uStack_ec = _UNK_181a0386c;
      fStack_e8 = _DAT_181a03840;
      uStack_e4 = _UNK_181a03844;
      uStack_e0 = _UNK_181a03848;
      uStack_dc = _UNK_181a0384c;
      if (fVar9 <= _DAT_181a031bc) {
        fVar14 = (_DAT_181a031bc - fVar9) + (_DAT_181a031bc - fVar9);
        fStack_104 = _DAT_181a03230 - fVar14;
        fVar14 = fVar14 * 0.0;
        fStack_108 = fVar14 + _DAT_181a03230;
        fStack_100 = fVar14 + 0.0;
        fStack_fc = fStack_108;
      }
      else {
        fVar13 = (_DAT_181a03230 - fVar9) + (_DAT_181a03230 - fVar9);
        fVar14 = fVar13 * 0.0;
        fStack_108 = fVar13 + 0.0;
        fStack_104 = fVar14 + _DAT_181a03230;
        fStack_fc = fStack_104;
        fStack_100 = fVar14 + 0.0;
      }
      if (fVar9 <= _DAT_181a031bc) {
        pfVar6 = &fStack_f8;
        if (fVar9 <= _DAT_181a03184) {
          pfVar6 = &fStack_e8;
        }
      }
      else {
        pfVar6 = &fStack_118;
      }
      fVar9 = *pfVar6;
      fVar14 = pfVar6[1];
      fVar13 = pfVar6[2];
    }
    else {
      fStackX_10 = param_5;
      fStack_108 = _DAT_181b2b568;
      fStack_104 = _DAT_181b2b56c;
      fStack_100 = _DAT_181b2b570;
      fStack_fc = _DAT_181b2b574;
      fVar9 = _DAT_181b2b568;
      fVar13 = _DAT_181b2b570;
      fVar14 = _DAT_181b2b56c;
    }
    uVar3 = func_0x000180004f90(&fStack_108);
    fVar2 = _DAT_181a0330c;
    fVar12 = _DAT_181a031f4;
    fVar1 = _DAT_181a03164;
    if (DAT_181b2bc70 == '\0') {
      fVar13 = fVar13 * _DAT_181a033ec;
      iVar7 = 8;
      fVar9 = fVar9 * _DAT_181a033ec;
      fVar15 = param_4 + param_6 + _DAT_181a032a0;
      fVar14 = fVar14 * _DAT_181a033ec;
      fVar11 = fVar15 + _DAT_181a032a0;
      do {
        fVar8 = (float)iVar7;
        fStack_114 = fVar11 + fVar8;
        fStack_118 = fVar8 + fStackX_10 + param_3;
        fStack_104 = fVar15 - fVar8;
        fStack_108 = param_3 - fVar8;
        func_0x000180027d60(lVar4,&fStack_108,&fStack_118,
                            (((int)((fVar10 - fVar8 * fVar1) * fVar2) << 8 | (int)fVar13) << 8 |
                            (int)fVar14) << 8 | (int)fVar9,fVar12,0);
        iVar7 = iVar7 + -1;
        fVar8 = _DAT_181a031bc;
      } while (0 < iVar7);
    }
    fVar10 = param_4 + param_6 + _DAT_181a032a0;
    fStack_108 = param_3 + param_5;
    fVar9 = fVar10 + _DAT_181a032a0;
    fStack_118 = param_3;
    fStack_114 = fVar10;
    fStack_104 = fVar9;
    func_0x000180027c60(lVar4,&fStack_118,&fStack_108,0xc8000000,fVar12,0xf0,_DAT_181a03248);
    if (0.0 < fStackX_10) {
      if (fStackX_10 < _DAT_181a03250) {
        fVar12 = fStackX_10 * fVar8;
      }
      fVar14 = fStackX_10 + param_3;
      fStack_118 = param_3;
      fStack_114 = fVar10;
      fStack_108 = fVar14;
      fStack_104 = fVar9;
      func_0x000180027d60(lVar4,&fStack_118,&fStack_108,uVar3,fVar12,0xf0);
      if (fStackX_10 < param_5) {
        fStack_108 = fVar14 + fVar8;
        fStack_118 = fVar14 - fVar8;
        fStack_114 = fVar10;
        fStack_104 = fVar9;
        func_0x000180027d60(lVar4,&fStack_118,&fStack_108,0xc8000000,0,0);
      }
    }
  }
  return;
}

