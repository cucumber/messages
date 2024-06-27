using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Feature message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class Feature {
    /**
     * The location of the `Feature` keyword
     */
    public Location Location { get; private set; }
    /**
     * All the tags placed above the `Feature` keyword
     */
    public List<Tag> Tags { get; private set; }
    /**
     * The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document
     */
    public string Language { get; private set; }
    /**
     * The text of the `Feature` keyword (in the language specified by `language`)
     */
    public string Keyword { get; private set; }
    /**
     * The name of the feature (the text following the `keyword`)
     */
    public string Name { get; private set; }
    /**
     * The line(s) underneath the line with the `keyword` that are used as description
     */
    public string Description { get; private set; }
    /**
     * Zero or more children
     */
    public List<FeatureChild> Children { get; private set; }

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
        this.Location = location;
        this.Tags = tags;
        this.Language = language;
        this.Keyword = keyword;
        this.Name = name;
        this.Description = description;
        this.Children = children;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Feature that = (Feature) o;
        return 
            Location.Equals(that.Location) &&         
            Tags.Equals(that.Tags) &&         
            Language.Equals(that.Language) &&         
            Keyword.Equals(that.Keyword) &&         
            Name.Equals(that.Name) &&         
            Description.Equals(that.Description) &&         
            Children.Equals(that.Children);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Tags.GetHashCode();
        hash = hash * 31 + Language.GetHashCode();
        hash = hash * 31 + Keyword.GetHashCode();
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + Description.GetHashCode();
        hash = hash * 31 + Children.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "Feature{" +
            "location=" + Location +
            ", tags=" + Tags +
            ", language=" + Language +
            ", keyword=" + Keyword +
            ", name=" + Name +
            ", description=" + Description +
            ", children=" + Children +
            '}';
    }
}
