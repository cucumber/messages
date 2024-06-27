using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the PickleStep message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * An executable step
 */
// Generated code
public sealed class PickleStep {
    public PickleStepArgument? Argument { get; private set; }
    /**
     * References the IDs of the source of the step. For Gherkin, this can be
     * the ID of a Step, and possibly also the ID of a TableRow
     */
    public List<string> AstNodeIds { get; private set; }
    /**
     * A unique ID for the PickleStep
     */
    public string Id { get; private set; }
    /**
     * The context in which the step was specified: context (Given), action (When) or outcome (Then).
     *
     * Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
     */
    public PickleStepType? Type { get; private set; }
    public string Text { get; private set; }

    public PickleStep(
        PickleStepArgument argument,
        List<string> astNodeIds,
        string id,
        PickleStepType type,
        string text
    ) 
    {
        this.Argument = argument;
        this.AstNodeIds = astNodeIds;
        this.Id = id;
        this.Type = type;
        this.Text = text;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleStep that = (PickleStep) o;
        return 
            Object.Equals(Argument, that.Argument) &&         
            AstNodeIds.Equals(that.AstNodeIds) &&         
            Id.Equals(that.Id) &&         
            Object.Equals(Type, that.Type) &&         
            Text.Equals(that.Text);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Argument?.GetHashCode()?? 0;
        hash = hash * 31 + AstNodeIds.GetHashCode();
        hash = hash * 31 + Id.GetHashCode();
        hash = hash * 31 + Type?.GetHashCode()?? 0;
        hash = hash * 31 + Text.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "PickleStep{" +
            "argument=" + Argument +
            ", astNodeIds=" + AstNodeIds +
            ", id=" + Id +
            ", type=" + Type +
            ", text=" + Text +
            '}';
    }
}
