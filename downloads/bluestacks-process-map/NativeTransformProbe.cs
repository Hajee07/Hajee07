using System;
using System.Collections.Generic;

namespace HeadBridge.Mapping
{
    public sealed partial class Reader
    {
        private static void NativeAnchors(ObjectReads reads, ulong bias, GameLayoutCheck[] checks)
        {
            foreach (GameLayoutCheck check in checks)
                Expect(EqualBytes(reads.Read(checked(bias + check.Address), check.Expected(bias).Length), check.Expected(bias)),
                    "native Transform code identity " + check.Name);
        }
        private static float[] NativeVector(byte[] data, int offset, int components)
        {
            float[] result = new float[4];
            for (int i = 0; i < components; i++)
            {
                result[i] = BitConverter.ToSingle(data, offset + i * 4);
                Expect(!float.IsNaN(result[i]) && !float.IsInfinity(result[i]), "finite native TRS component");
            }
            return result;
        }
        // Same multiplication/addition order and lane permutations as the
        // exact ARM64 0x691584 loop. No fused multiply-add is used there.
        private static float[] NativeParentPosition(float[] value, byte[] trs)
        {
            float[] t = NativeVector(trs, 0, 3), q = NativeVector(trs, 16, 4), scale = NativeVector(trs, 32, 3);
            double norm = (double)q[0] * q[0] + (double)q[1] * q[1] + (double)q[2] * q[2] + (double)q[3] * q[3];
            Expect(norm >= 0.98 && norm <= 1.02, "native parent quaternion norm");
            float[] scaled = new float[4], result = new float[4];
            float[] rev = { q[1], q[0], q[3], q[2] }, ext = { q[2], q[3], q[0], q[1] }, revExt = { q[3], q[2], q[1], q[0] };
            float[] c1 = { -2, 2, -2, 0 }, c2 = { 2, -2, -2, 0 }, c3 = { -2, -2, 2, 0 };
            for (int i = 0; i < 4; i++) scaled[i] = value[i] * scale[i];
            for (int i = 0; i < 4; i++)
            {
                float a = rev[i] * (c1[i] * q[1]) - ext[i] * (c2[i] * q[2]);
                float b = revExt[i] * (c3[i] * q[2]) - rev[i] * (c1[i] * q[0]);
                float c = ext[i] * (c2[i] * q[0]) - revExt[i] * (c3[i] * q[1]);
                float first = scaled[i] + a * scaled[0];
                float second = b * scaled[1] + c * scaled[2];
                result[i] = (first + second) + t[i];
            }
            return result;
        }
        private sealed class NativeHeadJobChangedException : InvalidOperationException
        { internal NativeHeadJobChangedException(string detail) : base(detail) { } }
        private sealed class NativeHeadMotionException : InvalidOperationException
        { internal NativeHeadMotionException(string detail) : base(detail) { } }
        private sealed class NativeTrsChunk
        { internal int First, Length; internal readonly List<int> Indices = new List<int>(); }
        private static List<NativeTrsChunk> NativeChunks(List<int> chain)
        {
            List<int> sorted = new List<int>(chain); sorted.Sort();
            List<NativeTrsChunk> chunks = new List<NativeTrsChunk>(); NativeTrsChunk chunk = null;
            int previous = -1, total = 0;
            foreach (int index in sorted)
            {
                if (chunk == null || (index-previous-1)*48 > 192 || (index-chunk.First+1)*48 > 4096)
                { chunk = new NativeTrsChunk { First=index }; chunks.Add(chunk); }
                int length = (index-chunk.First+1)*48; total += length-chunk.Length;
                chunk.Length=length; chunk.Indices.Add(index); previous=index;
            }
            Expect(chain.Count > 0 && chain.Count <= 128 && total <= 32768, "native TRS capture byte bound");
            return chunks;
        }
        private Dictionary<int, byte[]> NativeCapture(GameProcess game, ulong matrices, List<NativeTrsChunk> chunks, bool reverse)
        {
            Dictionary<int, byte[]> rows = new Dictionary<int, byte[]>();
            for (int i=0; i<chunks.Count; i++)
            {
                NativeTrsChunk chunk = chunks[reverse ? chunks.Count-1-i : i];
                ulong address = checked(matrices+(ulong)chunk.First*48UL);
                ObjectReads.User(address, 1, "native TRS capture");
                Expect(chunk.Length > 0 && chunk.Length <= 4096 && checked(address+(ulong)chunk.Length) <= 0x0000800000000000UL,
                    "native TRS capture range");
                byte[] block = Virtual(game.Root, address, chunk.Length);
                foreach (int index in chunk.Indices)
                {
                    byte[] row = new byte[48]; Array.Copy(block,(index-chunk.First)*48,row,0,48); rows.Add(index,row);
                }
            }
            return rows;
        }
        private static int NativeIdentityRecheck(ObjectReads reads,ulong hierarchy=0)
        {
            try { return hierarchy==0 ? reads.Recheck() : reads.RecheckNativeHierarchy(hierarchy); }
            catch (PhysicalScopeLimitException) { throw; }
            catch (NativeHeadJobChangedException) { throw; }
            catch (InvalidOperationException error)
            { throw new InvalidOperationException("Native identity recheck failed: " + error.Message, error); }
        }
        private void ReadNativeHeadPosition(GameProcess game, ModuleResult module, PlayerObjectResult result, Action<string> progress)
        {
            for (int attempt=1; attempt<=3; attempt++)
            {
                result.HeadSampleAttempts=attempt;
                if (progress!=null) progress("NativeHeadSampleAttempt Attempt="+attempt+" MaximumAttempts=3");
                try { ReadNativeHeadAttempt(game,module,result); return; }
                catch (NativeHeadJobChangedException error)
                {
                    if(progress!=null)progress("NativeHeadSampleJobChange Attempt="+attempt+" Discarded=True Detail="+error.Message);
                    if(attempt==3)throw;
                    // The entire attempt is discarded. A fresh attempt must revalidate
                    // code, bindings, hierarchy, zero jobs and both TRS captures.
                }
                catch (NativeHeadMotionException error)
                {
                    if (progress!=null) progress("NativeHeadSampleMotion Attempt="+attempt+" Discarded=True Detail="+error.Message);
                    if (attempt==3) throw;
                    // Changed selected TRS rows are also retryable. Each fresh
                    // attempt revalidates bindings, hierarchy and backlinks.
                    // Reader-global call/time budgets are never reset.
                }
            }
        }
        private void ReadNativeHeadAttempt(GameProcess game, ModuleResult module, PlayerObjectResult result)
        {
            result.HeadWorldStatus = "NOT_READY_MANAGED_TRANSFORM";
            if (result.HeadStatus != "MANAGED_TRANSFORM_VERIFIED") return;
            ObjectReads reads = new ObjectReads(this, game.Root);
            NativeAnchors(reads, module.LoadBias, NativeTransformReference.Il2CppAnchors);
            ulong bias = 0;
            ulong[] cells = { 0xafb9e00, 0xafb9e10 }, targets = { 0x45ea4c, 0x45ec64 };
            for (int i = 0; i < cells.Length; i++)
            {
                ulong target = reads.Value(checked(module.LoadBias + cells[i]),"PositionIcallBinding"+i);
                if (target == 0) continue;
                ObjectReads.User(target, 4, "resolved Unity position icall");
                Expect(target > targets[i], "Unity icall load-bias subtraction");
                ulong observed = target - targets[i]; ObjectReads.User(observed, 4096, "Unity load bias");
                Expect(bias == 0 || bias == observed, "consistent resolved Unity position bindings"); bias = observed;
            }
            result.HeadWorldStatus = "NOT_READY_POSITION_ICALL_UNRESOLVED";
            if (bias == 0) { NativeIdentityRecheck(reads); return; }
            Expect(EqualBytes(reads.Read(bias, 64), Hex(NativeTransformReference.HeaderHex)), "Unity ELF header");
            Expect(EqualBytes(reads.Read(bias + 64, NativeTransformReference.ProgramsHex.Length / 2), Hex(NativeTransformReference.ProgramsHex)), "Unity ELF program tables");
            Expect(EqualBytes(reads.Read(bias + 0x308, 24), Hex(NativeTransformReference.NoteHex)), "Unity build ID");
            NativeAnchors(reads, bias, NativeTransformReference.UnityAnchors);
            result.UnityLoadBias = bias;
            Expect(reads.Value(result.HeadProvider + 0x10,"HeadProvider.Transform") == result.HeadTransform, "head provider still references the verified Transform");
            ulong native = reads.Value(result.HeadTransform + 0x10,"ManagedTransform.NativePointer");
            result.HeadWorldStatus = "NOT_READY_NATIVE_TRANSFORM_NULL";
            if (native == 0) { NativeIdentityRecheck(reads); return; }
            ObjectReads.User(native, 8, "native head Transform");
            ulong data = reads.Pointer(native + 0x38, "native Transform hierarchy");
            int index = BitConverter.ToInt32(reads.Read(native + 0x40, 4,"NativeTransform.Index"), 0);
            // The native getter synchronizes/clears an outstanding job here.
            // A read-only sample requires it already to be clear.
            ulong job = reads.Value(data,"Hierarchy.JobHandle"); uint jobTag = reads.Word(data + 8,"Hierarchy.JobTag");
            if (job != 0 || jobTag != 0)
            {
                result.HeadWorldStatus = "NOT_READY_HIERARCHY_JOB_PENDING";
                result.HeadWorldError = "Job=0x" + job.ToString("x") + " Tag=" + jobTag;
                NativeIdentityRecheck(reads,data); return;
            }
            uint capacity = reads.Word(data + 0x10,"Hierarchy.Capacity");
            Expect(capacity > 0 && capacity <= 65536 && index >= 0 && (uint)index < capacity, "native hierarchy capacity/index bound");
            ulong matrices = reads.Pointer(data + 0x18, "native TRS array"), parents = reads.Pointer(data + 0x20, "native parent-index array"),
                transforms = reads.Pointer(data + 0x30, "native Transform backlink array");
            HashSet<int> visited = new HashSet<int>(); List<int> chain = new List<int>();
            ulong expectedNative = native;
            for (int depth = 0; ; depth++)
            {
                Expect(depth < 128 && index >= 0 && (uint)index < capacity && visited.Add(index), "native parent-chain bound/cycle");
                ulong current = reads.Pointer(checked(transforms + (ulong)index * 8UL), "hierarchy Transform backlink");
                Expect(current == expectedNative && reads.Value(current + 0x38,"NativeTransform.Hierarchy") == data && reads.Word(current + 0x40,"NativeTransform.Index") == (uint)index,
                    "native hierarchy object/index backlinks");
                chain.Add(index);
                int parent = BitConverter.ToInt32(reads.Read(checked(parents + (ulong)index * 4UL), 4,"Hierarchy.ParentIndex"), 0);
                expectedNative = reads.Value(current + 0x90,"NativeTransform.ParentPointer");
                if (parent == -1) { Expect(expectedNative == 0, "native root parent backlink"); result.HeadParentCount = depth; break; }
                Expect(parent >= 0 && (uint)parent < capacity && expectedNative != 0, "native parent-index/Transform link");
                index = parent;
            }
            NativeIdentityRecheck(reads,data);
            List<NativeTrsChunk> chunks = NativeChunks(chain);
            // Keep all code/identity verification outside the two TRS copies.
            // Nearby rows share a bounded transport read, but only selected
            // rows participate in the comparison; gap bytes are unused.
            Dictionary<int, byte[]> first = NativeCapture(game,matrices,chunks,false);
            Dictionary<int, byte[]> second = NativeCapture(game,matrices,chunks,true);
            foreach (int slot in chain)
                if (!EqualBytes(first[slot],second[slot]))
                {
                    NativeIdentityRecheck(reads,data);
                    throw new NativeHeadMotionException("TRS_CHANGED Index="+slot+" Address=0x"+(matrices+(ulong)slot*48UL).ToString("x")+" Bytes=48");
                }
            float[] position = null;
            for (int depth=0; depth<chain.Count; depth++)
            {
                byte[] trs = first[chain[depth]];
                NativeVector(trs,0,3); NativeVector(trs,16,4); NativeVector(trs,32,3);
                position = depth==0 ? NativeVector(trs,0,3) : NativeParentPosition(position,trs);
                for (int axis=0; axis<3; axis++)
                    Expect(!float.IsNaN(position[axis]) && !float.IsInfinity(position[axis]) && Math.Abs(position[axis])<=10000000,
                        "finite bounded head world position");
            }
            int observations = NativeIdentityRecheck(reads,data)+chain.Count;
            result.HeadCaptureChunks=chunks.Count;
            result.NativeHeadTransform = native; result.HeadHierarchyCapacity = capacity;
            result.HeadWorldX = position[0]; result.HeadWorldY = position[1]; result.HeadWorldZ = position[2];
            result.HeadWorldObservations = observations; result.HeadWorldStatus = "SAMPLED_READ_ONLY";
        }
    }
}
