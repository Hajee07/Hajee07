/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong * recovered_1800785e0(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  longlong *plVar6;
  longlong lVar7;
  
  if (param_1 != param_2) {
    if (0xf < (ulonglong)param_1[3]) {
      lVar1 = *param_1;
      lVar7 = lVar1;
      if ((0xfff < param_1[3] + 1U) &&
         (lVar7 = *(longlong *)(lVar1 + -8), 0x1f < (lVar1 - lVar7) - 8U)) {
        _invoke_watson(0,0,0,0,0);
        pcVar2 = (code *)swi(3);
        plVar6 = (longlong *)(*pcVar2)();
        return plVar6;
      }
      func_0x000180127e40(lVar7);
    }
    param_1[3] = 0xf;
    param_1[2] = 0;
    *(undefined *)param_1 = 0;
    uVar3 = *(undefined4 *)((longlong)param_2 + 4);
    uVar4 = *(undefined4 *)(param_2 + 1);
    uVar5 = *(undefined4 *)((longlong)param_2 + 0xc);
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    *(undefined4 *)((longlong)param_1 + 4) = uVar3;
    *(undefined4 *)(param_1 + 1) = uVar4;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar5;
    uVar3 = *(undefined4 *)((longlong)param_2 + 0x14);
    uVar4 = *(undefined4 *)(param_2 + 3);
    uVar5 = *(undefined4 *)((longlong)param_2 + 0x1c);
    *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + 2);
    *(undefined4 *)((longlong)param_1 + 0x14) = uVar3;
    *(undefined4 *)(param_1 + 3) = uVar4;
    *(undefined4 *)((longlong)param_1 + 0x1c) = uVar5;
    param_2[2] = 0;
    param_2[3] = 0xf;
    *(undefined *)param_2 = 0;
  }
  return param_1;
}

