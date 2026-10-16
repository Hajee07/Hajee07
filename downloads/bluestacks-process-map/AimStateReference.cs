// Generated from exact SHA-256-verified ELF/metadata inputs.
namespace HeadBridge.Mapping {
    internal static class AimStateReference {
        internal const ulong ReturnDescriptor=0xad9b270UL; internal const uint ReturnBits=2148597760U;
        internal const ulong QuaternionMetadata=54782828UL; internal const string QuaternionRecord="e95b03009b64ee002fbd0000ffffffffbb1901002fbd0000ffffffff090110005b1807000dd80400ffffffff2f560000ffffffff391e0000ec380b00888d00002f000300060000000000060002000200190c000016010002";
        internal static readonly StateMethod Method=new StateMethod(27005628UL,0xab2a8d8UL,0x6f249acUL,"a4895800507c00002fbd000000000008ffffffffffffffffb90400002737030686000000ffff0000");
        internal static readonly StateField[] Fields = {
            new StateField(31824,280,"<AKKPEKIHGAH>k__BackingField",0x614UL,0x19e6a24UL,0xad9b280UL,2148597761U,40980,7877375UL,67360562U,44993740UL,"6b9f590030bd000032d70304"),
            new StateField(40980,0,"x",0x10UL,0x1ab6440UL,0xad9be80UL,2148270086U,-1,2004424UL,67110119U,47553220UL,"34020000c1c50000e7040004"),
            new StateField(40980,1,"y",0x14UL,0x1ab6444UL,0xad9be80UL,2148270086U,-1,2004426UL,67110120U,47553232UL,"36020000c1c50000e8040004"),
            new StateField(40980,2,"z",0x18UL,0x1ab6448UL,0xad9be80UL,2148270086U,-1,2027253UL,67110121U,47553244UL,"615b0000c1c50000e9040004"),
            new StateField(40980,3,"w",0x1cUL,0x1ab644cUL,0xad9be80UL,2148270086U,-1,2079626UL,67110122U,47553256UL,"f6270100c1c50000ea040004"),
        };
        internal static readonly StateMethod VectorMethod=new StateMethod(31275268UL,0xaf5fbe8UL,0x9fddc4cUL,"75afe70014a00000f119010000000008afed0300ffffffffffffffff9b0a000696080000ffff0200");
        internal static readonly GameLayoutCheck[] Anchors = {
            new GameLayoutCheck("GetAimRotation_0",0x6f249acUL,"fe4fbfa9f30300aa20978052e1031faa181864942001003620978052e1031faa41186494600100b4e10313aae2031faafe4fc1a8b87a5414601646bd611a46bd"),
            new GameLayoutCheck("GetAimRotation_64",0x6f249ecUL,"621e46bd632246bdfe4fc1a8c0035fd61fc1d094"),
            new GameLayoutCheck("QuaternionVectorMultiply_0",0x9fddc4cUL,"0728201e3028211e5128221e1308271e3408301e4208311e12102e1e1508301e0008311e2108311e6708271e7008301e6308311e912a221e622a221eb63a231e"),
            new GameLayoutCheck("QuaternionVectorMultiply_64",0x9fddc8cUL,"a32a231e1528301e0038301e3038271e2128271e672a341e513a311e423a221eb308361e8308231e8008201ea108211e473a271e8408311ea208221ed408351e"),
            new GameLayoutCheck("QuaternionVectorMultiply_128",0x9fddcccUL,"d008301e0528211ec608271e602a241e6128221e802a201e012a211ea228261ec0035fd6"),
            new GameLayoutCheck("UnityCoreModuleName",0xa729470UL,0x195af72UL),
            new GameLayoutCheck("UnityCoreModuleNameBytes",0x195af72UL,"556e697479456e67696e652e436f72654d6f64756c652e646c6c00"),
            new GameLayoutCheck("UnityCoreModuleCount",0xa729478UL,"9012000000000000"),
            new GameLayoutCheck("UnityCoreModuleTable",0xa729480UL,0xaf5a718UL),
        };
    }
}
