using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the FeatureChild message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A child node of a `Feature` node
 */

public sealed class FeatureChild 
{
    public Rule Rule { get; private set; }
    public Background Background { get; private set; }
    public Scenario Scenario { get; private set; }


    public static FeatureChild Create(Rule rule) 
    {
        return new FeatureChild(
            Require<Rule>(rule, "Rule", "FeatureChild.Rule cannot be null"),
            null,
            null
        );
    }

    public static FeatureChild Create(Background background) 
    {
        return new FeatureChild(
            null,
            Require<Background>(background, "Background", "FeatureChild.Background cannot be null"),
            null
        );
    }

    public static FeatureChild Create(Scenario scenario) 
    {
        return new FeatureChild(
            null,
            null,
            Require<Scenario>(scenario, "Scenario", "FeatureChild.Scenario cannot be null")
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

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        FeatureChild that = (FeatureChild) o;
        return 
            Object.Equals(Rule, that.Rule) &&         
            Object.Equals(Background, that.Background) &&         
            Object.Equals(Scenario, that.Scenario);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Rule != null)
          hash = hash * 31 + Rule.GetHashCode();
        if (Background != null)
          hash = hash * 31 + Background.GetHashCode();
        if (Scenario != null)
          hash = hash * 31 + Scenario.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "FeatureChild{" +
            "rule=" + Rule +
            ", background=" + Background +
            ", scenario=" + Scenario +
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
