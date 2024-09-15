
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Group message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record Group 
{
    public List<Group> Children { get; }
    public long? Start { get; }
    public string? Value { get; }


    public Group(
        List<Group> children,
        long? start,
        string? value
    ) 
    {
        this.Children = children ?? throw new ArgumentNullException("Children", "Group.Children cannot be null");
        this.Start = start;
        this.Value = value;
    }
}
