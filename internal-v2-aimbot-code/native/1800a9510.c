/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x0001800a9683) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
recovered_1800a9510(undefined8 param_1,undefined *param_2,undefined *param_3,undefined8 param_4,
                   undefined8 param_5)

{
  ulonglong uVar1;
  longlong **pplVar2;
  int iVar3;
  longlong *plVar4;
  longlong **pplVar5;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  longlong **pplVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined4 *puVar12;
  longlong **pplVar13;
  ulonglong uVar14;
  undefined8 uStackX_8;
  undefined8 uStackX_10;
  undefined8 uStackX_20;
  undefined auStack_198 [16];
  undefined4 *puStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined auStack_170 [16];
  longlong **pplStack_160;
  longlong **pplStack_158;
  undefined8 *puStack_150;
  undefined8 *puStack_148;
  undefined4 *puStack_140;
  undefined8 uStack_138;
  longlong **applStack_130 [3];
  longlong lStack_118;
  int iStack_110;
  uint uStack_10c;
  undefined4 auStack_f8 [2];
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined auStack_e0 [16];
  undefined auStack_d0 [16];
  undefined auStack_c0 [16];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  
  uStackX_8 = param_1;
  uStackX_20 = param_4;
  uStackX_8 = _msize(param_4);
  auStack_198 = ZEXT816(0);
  puStack_188 = (undefined4 *)0x0;
  lVar7 = VirtualQueryEx(_DAT_181b2f6e8,param_2,applStack_130,0x30);
  while( true ) {
    if (lVar7 == 0) break;
    if (param_3 <= param_2) break;
    if (((iStack_110 == 0x1000) && ((uStack_10c >> 8 & 1) == 0)) && (uStack_10c != 1)) {
      uStack_180 = applStack_130[0];
      uStack_178 = lStack_118;
      if ((undefined4 *)auStack_198._8_8_ == puStack_188) {
        lVar7 = (longlong)(auStack_198._8_8_ - auStack_198._0_8_) >> 4;
        if (lVar7 == 0xfffffffffffffff) {
          recovered_18006aad0();
          goto LAB_1800a9a7c;
        }
        uVar1 = lVar7 + 1;
        uVar11 = (longlong)puStack_188 - auStack_198._0_8_ >> 4;
        if (0xfffffffffffffff - (uVar11 >> 1) < uVar11) {
          uVar14 = 0xfffffffffffffff;
        }
        else {
          uVar11 = uVar11 + (uVar11 >> 1);
          uVar14 = uVar1;
          if (uVar1 <= uVar11) {
            uVar14 = uVar11;
          }
          if (0xfffffffffffffff < uVar14) goto LAB_1800a9a70;
        }
        lVar8 = func_0x000180024110(uVar14 * 0x10);
        puVar12 = (undefined4 *)(lVar7 * 0x10 + lVar8);
        *puVar12 = (undefined4)uStack_180;
        puVar12[1] = uStack_180._4_4_;
        puVar12[2] = (undefined4)uStack_178;
        puVar12[3] = uStack_178._4_4_;
        func_0x0001801ca893(lVar8,auStack_198._0_8_,auStack_198._8_8_ - auStack_198._0_8_);
        if ((undefined4 *)auStack_198._0_8_ != (undefined4 *)0x0) {
          if ((0xfff < ((longlong)puStack_188 - auStack_198._0_8_ & 0xfffffffffffffff0U)) &&
             (0x1f < (ulonglong)(auStack_198._0_8_ + (-8 - *(longlong *)(auStack_198._0_8_ + -8)))))
          goto LAB_1800a99af;
          func_0x000180127e40();
        }
        auStack_198._8_8_ = uVar1 * 0x10 + lVar8;
        auStack_198._0_8_ = lVar8;
        puStack_188 = (undefined4 *)(lVar8 + uVar14 * 0x10);
      }
      else {
        uStack_180._0_4_ = SUB84(applStack_130[0],0);
        uStack_180._4_4_ = (undefined4)((ulonglong)applStack_130[0] >> 0x20);
        uStack_178._0_4_ = (undefined4)lStack_118;
        uStack_178._4_4_ = (undefined4)((ulonglong)lStack_118 >> 0x20);
        *(undefined4 *)auStack_198._8_8_ = (undefined4)uStack_180;
        *(undefined4 *)(auStack_198._8_8_ + 4) = uStack_180._4_4_;
        *(undefined4 *)(auStack_198._8_8_ + 8) = (undefined4)uStack_178;
        *(undefined4 *)(auStack_198._8_8_ + 0xc) = uStack_178._4_4_;
        auStack_198._8_8_ = (undefined4 *)(auStack_198._8_8_ + 0x10);
      }
    }
    param_2 = (undefined *)(lStack_118 + (longlong)applStack_130[0]);
    lVar7 = VirtualQueryEx(_DAT_181b2f6e8,param_2,applStack_130,0x30);
  }
  auStack_e0 = ZEXT816(0);
  auStack_d0 = ZEXT816(0);
  auStack_c0 = ZEXT816(0);
  uStack_f0 = 0;
  uStack_e8 = 0;
  uStack_b0 = 0xffffffff;
  auStack_f8[0] = 2;
  uStack_ac = 0;
  pplStack_158 = (longlong **)&DAT_181b2f6e0;
  auStack_170 = ZEXT816(0);
  pplStack_160 = (longlong **)0x0;
  puStack_150 = &uStackX_20;
  puStack_148 = &uStackX_8;
  puStack_140 = auStack_f8;
  uStack_138 = param_5;
  puVar12 = (undefined4 *)auStack_198._0_8_;
  do {
    if (puVar12 == (undefined4 *)auStack_198._8_8_) {
      pplVar9 = (longlong **)auStack_170._8_8_;
      pplVar13 = (longlong **)auStack_170._0_8_;
      if (auStack_170._0_8_ != auStack_170._8_8_) {
        do {
          pplVar5 = (longlong **)*pplVar13;
          *pplVar13 = (longlong *)0x0;
          uStack_178 = CONCAT71(uStack_178._1_7_,1);
          uStack_180 = pplVar5;
          if ((pplVar5 == (longlong **)0x0) || (*(char *)(pplVar5 + 0x17) != '\0')) {
            recovered_1800a4920(4);
LAB_1800a9a70:
            func_0x000180003980();
            pcVar6 = (code *)swi(3);
            uVar10 = (*pcVar6)();
            return uVar10;
          }
          (*(code *)(*pplVar5)[2])(pplVar5,1);
          LOCK();
          pplVar2 = pplVar5 + 1;
          iVar3 = *(int *)pplVar2;
          *(int *)pplVar2 = *(int *)pplVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            plVar4 = pplVar5[0x19];
            if (plVar4 == (longlong *)0x0) {
              (*(code *)**pplVar5)(pplVar5,1);
            }
            else {
              (**(code **)*plVar4)(plVar4,pplVar5);
            }
          }
          pplVar13 = pplVar13 + 2;
        } while (pplVar13 != pplVar9);
      }
      if ((longlong **)auStack_170._0_8_ != (longlong **)0x0) {
        func_0x0001800bad80(auStack_170._0_8_,auStack_170._8_8_);
        if ((0xfff < ((longlong)pplStack_160 - auStack_170._0_8_ & 0xfffffffffffffff0U)) &&
           (0x1f < (auStack_170._0_8_ - *(longlong *)(auStack_170._0_8_ + -8)) - 8U)) {
LAB_1800a99af:
          _invoke_watson(0,0,0,0,0);
          pcVar6 = (code *)swi(3);
          uVar10 = (*pcVar6)();
          return uVar10;
        }
        func_0x000180127e40();
        auStack_170 = ZEXT816(0);
        pplStack_160 = (longlong **)0x0;
      }
      if ((undefined4 *)auStack_198._0_8_ != (undefined4 *)0x0) {
        puVar12 = (undefined4 *)auStack_198._0_8_;
        if ((0xfff < ((longlong)puStack_188 - auStack_198._0_8_ & 0xfffffffffffffff0U)) &&
           (puVar12 = *(undefined4 **)(auStack_198._0_8_ + -8),
           0x1f < (ulonglong)(auStack_198._0_8_ + (-8 - (longlong)puVar12)))) {
          _invoke_watson(0,0,0,0,0);
          pcVar6 = (code *)swi(3);
          uVar10 = (*pcVar6)();
          return uVar10;
        }
        func_0x000180127e40(puVar12);
      }
      return 1;
    }
    uStack_a8 = *puVar12;
    uStack_a4 = puVar12[1];
    uStack_a0 = puVar12[2];
    uStack_9c = puVar12[3];
    uStack_98 = 0x81b2f6e0;
    uStack_94 = 1;
    uStack_78 = param_5;
    uStack_88 = &uStackX_8;
    uStack_80 = auStack_f8;
    uStack_90 = &uStackX_20;
    uStackX_10 = func_0x000180127a94(0x120);
    pplVar9 = (longlong **)func_0x0001800b9940(uStackX_10,&uStack_a8);
    puStack_150 = (undefined8 *)((ulonglong)puStack_150 & 0xffffffffffffff00);
    puStack_148 = (undefined8 *)((ulonglong)puStack_148 & 0xffffffffffffff00);
    pplStack_158 = pplVar9;
    if (pplVar9 == (longlong **)0x0) {
LAB_1800a9a7c:
      recovered_1800a4920(4);
      pcVar6 = (code *)swi(3);
      uVar10 = (*pcVar6)();
      return uVar10;
    }
    uStack_178 = CONCAT71(uStack_178._1_7_,1);
    LOCK();
    *(int *)(pplVar9 + 1) = *(int *)(pplVar9 + 1) + 1;
    UNLOCK();
    LOCK();
    pplVar13 = pplVar9 + 1;
    iVar3 = *(int *)pplVar13;
    *(int *)pplVar13 = *(int *)pplVar13 + -1;
    UNLOCK();
    uStack_180 = pplVar9;
    if (iVar3 == 1) {
      plVar4 = pplVar9[0x19];
      if (plVar4 == (longlong *)0x0) {
        (*(code *)**pplVar9)(pplVar9,1);
      }
      else {
        (**(code **)*plVar4)(plVar4,pplVar9);
      }
    }
    if ((longlong **)auStack_170._8_8_ == pplStack_160) {
      func_0x0001800b9e30(auStack_170,auStack_170._8_8_,&uStack_180);
      pplVar9 = uStack_180;
    }
    else {
      *(longlong ***)auStack_170._8_8_ = pplVar9;
      *(undefined *)(auStack_170._8_8_ + 8) = 1;
      auStack_170._8_8_ = (longlong **)(auStack_170._8_8_ + 0x10);
      pplVar9 = (longlong **)0x0;
    }
    if (pplVar9 != (longlong **)0x0) {
      LOCK();
      pplVar13 = pplVar9 + 1;
      iVar3 = *(int *)pplVar13;
      *(int *)pplVar13 = *(int *)pplVar13 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        plVar4 = pplVar9[0x19];
        if (plVar4 == (longlong *)0x0) {
          (*(code *)**pplVar9)(pplVar9,1);
        }
        else {
          (**(code **)*plVar4)(plVar4,pplVar9);
        }
      }
    }
    puVar12 = puVar12 + 4;
  } while( true );
}

