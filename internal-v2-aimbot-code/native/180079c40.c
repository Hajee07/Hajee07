/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


undefined (*) [16]
recovered_180079c40(undefined (*param_1) [16],undefined8 param_2,undefined8 *param_3,
                   undefined8 *param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined (*pauVar10) [16];
  ulonglong uVar11;
  
  *param_1 = ZEXT816(0);
  *(undefined8 *)param_1[1] = 0;
  *(undefined8 *)(param_1[1] + 8) = 0;
  uVar2 = param_3[2];
  uVar3 = param_4[2];
  uVar1 = uVar3 + uVar2;
  if ((param_3[3] - uVar2 < uVar3) || ((ulonglong)param_3[3] < (ulonglong)param_4[3])) {
    if (param_4[3] - uVar3 < uVar2) {
      if (0x7fffffffffffffff - uVar2 < uVar3) {
        func_0x000180052a50();
        pcVar4 = (code *)swi(3);
        pauVar10 = (undefined (*) [16])(*pcVar4)();
        return pauVar10;
      }
      uVar8 = uVar1 | 0xf;
      uVar11 = 0x7fffffffffffffff;
      if ((uVar8 < 0x8000000000000000) && (uVar11 = uVar8, uVar8 < 0x16)) {
        uVar11 = 0x16;
      }
      lVar9 = func_0x000180024110(uVar11 + 1);
      *(longlong *)*param_1 = lVar9;
      *(ulonglong *)param_1[1] = uVar1;
      *(ulonglong *)(param_1[1] + 8) = uVar11;
      if (0xf < (ulonglong)param_3[3]) {
        param_3 = (undefined8 *)*param_3;
      }
      func_0x0001801ca88d(lVar9,param_3,uVar2);
      if (0xf < (ulonglong)param_4[3]) {
        param_4 = (undefined8 *)*param_4;
      }
      func_0x0001801ca88d(lVar9 + uVar2,param_4,uVar3 + 1);
    }
    else {
      uVar5 = *(undefined4 *)((longlong)param_4 + 4);
      uVar6 = *(undefined4 *)(param_4 + 1);
      uVar7 = *(undefined4 *)((longlong)param_4 + 0xc);
      *(undefined4 *)*param_1 = *(undefined4 *)param_4;
      *(undefined4 *)(*param_1 + 4) = uVar5;
      *(undefined4 *)(*param_1 + 8) = uVar6;
      *(undefined4 *)(*param_1 + 0xc) = uVar7;
      uVar5 = *(undefined4 *)((longlong)param_4 + 0x14);
      uVar6 = *(undefined4 *)(param_4 + 3);
      uVar7 = *(undefined4 *)((longlong)param_4 + 0x1c);
      *(undefined4 *)param_1[1] = *(undefined4 *)(param_4 + 2);
      *(undefined4 *)(param_1[1] + 4) = uVar5;
      *(undefined4 *)(param_1[1] + 8) = uVar6;
      *(undefined4 *)(param_1[1] + 0xc) = uVar7;
      param_4[2] = 0;
      *(undefined *)param_4 = 0;
      param_4[3] = 0xf;
      lVar9 = *(longlong *)*param_1;
      func_0x0001801ca893(lVar9 + uVar2,lVar9,uVar3 + 1);
      if (0xf < (ulonglong)param_3[3]) {
        param_3 = (undefined8 *)*param_3;
      }
      func_0x0001801ca88d(lVar9,param_3,uVar2);
      *(ulonglong *)param_1[1] = uVar1;
    }
  }
  else {
    uVar5 = *(undefined4 *)((longlong)param_3 + 4);
    uVar6 = *(undefined4 *)(param_3 + 1);
    uVar7 = *(undefined4 *)((longlong)param_3 + 0xc);
    *(undefined4 *)*param_1 = *(undefined4 *)param_3;
    *(undefined4 *)(*param_1 + 4) = uVar5;
    *(undefined4 *)(*param_1 + 8) = uVar6;
    *(undefined4 *)(*param_1 + 0xc) = uVar7;
    uVar5 = *(undefined4 *)((longlong)param_3 + 0x14);
    uVar6 = *(undefined4 *)(param_3 + 3);
    uVar7 = *(undefined4 *)((longlong)param_3 + 0x1c);
    *(undefined4 *)param_1[1] = *(undefined4 *)(param_3 + 2);
    *(undefined4 *)(param_1[1] + 4) = uVar5;
    *(undefined4 *)(param_1[1] + 8) = uVar6;
    *(undefined4 *)(param_1[1] + 0xc) = uVar7;
    param_3[2] = 0;
    param_3[3] = 0xf;
    *(undefined *)param_3 = 0;
    pauVar10 = param_1;
    if (0xf < *(ulonglong *)(param_1[1] + 8)) {
      pauVar10 = *(undefined (**) [16])*param_1;
    }
    if (0xf < (ulonglong)param_4[3]) {
      param_4 = (undefined8 *)*param_4;
    }
    func_0x0001801ca88d(*pauVar10 + uVar2,param_4,uVar3 + 1);
    *(ulonglong *)param_1[1] = uVar1;
  }
  return param_1;
}

