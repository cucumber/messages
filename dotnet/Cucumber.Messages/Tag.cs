using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Tag message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A tag
 */
// Generated code
public sealed class Tag {
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
        this.Location = location;
        this.Name = name;
        this.Id = id;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Tag that = (Tag) o;
        return 
            Location.Equals(that.Location) &&         
            Name.Equals(that.Name) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "Tag{" +
            "location=" + Location +
            ", name=" + Name +
            ", id=" + Id +
            '}';
    }
}
