/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * recovered_180072400(char param_1,char param_2)

{
  undefined8 *puVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  float fVar5;
  float fVar6;
  undefined8 *puVar7;
  float fVar8;
  int iVar9;
  longlong lVar10;
  undefined8 *puVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fStack_e8;
  
  iVar9 = _DAT_181b2bebc;
  fVar8 = _DAT_181b2beac;
  puVar7 = _DAT_181b2be38;
  fVar6 = _DAT_181b2b63c;
  fVar5 = _DAT_181b2b410;
  cVar4 = DAT_181b2b406;
  fVar3 = _DAT_181a032ec;
  fVar2 = _DAT_181a03230;
  puVar11 = (undefined8 *)0x0;
  if (((_DAT_181b2bec8 < 1) || (_DAT_181b2becc < 1)) || (DAT_181b2bec4 == '\0')) {
    puVar11 = (undefined8 *)0x0;
  }
  else {
    fVar19 = (float)_DAT_181b2becc * _DAT_181a031bc;
    fVar18 = (float)_DAT_181b2bec8 * _DAT_181a031bc;
    fVar17 = _DAT_181a03460;
    for (puVar1 = (undefined8 *)*_DAT_181b2be38; puVar1 != puVar7; puVar1 = (undefined8 *)*puVar1) {
      if ((((*(int *)((longlong)puVar1 + 0x9c) != 0) && (*(int *)((longlong)puVar1 + 0x9c) != iVar9)
           ) && ((*(char *)((longlong)puVar1 + 0x19) != '\0' &&
                 ((*(char *)((longlong)puVar1 + 0x1a) == '\0' && (*(int *)(puVar1 + 6) != 0)))))) &&
         ((cVar4 == '\0' || (*(char *)((longlong)puVar1 + 0x1b) == '\0')))) {
        lVar10 = 0x118;
        if (param_2 == '\0') {
          lVar10 = 0xa0;
        }
        fVar16 = *(float *)(lVar10 + 8 + (longlong)puVar1);
        fVar12 = (float)((ulonglong)*(undefined8 *)(lVar10 + (longlong)puVar1) >> 0x20);
        fStack_e8 = (float)*(undefined8 *)(lVar10 + (longlong)puVar1);
        fVar13 = fVar12 * _DAT_181b2be8c + fStack_e8 * _DAT_181b2be7c + fVar16 * _DAT_181b2be9c +
                 fVar8;
        if (_DAT_181a03124 <= fVar13) {
          fVar15 = ((fVar12 * _DAT_181b2be80 + fStack_e8 * _DAT_181b2be70 + fVar16 * _DAT_181b2be90
                    + _DAT_181b2bea0) * fVar18) / fVar13 + fVar18;
          fVar16 = fVar19 - ((fVar12 * _DAT_181b2be84 + fStack_e8 * _DAT_181b2be74 +
                              fVar16 * _DAT_181b2be94 + _DAT_181b2bea4) * fVar19) / fVar13;
          if ((fVar2 <= fVar15) && (fVar2 <= fVar16)) {
            fVar13 = _DAT_181b2beb0 - (float)*(undefined8 *)(lVar10 + (longlong)puVar1);
            fVar12 = _DAT_181b2beb8 - *(float *)(lVar10 + 8 + (longlong)puVar1);
            fVar14 = _DAT_181b2beb4 -
                     (float)((ulonglong)*(undefined8 *)(lVar10 + (longlong)puVar1) >> 0x20);
            fVar12 = fVar14 * fVar14 + fVar13 * fVar13 + fVar12 * fVar12;
            if (fVar12 < 0.0) {
              fVar12 = (float)func_0x0001801cb525(fVar12);
            }
            else {
              fVar12 = SQRT(fVar12);
            }
            if ((fVar12 <= fVar6) && (fVar3 < fVar12)) {
              fVar15 = fVar18 - fVar15;
              fVar16 = fVar19 - fVar16;
              fVar16 = fVar16 * fVar16 + fVar15 * fVar15;
              if (fVar16 < 0.0) {
                fVar16 = (float)func_0x0001801cb525(fVar16);
              }
              else {
                fVar16 = SQRT(fVar16);
              }
              if (((param_1 == '\0') || (fVar16 <= fVar5)) && (fVar16 < fVar17)) {
                puVar11 = puVar1 + 3;
                fVar17 = fVar16;
              }
            }
          }
        }
      }
    }
  }
  return puVar11;
}

