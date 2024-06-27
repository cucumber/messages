using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

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
// Generated code
public sealed class StepMatchArgument {
    /**
     * Represents the outermost capture group of an argument. This message closely matches the
     * `Group` class in the `cucumber-expressions` library.
     */
    public Group Group { get; private set; }
    public string? ParameterTypeName { get; private set; }

    public StepMatchArgument(
        Group group,
        string parameterTypeName
    ) 
    {
        this.Group = group;
        this.ParameterTypeName = parameterTypeName;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        StepMatchArgument that = (StepMatchArgument) o;
        return 
            Group.Equals(that.Group) &&         
            Object.Equals(ParameterTypeName, that.ParameterTypeName);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Group.GetHashCode();
        hash = hash * 31 + ParameterTypeName?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "StepMatchArgument{" +
            "group=" + Group +
            ", parameterTypeName=" + ParameterTypeName +
            '}';
    }
}
