/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong *
recovered_180070640(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  undefined8 uStack_34;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined8 uStack_1c;
  undefined4 uStack_14;
  undefined uStack_10;
  undefined uStack_f;
  undefined uStack_e;
  undefined uStack_d;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar4 = _DAT_181b2be40;
  if (_DAT_181b2be40 != 0) {
    if (0x666666666666666 < _DAT_181b2be40) {
      recovered_18006aad0(param_1,param_2,param_3,param_4,1);
      pcVar2 = (code *)swi(3);
      plVar6 = (longlong *)(*pcVar2)();
      return plVar6;
    }
    uVar5 = func_0x000180024110(_DAT_181b2be40 * 0x28);
    func_0x0001801ca893(uVar5,*param_1,param_1[1] - *param_1);
    recovered_18007a480(param_1,uVar5,0,uVar4);
  }
  puVar3 = _DAT_181b2be38;
  puVar7 = (undefined8 *)*_DAT_181b2be38;
  while (puVar7 != puVar3) {
    uStack_34 = puVar7[0x14];
    uStack_2c = *(undefined4 *)(puVar7 + 0x15);
    uStack_28 = puVar7[0x23];
    uStack_20 = *(undefined4 *)(puVar7 + 0x24);
    uStack_1c = puVar7[0x2c];
    uStack_14 = *(undefined4 *)(puVar7 + 0x2d);
    uStack_10 = *(undefined *)((longlong)puVar7 + 0x19);
    uStack_f = *(undefined *)((longlong)puVar7 + 0x1a);
    uStack_e = *(undefined *)((longlong)puVar7 + 0x1b);
    puVar1 = (undefined4 *)param_1[1];
    if (puVar1 == (undefined4 *)param_1[2]) {
      recovered_180079e50(param_1,puVar1,&uStack_34);
      puVar7 = (undefined8 *)*puVar7;
    }
    else {
      uStack_34._4_4_ = (undefined4)((ulonglong)uStack_34 >> 0x20);
      *puVar1 = (undefined4)uStack_34;
      puVar1[1] = uStack_34._4_4_;
      puVar1[2] = uStack_2c;
      puVar1[3] = (undefined4)uStack_28;
      uStack_28._4_4_ = (undefined4)((ulonglong)uStack_28 >> 0x20);
      uStack_1c._4_4_ = (undefined4)((ulonglong)uStack_1c >> 0x20);
      puVar1[4] = uStack_28._4_4_;
      puVar1[5] = uStack_20;
      puVar1[6] = (undefined4)uStack_1c;
      puVar1[7] = uStack_1c._4_4_;
      *(ulonglong *)(puVar1 + 8) =
           CONCAT17(uStack_d,CONCAT16(uStack_e,CONCAT15(uStack_f,CONCAT14(uStack_10,uStack_14))));
      param_1[1] = param_1[1] + 0x28;
      puVar7 = (undefined8 *)*puVar7;
    }
  }
  return param_1;
}

