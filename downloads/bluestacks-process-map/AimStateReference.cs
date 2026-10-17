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
            new GameLayoutCheck("GetRuntimeMainCameraTransform_0",0x6f2f368UL,"fe0f1ef8f44f01a9b40302d0886a5c39f30300aa2801003780c00190006040f91596d09440c001d0003446f91296d09428008052886a1c39007883524000a072"),
            new GameLayoutCheck("GetRuntimeMainCameraTransform_64",0x6f2f3a8UL,"e1031faa9ced639460010036007883524000a072e1031faac4ed6394800600b4e10313aaf44f41a9e2031faafe0742f8bff55314e0031faa7ec3c19454c001d0"),
            new GameLayoutCheck("GetRuntimeMainCameraTransform_128",0x6f2f3e8UL,"943646f9f30300aa880240f909e140b969000035e00308aa5596d094e00313aae1031faae2031faa14f3c294a001003688c00190086140f9000140f908e040b9"),
            new GameLayoutCheck("GetRuntimeMainCameraTransform_192",0x6f2f428UL,"480000354a96d094e0031faac4830a94e00200b4e1031faa95750994f30300aa800240f908e040b9480000354096d094e00313aae1031faae2031faa64eec294"),
            new GameLayoutCheck("GetRuntimeMainCameraTransform_256",0x6f2f468UL,"e0000036530100b4e00313aaf44f41a9e1031faafe0742f88ae1c214f44f41a9e0031faafe0742f8c0035fd67996d094"),
            new GameLayoutCheck("CurrentCameraControllerManager_0",0x71d0344UL,"fe0f1ef8f44f01a9b3ee01d068b65f392801003760ab01f0006040f91f12c69420ad01b000e044f91c12c6942800805268b61f39006e8052e1031faaa7695994"),
            new GameLayoutCheck("CurrentCameraControllerManager_64",0x71d0384UL,"20010036006e8052e1031faad0695994000700b4f44f41a9e1031faafe0742f8a0bc491473ab01f0736240f9680240f909e140b989000035e00308aa6512c694"),
            new GameLayoutCheck("CurrentCameraControllerManager_128",0x71d03c4UL,"680240f9095d40f9200140f9c00100b434ad01b094e244f90a0040f9890240f94cc144392bc144399f010b6bc30000544a6540f94a0d0b8b4a815ff85f0109eb"),
            new GameLayoutCheck("CurrentCameraControllerManager_192",0x71d0404UL,"a0000054f44f41a9e0031faafe0742f8c0035fd60ae140b90a010035e00308aa4c12c694680240f9085d40f9000140f9000200b4890240f9080040f92ac14439"),
            new GameLayoutCheck("CurrentCameraControllerManager_256",0x71d0444UL,"0bc144397f010a6b43010054086540f9080d0a8b08815ff81f0109eba1000054f44f41a9e1031faafe0742f81c4d05148112c694"),
            new GameLayoutCheck("GetCameraControllerManager_0",0x73238e0UL,"fe4fbfa9f30300aae06d8052e1031faa4b1c549420010036e06d8052e1031faa741c5494000100b4e10313aae2031faafe4fc1a80d6f4414606e40f9fe4fc1a8"),
            new GameLayoutCheck("GetCameraControllerManager_64",0x7323920UL,"c0035fd655c5c094"),
            new GameLayoutCheck("get_GameCamera_0",0x718ca94UL,"fe4fbfa9f30300aac0858052e1031faade775a9420010036c0858052e1031faa07785a94000100b4e10313aae2031faafe4fc1a8e6d84a14601240f9fe4fc1a8"),
            new GameLayoutCheck("get_GameCamera_64",0x718cad4UL,"c0035fd6e820c794"),
            new GameLayoutCheck("get_main_0",0x9fa01d8UL,"fe4fbfa9b38000f060c241f9a00000b520cefbd0002c35916ad20e9460c201f9fe4fc1a800001fd6"),
            new GameLayoutCheck("get_main_icall_name",0x1966d4bUL,"556e697479456e67696e652e43616d6572613a3a6765745f6d61696e282900"),
            new GameLayoutCheck("get_transform_0",0x9fe7aa8UL,"fe0f1ef8f44f01a9947e00d0813643f9f30300aac10000b520cefb9000b0239134b40d94e10300aa803603f9e00313aaf44f41a9fe0742f820001fd6"),
            new GameLayoutCheck("get_transform_icall_name",0x19ab8ecUL,"556e697479456e67696e652e436f6d706f6e656e743a3a6765745f7472616e73666f726d282900"),
            new GameLayoutCheck("ObjectNull_CompareBaseObjects_0",0x9feef94UL,"fe57bea9f44f01a9557e00f0a86e6439f30301aaf40300aac8000037403a00f0003446f909970d9428008052a86e2439880213aa680000b52800805217000014"),
            new GameLayoutCheck("ObjectNull_CompareBaseObjects_64",0x9feefd4UL,"b30000b4940100b49f0213ebe8179f1a12000014483a00f0083546f9000140f908e040b94800003556970d94e00314aa08000014483a00d0083546f9000140f9"),
            new GameLayoutCheck("ObjectNull_CompareBaseObjects_128",0x9fef014UL,"08e040b9480000354e970d94e00313aa1f00009408000052f44f41a900010012fe57c2a8c0035fd6"),
            new GameLayoutCheck("ObjectNull_IsNativeObjectAlive_0",0x9fef0a0UL,"fe0f1ff8c00000b4000840f9e1031faae2031faafe0741f83978f9176f970d94"),
            new GameLayoutCheck("ObjectNull_GetCachedPtr_0",0x9fef0c0UL,"000840f9c0035fd6"),
            new GameLayoutCheck("ObjectNull_op_Equality_0",0x9fec060UL,"fe0f1df8f65701a9f44f02a9757e00b0763a00b0a85e6639d63646f9f30301aaf40300aac8000037603a00b0003446f9d3a20d9428008052a85e2639c00240f9"),
            new GameLayoutCheck("ObjectNull_op_Equality_64",0x9fec0a0UL,"08e040b9480000352ba30d94e00314aae10313aaf44f42a9f65741a9fe0743f8b50b0014"),
            new GameLayoutCheck("ObjectNull_op_Inequality_0",0x9feadf4UL,"fe0f1df8f65701a9f44f02a9757e00f0763a00f0a8626639d63646f9f30301aaf40300aac8000037603a00f0003446f96ea70d9428008052a8622639c00240f9"),
            new GameLayoutCheck("ObjectNull_op_Inequality_64",0x9feae34UL,"08e040b948000035c6a70d94e00314aae10313aa53100094f44f42a9f65741a9e803202a00010012fe0743f8c0035fd6"),
            new GameLayoutCheck("ObjectNull_IntPtrNotEqual",0x9e4d19cUL,"1f0001ebe0079f1ac0035fd6"),
            new GameLayoutCheck("CameraCheckPatch_0",0x882aa1cUL,"fe57bea9f44f01a9353c01d0740301f0a8f65e3994ce45f9f303002ac8000037600301f000cc45f966a86c9428008052a8f61e39800240f908e040b968000035"),
            new GameLayoutCheck("CameraCheckPatch_64",0x882aa5cUL,"bea86c94800240f9085c40f9080140f9e80200b4091940b93f01136b0d02005409e040b9c9000035b4a86c94880240f9085d40f9080140f9a80100b4091940b9"),
            new GameLayoutCheck("CameraCheckPatch_128",0x882aa9cUL,"3f01136b6901005408cd338b081140f91f0100f1e0079f1a02000014e0031f2af44f41a9fe57c2a8c0035fd6eca86c94eda86c94"),
            new GameLayoutCheck("ObjectNull_ClassUsageGOT",0xa739c68UL,0xac356c8UL),
        };
        internal const ulong CameraMainCell=0xafb7380UL, ComponentTransformCell=0xafb9668UL;
        internal static readonly StateMethod[] CameraMethods={
            new StateMethod(26979428UL,0xab29460UL,0x6f2f368UL,"71575800507c00006acd000000000008ffffffffffffffffc01b02009834030686000000ffff0000"),
            new StateMethod(19981308UL,0xa9d3918UL,0x71d0344UL,"fc331d00823000006e70000000000008ffffffffffffffff700300002f89000696000000ffff0000"),
            new StateMethod(20001388UL,0xa9d48c8UL,0x73238e0UL,"95711d00893000006e70000000000008ffffffffffffffff6f030000258b000686000000ffff0000"),
            new StateMethod(27227548UL,0xab35638UL,0x718ca94UL,"39ad2e00027d00005970000000000008ffffffffffffffff2e040000d34c030686080000ffff0000"),
            new StateMethod(31183028UL,0xaf5b3d8UL,0x9fa01d8UL,"3b76ee007e9f00005970000000000008ffffffffffffffffffffffff9901000696080010ffff0000"),
            new StateMethod(31291548UL,0xaf608a0UL,0x9fe7aa8UL,"83b523004da000006acd000000000008ffffffffffffffffffffffff320c000686080010ffff0000"),
            new StateMethod(31301668UL,0xaf61088UL,0x9feef94UL,"4b2fef0077a000000b6300000000000896f00300ffffffffffffffff2f0d000691000000ffff0200"),
            new StateMethod(31301708UL,0xaf61090UL,0x9fef0a0UL,"5e2fef0077a000000b6300000000000898f00300ffffffffffffffff300d000691000000ffff0100"),
            new StateMethod(31301748UL,0xaf61098UL,0x9fef0c0UL,"722fef0077a00000e69b000000000008ffffffffffffffffffffffff310d000681000000ffff0000"),
            new StateMethod(31304268UL,0xaf61290UL,0x9fec060UL,"67be010077a000000b630000000000080ff10300ffffffffffffffff700d000696080000ffff0200"),
            new StateMethod(31304308UL,0xaf61298UL,0x9feadf4UL,"73be010077a000000b6300000000000811f10300ffffffffffffffff710d000696080000ffff0200"),
        };
        internal static readonly StateField[] ControllerFields={
            new StateField(12425,9,"m_CameraControllerManager",0xd8UL,0x1afca14UL,0xadbaa70UL,1179652U,32002,3937257UL,67203611U,43110328UL,"55801d00707000001b720104"),
            new StateField(32002,0,"EKIPKGNKILM",0x20UL,0x19e9224UL,0xad96ac0UL,1179649U,40830,7952809UL,67363755U,45032056UL,"15c65a005a700000abe30304"),
            new StateField(41079,0,"m_CachedPtr",0x10UL,0x1ab672cUL,0xad99640UL,2149056513U,-1,17680078UL,67110306U,47555464UL,"3a33ef00e79b0000a2050004"),
        };
        internal static readonly ObjectClassProfile[] ControllerClasses={
            new ObjectClassProfile(32002,"COW.GamePlay.CameraControllerManager",0,41057,7951736UL,7768922UL,"e4c15a00c6f757006e700000ffffffff7ead00006e700000ffffffff00001000aae30300d24c0300ffffffff67310000dc210000ffffffffa62a0800ffffffff2e000100130000000300040000000000000c0000007d0002",1179648U,152U,0U,33586432U,0UL,152U,true),
            new ObjectClassProfile(40830,"UnityEngine.Camera",0,41031,3110550UL,17627183UL,"02e310009b64ee0059700000ffffffffab61000059700000ffffffff01011000fc140700cfce0400ffffffff38540000ef2b0000ffffffff9d320b00ffffffff71002600070000000200040000000000000c00007e000002",1179648U,24U,24U,33554558U,0UL,24U,true),
            new ObjectClassProfile(41031,"UnityEngine.Behaviour",0,41037,17675211UL,17627183UL,"3720ef009b64ee00ab610000ffffffff41740000ab610000ffffffff01001000ffffffffa1d90400ffffffff5e560000ffffffffffffffffdf390b00ffffffff04000200000000000000040000000000000c000049010002",1179648U,24U,0U,33554761U,0UL,24U,true),
            new ObjectClassProfile(41037,"UnityEngine.Component",0,41079,2329274UL,17627183UL,"26f704009b64ee0041740000ffffffffb0b4000041740000ffffffff01001000ffffffffb2d90400ffffffff60560000fffffffffffffffff7390b00ffffffff31000300000000000000040000000000000c00004f010002",1179648U,24U,0U,33554767U,0UL,24U,true),
            new ObjectClassProfile(41079,"UnityEngine.Object",0,37718,2123429UL,17627183UL,"11d301009b64ee00b0b40000ffffffff9eb40000b0b40000ffffffff0900100016190700abda0400ffffffff77560000ffffffffffffffff523b0b00ffffffff5d000200060000000000040000000000180c000079010002",1179648U,24U,4U,33554809U,0UL,24U,true),
        };
        internal const ulong ObjectNullEqualityInit=0xafb9997UL, ObjectNullInequalityInit=0xafb9998UL, ObjectNullCompareInit=0xafb991bUL;
        internal const ulong ObjectNullClassCell=0xac356c8UL;
        internal const ulong ControllerFacadeInitCell=0xafa67edUL;
        internal const ulong GameCameraGetterInitCell=0xafa571aUL, CameraPatchInitCell=0xafb07bdUL;
        internal const int GameCameraGetterGate=0x21bc0;
    }
}
