/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong ** recovered_180072454(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  float fVar4;
  float fVar5;
  char cVar6;
  float fVar7;
  float fVar8;
  longlong **pplVar9;
  float fVar10;
  int iVar11;
  int in_EAX;
  longlong lVar12;
  undefined8 unaff_RBX;
  longlong **pplVar13;
  longlong **unaff_RBP;
  undefined8 unaff_RSI;
  undefined8 unaff_RDI;
  longlong in_R11;
  undefined8 unaff_R12;
  char unaff_R13B;
  undefined8 unaff_R14;
  char unaff_R15B;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined4 unaff_XMM6_Da;
  float fVar17;
  undefined4 unaff_XMM6_Db;
  undefined4 unaff_XMM6_Dc;
  undefined4 unaff_XMM6_Dd;
  undefined4 unaff_XMM7_Da;
  float fVar18;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  float unaff_XMM8_Da;
  undefined4 unaff_XMM9_Da;
  float fVar19;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  float fVar20;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  undefined4 unaff_XMM11_Da;
  undefined4 unaff_XMM11_Db;
  undefined4 unaff_XMM11_Dc;
  undefined4 unaff_XMM11_Dd;
  float fStackX_20;
  
  *(undefined8 *)(in_R11 + 8) = unaff_RBX;
  *(undefined8 *)(in_R11 + 0x10) = unaff_RSI;
  pplVar9 = _DAT_181b2be38;
  *(undefined8 *)(in_R11 + -0x20) = unaff_R12;
  iVar11 = _DAT_181b2bebc;
  *(undefined8 *)(in_R11 + -0x28) = unaff_R14;
  cVar6 = DAT_181b2b406;
  pplVar13 = (longlong **)*pplVar9;
  *(undefined4 *)(in_R11 + -0x68) = unaff_XMM9_Da;
  *(undefined4 *)(in_R11 + -100) = unaff_XMM9_Db;
  *(undefined4 *)(in_R11 + -0x60) = unaff_XMM9_Dc;
  *(undefined4 *)(in_R11 + -0x5c) = unaff_XMM9_Dd;
  *(undefined4 *)(in_R11 + -0x78) = unaff_XMM10_Da;
  *(undefined4 *)(in_R11 + -0x74) = unaff_XMM10_Db;
  *(undefined4 *)(in_R11 + -0x70) = unaff_XMM10_Dc;
  *(undefined4 *)(in_R11 + -0x6c) = unaff_XMM10_Dd;
  fVar8 = _DAT_181b2b63c;
  fVar7 = _DAT_181b2b410;
  fVar20 = (float)in_EAX * _DAT_181a031bc;
  fVar19 = (float)param_3 * _DAT_181a031bc;
  if (pplVar13 != pplVar9) {
    *(undefined8 *)(in_R11 + 0x18) = unaff_RDI;
    auVar3._4_4_ = unaff_XMM11_Db;
    auVar3._0_4_ = unaff_XMM11_Da;
    auVar3._8_4_ = unaff_XMM11_Dc;
    auVar3._12_4_ = unaff_XMM11_Dd;
    *(undefined (*) [16])(in_R11 + -0x88) = auVar3;
    fVar10 = _DAT_181b2beac;
    fVar5 = _DAT_181a032ec;
    fVar4 = _DAT_181a03230;
    auVar1._4_4_ = unaff_XMM6_Db;
    auVar1._0_4_ = unaff_XMM6_Da;
    auVar1._8_4_ = unaff_XMM6_Dc;
    auVar1._12_4_ = unaff_XMM6_Dd;
    *(undefined (*) [16])(in_R11 + -0x38) = auVar1;
    auVar2._4_4_ = unaff_XMM7_Db;
    auVar2._0_4_ = unaff_XMM7_Da;
    auVar2._8_4_ = unaff_XMM7_Dc;
    auVar2._12_4_ = unaff_XMM7_Dd;
    *(undefined (*) [16])(in_R11 + -0x48) = auVar2;
    do {
      if ((((*(int *)((longlong)pplVar13 + 0x9c) != 0) &&
           (*(int *)((longlong)pplVar13 + 0x9c) != iVar11)) &&
          (*(char *)((longlong)pplVar13 + 0x19) != '\0')) &&
         (((*(char *)((longlong)pplVar13 + 0x1a) == '\0' && (*(int *)(pplVar13 + 6) != 0)) &&
          ((cVar6 == '\0' || (*(char *)((longlong)pplVar13 + 0x1b) == '\0')))))) {
        lVar12 = 0x118;
        if (unaff_R13B == '\0') {
          lVar12 = 0xa0;
        }
        fVar18 = *(float *)(lVar12 + 8 + (longlong)pplVar13);
        fVar14 = (float)((ulonglong)*(undefined8 *)(lVar12 + (longlong)pplVar13) >> 0x20);
        fStackX_20 = (float)*(undefined8 *)(lVar12 + (longlong)pplVar13);
        fVar15 = fVar14 * _DAT_181b2be8c + fStackX_20 * _DAT_181b2be7c + fVar18 * _DAT_181b2be9c +
                 fVar10;
        if (_DAT_181a03124 <= fVar15) {
          fVar17 = ((fVar14 * _DAT_181b2be80 + fStackX_20 * _DAT_181b2be70 + fVar18 * _DAT_181b2be90
                    + _DAT_181b2bea0) * fVar19) / fVar15 + fVar19;
          fVar18 = fVar20 - ((fVar14 * _DAT_181b2be84 + fStackX_20 * _DAT_181b2be74 +
                              fVar18 * _DAT_181b2be94 + _DAT_181b2bea4) * fVar20) / fVar15;
          if ((fVar4 <= fVar17) && (fVar4 <= fVar18)) {
            fVar15 = _DAT_181b2beb0 - (float)*(undefined8 *)(lVar12 + (longlong)pplVar13);
            fVar14 = _DAT_181b2beb8 - *(float *)(lVar12 + 8 + (longlong)pplVar13);
            fVar16 = _DAT_181b2beb4 -
                     (float)((ulonglong)*(undefined8 *)(lVar12 + (longlong)pplVar13) >> 0x20);
            fVar14 = fVar16 * fVar16 + fVar15 * fVar15 + fVar14 * fVar14;
            if (fVar14 < 0.0) {
              fVar14 = (float)func_0x0001801cb525(fVar14);
            }
            else {
              fVar14 = SQRT(fVar14);
            }
            if ((fVar14 <= fVar8) && (fVar5 < fVar14)) {
              fVar17 = fVar19 - fVar17;
              fVar18 = fVar20 - fVar18;
              fVar18 = fVar18 * fVar18 + fVar17 * fVar17;
              if (fVar18 < 0.0) {
                fVar18 = (float)func_0x0001801cb525(fVar18);
              }
              else {
                fVar18 = SQRT(fVar18);
              }
              if (((unaff_R15B == '\0') || (fVar18 <= fVar7)) && (fVar18 < unaff_XMM8_Da)) {
                unaff_RBP = pplVar13 + 3;
                unaff_XMM8_Da = fVar18;
              }
            }
          }
        }
      }
      pplVar13 = (longlong **)*pplVar13;
    } while (pplVar13 != pplVar9);
  }
  return unaff_RBP;
}

