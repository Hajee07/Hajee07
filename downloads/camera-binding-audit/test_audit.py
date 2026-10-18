import importlib.util
import sys
import unittest
from pathlib import Path
from audit_bindings import audit, TARGETS

class AuditTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        spec=importlib.util.spec_from_file_location('mapper',sys.argv[2])
        m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
        cls.elf=m.Elf(Path(sys.argv[1]).read_bytes())
    def test_pinned_patterns(self):
        self.assertEqual(len(audit(self.elf)['bindings']),5)
    def test_changed_tail_rejected(self):
        original=self.elf
        class Changed:
            def bytes(self,at,size):
                raw=original.bytes(at,size)
                if at==TARGETS['get_fieldOfView']:
                    raw=raw[:56]+bytes.fromhex('c0035fd6')+raw[60:]
                return raw
        with self.assertRaises(ValueError):audit(Changed())
    def test_changed_resolver_rejected(self):
        original=self.elf
        class Changed:
            def bytes(self,at,size):
                raw=original.bytes(at,size)
                if at==TARGETS['get_fieldOfView']:
                    raw=raw[:32]+bytes.fromhex('1f2003d5')+raw[36:]
                return raw
        with self.assertRaises(ValueError):audit(Changed())

if __name__=='__main__':
    unittest.main(argv=[sys.argv[0]],verbosity=2)
