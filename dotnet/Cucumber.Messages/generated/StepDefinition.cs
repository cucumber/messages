
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the StepDefinition message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record StepDefinition 
{
    public string Id { get; }
    public StepDefinitionPattern Pattern { get; }
    public SourceReference SourceReference { get; }


    public StepDefinition(
        string id,
        StepDefinitionPattern pattern,
        SourceReference sourceReference
    ) 
    {
        Id = id ?? throw new ArgumentNullException("Id", "StepDefinition.Id cannot be null");
        Pattern = pattern ?? throw new ArgumentNullException("Pattern", "StepDefinition.Pattern cannot be null");
        SourceReference = sourceReference ?? throw new ArgumentNullException("SourceReference", "StepDefinition.SourceReference cannot be null");
    }
}
