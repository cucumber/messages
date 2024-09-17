
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestStep message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A `TestStep` is derived from either a `PickleStep`
 * combined with a `StepDefinition`, or from a `Hook`.
 */

public sealed record TestStep 
{
    /**
     * Pointer to the `Hook` (if derived from a Hook)
     */
    public string? HookId { get; }
    public string Id { get; }
    /**
     * Pointer to the `PickleStep` (if derived from a `PickleStep`)
     */
    public string? PickleStepId { get; }
    /**
     * Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`)
     */
    public ImmutableArray<string>? StepDefinitionIds { get; }
    /**
     * A list of list of StepMatchArgument (if derived from a `PickleStep`).
     * Each element represents a matching step definition. A size of 0 means `UNDEFINED`,
     * and a size of 2+ means `AMBIGUOUS`
     */
    public ImmutableArray<StepMatchArgumentsList>? StepMatchArgumentsLists { get; }


    public TestStep(
        string? hookId,
        string id,
        string? pickleStepId,
        ImmutableArray<string>? stepDefinitionIds,
        ImmutableArray<StepMatchArgumentsList>? stepMatchArgumentsLists
    ) 
    {
        HookId = hookId;
        Id = id ?? throw new ArgumentNullException("Id", "TestStep.Id cannot be null");
        PickleStepId = pickleStepId;
        StepDefinitionIds = stepDefinitionIds;
        StepMatchArgumentsLists = stepMatchArgumentsLists;
    }
}
