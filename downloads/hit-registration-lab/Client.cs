using System.Diagnostics;
using System.Net.Http.Json;
using System.Text.Json;
namespace HitLab;
public sealed class ExternalClient : IDisposable
{
    private readonly HttpClient http;
    public ExternalClient(string endpoint)
    {
        var uri=new Uri(endpoint);
        if(uri.Scheme!="http"||uri.Host!="127.0.0.1")throw new ArgumentException("Local owned server at 127.0.0.1 required");
        http=new(){BaseAddress=uri,Timeout=TimeSpan.FromSeconds(10)};
    }
    public async Task<Scene> Scene()=>await http.GetFromJsonAsync<Scene>("scene",Wire.Json)??throw new InvalidOperationException();
    public async Task<Guid> Session()
    {
        using var response=await http.PostAsync("session",null);response.EnsureSuccessStatusCode();
        using var doc=JsonDocument.Parse(await response.Content.ReadAsStringAsync());return doc.RootElement.GetProperty("session").GetGuid();
    }
    public async Task<(Receipt Receipt,double RttMs)> Fire(Shot shot)
    {
        long start=Stopwatch.GetTimestamp();using var response=await http.PostAsJsonAsync("shot",shot,Wire.Json);response.EnsureSuccessStatusCode();
        var receipt=await response.Content.ReadFromJsonAsync<Receipt>(Wire.Json)??throw new InvalidOperationException();
        return(receipt,Stopwatch.GetElapsedTime(start).TotalMilliseconds);
    }
    public async Task<object> Experiment(string reportPath)
    {
        var scene=await Scene();var session=await Session();var rows=new List<object>();long sequence=0;
        var config=await http.GetFromJsonAsync<LabConfig>("policy",Wire.Json)??throw new InvalidOperationException();
        var latencies=new List<double>();int accepted=0,geometricAgreement=0,policyAgreement=0,claimDisagreements=0;
        var outcomes=new Dictionary<string,int>();
        foreach(var box in scene.Boxes)
        {
            var result=await Fire(new(session,++sequence,box.Center-scene.Origin,Region.Head));
            latencies.Add(result.RttMs);
            var receipt=result.Receipt;
            outcomes[receipt.Reason]=outcomes.GetValueOrDefault(receipt.Reason)+1;
            if(receipt.Accepted){accepted++;if(receipt.GeometricRegion==box.Region)geometricAgreement++;if(receipt.AwardedRegion==(config.Policy==ClassificationPolicy.Geometric?receipt.GeometricRegion:Region.Head))policyAgreement++;}
            if(receipt.ClaimMatchesGeometry==false)claimDisagreements++;
            rows.Add(new{aimedAt=box.Region,clientClaim=Region.Head,result.Receipt,result.RttMs});
        }
        latencies.Sort();
        var metrics=new{shots=rows.Count,accepted,geometricAgreementWithAnalyticCenter=geometricAgreement,serverPolicyAgreement=policyAgreement,claimDisagreements,outcomes,rttMedianMs=(latencies[2]+latencies[3])/2,rttP95Ms=latencies[(int)Math.Ceiling(latencies.Count*.95)-1],sampleCount=latencies.Count};
        var report=new{config,metrics,scope="OWNED_LOCAL_LAB_ONLY",utc=DateTimeOffset.UtcNow,rows,latencyMeaning="HTTP round trip including server processing; not one-way network latency",freeFireServerAcceptance="NOT_TESTED"};
        await File.WriteAllTextAsync(reportPath,JsonSerializer.Serialize(report,new JsonSerializerOptions(Wire.Json){WriteIndented=true}));return report;
    }
    public void Dispose()=>http.Dispose();
}
