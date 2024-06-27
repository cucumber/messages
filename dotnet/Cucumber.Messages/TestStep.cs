using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TestStep message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A `TestStep` is derived from either a `PickleStep`
 * combined with a `StepDefinition`, or from a `Hook`.
 */
// Generated code
public sealed class TestStep {
    /**
     * Pointer to the `Hook` (if derived from a Hook)
     */
    public string? HookId { get; private set; }
    public string Id { get; private set; }
    /**
     * Pointer to the `PickleStep` (if derived from a `PickleStep`)
     */
    public string? PickleStepId { get; private set; }
    /**
     * Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`)
     */
    public List<string>? StepDefinitionIds { get; private set; }
    /**
     * A list of list of StepMatchArgument (if derived from a `PickleStep`).
     * Each element represents a matching step definition. A size of 0 means `UNDEFINED`,
     * and a size of 2+ means `AMBIGUOUS`
     */
    public List<StepMatchArgumentsList>? StepMatchArgumentsLists { get; private set; }

    public TestStep(
        string hookId,
        string id,
        string pickleStepId,
        List<string> stepDefinitionIds,
        List<StepMatchArgumentsList> stepMatchArgumentsLists
    ) 
    {
        this.HookId = hookId;
        this.Id = id;
        this.PickleStepId = pickleStepId;
        this.StepDefinitionIds = stepDefinitionIds;
        this.StepMatchArgumentsLists = stepMatchArgumentsLists;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestStep that = (TestStep) o;
        return 
            Object.Equals(HookId, that.HookId) &&         
            Id.Equals(that.Id) &&         
            Object.Equals(PickleStepId, that.PickleStepId) &&         
            Object.Equals(StepDefinitionIds, that.StepDefinitionIds) &&         
            Object.Equals(StepMatchArgumentsLists, that.StepMatchArgumentsLists);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + HookId?.GetHashCode()?? 0;
        hash = hash * 31 + Id.GetHashCode();
        hash = hash * 31 + PickleStepId?.GetHashCode()?? 0;
        hash = hash * 31 + StepDefinitionIds?.GetHashCode()?? 0;
        hash = hash * 31 + StepMatchArgumentsLists?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "TestStep{" +
            "hookId=" + HookId +
            ", id=" + Id +
            ", pickleStepId=" + PickleStepId +
            ", stepDefinitionIds=" + StepDefinitionIds +
            ", stepMatchArgumentsLists=" + StepMatchArgumentsLists +
            '}';
    }
}
