/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180080a40(float param_1,float param_2,float param_3,float param_4,undefined8 *param_5
                        ,undefined4 param_6,float param_7,undefined8 param_8,char param_9,
                        char param_10)

{
  undefined4 uVar1;
  longlong lVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  float fStack_15c;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  float fStack_148;
  undefined8 uStack_140;
  undefined4 uStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  
  lVar2 = _DAT_181b2f2c0;
  if (*(int *)(_DAT_181b2f2c0 + 0x4900) < 1) {
    _wassert(&UNK_180213478,&UNK_18020d8d0,0x742);
  }
  lVar2 = func_0x00018000a880(**(undefined8 **)(lVar2 + 0x4908),0,&UNK_18020ed28);
  if (lVar2 != 0) {
    fVar4 = param_4 * _DAT_181a03184;
    fVar9 = param_3 * _DAT_181a03184;
    fStack_150 = fVar4;
    if (DAT_181b2bc70 == '\0') {
      fStack_160 = fVar9;
      if ((param_9 != '\0') && (DAT_181b2b4b0 != '\0')) {
        if (param_10 == '\0') {
          uVar1 = func_0x000180004f90(0x181b2b4b4);
        }
        else {
          uVar1 = 0x2d0000ff;
        }
        fStack_178 = param_1 + param_3;
        fStack_174 = param_2 + param_4;
        fStack_14c = param_1;
        fStack_148 = param_2;
        func_0x000180027d60(lVar2,&fStack_14c,&fStack_178,uVar1,0,0);
      }
      param_3 = param_3 + param_1;
      param_4 = param_4 + param_2;
      iVar3 = (int)param_7;
      if (iVar3 < 1) {
        fVar4 = fVar9 + param_1;
        fVar5 = param_2 + fVar4;
      }
      else {
        fStack_154 = fVar4 + param_2;
        fStack_158 = fVar9 + param_1;
        fStack_14c = param_3 - fVar9;
        fStack_178 = param_4 - fVar4;
        do {
          fStack_134 = ((_DAT_181a03230 - (float)iVar3 / param_7) * _DAT_181a03330) / _DAT_181a033ec
          ;
          if (param_10 == '\0') {
            uStack_140 = *param_5;
            uStack_138 = *(undefined4 *)(param_5 + 1);
          }
          else {
            uStack_140 = 0x3f800000;
            uStack_138 = 0;
          }
          fVar4 = (float)iVar3 * _DAT_181a031bc;
          fVar5 = param_2 - fVar4;
          fVar10 = param_1 - fVar4;
          fVar8 = fVar4 + fStack_158;
          fStack_130 = fVar8;
          fStack_12c = fVar5;
          fStack_128 = fVar10;
          fStack_124 = fVar5;
          uVar1 = func_0x000180004f90(&uStack_140);
          func_0x000180027b00(lVar2,&fStack_128,&fStack_130,uVar1,param_6);
          fVar9 = fVar4 + fStack_154;
          fStack_120 = fVar10;
          fStack_11c = fVar9;
          fStack_118 = fVar10;
          fStack_114 = fVar5;
          func_0x000180027b00(lVar2,&fStack_118,&fStack_120,uVar1,param_6);
          fVar6 = fStack_14c - fVar4;
          fVar7 = param_3 + fVar4;
          fStack_110 = fVar6;
          fStack_10c = fVar5;
          fStack_108 = fVar7;
          fStack_104 = fVar5;
          func_0x000180027b00(lVar2,&fStack_108,&fStack_110,uVar1,param_6);
          fStack_100 = fVar7;
          fStack_fc = fVar9;
          fStack_f8 = fVar7;
          fStack_f4 = fVar5;
          func_0x000180027b00(lVar2,&fStack_f8,&fStack_100,uVar1,param_6);
          fVar9 = param_4 + fVar4;
          fStack_f0 = fVar8;
          fStack_ec = fVar9;
          fStack_e8 = fVar10;
          fStack_e4 = fVar9;
          func_0x000180027b00(lVar2,&fStack_e8,&fStack_f0,uVar1,param_6);
          fVar4 = fStack_178 - fVar4;
          fStack_e0 = fVar10;
          fStack_dc = fVar4;
          fStack_d8 = fVar10;
          fStack_d4 = fVar9;
          func_0x000180027b00(lVar2,&fStack_d8,&fStack_e0,uVar1,param_6);
          fStack_d0 = fVar6;
          fStack_cc = fVar9;
          fStack_c8 = fVar7;
          fStack_c4 = fVar9;
          func_0x000180027b00(lVar2,&fStack_c8,&fStack_d0,uVar1,param_6);
          fStack_170 = fVar7;
          fStack_16c = fVar4;
          fStack_168 = fVar7;
          fStack_164 = fVar9;
          func_0x000180027b00(lVar2,&fStack_168,&fStack_170,uVar1,param_6);
          iVar3 = iVar3 + -1;
          fVar4 = fStack_158;
          fVar9 = fStack_160;
          fVar5 = fStack_154;
        } while (0 < iVar3);
      }
      fStack_170 = param_1;
      fStack_16c = param_2;
      fStack_168 = fVar4;
      fStack_164 = param_2;
      uVar1 = func_0x000180004f90(param_5);
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_1;
      fStack_16c = param_2;
      fStack_168 = param_1;
      fStack_164 = fVar5;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_3;
      fStack_16c = param_2;
      fStack_168 = param_3 - fVar9;
      fStack_164 = param_2;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_3;
      fStack_16c = param_2;
      fStack_168 = param_3;
      fStack_164 = fVar5;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_1;
      fStack_16c = param_4;
      fStack_168 = fVar4;
      fStack_164 = param_4;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fVar4 = param_4 - fStack_150;
      fStack_170 = param_1;
      fStack_16c = param_4;
      fStack_168 = param_1;
      fStack_164 = fVar4;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_3;
      fStack_16c = param_4;
      fStack_168 = param_3 - fVar9;
      fStack_164 = param_4;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
      fStack_170 = param_3;
      fStack_16c = param_4;
      fStack_168 = param_3;
      fStack_164 = fVar4;
      func_0x000180027b00(lVar2,&fStack_170,&fStack_168,uVar1,param_6);
    }
    else {
      fStack_178 = param_1;
      fStack_174 = param_2;
      fStack_160 = fVar9 + param_1;
      fStack_15c = param_2;
      uVar1 = func_0x000180004f90(param_5);
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fStack_178 = param_1;
      fStack_174 = param_2;
      fStack_160 = param_1;
      fStack_15c = fVar4 + param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      param_3 = param_1 + param_3;
      fStack_178 = param_3;
      fStack_174 = param_2;
      fStack_160 = param_3 - fVar9;
      fStack_15c = param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fStack_178 = param_3;
      fStack_174 = param_2;
      fStack_160 = param_3;
      fStack_15c = fVar4 + param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      param_2 = param_2 + param_4;
      fStack_178 = param_1;
      fStack_174 = param_2;
      fStack_160 = fVar9 + param_1;
      fStack_15c = param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fVar9 = param_2 - fStack_150;
      fStack_178 = param_1;
      fStack_174 = param_2;
      fStack_160 = param_1;
      fStack_15c = fVar9;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fStack_178 = param_3;
      fStack_174 = param_2;
      fStack_160 = param_3 - fVar9;
      fStack_15c = param_2;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
      fStack_178 = param_3;
      fStack_174 = param_2;
      fStack_160 = param_3;
      fStack_15c = fVar9;
      func_0x000180027b00(lVar2,&fStack_178,&fStack_160,uVar1,param_6);
    }
  }
  return;
}

