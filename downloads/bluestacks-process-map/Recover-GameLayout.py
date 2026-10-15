#!/usr/bin/env python3
"""Recover selected metadata/registration evidence for the exact supplied APK.

This produces verification references, not a player-object reader or aim writer.
The custom magic/version words are retained; no standard metadata version is
invented. All offsets in the report are explicitly relative or field offsets.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

ELF_SHA = '549093d79212873f26bc13f8957d06cc7575e92f24b53721eb13e8a0a53cb657'
META_SHA = 'e6550955f005877d6daf94f4984892501ad86fe36d52cd1a1c94ceed0dd15aa3'


def require(condition, message):
    if not condition:
        raise ValueError(message)


def decode_metadata(raw):
    require(hashlib.sha256(raw).hexdigest() == META_SHA, 'Unexpected metadata SHA-256')
    decoded = bytearray(raw)
    xor = bytes(value ^ 0x66 for value in range(256))
    for base in range(0, len(decoded), 0x10000):
        start = base + (0 if base == 0 else 0x1000)
        end = min(base + 0x5000, len(decoded))
        if start < end:
            decoded[start:end] = decoded[start:end].translate(xor)
    return bytes(decoded)


class Metadata:
    def __init__(self, data):
        self.data = data
        self.header = struct.unpack_from('<64I', data)
        previous = 0x100
        for index in range(2, 64, 2):
            offset, size = self.header[index:index + 2]
            require(offset == previous and offset + size <= len(data), 'Metadata section continuity/bounds mismatch')
            previous = offset + size
        require(previous == len(data), 'Unaccounted metadata bytes')
        self.types = self.records(40, '<16i8H2I')
        self.methods = self.records(12, '<8i4H')
        self.fields = self.records(24, '<iiI')
        self.parameters = self.records(22, '<iIi')
        self.images = self.records(42, '<10i')
        self.validate()

    def records(self, index, fmt):
        start, length = self.header[index:index + 2]
        size = struct.calcsize(fmt)
        require(length % size == 0, 'Metadata record stride mismatch')
        return list(struct.iter_unpack(fmt, self.data[start:start + length]))

    def string(self, index):
        start, size = self.header[6:8]
        require(0 <= index < size, 'String index outside string table')
        end = self.data.find(b'\0', start + index, start + size)
        require(end >= 0, 'Unterminated metadata string')
        value = self.data[start + index:end].decode('utf-8')
        require(all(ord(c) >= 32 for c in value), 'Control bytes in metadata identifier')
        return value

    def type_name(self, index):
        require(0 <= index < len(self.types), 'Type-definition index out of bounds')
        item = self.types[index]
        return '.'.join(x for x in (self.string(item[1]), self.string(item[0])) if x)

    def validate(self):
        require((len(self.types), len(self.methods), len(self.fields), len(self.images)) == (43624, 336350, 475669, 56), 'Unexpected metadata counts')
        owned_methods, owned_fields, owned_types = set(), set(), set()
        for type_index, item in enumerate(self.types):
            self.type_name(type_index)
            require(item[-1] >> 24 == 2, 'Invalid type token')
            for first, count, records, owned, kind in ((item[9], item[16], self.methods, owned_methods, 6), (item[8], item[18], self.fields, owned_fields, 4)):
                require(count == 0 or 0 <= first <= len(records) - count, 'Invalid type member range')
                for index in range(first, first + count):
                    require(index not in owned, 'Overlapping type member ranges')
                    owned.add(index)
                    member = records[index]
                    self.string(member[0])
                    if kind == 6:
                        require(member[1] == type_index and member[7] >> 24 == 6, 'Method owner/token mismatch')
                        parameter_start, parameter_count = member[4], member[11]
                        require(parameter_count == 0 or 0 <= parameter_start <= len(self.parameters) - parameter_count, 'Invalid parameter range')
                    else:
                        require(member[2] >> 24 == 4, 'Field token mismatch')
        require(len(owned_methods) == len(self.methods) and len(owned_fields) == len(self.fields), 'Unowned metadata members')
        for item in self.parameters:
            self.string(item[0])
            require(item[1] >> 24 == 8, 'Parameter token mismatch')
        for image in self.images:
            self.string(image[0])
            require(0 <= image[1] < len(self.images) and 0 <= image[2] <= len(self.types) - image[3], 'Invalid image range')
            type_tokens, method_tokens, field_tokens = [], [], []
            for index in range(image[2], image[2] + image[3]):
                require(index not in owned_types, 'Overlapping images')
                owned_types.add(index)
                item = self.types[index]
                type_tokens.append(item[-1] & 0xffffff)
                for method in self.methods[item[9]:item[9] + item[16]] if item[16] else []:
                    method_tokens.append(method[7] & 0xffffff)
                for field in self.fields[item[8]:item[8] + item[18]] if item[18] else []:
                    field_tokens.append(field[2] & 0xffffff)
            # Nested type definitions can be reordered relative to their token
            # RIDs. Validate the complete per-image token sets, not row order.
            for tokens in (type_tokens, method_tokens, field_tokens):
                require(set(tokens) == set(range(1, len(tokens) + 1)), 'Image token coverage/uniqueness mismatch')
        require(len(owned_types) == len(self.types), 'Unowned type definitions')


class Elf:
    def __init__(self, data):
        require(hashlib.sha256(data).hexdigest() == ELF_SHA, 'Unexpected ELF SHA-256')
        self.data = data
        phoff = struct.unpack_from('<Q', data, 32)[0]
        stride, count = struct.unpack_from('<HH', data, 54)
        self.loads = [p for p in (struct.unpack_from('<II6Q', data, phoff + stride * i) for i in range(count)) if p[0] == 1]
        shoff = struct.unpack_from('<Q', data, 40)[0]
        stride, count = struct.unpack_from('<HH', data, 58)
        self.relocations = {}
        for index in range(count):
            section = struct.unpack_from('<II4QII2Q', data, shoff + stride * index)
            if section[1] != 4:
                continue
            require(section[9] == 24, 'Unexpected RELA stride')
            for slot, info, addend in struct.iter_unpack('<QQq', data[section[4]:section[4] + section[5]]):
                if info == 1027:
                    require(slot not in self.relocations, 'Duplicate relative relocation')
                    self.relocations[slot] = addend

    def file_offset(self, rva, size=1):
        hits = [p[2] + rva - p[3] for p in self.loads if p[3] <= rva and rva + size <= p[3] + p[5]]
        require(len(hits) == 1, 'RVA not uniquely file backed')
        return hits[0]

    def rva(self, offset):
        hits = [p[3] + offset - p[2] for p in self.loads if p[2] <= offset < p[2] + p[5]]
        require(len(hits) == 1, 'File offset has ambiguous runtime locations')
        return hits[0]

    def bytes(self, rva, size):
        offset = self.file_offset(rva, size)
        return self.data[offset:offset + size]

    def pointer(self, rva):
        return self.relocations.get(rva, struct.unpack('<Q', self.bytes(rva, 8))[0])


def recover(elf, meta):
    checks, classes, fields, methods = [], [], [], []

    def raw(label, rva, size):
        checks.append(dict(name=label, rva=rva, hex=elf.bytes(rva, size).hex()))

    def pointer(label, rva):
        require(rva in elf.relocations, 'Expected relocated pointer: ' + label)
        target = elf.pointer(rva)
        elf.file_offset(target)
        checks.append(dict(name=label, rva=rva, target_rva=target))
        return target

    needle = b'Assembly-CSharp.dll\0'
    pos = elf.data.find(needle)
    require(pos >= 0 and elf.data.find(needle, pos + 1) < 0, 'Code module name is not unique')
    name_rva = elf.rva(pos)
    module_refs = [slot for slot, target in elf.relocations.items() if target == name_rva]
    require(len(module_refs) == 1, 'Ambiguous Assembly-CSharp module record')
    module = module_refs[0]
    pointer('code_module_name', module)
    raw('code_module_name_bytes', name_rva, len(needle))
    method_count = struct.unpack('<Q', elf.bytes(module + 8, 8))[0]
    raw('code_module_method_count', module + 8, 8)
    method_table = pointer('code_module_method_table', module + 16)
    assembly = next(image for image in meta.images if meta.string(image[0]) == 'Assembly-CSharp.dll')
    expected_count = sum(item[16] for item in meta.types[assembly[2]:assembly[2] + assembly[3]])
    require(method_count == expected_count == 289444, 'Code module method count differs from metadata')

    # Identify the adjacent field-offset and type-size counts independently.
    candidates, cursor = [], 0
    packed_count = struct.pack('<Q', len(meta.types))
    while True:
        cursor = elf.data.find(packed_count, cursor)
        if cursor < 0:
            break
        if cursor % 8 == 0 and elf.data[cursor + 16:cursor + 24] == packed_count:
            try:
                address = elf.rva(cursor)
                if address + 8 in elf.relocations and address + 24 in elf.relocations:
                    candidates.append(address)
            except ValueError:
                pass
        cursor += 1
    require(len(candidates) == 1, 'Metadata registration count pair is ambiguous')
    registration = candidates[0] - 0x50
    for index in range(7):
        raw('registration_count_' + str(index), registration + index * 16, 8)
        pointer('registration_table_' + str(index), registration + index * 16 + 8)
    type_count = struct.unpack('<Q', elf.bytes(registration + 0x30, 8))[0]
    type_table = elf.pointer(registration + 0x38)
    field_table = elf.pointer(registration + 0x58)
    size_table = elf.pointer(registration + 0x68)
    require(all(0 <= item[2] < type_count for item in meta.types), 'By-value type index out of native range')
    require(all(0 <= item[1] < type_count for item in meta.fields), 'Field type index out of native range')
    require(all(0 <= item[2] < type_count for item in meta.methods + meta.parameters), 'Return/parameter type index out of native range')

    def type_info(index):
        address = elf.pointer(type_table + index * 8)
        data, bits = struct.unpack('<QI', elf.bytes(address, 12))
        kind = bits >> 16 & 255
        if kind in (0x11, 0x12):
            name = meta.type_name(data)
        else:
            name = {1: 'void', 2: 'bool', 8: 'int32', 9: 'uint32', 10: 'int64', 11: 'uint64', 12: 'float', 13: 'double', 14: 'string'}.get(kind, 'Il2CppTypeKind_0x%x' % kind)
        return name, bits & 65535, address

    selection = {
        'COW.GameFacade': {'CurrentGame', 'CurrentMatchGame'},
        'COW.GamePlay.Player': {'<AKKPEKIHGAH>k__BackingField', 'BANPEGJEAKE', 'LHICEKMGJOB', 'NBIIBJBALJD', 'm_CurrentAimRotation'},
        'COW.MatchGame': {0x90},
        'COW.GamePlay.JMAGGLCNGIG': {0xd8},
    }
    type_indices = {}
    for index in range(len(meta.types)):
        name = meta.type_name(index)
        if name in selection:
            require(name not in type_indices, 'Duplicate selected class name')
            require(assembly[2] <= index < assembly[2] + assembly[3], 'Selected class is outside Assembly-CSharp')
            type_indices[name] = index
    require(len(type_indices) == len(selection), 'Selected class missing or ambiguous')
    for class_name, selected in selection.items():
        index = type_indices[class_name]
        item = meta.types[index]
        offsets = pointer(class_name + '.field_offsets', field_table + index * 8)
        sizes = pointer(class_name + '.type_sizes', size_table + index * 8)
        raw(class_name + '.size_values', sizes, 16)
        instance_size, native_size, static_size, thread_size = struct.unpack('<4I', elf.bytes(sizes, 16))
        classes.append(dict(name=class_name, type_index=index, field_count=item[18], method_count=item[16], instance_size=instance_size, static_size=static_size))
        found = 0
        for local in range(item[18]):
            definition = meta.fields[item[8] + local]
            name = meta.string(definition[0])
            value_address = offsets + local * 4
            value = struct.unpack('<I', elf.bytes(value_address, 4))[0]
            type_name, attrs, type_rva = type_info(definition[1])
            if name not in selected and not (value in selected and not attrs & 16):
                continue
            require(value < (static_size if attrs & 16 else instance_size), 'Selected field offset exceeds its storage size')
            found += 1
            raw(class_name + '.' + name + '.offset', value_address, 4)
            pointer(class_name + '.' + name + '.type', type_table + definition[1] * 8)
            raw(class_name + '.' + name + '.type_descriptor', type_rva, 12)
            definition_index = struct.unpack('<Q', elf.bytes(type_rva, 8))[0]
            require(0 <= definition_index < len(meta.types), 'Selected descriptor type index out of range')
            record_offset = meta.header[40] + definition_index * 88
            checks[-1].update(type_definition_index=definition_index,
                              type_definition_hex=meta.data[record_offset:record_offset + 88].hex())
            fields.append(dict(owner=class_name, name=name, type=type_name, attributes=attrs, storage='static' if attrs & 16 else 'instance', offset=value, metadata_index=item[8] + local, local_index=local, token=definition[2], offset_slot_rva=value_address))
        require(found == len(selected), 'Selected fields missing or ambiguous')

    wanted = {
        'COW.GameFacade': {'CurrentMatch': 0, 'CurrentLocalPlayer': 0},
        'COW.GamePlay.Player': {'get_HeadBoneTransform': 0, 'get_HeadCollider': 0, 'IsVisible': 0, 'SetAimRotation': 2, 'IsLocalPlayer': 0},
        'COW.MatchGame': {'GetMatch': 0},
        'COW.GamePlay.JMAGGLCNGIG': {'IKKLCLKFBHM': 0},
    }
    for class_name, names in wanted.items():
        item = meta.types[type_indices[class_name]]
        found = set()
        for index in range(item[9], item[9] + item[16]):
            definition = meta.methods[index]
            name = meta.string(definition[0])
            if name not in names or definition[11] != names[name]:
                continue
            require(name not in found, 'Ambiguous method overload')
            found.add(name)
            rid = definition[7] & 0xffffff
            require(1 <= rid <= method_count, 'Method token outside native module table')
            slot = method_table + (rid - 1) * 8
            rva = pointer(class_name + '.' + name + '.method_pointer', slot)
            require(any(p[1] & 1 and p[3] <= rva < p[3] + p[5] for p in elf.loads), 'Method is not in an executable PT_LOAD')
            raw(class_name + '.' + name + '.entry', rva, 32)
            parameters = []
            for parameter in meta.parameters[definition[4]:definition[4] + definition[11]] if definition[11] else []:
                parameters.append(dict(name=meta.string(parameter[0]), type=type_info(parameter[2])[0]))
            methods.append(dict(owner=class_name, name=name, metadata_index=index, token=definition[7], rva=rva, pointer_slot_rva=slot, return_type=type_info(definition[2])[0], parameters=parameters, hotfix_index_candidate=definition[6]))
        require(found == set(names), 'Selected method missing')

    # Independently inspected ARM64 instructions supporting the limited semantics.
    for name, address, size in [('head_provider_load', 0x6f37c50, 8), ('visibility_provider_load', 0x6f38874, 16), ('aim_setter_original_stores', 0x6f34fdc, 16), ('match_field_load', 0x731de80, 12), ('local_player_field_load', 0x720a79c, 12)]:
        raw(name, address, size)
    return dict(metadata_sha256=META_SHA, elf_sha256=ELF_SHA, metadata_header_hex=meta.data[:256].hex(),
                metadata_size=len(meta.data), type_definitions_offset=meta.header[40], type_definition_stride=88, metadata_magic_version_decoded=[hex(x) for x in meta.header[:2]],
                counts=dict(types=len(meta.types), methods=len(meta.methods), fields=len(meta.fields), parameters=len(meta.parameters), images=len(meta.images), native_types=type_count, assembly_csharp_methods=method_count),
                registration_rva=registration, code_module_rva=module, classes=classes, fields=fields, methods=methods, checks=checks,
                limitations=['Custom metadata version is not identified.', 'Fields and methods are static candidates until runtime registration checks pass.', 'Player objects, world-space head positions, line-of-sight semantics and aim execution remain unverified.', 'Hotfix dispatch is present; original-code paths are not guaranteed to be active.'])


def write_outputs(report, folder):
    folder = Path(folder)
    folder.mkdir(parents=True, exist_ok=True)
    (folder / 'game-layout.json').write_text(json.dumps(report, indent=2) + '\n')
    lines = ['// Generated by Recover-GameLayout.py from SHA-256-verified user inputs.', 'namespace HeadBridge.Mapping {', '    internal static class GameLayoutReference {',
             '        internal const int Fields = %d, Methods = %d;' % (len(report['fields']), len(report['methods'])),
             '        internal const string MetadataSha256 = "%s";' % META_SHA,
             '        internal const ulong MetadataSize = %dUL, TypeDefinitionsOffset = %dUL;' % (report['metadata_size'], report['type_definitions_offset']),
             '        internal const string MetadataHeaderHex = "%s";' % report['metadata_header_hex'],
             '        internal static readonly GameLayoutCheck[] Checks = new GameLayoutCheck[] {']
    for item in report['checks']:
        name = json.dumps(item['name'], ensure_ascii=True)
        value = '0x%xUL' % item['target_rva'] if 'target_rva' in item else '"' + item['hex'] + '"'
        if 'type_definition_index' in item:
            value += ', %d, "%s"' % (item['type_definition_index'], item['type_definition_hex'])
        lines.append('            new GameLayoutCheck(%s, 0x%xUL, %s),' % (name, item['rva'], value))
    lines += ['        };', '    }', '}', '']
    (folder / 'GameLayoutReference.cs').write_text('\n'.join(lines))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('elf')
    parser.add_argument('metadata')
    parser.add_argument('output_directory')
    args = parser.parse_args()
    metadata = Metadata(decode_metadata(Path(args.metadata).read_bytes()))
    elf = Elf(Path(args.elf).read_bytes())
    report = recover(elf, metadata)
    write_outputs(report, args.output_directory)
    print('MetadataValidation=PASS ' + json.dumps(report['counts'], sort_keys=True))
    print('NativeCandidates Fields=%d Methods=%d RuntimeChecks=%d' % (len(report['fields']), len(report['methods']), len(report['checks'])))
