/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_180073610(void)

{
  float fVar1;
  int iVar2;
  longlong **pplVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  char cVar11;
  short sVar12;
  longlong **pplVar13;
  longlong **pplVar14;
  longlong **pplVar15;
  double dVar16;
  double dVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  int aiStackX_8 [2];
  float fStackX_10;
  float fStackX_14;
  
  if ((DAT_181b2b403 != '\0') &&
     (sVar12 = GetAsyncKeyState(_DAT_181b2b414), iVar8 = _DAT_181b2becc, iVar7 = _DAT_181b2bec8,
     fVar6 = _DAT_181b2beb8, fVar5 = _DAT_181b2beb4, fVar4 = _DAT_181b2beb0,
     pplVar3 = _DAT_181b2be38, iVar2 = _DAT_181b2b40c, cVar11 = DAT_181b2b406,
     fVar1 = _DAT_181a03230, sVar12 < 0)) {
    pplVar14 = (longlong **)0x0;
    pplVar13 = (longlong **)*_DAT_181b2be38;
    fVar22 = (float)_DAT_181b2becc * _DAT_181a031bc;
    fVar21 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
    fVar20 = _DAT_181a03460;
    if (pplVar13 != _DAT_181b2be38) {
      do {
        if ((*(char *)((longlong)pplVar13 + 0x1a) == '\0') &&
           ((cVar11 == '\0' || (*(char *)((longlong)pplVar13 + 0x1b) == '\0')))) {
          pplVar15 = pplVar13 + 0x14;
          recovered_180067e80(&fStackX_10,&DAT_181b2be70,pplVar15,iVar7,iVar8);
          fVar10 = fStackX_14;
          fVar9 = fStackX_10;
          if ((fVar1 <= fStackX_10) && (fVar1 <= fStackX_14)) {
            fVar18 = fVar4 - SUB84(*pplVar15,0);
            fVar19 = fVar5 - (float)((ulonglong)*pplVar15 >> 0x20);
            fVar18 = fVar19 * fVar19 + fVar18 * fVar18 +
                     (fVar6 - *(float *)(pplVar15 + 1)) * (fVar6 - *(float *)(pplVar15 + 1));
            if (fVar18 < 0.0) {
              fVar18 = (float)func_0x0001801cb525(fVar18);
            }
            else {
              fVar18 = SQRT(fVar18);
            }
            if (fVar18 <= (float)iVar2) {
              dVar16 = (double)func_0x0001801cb507((double)(fVar10 - fVar22));
              dVar17 = (double)func_0x0001801cb507((double)(fVar9 - fVar21));
              dVar16 = dVar16 + dVar17;
              if (dVar16 < 0.0) {
                dVar16 = (double)func_0x0001801cb51f(dVar16);
              }
              else {
                dVar16 = SQRT(dVar16);
              }
              if ((float)dVar16 < fVar20) {
                pplVar14 = pplVar13 + 3;
                fVar20 = (float)dVar16;
              }
            }
          }
        }
        pplVar13 = (longlong **)*pplVar13;
      } while (pplVar13 != pplVar3);
      if ((((pplVar14 != (longlong **)0x0) && (*(uint *)((longlong)pplVar14 + 0x84) != 0)) &&
          (aiStackX_8[0] =
                recovered_180069360((ulonglong)*(uint *)((longlong)pplVar14 + 0x84) + 0x4e8),
          aiStackX_8[0] != 0)) &&
         (cVar11 = recovered_180067cc0((ulonglong)*(uint *)((longlong)pplVar14 + 0x84) + 0x54,
                                       &fStackX_10), cVar11 != '\0')) {
        (*_DAT_181b4efa8)(_DAT_181b4ef90,CONCAT44(fStackX_14,fStackX_10),aiStackX_8,4);
      }
    }
  }
  return;
}

