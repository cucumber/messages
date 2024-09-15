
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

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
    public List<Tag> Tags { get; }
    public string Keyword { get; }
    public string Name { get; }
    public string Description { get; }
    public List<Step> Steps { get; }
    public List<Examples> Examples { get; }
    public string Id { get; }


    public Scenario(
        Location location,
        List<Tag> tags,
        string keyword,
        string name,
        string description,
        List<Step> steps,
        List<Examples> examples,
        string id
    ) 
    {
        this.Location = location ?? throw new ArgumentNullException("Location", "Scenario.Location cannot be null");
        this.Tags = tags ?? throw new ArgumentNullException("Tags", "Scenario.Tags cannot be null");
        this.Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Scenario.Keyword cannot be null");
        this.Name = name ?? throw new ArgumentNullException("Name", "Scenario.Name cannot be null");
        this.Description = description ?? throw new ArgumentNullException("Description", "Scenario.Description cannot be null");
        this.Steps = steps ?? throw new ArgumentNullException("Steps", "Scenario.Steps cannot be null");
        this.Examples = examples ?? throw new ArgumentNullException("Examples", "Scenario.Examples cannot be null");
        this.Id = id ?? throw new ArgumentNullException("Id", "Scenario.Id cannot be null");
    }
}
