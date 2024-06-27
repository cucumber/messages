using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the StepMatchArgumentsList message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class StepMatchArgumentsList {
    public List<StepMatchArgument> StepMatchArguments { get; private set; }

    public StepMatchArgumentsList(
        List<StepMatchArgument> stepMatchArguments
    ) 
    {
        this.StepMatchArguments = stepMatchArguments;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        StepMatchArgumentsList that = (StepMatchArgumentsList) o;
        return 
            StepMatchArguments.Equals(that.StepMatchArguments);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + StepMatchArguments.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "StepMatchArgumentsList{" +
            "stepMatchArguments=" + StepMatchArguments +
            '}';
    }
}
