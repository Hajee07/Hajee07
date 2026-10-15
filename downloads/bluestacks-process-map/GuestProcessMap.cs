using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

namespace HeadBridge.Mapping
{
    public sealed class RamRange
    {
        public ulong First;
        public ulong Last;
        public RamRange(ulong first, ulong last) { First = first; Last = last; }
    }
    public sealed class KernelContext
    {
        public readonly ulong Root;
        public readonly ulong Slide;
        public readonly ulong InitialActiveMm;
        internal KernelContext(ulong root, ulong slide, ulong initialActiveMm)
        { Root = root; Slide = slide; InitialActiveMm = initialActiveMm; }
    }
    public sealed class GameProcess
    {
        public int Pid;
        public string Name;
        public ulong Task;
        public ulong Mm;
        public ulong PgdVirtual;
        public ulong Root;
        public int TasksVisited;
    }
    public sealed class LibraryMapping
    {
        public string Name;
        public ulong Start;
        public ulong End;
        public ulong FilePageOffset;
        public bool Arm64ElfHeader;
        public bool Revalidated;
    }
    public sealed class LibraryResult
    {
        public int VmasVisited;
        public int FilesInspected;
        public int RepeatedFilesSkipped;
        public string StopReason = "INCOMPLETE";
        public bool CompleteVmaList;
        public readonly List<LibraryMapping> Mappings = new List<LibraryMapping>();
    }
    public sealed partial class Reader
    {
        // These addresses and offsets belong only to the inspected boot image.
        public const ulong BannerVa = 0xffffffff81e00140UL;
        public const ulong InitTaskVa = 0xffffffff822147c0UL;
        public const ulong InitMmVa = 0xffffffff8225ebe0UL;
        public const ulong InitPgdVa = 0xffffffff8220e000UL;
        public const ulong SyscallVa = 0xffffffff81a00020UL;
        public const ulong TrampolineVa = 0xffffffff81c02000UL;
        public const string BannerHex = "4c696e75782076657273696f6e20342e31392e31393520286275696c64406275696c645f31382920286763632076657273696f6e20342e36203230313230313036202870726572656c65617365292028474343292c20474e55206c642028474e552042696e7574696c732920322e32332e322920233120534d5020505245454d505420467269204f63742031372031303a32323a34392049535420323032350a00";
        private const string MmAnchor = "554889e54883ec204c896df84c8dafe00700004c8965f04989fc48895de84c89efe84aeb8500498b9c24c00400004885db740c41f644242620751df0ff43584c";
        private const string CommAnchor = "554889e54883ec204c8965e84c8da2e007000048895de04c8975f84889fb4989d64c89e74c896df04989f5e8b0d16d00498db6200700004c89ea4889dfe8deff";
        private const string TasksAnchor = "4d8bae700400004d8db590fbffff";
        private const string PidAnchor = "8b93700500004c8b0331f68b4de8";
        private const string PgdAnchor = "498b742450";
        private const string VmaAnchor = "554885d2488956184889e57417488b4a10488972104885c948894e107404488971185dc34885c948893774064883e920ebe348c74610000000005dc30f1f4000";
        private const string DentryAnchor = "4d8b7728498d47384939c67539418b57244d8d6c24084c89f64c89ef83c201e8";
        private const ulong AddressMask = 0x000ffffffffff000UL;
        private readonly Func<ulong, int, string> transport;
        private readonly RamRange[] ram;
        private readonly Stopwatch timer = Stopwatch.StartNew();
        private struct MappingKey : IEquatable<MappingKey>
        {
            internal ulong Root;
            internal ulong Page;
            public bool Equals(MappingKey other) { return Root == other.Root && Page == other.Page; }
            public override bool Equals(object other) { return other is MappingKey && Equals((MappingKey)other); }
            public override int GetHashCode() { return Root.GetHashCode() ^ Page.GetHashCode(); }
        }
        private readonly Dictionary<MappingKey, ulong> translations = new Dictionary<MappingKey, ulong>();
        public int PhysicalCalls { get; private set; }
        public int TranslationCacheHits { get; private set; }
        public LibraryResult LastLibraries { get; private set; }
        private static readonly Regex Reply = new Regex("\\ABridgeRead=PASS BytesRead=([0-9]+) Hex=([0-9a-fA-F]+)\\s*\\z", RegexOptions.CultureInvariant);

