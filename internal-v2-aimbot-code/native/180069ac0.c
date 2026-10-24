/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong *
recovered_180069ac0(longlong *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined4 uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  
  uVar5 = 0;
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while (*(char *)(param_2 + lVar7) != '\0');
  lVar6 = *(longlong *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1);
  if ((lVar6 < 1) || (lVar6 <= lVar7)) {
    lVar6 = 0;
  }
  else {
    lVar6 = lVar6 - lVar7;
  }
  plVar1 = *(longlong **)((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1);
  plVar8 = param_1;
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
    uVar5 = 4;
  }
  else {
    lVar4 = *param_1;
    if ((*(uint *)((longlong)*(int *)(lVar4 + 4) + 0x18 + (longlong)param_1) & 0x1c0) != 0x40) {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        iVar3 = _sputc___basic_streambuf_DU__char_traits_D_std___std__QEAAHD_Z
                          (*(undefined8 *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(undefined *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) goto LAB_180069c16;
      }
      lVar4 = *param_1;
    }
    lVar4 = _sputn___basic_streambuf_DU__char_traits_D_std___std__QEAA_JPEBD_J_Z
                      (*(undefined8 *)((longlong)*(int *)(lVar4 + 4) + 0x48 + (longlong)param_1),
                       param_2,lVar7,param_4,plVar8,cVar2);
    if (lVar4 == lVar7) {
      for (; 0 < lVar6; lVar6 = lVar6 + -1) {
        iVar3 = _sputc___basic_streambuf_DU__char_traits_D_std___std__QEAAHD_Z
                          (*(undefined8 *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x48 + (longlong)param_1),
                           *(undefined *)
                            ((longlong)*(int *)(*param_1 + 4) + 0x58 + (longlong)param_1));
        if (iVar3 == -1) goto LAB_180069c16;
      }
    }
    else {
LAB_180069c16:
      uVar5 = 4;
    }
    *(undefined8 *)((longlong)*(int *)(*param_1 + 4) + 0x28 + (longlong)param_1) = 0;
  }
  _setstate___basic_ios_DU__char_traits_D_std___std__QEAAXH_N_Z
            ((longlong)*(int *)(*param_1 + 4) + (longlong)param_1,uVar5,0);
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

