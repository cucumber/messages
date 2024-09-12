using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the StepMatchArgumentsList message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class StepMatchArgumentsList 
{
    public List<StepMatchArgument> StepMatchArguments { get; private set; }


    public StepMatchArgumentsList(
        List<StepMatchArgument> stepMatchArguments
    ) 
    {
        RequireNonNull<List<StepMatchArgument>>(stepMatchArguments, "StepMatchArguments", "StepMatchArgumentsList.StepMatchArguments cannot be null");
        this.StepMatchArguments = new List<StepMatchArgument>(stepMatchArguments);        
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        StepMatchArgumentsList that = (StepMatchArgumentsList) o;
        return 
            StepMatchArguments.Equals(that.StepMatchArguments);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (StepMatchArguments != null)
          hash = hash * 31 + StepMatchArguments.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "StepMatchArgumentsList{" +
            "stepMatchArguments=" + StepMatchArguments +
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
