/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800736cb(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  char cVar8;
  longlong *unaff_RBX;
  undefined4 unaff_EBP;
  longlong *unaff_RSI;
  longlong *plVar9;
  longlong unaff_R14;
  double dVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  float unaff_XMM8_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  int in_stack_00000120;
  float fStack0000000000000128;
  float fStack000000000000012c;
  
  fVar5 = _DAT_181b2beb8;
  fVar4 = _DAT_181b2beb4;
  fVar3 = _DAT_181b2beb0;
  iVar2 = _DAT_181b2b40c;
  cVar8 = DAT_181b2b406;
  fVar1 = _DAT_181a03230;
  do {
    if ((*(char *)((longlong)unaff_RBX + 0x1a) == '\0') &&
       ((cVar8 == '\0' || (*(char *)((longlong)unaff_RBX + 0x1b) == '\0')))) {
      plVar9 = unaff_RBX + 0x14;
      recovered_180067e80(&stack0x00000128,&DAT_181b2be70,plVar9,unaff_EBP);
      fVar7 = fStack000000000000012c;
      fVar6 = fStack0000000000000128;
      if ((fVar1 <= fStack0000000000000128) && (fVar1 <= fStack000000000000012c)) {
        fVar12 = fVar3 - (float)*plVar9;
        fVar13 = fVar4 - (float)((ulonglong)*plVar9 >> 0x20);
        fVar12 = fVar13 * fVar13 + fVar12 * fVar12 +
                 (fVar5 - *(float *)(plVar9 + 1)) * (fVar5 - *(float *)(plVar9 + 1));
        if (fVar12 < 0.0) {
          fVar12 = (float)func_0x0001801cb525(fVar12);
        }
        else {
          fVar12 = SQRT(fVar12);
        }
        if (fVar12 <= (float)iVar2) {
          dVar10 = (double)func_0x0001801cb507((double)(fVar7 - unaff_XMM11_Da));
          dVar11 = (double)func_0x0001801cb507((double)(fVar6 - unaff_XMM10_Da));
          dVar10 = dVar10 + dVar11;
          if (dVar10 < 0.0) {
            dVar10 = (double)func_0x0001801cb51f(dVar10);
          }
          else {
            dVar10 = SQRT(dVar10);
          }
          if ((float)dVar10 < unaff_XMM8_Da) {
            unaff_RSI = unaff_RBX + 3;
            unaff_XMM8_Da = (float)dVar10;
          }
        }
      }
    }
    unaff_RBX = (longlong *)*unaff_RBX;
  } while (unaff_RBX != (longlong *)unaff_R14);
  if ((unaff_RSI != (longlong *)0x0) && (*(uint *)((longlong)unaff_RSI + 0x84) != 0)) {
    in_stack_00000120 =
         recovered_180069360((ulonglong)*(uint *)((longlong)unaff_RSI + 0x84) + 0x4e8);
    if (in_stack_00000120 != 0) {
      cVar8 = recovered_180067cc0((ulonglong)*(uint *)((longlong)unaff_RSI + 0x84) + 0x54,
                                  &stack0x00000128);
      if (cVar8 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStack000000000000012c,fStack0000000000000128),
                          &stack0x00000120,4);
      }
    }
  }
  return;
}

