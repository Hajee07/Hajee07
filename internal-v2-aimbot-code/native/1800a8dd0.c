/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800a8dd0(undefined8 param_1,longlong **param_2)

{
  longlong *plVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  longlong **pplVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  undefined8 uStackX_8;
  undefined4 auStackX_18 [2];
  longlong lStackX_20;
  undefined auStack_d8 [16];
  undefined auStack_c8 [16];
  longlong lStack_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined auStack_90 [16];
  undefined auStack_80 [16];
  undefined auStack_70 [8];
  undefined8 uStack_68;
  undefined8 uStack_60;
  
  uStackX_8 = param_1;
  recovered_180069a10(0x181b2f740);
  recovered_180069a10(0x181b2f780);
  recovered_180069a10(0x181b2f7c0);
  recovered_180069a10(0x181b2f800);
  if (_DAT_181b2f880 != _DAT_181b2f888) {
    _DAT_181b2f888 = _DAT_181b2f880;
  }
  GetSystemInfo(auStack_70);
  uStackX_8 = uStack_60;
  uVar4 = recovered_1800a8c60();
  iVar3 = recovered_1800a8cf0(uVar4);
  if ((iVar3 == 0) ||
     (_DAT_181b2f6e0 = iVar3, _DAT_181b2f6e8 = OpenProcess(0x1fffff,0,iVar3), _DAT_181b2f6e8 == 0))
  {
    puVar9 = &UNK_1819dc778;
  }
  else {
    plVar7 = param_2[2];
    if (0x7fffffffffffffffU - (longlong)plVar7 < 7) {
      func_0x000180052a50();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    pplVar6 = param_2;
    if ((longlong *)0xf < param_2[3]) {
      pplVar6 = (longlong **)*param_2;
    }
    auStack_d8 = ZEXT816(0);
    auStack_c8 = ZEXT816(0);
    uVar11 = (longlong)plVar7 + 7;
    uVar10 = 0xf;
    puVar5 = (undefined4 *)auStack_d8;
    if (0xf < uVar11) {
      uVar10 = uVar11 | 0xf;
      if (uVar10 < 0x8000000000000000) {
        if (uVar10 < 0x16) {
          uVar10 = 0x16;
        }
      }
      else {
        uVar10 = 0x7fffffffffffffff;
      }
      puVar5 = (undefined4 *)func_0x000180024110(uVar10 + 1);
      auStack_d8._0_8_ = puVar5;
    }
    auStack_c8._8_8_ = uVar10;
    auStack_c8._0_8_ = uVar11;
    *puVar5 = _DAT_1819dc7a8;
    *(undefined2 *)(puVar5 + 1) = _DAT_1819dc7ac;
    *(undefined *)((longlong)puVar5 + 6) = DAT_1819dc7ae;
    func_0x0001801ca88d((longlong)puVar5 + 7,pplVar6,plVar7);
    *(undefined *)((longlong)puVar5 + uVar11) = 0;
    puVar5 = (undefined4 *)recovered_180066ec0(auStack_d8,&UNK_1819dc768,0xc);
    uStack_b0 = *puVar5;
    uStack_ac = puVar5[1];
    uStack_a8 = puVar5[2];
    uStack_a4 = puVar5[3];
    uStack_a0 = puVar5[4];
    uStack_9c = puVar5[5];
    uStack_98 = puVar5[6];
    uStack_94 = puVar5[7];
    uVar11 = 0;
    *(undefined8 *)(puVar5 + 4) = 0;
    *(undefined8 *)(puVar5 + 6) = 0xf;
    *(undefined *)puVar5 = 0;
    uVar12 = recovered_1800785e0(&DAT_181ade2c0,&uStack_b0);
    if (0xf < CONCAT44(uStack_94,uStack_98)) {
      if ((0xfff < CONCAT44(uStack_94,uStack_98) + 1) &&
         (0x1f < (CONCAT44(uStack_ac,uStack_b0) - *(longlong *)(CONCAT44(uStack_ac,uStack_b0) + -8))
                 - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar12 = func_0x000180127e40();
    }
    if (0xf < (ulonglong)auStack_c8._8_8_) {
      if ((0xfff < auStack_c8._8_8_ + 1) &&
         (0x1f < (auStack_d8._0_8_ - *(longlong *)(auStack_d8._0_8_ + -8)) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar12 = func_0x000180127e40();
    }
    if (DAT_181ade204 == '\0') {
      recovered_1800a9bf0(uVar12,uStack_68,uStackX_8,_DAT_181b2f898,&DAT_181b2f880);
    }
    else {
      recovered_1800a9510();
    }
    if (_DAT_181b2f880 != _DAT_181b2f888) {
      if (_DAT_181b2f888 - _DAT_181b2f880 >> 3 != 0) {
        do {
          plVar7 = param_2[2];
          plVar1 = param_2[3];
          pplVar6 = param_2;
          if ((longlong *)0xf < plVar1) {
            pplVar6 = (longlong **)*param_2;
          }
          if ((plVar7 == (longlong *)0x8) && (*pplVar6 == (longlong *)0x6b63654e7466654c)) {
            lStackX_20 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x188;
            lStack_b8 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x154;
          }
          else {
            pplVar6 = param_2;
            if ((longlong *)0xf < plVar1) {
              pplVar6 = (longlong **)*param_2;
            }
            if (plVar7 == (longlong *)0x9) {
              lVar8 = (longlong)*pplVar6 + -0x63654e7468676952;
              if (lVar8 == 0) {
                lVar8 = (ulonglong)*(byte *)(pplVar6 + 1) - 0x6b;
              }
              if (lVar8 == 0) {
                lStackX_20 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x184;
                lStack_b8 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x154;
                goto LAB_1800a9203;
              }
            }
            pplVar6 = param_2;
            if ((longlong *)0xf < plVar1) {
              pplVar6 = (longlong **)*param_2;
            }
            if (plVar7 == (longlong *)0xc) {
              lVar8 = (longlong)*pplVar6 + -0x756f68537466654c;
              if (lVar8 == 0) {
                lVar8 = (ulonglong)*(uint *)(pplVar6 + 1) - 0x7265646c;
              }
              if (lVar8 == 0) {
                lStackX_20 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x194;
                lStack_b8 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x154;
                goto LAB_1800a9203;
              }
            }
            pplVar6 = param_2;
            if ((longlong *)0xf < plVar1) {
              pplVar6 = (longlong **)*param_2;
            }
            if (plVar7 == (longlong *)0xd) {
              lVar8 = (longlong)*pplVar6 + -0x6f68537468676952;
              if ((lVar8 == 0) &&
                 (lVar8 = (ulonglong)*(uint *)(pplVar6 + 1) - 0x65646c75, lVar8 == 0)) {
                lVar8 = (ulonglong)*(byte *)((longlong)pplVar6 + 0xc) - 0x72;
              }
              if (lVar8 == 0) {
                lStackX_20 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x198;
                lStack_b8 = *(longlong *)(_DAT_181b2f880 + uVar11 * 8) + 0x154;
                goto LAB_1800a9203;
              }
            }
            lStackX_20 = *(longlong *)(uVar11 * 8 + _DAT_181b2f880) + 0xb6;
            lStack_b8 = *(longlong *)(uVar11 * 8 + _DAT_181b2f880) + 0xb2;
          }
LAB_1800a9203:
          iVar3 = ReadProcessMemory(_DAT_181b2f6e8,lStack_b8,auStackX_18,4,0);
          uVar12 = auStackX_18[0];
          if (iVar3 == 0) {
            uVar4 = 0x23;
            puVar9 = &UNK_1819dc7b0;
            goto LAB_1800a94db;
          }
          plVar7 = (longlong *)func_0x0001800b8500(0x181b2f740,auStack_90,&lStack_b8);
          *(undefined4 *)(*plVar7 + 0x18) = uVar12;
          iVar3 = ReadProcessMemory(_DAT_181b2f6e8,lStackX_20,&uStackX_8,4,0);
          if (iVar3 == 0) {
            uVar4 = 0x24;
            puVar9 = &UNK_1819dc800;
            goto LAB_1800a94db;
          }
          uVar12 = (undefined4)uStackX_8;
          plVar7 = (longlong *)func_0x0001800b8500(0x181b2f780,auStack_80,&lStackX_20);
          *(undefined4 *)(*plVar7 + 0x18) = uVar12;
          iVar3 = WriteProcessMemory(_DAT_181b2f6e8,lStack_b8,&uStackX_8,4,0);
          if (iVar3 == 0) {
            uVar4 = 0x24;
            puVar9 = &UNK_1819dc7d8;
            goto LAB_1800a94db;
          }
          uVar12 = (undefined4)uStackX_8;
          plVar7 = (longlong *)func_0x0001800b8500(0x181b2f7c0,&uStack_b0,&lStack_b8);
          *(undefined4 *)(*plVar7 + 0x18) = uVar12;
          iVar3 = WriteProcessMemory(_DAT_181b2f6e8,lStackX_20,auStackX_18,4,0);
          uVar12 = auStackX_18[0];
          if (iVar3 == 0) {
            uVar4 = 0x25;
            puVar9 = &UNK_1819dc848;
            goto LAB_1800a94db;
          }
          plVar7 = (longlong *)func_0x0001800b8500(0x181b2f800,auStack_d8,&lStackX_20);
          *(undefined4 *)(*plVar7 + 0x18) = uVar12;
          uVar11 = uVar11 + 1;
        } while (uVar11 < (ulonglong)(_DAT_181b2f888 - _DAT_181b2f880 >> 3));
      }
      plVar7 = param_2[2];
      if (0x7fffffffffffffffU - (longlong)plVar7 < 7) {
        func_0x000180052a50();
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      if ((longlong *)0xf < param_2[3]) {
        param_2 = (longlong **)*param_2;
      }
      auStack_d8 = ZEXT816(0);
      auStack_c8 = ZEXT816(0);
      uVar11 = (longlong)plVar7 + 7;
      uVar10 = 0xf;
      puVar5 = (undefined4 *)auStack_d8;
      if (0xf < uVar11) {
        uVar10 = uVar11 | 0xf;
        if (uVar10 < 0x8000000000000000) {
          if (uVar10 < 0x16) {
            uVar10 = 0x16;
          }
        }
        else {
          uVar10 = 0x7fffffffffffffff;
        }
        puVar5 = (undefined4 *)func_0x000180024110(uVar10 + 1);
        auStack_d8._0_8_ = puVar5;
      }
      auStack_c8._8_8_ = uVar10;
      auStack_c8._0_8_ = uVar11;
      *puVar5 = _DAT_1819dc7a8;
      *(undefined2 *)(puVar5 + 1) = _DAT_1819dc7ac;
      *(undefined *)((longlong)puVar5 + 6) = DAT_1819dc7ae;
      func_0x0001801ca88d((longlong)puVar5 + 7,param_2,plVar7);
      *(undefined *)((longlong)puVar5 + uVar11) = 0;
      puVar5 = (undefined4 *)recovered_180066ec0(auStack_d8,&UNK_1819dc828,0x18);
      uStack_b0 = *puVar5;
      uStack_ac = puVar5[1];
      uStack_a8 = puVar5[2];
      uStack_a4 = puVar5[3];
      uStack_a0 = puVar5[4];
      uStack_9c = puVar5[5];
      uStack_98 = puVar5[6];
      uStack_94 = puVar5[7];
      *(undefined8 *)(puVar5 + 4) = 0;
      *(undefined8 *)(puVar5 + 6) = 0xf;
      *(undefined *)puVar5 = 0;
      recovered_1800785e0(&DAT_181ade2c0,&uStack_b0);
      if (0xf < CONCAT44(uStack_94,uStack_98)) {
        if ((0xfff < CONCAT44(uStack_94,uStack_98) + 1) &&
           (0x1f < (CONCAT44(uStack_ac,uStack_b0) -
                   *(longlong *)(CONCAT44(uStack_ac,uStack_b0) + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        func_0x000180127e40();
      }
      recovered_180066e40(auStack_d8);
      return;
    }
    puVar9 = &UNK_1819dc790;
  }
  uVar4 = 0x12;
LAB_1800a94db:
  recovered_1800676d0(&DAT_181ade2c0,puVar9,uVar4);
  return;
}

