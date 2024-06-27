using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Background message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class Background {
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
        this.Location = location;
        this.Keyword = keyword;
        this.Name = name;
        this.Description = description;
        this.Steps = steps;
        this.Id = id;
    }

    public override boolean Equals(Object o) {
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

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Keyword.GetHashCode();
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + Description.GetHashCode();
        hash = hash * 31 + Steps.GetHashCode();
        hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "Background{" +
            "location=" + Location +
            ", keyword=" + Keyword +
            ", name=" + Name +
            ", description=" + Description +
            ", steps=" + Steps +
            ", id=" + Id +
            '}';
    }
}
