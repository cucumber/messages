using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the StepDefinition message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class StepDefinition {
    public string Id { get; private set; }
    public StepDefinitionPattern Pattern { get; private set; }
    public SourceReference SourceReference { get; private set; }

    public StepDefinition(
        string id,
        StepDefinitionPattern pattern,
        SourceReference sourceReference
    ) 
    {
        this.Id = id;
        this.Pattern = pattern;
        this.SourceReference = sourceReference;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        StepDefinition that = (StepDefinition) o;
        return 
            Id.Equals(that.Id) &&         
            Pattern.Equals(that.Pattern) &&         
            SourceReference.Equals(that.SourceReference);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Id.GetHashCode();
        hash = hash * 31 + Pattern.GetHashCode();
        hash = hash * 31 + SourceReference.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "StepDefinition{" +
            "id=" + Id +
            ", pattern=" + Pattern +
            ", sourceReference=" + SourceReference +
            '}';
    }
}
