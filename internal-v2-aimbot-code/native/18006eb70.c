/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_18006eb70(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  float fVar4;
  undefined8 *puVar5;
  char cVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int aiStackX_10 [2];
  undefined8 uStackX_18;
  undefined8 uStackX_20;
  float fStack_108;
  float fStack_104;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 auStack_88 [4];
  float afStack_68 [12];
  
  puVar5 = _DAT_181b2be38;
  fVar4 = _DAT_181a0337c;
  for (puVar3 = (undefined8 *)*_DAT_181b2be38; puVar3 != puVar5; puVar3 = (undefined8 *)*puVar3) {
    if (((*(char *)((longlong)puVar3 + 0x19) != '\0') &&
        (*(char *)((longlong)puVar3 + 0x1a) == '\0')) &&
       (func_0x00018006e9c0(puVar3 + 3,*(undefined4 *)(puVar3 + 2)),
       *(char *)((longlong)puVar3 + 0x1a) == '\0')) {
      puVar1 = puVar3 + 0x14;
      uVar2 = *puVar1;
      fVar8 = *(float *)(puVar3 + 0x15);
      aiStackX_10[0] = 0;
      cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b110,&uStackX_18);
      if (((cVar6 != '\0') &&
          (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_18,aiStackX_10,4), iVar7 == 0)) &&
         ((aiStackX_10[0] != 0 &&
          (cVar6 = func_0x00018006c290(aiStackX_10[0],puVar1), cVar6 != '\0')))) {
        fStack_108 = (float)uVar2;
        fStack_104 = (float)((ulonglong)uVar2 >> 0x20);
        if (((fStack_108 != 0.0) || (fStack_104 != 0.0)) || (fVar8 != 0.0)) {
          if ((float *)((longlong)puVar3 + 0x184) != afStack_68) {
            *(float *)((longlong)puVar3 + 0x184) = ((float)*puVar1 - fStack_108) * fVar4;
            *(float *)(puVar3 + 0x31) = (*(float *)((longlong)puVar3 + 0xa4) - fStack_104) * fVar4;
            *(float *)((longlong)puVar3 + 0x18c) = (*(float *)(puVar3 + 0x15) - fVar8) * fVar4;
          }
        }
        if (puVar3 + 0x2f != puVar1) {
          *(undefined4 *)(puVar3 + 0x2f) = *(undefined4 *)puVar1;
          *(undefined4 *)((longlong)puVar3 + 0x17c) = *(undefined4 *)((longlong)puVar3 + 0xa4);
          *(undefined4 *)(puVar3 + 0x30) = *(undefined4 *)(puVar3 + 0x15);
        }
        fVar10 = (float)((ulonglong)*param_1 >> 0x20);
        fVar8 = (float)*param_1 - (float)*puVar1;
        fVar9 = fVar10 - (float)((ulonglong)*puVar1 >> 0x20);
        fVar8 = fVar9 * fVar9 + fVar8 * fVar8 +
                (*(float *)(param_1 + 1) - *(float *)(puVar3 + 0x15)) *
                (*(float *)(param_1 + 1) - *(float *)(puVar3 + 0x15));
        if (fVar8 < 0.0) {
          fVar8 = (float)func_0x0001801cb525(CONCAT44(fVar10,fVar8));
        }
        else {
          fVar8 = SQRT(fVar8);
        }
        *(float *)((longlong)puVar3 + 0x24) = fVar8;
      }
      aiStackX_10[0] = 0;
      cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b148,&uStackX_20);
      if (((cVar6 != '\0') &&
          (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStackX_20,aiStackX_10,4), iVar7 == 0)) &&
         (aiStackX_10[0] != 0)) {
        func_0x00018006c290(aiStackX_10[0],puVar3 + 0x2c);
      }
      aiStackX_10[0] = 0;
      cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b0f0,&uStack_f8);
      if (((cVar6 != '\0') &&
          (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_f8,aiStackX_10,4), iVar7 == 0)) &&
         (aiStackX_10[0] != 0)) {
        func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0xac);
      }
      aiStackX_10[0] = 0;
      cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b128,&uStack_f0);
      if (((cVar6 != '\0') &&
          (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_f0,aiStackX_10,4), iVar7 == 0)) &&
         (aiStackX_10[0] != 0)) {
        func_0x00018006c290(aiStackX_10[0],puVar3 + 0x23);
      }
      if (DAT_181b2b538 != '\0') {
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b118,&uStack_e8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_e8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0xc4);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b0f8,&uStack_e0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_e0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x17);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b100,&uStack_d8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_d8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0xdc);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b120,&uStack_d0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_d0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x1a);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b108,&uStack_c8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_c8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0xf4);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b150,&uStack_c0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_c0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x1d);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b178,&uStack_b8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_b8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x20);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b160,&uStack_b0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_b0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0x10c);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b168,&uStack_a8);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_a8,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0x124);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b170,&uStack_a0);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_a0,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0x13c);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b158,&uStack_98);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_98,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x26);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b138,&uStack_90);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,uStack_90,aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],puVar3 + 0x29);
        }
        aiStackX_10[0] = 0;
        cVar6 = recovered_180067cc0(*(int *)(puVar3 + 2) + _DAT_181a2b130,auStack_88);
        if (((cVar6 != '\0') &&
            (iVar7 = (*_DAT_181b4ef88)(_DAT_181b4ef90,auStack_88[0],aiStackX_10,4), iVar7 == 0)) &&
           (aiStackX_10[0] != 0)) {
          func_0x00018006c290(aiStackX_10[0],(longlong)puVar3 + 0x154);
        }
      }
    }
  }
  return;
}

