using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the FeatureChild message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A child node of a `Feature` node
 */
// Generated code
public sealed class FeatureChild {
    public Rule? Rule { get; private set; }
    public Background? Background { get; private set; }
    public Scenario? Scenario { get; private set; }

    public static FeatureChild Create(Rule rule) {
        return new FeatureChild(
            rule,
            null,
            null
        );
    }

    public static FeatureChild Create(Background background) {
        return new FeatureChild(
            null,
            background,
            null
        );
    }

    public static FeatureChild Create(Scenario scenario) {
        return new FeatureChild(
            null,
            null,
            scenario
        );
    }

    public FeatureChild(
        Rule rule,
        Background background,
        Scenario scenario
    ) 
    {
        this.Rule = rule;
        this.Background = background;
        this.Scenario = scenario;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        FeatureChild that = (FeatureChild) o;
        return 
            Object.Equals(Rule, that.Rule) &&         
            Object.Equals(Background, that.Background) &&         
            Object.Equals(Scenario, that.Scenario);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Rule?.GetHashCode()?? 0;
        hash = hash * 31 + Background?.GetHashCode()?? 0;
        hash = hash * 31 + Scenario?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "FeatureChild{" +
            "rule=" + Rule +
            ", background=" + Background +
            ", scenario=" + Scenario +
            '}';
    }
}
