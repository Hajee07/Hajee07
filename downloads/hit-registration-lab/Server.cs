using System.Net;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
namespace HitLab;
public static class Wire
{
    public static readonly JsonSerializerOptions Json=new(JsonSerializerDefaults.Web){Converters={new JsonStringEnumConverter()}};
}
public sealed class LabServer : IAsyncDisposable
{
    private readonly HttpListener listener=new();
    private readonly Authority authority;
    public LabServer(int port,Authority authority)
    {
        if(port<1024||port>65535) throw new ArgumentException("Port must be 1024..65535");
        this.authority=authority;listener.Prefixes.Add($"http://127.0.0.1:{port}/");
    }
    public async Task Run(CancellationToken token)
    {
        listener.Start();
        using var registration=token.Register(()=>listener.Stop());
        try
        {
            while(!token.IsCancellationRequested)
            {
                var context=await listener.GetContextAsync();
                await Handle(context,token);
            }
        }
        catch(Exception e) when(token.IsCancellationRequested&&(e is HttpListenerException or ObjectDisposedException)) { }
    }
    private async Task Handle(HttpListenerContext c,CancellationToken token)
    {
        try
        {
            c.Response.Headers["Cache-Control"]="no-store";
            string path=c.Request.Url!.AbsolutePath;
            if(c.Request.HttpMethod=="GET"&&path=="/")
            {
                c.Response.ContentType="text/html; charset=utf-8";
                byte[] page=await File.ReadAllBytesAsync(Path.Combine(AppContext.BaseDirectory,"game.html"),token);
                await c.Response.OutputStream.WriteAsync(page,token);return;
            }
            object body;
            if(c.Request.HttpMethod=="GET"&&path=="/health")body=new{status="ready",scope="OWNED_LOCAL_LAB"};
            else if(c.Request.HttpMethod=="GET"&&path=="/policy")body=authority.Config;
            else if(c.Request.HttpMethod=="GET"&&path=="/scene")body=authority.Scene;
            else if(c.Request.HttpMethod=="POST"&&path=="/session")body=new{session=authority.OpenSession()};
            else if(c.Request.HttpMethod=="POST"&&path=="/shot")
            {
                if(c.Request.ContentLength64==0||c.Request.ContentLength64>4096){c.Response.StatusCode=413;body=new{error="Request body must be 1..4096 bytes"};}
                else
                {
                    using var timeout=CancellationTokenSource.CreateLinkedTokenSource(token);timeout.CancelAfter(TimeSpan.FromSeconds(3));
                    using var payload=new MemoryStream();var buffer=new byte[1024];
                    while(true)
                    {
                        int count=await c.Request.InputStream.ReadAsync(buffer,timeout.Token);
                        if(count==0)break;
                        if(payload.Length+count>4096)throw new JsonException("Body too large");
                        payload.Write(buffer,0,count);
                    }
                    var shot=JsonSerializer.Deserialize<Shot>(payload.ToArray(),Wire.Json)??throw new JsonException("Missing shot");
                    var receipt=authority.Submit(shot);
                    if(authority.Config.DelayMs>0)await Task.Delay(authority.Config.DelayMs,token);
                    body=receipt;
                }
            }
            else {c.Response.StatusCode=404;body=new{error="Unknown route or method"};}
            c.Response.ContentType="application/json";
            await JsonSerializer.SerializeAsync(c.Response.OutputStream,body,body.GetType(),Wire.Json,token);
        }
        catch(Exception e) when(e is JsonException or ArgumentException or EndOfStreamException or OperationCanceledException or InvalidOperationException)
        {
            try{c.Response.StatusCode=400;await c.Response.OutputStream.WriteAsync(Encoding.UTF8.GetBytes("{\"error\":\"Invalid or incomplete lab request\"}"));}catch(HttpListenerException){}
        }
        catch(HttpListenerException){ }
        finally {c.Response.Close();}
    }
    public ValueTask DisposeAsync(){listener.Close();return ValueTask.CompletedTask;}
}
