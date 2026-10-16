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
        internal static readonly GameLayoutCheck[] Anchors = {
            new GameLayoutCheck("GetAimRotation_0",0x6f249acUL,"fe4fbfa9f30300aa20978052e1031faa181864942001003620978052e1031faa41186494600100b4e10313aae2031faafe4fc1a8b87a5414601646bd611a46bd"),
            new GameLayoutCheck("GetAimRotation_64",0x6f249ecUL,"621e46bd632246bdfe4fc1a8c0035fd61fc1d094"),
        };
    }
}
