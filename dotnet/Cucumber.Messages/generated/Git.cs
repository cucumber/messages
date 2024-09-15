
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Git message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Information about Git, provided by the Build/CI server as environment
 * variables.
 */

public sealed record Git 
{
    public string Remote { get; }
    public string Revision { get; }
    public string? Branch { get; }
    public string? Tag { get; }


    public Git(
        string remote,
        string revision,
        string? branch,
        string? tag
    ) 
    {
        Remote = remote ?? throw new ArgumentNullException("Remote", "Git.Remote cannot be null");
        Revision = revision ?? throw new ArgumentNullException("Revision", "Git.Revision cannot be null");
        Branch = branch;
        Tag = tag;
    }
}
