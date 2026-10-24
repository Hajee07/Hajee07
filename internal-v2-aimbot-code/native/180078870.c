/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong * recovered_180078870(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 uVar6;
  longlong lVar7;
  
  uVar6 = 0;
  uVar4 = *(ulonglong *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1);
  if (((longlong)uVar4 < 1) || (uVar4 <= param_3)) {
    lVar7 = 0;
  }
  else {
    lVar7 = uVar4 - param_3;
  }
  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  cVar2 = _good_ios_base_std__QEBA_NXZ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1);
  if (cVar2 == '\0') {
    cVar2 = '\0';
  }
  else {
    plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x50 + (longlong)param_1);
    if ((plVar1 == (longlong *)0x0) || (plVar1 == param_1)) {
      cVar2 = '\x01';
    }
    else {
      _flush___basic_ostream_DU__char_traits_D_std___std__QEAAAEAV12_XZ();
      cVar2 = _good_ios_base_std__QEBA_NXZ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1);
    }
  }
  if (cVar2 == '\0') {
    uVar6 = 4;
  }
  else {
    lVar5 = *param_1;
    if ((*(uint *)((longlong)*(int *)(lVar5 + 4) + 0x18 + (longlong)param_1) & 0x1c0) != 0x40) {
      for (; lVar7 != 0; lVar7 = lVar7 + -1) {
        iVar3 = _sputc___basic_streambuf_DU__char_traits_D_std___std__QEAAHD_Z
                          (*(undefined8 *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(undefined *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) {
          uVar6 = 4;
          goto LAB_180078970;
        }
      }
      lVar5 = *param_1;
    }
    uVar4 = _sputn___basic_streambuf_DU__char_traits_D_std___std__QEAA_JPEBD_J_Z
                      (*(undefined8 *)((longlong)*(int *)(lVar5 + 4) + 0x48 + (longlong)param_1),
                       param_2,param_3);
    if (uVar4 == param_3) {
LAB_180078970:
      do {
        if (lVar7 == 0) goto LAB_180078998;
        iVar3 = _sputc___basic_streambuf_DU__char_traits_D_std___std__QEAAHD_Z
                          (*(undefined8 *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(undefined *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) break;
        lVar7 = lVar7 + -1;
      } while( true );
    }
    uVar6 = 4;
LAB_180078998:
    *(undefined8 *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1) = 0;
  }
  _setstate___basic_ios_DU__char_traits_D_std___std__QEAAXH_N_Z
            ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1,uVar6,0);
  cVar2 = _uncaught_exception_std__YA_NXZ();
  if (cVar2 == '\0') {
    __Osfx___basic_ostream_DU__char_traits_D_std___std__QEAAXXZ(param_1);
  }
  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))();
  }
  return param_1;
}

