(function(root){
'use strict';
function vector(v,n){if(!Array.isArray(v)||v.length!==n||v.some(x=>typeof x!=='number'||!Number.isFinite(x)))throw Error('Finite numeric vector required');return v;}
function rows(values){vector(values,16);return Array.from({length:4},(_,r)=>Array.from({length:4},(_,c)=>values[c*4+r]));}
function mul(m,v){return m.map(row=>row.reduce((s,x,i)=>s+x*v[i],0));}
function rectangle(v,width,height){vector(v,4);if(v[0]<0||v[1]<0||v[2]<=0||v[3]<=0||v[0]+v[2]>width||v[1]+v[3]>height)throw Error('Viewport must fit inside selected screenshot');return v;}
function readLandmarks(data){
 if(!data||typeof data.WorldCoordinateSource!=='string'||!data.WorldCoordinateSource.trim()||/^(REPLACE|MISSING)/.test(data.WorldCoordinateSource))throw Error('Independent world-coordinate source description required');
 if(!Array.isArray(data.Landmarks)||data.Landmarks.length<4)throw Error('At least four world landmarks required');
 const ids=new Set(),points=new Set();
 data.Landmarks.forEach(p=>{if(typeof p.Id!=='string'||!p.Id.trim()||ids.has(p.Id))throw Error('Distinct landmark IDs required');ids.add(p.Id);vector(p.World,3);points.add(JSON.stringify(p.World));});
 if(points.size<4)throw Error('At least four distinct world positions required');return data.Landmarks;
}
function assess(config,role,viewport,data,pixels,convention,depth,tolerance){
 if(config.Status!=='PENDING_LANDMARKS'||!config.Matrices)throw Error('Successful ready V6 report required');
 if(convention!=='COLUMN_MAJOR_COLUMN_VECTOR')throw Error('Select the explicit candidate convention');
 if(!['MINUS_ONE_TO_ONE','ZERO_TO_ONE'].includes(depth))throw Error('Select explicit clip-depth convention');
 if(typeof tolerance!=='number'||!Number.isFinite(tolerance)||tolerance<=0||tolerance>20)throw Error('Tolerance must be >0 and <=20 pixels');
 if(!['Before','After'].includes(role))throw Error('Unknown screenshot role');
 const image=config[role];rectangle(viewport,image.Width,image.Height);
 const view=rows(config.Matrices.View),projection=rows(config.Matrices.Projection),landmarks=readLandmarks(data);
 const details=landmarks.map(p=>{
  const pixel=vector(pixels[p.Id],2);if(pixel[0]<viewport[0]||pixel[1]<viewport[1]||pixel[0]>viewport[0]+viewport[2]||pixel[1]>viewport[1]+viewport[3])throw Error('Measured point outside viewport');
  const clip=mul(projection,mul(view,p.World.concat(1)));if(!clip.every(Number.isFinite)||clip[3]<=1e-8)throw Error('Invalid/behind-camera landmark '+p.Id);
  const ndc=clip.slice(0,3).map(x=>x/clip[3]);const low=depth==='ZERO_TO_ONE'?0:-1;
  if(ndc[0]<-1||ndc[0]>1||ndc[1]<-1||ndc[1]>1||ndc[2]<low||ndc[2]>1)throw Error('Landmark outside candidate clip volume: '+p.Id);
  const predicted=[viewport[0]+(ndc[0]+1)*viewport[2]/2,viewport[1]+(1-ndc[1])*viewport[3]/2];
  return {Id:p.Id,World:p.World,MeasuredPixel:pixel,PredictedPixel:predicted,ErrorPixels:Math.hypot(predicted[0]-pixel[0],predicted[1]-pixel[1])};
 });
 const maximum=Math.max(...details.map(p=>p.ErrorPixels));
 return {Schema:1,Status:maximum<=tolerance?'SUPPLIED_LANDMARK_REPROJECTION_MATCH':'SUPPLIED_LANDMARK_REPROJECTION_MISMATCH',Scope:'USER_SUPPLIED_WORLD_AND_PIXEL_DATA_CANDIDATE_CONVENTION_ONLY',ViewportStatus:'USER_DECLARED_RECTANGLE',Viewport:viewport,Screenshot:image,ReportSHA256:config.ReportSHA256,WorldCoordinateSource:data.WorldCoordinateSource,Convention:convention,DepthRange:depth,TolerancePixels:tolerance,MaximumErrorPixels:maximum,RmsPixels:Math.sqrt(details.reduce((s,p)=>s+p.ErrorPixels*p.ErrorPixels,0)/details.length),Landmarks:details,ActualRenderedCamera:'UNVERIFIED',FrameAlignment:'BRACKETED_ONLY_NOT_SYNCHRONIZED',AimWrites:'NONE'};
}
const api={vector,rows,mul,rectangle,readLandmarks,assess};if(typeof module!=='undefined'&&module.exports)module.exports=api;else root.ProjectionCore=api;
})(typeof globalThis!=='undefined'?globalThis:this);
