using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Background message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class Background 
{
    /**
     * The location of the `Background` keyword
     */
    public Location Location { get; private set; }
    public string Keyword { get; private set; }
    public string Name { get; private set; }
    public string Description { get; private set; }
    public List<Step> Steps { get; private set; }
    public string Id { get; private set; }


    public Background(
        Location location,
        string keyword,
        string name,
        string description,
        List<Step> steps,
        string id
    ) 
    {
              RequireNonNull<Location>(location, "Location", "Background.Location cannot be null");
        this.Location = location;
              RequireNonNull<string>(keyword, "Keyword", "Background.Keyword cannot be null");
        this.Keyword = keyword;
              RequireNonNull<string>(name, "Name", "Background.Name cannot be null");
        this.Name = name;
              RequireNonNull<string>(description, "Description", "Background.Description cannot be null");
        this.Description = description;
              RequireNonNull<List<Step>>(steps, "Steps", "Background.Steps cannot be null");
        this.Steps = steps == null ? new List<Step>() : new List<Step>(steps);
              RequireNonNull<string>(id, "Id", "Background.Id cannot be null");
        this.Id = id;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Background that = (Background) o;
        return 
            Location.Equals(that.Location) &&         
            Keyword.Equals(that.Keyword) &&         
            Name.Equals(that.Name) &&         
            Description.Equals(that.Description) &&         
            Steps.Equals(that.Steps) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Keyword != null)
          hash = hash * 31 + Keyword.GetHashCode();
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (Description != null)
          hash = hash * 31 + Description.GetHashCode();
        if (Steps != null)
          hash = hash * 31 + Steps.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Background{" +
            "location=" + Location +
            ", keyword=" + Keyword +
            ", name=" + Name +
            ", description=" + Description +
            ", steps=" + Steps +
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
