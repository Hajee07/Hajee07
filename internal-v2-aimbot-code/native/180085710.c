/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


void recovered_180085710(longlong param_1)

{
  code *pcVar1;
  longlong lVar2;
  undefined *puVar3;
  ulonglong uVar4;
  int iVar5;
  undefined8 uVar6;
  longlong *plVar7;
  ulonglong uVar8;
  undefined *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong *plVar15;
  longlong lStackX_10;
  undefined auStack_2f8 [16];
  undefined auStack_2e8 [16];
  undefined auStack_2d8 [16];
  undefined auStack_2c8 [16];
  undefined auStack_2b8 [16];
  undefined auStack_2a8 [16];
  undefined auStack_298 [16];
  undefined auStack_288 [16];
  undefined auStack_278 [16];
  undefined auStack_268 [16];
  undefined auStack_258 [16];
  undefined auStack_248 [16];
  undefined auStack_238 [528];
  
  plVar15 = (longlong *)&UNK_1802f5b80;
  uVar14 = 0;
  while( true ) {
    uVar8 = 0;
    uVar6 = recovered_180085590();
    auStack_2f8 = ZEXT816(0);
    auStack_2e8 = ZEXT816(0);
    lVar11 = -1;
    do {
      lVar11 = lVar11 + 1;
    } while (*(char *)(*plVar15 + lVar11) != '\0');
    recovered_180066cc0(auStack_2f8);
    puVar3 = (undefined *)auStack_2f8._0_8_;
    uVar4 = auStack_2e8._8_8_;
    puVar9 = auStack_2f8;
    if (0xf < (ulonglong)auStack_2e8._8_8_) {
      puVar9 = (undefined *)auStack_2f8._0_8_;
    }
    uVar13 = 0xcbf29ce484222325;
    if (auStack_2e8._0_8_ != 0) {
      do {
        uVar13 = (uVar13 ^ (byte)puVar9[uVar8]) * 0x100000001b3;
        uVar8 = uVar8 + 1;
      } while (uVar8 < (ulonglong)auStack_2e8._0_8_);
    }
    lVar11 = recovered_180085cb0(uVar6,auStack_258,auStack_2f8,uVar13);
    lVar11 = *(longlong *)(lVar11 + 8);
    if (0xf < uVar4) {
      puVar9 = puVar3;
      if ((0xfff < uVar4 + 1) &&
         (puVar9 = *(undefined **)(puVar3 + -8),
         (undefined *)0x1f < puVar3 + (-8 - (longlong)puVar9))) {
        _invoke_watson(0,0,0,0,0);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      func_0x000180127e40(puVar9);
    }
    if (lVar11 == 0) break;
LAB_1800859a9:
    uVar14 = uVar14 + 0x18;
    plVar15 = plVar15 + 3;
    if (0x35f < uVar14) {
      return;
    }
  }
  auStack_2d8 = ZEXT816(0);
  auStack_2c8 = ZEXT816(0);
  auStack_2b8 = ZEXT816(0);
  auStack_2a8 = ZEXT816(0);
  auStack_298 = ZEXT816(0);
  auStack_288 = ZEXT816(0);
  auStack_278 = ZEXT816(0);
  auStack_268 = ZEXT816(0);
  MultiByteToWideChar(0xfde9,0,*plVar15,0xffffffff,auStack_2d8,0x40);
  puVar10 = (undefined8 *)0x181a2b180;
LAB_180085880:
  func_0x0001801ca899(auStack_238,0,0x208);
  func_0x000180085be0(auStack_238,&UNK_1819d8458,*puVar10,auStack_2d8);
  lVar11 = *plVar15;
  if (((param_1 == 0) || (lVar11 == 0)) || (iVar5 = GetFileAttributesW(auStack_238), iVar5 == -1))
  goto LAB_180085900;
  lStackX_10 = 0;
  iVar5 = D3DX11CreateShaderResourceViewFromFileW(param_1,auStack_238,0,0,&lStackX_10,0);
  lVar2 = lStackX_10;
  if ((iVar5 < 0) || (lStackX_10 == 0)) goto LAB_180085900;
  uVar6 = recovered_180085590();
  auStack_2f8 = ZEXT816(0);
  auStack_2e8 = ZEXT816(0);
  lVar12 = -1;
  do {
    lVar12 = lVar12 + 1;
  } while (*(char *)(lVar11 + lVar12) != '\0');
  recovered_180066cc0(auStack_2f8,lVar11);
  plVar7 = (longlong *)recovered_180085d80(uVar6,auStack_248,auStack_2f8);
  *(longlong *)(*plVar7 + 0x30) = lVar2;
  if (0xf < (ulonglong)auStack_2e8._8_8_) {
    if ((0xfff < auStack_2e8._8_8_ + 1) &&
       (0x1f < (auStack_2f8._0_8_ - *(longlong *)(auStack_2f8._0_8_ + -8)) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    func_0x000180127e40();
  }
  goto LAB_1800859a9;
LAB_180085900:
  puVar10 = puVar10 + 1;
  if (puVar10 == (undefined8 *)0x181a2b190) goto LAB_1800859a9;
  goto LAB_180085880;
}

