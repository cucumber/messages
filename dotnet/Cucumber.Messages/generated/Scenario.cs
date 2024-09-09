using System;
using System.Collections.Generic;

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

public sealed class Scenario 
{
    /**
     * The location of the `Scenario` keyword
     */
    public Location Location { get; private set; }
    public List<Tag> Tags { get; private set; }
    public string Keyword { get; private set; }
    public string Name { get; private set; }
    public string Description { get; private set; }
    public List<Step> Steps { get; private set; }
    public List<Examples> Examples { get; private set; }
    public string Id { get; private set; }


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
              RequireNonNull<Location>(location, "Location", "Scenario.Location cannot be null");
        this.Location = location;
              RequireNonNull<List<Tag>>(tags, "Tags", "Scenario.Tags cannot be null");
        this.Tags = tags == null ? new List<Tag>() : new List<Tag>(tags);
              RequireNonNull<string>(keyword, "Keyword", "Scenario.Keyword cannot be null");
        this.Keyword = keyword;
              RequireNonNull<string>(name, "Name", "Scenario.Name cannot be null");
        this.Name = name;
              RequireNonNull<string>(description, "Description", "Scenario.Description cannot be null");
        this.Description = description;
              RequireNonNull<List<Step>>(steps, "Steps", "Scenario.Steps cannot be null");
        this.Steps = steps == null ? new List<Step>() : new List<Step>(steps);
              RequireNonNull<List<Examples>>(examples, "Examples", "Scenario.Examples cannot be null");
        this.Examples = examples == null ? new List<Examples>() : new List<Examples>(examples);
              RequireNonNull<string>(id, "Id", "Scenario.Id cannot be null");
        this.Id = id;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Scenario that = (Scenario) o;
        return 
            Location.Equals(that.Location) &&         
            Tags.Equals(that.Tags) &&         
            Keyword.Equals(that.Keyword) &&         
            Name.Equals(that.Name) &&         
            Description.Equals(that.Description) &&         
            Steps.Equals(that.Steps) &&         
            Examples.Equals(that.Examples) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Tags != null)
          hash = hash * 31 + Tags.GetHashCode();
        if (Keyword != null)
          hash = hash * 31 + Keyword.GetHashCode();
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (Description != null)
          hash = hash * 31 + Description.GetHashCode();
        if (Steps != null)
          hash = hash * 31 + Steps.GetHashCode();
        if (Examples != null)
          hash = hash * 31 + Examples.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Scenario{" +
            "location=" + Location +
            ", tags=" + Tags +
            ", keyword=" + Keyword +
            ", name=" + Name +
            ", description=" + Description +
            ", steps=" + Steps +
            ", examples=" + Examples +
            ", id=" + Id +
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
