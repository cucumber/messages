using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestStep message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A `TestStep` is derived from either a `PickleStep`
 * combined with a `StepDefinition`, or from a `Hook`.
 */

public sealed class TestStep 
{
    /**
     * Pointer to the `Hook` (if derived from a Hook)
     */
    public string HookId { get; private set; }
    public string Id { get; private set; }
    /**
     * Pointer to the `PickleStep` (if derived from a `PickleStep`)
     */
    public string PickleStepId { get; private set; }
    /**
     * Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`)
     */
    public List<string> StepDefinitionIds { get; private set; }
    /**
     * A list of list of StepMatchArgument (if derived from a `PickleStep`).
     * Each element represents a matching step definition. A size of 0 means `UNDEFINED`,
     * and a size of 2+ means `AMBIGUOUS`
     */
    public List<StepMatchArgumentsList> StepMatchArgumentsLists { get; private set; }


    public TestStep(
        string hookId,
        string id,
        string pickleStepId,
        List<string> stepDefinitionIds,
        List<StepMatchArgumentsList> stepMatchArgumentsLists
    ) 
    {
        this.HookId = hookId;
        RequireNonNull<string>(id, "Id", "TestStep.Id cannot be null");
        this.Id = id;
        this.PickleStepId = pickleStepId;
        this.StepDefinitionIds = stepDefinitionIds == null ? null : new List<string>(stepDefinitionIds);
        this.StepMatchArgumentsLists = stepMatchArgumentsLists == null ? null : new List<StepMatchArgumentsList>(stepMatchArgumentsLists);
    }

    public override bool Equals(Object o) 
    {
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

    public override int GetHashCode() 
    {
        int hash = 17;
        if (HookId != null)
          hash = hash * 31 + HookId.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (PickleStepId != null)
          hash = hash * 31 + PickleStepId.GetHashCode();
        if (StepDefinitionIds != null)
          hash = hash * 31 + StepDefinitionIds.GetHashCode();
        if (StepMatchArgumentsLists != null)
          hash = hash * 31 + StepMatchArgumentsLists.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestStep{" +
            "hookId=" + HookId +
            ", id=" + Id +
            ", pickleStepId=" + PickleStepId +
            ", stepDefinitionIds=" + StepDefinitionIds +
            ", stepMatchArgumentsLists=" + StepMatchArgumentsLists +
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
