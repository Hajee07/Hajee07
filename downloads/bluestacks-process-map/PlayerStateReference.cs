// Generated from exact SHA-256-verified ELF/metadata inputs.
namespace HeadBridge.Mapping {
    internal static class PlayerStateReference {
        internal static readonly ObjectClassProfile[] Classes = {
            new ObjectClassProfile(31911,"COW.GamePlay.AttackableEntity",0,31912,7942031UL,7768922UL,"fb9b5a00c6f757001f5c0000ffffffff0f6600001f5c0000ffffffff8000100034e203002f4b0300ffffffff32310000ffffffff0a1600009f270800696300001d0004000200000000004f0001000300000c0000a87c0002",1179648U,136U,0U,33586344U,0,128U,true),
            new ObjectClassProfile(36356,"GCommon.BitArrayBoolean",0,36353,8678914UL,8633433UL,"6eda6500c528650069620000ffffffff5f62000069620000ffffffff01001000ad4b040042100400ffffffffffffffff1e260000ffffffffd9500a00ffffffff09000000020000000100040000000000000c0000048e0002",1179648U,32U,0U,33590788U,0,28U,true),
            new ObjectClassProfile(36353,"GCommon.BitArray",0,37718,8678878UL,8633433UL,"4ada6500c52865005f620000ffffffff9eb400005f620000ffffffff01001000a74b04001e100400ffffffffffffffffffffffffffffffffd1500a00ffffffff13000000030000000000040000000000000c0000028e0002",1179648U,24U,0U,33590786U,0,20U,true),
        };
        internal static readonly StateField[] Fields = {
            new StateField(31824,182,"<DJJMAHEIDID>k__BackingField",0x430UL,0x19e689cUL,0xad992c0UL,2148007937U,-1,7875763UL,67360464U,44992564UL,"1f995900a99b0000d0d60304"),
            new StateField(31824,432,"<INNGIOBPAJM>k__BackingField",0xa6cUL,0x19e6c84UL,0xad964e0UL,2147614721U,-1,7879432UL,67360714U,44995564UL,"74a759000c630000cad70304"),
            new StateField(31824,509,"NBIIBJBALJD",0xad0UL,0x19e6db8UL,0xadad040UL,1179652U,36356,7880873UL,67360791U,44996488UL,"15ad59006b62000017d80304"),
            new StateField(31911,0,"CGJLEBOGBNP",0x7cUL,0x19e8ba4UL,0xad964e0UL,2147614721U,-1,7941954UL,67363381U,45027568UL,"ae9b5a000c63000035e20304"),
            new StateField(36353,2,"m_Value",0x10UL,0x1a03178UL,0xad9dd30UL,2148073476U,-1,2119572UL,67390378U,45351532UL,"00c401009e170100aa4b0404"),
            new StateField(36356,1,"m_Mode",0x18UL,0x1a03198UL,0xae67130UL,2148597764U,36355,4735628UL,67390383U,45351592UL,"f8ae2900ae220100af4b0404"),
        };
        internal static readonly StateMethod[] Methods = {
            new StateMethod(26979908UL,0xab294c0UL,0x6f2ff24UL,"09341f00507c0000a89b000000000008ffffffffffffffffffffffffa434030686080000ffff0000"),
            new StateMethod(26988468UL,0xab29b70UL,0x6f36230UL,"db685800507c00000b63000000000008ffffffffffffffffd84d00007a35030686080000ffff0000"),
            new StateMethod(26988508UL,0xab29b78UL,0x6f36298UL,"ec685800507c00000b63000000000008ffffffffffffffffffffffff7b35030686080000ffff0000"),
            new StateMethod(26991948UL,0xab29e28UL,0x6f38834UL,"4d4e0200507c00000b63000000000008fffffffffffffffff31b0200d1350306c600000046000000"),
            new StateMethod(27210788UL,0xab34920UL,0x717533cUL,"b39a5a00a77c00000b63000000000008ffffffffffffffff47040000304b0306e60900002d000000"),
            new StateMethod(29229068UL,0xab971e8UL,0x8279898UL,"5bbe0100048e00000b63000000000008cfa50200ffffffffffffffff4910040696080000ffff0100"),
        };
        internal static readonly GameLayoutCheck[] Anchors = {
            new GameLayoutCheck("get_TeamIndex_0",0x6f2ff24UL,"003044b9c0035fd6"),
            new GameLayoutCheck("get_IsReallyDead_0",0x6f36230UL,"fe4fbfa9f30300aa00bb8952e1031faaf7d163942001003600bb8952e1031faa"),
            new GameLayoutCheck("get_IsReallyDead_32",0x6f36250UL,"20d26394000200b4e10313aae2031faafe4fc1a8c8ce5314e00313aae1031faa"),
            new GameLayoutCheck("get_IsReallyDead_64",0x6f36270UL,"33fc0894a000003668b269391f010071e0179f1a02000014e0031f2afe4fc1a8"),
            new GameLayoutCheck("get_IsReallyDead_96",0x6f36290UL,"c0035fd6f97ad094"),
            new GameLayoutCheck("get_IsPendingRevive_0",0x6f36298UL,"00b06939c0035fd6"),
            new GameLayoutCheck("IsVisible_0",0x6f38834UL,"fe4fbfa9f30300aa607e83524000a072e1031faa75c8639440010036607e8352"),
            new GameLayoutCheck("IsVisible_32",0x6f38854UL,"4000a072e1031faa9dc86394200100b4e10313aae2031faafe4fc1a845c55314"),
            new GameLayoutCheck("IsVisible_64",0x6f38874UL,"606a45f9e1031faafe4fc1a806044d147d71d094"),
            new GameLayoutCheck("get_IsDead_0",0x717533cUL,"fe4fbfa9f30300aae0888052e1031faab4d55a9420010036e0888052e1031faa"),
            new GameLayoutCheck("get_IsDead_32",0x717535cUL,"ddd55a94000100b4e10313aae2031faafe4fc1a885d24a1460f24139fe4fc1a8"),
            new GameLayoutCheck("get_IsDead_64",0x717537cUL,"c0035fd6be7ec794"),
            new GameLayoutCheck("op_Implicit_0",0x8279898UL,"fe0f1ff8600100b4081040b9091840b91f010071ea079f1a1f050031e8179f1a"),
            new GameLayoutCheck("op_Implicit_32",0x82798b8UL,"3f0500714001881afe0741f8c0035fd66c6d8394"),
        };
        internal static readonly StateVisibility[] Visibility = {
            new StateVisibility(12654,48289456UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(12655,48291484UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(30536,49900220UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(31824,49948772UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(32360,49983916UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34527,50346380UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34541,50349224UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34542,50351260UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34543,50353296UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34545,50355348UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34547,50357448UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34548,50359476UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34554,50361632UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34556,50363668UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34561,50365904UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34562,50367972UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34564,50370032UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34570,50372252UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34571,50374280UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34573,50376308UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34620,50379632UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34621,50381660UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34624,50383752UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34630,50386320UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34631,50388380UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34632,50390140UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34633,50392168UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34655,50395436UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34656,50397212UL,0x60066ba1U,0x6f38834UL),
            new StateVisibility(34657,50398988UL,0x60078a93U,0x7c6a7c4UL),
            new StateVisibility(35618,50485372UL,0x60066ba1U,0x6f38834UL),
        };
    }
}
