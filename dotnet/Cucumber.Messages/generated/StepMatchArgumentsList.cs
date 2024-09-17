
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the StepMatchArgumentsList message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record StepMatchArgumentsList 
{
    public ImmutableArray<StepMatchArgument> StepMatchArguments { get; }


    public StepMatchArgumentsList(
        ImmutableArray<StepMatchArgument> stepMatchArguments
    ) 
    {
        StepMatchArguments = stepMatchArguments;
    }
}
