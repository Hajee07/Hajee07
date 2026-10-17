using System.Text.Json;
namespace HitLab;
public static class Program
{
    public static async Task<int> Main(string[] args)
    {
        try
        {
            string mode=args.FirstOrDefault()??"help";
            string Option(string name,string fallback){int i=Array.IndexOf(args,name);return i>=0&&i+1<args.Length?args[i+1]:fallback;}
            if(mode=="test"){await Tests.Run();return 0;}
            if(mode=="environment")
            {
                Console.WriteLine(JsonSerializer.Serialize(new{os=System.Runtime.InteropServices.RuntimeInformation.OSDescription,processArchitecture=System.Runtime.InteropServices.RuntimeInformation.ProcessArchitecture.ToString(),framework=System.Runtime.InteropServices.RuntimeInformation.FrameworkDescription,pointerBytes=IntPtr.Size,littleEndian=BitConverter.IsLittleEndian,scope="HOST_ONLY_NO_EMULATOR_ACCESS"},Wire.Json));return 0;
            }
            if(mode=="server")
            {
                string policy=Option("--policy","geometric");
                if(policy!="geometric"&&policy!="convert")throw new ArgumentException("Use geometric or convert policy");
                var config=new LabConfig(policy=="convert"?ClassificationPolicy.AllValidatedHitsAreHeadshots:ClassificationPolicy.Geometric,args.Contains("--wall"),int.Parse(Option("--delay-ms","0")));
                int port=int.Parse(Option("--port","5088"));
                await using var server=new LabServer(port,new(config));using var stop=new CancellationTokenSource();
                Console.CancelKeyPress+=(_,e)=>{e.Cancel=true;stop.Cancel();};
                Console.WriteLine($"Owned lab http://127.0.0.1:{port}/ Policy={policy}; Ctrl+C stops server");await server.Run(stop.Token);return 0;
            }
            if(mode=="client")
            {
                using var client=new ExternalClient(Option("--url","http://127.0.0.1:5088/"));
                string output=Option("--report","experiment.json");await client.Experiment(output);Console.WriteLine($"Report={Path.GetFullPath(output)}");return 0;
            }
            Console.WriteLine("HitLab: server [--policy geometric|convert] [--port 5088] [--wall] [--delay-ms 0..1000] | client [--url http://127.0.0.1:5088/] [--report experiment.json] | test | environment");return mode=="help"?0:1;
        }
        catch(Exception e){Console.Error.WriteLine(e.Message);return 1;}
    }
}
