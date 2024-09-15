
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Hook message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record Hook 
{
    public string Id { get; }
    public string? Name { get; }
    public SourceReference SourceReference { get; }
    public string? TagExpression { get; }


    public Hook(
        string id,
        string? name,
        SourceReference sourceReference,
        string? tagExpression
    ) 
    {
        this.Id = id ?? throw new ArgumentNullException("Id", "Hook.Id cannot be null");
        this.Name = name;
        this.SourceReference = sourceReference ?? throw new ArgumentNullException("SourceReference", "Hook.SourceReference cannot be null");
        this.TagExpression = tagExpression;
    }
}
