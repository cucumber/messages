
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

public sealed record StepMatchArgument 
{
    /**
     * Represents the outermost capture group of an argument. This message closely matches the
     * `Group` class in the `cucumber-expressions` library.
     */
    public Group Group { get; }
    public string? ParameterTypeName { get; }


    public StepMatchArgument(
        Group group,
        string? parameterTypeName
    ) 
    {
        this.Group = group ?? throw new ArgumentNullException("Group", "StepMatchArgument.Group cannot be null");
        this.ParameterTypeName = parameterTypeName;
    }
}
