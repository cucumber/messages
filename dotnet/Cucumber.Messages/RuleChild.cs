using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the RuleChild message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A child node of a `Rule` node
 */
// Generated code
public sealed class RuleChild {
    public Background? Background { get; private set; }
    public Scenario? Scenario { get; private set; }

    public static RuleChild Create(Background background) {
        return new RuleChild(
            background,
            null
        );
    }

    public static RuleChild Create(Scenario scenario) {
        return new RuleChild(
            null,
            scenario
        );
    }

    public RuleChild(
        Background background,
        Scenario scenario
    ) 
    {
        this.Background = background;
        this.Scenario = scenario;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        RuleChild that = (RuleChild) o;
        return 
            Object.Equals(Background, that.Background) &&         
            Object.Equals(Scenario, that.Scenario);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Background?.GetHashCode()?? 0;
        hash = hash * 31 + Scenario?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "RuleChild{" +
            "background=" + Background +
            ", scenario=" + Scenario +
            '}';
    }
}
