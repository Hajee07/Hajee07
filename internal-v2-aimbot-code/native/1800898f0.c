/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined (*) [16] recovered_1800898f0(undefined (*param_1) [16],undefined4 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined8 ****ppppuVar9;
  undefined8 ****ppppuVar10;
  ulonglong uVar11;
  longlong lVar12;
  char *pcVar13;
  undefined auStackX_18 [8];
  char acStack_3c [4];
  undefined8 ****appppuStack_38 [2];
  longlong lStack_28;
  ulonglong uStack_20;
  
  ppppuVar9 = (undefined8 ****)0x0;
  if (DAT_181b2f6db == '\0') {
    func_0x000180086370();
    func_0x000180088770();
    func_0x000180089280();
    DAT_181b2f6db = '\x01';
  }
  uVar6 = func_0x000180089860(param_2);
  plVar7 = (longlong *)
           (((((ulonglong)(uVar6 >> 0x10) & 0xff ^
              ((ulonglong)(uVar6 >> 8 & 0xff) ^
              ((ulonglong)uVar6 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3) * 0x100000001b3) *
              0x100000001b3 ^ (ulonglong)(uVar6 >> 0x18)) * 0x100000001b3 & _DAT_181b30370) * 0x10 +
           _DAT_181b30358);
  lVar12 = plVar7[1];
  if (lVar12 == _DAT_181b30348) {
LAB_1800899c1:
    lVar12 = 0;
  }
  else {
    uVar1 = *(uint *)(lVar12 + 0x10);
    while (uVar6 != uVar1) {
      if (lVar12 == *plVar7) goto LAB_1800899c1;
      lVar12 = *(longlong *)(lVar12 + 8);
      uVar1 = *(uint *)(lVar12 + 0x10);
    }
  }
  lVar8 = _DAT_181b30348;
  if (lVar12 != 0) {
    lVar8 = lVar12;
  }
  if (lVar8 == _DAT_181b30348) {
    pcVar13 = acStack_3c + 1;
    uVar11 = (ulonglong)uVar6;
    do {
      pcVar13 = pcVar13 + -1;
      uVar2 = uVar11 / 10;
      *pcVar13 = (char)uVar11 + (char)uVar2 * -10 + '0';
      uVar11 = uVar2;
    } while ((int)uVar2 != 0);
    recovered_180078780(appppuStack_38,pcVar13,acStack_3c + 1,auStackX_18);
    if (uStack_20 - lStack_28 < 5) {
      ppppuVar9 = (undefined8 ****)
                  recovered_1800678e0(appppuStack_38,5,lStack_28,0,&UNK_1819d8940,5);
    }
    else {
      ppppuVar10 = appppuStack_38;
      if (0xf < uStack_20) {
        ppppuVar10 = appppuStack_38[0];
      }
      if ((&UNK_1819d8944 < ppppuVar10) ||
         ((undefined *)(lStack_28 + (longlong)ppppuVar10) < &UNK_1819d8940)) {
        ppppuVar9 = (undefined8 ****)0x5;
      }
      else if (&UNK_1819d8940 < ppppuVar10) {
        ppppuVar9 = ppppuVar10 + -0x3033b128;
      }
      lVar12 = lStack_28 + 1;
      lStack_28 = lStack_28 + 5;
      func_0x0001801ca893((undefined *)((longlong)ppppuVar10 + 5),ppppuVar10,lVar12);
      func_0x0001801ca88d(ppppuVar10,&UNK_1819d8940,ppppuVar9);
      func_0x0001801ca88d((undefined *)((longlong)ppppuVar10 + (longlong)ppppuVar9),
                          &UNK_1819d8945 + (longlong)ppppuVar9,5 - (longlong)ppppuVar9);
      ppppuVar9 = appppuStack_38;
    }
    *param_1 = ZEXT816(0);
    *(undefined8 *)param_1[1] = 0;
    *(undefined8 *)(param_1[1] + 8) = 0;
    uVar3 = *(undefined4 *)((longlong)ppppuVar9 + 4);
    uVar4 = *(undefined4 *)(ppppuVar9 + 1);
    uVar5 = *(undefined4 *)((longlong)ppppuVar9 + 0xc);
    *(undefined4 *)*param_1 = *(undefined4 *)ppppuVar9;
    *(undefined4 *)(*param_1 + 4) = uVar3;
    *(undefined4 *)(*param_1 + 8) = uVar4;
    *(undefined4 *)(*param_1 + 0xc) = uVar5;
    uVar3 = *(undefined4 *)((longlong)ppppuVar9 + 0x14);
    uVar4 = *(undefined4 *)(ppppuVar9 + 3);
    uVar5 = *(undefined4 *)((longlong)ppppuVar9 + 0x1c);
    *(undefined4 *)param_1[1] = *(undefined4 *)(ppppuVar9 + 2);
    *(undefined4 *)(param_1[1] + 4) = uVar3;
    *(undefined4 *)(param_1[1] + 8) = uVar4;
    *(undefined4 *)(param_1[1] + 0xc) = uVar5;
    ppppuVar9[2] = (undefined8 ***)0x0;
    ppppuVar9[3] = (undefined8 ***)0xf;
    *(undefined *)ppppuVar9 = 0;
    recovered_180066e40(appppuStack_38);
  }
  else {
    recovered_180080190(param_1,lVar8 + 0x18);
  }
  return param_1;
}

