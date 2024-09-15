
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleStep message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * An executable step
 */

public sealed record PickleStep 
{
    public PickleStepArgument? Argument { get; }
    /**
     * References the IDs of the source of the step. For Gherkin, this can be
     * the ID of a Step, and possibly also the ID of a TableRow
     */
    public List<string> AstNodeIds { get; }
    /**
     * A unique ID for the PickleStep
     */
    public string Id { get; }
    /**
     * The context in which the step was specified: context (Given), action (When) or outcome (Then).
     *
     * Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
     */
    public PickleStepType? Type { get; }
    public string Text { get; }


    public PickleStep(
        PickleStepArgument? argument,
        List<string> astNodeIds,
        string id,
        PickleStepType? type,
        string text
    ) 
    {
        this.Argument = argument;
        this.AstNodeIds = astNodeIds ?? throw new ArgumentNullException("AstNodeIds", "PickleStep.AstNodeIds cannot be null");
        this.Id = id ?? throw new ArgumentNullException("Id", "PickleStep.Id cannot be null");
        this.Type = type;
        this.Text = text ?? throw new ArgumentNullException("Text", "PickleStep.Text cannot be null");
    }
}
