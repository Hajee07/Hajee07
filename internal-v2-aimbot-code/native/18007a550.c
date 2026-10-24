/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


longlong ** recovered_18007a550(longlong *param_1,longlong **param_2)

{
  char cVar1;
  undefined uVar2;
  longlong **pplVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong **pplVar6;
  longlong **pplVar7;
  longlong **pplVar8;
  longlong **pplVar9;
  longlong **pplVar10;
  
  pplVar7 = (longlong **)param_2[2];
  pplVar8 = param_2 + 2;
  if (*(char *)((longlong)pplVar7 + 0x19) == '\0') {
    cVar1 = *(char *)((longlong)*pplVar7 + 0x19);
    pplVar6 = pplVar7;
    pplVar3 = (longlong **)*pplVar7;
    while (cVar1 == '\0') {
      cVar1 = *(char *)((longlong)*pplVar3 + 0x19);
      pplVar6 = pplVar3;
      pplVar3 = (longlong **)*pplVar3;
    }
  }
  else {
    cVar1 = *(char *)((longlong)param_2[1] + 0x19);
    pplVar9 = (longlong **)param_2[1];
    pplVar3 = param_2;
    while ((pplVar6 = pplVar9, cVar1 == '\0' && (pplVar3 == (longlong **)pplVar6[2]))) {
      cVar1 = *(char *)((longlong)pplVar6[1] + 0x19);
      pplVar9 = (longlong **)pplVar6[1];
      pplVar3 = pplVar6;
    }
  }
  pplVar10 = param_2 + 1;
  pplVar3 = (longlong **)*param_2;
  pplVar9 = pplVar7;
  if (((*(char *)((longlong)pplVar3 + 0x19) == '\0') &&
      (pplVar9 = pplVar3, *(char *)((longlong)pplVar7 + 0x19) == '\0')) &&
     (pplVar9 = (longlong **)pplVar6[2], pplVar6 != param_2)) {
    pplVar3[1] = (longlong *)pplVar6;
    *pplVar6 = *param_2;
    pplVar7 = pplVar6;
    if (pplVar6 != (longlong **)*pplVar8) {
      pplVar7 = (longlong **)pplVar6[1];
      if (*(char *)((longlong)pplVar9 + 0x19) == '\0') {
        pplVar9[1] = (longlong *)pplVar7;
      }
      *pplVar7 = (longlong *)pplVar9;
      pplVar6[2] = *pplVar8;
      (*pplVar8)[1] = (longlong)pplVar6;
    }
    if (*(longlong ***)(*param_1 + 8) == param_2) {
      *(longlong ***)(*param_1 + 8) = pplVar6;
    }
    else {
      pplVar8 = (longlong **)*pplVar10;
      if ((longlong **)*pplVar8 == param_2) {
        *pplVar8 = (longlong *)pplVar6;
      }
      else {
        pplVar8[2] = (longlong *)pplVar6;
      }
    }
    uVar2 = *(undefined *)(pplVar6 + 3);
    pplVar6[1] = *pplVar10;
    *(undefined *)(pplVar6 + 3) = *(undefined *)(param_2 + 3);
    *(undefined *)(param_2 + 3) = uVar2;
  }
  else {
    pplVar7 = (longlong **)*pplVar10;
    if (*(char *)((longlong)pplVar9 + 0x19) == '\0') {
      pplVar9[1] = (longlong *)pplVar7;
    }
    if (*(longlong ***)(*param_1 + 8) == param_2) {
      *(longlong ***)(*param_1 + 8) = pplVar9;
    }
    else if ((longlong **)*pplVar7 == param_2) {
      *pplVar7 = (longlong *)pplVar9;
    }
    else {
      pplVar7[2] = (longlong *)pplVar9;
    }
    if (*(longlong ***)(longlong **)*param_1 == param_2) {
      pplVar8 = pplVar7;
      if (*(char *)((longlong)pplVar9 + 0x19) == '\0') {
        cVar1 = *(char *)((longlong)*pplVar9 + 0x19);
        pplVar6 = (longlong **)*pplVar9;
        pplVar8 = pplVar9;
        while (pplVar3 = pplVar6, cVar1 == '\0') {
          pplVar6 = (longlong **)*pplVar3;
          cVar1 = *(char *)((longlong)pplVar6 + 0x19);
          pplVar8 = pplVar3;
        }
      }
      *(longlong **)*param_1 = (longlong *)pplVar8;
    }
    lVar4 = *param_1;
    if (*(longlong ***)(lVar4 + 0x10) == param_2) {
      if (*(char *)((longlong)pplVar9 + 0x19) == '\0') {
        cVar1 = *(char *)((longlong)pplVar9[2] + 0x19);
        pplVar8 = (longlong **)pplVar9[2];
        pplVar6 = pplVar9;
        while (pplVar3 = pplVar8, cVar1 == '\0') {
          pplVar8 = (longlong **)pplVar3[2];
          cVar1 = *(char *)((longlong)pplVar8 + 0x19);
          pplVar6 = pplVar3;
        }
        *(longlong ***)(lVar4 + 0x10) = pplVar6;
      }
      else {
        *(longlong ***)(lVar4 + 0x10) = pplVar7;
      }
    }
  }
  if (*(char *)(param_2 + 3) == '\x01') {
    if ((pplVar9 != *(longlong ***)(*param_1 + 8)) &&
       (pplVar8 = pplVar9, *(char *)(pplVar9 + 3) == '\x01')) {
      do {
        pplVar9 = pplVar7;
        pplVar7 = (longlong **)*pplVar9;
        if (pplVar8 == pplVar7) {
          pplVar7 = (longlong **)pplVar9[2];
          if (*(char *)(pplVar7 + 3) == '\0') {
            *(undefined *)(pplVar7 + 3) = 1;
            pplVar7 = (longlong **)pplVar9[2];
            *(undefined *)(pplVar9 + 3) = 0;
            pplVar9[2] = *pplVar7;
            if (*(char *)((longlong)*pplVar7 + 0x19) == '\0') {
              (*pplVar7)[1] = (longlong)pplVar9;
            }
            pplVar6 = pplVar9 + 1;
            pplVar7[1] = pplVar9[1];
            if (pplVar9 == *(longlong ***)(*param_1 + 8)) {
              *(longlong ***)(*param_1 + 8) = pplVar7;
              *pplVar7 = (longlong *)pplVar9;
              *pplVar6 = (longlong *)pplVar7;
              pplVar7 = (longlong **)pplVar9[2];
            }
            else {
              pplVar3 = (longlong **)*pplVar6;
              if (pplVar9 == (longlong **)*pplVar3) {
                *pplVar3 = (longlong *)pplVar7;
                *pplVar7 = (longlong *)pplVar9;
                *pplVar6 = (longlong *)pplVar7;
                pplVar7 = (longlong **)pplVar9[2];
              }
              else {
                pplVar3[2] = (longlong *)pplVar7;
                *pplVar7 = (longlong *)pplVar9;
                *pplVar6 = (longlong *)pplVar7;
                pplVar7 = (longlong **)pplVar9[2];
              }
            }
          }
          if (*(char *)((longlong)pplVar7 + 0x19) == '\0') {
            if ((*(char *)(*pplVar7 + 3) != '\x01') || (*(char *)(pplVar7[2] + 3) != '\x01')) {
              if (*(char *)(pplVar7[2] + 3) == '\x01') {
                *(undefined *)(*pplVar7 + 3) = 1;
                plVar5 = *pplVar7;
                *(undefined *)(pplVar7 + 3) = 0;
                *pplVar7 = (longlong *)plVar5[2];
                if (*(char *)(plVar5[2] + 0x19) == '\0') {
                  *(longlong ***)(plVar5[2] + 8) = pplVar7;
                }
                plVar5[1] = (longlong)pplVar7[1];
                if (pplVar7 == *(longlong ***)(*param_1 + 8)) {
                  *(longlong **)(*param_1 + 8) = plVar5;
                }
                else {
                  pplVar6 = (longlong **)pplVar7[1];
                  if (pplVar7 == (longlong **)pplVar6[2]) {
                    pplVar6[2] = plVar5;
                  }
                  else {
                    *pplVar6 = plVar5;
                  }
                }
                plVar5[2] = (longlong)pplVar7;
                pplVar7[1] = plVar5;
                pplVar7 = (longlong **)pplVar9[2];
              }
              *(undefined *)(pplVar7 + 3) = *(undefined *)(pplVar9 + 3);
              *(undefined *)(pplVar9 + 3) = 1;
              *(undefined *)(pplVar7[2] + 3) = 1;
              pplVar7 = (longlong **)pplVar9[2];
              pplVar9[2] = *pplVar7;
              if (*(char *)((longlong)*pplVar7 + 0x19) == '\0') {
                (*pplVar7)[1] = (longlong)pplVar9;
              }
              pplVar7[1] = pplVar9[1];
              if (pplVar9 == *(longlong ***)(*param_1 + 8)) {
                *(longlong ***)(*param_1 + 8) = pplVar7;
                *pplVar7 = (longlong *)pplVar9;
              }
              else {
                pplVar6 = (longlong **)pplVar9[1];
                if (pplVar9 == (longlong **)*pplVar6) {
                  *pplVar6 = (longlong *)pplVar7;
                  *pplVar7 = (longlong *)pplVar9;
                }
                else {
                  pplVar6[2] = (longlong *)pplVar7;
                  *pplVar7 = (longlong *)pplVar9;
                }
              }
LAB_18007aa1a:
              pplVar9[1] = (longlong *)pplVar7;
              pplVar9 = pplVar8;
              break;
            }
LAB_18007a8b0:
            *(undefined *)(pplVar7 + 3) = 0;
          }
        }
        else {
          if (*(char *)(pplVar7 + 3) == '\0') {
            *(undefined *)(pplVar7 + 3) = 1;
            plVar5 = *pplVar9;
            *(undefined *)(pplVar9 + 3) = 0;
            *pplVar9 = (longlong *)plVar5[2];
            if (*(char *)(plVar5[2] + 0x19) == '\0') {
              *(longlong ***)(plVar5[2] + 8) = pplVar9;
            }
            pplVar7 = pplVar9 + 1;
            plVar5[1] = (longlong)pplVar9[1];
            if (pplVar9 == *(longlong ***)(*param_1 + 8)) {
              *(longlong **)(*param_1 + 8) = plVar5;
              plVar5[2] = (longlong)pplVar9;
              *pplVar7 = plVar5;
              pplVar7 = (longlong **)*pplVar9;
            }
            else {
              pplVar6 = (longlong **)*pplVar7;
              if (pplVar9 == (longlong **)pplVar6[2]) {
                pplVar6[2] = plVar5;
                plVar5[2] = (longlong)pplVar9;
                *pplVar7 = plVar5;
                pplVar7 = (longlong **)*pplVar9;
              }
              else {
                *pplVar6 = plVar5;
                plVar5[2] = (longlong)pplVar9;
                *pplVar7 = plVar5;
                pplVar7 = (longlong **)*pplVar9;
              }
            }
          }
          if (*(char *)((longlong)pplVar7 + 0x19) == '\0') {
            if ((*(char *)(pplVar7[2] + 3) != '\x01') || (*(char *)(*pplVar7 + 3) != '\x01')) {
              if (*(char *)(*pplVar7 + 3) == '\x01') {
                *(undefined *)(pplVar7[2] + 3) = 1;
                pplVar6 = (longlong **)pplVar7[2];
                *(undefined *)(pplVar7 + 3) = 0;
                pplVar7[2] = *pplVar6;
                if (*(char *)((longlong)*pplVar6 + 0x19) == '\0') {
                  (*pplVar6)[1] = (longlong)pplVar7;
                }
                pplVar6[1] = pplVar7[1];
                if (pplVar7 == *(longlong ***)(*param_1 + 8)) {
                  *(longlong ***)(*param_1 + 8) = pplVar6;
                }
                else {
                  pplVar3 = (longlong **)pplVar7[1];
                  if (pplVar7 == (longlong **)*pplVar3) {
                    *pplVar3 = (longlong *)pplVar6;
                  }
                  else {
                    pplVar3[2] = (longlong *)pplVar6;
                  }
                }
                *pplVar6 = (longlong *)pplVar7;
                pplVar7[1] = (longlong *)pplVar6;
                pplVar7 = (longlong **)*pplVar9;
              }
              *(undefined *)(pplVar7 + 3) = *(undefined *)(pplVar9 + 3);
              *(undefined *)(pplVar9 + 3) = 1;
              *(undefined *)(*pplVar7 + 3) = 1;
              pplVar7 = (longlong **)*pplVar9;
              *pplVar9 = pplVar7[2];
              if (*(char *)((longlong)pplVar7[2] + 0x19) == '\0') {
                pplVar7[2][1] = (longlong)pplVar9;
              }
              pplVar7[1] = pplVar9[1];
              if (pplVar9 == *(longlong ***)(*param_1 + 8)) {
                *(longlong ***)(*param_1 + 8) = pplVar7;
              }
              else {
                pplVar6 = (longlong **)pplVar9[1];
                if (pplVar9 == (longlong **)pplVar6[2]) {
                  pplVar6[2] = (longlong *)pplVar7;
                }
                else {
                  *pplVar6 = (longlong *)pplVar7;
                }
              }
              pplVar7[2] = (longlong *)pplVar9;
              goto LAB_18007aa1a;
            }
            goto LAB_18007a8b0;
          }
        }
        if ((pplVar9 == *(longlong ***)(*param_1 + 8)) ||
           (pplVar7 = (longlong **)pplVar9[1], pplVar8 = pplVar9, *(char *)(pplVar9 + 3) != '\x01'))
        break;
      } while( true );
    }
    *(undefined *)(pplVar9 + 3) = 1;
  }
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
  }
  return param_2;
}

