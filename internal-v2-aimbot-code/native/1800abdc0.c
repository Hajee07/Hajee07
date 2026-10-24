/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_1800abdc0(undefined4 param_1,undefined param_2,undefined8 param_3,longlong param_4,
                        longlong param_5)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uStack_c8;
  int iStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined uStack_b4;
  undefined8 uStack_b0;
  longlong alStack_a8 [7];
  longlong *plStack_70;
  longlong alStack_68 [7];
  longlong *plStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  plStack_70 = (longlong *)0x0;
  puVar1 = *(undefined8 **)(param_4 + 0x38);
  uStack_b8 = param_1;
  uStack_b4 = param_2;
  uStack_b0 = param_3;
  if (puVar1 != (undefined8 *)0x0) {
    plStack_70 = (longlong *)(**(code **)*puVar1)(puVar1,alStack_a8);
  }
  plStack_30 = (longlong *)0x0;
  puVar1 = *(undefined8 **)(param_5 + 0x38);
  if (puVar1 != (undefined8 *)0x0) {
    plStack_30 = (longlong *)(**(code **)*puVar1)(puVar1,alStack_68);
  }
  puVar4 = (undefined4 *)func_0x000180127a94(0x90);
  *puVar4 = uStack_b8;
  *(undefined *)(puVar4 + 1) = uStack_b4;
  *(undefined8 *)(puVar4 + 2) = uStack_b0;
  *(undefined8 *)(puVar4 + 0x12) = 0;
  if (plStack_70 != (longlong *)0x0) {
    uVar5 = (**(code **)*plStack_70)(plStack_70,puVar4 + 4);
    *(undefined8 *)(puVar4 + 0x12) = uVar5;
  }
  *(undefined8 *)(puVar4 + 0x22) = 0;
  if (plStack_30 != (longlong *)0x0) {
    uVar5 = (**(code **)*plStack_30)(plStack_30,puVar4 + 0x14);
    *(undefined8 *)(puVar4 + 0x22) = uVar5;
  }
  lVar6 = _beginthreadex(0,0,&DAT_1800b9aa0,puVar4,0,&iStack_c0);
  uStack_bc = (undefined4)((ulonglong)uStack_c8 >> 0x20);
  if (lVar6 != 0) {
    iStack_c0 = (int)uStack_c8;
    if (iStack_c0 != 0) {
      uStack_c8._0_4_ = (undefined4)lVar6;
      uStack_c8._4_4_ = (undefined4)((ulonglong)lVar6 >> 0x20);
      uStack_28 = (undefined4)uStack_c8;
      uStack_24 = uStack_c8._4_4_;
      iStack_20 = iStack_c0;
      uStack_1c = uStack_bc;
      iVar3 = _Thrd_detach(&uStack_28);
      if (iVar3 == 0) {
        if (plStack_30 != (longlong *)0x0) {
          (**(code **)(*plStack_30 + 0x20))(plStack_30,plStack_30 != alStack_68);
          plStack_30 = (longlong *)0x0;
        }
        if (plStack_70 != (longlong *)0x0) {
          (**(code **)(*plStack_70 + 0x20))(plStack_70,plStack_70 != alStack_a8);
        }
        return;
      }
    }
    __Throw_Cpp_error_std__YAXH_Z(1);
  }
  __Throw_Cpp_error_std__YAXH_Z(6);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

