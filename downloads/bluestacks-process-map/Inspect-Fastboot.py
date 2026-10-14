#!/usr/bin/env python3
"""Extract the bounded, parentless VDI 1.1 flat-boot format observed in this upload."""
import argparse
import hashlib
import json
import struct
import zipfile
import zlib
from pathlib import Path


def require(condition, message):
    if not condition:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def gunzip(data, maximum):
    decoder = zlib.decompressobj(16 + zlib.MAX_WBITS)
    output = decoder.decompress(data, maximum + 1)
    require(len(output) <= maximum and decoder.eof and not decoder.unconsumed_tail,
            "Invalid, incomplete, or oversized gzip stream")
    return output, len(data) - len(decoder.unused_data)


def extract(archive_path, output_path):
    output_path.mkdir(parents=True, exist_ok=True)
    archive_bytes = archive_path.read_bytes()
    require(len(archive_bytes) <= 32 * 1024 * 1024, "Archive exceeds this inspector's bound")
    with zipfile.ZipFile(archive_path) as archive:
        entries = archive.infolist()
        require(len(entries) == 1 and entries[0].filename == "fastboot.vdi", "Expected one fastboot.vdi entry")
        require(entries[0].file_size <= 32 * 1024 * 1024, "Image is oversized")
        require(archive.testzip() is None, "ZIP CRC failure")
        image = archive.read(entries[0])
    require(len(image) >= 472, "Truncated VDI header")
    u32 = lambda offset: struct.unpack_from("<I", image, offset)[0]
    require(u32(64) == 0xBEDA107F and u32(68) == 0x10001, "Not the inspected VDI version")
    require(u32(72) >= 400 and u32(76) == 1 and image[424:456] == bytes(32), "Unsupported image type or parent")
    map_offset, data_offset = u32(340), u32(344)
    size = struct.unpack_from("<Q", image, 368)[0]
    block_size, extra, count, allocated = u32(376), u32(380), u32(384), u32(388)
    require(0 < size <= 32 * 1024 * 1024 and 512 <= block_size <= 8 * 1024 * 1024,
            "Unsupported logical size or block size")
    require(block_size & (block_size - 1) == 0 and extra == 0, "Unsupported block layout")
    require(count == (size + block_size - 1) // block_size, "Invalid block count")
    require(map_offset >= 72 + u32(72) and data_offset >= map_offset + count * 4 and data_offset <= len(image),
            "Invalid block-map/data offsets")
    block_map = struct.unpack_from(f"<{count}I", image, map_offset)
    raw, seen = bytearray(size), set()
    for logical, physical in enumerate(block_map):
        if physical in (0xFFFFFFFF, 0xFFFFFFFE):
            continue
        require(physical < allocated and physical not in seen, "Invalid or duplicate physical block")
        seen.add(physical)
        source = data_offset + physical * block_size
        length = min(block_size, size - logical * block_size)
        require(source + length <= len(image), "Physical block is truncated")
        raw[logical * block_size:logical * block_size + length] = image[source:source + length]
    base = 512
    require(raw[510:512] == b"\x55\xaa" and raw[base + 0x202:base + 0x206] == b"HdrS",
            "Not the observed flat-boot kernel layout")
    setup_sectors = raw[base + 0x1F1] or 4
    kernel_length = (setup_sectors + 1) * 512 + struct.unpack_from("<I", raw, base + 0x1F4)[0] * 16
    require(base + kernel_length <= len(raw), "Kernel exceeds the boot image")
    payload_offset, payload_length = struct.unpack_from("<II", raw, base + 0x248)
    payload_start = base + (setup_sectors + 1) * 512 + payload_offset
    require(payload_start + payload_length <= base + kernel_length, "Kernel payload bounds are invalid")
    kernel, consumed = gunzip(raw[payload_start:payload_start + payload_length], 128 * 1024 * 1024)
    require(consumed == payload_length and kernel[:6] == b"\x7fELF\x02\x01" and
            struct.unpack_from("<H", kernel, 18)[0] == 62, "Kernel is not a complete x86-64 ELF payload")
    version_start = base + 0x200 + struct.unpack_from("<H", raw, base + 0x20E)[0]
    version_end = raw.find(0, version_start, min(version_start + 512, base + kernel_length))
    require(version_end > version_start, "Invalid version-string pointer")
    version = raw[version_start:version_end].decode("ascii")
    initrd_start = (base + kernel_length + 511) & ~511
    initrd_length = struct.unpack_from("<I", raw, 0x1FA)[0]
    require(initrd_start + initrd_length <= len(raw), "Initrd bounds are invalid")
    initrd, consumed = gunzip(raw[initrd_start:initrd_start + initrd_length], 32 * 1024 * 1024)
    require(consumed == initrd_length and initrd.startswith(b"070701"), "Initrd is not the observed cpio format")
    artifacts = {"fastboot.vdi": image, "fastboot.raw": raw,
                 "bzImage": raw[base:base + kernel_length], "vmlinux": kernel, "initrd.cpio": initrd}
    facts = {"archive_sha256": digest(archive_bytes), "version": version,
             "vdi_block_map": list(block_map), "kernel_start": base,
             "kernel_payload_start": payload_start, "initrd_start": initrd_start,
             "artifacts": {name: {"size": len(data), "sha256": digest(data)} for name, data in artifacts.items()}}
    for name, data in artifacts.items():
        (output_path / name).write_bytes(data)
    (output_path / "extraction.json").write_text(json.dumps(facts, indent=2) + "\n")
    print(json.dumps(facts, indent=2))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("archive", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    extract(args.archive, args.output)