        private int physicalScopeLimit=30000;
        internal sealed class PhysicalScopeLimitException : InvalidOperationException
        { internal PhysicalScopeLimitException() : base("Physical call scope exhausted; partial results only.") { } }
        private sealed class PhysicalScope : IDisposable
        {
            private Reader owner; private readonly int previous;
            internal PhysicalScope(Reader owner,int additional)
            { this.owner=owner;previous=owner.physicalScopeLimit;owner.physicalScopeLimit=Math.Min(previous,checked(owner.PhysicalCalls+additional)); }
            public void Dispose() { if(owner!=null){owner.physicalScopeLimit=previous;owner=null;} }
        }
        internal IDisposable PhysicalCallScope(int maximumAdditionalCalls)
        {
            if(maximumAdditionalCalls<1 || maximumAdditionalCalls>30000)throw new ArgumentOutOfRangeException("maximumAdditionalCalls");
            return new PhysicalScope(this,maximumAdditionalCalls);
        }

        public Reader(Func<ulong, int, string> transport, RamRange[] ram)
        {
            if (transport == null || ram == null || ram.Length == 0) throw new ArgumentException("Reader requires a transport and verified RAM ranges.");
            this.transport = transport; this.ram = ram;
        }
        public static byte[] Hex(string text)
        {
            if (text == null || (text.Length & 1) != 0) throw new FormatException("Invalid hexadecimal length.");
            byte[] output = new byte[text.Length / 2];
            for (int i = 0; i < output.Length; i++) output[i] = byte.Parse(text.Substring(i * 2, 2), NumberStyles.HexNumber, CultureInfo.InvariantCulture);
            return output;
        }
        public static bool Canonical(ulong address)
        {
            ulong top = address >> 47;
            return top == 0 || top == 0x1ffffUL;
        }
        public static ulong[] SlidesFromLstar(ulong value)
        {
            List<ulong> slides = new List<ulong>(); slides.Add(0);
            foreach (ulong entry in new ulong[] { SyscallVa, TrampolineVa })
                if (value >= entry)
                {
                    ulong candidate = value - entry;
                    if (candidate <= 0x40000000UL && (candidate & 0x1fffffUL) == 0 && !slides.Contains(candidate)) slides.Add(candidate);
                }
            return slides.ToArray();
        }
        private static void KernelPointer(ulong address)
        {
            if (address < 0xffff800000000000UL || !Canonical(address) || (address & 7) != 0)
                throw new InvalidOperationException("Invalid kernel pointer in live metadata.");
        }
        private void InRam(ulong address, int count)
        {
            if (count < 1 || count > 4096 || address > ulong.MaxValue - (ulong)(count - 1)) throw new ArgumentOutOfRangeException("count");
            foreach (RamRange range in ram)
                if (address >= range.First && address + (ulong)(count - 1) <= range.Last) return;
            throw new InvalidOperationException("Physical read is outside the debugger-reported RAM ranges.");
        }
        public byte[] Physical(ulong address, int count)
        {
            InRam(address, count);
            if (PhysicalCalls >= 30000 || timer.Elapsed.TotalSeconds > 120) throw new InvalidOperationException("Read budget exhausted; partial results only.");
            if(PhysicalCalls>=physicalScopeLimit)throw new PhysicalScopeLimitException();
            PhysicalCalls++;
            string text = transport(address, count);
            Match match = Reply.Match(text ?? "");
            if (!match.Success || int.Parse(match.Groups[1].Value, CultureInfo.InvariantCulture) != count || match.Groups[2].Value.Length != count * 2)
                throw new InvalidOperationException("Native read failed or returned an invalid byte count/protocol.");
            return Hex(match.Groups[2].Value);
        }
        private ulong Physical64(ulong address) { return BitConverter.ToUInt64(Physical(address, 8), 0); }
        public ulong Translate(ulong cr3, ulong address)
        {
            if (!Canonical(address)) throw new ArgumentOutOfRangeException("address", "Noncanonical 48-bit virtual address.");
            ulong table = cr3 & AddressMask; // Remove PCID/control bits; retain the architectural address bits.
            if (table == 0) throw new InvalidOperationException("Null page-table root.");
            int[] shifts = new int[] { 39, 30, 21, 12 };
            for (int level = 0; level < shifts.Length; level++)
            {
                ulong entry = Physical64(checked(table + ((address >> shifts[level]) & 511UL) * 8UL));
                if ((entry & 1) == 0) throw new InvalidOperationException("Virtual page is not present.");
                if (level == 0 && (entry & 128) != 0) throw new InvalidOperationException("Reserved page-size bit in PML4 entry.");
                if (level == 1 && (entry & 128) != 0)
                {
                    if ((entry & 0x3fffe000UL) != 0) throw new InvalidOperationException("Reserved bits in 1 GiB page.");
                    return (entry & 0x000fffffc0000000UL) | (address & 0x3fffffffUL);
                }
                if (level == 2 && (entry & 128) != 0)
                {
                    if ((entry & 0x1fe000UL) != 0) throw new InvalidOperationException("Reserved bits in 2 MiB page.");
                    return (entry & 0x000fffffffe00000UL) | (address & 0x1fffffUL);
                }
                table = entry & AddressMask;
            }
            return table | (address & 4095UL);
        }
        public byte[] Virtual(ulong root, ulong address, int count)
        {
            if (count < 1 || count > 4096 || address > ulong.MaxValue - (ulong)(count - 1)) throw new ArgumentOutOfRangeException("count");
            byte[] result = new byte[count];
            for (int used = 0; used < count; )
            {
                ulong current = checked(address + (ulong)used);
                int length = Math.Min(count - used, 4096 - (int)(current & 4095UL));
                MappingKey key = new MappingKey { Root = root & AddressMask, Page = current & ~4095UL };
                ulong page;
                bool cached = translations.TryGetValue(key, out page);
                ulong physical;
                if (cached) { physical = page | (current & 4095UL); TranslationCacheHits++; }
                else { physical = Translate(root, current); page = physical & ~4095UL; }
                byte[] data;
                try
                {
                    data = Physical(physical, length);
                    // Always walk live page tables after reading, even on cache hits.
                    if (Translate(root, current) != physical) throw new InvalidOperationException("Virtual mapping changed while reading.");
                }
                catch { translations.Remove(key); throw; }
                if (!cached)
                {
                    if (translations.Count >= 1024) translations.Clear();
                    translations[key] = page;
                }
                Buffer.BlockCopy(data, 0, result, used, length); used += length;
            }
            return result;
        }
        private ulong U64(ulong root, ulong address) { return BitConverter.ToUInt64(Virtual(root, address, 8), 0); }
        private static string CString(byte[] bytes, int start, int maximum)
        {
            int length = 0;
            while (length < maximum && bytes[start + length] != 0) length++;
            if (length == maximum) throw new InvalidOperationException("Unterminated kernel name.");
            return Encoding.ASCII.GetString(bytes, start, length);
        }
        private void Expect(ulong root, ulong address, string expected)
        {
            byte[] data = Hex(expected); byte[] actual = Virtual(root, address, data.Length);
            for (int i = 0; i < data.Length; i++) if (actual[i] != data[i]) throw new InvalidOperationException("Live kernel does not match the extracted image.");
        }
        public KernelContext VerifyKernel(ulong seedRoot, ulong slide)
        {
            if (slide > 0x40000000UL || (slide & 0x1fffffUL) != 0) throw new ArgumentException("Unsupported kernel relocation candidate.");
            Expect(seedRoot, checked(BannerVa + slide), BannerHex);
            Expect(seedRoot, 0xffffffff810e89e0UL + slide, MmAnchor);
            Expect(seedRoot, 0xffffffff8126a370UL + slide, CommAnchor);
            Expect(seedRoot, 0xffffffff8111e2d8UL + slide, TasksAnchor);
            Expect(seedRoot, 0xffffffff81119da7UL + slide, PidAnchor);
            Expect(seedRoot, 0xffffffff810e8e7bUL + slide, PgdAnchor);
            Expect(seedRoot, 0xffffffff8121b120UL + slide, VmaAnchor);
            Expect(seedRoot, 0xffffffff8127d69eUL + slide, DentryAnchor);
            byte[] task = Virtual(seedRoot, InitTaskVa + slide + 0x470UL, 0x2c0);
            int initialPid = BitConverter.ToInt32(task, 0x100);
            string initialName = CString(task, 0x2b0, 16);
            ulong initialMm = BitConverter.ToUInt64(task, 0x50);
            ulong initialActiveMm = BitConverter.ToUInt64(task, 0x58);
            if (initialPid != 0) throw new InvalidOperationException("Initial task PID mismatch: observed " + initialPid + ".");
            if (initialName != "swapper/0") throw new InvalidOperationException("Initial task name mismatch: observed " + initialName + ".");
            if (initialMm != 0) throw new InvalidOperationException("Initial idle task has a non-null mm: 0x" + initialMm.ToString("x") + ".");
            // context_switch assigns a borrowed mm to kernel threads and clears
            // it when they switch away. This field is not a fixed init_mm pointer.
            if (initialActiveMm != 0) KernelPointer(initialActiveMm);
            ulong pgd = U64(seedRoot, InitMmVa + slide + 0x50UL);
            if (pgd != InitPgdVa + slide) throw new InvalidOperationException("Initial mm page table does not match the inspected kernel.");
            ulong root = Translate(seedRoot, pgd);
            if ((root & 4095UL) != 0) throw new InvalidOperationException("Initial page-table alignment is invalid.");
            Expect(root, BannerVa + slide, BannerHex);
            return new KernelContext(root, slide, initialActiveMm);
        }
        public GameProcess FindProcess(KernelContext kernel, int pid, string expectedName)
        {
            if (kernel == null || pid < 1 || string.IsNullOrEmpty(expectedName)) throw new ArgumentException("Game identity is required.");
            ulong head = InitTaskVa + kernel.Slide + 0x470UL;
            ulong previous = head, node = U64(kernel.Root, head);
            HashSet<ulong> visited = new HashSet<ulong>();
            while (node != head)
            {
                KernelPointer(node);
                if (visited.Count >= 2048 || !visited.Add(node)) throw new InvalidOperationException("Task-list bound or cycle validation failed.");
                ulong task = checked(node - 0x470UL);
                byte[] data = Virtual(kernel.Root, node, 0x2c0);
                if (BitConverter.ToUInt64(data, 8) != previous) throw new InvalidOperationException("Task list changed during traversal.");
                if (BitConverter.ToInt32(data, 0x100) == pid)
                {
                    string name = CString(data, 0x2b0, 16);
                    if (name != expectedName) throw new InvalidOperationException("PID belongs to a different command name.");
                    ulong mm = BitConverter.ToUInt64(data, 0x50); KernelPointer(mm);
                    ulong pgd = U64(kernel.Root, mm + 0x50UL); KernelPointer(pgd);
                    if ((pgd & 4095UL) != 0) throw new InvalidOperationException("Game PGD is not page-aligned.");
                    ulong root = Translate(kernel.Root, pgd);
                    if ((root & 4095UL) != 0) throw new InvalidOperationException("Game physical PGD is not page-aligned.");
                    return new GameProcess { Pid = pid, Name = name, Task = task, Mm = mm, PgdVirtual = pgd, Root = root, TasksVisited = visited.Count };
                }
                previous = node; node = BitConverter.ToUInt64(data, 0);
            }
            throw new InvalidOperationException("ADB game PID was not found in the initial process namespace.");
        }
        public void Recheck(KernelContext kernel, GameProcess game)
        {
            byte[] data = Virtual(kernel.Root, game.Task + 0x470UL, 0x2c0);
            if (BitConverter.ToInt32(data, 0x100) != game.Pid || CString(data, 0x2b0, 16) != game.Name ||
                BitConverter.ToUInt64(data, 0x50) != game.Mm || U64(kernel.Root, game.Mm + 0x50UL) != game.PgdVirtual ||
                Translate(kernel.Root, game.PgdVirtual) != game.Root)
                throw new InvalidOperationException("Game identity or page table changed during collection.");
        }
        private string FileName(ulong root, ulong file)
        {
            KernelPointer(file);
            ulong dentry = U64(root, file + 0x18UL); KernelPointer(dentry);
            byte[] nameInfo = Virtual(root, dentry + 0x24UL, 12);
            int length = BitConverter.ToInt32(nameInfo, 0);
            ulong nameAddress = BitConverter.ToUInt64(nameInfo, 4);
            if (length < 1 || length > 255) throw new InvalidOperationException("Invalid VMA file-name length.");
            KernelPointer(nameAddress & ~7UL);
            string name = CString(Virtual(root, nameAddress, length + 1), 0, length + 1);
            if (Encoding.ASCII.GetByteCount(name) != length) throw new InvalidOperationException("VMA file name is inconsistent with its length.");
            return name;
        }
        public LibraryResult Libraries(KernelContext kernel, GameProcess game)
        { return Libraries(kernel, game, null); }
        public LibraryResult Libraries(KernelContext kernel, GameProcess game, Action<string> progress)
        { return ScanLibraries(kernel, game, progress, false); }
        public LibraryResult ProbeLibrary(KernelContext kernel, GameProcess game, Action<string> progress)
        { return ScanLibraries(kernel, game, progress, true); }
        private void RecheckVma(KernelContext kernel, GameProcess game, ulong node, byte[] expected)
        {
            byte[] current = Virtual(kernel.Root, node, 0xa8);
            foreach (int offset in new int[] { 0, 8, 0x10, 0x18, 0x98, 0xa0 })
                if (BitConverter.ToUInt64(current, offset) != BitConverter.ToUInt64(expected, offset))
                    throw new InvalidOperationException("Target VMA changed during verification.");
            ulong previous = BitConverter.ToUInt64(current, 0x18), next = BitConverter.ToUInt64(current, 0x10);
            if (previous == 0)
            {
                if (U64(kernel.Root, game.Mm) != node)
                    throw new InvalidOperationException("Target VMA is no longer the process list head.");
            }
            else
            {
                KernelPointer(previous);
                if (U64(kernel.Root, previous + 0x10UL) != node)
                    throw new InvalidOperationException("Target VMA predecessor no longer links to it.");
            }
            if (next != 0)
            {
                KernelPointer(next);
                if (U64(kernel.Root, next + 0x18UL) != node)
                    throw new InvalidOperationException("Target VMA successor no longer links to it.");
            }
        }
        private void VerifyTarget(KernelContext kernel, GameProcess game, ulong node, byte[] area, LibraryMapping mapping, byte[] header)
        {
            Recheck(kernel, game);
            RecheckVma(kernel, game, node, area);
            if (FileName(kernel.Root, BitConverter.ToUInt64(area, 0xa0)) != mapping.Name)
                throw new InvalidOperationException("Target library filename changed during verification.");
            byte[] current = Virtual(game.Root, mapping.Start, header.Length);
            for (int i = 0; i < header.Length; i++)
                if (current[i] != header[i]) throw new InvalidOperationException("Target library ELF header changed during verification.");
            RecheckVma(kernel, game, node, area);
            Recheck(kernel, game);
            mapping.Revalidated = true;
        }
        private sealed class VmaTraversalException : InvalidOperationException
        {
            internal readonly string Reason;
            internal bool Retryable { get { return Reason == "REPEATED_NODE" || Reason == "VMA_ORDER" || Reason == "VMA_BACKLINK"; } }
            internal VmaTraversalException(string reason, ulong node, ulong previous, int count, string detail = "")
                : base("VMA traversal failed Reason=" + reason + " Node=0x" + node.ToString("x") +
                    " Previous=0x" + previous.ToString("x") + " VmasVisited=" + count + " Limit=4096 " + detail)
            { Reason = reason; }
        }
        private LibraryResult ScanLibraries(KernelContext kernel, GameProcess game, Action<string> progress, bool stopAfterTarget,
            Func<ulong, byte[], LibraryMapping, byte[], bool> verifyModule = null)
        {
            Recheck(kernel, game);
            LibraryResult result = new LibraryResult();
            LastLibraries = result;
            ulong node = U64(kernel.Root, game.Mm), previous = 0, previousEnd = 0;
            HashSet<ulong> seen = new HashSet<ulong>();
            Dictionary<ulong, string> fileNames = new Dictionary<ulong, string>();
            Dictionary<ulong, string> matchedFiles = new Dictionary<ulong, string>();
            while (node != 0)
            {
                KernelPointer(node);
                if (seen.Count >= 4096)
                {
                    result.StopReason = "NODE_LIMIT";
                    throw new VmaTraversalException("NODE_LIMIT", node, previous, result.VmasVisited);
                }
                if (!seen.Add(node))
                {
                    result.StopReason = "REPEATED_NODE";
                    throw new VmaTraversalException("REPEATED_NODE", node, previous, result.VmasVisited);
                }
                byte[] area = Virtual(kernel.Root, node, 0xa8);
                ulong start = BitConverter.ToUInt64(area, 0), end = BitConverter.ToUInt64(area, 8);
                ulong actualPrevious = BitConverter.ToUInt64(area, 0x18);
                string invalid = start >= end ? "INVALID_RANGE" : end > 0x0000800000000000UL ? "USER_RANGE" :
                    ((start | end) & 4095UL) != 0 ? "PAGE_ALIGNMENT" : start < previousEnd ? "VMA_ORDER" :
                    actualPrevious != previous ? "VMA_BACKLINK" : null;
                if (invalid != null)
                {
                    result.StopReason = invalid;
                    string detail = "Start=0x" + start.ToString("x") + " End=0x" + end.ToString("x") +
                        " PreviousEnd=0x" + previousEnd.ToString("x") + " LinkPrevious=0x" + actualPrevious.ToString("x") +
                        " Next=0x" + BitConverter.ToUInt64(area, 0x10).ToString("x");
                    if (progress != null) progress("LibraryScanInconsistency Reason=" + invalid + " Node=0x" + node.ToString("x") + " " + detail);
                    throw new VmaTraversalException(invalid, node, previous, result.VmasVisited, detail);
                }
                result.VmasVisited = seen.Count;
                if (progress != null && (result.VmasVisited == 1 || result.VmasVisited % 128 == 0))
                    progress("LibraryScanProgress VmasVisited=" + result.VmasVisited + " PhysicalReadCalls=" + PhysicalCalls + " FilesInspected=" + result.FilesInspected + " RepeatedFilesSkipped=" + result.RepeatedFilesSkipped);
                ulong file = BitConverter.ToUInt64(area, 0xa0);
                if (file != 0)
                {
                    KernelPointer(file);
                    string name;
                    if (fileNames.TryGetValue(file, out name)) result.RepeatedFilesSkipped++;
                    else
                    {
                        name = FileName(kernel.Root, file);
                        result.FilesInspected++;
                        if (fileNames.Count >= 1024) fileNames.Clear();
                        fileNames[file] = name;
                    }
                    if (name == "libil2cpp.so" || name == "libunity.so" || name == "global-metadata.dat")
                    {
                        matchedFiles[file] = name;
                        ulong offset = BitConverter.ToUInt64(area, 0x98);
                        bool arm64 = false;
                        byte[] header = null;
                        if (offset == 0 && end - start >= 20)
                        {
                            header = Virtual(game.Root, start, 20);
                            arm64 = header[0] == 0x7f && header[1] == 69 && header[2] == 76 && header[3] == 70 &&
                                    header[4] == 2 && header[5] == 1 && BitConverter.ToUInt16(header, 18) == 183;
                        }
                        LibraryMapping mapping = new LibraryMapping { Name = name, Start = start, End = end, FilePageOffset = offset, Arm64ElfHeader = arm64 };
                        result.Mappings.Add(mapping);
                        if (progress != null && (arm64 || result.Mappings.Count == 1)) progress("LibraryCandidate Name=" + name + " Start=0x" + start.ToString("x") + " End=0x" + end.ToString("x") + " Arm64ElfHeader=" + arm64 + " Status=PENDING_RECHECK");
                        if (verifyModule != null && name == "libil2cpp.so" && arm64)
                        {
                            if (verifyModule(node, area, mapping, header))
                            {
                                result.StopReason = "MODULE_VERIFIED";
                                return result;
                            }
                        }
                        else if (stopAfterTarget && name == "libil2cpp.so" && arm64)
                        {
                            VerifyTarget(kernel, game, node, area, mapping, header);
                            result.StopReason = "TARGET_VERIFIED";
                            return result;
                        }
                    }
                }
                previous = node; previousEnd = end; node = BitConverter.ToUInt64(area, 0x10);
            }
            foreach (KeyValuePair<ulong, string> file in matchedFiles)
                if (FileName(kernel.Root, file.Key) != file.Value)
                    throw new InvalidOperationException("Matched library file identity changed during the scan.");
            Recheck(kernel, game);
            result.StopReason = "END_OF_LIST";
            result.CompleteVmaList = true;
            return result;
        }
    }
}
