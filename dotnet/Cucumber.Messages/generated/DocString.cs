
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the DocString message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record DocString 
{
    public Location Location { get; }
    public string? MediaType { get; }
    public string Content { get; }
    public string Delimiter { get; }


    public DocString(
        Location location,
        string? mediaType,
        string content,
        string delimiter
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "DocString.Location cannot be null");
        MediaType = mediaType;
        Content = content ?? throw new ArgumentNullException("Content", "DocString.Content cannot be null");
        Delimiter = delimiter ?? throw new ArgumentNullException("Delimiter", "DocString.Delimiter cannot be null");
    }
}
