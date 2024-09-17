
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Scenario message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record Scenario 
{
    /**
     * The location of the `Scenario` keyword
     */
    public Location Location { get; }
    public ImmutableArray<Tag> Tags { get; }
    public string Keyword { get; }
    public string Name { get; }
    public string Description { get; }
    public ImmutableArray<Step> Steps { get; }
    public ImmutableArray<Examples> Examples { get; }
    public string Id { get; }


    public Scenario(
        Location location,
        ImmutableArray<Tag> tags,
        string keyword,
        string name,
        string description,
        ImmutableArray<Step> steps,
        ImmutableArray<Examples> examples,
        string id
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "Scenario.Location cannot be null");
        Tags = tags;
        Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Scenario.Keyword cannot be null");
        Name = name ?? throw new ArgumentNullException("Name", "Scenario.Name cannot be null");
        Description = description ?? throw new ArgumentNullException("Description", "Scenario.Description cannot be null");
        Steps = steps;
        Examples = examples;
        Id = id ?? throw new ArgumentNullException("Id", "Scenario.Id cannot be null");
    }
}
