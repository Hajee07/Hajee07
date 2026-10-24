/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18007326a(void)

{
  float fVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  longlong *unaff_RBX;
  undefined4 unaff_EBP;
  longlong *unaff_RSI;
  longlong *plVar8;
  longlong unaff_R14;
  float fVar9;
  double dVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float unaff_XMM8_Da;
  float unaff_XMM10_Da;
  float unaff_XMM11_Da;
  undefined4 in_stack_00000030;
  undefined8 uStack0000000000000034;
  longlong in_stack_00000040;
  float in_stack_00000048;
  int in_stack_00000150;
  float fStack0000000000000158;
  float fStack000000000000015c;
  
  fVar5 = _DAT_181b2beb8;
  fVar4 = _DAT_181b2beb4;
  fVar3 = _DAT_181b2b410;
  cVar2 = DAT_181b2b407;
  cVar7 = DAT_181b2b406;
  fVar1 = _DAT_181a03230;
  do {
    if (((*(char *)((longlong)unaff_RBX + 0x1a) == '\0') &&
        ((cVar7 == '\0' || (*(char *)((longlong)unaff_RBX + 0x1b) == '\0')))) &&
       ((cVar2 == '\0' || (*(char *)(unaff_RBX + 3) == '\0')))) {
      plVar8 = unaff_RBX + 0x14;
      recovered_180067e80(&stack0x00000158,&DAT_181b2be70,plVar8,unaff_EBP);
      fVar6 = fStack000000000000015c;
      fVar9 = fStack0000000000000158;
      if ((fVar1 <= fStack0000000000000158) && (fVar1 <= fStack000000000000015c)) {
        in_stack_00000040 = *plVar8;
        fVar13 = _DAT_181b2beb0 - (float)in_stack_00000040;
        fVar12 = fVar5 - *(float *)(plVar8 + 1);
        fVar14 = fVar4 - (float)((ulonglong)in_stack_00000040 >> 0x20);
        fVar12 = fVar14 * fVar14 + fVar13 * fVar13 + fVar12 * fVar12;
        if (fVar12 < 0.0) {
          fVar12 = (float)func_0x0001801cb525(fVar12);
        }
        else {
          fVar12 = SQRT(fVar12);
        }
        if (fVar12 <= (float)_DAT_181b2b40c) {
          dVar10 = (double)func_0x0001801cb507((double)(fVar6 - unaff_XMM11_Da));
          dVar11 = (double)func_0x0001801cb507((double)(fVar9 - unaff_XMM10_Da));
          dVar10 = dVar10 + dVar11;
          if (dVar10 < 0.0) {
            dVar10 = (double)func_0x0001801cb51f(dVar10);
          }
          else {
            dVar10 = SQRT(dVar10);
          }
          fVar9 = (float)dVar10;
          if ((fVar9 <= fVar3) && (fVar9 < unaff_XMM8_Da)) {
            unaff_RSI = unaff_RBX + 3;
            unaff_XMM8_Da = fVar9;
          }
        }
      }
    }
    unaff_RBX = (longlong *)*unaff_RBX;
  } while (unaff_RBX != (longlong *)unaff_R14);
  if ((unaff_RSI != (longlong *)0x0) && (*(int *)((longlong)unaff_RSI + 0x84) != 0)) {
    in_stack_00000030 = 0;
    uStack0000000000000034 = 0x3f800000;
    in_stack_00000040 =
         CONCAT44(((float)((ulonglong)unaff_RSI[0x11] >> 0x20) + 0.0) - fVar4,
                  ((float)unaff_RSI[0x11] + 0.0) - _DAT_181b2beb0);
    in_stack_00000048 = (*(float *)(unaff_RSI + 0x12) + 0.0) - fVar5;
    func_0x00018006da10(&stack0x00000060,&stack0x00000040,&stack0x00000030);
    cVar7 = recovered_180067cc0((ulonglong)_DAT_181b2bebc + 0x440,&stack0x00000158);
    if (cVar7 != '\0') {
      (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStack000000000000015c,fStack0000000000000158),
                        &stack0x00000060,0x10);
    }
    in_stack_00000150 =
         recovered_180069360((ulonglong)*(uint *)((longlong)unaff_RSI + 0x84) + 0x4e8);
    if (in_stack_00000150 != 0) {
      cVar7 = recovered_180067cc0((ulonglong)*(uint *)((longlong)unaff_RSI + 0x84) + 0x54,
                                  &stack0x00000158);
      if (cVar7 != '\0') {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStack000000000000015c,fStack0000000000000158),
                          &stack0x00000150,4);
      }
    }
  }
  return;
}

