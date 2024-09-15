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
        var version = assembly.GetCustomAttribute<AssemblyInformationalVersionAttribute>()?.InformationalVersion;
        return version?.Split(new char['+'], 2)[0];
    }
}
