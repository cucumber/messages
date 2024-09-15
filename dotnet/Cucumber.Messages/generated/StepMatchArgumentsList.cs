
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

public sealed record StepMatchArgumentsList 
{
    public List<StepMatchArgument> StepMatchArguments { get; }


    public StepMatchArgumentsList(
        List<StepMatchArgument> stepMatchArguments
    ) 
    {
        this.StepMatchArguments = stepMatchArguments ?? throw new ArgumentNullException("StepMatchArguments", "StepMatchArgumentsList.StepMatchArguments cannot be null");
    }
}
