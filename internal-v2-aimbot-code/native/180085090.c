/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180085090(longlong **param_1,longlong param_2,float *param_3,undefined8 param_4,
                        char *param_5)

{
  char *pcVar1;
  longlong lVar2;
  float fVar3;
  float fVar4;
  char *pcVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  
  pcVar5 = param_5;
  fVar4 = _DAT_181a0348c;
  fVar3 = _DAT_181a03230;
  if ((param_5 != (char *)0x0) && (*param_5 != '\0')) {
    if (param_2 == 0) {
      fVar13 = *(float *)(_DAT_181b2f2c0 + 0x3c38);
    }
    else {
      fVar13 = *(float *)(param_2 + 0x14);
    }
    lVar9 = -1;
    fVar10 = fVar4;
    fVar12 = _DAT_181a0348c;
    do {
      if ((fVar12 != 0.0) || (fVar10 != 0.0)) {
        param_5._0_4_ = fVar12 + *param_3;
        param_5._4_4_ = fVar10 + param_3[1];
        lVar2 = **param_1;
        lVar7 = -1;
        do {
          pcVar1 = pcVar5 + 1 + lVar7;
          lVar7 = lVar7 + 1;
        } while (*pcVar1 != '\0');
        if (pcVar5 != pcVar5 + lVar7) {
          lVar8 = param_2;
          if (param_2 == 0) {
            lVar8 = *(longlong *)(*(longlong *)(lVar2 + 0x38) + 8);
          }
          fVar11 = fVar13;
          if (fVar13 == 0.0) {
            fVar11 = *(float *)(*(longlong *)(lVar2 + 0x38) + 0x10);
          }
          if (*(longlong *)(*(longlong *)(lVar8 + 0x40) + 8) != *(longlong *)(lVar2 + 0x98)) {
            _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
          }
          uStack_a8 = *(undefined4 *)(lVar2 + 0x88);
          uStack_a4 = *(undefined4 *)(lVar2 + 0x8c);
          uStack_a0 = *(undefined4 *)(lVar2 + 0x90);
          uStack_9c = *(undefined4 *)(lVar2 + 0x94);
          func_0x000180030c90(lVar8,lVar2,fVar11,&param_5,0xc8000000,&uStack_a8,pcVar5,
                              pcVar5 + lVar7,0,0);
        }
      }
      fVar10 = fVar10 + fVar3;
    } while ((fVar10 <= fVar3) || (fVar12 = fVar12 + fVar3, fVar10 = fVar4, fVar12 <= fVar3));
    lVar7 = **param_1;
    uVar6 = func_0x000180004f90(param_4);
    if ((uVar6 & 0xff000000) != 0) {
      do {
        pcVar1 = pcVar5 + 1 + lVar9;
        lVar9 = lVar9 + 1;
      } while (*pcVar1 != '\0');
      if (pcVar5 != pcVar5 + lVar9) {
        if (param_2 == 0) {
          param_2 = *(longlong *)(*(longlong *)(lVar7 + 0x38) + 8);
        }
        if (fVar13 == 0.0) {
          fVar13 = *(float *)(*(longlong *)(lVar7 + 0x38) + 0x10);
        }
        if (*(longlong *)(*(longlong *)(param_2 + 0x40) + 8) != *(longlong *)(lVar7 + 0x98)) {
          _wassert(&UNK_1819d1c30,&UNK_1819d1a00,0x6ab);
        }
        uStack_a8 = *(undefined4 *)(lVar7 + 0x88);
        uStack_a4 = *(undefined4 *)(lVar7 + 0x8c);
        uStack_a0 = *(undefined4 *)(lVar7 + 0x90);
        uStack_9c = *(undefined4 *)(lVar7 + 0x94);
        func_0x000180030c90(param_2,lVar7,fVar13,param_3,uVar6,&uStack_a8,pcVar5,pcVar5 + lVar9,0,0)
        ;
      }
    }
  }
  return;
}

