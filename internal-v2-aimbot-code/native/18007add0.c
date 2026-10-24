/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_18007add0(longlong param_1,ulonglong param_2)

{
  longlong **pplVar1;
  longlong **pplVar2;
  longlong **pplVar3;
  longlong *plVar4;
  longlong **pplVar5;
  longlong *plVar6;
  longlong *plVar7;
  code *pcVar8;
  longlong **pplVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong **pplVar12;
  
  for (lVar11 = 0x3f; 0xfffffffffffffffU >> lVar11 == 0; lVar11 = lVar11 + -1) {
  }
  if ((ulonglong)(1L << ((byte)lVar11 & 0x3f)) < param_2) {
    __Xlength_error_std__YAXPEBD_Z(&UNK_1819d7808);
    pcVar8 = (code *)swi(3);
    (*pcVar8)();
    return;
  }
  pplVar1 = *(longlong ***)(param_1 + 8);
  uVar10 = param_2 - 1 | 1;
  lVar11 = 0x3f;
  if (uVar10 != 0) {
    for (; uVar10 >> lVar11 == 0; lVar11 = lVar11 + -1) {
    }
  }
  lVar11 = 1L << ((char)lVar11 + 1U & 0x3f);
  func_0x0001800674b0(param_1 + 0x18,lVar11 * 2,pplVar1);
  *(longlong *)(param_1 + 0x38) = lVar11;
  *(longlong *)(param_1 + 0x30) = lVar11 + -1;
  pplVar9 = (longlong **)**(undefined8 **)(param_1 + 8);
joined_r0x00018007ae4f:
  do {
    while( true ) {
      while( true ) {
        if (pplVar9 == pplVar1) {
          return;
        }
        pplVar2 = (longlong **)*pplVar9;
        pplVar12 = (longlong **)
                   (((((((ulonglong)*(byte *)(pplVar9 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                       (ulonglong)*(byte *)((longlong)pplVar9 + 0x11)) * 0x100000001b3 ^
                      (ulonglong)*(byte *)((longlong)pplVar9 + 0x12)) * 0x100000001b3 ^
                     (ulonglong)*(byte *)((longlong)pplVar9 + 0x13)) * 0x100000001b3 &
                    *(ulonglong *)(param_1 + 0x30)) * 0x10 + *(longlong *)(param_1 + 0x18));
        if ((longlong **)*pplVar12 != pplVar1) break;
        *pplVar12 = (longlong *)pplVar9;
        pplVar12[1] = (longlong *)pplVar9;
        pplVar9 = pplVar2;
      }
      pplVar3 = (longlong **)pplVar12[1];
      if (*(int *)(pplVar9 + 2) != *(int *)(pplVar3 + 2)) break;
      pplVar3 = (longlong **)*pplVar3;
      if (pplVar3 != pplVar9) {
        plVar4 = pplVar9[1];
        *plVar4 = (longlong)pplVar2;
        pplVar5 = (longlong **)pplVar2[1];
        *pplVar5 = (longlong *)pplVar3;
        plVar6 = pplVar3[1];
        *plVar6 = (longlong)pplVar9;
        pplVar3[1] = (longlong *)pplVar5;
        pplVar2[1] = plVar4;
        pplVar9[1] = plVar6;
      }
      pplVar12[1] = (longlong *)pplVar9;
      pplVar9 = pplVar2;
    }
    do {
      if ((longlong **)*pplVar12 == pplVar3) {
        plVar4 = pplVar9[1];
        *plVar4 = (longlong)pplVar2;
        pplVar5 = (longlong **)pplVar2[1];
        *pplVar5 = (longlong *)pplVar3;
        plVar6 = pplVar3[1];
        *plVar6 = (longlong)pplVar9;
        pplVar3[1] = (longlong *)pplVar5;
        pplVar2[1] = plVar4;
        pplVar9[1] = plVar6;
        *pplVar12 = (longlong *)pplVar9;
        pplVar9 = pplVar2;
        goto joined_r0x00018007ae4f;
      }
      pplVar3 = (longlong **)pplVar3[1];
    } while (*(int *)(pplVar9 + 2) != *(int *)(pplVar3 + 2));
    plVar4 = *pplVar3;
    plVar6 = pplVar9[1];
    *plVar6 = (longlong)pplVar2;
    pplVar12 = (longlong **)pplVar2[1];
    *pplVar12 = plVar4;
    plVar7 = (longlong *)plVar4[1];
    *plVar7 = (longlong)pplVar9;
    plVar4[1] = (longlong)pplVar12;
    pplVar2[1] = plVar6;
    pplVar9[1] = plVar7;
    pplVar9 = pplVar2;
  } while( true );
}

