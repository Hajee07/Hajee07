import importlib.util
import sys
import unittest
from pathlib import Path
from audit_native_sources import audit, BINDINGS, UNITY_SHA

class NativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        spec=importlib.util.spec_from_file_location('mapper',sys.argv[2])
        m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);m.ELF_SHA=UNITY_SHA
        cls.elf=m.Elf(Path(sys.argv[1]).read_bytes())
    def test_pinned_registrations(self):
        report=audit(self.elf)
        self.assertEqual(len(report['bindings']),5)
        self.assertFalse(report['native_data_layout_runtime_verified'])
    def test_reject_registration_mutations(self):
        original=self.elf
        for label,at in [('name',BINDINGS[0][2]),('target',BINDINGS[0][1]),
                         ('branch',BINDINGS[0][1]+16),('helper',BINDINGS[0][3]+0x8c)]:
            class Changed:
                loads=original.loads
                def bytes(self,start,size):
                    raw=bytearray(original.bytes(start,size))
                    if start<=at<start+size:
                        raw[at-start:at-start+4]=bytes(4)
                    return bytes(raw)
            with self.subTest(label=label),self.assertRaises(ValueError):audit(Changed())

if __name__=='__main__':unittest.main(argv=[sys.argv[0]],verbosity=2)
