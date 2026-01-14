using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Group message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class Group 
{
    public List<Group> Children { get; private set; }
    public Nullable<long> Start { get; private set; }
    public string Value { get; private set; }


    public static Group Create(List<Group> children) 
    {
        return new Group(
            Require<List<Group>>(children, "Children", "Group.Children cannot be null"),
            null,
            null
        );
    }

    public static Group Create(long start) 
    {
        return new Group(
            null,
            Require<long>(start, "Start", "Group.Start cannot be null"),
            null
        );
    }

    public static Group Create(string value) 
    {
        return new Group(
            null,
            null,
            Require<string>(value, "Value", "Group.Value cannot be null")
        );
    }

    public Group(
        List<Group> children,
        Nullable<long> start,
        string value
    ) 
    {
        this.Children = children == null ? null : new List<Group>(children);
        this.Start = start;
        this.Value = value;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Group that = (Group) o;
        return 
            Object.Equals(Children, that.Children) &&         
            Object.Equals(Start, that.Start) &&         
            Object.Equals(Value, that.Value);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Children != null)
          hash = hash * 31 + Children.GetHashCode();
        if (Start.HasValue)
          hash = hash * 31 + Start.Value.GetHashCode();
        if (Value != null)
          hash = hash * 31 + Value.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Group{" +
            "children=" + Children +
            (Start.HasValue ? ", start=" + Start.Value : "") +
            ", value=" + Value +
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
