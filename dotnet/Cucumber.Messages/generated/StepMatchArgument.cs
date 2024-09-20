using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the StepMatchArgument message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Represents a single argument extracted from a step match and passed to a step definition.
 * This is used for the following purposes:
 * - Construct an argument to pass to a step definition (possibly through a parameter type transform)
 * - Highlight the matched parameter in rich formatters such as the HTML formatter
 *
 * This message closely matches the `Argument` class in the `cucumber-expressions` library.
 */

public sealed class StepMatchArgument 
{
    /**
     * Represents the outermost capture group of an argument. This message closely matches the
     * `Group` class in the `cucumber-expressions` library.
     */
    public Group Group { get; private set; }
    public string ParameterTypeName { get; private set; }


    public StepMatchArgument(
        Group group,
        string parameterTypeName
    ) 
    {
        RequireNonNull<Group>(group, "Group", "StepMatchArgument.Group cannot be null");
        this.Group = group;
        this.ParameterTypeName = parameterTypeName;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        StepMatchArgument that = (StepMatchArgument) o;
        return 
            Group.Equals(that.Group) &&         
            Object.Equals(ParameterTypeName, that.ParameterTypeName);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Group != null)
          hash = hash * 31 + Group.GetHashCode();
        if (ParameterTypeName != null)
          hash = hash * 31 + ParameterTypeName.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "StepMatchArgument{" +
            "group=" + Group +
            ", parameterTypeName=" + ParameterTypeName +
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
