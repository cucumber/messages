
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

public sealed record FeatureChild 
{
    public Rule? Rule { get; }
    public Background? Background { get; }
    public Scenario? Scenario { get; }


    public static FeatureChild Create(Rule rule) 
    {
        return new FeatureChild(
            rule ?? throw new ArgumentNullException("Rule", "FeatureChild.Rule cannot be null"),
            null,
            null
        );
    }

    public static FeatureChild Create(Background background) 
    {
        return new FeatureChild(
            null,
            background ?? throw new ArgumentNullException("Background", "FeatureChild.Background cannot be null"),
            null
        );
    }

    public static FeatureChild Create(Scenario scenario) 
    {
        return new FeatureChild(
            null,
            null,
            scenario ?? throw new ArgumentNullException("Scenario", "FeatureChild.Scenario cannot be null")
        );
    }

    public FeatureChild(
        Rule? rule,
        Background? background,
        Scenario? scenario
    ) 
    {
        this.Rule = rule;
        this.Background = background;
        this.Scenario = scenario;
    }
}
