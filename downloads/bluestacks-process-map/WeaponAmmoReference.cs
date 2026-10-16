// Generated from exact SHA-256-verified ELF/metadata inputs.
namespace HeadBridge.Mapping {
    internal sealed class WeaponAmmoField {
        internal readonly int Local; internal readonly string Name,RecordHex;
        internal readonly ulong OffsetRva,Descriptor,NameOffset,MetadataOffset; internal readonly uint Bits,Token;
        internal WeaponAmmoField(int local,string name,ulong registration,ulong descriptor,uint bits,ulong nameOffset,uint token,ulong metadata,string record)
        { Local=local;Name=name;OffsetRva=registration;Descriptor=descriptor;Bits=bits;NameOffset=nameOffset;Token=token;MetadataOffset=metadata;RecordHex=record; }
    }
    internal static class WeaponAmmoReference {
        internal const int FieldCount=253; internal const uint GetterOffset=0x610U;
        internal static readonly StateField[] SelectionFields = {
            new StateField(31824,278,"GGBNFECEPJG",0x608UL,0x19e6a1cUL,0xadd6240UL,1179652U,32623,7877335UL,67360560U,44993716UL,"439f5900028d000030d70304"),
            new StateField(31824,319,"BKEPAKCAGNJ",0x740UL,0x19e6ac0UL,0xadd7420UL,1179652U,32430,7877904UL,67360601U,44994208UL,"7ca15900278e000059d70304"),
            new StateField(32430,37,"LMFNCLKHIIO",0xa0UL,0x19ebfd8UL,0xad96950UL,1179649U,32463,8038602UL,67366669U,45067024UL,"36155c00a06400000def0304"),
            new StateField(32430,38,"PDIMNGEMALB",0xa8UL,0x19ebfdcUL,0xadd62d0UL,1179649U,32613,8038614UL,67366670U,45067036UL,"42155c000b8d00000eef0304"),
            new StateField(32430,70,"OMHEPNBNEKL",0x148UL,0x19ec05cUL,0xad964e0UL,2147614721U,-1,8039015UL,67366702U,45067420UL,"d3165c000c6300002eef0304"),
        };
        internal static readonly WeaponAmmoField[] Candidates = {
            new WeaponAmmoField(42,"CFJLLCEFDIP",0x19eddb0UL,0xad992e0UL,2148007940U,8087008UL,67368429U,45088144UL,"4cd25c00ab9b0000edf50304"),
            new WeaponAmmoField(59,"BCMEFGAIEIG",0x19eddf4UL,0xad992c0UL,2148007937U,8087217UL,67368446U,45088348UL,"1dd35c00a99b0000fef50304"),
            new WeaponAmmoField(63,"DKECMNNPBCE",0x19ede04UL,0xad992e0UL,2148007940U,8087265UL,67368450U,45088396UL,"4dd35c00ab9b000002f60304"),
            new WeaponAmmoField(86,"MCIBEDAEAMG",0x19ede60UL,0xad992e0UL,2148007940U,8087592UL,67368473U,45088672UL,"94d45c00ab9b000019f60304"),
            new WeaponAmmoField(88,"NJKBAOGODEC",0x19ede68UL,0xad992e0UL,2148007940U,8087616UL,67368475U,45088696UL,"acd45c00ab9b00001bf60304"),
            new WeaponAmmoField(94,"KCGKFGNDIFB",0x19ede80UL,0xad992e0UL,2148007940U,8087688UL,67368481U,45088768UL,"f4d45c00ab9b000021f60304"),
            new WeaponAmmoField(102,"<OBJDFBNHMNB>k__BackingField",0x19edea0UL,0xad992c0UL,2148007937U,8087869UL,67368489U,45088864UL,"a9d55c00a99b000029f60304"),
            new WeaponAmmoField(105,"NJEENAEMFAO",0x19edeacUL,0xad992c0UL,2148007937U,8087922UL,67368492U,45088900UL,"ded55c00a99b00002cf60304"),
            new WeaponAmmoField(164,"PBLOIJMLGLM",0x19edf98UL,0xad992c0UL,2148007937U,8088681UL,67368551U,45089608UL,"d5d85c00a99b000067f60304"),
            new WeaponAmmoField(183,"ANMEOOALCEE",0x19edfe4UL,0xad992c0UL,2148007937U,8088909UL,67368570U,45089836UL,"b9d95c00a99b00007af60304"),
            new WeaponAmmoField(211,"GHHJKBMAHHA",0x19ee054UL,0xad992c0UL,2148007937U,8089233UL,67368598U,45090172UL,"fdda5c00a99b000096f60304"),
        };
        internal static readonly StateMethod[] Methods = {
            new StateMethod(26996268UL,0xab2a188UL,0x6f17f74UL,"01785800507c00009b91000000000008ffffffffffffffff470300003d36030686000000ffff0000"),
            new StateMethod(26995908UL,0xab2a140UL,0x6f18290UL,"07775800507c00009b91000000000008ffffffffffffffff460300003436030686000000ffff0000"),
            new StateMethod(27428948UL,0xab3f390UL,0x7399188UL,"f6235a00cf7e00000b6300000000000879140200ffffffff450300007e60030696080000ffff0100"),
            new StateMethod(27400908UL,0xab3dda8UL,0x734b8d4UL,"c6fd5b00ae7e00009f64000000000008ffffffffffffffff86020000c15d030686080000ffff0000"),
            new StateMethod(27402868UL,0xab3df30UL,0x734b930UL,"26015c00ae7e00000b63000000000008ffffffffffffffff85020000f25d030686080000ffff0000"),
            new StateMethod(27567628UL,0xab45fe8UL,0x7457fa4UL,"db565c0011800000a89b000000000008ffffffffffffffff28030000096e030686080000ffff0000"),
        };
        internal static readonly GameLayoutCheck[] Anchors = {
            new GameLayoutCheck("ammo_weapon_cast_got",0xa752800UL,0xac2fbc0UL),
            new GameLayoutCheck("GetActiveWeapon_210492_0",0x6f17f74UL,"fe4fbfa9f30300aae0688052e1031faaa64a649420010036e0688052e1031faacf4a6494e00100b4e10313aae2031faafe4fc1a8dd9b5414600643f9e1031faa"),
            new GameLayoutCheck("GetActiveWeapon_210492_64",0x6f17fb4UL,"7504129480000036600643f9fe4fc1a8c0035fd6e00313aafe4fc1a8b0000014a9f3d094"),
            new GameLayoutCheck("GetWeaponOnHand_210483_0",0x6f18290UL,"fe0f1ef8f44f01a9740402b088125e39f30300aac8000037c0c101d0000044f94bf2d0942800805288121e39c0688052e1031faad649649440010036c0688052"),
            new GameLayoutCheck("GetWeaponOnHand_210483_64",0x6f182d0UL,"e1031faaff496494a00300b4e10313aaf44f41a9e2031faafe0742f80c9b541460a243f9600200b4e1031faa76cd1094000200b4c8c101d0080144f9090040f9"),
            new GameLayoutCheck("GetWeaponOnHand_210483_128",0x6f18310UL,"080140f92bc144390ac144397f010a6b62000054e0031faa06000014296540f9290d0a8b29815ff83f0108eb00009f9af44f41a9fe0742f8c0035fd6cbf2d094"),
            new GameLayoutCheck("DEIPJDIGKIP_221309_0",0x7399188UL,"fe4fbfa9f30300aaa0688052e1031faa2146529420010036a0688052e1031faa4a465294200100b4e10313aae2031faafe4fc1a8f24242147f0200f1e0079f1a"),
            new GameLayoutCheck("DEIPJDIGKIP_221309_64",0x73991c8UL,"fe4fc1a8c0035fd62aefbe94"),
            new GameLayoutCheck("PDAGHPAOBLP_220608_0",0x734b8d4UL,"fe4fbfa9f30300aac0508052e1031faa4e7c539420010036c0508052e1031faa777c5394a00100b4e10313aae2031faafe4fc1a82cb24314e00313aa08000094"),
            new GameLayoutCheck("PDAGHPAOBLP_220608_64",0x734b914UL,"60000036605640f902000014605240f9fe4fc1a8c0035fd65325c094"),
            new GameLayoutCheck("CKIKAFHOBDC_220657_0",0x734b930UL,"fe4fbfa9f30300aaa0508052e1031faa377c539420010036a0508052e1031faa607c5394000100b4e10313aae2031faafe4fc1a80879431460224539fe4fc1a8"),
            new GameLayoutCheck("CKIKAFHOBDC_220657_64",0x734b970UL,"c0035fd64125c094"),
            new GameLayoutCheck("IHBDOPMADIE_224776_0",0x7457fa4UL,"fe4fbfa9f30300aa00658052e1031faa9a4a4f942001003600658052e1031faac34a4f94000100b4e10313aae2031faafe4fc1a8984c3f14601246b9fe4fc1a8"),
            new GameLayoutCheck("IHBDOPMADIE_224776_64",0x7457fe4UL,"c0035fd6a4f3bb94"),
        };
    }
}
