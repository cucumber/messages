
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Examples message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record Examples 
{
    /**
     * The location of the `Examples` keyword
     */
    public Location Location { get; }
    public List<Tag> Tags { get; }
    public string Keyword { get; }
    public string Name { get; }
    public string Description { get; }
    public TableRow? TableHeader { get; }
    public List<TableRow> TableBody { get; }
    public string Id { get; }


    public Examples(
        Location location,
        List<Tag> tags,
        string keyword,
        string name,
        string description,
        TableRow? tableHeader,
        List<TableRow> tableBody,
        string id
    ) 
    {
        this.Location = location ?? throw new ArgumentNullException("Location", "Examples.Location cannot be null");
        this.Tags = tags ?? throw new ArgumentNullException("Tags", "Examples.Tags cannot be null");
        this.Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Examples.Keyword cannot be null");
        this.Name = name ?? throw new ArgumentNullException("Name", "Examples.Name cannot be null");
        this.Description = description ?? throw new ArgumentNullException("Description", "Examples.Description cannot be null");
        this.TableHeader = tableHeader;
        this.TableBody = tableBody ?? throw new ArgumentNullException("TableBody", "Examples.TableBody cannot be null");
        this.Id = id ?? throw new ArgumentNullException("Id", "Examples.Id cannot be null");
    }
}
