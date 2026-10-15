using System;

namespace HeadBridge.Mapping
{
    public sealed partial class Reader
    {
        private static void MetadataClassIdentity(ObjectReads reads, ulong klass, ObjectClassProfile profile, GameLayoutResult layout)
        {
            ulong row = checked(layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + (ulong)profile.Index * 88UL);
            Expect(EqualBytes(reads.Read(row, 88), Hex(profile.RecordHex)), "head cache class definition record");
            Expect(reads.Value(klass + 0x78) == klass && reads.Word(klass + 0x11c) == profile.Token &&
                reads.Value(klass + 0x10) == checked(layout.RuntimeMetadataBase + profile.NameOffset) &&
                reads.Value(klass + 0x18) == checked(layout.RuntimeMetadataBase + profile.NamespaceOffset), "head cache class identity " + profile.Name);
        }
        private static void VerifyHeadDictionary(ObjectReads reads, ulong klass, ModuleResult module, GameLayoutResult layout)
        {
            ObjectClassProfile definition = ObjectReference.HeadDictionaryProfile;
            MetadataClassIdentity(reads, klass, definition, layout);
            ulong descriptor = checked(module.LoadBias + ObjectReference.HeadDictionaryTypeRva);
            Expect(reads.Word(descriptor + 8) == ObjectReference.HeadDictionaryTypeBits, "head dictionary declared type flags");
            ulong generic = reads.Pointer(descriptor, "head dictionary generic class");
            Expect(reads.Value(klass + 0x60) == generic && reads.Value(klass + 0x20) == generic &&
                (reads.Word(klass + 0x28) >> 16 & 255) == 0x15 && reads.Value(generic + 0x18) == klass,
                "head dictionary closed generic class");
            ulong type = reads.Pointer(generic, "head dictionary definition type");
            Expect((reads.Word(type + 8) >> 16 & 255) == 0x12 && reads.Value(type) ==
                checked(layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + (ulong)definition.Index * 88UL),
                "head dictionary generic definition");
            ulong inst = reads.Pointer(generic + 8, "head dictionary class arguments");
            Expect(reads.Word(inst) == 2, "head dictionary generic argument count");
            ulong arguments = reads.Pointer(inst + 8, "head dictionary type arguments");
            ulong keyType = reads.Pointer(arguments, "head dictionary key type"), valueType = reads.Pointer(arguments + 8, "head dictionary value type");
            Expect((reads.Word(keyType + 8) >> 16 & 255) == 14, "head dictionary key must be String");
            Expect((reads.Word(valueType + 8) >> 16 & 255) == 0x12 && reads.Value(valueType) ==
                checked(layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + 31705UL * 88UL),
                "head dictionary value must be BFOONIGAIFK");
            uint size = reads.Word(klass + 0xf8);
            Expect(size >= 40 && size <= 1048576, "head dictionary runtime storage bound");
        }
        private static void VerifyHeadStringClass(ObjectReads reads, ulong klass, GameLayoutResult layout)
        {
            ObjectClassProfile profile = ObjectReference.HeadStringProfile;
            MetadataClassIdentity(reads, klass, profile, layout);
            Expect(reads.Value(klass + 0x68) == checked(layout.RuntimeMetadataBase + GameLayoutReference.TypeDefinitionsOffset + (ulong)profile.Index * 88UL) &&
                (reads.Word(klass + 0x28) >> 16 & 255) == 14, "head cache key String identity");
            // System.String is variable-length. Its native initial-size word is
            // opaque in this build; the key length and character reads are bounded.
        }
        private ulong FindCachedHead(ObjectReads reads, GameProcess game, ModuleResult module, GameLayoutResult layout,
            PlayerObjectResult result, ObjectClassProfile player, ulong wrappers, ulong wrapperLength, Action<string> progress)
        {
            result.HeadSource = "MODEL_DICTIONARY";
            if (HotfixEntry(reads, wrappers, wrapperLength, 0x21f1a) || HotfixEntry(reads, wrappers, wrapperLength, 0x4f35))
            { result.HeadStatus = "HOTFIX_ACTIVE_MODEL_LOOKUP"; return 0; }
            ulong klass = reads.Pointer(result.LocalPlayer, "local player class");
            int count = BitConverter.ToUInt16(reads.Read(klass + 0x12a, 2), 0);
            int start = BitConverter.ToInt32(Hex(player.RecordHex), 0x38);
            Expect(start >= 0 && count == BitConverter.ToUInt16(Hex(player.RecordHex), 0x4a), "head lookup player vtable metadata");
            if (count <= 29 || reads.Word(checked(layout.RuntimeMetadataBase + ObjectReference.VtableTableOffset + ((ulong)start + 29UL) * 4UL)) != 0x600677bfU ||
                reads.Value(klass + 0x308) != checked(module.LoadBias + 0x7013344UL))
            { result.HeadStatus = "UNSUPPORTED_MODEL_VIRTUAL_TARGET"; return 0; }
            result.HeadModel = reads.Value(result.LocalPlayer + 0x1530);
            if (result.HeadModel == 0) { result.HeadStatus = "NOT_READY_MODEL_CACHE_NULL"; return 0; }
            ObjectReads.User(result.HeadModel, 8, "head model cache");
            ulong modelClass = reads.Pointer(result.HeadModel, "head model cache class");
            Expect(ReadObjectClass(reads, modelClass, layout, progress).Index == 31706, "head model cache class type");
            ulong dictionary = reads.Value(result.HeadModel + 0x10);
            if (dictionary == 0) { result.HeadStatus = "NOT_READY_DICTIONARY_NULL"; return 0; }
            ObjectReads.User(dictionary, 8, "head model dictionary");
            ulong dictionaryClass = reads.Pointer(dictionary, "head dictionary class");
            VerifyHeadDictionary(reads, dictionaryClass, module, layout);
            uint used = reads.Word(dictionary + 0x20); reads.Word(dictionary + 0x24); // Snapshot the version too.
            Expect(used <= 512, "head dictionary used-entry bound");
            result.HeadCacheEntries = checked((int)used);
            if (used == 0) { result.HeadStatus = "NOT_READY_BONE_NOT_CACHED"; return 0; }
            ulong entries = reads.Pointer(dictionary + 0x18, "head dictionary entries");
            reads.Pointer(entries, "head dictionary entry array class");
            ulong capacity = reads.Value(entries + 0x18);
            Expect(capacity >= used && capacity <= 8192, "head dictionary entry-array bound");
            byte[] data = new byte[checked((int)used * 24)];
            for (int offset = 0; offset < data.Length; offset += 4096)
            {
                int length = Math.Min(4096, data.Length - offset);
                byte[] part = reads.Read(checked(entries + 0x20UL + (ulong)offset), length);
                Array.Copy(part, 0, data, offset, length);
            }
            byte[] wanted = Hex(ObjectReference.HeadKeyUtf16Hex);
            ulong provider = 0, stringClass = 0;
            int hits = 0;
            for (int i = 0; i < used; i++)
            {
                int at = i * 24;
                if (BitConverter.ToInt32(data, at) < 0) continue; // Removed entry.
                int next = BitConverter.ToInt32(data, at + 4);
                Expect(next >= -1 && next < used, "head dictionary entry link bound");
                ulong key = BitConverter.ToUInt64(data, at + 8);
                if (key == 0) continue;
                ObjectReads.User(key, 8, "head dictionary string key");
                ulong keyClass = reads.Pointer(key, "head dictionary String class");
                if (stringClass == 0) { VerifyHeadStringClass(reads, keyClass, layout); stringClass = keyClass; }
                Expect(keyClass == stringClass, "head dictionary consistent String class");
                uint characters = reads.Word(key + 0x10);
                Expect(characters <= 256, "head dictionary key length bound");
                if (characters * 2 != wanted.Length || !EqualBytes(reads.Read(key + 0x14, wanted.Length), wanted)) continue;
                hits++;
                Expect(hits == 1, "duplicate bone_Head dictionary entries");
                provider = BitConverter.ToUInt64(data, at + 16);
            }
            if (progress != null) progress("HeadCacheLookup Entries=" + used + " Key=bone_Head Matches=" + hits + " Writes=NONE");
            if (hits == 0) { result.HeadStatus = "NOT_READY_BONE_NOT_CACHED"; return 0; }
            if (provider == 0) { result.HeadStatus = "NOT_READY_CACHED_NODE_NULL"; return 0; }
            ObjectReads.User(provider, 8, "cached head node");
            Expect(ReadObjectClass(reads, reads.Pointer(provider, "cached head node class"), layout, progress).Index == 31705,
                "cached head node value class");
            return provider;
        }
    }
}
