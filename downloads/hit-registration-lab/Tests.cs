using System.Net;
using System.Net.Http.Json;
using System.Net.Sockets;
using System.Text;
using System.Text.Json;
namespace HitLab;
public static class Tests
{
    private static int checks;
    private static void Check(bool value,string name){if(!value)throw new Exception("FAIL: "+name);checks++;Console.WriteLine("PASS: "+name);}
    private static int FreePort(){var socket=new TcpListener(IPAddress.Loopback,0);socket.Start();int port=((IPEndPoint)socket.LocalEndpoint).Port;socket.Stop();return port;}
    public static async Task Run()
    {
        var sphere=new Hitbox(Region.Head,new(0,0,5),1);
        Check(Math.Abs(Geometry.RaySphere(new(0,0,0),new(0,0,1),sphere,10)!.Value-4)<1e-10,"analytic sphere entry distance");
        Check(Geometry.RaySphere(new(0,0,0),new(0,0,1),sphere,3) is null,"range limit");
        Check(Geometry.RaySphere(new(1,0,0),new(0,0,1),sphere,10)==5,"tangent contact");
        Check(Geometry.RaySphere(new(0,0,5),new(0,0,1),sphere,10)==0,"origin inside volume");
        Check(Geometry.RaySphere(new(2,0,0),new(0,0,1),sphere,10) is null,"geometric miss");
        bool boundsRejected=false;try{Geometry.RaySphere(new(0,0,0),new(0,0,1),sphere,-1);}catch(ArgumentException){boundsRejected=true;}Check(boundsRejected,"invalid ray bounds rejected");
        var near=Geometry.First(new(0,0,0),new(0,0,1),new[]{sphere,new Hitbox(Region.Chest,new(0,0,2),0.25)},10);
        Check(near?.Region==Region.Chest,"nearest collider wins over head behind it");
        var rotated=new Rotation(0,Math.Sin(Math.PI/4),0,Math.Cos(Math.PI/4)).Apply(new(0,0,1));
        Check((rotated-new Vec(1,0,0)).Length<1e-10,"known quaternion rotates forward to right");
        bool bad=false;try{new Rotation(0,0,0,0).Apply(new(1,0,0));}catch(ArgumentException){bad=true;}Check(bad,"invalid quaternion rejected");
        var ballistic=Geometry.Projectile(new(0,0,0),new(0,0,10),new(0,0,0),1,.01,new[]{sphere});
        Check(ballistic.HasValue&&Math.Abs(ballistic.Value.Time-.4)<1e-8,"ballistic zero-gravity time oracle");
        var falling=Geometry.Projectile(new(0,1,0),new(0,0,10),new(0,-9.81,0),1,.005,new[]{new Hitbox(Region.Leg,new(0,-.22625,5),.1)});
        Check(falling.HasValue,"gravity trajectory intersects independently placed falling target");
        foreach(var policy in Enum.GetValues<ClassificationPolicy>())
        {
            var a=new Authority(new(policy));var id=a.OpenSession();long seq=0;
            foreach(var box in a.Scene.Boxes)
            {
                var r=a.Submit(new(id,++seq,box.Center-a.Scene.Origin,Region.Head));
                Check(r.Accepted&&r.GeometricRegion==box.Region&&r.AwardedRegion==(policy==ClassificationPolicy.Geometric?box.Region:Region.Head),$"{policy} server collision/classification {box.Region}");
                Check(r.ClaimMatchesGeometry==(box.Region==Region.Head),$"{policy} reports client claim discrepancy {box.Region}");
            }
            Check(!a.Submit(new(id,seq,new(0,0,1),Region.Head)).Accepted,"replayed sequence rejected");
            Check(a.Submit(new(id,++seq,new(0,0,-1),Region.Head)).Reason=="MISS","conversion does not create a hit from miss");
            Check(a.Submit(new(id,++seq,new(double.NaN,0,1),Region.Head)).Reason=="INVALID_DIRECTION","nonfinite direction rejected");
            Check(a.Submit(new(id,++seq,new(0,0,0),Region.Head)).Reason=="INVALID_DIRECTION","zero direction rejected");
            Check(a.Submit(new(Guid.NewGuid(),1,new(0,0,1),Region.Head)).Reason=="UNKNOWN_OR_EXPIRED_SESSION","unissued session rejected");
        }
        var wall=new Authority(new(ClassificationPolicy.AllValidatedHitsAreHeadshots,true));
        Check(wall.Submit(new(wall.OpenSession(),1,wall.Scene.Boxes[0].Center-wall.Scene.Origin,Region.Head)).Reason=="OCCLUDED","conversion cannot bypass wall");
        var scene=new Authority(new(ClassificationPolicy.Geometric),new(2,0,1),new Rotation(0,Math.Sin(.4),0,Math.Cos(.4)));
        Check(scene.Submit(new(scene.OpenSession(),1,scene.Scene.Boxes[0].Center-scene.Scene.Origin,null)).GeometricRegion==Region.Head,"transformed skeleton center used by server");
        foreach(var policy in Enum.GetValues<ClassificationPolicy>()) await Network(policy,false);
        await Network(ClassificationPolicy.AllValidatedHitsAreHeadshots,true);
        Console.WriteLine($"TESTS=PASS Checks={checks} Scope=OWNED_LOCAL_LAB WindowsExecution=NOT_TESTED FreeFireServerAcceptance=NOT_TESTED");
    }
    private static async Task Network(ClassificationPolicy policy,bool blocked)
    {
        int port=FreePort();string url=$"http://127.0.0.1:{port}/";
        using var stop=new CancellationTokenSource();var a=new Authority(new(policy,blocked,10));
        await using var server=new LabServer(port,a);Task running=server.Run(stop.Token);
        try
        {
            using var http=new HttpClient{BaseAddress=new(url),Timeout=TimeSpan.FromSeconds(5)};
            Check((await http.GetStringAsync("health")).Contains("ready"),"HTTP readiness request");
            Check((await http.GetStringAsync("")).Contains("Owned Hit Registration Lab"),"controlled game page served");
            using var client=new ExternalClient(url);var scene=await client.Scene();var session=await client.Session();long seq=0;var times=new List<double>();
            foreach(var box in scene.Boxes)
            {
                var result=await client.Fire(new(session,++seq,box.Center-scene.Origin,Region.Head));
                times.Add(result.RttMs);
                Check(blocked?result.Receipt.Reason=="OCCLUDED":result.Receipt.Accepted&&result.Receipt.GeometricRegion==box.Region&&result.Receipt.AwardedRegion==(policy==ClassificationPolicy.Geometric?box.Region:Region.Head),$"HTTP {policy} Wall={blocked} {box.Region}");
            }
            Check((await client.Fire(new(session,seq,new(0,0,1),Region.Head))).Receipt.Reason=="REPLAY_OR_OUT_OF_ORDER","HTTP replay rejected");
            using var malformed=await http.PostAsync("shot",new StringContent("{broken",Encoding.UTF8,"application/json"));Check(malformed.StatusCode==HttpStatusCode.BadRequest,"malformed JSON rejected without server crash");
            using var oversized=await http.PostAsync("shot",new StringContent(new string('x',5000)));Check(oversized.StatusCode==HttpStatusCode.RequestEntityTooLarge,"oversized request rejected");
            Check((await http.GetStringAsync("health")).Contains("ready"),"server healthy after invalid input");
            string report=Path.Combine(Path.GetTempPath(),Guid.NewGuid()+".json");
            try{await client.Experiment(report);using var doc=JsonDocument.Parse(await File.ReadAllTextAsync(report));Check(doc.RootElement.GetProperty("rows").GetArrayLength()==6,"client writes six event experiment report");}finally{File.Delete(report);}
            times.Sort();Console.WriteLine($"MEASURE Policy={policy} Wall={blocked} Samples={times.Count} RttMedianMs={times[times.Count/2]:F3} RttMaxMs={times[^1]:F3} InjectedServerDelayMs=10");
        }
        finally {stop.Cancel();await running;}
    }
}
