/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_18006b9b0(undefined (*param_1) [16],longlong param_2,ulonglong param_3)

{
  longlong lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined (*pauVar7) [16];
  uint auStackX_10 [2];
  ulonglong uStackX_18;
  ulonglong *puStackX_20;
  ulonglong uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined auStack_48 [32];
  
  auStackX_10[0] = 0;
  uStackX_18 = param_3;
  cVar3 = recovered_180067cc0(param_2 + 0x31c,&uStackX_18);
  if (((cVar3 == '\0') ||
      (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_18,auStackX_10,4), iVar4 != 0)) ||
     (uStack_70 = (ulonglong)auStackX_10[0], auStackX_10[0] == 0)) {
LAB_18006bd18:
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0xf;
    (*param_1)[0] = 0;
    return param_1;
  }
  uStackX_18 = uStackX_18 & 0xffffffff00000000;
  cVar3 = recovered_180067cc0((ulonglong)auStackX_10[0] + 8,&puStackX_20);
  if (((cVar3 == '\0') ||
      (iVar4 = (*_DAT_181b4ef88)(_DAT_181b4ef90,puStackX_20,&uStackX_18,4), iVar4 != 0)) ||
     (0x3f < (int)uStackX_18 - 1U)) goto LAB_18006bd18;
  puStackX_20 = &uStack_70;
  func_0x00018006b850(&puStackX_20,&uStack_68,(int)uStackX_18 * 5);
  if (uStack_58 == 0) {
LAB_18006bb20:
    puVar6 = (undefined4 *)func_0x00018006b850(&puStackX_20,auStack_48,(int)uStackX_18 * 2 + 2);
    if (&uStack_68 != puVar6) {
      if (0xf < uStack_50) {
        if ((0xfff < uStack_50 + 1) &&
           (0x1f < (CONCAT44(uStack_64,uStack_68) -
                   *(longlong *)(CONCAT44(uStack_64,uStack_68) + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar2 = (code *)swi(3);
          pauVar7 = (undefined (*) [16])(*pcVar2)();
          return pauVar7;
        }
        func_0x000180127e40();
      }
      uStack_68 = *puVar6;
      uStack_64 = puVar6[1];
      uStack_60 = puVar6[2];
      uStack_5c = puVar6[3];
      uStack_58 = *(ulonglong *)(puVar6 + 4);
      uStack_50 = *(ulonglong *)(puVar6 + 6);
      *(undefined8 *)(puVar6 + 4) = 0;
      *(undefined8 *)(puVar6 + 6) = 0xf;
      *(undefined *)puVar6 = 0;
    }
    recovered_180066e40(auStack_48);
LAB_18006bbcd:
    if (uStack_58 != 0) {
      puVar6 = &uStack_68;
      if (0xf < uStack_50) {
        puVar6 = (undefined4 *)CONCAT44(uStack_64,uStack_68);
      }
      if (((uStack_58 == 0) ||
          (lVar1 = uStack_58 + (longlong)puVar6, lVar5 = func_0x000180127880(puVar6,lVar1,0xef),
          lVar5 == lVar1)) || (lVar5 - (longlong)puVar6 == -1)) goto LAB_18006bd07;
      puVar6 = &uStack_68;
      if (0xf < uStack_50) {
        puVar6 = (undefined4 *)CONCAT44(uStack_64,uStack_68);
      }
      if (((uStack_58 < 3) ||
          (lVar1 = (longlong)puVar6 + uStack_58,
          lVar5 = func_0x0001801278a0(puVar6,lVar1,&UNK_1819d7824,3), lVar5 == lVar1)) ||
         (lVar5 - (longlong)puVar6 == -1)) goto LAB_18006bd07;
    }
  }
  else {
    puVar6 = &uStack_68;
    if (0xf < uStack_50) {
      puVar6 = (undefined4 *)CONCAT44(uStack_64,uStack_68);
    }
    if (uStack_58 != 0) {
      lVar1 = uStack_58 + (longlong)puVar6;
      lVar5 = func_0x000180127880(puVar6,lVar1,0xef);
      if ((lVar5 != lVar1) && (lVar5 - (longlong)puVar6 != -1)) {
        puVar6 = &uStack_68;
        if (0xf < uStack_50) {
          puVar6 = (undefined4 *)CONCAT44(uStack_64,uStack_68);
        }
        if (((2 < uStack_58) &&
            (lVar1 = uStack_58 + (longlong)puVar6,
            lVar5 = func_0x0001801278a0(puVar6,lVar1,&UNK_1819d7824,3), lVar5 != lVar1)) &&
           (lVar5 - (longlong)puVar6 != -1)) goto LAB_18006bb20;
      }
      goto LAB_18006bbcd;
    }
  }
  puVar6 = (undefined4 *)func_0x00018006b850(&puStackX_20,auStack_48,(int)uStackX_18 * 2);
  if (&uStack_68 != puVar6) {
    if (0xf < uStack_50) {
      if ((0xfff < uStack_50 + 1) &&
         (0x1f < (CONCAT44(uStack_64,uStack_68) - *(longlong *)(CONCAT44(uStack_64,uStack_68) + -8))
                 - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        pauVar7 = (undefined (*) [16])(*pcVar2)();
        return pauVar7;
      }
      func_0x000180127e40();
    }
    uStack_68 = *puVar6;
    uStack_64 = puVar6[1];
    uStack_60 = puVar6[2];
    uStack_5c = puVar6[3];
    uStack_58 = *(ulonglong *)(puVar6 + 4);
    uStack_50 = *(ulonglong *)(puVar6 + 6);
    *(undefined8 *)(puVar6 + 4) = 0;
    *(undefined8 *)(puVar6 + 6) = 0xf;
    *(undefined *)puVar6 = 0;
  }
  recovered_180066e40(auStack_48);
LAB_18006bd07:
  *(undefined4 *)*param_1 = uStack_68;
  *(undefined4 *)(*param_1 + 4) = uStack_64;
  *(undefined4 *)(*param_1 + 8) = uStack_60;
  *(undefined4 *)(*param_1 + 0xc) = uStack_5c;
  *(undefined4 *)param_1[1] = (undefined4)uStack_58;
  *(undefined4 *)(param_1[1] + 4) = uStack_58._4_4_;
  *(undefined4 *)(param_1[1] + 8) = (undefined4)uStack_50;
  *(undefined4 *)(param_1[1] + 0xc) = uStack_50._4_4_;
  return param_1;
}

