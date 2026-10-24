/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180081e00(short param_1,undefined8 param_2,float param_3,float param_4,float param_5,
                        undefined8 param_6,char param_7)

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
  float fVar16;
  float afStack_118 [4];
  float fStack_108;
  float fStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  
  lVar4 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar4 = func_0x00018000a880(**(undefined8 **)(lVar4 + 0x4908),0,&UNK_18020ed28);
  fVar15 = _DAT_181a03230;
  fVar8 = _DAT_181a031bc;
  if (lVar4 != 0) {
    fVar9 = (param_4 - _DAT_181a032a0) - _DAT_181a032a8;
    afStack_118[2] = 1.0;
    afStack_118[0] = 0.0;
    afStack_118[1] = (float)(int)param_1 / _DAT_181a033d8;
    pfVar6 = afStack_118;
    if (0.0 <= afStack_118[1]) {
      pfVar6 = afStack_118 + 1;
    }
    pfVar5 = afStack_118 + 2;
    if (afStack_118[1] <= _DAT_181a03230) {
      pfVar5 = pfVar6;
    }
    fVar10 = *pfVar5;
    if (param_7 == '\0') {
      fVar11 = fVar10 * param_5;
      fStack_108 = _DAT_181a03850;
      fStack_104 = (float)_UNK_181a03854;
      uStack_100 = _UNK_181a03858;
      uStack_fc = _UNK_181a0385c;
      fStack_d8 = _DAT_181a03840;
      uStack_d4 = _UNK_181a03844;
      uStack_d0 = _UNK_181a03848;
      uStack_cc = _UNK_181a0384c;
      fStack_e8 = _DAT_181a03860;
      uStack_e4 = _UNK_181a03864;
      uStack_e0 = _UNK_181a03868;
      uStack_dc = _UNK_181a0386c;
      if (fVar10 <= _DAT_181a031bc) {
        fVar16 = (_DAT_181a031bc - fVar10) + (_DAT_181a031bc - fVar10);
        fStack_f4 = _DAT_181a03230 - fVar16;
        fVar16 = fVar16 * 0.0;
        fStack_f8 = fVar16 + _DAT_181a03230;
        fStack_f0 = fVar16 + 0.0;
        fStack_ec = fStack_f8;
      }
      else {
        fVar14 = (_DAT_181a03230 - fVar10) + (_DAT_181a03230 - fVar10);
        fVar16 = fVar14 * 0.0;
        fStack_f8 = fVar14 + 0.0;
        fStack_f4 = fVar16 + _DAT_181a03230;
        fStack_ec = fStack_f4;
        fStack_f0 = fVar16 + 0.0;
      }
      if (fVar10 <= _DAT_181a031bc) {
        pfVar6 = &fStack_e8;
        if (fVar10 <= _DAT_181a03184) {
          pfVar6 = &fStack_d8;
        }
      }
      else {
        pfVar6 = &fStack_108;
      }
      fVar10 = *pfVar6;
      fVar16 = pfVar6[1];
      fVar14 = pfVar6[2];
    }
    else {
      fStack_f8 = _DAT_181b2b568;
      fStack_f4 = _DAT_181b2b56c;
      fStack_f0 = _DAT_181b2b570;
      fStack_ec = _DAT_181b2b574;
      fVar10 = _DAT_181b2b568;
      fVar11 = param_5;
      fVar14 = _DAT_181b2b570;
      fVar16 = _DAT_181b2b56c;
    }
    uVar3 = func_0x000180004f90(&fStack_f8);
    fVar2 = _DAT_181a0330c;
    fVar13 = _DAT_181a031f4;
    fVar1 = _DAT_181a03164;
    if (DAT_181b2bc70 == '\0') {
      fVar14 = fVar14 * _DAT_181a033ec;
      iVar7 = 8;
      fVar12 = fVar9 + _DAT_181a032a0;
      fVar10 = fVar10 * _DAT_181a033ec;
      fVar16 = fVar16 * _DAT_181a033ec;
      do {
        fVar8 = (float)iVar7;
        fStack_104 = fVar12 + fVar8;
        fStack_108 = fVar8 + fVar11 + param_3;
        fStack_f4 = fVar9 - fVar8;
        fStack_f8 = param_3 - fVar8;
        func_0x000180027d60(lVar4,&fStack_f8,&fStack_108,
                            (((int)((fVar15 - fVar8 * fVar1) * fVar2) << 8 | (int)fVar14) << 8 |
                            (int)fVar16) << 8 | (int)fVar10,fVar13,0);
        iVar7 = iVar7 + -1;
        fVar8 = _DAT_181a031bc;
      } while (0 < iVar7);
    }
    fStack_f8 = param_3 + param_5;
    fVar15 = fVar9 + _DAT_181a032a0;
    fStack_108 = param_3;
    fStack_104 = fVar9;
    fStack_f4 = fVar15;
    func_0x000180027c60(lVar4,&fStack_108,&fStack_f8,0xc8000000,fVar13,0xf0,_DAT_181a03248);
    if (0.0 < fVar11) {
      if (fVar11 < _DAT_181a03250) {
        fVar13 = fVar11 * fVar8;
      }
      fVar10 = fVar11 + param_3;
      fStack_108 = param_3;
      fStack_104 = fVar9;
      fStack_f8 = fVar10;
      fStack_f4 = fVar15;
      func_0x000180027d60(lVar4,&fStack_108,&fStack_f8,uVar3,fVar13,0xf0);
      if (fVar11 < param_5) {
        fStack_f8 = fVar10 + fVar8;
        fStack_108 = fVar10 - fVar8;
        fStack_104 = fVar9;
        fStack_f4 = fVar15;
        func_0x000180027d60(lVar4,&fStack_108,&fStack_f8,0xc8000000,0,0);
      }
    }
  }
  return;
}

