using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Hook message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class Hook 
{
    public string Id { get; private set; }
    public string Name { get; private set; }
    public SourceReference SourceReference { get; private set; }
    public string TagExpression { get; private set; }


    public Hook(
        string id,
        string name,
        SourceReference sourceReference,
        string tagExpression
    ) 
    {
        RequireNonNull<string>(id, "Id", "Hook.Id cannot be null");
        this.Id = id;
        this.Name = name;
        RequireNonNull<SourceReference>(sourceReference, "SourceReference", "Hook.SourceReference cannot be null");
        this.SourceReference = sourceReference;
        this.TagExpression = tagExpression;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Hook that = (Hook) o;
        return 
            Id.Equals(that.Id) &&         
            Object.Equals(Name, that.Name) &&         
            SourceReference.Equals(that.SourceReference) &&         
            Object.Equals(TagExpression, that.TagExpression);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (SourceReference != null)
          hash = hash * 31 + SourceReference.GetHashCode();
        if (TagExpression != null)
          hash = hash * 31 + TagExpression.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Hook{" +
            "id=" + Id +
            ", name=" + Name +
            ", sourceReference=" + SourceReference +
            ", tagExpression=" + TagExpression +
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
