/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x0001800a9dcf) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
recovered_1800a9bf0(ulonglong param_1,ulonglong param_2,ulonglong param_3,char *param_4,
                   undefined8 param_5)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  char *pcVar8;
  ulonglong uVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  ulonglong uStackX_8;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined auStack_98 [16];
  undefined8 *puStack_88;
  longlong alStack_80 [2];
  uint uStack_70;
  longlong lStack_68;
  int iStack_60;
  uint uStack_5c;
  
  uStackX_8 = param_1;
  uVar5 = recovered_1800a8c60();
  iVar4 = recovered_1800a8cf0(uVar5);
  if ((iVar4 == 0) ||
     (_DAT_181b2f6e0 = iVar4, _DAT_181b2f6e8 = OpenProcess(0x1fffff,0,iVar4), _DAT_181b2f6e8 == 0))
  {
    uVar5 = 0;
  }
  else {
    uVar5 = recovered_1800a8c60();
    iVar4 = recovered_1800a8cf0(uVar5);
    if (iVar4 != 0) {
      _DAT_181b2f6e0 = iVar4;
      _DAT_181b2f6e8 = OpenProcess(0x1fffff,0,iVar4);
    }
    auStack_98 = ZEXT816(0);
    puStack_88 = (undefined8 *)0x0;
    lStack_68 = 0x1000;
    uVar6 = _msize(param_4);
    lVar7 = VirtualQueryEx(_DAT_181b2f6e8,param_2,alStack_80,0x30);
    while( true ) {
      puVar13 = (undefined8 *)auStack_98._0_8_;
      if (((lVar7 == 0) || (param_3 <= param_2)) || (param_2 + lStack_68 <= param_2)) break;
      if ((((iStack_60 == 0x1000) && ((uStack_5c >> 8 & 1) == 0)) && (uStack_5c != 1)) &&
         ((uStack_70 & 0x200) == 0)) {
        uStack_a8 = (undefined4)alStack_80[0];
        uStack_a4 = (undefined4)((ulonglong)alStack_80[0] >> 0x20);
        uStack_a0 = (undefined4)lStack_68;
        uStack_9c = (undefined4)((ulonglong)lStack_68 >> 0x20);
        if ((undefined8 *)auStack_98._8_8_ == puStack_88) {
          lVar7 = (longlong)(auStack_98._8_8_ - auStack_98._0_8_) >> 4;
          if (lVar7 == 0xfffffffffffffff) {
            recovered_18006aad0();
LAB_1800aa073:
            func_0x000180003980();
            pcVar2 = (code *)swi(3);
            uVar5 = (*pcVar2)();
            return uVar5;
          }
          uVar11 = lVar7 + 1;
          uVar9 = (longlong)puStack_88 - auStack_98._0_8_ >> 4;
          if (0xfffffffffffffff - (uVar9 >> 1) < uVar9) {
            uVar12 = 0xfffffffffffffff;
          }
          else {
            uVar9 = (uVar9 >> 1) + uVar9;
            uVar12 = uVar11;
            if (uVar11 <= uVar9) {
              uVar12 = uVar9;
            }
            if (0xfffffffffffffff < uVar12) goto LAB_1800aa073;
          }
          lVar10 = func_0x000180024110(uVar12 * 0x10);
          puVar1 = (undefined4 *)(lVar7 * 0x10 + lVar10);
          *puVar1 = uStack_a8;
          puVar1[1] = uStack_a4;
          puVar1[2] = uStack_a0;
          puVar1[3] = uStack_9c;
          func_0x0001801ca893(lVar10,auStack_98._0_8_,auStack_98._8_8_ - auStack_98._0_8_);
          if ((undefined8 *)auStack_98._0_8_ != (undefined8 *)0x0) {
            if ((0xfff < ((longlong)puStack_88 - auStack_98._0_8_ & 0xfffffffffffffff0U)) &&
               (0x1f < (ulonglong)(auStack_98._0_8_ + (-8 - *(longlong *)(auStack_98._0_8_ + -8)))))
            {
              _invoke_watson(0,0,0,0,0);
              pcVar2 = (code *)swi(3);
              uVar5 = (*pcVar2)();
              return uVar5;
            }
            func_0x000180127e40();
          }
          auStack_98._8_8_ = uVar11 * 0x10 + lVar10;
          auStack_98._0_8_ = lVar10;
          puStack_88 = (undefined8 *)(uVar12 * 0x10 + lVar10);
        }
        else {
          *(undefined4 *)auStack_98._8_8_ = uStack_a8;
          *(undefined4 *)(auStack_98._8_8_ + 4) = uStack_a4;
          *(undefined4 *)(auStack_98._8_8_ + 8) = uStack_a0;
          *(undefined4 *)(auStack_98._8_8_ + 0xc) = uStack_9c;
          auStack_98._8_8_ = (undefined8 *)(auStack_98._8_8_ + 0x10);
        }
      }
      param_2 = alStack_80[0] + lStack_68;
      lVar7 = VirtualQueryEx(_DAT_181b2f6e8,param_2,alStack_80);
    }
    for (; puVar13 != (undefined8 *)auStack_98._8_8_; puVar13 = puVar13 + 2) {
      uVar3 = *puVar13;
      uStackX_8 = 0;
      uVar5 = puVar13[1];
      lVar7 = func_0x000180127f44(uVar5);
      func_0x0001801ca899(lVar7,0,uVar5);
      ReadProcessMemory(_DAT_181b2f6e8,uVar3,lVar7,uVar5,&uStackX_8);
      if (0 < (int)uStackX_8) {
        lVar10 = 0;
        uVar11 = 0;
        if (uStackX_8 != 0) {
          do {
            uVar9 = 0;
            if (uVar6 != 0) {
              pcVar8 = param_4;
              do {
                if ((pcVar8[(lVar7 - (longlong)param_4) + uVar11] != *pcVar8) && (*pcVar8 != '?'))
                goto LAB_1800a9f2e;
                uVar9 = uVar9 + 1;
                pcVar8 = pcVar8 + 1;
              } while (uVar9 < uVar6);
            }
            if (uVar9 == uVar6) {
              if ((int)uVar11 != -1) goto LAB_1800a9f60;
              break;
            }
LAB_1800a9f2e:
            uVar11 = uVar11 + 1;
          } while (uVar11 < uStackX_8);
        }
      }
LAB_1800a9fd7:
      func_0x000180127e40(lVar7);
    }
    if ((undefined8 *)auStack_98._0_8_ != (undefined8 *)0x0) {
      puVar13 = (undefined8 *)auStack_98._0_8_;
      if ((0xfff < ((longlong)puStack_88 - auStack_98._0_8_ & 0xfffffffffffffff0U)) &&
         (puVar13 = *(undefined8 **)(auStack_98._0_8_ + -8),
         0x1f < (ulonglong)(auStack_98._0_8_ + (-8 - (longlong)puVar13)))) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        uVar5 = (*pcVar2)();
        return uVar5;
      }
      func_0x000180127e40(puVar13);
    }
    uVar5 = 1;
  }
  return uVar5;
LAB_1800a9f60:
  recovered_1800694f0(param_5);
  lVar10 = lVar10 + (int)uVar11 + uVar6;
  uVar9 = 0;
  if (uStackX_8 - lVar10 == uVar6) goto LAB_1800a9fd7;
  while( true ) {
    uVar11 = 0;
    if (uVar6 != 0) {
      pcVar8 = param_4;
      do {
        if ((pcVar8[((lVar10 + lVar7) - (longlong)param_4) + uVar9] != *pcVar8) && (*pcVar8 != '?'))
        goto LAB_1800a9fc4;
        uVar11 = uVar11 + 1;
        pcVar8 = pcVar8 + 1;
      } while (uVar11 < uVar6);
    }
    if (uVar11 == uVar6) break;
LAB_1800a9fc4:
    uVar9 = uVar9 + 1;
    if ((uStackX_8 - lVar10) - uVar6 <= uVar9) goto LAB_1800a9fd7;
  }
  uVar11 = uVar9 & 0xffffffff;
  if ((int)uVar9 == -1) goto LAB_1800a9fd7;
  goto LAB_1800a9f60;
}

