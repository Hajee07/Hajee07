/* Inferred pseudocode from user-supplied NOVA XITERS INTERNAL V2 embedded Windows x64 DLL.
 * Not original source. Types/names inferred. No live game or Windows runtime validation.
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 recovered_1800af0d6(void)

{
  float fVar1;
  float fVar2;
  short sVar3;
  longlong lVar4;
  uint unaff_EDI;
  
  if (2 < _DAT_181b2b470) {
    _DAT_181b2b470 = unaff_EDI;
  }
  if (1 < _DAT_181b2b474) {
    _DAT_181b2b474 = 1;
  }
  if ((_DAT_181b2b578 < _DAT_181a03340) || (_DAT_181a033b4 < _DAT_181b2b578)) {
    _DAT_181b2b578 = 64.0;
  }
  if (3 < _DAT_181b2b520) {
    _DAT_181b2b520 = 2;
  }
  if (3 < _DAT_181b2b524) {
    _DAT_181b2b524 = unaff_EDI;
  }
  if (3 < _DAT_181b2b528) {
    _DAT_181b2b528 = 2;
  }
  if (3 < _DAT_181b2b52c) {
    _DAT_181b2b52c = 3;
  }
  if (3 < _DAT_181b2b500) {
    _DAT_181b2b500 = 2;
  }
  if (3 < _DAT_181b2b518) {
    _DAT_181b2b518 = 3;
  }
  if (3 < _DAT_181b2b530) {
    _DAT_181b2b530 = 3;
  }
  if (3 < _DAT_181b2b534) {
    _DAT_181b2b534 = 2;
  }
  if (3 < _DAT_181b2b560) {
    _DAT_181b2b560 = 1;
  }
  if (1 < _DAT_181b2b49c) {
    _DAT_181b2b49c = 1;
  }
  lVar4 = fread(0x181b2b584,0x6e8,1);
  fVar2 = _DAT_181b2b5bc;
  fVar1 = _DAT_181a032ec;
  if (lVar4 == 1) {
    if (499 < _DAT_181b2b638 - 1U) {
      _DAT_181b2b638 = 8;
    }
    if ((_DAT_181b2b63c < _DAT_181a03230) || (_DAT_181a03414 < _DAT_181b2b63c)) {
      _DAT_181b2b63c = 200.0;
    }
    if ((_DAT_181b2b640 < _DAT_181a03230) || (_DAT_181a0336c < _DAT_181b2b640)) {
      _DAT_181b2b640 = 8.0;
    }
    if ((_DAT_181b2b644 < _DAT_181a0315c) || (_DAT_181a032ec < _DAT_181b2b644)) {
      _DAT_181b2b644 = 0.5;
    }
    if (1 < _DAT_181b2b634) {
      _DAT_181b2b634 = unaff_EDI;
    }
    if ((_DAT_181b2b628 < _DAT_181a03230) || (_DAT_181a0336c < _DAT_181b2b628)) {
      _DAT_181b2b628 = 8.0;
    }
    if ((_DAT_181b2b62c < _DAT_181a0315c) || (_DAT_181a032ec < _DAT_181b2b62c)) {
      _DAT_181b2b62c = 1.0;
    }
    if (1 < _DAT_181b2b620) {
      _DAT_181b2b620 = unaff_EDI;
    }
    if ((_DAT_181b2b590 < _DAT_181a0315c) || (_DAT_181a032b0 < _DAT_181b2b590)) {
      _DAT_181b2b590 = 1.0;
    }
    if ((_DAT_181b2bc64 < _DAT_181a03230) || (_DAT_181a0330c < _DAT_181b2bc64)) {
      _DAT_181b2bc64 = 5.0;
    }
    if (1 < _DAT_181b2b5b8) {
      _DAT_181b2b5b8 = 1;
    }
    sVar3 = func_0x0001801cb4cb(_DAT_181b2b5bc);
    if ((0 < sVar3) || (fVar2 < fVar1)) {
      _DAT_181b2b5bc = 500.0;
    }
    else if (_DAT_181a03434 < fVar2) {
      _DAT_181b2b5bc = 3000.0;
    }
    lVar4 = fread(&DAT_181b2bc6c,0x10c,1);
    if ((((((lVar4 == 1) && (lVar4 = fread(0x181b30430,9999,1), lVar4 == 1)) &&
          (lVar4 = fread(&DAT_181b2f8c9,1,1), lVar4 == 1)) &&
         ((lVar4 = fread(0x181b32b80,0x2f90,1), lVar4 == 1 &&
          (lVar4 = fread(&DAT_181b32b7c,4,1), lVar4 == 1)))) &&
        (((lVar4 = fread(&DAT_181b303b8,4,1), lVar4 == 1 &&
          ((lVar4 = fread(&DAT_181b32b54,4,1), lVar4 == 1 &&
           (lVar4 = fread(&DAT_181b32b64,4,1), lVar4 == 1)))) &&
         (lVar4 = fread(&DAT_181b32b4c,4,1), lVar4 == 1)))) &&
       ((((lVar4 = fread(&DAT_181b303bc,4,1), lVar4 == 1 &&
          (lVar4 = fread(&DAT_181b30428,4,1), lVar4 == 1)) &&
         (lVar4 = fread(&DAT_181b30420,4,1), lVar4 == 1)) &&
        (((lVar4 = fread(&DAT_181b32b50,4,1), lVar4 == 1 &&
          (lVar4 = fread(&DAT_181ade2b8,4,1), lVar4 == 1)) &&
         ((lVar4 = fread(&DAT_181b32b78,4,1), lVar4 == 1 &&
          ((lVar4 = fread(&DAT_181b3042c,4,1), lVar4 == 1 &&
           (lVar4 = fread(&DAT_181b2bede,1,1), lVar4 == 1)))))))))) {
      lVar4 = fread(&DAT_181ade1f8,4,1);
      if ((lVar4 != 1) || ((0xfd < _DAT_181ade1f8 - 1U || (_DAT_181ade1f8 == 0x24)))) {
        _DAT_181ade1f8 = 0x77;
      }
      lVar4 = fread(&DAT_181ade204,1,1);
      if (lVar4 != 1) {
        DAT_181ade204 = 1;
      }
      lVar4 = fread(&DAT_181b32b48,4,1);
      if (lVar4 != 1) {
        _DAT_181b32b48 = unaff_EDI;
      }
      lVar4 = fread(&DAT_181b32b40,4,1);
      if (lVar4 != 1) {
        _DAT_181b32b40 = unaff_EDI;
      }
      return 1;
    }
  }
  return 0;
}

