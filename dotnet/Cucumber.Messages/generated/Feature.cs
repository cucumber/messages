using System;
using System.Collections.Generic;

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

public sealed class Feature 
{
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
              RequireNonNull<Location>(location, "Location", "Feature.Location cannot be null");
        this.Location = location;
              RequireNonNull<List<Tag>>(tags, "Tags", "Feature.Tags cannot be null");
        this.Tags = new List<Tag>(tags);
              RequireNonNull<string>(language, "Language", "Feature.Language cannot be null");
        this.Language = language;
              RequireNonNull<string>(keyword, "Keyword", "Feature.Keyword cannot be null");
        this.Keyword = keyword;
              RequireNonNull<string>(name, "Name", "Feature.Name cannot be null");
        this.Name = name;
              RequireNonNull<string>(description, "Description", "Feature.Description cannot be null");
        this.Description = description;
              RequireNonNull<List<FeatureChild>>(children, "Children", "Feature.Children cannot be null");
        this.Children = new List<FeatureChild>(children);
    }

    public override bool Equals(Object o) 
    {
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

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Tags != null)
          hash = hash * 31 + Tags.GetHashCode();
        if (Language != null)
          hash = hash * 31 + Language.GetHashCode();
        if (Keyword != null)
          hash = hash * 31 + Keyword.GetHashCode();
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (Description != null)
          hash = hash * 31 + Description.GetHashCode();
        if (Children != null)
          hash = hash * 31 + Children.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
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

    private static T Require<T>(T property, string propertyName, string errorMessage)
    {
      RequireNonNull<T>(property, propertyName, errorMessage);
      return property;
    }
    private static void RequireNonNull<T>(T property, string propertyName, string errorMessage) 
    {
      if (property == null) throw new ArgumentNullException(propertyName, errorMessage);
    }
}
