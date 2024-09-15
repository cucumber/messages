
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Feature message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record Feature 
{
    /**
     * The location of the `Feature` keyword
     */
    public Location Location { get; }
    /**
     * All the tags placed above the `Feature` keyword
     */
    public List<Tag> Tags { get; }
    /**
     * The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document
     */
    public string Language { get; }
    /**
     * The text of the `Feature` keyword (in the language specified by `language`)
     */
    public string Keyword { get; }
    /**
     * The name of the feature (the text following the `keyword`)
     */
    public string Name { get; }
    /**
     * The line(s) underneath the line with the `keyword` that are used as description
     */
    public string Description { get; }
    /**
     * Zero or more children
     */
    public List<FeatureChild> Children { get; }


    public Feature(
        Location location,
        List<Tag> tags,
        string language,
        string keyword,
        string name,
        string description,
        List<FeatureChild> children
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "Feature.Location cannot be null");
        Tags = tags ?? throw new ArgumentNullException("Tags", "Feature.Tags cannot be null");
        Language = language ?? throw new ArgumentNullException("Language", "Feature.Language cannot be null");
        Keyword = keyword ?? throw new ArgumentNullException("Keyword", "Feature.Keyword cannot be null");
        Name = name ?? throw new ArgumentNullException("Name", "Feature.Name cannot be null");
        Description = description ?? throw new ArgumentNullException("Description", "Feature.Description cannot be null");
        Children = children ?? throw new ArgumentNullException("Children", "Feature.Children cannot be null");
    }
}
