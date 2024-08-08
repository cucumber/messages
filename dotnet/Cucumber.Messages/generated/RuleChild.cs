using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the RuleChild message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A child node of a `Rule` node
 */

public sealed class RuleChild 
{
    public Background Background { get; private set; }
    public Scenario Scenario { get; private set; }


    public static RuleChild Create(Background background) 
    {
        return new RuleChild(
            Require<Background>(background, "Background", "RuleChild.Background cannot be null"),
            null
        );
    }

    public static RuleChild Create(Scenario scenario) 
    {
        return new RuleChild(
            null,
            Require<Scenario>(scenario, "Scenario", "RuleChild.Scenario cannot be null")
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

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        RuleChild that = (RuleChild) o;
        return 
            Object.Equals(Background, that.Background) &&         
            Object.Equals(Scenario, that.Scenario);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Background != null)
          hash = hash * 31 + Background.GetHashCode();
        if (Scenario != null)
          hash = hash * 31 + Scenario.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "RuleChild{" +
            "background=" + Background +
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
