
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the RuleChild message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A child node of a `Rule` node
 */

public sealed record RuleChild 
{
    public Background? Background { get; }
    public Scenario? Scenario { get; }


    public static RuleChild Create(Background background) 
    {
        return new RuleChild(
            background ?? throw new ArgumentNullException("Background", "RuleChild.Background cannot be null"),
            null
        );
    }

    public static RuleChild Create(Scenario scenario) 
    {
        return new RuleChild(
            null,
            scenario ?? throw new ArgumentNullException("Scenario", "RuleChild.Scenario cannot be null")
        );
    }

    public RuleChild(
        Background? background,
        Scenario? scenario
    ) 
    {
        Background = background;
        Scenario = scenario;
    }
}
