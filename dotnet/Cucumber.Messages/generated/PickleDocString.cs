
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleDocString message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record PickleDocString 
{
    public string? MediaType { get; }
    public string Content { get; }


    public PickleDocString(
        string? mediaType,
        string content
    ) 
    {
        MediaType = mediaType;
        Content = content ?? throw new ArgumentNullException("Content", "PickleDocString.Content cannot be null");
    }
}
