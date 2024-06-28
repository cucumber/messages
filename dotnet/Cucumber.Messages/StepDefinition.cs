using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the StepDefinition message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class StepDefinition 
{
    public string Id { get; private set; }
    public StepDefinitionPattern Pattern { get; private set; }
    public SourceReference SourceReference { get; private set; }


    public StepDefinition(
        string id,
        StepDefinitionPattern pattern,
        SourceReference sourceReference
    ) 
    {
              RequireNonNull<string>(id, "Id", "StepDefinition.Id cannot be null");
        this.Id = id;
              RequireNonNull<StepDefinitionPattern>(pattern, "Pattern", "StepDefinition.Pattern cannot be null");
        this.Pattern = pattern;
              RequireNonNull<SourceReference>(sourceReference, "SourceReference", "StepDefinition.SourceReference cannot be null");
        this.SourceReference = sourceReference;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        StepDefinition that = (StepDefinition) o;
        return 
            Id.Equals(that.Id) &&         
            Pattern.Equals(that.Pattern) &&         
            SourceReference.Equals(that.SourceReference);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (Pattern != null)
          hash = hash * 31 + Pattern.GetHashCode();
        if (SourceReference != null)
          hash = hash * 31 + SourceReference.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "StepDefinition{" +
            "id=" + Id +
            ", pattern=" + Pattern +
            ", sourceReference=" + SourceReference +
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
