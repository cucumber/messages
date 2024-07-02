using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the StepDefinitionPattern message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class StepDefinitionPattern 
{
    public string Source { get; private set; }
    public StepDefinitionPatternType Type { get; private set; }


    public StepDefinitionPattern(
        string source,
        StepDefinitionPatternType type
    ) 
    {
              RequireNonNull<string>(source, "Source", "StepDefinitionPattern.Source cannot be null");
        this.Source = source;
              RequireNonNull<StepDefinitionPatternType>(type, "Type", "StepDefinitionPattern.Type cannot be null");
        this.Type = type;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        StepDefinitionPattern that = (StepDefinitionPattern) o;
        return 
            Source.Equals(that.Source) &&         
            Type.Equals(that.Type);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Source != null)
          hash = hash * 31 + Source.GetHashCode();
          hash = hash * 31 + Type.GetHashCode();  
        return hash;
    }

    public override string ToString() 
    {
        return "StepDefinitionPattern{" +
            "source=" + Source +
            ", type=" + Type +
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
