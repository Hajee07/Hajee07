import copy
import unittest
from check_projection import assess


def fixture():
    return dict(convention='ROW_ARRAYS_COLUMN_VECTORS_TOP_LEFT_PIXELS',
                view=[[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]],
                projection=[[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]],
                viewport=[10,20,800,600], tolerance_pixels=1,
                depth_range='ZERO_TO_ONE', landmarks=[
                    dict(world=[-.5,-.5,.5],pixel=[210,470]),
                    dict(world=[.5,-.5,.5],pixel=[610,470]),
                    dict(world=[-.5,.5,.5],pixel=[210,170]),
                    dict(world=[.5,.5,.5],pixel=[610,170])])


class ProjectionTests(unittest.TestCase):
    def test_match(self):
        self.assertEqual(assess(fixture())['maximum_error_pixels'], 0)
    def test_mismatch(self):
        d=fixture(); d['landmarks'][0]['pixel'][0]+=10
        self.assertEqual(assess(d)['status'], 'REPROJECTION_MISMATCH')
    def test_translation(self):
        d=fixture(); d['view'][0][3]=.1
        for p in d['landmarks']: p['pixel'][0]+=40
        self.assertLess(assess(d)['maximum_error_pixels'], 1e-10)
    def test_rejections(self):
        cases=[]
        for key,value in [('convention','UNKNOWN'),('depth_range','UNKNOWN'),
                          ('viewport',[0,0,0,600]),('tolerance_pixels',float('nan')),
                          ('landmarks',fixture()['landmarks'][:3])]:
            d=fixture(); d[key]=value; cases.append(d)
        d=fixture(); d['projection'][3][3]=-1; cases.append(d)
        d=fixture(); d['landmarks'][0]['world'][2]=-1; cases.append(d)
        d=fixture(); d['landmarks'][0]['world'][0]=float('inf'); cases.append(d)
        d=fixture(); d['landmarks']=[copy.deepcopy(d['landmarks'][0])]*4; cases.append(d)
        for d in cases:
            with self.subTest(data=d), self.assertRaises(ValueError): assess(d)


if __name__ == '__main__': unittest.main()
