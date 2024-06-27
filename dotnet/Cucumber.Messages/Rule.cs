using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Rule message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class Rule {
    /**
     * The location of the `Rule` keyword
     */
    public Location Location { get; private set; }
    /**
     * All the tags placed above the `Rule` keyword
     */
    public List<Tag> Tags { get; private set; }
    public string Keyword { get; private set; }
    public string Name { get; private set; }
    public string Description { get; private set; }
    public List<RuleChild> Children { get; private set; }
    public string Id { get; private set; }

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
        this.Location = location;
        this.Tags = tags;
        this.Keyword = keyword;
        this.Name = name;
        this.Description = description;
        this.Children = children;
        this.Id = id;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Rule that = (Rule) o;
        return 
            Location.Equals(that.Location) &&         
            Tags.Equals(that.Tags) &&         
            Keyword.Equals(that.Keyword) &&         
            Name.Equals(that.Name) &&         
            Description.Equals(that.Description) &&         
            Children.Equals(that.Children) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Tags.GetHashCode();
        hash = hash * 31 + Keyword.GetHashCode();
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + Description.GetHashCode();
        hash = hash * 31 + Children.GetHashCode();
        hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "Rule{" +
            "location=" + Location +
            ", tags=" + Tags +
            ", keyword=" + Keyword +
            ", name=" + Name +
            ", description=" + Description +
            ", children=" + Children +
            ", id=" + Id +
            '}';
    }
}
