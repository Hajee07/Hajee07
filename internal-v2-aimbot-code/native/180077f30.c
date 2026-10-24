/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Removing unreachable block (ram,0x000180078034) */
/* WARNING: Removing unreachable block (ram,0x000180078041) */
/* WARNING: Removing unreachable block (ram,0x000180078046) */

undefined4 * recovered_180077f30(undefined4 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined4 *puVar7;
  longlong lVar8;
  
  *param_1 = 0;
  *(undefined8 *)(param_1 + 2) = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  lVar4 = func_0x000180127a94(0x18);
  *(longlong *)lVar4 = lVar4;
  *(longlong *)(lVar4 + 8) = lVar4;
  *(longlong *)(param_1 + 2) = lVar4;
  *(undefined8 *)(param_1 + 6) = 0;
  *(undefined8 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 10) = 0;
  *(undefined8 *)(param_1 + 0xc) = 7;
  *(undefined8 *)(param_1 + 0xe) = 8;
  *param_1 = 0x3f800000;
  uVar2 = *(undefined8 *)(param_1 + 2);
  puVar5 = (undefined8 *)func_0x000180127a94(0x80);
  lVar4 = *(longlong *)(param_1 + 6);
  lVar6 = *(longlong *)(param_1 + 10) - lVar4 >> 3;
  if (lVar6 != 0) {
    lVar8 = lVar4;
    if ((0xfff < (ulonglong)(lVar6 * 8)) &&
       (lVar8 = *(longlong *)(lVar4 + -8), 0x1f < (lVar4 - lVar8) - 8U)) {
      _invoke_watson(0,0,0,0,0);
      pcVar3 = (code *)swi(3);
      puVar7 = (undefined4 *)(*pcVar3)();
      return puVar7;
    }
    func_0x000180127e40(lVar8);
  }
  *(undefined8 **)(param_1 + 6) = puVar5;
  puVar1 = puVar5 + 0x10;
  *(undefined8 **)(param_1 + 8) = puVar1;
  *(undefined8 **)(param_1 + 10) = puVar1;
  for (; puVar5 != puVar1; puVar5 = puVar5 + 1) {
    *puVar5 = uVar2;
  }
  return param_1;
}

