
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the UndefinedParameterType message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record UndefinedParameterType 
{
    public string Expression { get; }
    public string Name { get; }


    public UndefinedParameterType(
        string expression,
        string name
    ) 
    {
        this.Expression = expression ?? throw new ArgumentNullException("Expression", "UndefinedParameterType.Expression cannot be null");
        this.Name = name ?? throw new ArgumentNullException("Name", "UndefinedParameterType.Name cannot be null");
    }
}
