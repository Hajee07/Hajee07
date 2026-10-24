/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_180078290(longlong param_1)

{
  longlong **pplVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong **pplVar4;
  undefined8 *puVar5;
  longlong **in_RAX;
  longlong **pplVar6;
  longlong **pplVar7;
  longlong **pplVar8;
  longlong **pplVar9;
  longlong **pplVar10;
  longlong **pplVar11;
  longlong **pplVar12;
  
  if (*(ulonglong *)(param_1 + 0x10) != 0) {
    pplVar1 = *(longlong ***)(param_1 + 8);
    if (*(ulonglong *)(param_1 + 0x10) < *(ulonglong *)(param_1 + 0x38) >> 3) {
      pplVar11 = (longlong **)*pplVar1;
      if (pplVar11 == pplVar1) {
        return pplVar1;
      }
      lVar3 = *(longlong *)(param_1 + 0x18);
      pplVar4 = *(longlong ***)(param_1 + 8);
      pplVar12 = (longlong **)pplVar11[1];
      pplVar6 = (longlong **)
                ((((ulonglong)*(byte *)((longlong)pplVar11 + 0x13) ^
                  ((((ulonglong)*(byte *)(pplVar11 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                   (ulonglong)*(byte *)((longlong)pplVar11 + 0x11)) * 0x100000001b3 ^
                  (ulonglong)*(byte *)((longlong)pplVar11 + 0x12)) * 0x100000001b3) * 0x100000001b3
                 & *(ulonglong *)(param_1 + 0x30)) * 0x10 + lVar3);
      pplVar8 = (longlong **)*pplVar6;
      pplVar10 = (longlong **)pplVar6[1];
      pplVar7 = pplVar11;
      do {
        pplVar9 = (longlong **)*pplVar7;
        recovered_180066e40(pplVar7 + 0xf);
        recovered_180066e40(pplVar7 + 0xb);
        recovered_180066e40(pplVar7 + 7);
        func_0x000180127e40(pplVar7,400);
        *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
        if (pplVar7 == pplVar10) {
          pplVar10 = pplVar12;
          if (pplVar8 == pplVar11) {
            *pplVar6 = (longlong *)pplVar4;
            pplVar10 = pplVar4;
          }
          pplVar6[1] = (longlong *)pplVar10;
          while (pplVar9 != pplVar1) {
            pplVar10 = (longlong **)
                       (((((((ulonglong)*(byte *)(pplVar9 + 2) ^ 0xcbf29ce484222325) * 0x100000001b3
                           ^ (ulonglong)*(byte *)((longlong)pplVar9 + 0x11)) * 0x100000001b3 ^
                          (ulonglong)*(byte *)((longlong)pplVar9 + 0x12)) * 0x100000001b3 ^
                         (ulonglong)*(byte *)((longlong)pplVar9 + 0x13)) * 0x100000001b3 &
                        *(ulonglong *)(param_1 + 0x30)) * 0x10 + lVar3);
            pplVar11 = (longlong **)pplVar10[1];
            pplVar8 = pplVar9;
            while( true ) {
              pplVar9 = (longlong **)*pplVar8;
              recovered_180066e40(pplVar8 + 0xf);
              recovered_180066e40(pplVar8 + 0xb);
              recovered_180066e40(pplVar8 + 7);
              func_0x000180127e40(pplVar8,400);
              *(longlong *)(param_1 + 0x10) = *(longlong *)(param_1 + 0x10) + -1;
              if (pplVar8 == pplVar11) break;
              pplVar8 = pplVar9;
              if (pplVar9 == pplVar1) {
                *pplVar10 = (longlong *)pplVar9;
                goto LAB_180079a66;
              }
            }
            *pplVar10 = (longlong *)pplVar4;
            pplVar10[1] = (longlong *)pplVar4;
          }
          goto LAB_180079a66;
        }
        pplVar7 = pplVar9;
      } while (pplVar9 != pplVar1);
      if (pplVar8 == pplVar11) {
        *pplVar6 = (longlong *)pplVar9;
      }
LAB_180079a66:
      *pplVar12 = (longlong *)pplVar9;
      pplVar9[1] = (longlong *)pplVar12;
      return pplVar1;
    }
    *pplVar1[1] = 0;
    puVar5 = *pplVar1;
    while (puVar5 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*puVar5;
      recovered_180066e40(puVar5 + 0xf);
      recovered_180066e40(puVar5 + 0xb);
      recovered_180066e40(puVar5 + 7);
      func_0x000180127e40(puVar5,400);
      puVar5 = puVar2;
    }
    *(undefined8 *)*(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + 8);
    *(longlong *)(*(longlong *)(param_1 + 8) + 8) = *(longlong *)(param_1 + 8);
    *(undefined8 *)(param_1 + 0x10) = 0;
    in_RAX = (longlong **)
             recovered_180067850(*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x20),
                                 &stack0x00000008);
  }
  return in_RAX;
}

