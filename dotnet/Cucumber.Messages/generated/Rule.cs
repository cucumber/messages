using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Rule message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class Rule 
{
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
        RequireNonNull<Location>(location, "Location", "Rule.Location cannot be null");
        this.Location = location;
        RequireNonNull<List<Tag>>(tags, "Tags", "Rule.Tags cannot be null");
        this.Tags = new List<Tag>(tags);        
        RequireNonNull<string>(keyword, "Keyword", "Rule.Keyword cannot be null");
        this.Keyword = keyword;
        RequireNonNull<string>(name, "Name", "Rule.Name cannot be null");
        this.Name = name;
        RequireNonNull<string>(description, "Description", "Rule.Description cannot be null");
        this.Description = description;
        RequireNonNull<List<RuleChild>>(children, "Children", "Rule.Children cannot be null");
        this.Children = new List<RuleChild>(children);        
        RequireNonNull<string>(id, "Id", "Rule.Id cannot be null");
        this.Id = id;
    }

    public override bool Equals(Object o) 
    {
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
        if (Children != null)
          hash = hash * 31 + Children.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
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
