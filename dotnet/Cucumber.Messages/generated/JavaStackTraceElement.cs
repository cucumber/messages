
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the JavaStackTraceElement message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record JavaStackTraceElement 
{
    public string ClassName { get; }
    public string FileName { get; }
    public string MethodName { get; }


    public JavaStackTraceElement(
        string className,
        string fileName,
        string methodName
    ) 
    {
        this.ClassName = className ?? throw new ArgumentNullException("ClassName", "JavaStackTraceElement.ClassName cannot be null");
        this.FileName = fileName ?? throw new ArgumentNullException("FileName", "JavaStackTraceElement.FileName cannot be null");
        this.MethodName = methodName ?? throw new ArgumentNullException("MethodName", "JavaStackTraceElement.MethodName cannot be null");
    }
}
