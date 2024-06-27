using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the StepDefinitionPattern message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class StepDefinitionPattern {
    public string Source { get; private set; }
    public StepDefinitionPatternType Type { get; private set; }

    public StepDefinitionPattern(
        string source,
        StepDefinitionPatternType type
    ) 
    {
        this.Source = source;
        this.Type = type;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        StepDefinitionPattern that = (StepDefinitionPattern) o;
        return 
            Source.Equals(that.Source) &&         
            Type.Equals(that.Type);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Source.GetHashCode();
        hash = hash * 31 + Type.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "StepDefinitionPattern{" +
            "source=" + Source +
            ", type=" + Type +
            '}';
    }
}
