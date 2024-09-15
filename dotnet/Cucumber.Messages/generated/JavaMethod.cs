
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the JavaMethod message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record JavaMethod 
{
    public string ClassName { get; }
    public string MethodName { get; }
    public List<string> MethodParameterTypes { get; }


    public JavaMethod(
        string className,
        string methodName,
        List<string> methodParameterTypes
    ) 
    {
        ClassName = className ?? throw new ArgumentNullException("ClassName", "JavaMethod.ClassName cannot be null");
        MethodName = methodName ?? throw new ArgumentNullException("MethodName", "JavaMethod.MethodName cannot be null");
        MethodParameterTypes = methodParameterTypes ?? throw new ArgumentNullException("MethodParameterTypes", "JavaMethod.MethodParameterTypes cannot be null");
    }
}
