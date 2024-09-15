
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Tag message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A tag
 */

public sealed record Tag 
{
    /**
     * Location of the tag
     */
    public Location Location { get; }
    /**
     * The name of the tag (including the leading `@`)
     */
    public string Name { get; }
    /**
     * Unique ID to be able to reference the Tag from PickleTag
     */
    public string Id { get; }


    public Tag(
        Location location,
        string name,
        string id
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "Tag.Location cannot be null");
        Name = name ?? throw new ArgumentNullException("Name", "Tag.Name cannot be null");
        Id = id ?? throw new ArgumentNullException("Id", "Tag.Id cannot be null");
    }
}
