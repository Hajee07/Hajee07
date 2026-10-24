/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recovered_1800ad260(char *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  undefined8 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  ulonglong uVar14;
  char cVar15;
  int iVar16;
  undefined (*pauVar17) [16];
  undefined4 *puVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  undefined auVar22 [16];
  undefined4 auStackX_8 [2];
  undefined auStack_88 [5];
  undefined auStack_83 [3];
  undefined8 uStack_80;
  ulonglong uStack_78;
  ulonglong uStack_70;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined auStack_48 [16];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  auStackX_8[0] = 0;
  _DAT_181ade2d0 = 0;
  pauVar17 = (undefined (*) [16])&DAT_181ade2c0;
  if (0xf < _DAT_181ade2d8) {
    pauVar17 = _DAT_181ade2c0;
  }
  (*pauVar17)[0] = 0;
  uVar13 = _UNK_181a0393c;
  uVar12 = _UNK_181a03938;
  uVar11 = _UNK_181a03934;
  uVar10 = _DAT_181a03930;
  if (*param_1 == '\0') {
    uVar20 = recovered_1800a8c60();
    iVar16 = recovered_1800a8cf0(uVar20);
    if ((iVar16 != 0) &&
       (_DAT_181b2f6e0 = iVar16, _DAT_181b2f6e8 = OpenProcess(0x1fffff,0,iVar16),
       puVar2 = _DAT_181b2f748, _DAT_181b2f6e8 != 0)) {
      puVar6 = _DAT_181b2f788;
      for (puVar1 = (undefined8 *)*_DAT_181b2f748; _DAT_181b2f788 = puVar6, puVar1 != puVar2;
          puVar1 = (undefined8 *)*puVar1) {
        auStackX_8[0] = *(undefined4 *)(puVar1 + 3);
        WriteProcessMemory(_DAT_181b2f6e8,puVar1[2],auStackX_8,4,0);
        puVar6 = _DAT_181b2f788;
      }
      for (puVar2 = (undefined8 *)*puVar6; puVar2 != puVar6; puVar2 = (undefined8 *)*puVar2) {
        auStackX_8[0] = *(undefined4 *)(puVar2 + 3);
        WriteProcessMemory(_DAT_181b2f6e8,puVar2[2],auStackX_8,4,0);
      }
      CloseHandle(_DAT_181b2f6e8);
    }
    DAT_181b30435 = 0;
    LOCK();
    DAT_181b2f6df = 0;
    UNLOCK();
    stack0xffffffffffffff7c = uVar11;
    auStack_88._0_4_ = uVar10;
    uStack_80._0_4_ = uVar12;
    uStack_80._4_4_ = uVar13;
  }
  else {
    uStack_78 = _DAT_181a03560;
    uStack_70 = _UNK_181a03568;
    _auStack_83 = SUB1611(ZEXT816(0),5);
    auStack_88 = (undefined  [5])0x6b63654e;
    recovered_1800a8dd0(param_1,auStack_88);
    if (0xf < uStack_70) {
      if ((0xfff < uStack_70 + 1) && (0x1f < (_auStack_88 - *(longlong *)(_auStack_88 + -8)) - 8U))
      goto LAB_1800ad53a;
      func_0x000180127e40();
    }
    cVar15 = recovered_1800ad030();
    uVar14 = _DAT_181ade2d0;
    if (cVar15 != '\0') {
      DAT_181b30435 = 0;
      LOCK();
      DAT_181b2f6df = 0;
      UNLOCK();
      auVar22 = ZEXT816(0);
      if (_DAT_181ade2d0 == 0) {
        auStack_48 = auVar22;
        puVar18 = (undefined4 *)func_0x000180024110(0x20);
        uVar9 = _UNK_1819dcc14;
        uVar8 = _UNK_1819dcc10;
        uVar7 = _UNK_1819dcc0c;
        auStack_48._0_8_ = puVar18;
        uStack_38 = _DAT_181a03620;
        uStack_34 = _UNK_181a03624;
        uStack_30 = _UNK_181a03628;
        uStack_2c = _UNK_181a0362c;
        *puVar18 = _DAT_1819dcc08;
        puVar18[1] = uVar7;
        puVar18[2] = uVar8;
        puVar18[3] = uVar9;
        *(undefined2 *)(puVar18 + 4) = _DAT_1819dcc18;
        *(undefined *)((longlong)puVar18 + 0x12) = DAT_1819dcc1a;
        *(undefined *)((longlong)puVar18 + 0x13) = 0;
        puVar18 = (undefined4 *)auStack_48;
        bVar5 = true;
        bVar4 = false;
      }
      else {
        pauVar17 = (undefined (*) [16])&DAT_181ade2c0;
        if (0xf < _DAT_181ade2d8) {
          pauVar17 = _DAT_181ade2c0;
        }
        _auStack_88 = auVar22;
        if (0x7fffffffffffffff < _DAT_181ade2d0) {
          func_0x000180052a50();
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        if (_DAT_181ade2d0 < 0x10) {
          uStack_78 = _DAT_181ade2d0;
          uStack_70 = 0xf;
          _auStack_88 = *pauVar17;
        }
        else {
          uVar19 = _DAT_181ade2d0 | 0xf;
          uVar21 = 0x7fffffffffffffff;
          if ((uVar19 < 0x8000000000000000) && (uVar21 = uVar19, uVar19 < 0x16)) {
            uVar21 = 0x16;
          }
          uVar20 = func_0x000180024110(uVar21 + 1);
          _auStack_88 = uVar20;
          uStack_78 = uVar14;
          uStack_70 = uVar21;
          func_0x0001801ca88d(uVar20,pauVar17,uVar14 + 1);
        }
        puVar18 = (undefined4 *)auStack_88;
        bVar5 = false;
        bVar4 = true;
      }
      uStack_68 = *puVar18;
      uStack_64 = puVar18[1];
      uStack_60 = puVar18[2];
      uStack_5c = puVar18[3];
      uStack_58 = puVar18[4];
      uStack_54 = puVar18[5];
      uStack_50 = puVar18[6];
      uStack_4c = puVar18[7];
      *(undefined8 *)(puVar18 + 4) = 0;
      *(undefined8 *)(puVar18 + 6) = 0xf;
      *(undefined *)puVar18 = 0;
      if ((bVar4) && (0xf < uStack_70)) {
        if ((0xfff < uStack_70 + 1) && (0x1f < (_auStack_88 - *(longlong *)(_auStack_88 + -8)) - 8U)
           ) {
          _invoke_watson(0,0,0,0,0);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        func_0x000180127e40();
      }
      if ((bVar5) && (0xf < CONCAT44(uStack_2c,uStack_30))) {
        if ((0xfff < CONCAT44(uStack_2c,uStack_30) + 1) &&
           (0x1f < (auStack_48._0_8_ - *(longlong *)(auStack_48._0_8_ + -8)) - 8U)) {
          _invoke_watson(0,0,0,0,0);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        func_0x000180127e40();
      }
      stack0xffffffffffffff7c = uVar11;
      auStack_88._0_4_ = uVar10;
      uStack_80._0_4_ = uVar12;
      uStack_80._4_4_ = uVar13;
      recovered_18009bbb0();
      if (0xf < CONCAT44(uStack_4c,uStack_50)) {
        if ((0xfff < CONCAT44(uStack_4c,uStack_50) + 1) &&
           (0x1f < (CONCAT44(uStack_64,uStack_68) -
                   *(longlong *)(CONCAT44(uStack_64,uStack_68) + -8)) - 8U)) {
LAB_1800ad53a:
          _invoke_watson(0,0,0,0,0);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        func_0x000180127e40();
      }
      goto LAB_1800ad66f;
    }
    DAT_181b30435 = 1;
    LOCK();
    DAT_181b2f6df = 1;
    UNLOCK();
    stack0xffffffffffffff7c = _DAT_181a2aff4;
    auStack_88._0_4_ = _DAT_181a2aff0;
    uStack_80._0_4_ = _DAT_181a2aff8;
    uStack_80._4_4_ = _DAT_181a2affc;
  }
  recovered_18009bbb0();
LAB_1800ad66f:
  LOCK();
  DAT_181b2f8cb = 0;
  UNLOCK();
  return;
}

