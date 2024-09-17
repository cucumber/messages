
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

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
    public ImmutableArray<Tag> Tags { get; }
    public string Keyword { get; }
    public string Name { get; }
    public string Description { get; }
    public ImmutableArray<RuleChild> Children { get; }
    public string Id { get; }


    public Rule(
        Location location,
        ImmutableArray<Tag> tags,
        string keyword,
        string name,
        string description,
        ImmutableArray<RuleChild> children,
        string id
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "Rule.Location cannot be null");
        Tags = tags;
        Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Rule.Keyword cannot be null");
        Name = name ?? throw new ArgumentNullException("Name", "Rule.Name cannot be null");
        Description = description ?? throw new ArgumentNullException("Description", "Rule.Description cannot be null");
        Children = children;
        Id = id ?? throw new ArgumentNullException("Id", "Rule.Id cannot be null");
    }
}
