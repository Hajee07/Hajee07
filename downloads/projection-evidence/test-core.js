'use strict';
const assert=require('node:assert/strict'),p=require('./projection-core.js');let cases=0;
function fixture(){const view=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1];return [{Status:'PENDING_LANDMARKS',Matrices:{View:view,Projection:view.slice()},Before:{Width:820,Height:640},ReportSHA256:'fixture'},[10,20,800,600],{WorldCoordinateSource:'Independent synthetic scene geometry',Landmarks:[{Id:'a',World:[-.5,-.5,.5]},{Id:'b',World:[.5,-.5,.5]},{Id:'c',World:[-.5,.5,.5]},{Id:'d',World:[.5,.5,.5]}]},{a:[210,470],b:[610,470],c:[210,170],d:[610,170]}];}
function assess(f){return p.assess(f[0],'Before',f[1],f[2],f[3],'COLUMN_MAJOR_COLUMN_VECTOR','ZERO_TO_ONE',1);}
let f=fixture(),r=assess(f);assert.equal(r.Status,'SUPPLIED_LANDMARK_REPROJECTION_MATCH');assert.equal(r.MaximumErrorPixels,0);assert.equal(r.FrameAlignment,'BRACKETED_ONLY_NOT_SYNCHRONIZED');cases++;
f=fixture();f[3].a[0]+=10;assert.equal(assess(f).Status,'SUPPLIED_LANDMARK_REPROJECTION_MISMATCH');cases++;
f=fixture();f[0].Matrices.View[12]=.1;for(const v of Object.values(f[3]))v[0]+=40;assert(assess(f).MaximumErrorPixels<1e-10);cases++;
for(const change of [f=>f[0].Status='INCOMPLETE_CAPTURE',f=>f[1][2]=900,f=>f[2].Landmarks[0].World=null,f=>f[2].WorldCoordinateSource='MISSING',f=>f[2].Landmarks=f[2].Landmarks.slice(0,3),f=>f[3].a=null,f=>f[3].a=[-1,1],f=>f[0].Matrices.View[0]=NaN,f=>f[2].Landmarks[1].Id='a',f=>f[2].Landmarks[0].World=[100,0,.5]]){f=fixture();change(f);assert.throws(()=>assess(f));cases++;}
f=fixture();assert.throws(()=>p.assess(f[0],'Before',f[1],f[2],f[3],'UNKNOWN','ZERO_TO_ONE',1));cases++;
assert.throws(()=>p.assess(f[0],'Before',f[1],f[2],f[3],'COLUMN_MAJOR_COLUMN_VECTOR','UNKNOWN',1));cases++;
assert.throws(()=>p.assess(f[0],'Before',f[1],f[2],f[3],'COLUMN_MAJOR_COLUMN_VECTOR','ZERO_TO_ONE',Infinity));cases++;
console.log('ProjectionCore=PASS Cases='+cases+' LivePixels=NOT_TESTED');
