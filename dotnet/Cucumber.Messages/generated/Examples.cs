
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

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
    public ImmutableArray<Tag> Tags { get; }
    public string Keyword { get; }
    public string Name { get; }
    public string Description { get; }
    public TableRow? TableHeader { get; }
    public ImmutableArray<TableRow> TableBody { get; }
    public string Id { get; }


    public Examples(
        Location location,
        ImmutableArray<Tag> tags,
        string keyword,
        string name,
        string description,
        TableRow? tableHeader,
        ImmutableArray<TableRow> tableBody,
        string id
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "Examples.Location cannot be null");
        Tags = tags;
        Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Examples.Keyword cannot be null");
        Name = name ?? throw new ArgumentNullException("Name", "Examples.Name cannot be null");
        Description = description ?? throw new ArgumentNullException("Description", "Examples.Description cannot be null");
        TableHeader = tableHeader;
        TableBody = tableBody;
        Id = id ?? throw new ArgumentNullException("Id", "Examples.Id cannot be null");
    }
}
