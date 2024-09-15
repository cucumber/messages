
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Rule message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record Rule 
{
    /**
     * The location of the `Rule` keyword
     */
    public Location Location { get; }
    /**
     * All the tags placed above the `Rule` keyword
     */
    public List<Tag> Tags { get; }
    public string Keyword { get; }
    public string Name { get; }
    public string Description { get; }
    public List<RuleChild> Children { get; }
    public string Id { get; }


    public Rule(
        Location location,
        List<Tag> tags,
        string keyword,
        string name,
        string description,
        List<RuleChild> children,
        string id
    ) 
    {
        this.Location = location ?? throw new ArgumentNullException("Location", "Rule.Location cannot be null");
        this.Tags = tags ?? throw new ArgumentNullException("Tags", "Rule.Tags cannot be null");
        this.Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Rule.Keyword cannot be null");
        this.Name = name ?? throw new ArgumentNullException("Name", "Rule.Name cannot be null");
        this.Description = description ?? throw new ArgumentNullException("Description", "Rule.Description cannot be null");
        this.Children = children ?? throw new ArgumentNullException("Children", "Rule.Children cannot be null");
        this.Id = id ?? throw new ArgumentNullException("Id", "Rule.Id cannot be null");
    }
}
