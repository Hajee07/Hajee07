"""Reproduce C# math fixtures using the separately published isolated ARM64 verifier."""
import argparse,importlib.util,math,struct,sys
from pathlib import Path
sys.dont_write_bytecode=True
p=argparse.ArgumentParser();p.add_argument('unity');p.add_argument('mapper');p.add_argument('verifier_directory');p.add_argument('output_fragment');a=p.parse_args()
sys.path.insert(0,str(Path(a.verifier_directory).resolve()));import verify_dirty_view as v
spec=importlib.util.spec_from_file_location('mapper',a.mapper);r=importlib.util.module_from_spec(spec);spec.loader.exec_module(r);r.ELF_SHA=v.SHA
machine=v.SyntheticMachine(r.Elf(Path(a.unity).read_bytes()))
def world_pose(records):
 rows=[[[struct.unpack('<f',struct.pack('<f',x))[0] for x in vec] for vec in row] for row in records]
 position,quaternion=rows[0][0][:],rows[0][1][:]
 for t,q,s in rows[1:]:
  matrix=v.rotation(q);scaled=[position[k]*s[k] for k in range(3)]
  position=[t[i]+sum(matrix[i][k]*scaled[k] for k in range(3)) for i in range(3)]
  negative=[math.copysign(1,x)<0 for x in s]
  reflected=[quaternion[i]*(-1 if negative[(i+1)%3]!=negative[(i+2)%3] else 1) for i in range(3)]+[quaternion[3]]
  quaternion=v.qmul(q,reflected)
 return position,quaternion
code=['        private static void RunDerivedGoldenChecks() {','            float[] p,q; double[] actual,expected; bool same;']
for name,records in v.cases():
 pos,quat=world_pose(records);want=machine.run(records)
 def literals(values,suffix):return ','.join(format(x,'.17g')+('f' if suffix else 'd') for x in values)
 code+=['            p=new float[]{'+literals(pos,True)+'};q=new float[]{'+literals(quat,True)+'};expected=new double[]{'+literals(want,False)+'};', '            actual=Reader.DeriveViewSequence(p,q);same=true;for(int i=0;i<16;i++)same &= Math.Abs(actual[i]-expected[i])<=.001+.0001*Math.Abs(expected[i]);CameraCheck(same,"derived C# versus isolated ARM64 '+name+'");']
code+=['        }'];Path(a.output_fragment).write_text('\n'.join(code)+'\n');print('DerivedViewGoldens=GENERATED Cases=137')
