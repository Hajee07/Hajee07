import importlib.util
import math
from pathlib import Path
import sys
import unittest
from verify_dirty_view import derive,SyntheticMachine,SHA

class ModelTests(unittest.TestCase):
    def test_identity_z_flip(self):
        self.assertEqual(derive([([0,0,0],[0,0,0,1],[1,1,1])]),[1,0,0,0,0,1,0,0,0,0,-1,0,0,0,0,1])
    def test_local_scale_is_not_full_inverse(self):
        a=derive([([1,2,3],[0,0,0,1],[1,1,1])])
        b=derive([([1,2,3],[0,0,0,1],[2,3,4])])
        self.assertEqual(a,b)
        self.assertNotEqual(b[0],.5)
    def test_invalid_context_inputs(self):
        for case in [[],[([0,0,0],[0,0,0,0],[1,1,1])],
                     [([math.nan,0,0],[0,0,0,1],[1,1,1])],
                     [([0,0,0],[0,0,0,1],[1,1,1])]*33]:
            with self.subTest(case=case),self.assertRaises(ValueError):derive(case)
    def test_live_pose_formula_matches_synthetic_helper(self):
        expected=derive([([1,2,3],[0,0,0,1],[2,3,4])])
        actual=self.machine.run([([1,2,3],[0,0,0,1],[2,3,4])])
        self.assertEqual(expected,actual)
    def test_corrupt_scale_builder_is_detectable(self):
        address=self.machine.base+0xc0eae8
        original=bytes(self.machine.uc.mem_read(address,4))
        try:
            self.machine.uc.mem_write(address,bytes.fromhex('c0035fd6'))
            self.machine.uc.ctl_remove_cache(address,address+4)
            actual=self.machine.run([([1,2,3],[0,0,0,1],[1,1,1])])
            expected=derive([([1,2,3],[0,0,0,1],[1,1,1])])
            self.assertTrue(any(abs(x-y)>.001 for x,y in zip(actual,expected)))
        finally:
            self.machine.uc.mem_write(address,original)
            self.machine.uc.ctl_remove_cache(address,address+4)
    @classmethod
    def setUpClass(cls):
        spec=importlib.util.spec_from_file_location('mapper',sys.argv[2])
        m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);m.ELF_SHA=SHA
        cls.machine=SyntheticMachine(m.Elf(Path(sys.argv[1]).read_bytes()))

if __name__=='__main__':unittest.main(argv=[sys.argv[0]],verbosity=2)
