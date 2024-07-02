using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Tag message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A tag
 */

public sealed class Tag 
{
    /**
     * Location of the tag
     */
    public Location Location { get; private set; }
    /**
     * The name of the tag (including the leading `@`)
     */
    public string Name { get; private set; }
    /**
     * Unique ID to be able to reference the Tag from PickleTag
     */
    public string Id { get; private set; }


    public Tag(
        Location location,
        string name,
        string id
    ) 
    {
              RequireNonNull<Location>(location, "Location", "Tag.Location cannot be null");
        this.Location = location;
              RequireNonNull<string>(name, "Name", "Tag.Name cannot be null");
        this.Name = name;
              RequireNonNull<string>(id, "Id", "Tag.Id cannot be null");
        this.Id = id;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Tag that = (Tag) o;
        return 
            Location.Equals(that.Location) &&         
            Name.Equals(that.Name) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Tag{" +
            "location=" + Location +
            ", name=" + Name +
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
