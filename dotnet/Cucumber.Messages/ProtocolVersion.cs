using System.Reflection;

namespace Cucumber.Messages;

public class ProtocolVersion
{
    public static string Version
    {
        get
        {
            return GetPackageVersion(typeof(ProtocolVersion).GetTypeInfo().Assembly);
        }
    }

    private static string GetPackageVersion(Assembly assembly)
    {
        var informationalVersion = assembly.GetCustomAttribute<AssemblyInformationalVersionAttribute>()?.InformationalVersion;
        var version = informationalVersion?.Split(new char['+'], 2)[0];
        return version ?? throw new Exception("Unable to get assembly version");
    }
}
