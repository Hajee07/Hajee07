'use strict';
const fs=require('node:fs'),vm=require('node:vm'),assert=require('node:assert/strict');
async function main(){
 const elements=Object.create(null),downloads=[];let blob;
 function element(id){if(!elements[id])elements[id]={value:'',textContent:'',disabled:false,children:[],append(o){this.children.push(o);if(!this.value)this.value=o.value;},replaceChildren(){this.children=[];this.value='';}};return elements[id];}
 const ctx=Object.fromEntries(['clearRect','drawImage','strokeRect','beginPath','arc','fill','fillText','stroke'].map(k=>[k,()=>{}]));
 const canvas=element('canvas');canvas.getContext=()=>ctx;canvas.getBoundingClientRect=()=>({left:20,top:10,width:400,height:300});
 element('role').value='Before';element('tolerance').value='1';
 class Image{set src(v){this.complete=true;this.naturalWidth=800;this.naturalHeight=600;if(this.onload)this.onload();}}
 const document={getElementById:element,createElement(tag){if(tag==='a')return{click(){downloads.push({name:this.download,body:JSON.parse(blob.parts[0])});}};return {value:'',textContent:''};}};
 const screenshot={Name:'view-before.png',Width:800,Height:600,SHA256:'SYNTHETIC'};
 const eye=[1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1];
 const evidence={Status:'PENDING_LANDMARKS',Before:screenshot,After:{...screenshot,Name:'view-after.png'},Matrices:{View:eye,Projection:eye.slice()},ReportSHA256:'SYNTHETIC'};
 const context=vm.createContext({document,Image,ProjectionCore:require('./projection-core.js'),Blob:class{constructor(parts){this.parts=parts;blob=this;}},URL:{createObjectURL:()=> 'fixture',revokeObjectURL:()=>{}},setTimeout:fn=>fn(),console});
 const html=fs.readFileSync(__dirname+'/review-template.html','utf8').replace('__EVIDENCE_CONFIG__',JSON.stringify(evidence));
 for(const match of html.matchAll(/<script>([\s\S]*?)<\/script>/g))vm.runInContext(match[1],context);
 element('rectangle').onclick();canvas.onclick({clientX:70,clientY:60});canvas.onclick({clientX:370,clientY:260});element('saveViewport').onclick();
 assert.deepEqual(downloads.at(-1).body.Viewport,[100,100,600,400]);assert.equal(downloads.at(-1).body.Status,'PENDING_LANDMARKS');
 const landmarks={WorldCoordinateSource:'Independent synthetic geometry',Landmarks:[{Id:'a',World:[-.5,-.5,.5]},{Id:'b',World:[.5,-.5,.5]},{Id:'c',World:[-.5,.5,.5]},{Id:'d',World:[.5,.5,.5]}]};
 await element('worldFile').onchange({target:{files:[{text:async()=>JSON.stringify(landmarks)}]}});
 for(const [id,p]of Object.entries({a:[250,400],b:[550,400],c:[250,200],d:[550,200]})){element('landmark').value=id;canvas.onclick({clientX:20+p[0]/2,clientY:10+p[1]/2});}
 element('convention').value='COLUMN_MAJOR_COLUMN_VECTOR';element('depth').value='ZERO_TO_ONE';element('compare').onclick();
 assert.equal(element('saveComparison').disabled,false);element('saveComparison').onclick();assert.equal(downloads.at(-1).body.Status,'SUPPLIED_LANDMARK_REPROJECTION_MATCH');assert.equal(downloads.at(-1).body.ActualRenderedCamera,'UNVERIFIED');
 await element('worldFile').onchange({target:{files:[{text:async()=>'{"WorldCoordinateSource":"MISSING"}'}]}});assert.equal(element('saveComparison').disabled,true);
 element('role').value='After';element('role').onchange();assert.equal(element('viewport').textContent,'Viewport: not measured');assert.equal(element('saveComparison').disabled,true);
 const count=downloads.length;vm.runInContext('image.onerror()',context);element('full').onclick();element('saveViewport').onclick();assert.equal(downloads.length,count);
 console.log('ReviewUIHandlers=PASS CanvasScalingAndViewport=PASS LandmarkExport=PASS StaleResultSuppression=PASS Environment=SIMULATED_DOM_NOT_BROWSER');
}
main().catch(e=>{console.error(e);process.exit(1);});
