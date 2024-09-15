
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the StepDefinitionPattern message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record StepDefinitionPattern 
{
    public string Source { get; }
    public StepDefinitionPatternType Type { get; }


    public StepDefinitionPattern(
        string source,
        StepDefinitionPatternType type
    ) 
    {
        Source = source ?? throw new ArgumentNullException("Source", "StepDefinitionPattern.Source cannot be null");
        Type = type;
    }
}
