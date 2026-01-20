package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the PickleStep message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * An executable step
 */
// Generated code
@SuppressWarnings("unused")
public final class PickleStep {
    private final PickleStepArgument argument;
    private final java.util.List<String> astNodeIds;
    private final String id;
    private final PickleStepType type;
    private final String text;

    public PickleStep(
        PickleStepArgument argument,
        java.util.List<String> astNodeIds,
        String id,
        PickleStepType type,
        String text
    ) {
        this.argument = argument;
        this.astNodeIds = unmodifiableList(new ArrayList<>(requireNonNull(astNodeIds, "PickleStep.astNodeIds cannot be null")));
        this.id = requireNonNull(id, "PickleStep.id cannot be null");
        this.type = type;
        this.text = requireNonNull(text, "PickleStep.text cannot be null");
    }

    public Optional<PickleStepArgument> getArgument() {
        return Optional.ofNullable(argument);
    }

    /**
     * References the IDs of the source of the step. For Gherkin, this can be
     * the ID of a Step, and possibly also the ID of a TableRow
     */
    public java.util.List<String> getAstNodeIds() {
        return astNodeIds;
    }

    /**
     * A unique ID for the PickleStep
     */
    public String getId() {
        return id;
    }

    /**
     * The context in which the step was specified: context (Given), action (When) or outcome (Then).
     * <p>
     * Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
     */
    public Optional<PickleStepType> getType() {
        return Optional.ofNullable(type);
    }

    public String getText() {
        return text;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        PickleStep that = (PickleStep) o;
        return 
            Objects.equals(argument, that.argument) &&         
            astNodeIds.equals(that.astNodeIds) &&         
            id.equals(that.id) &&         
            Objects.equals(type, that.type) &&         
            text.equals(that.text);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            argument,
            astNodeIds,
            id,
            type,
            text
        );
    }

    @Override
    public String toString() {
        return "PickleStep{" +
            "argument=" + argument +
            ", astNodeIds=" + astNodeIds +
            ", id=" + id +
            ", type=" + type +
            ", text=" + text +
            '}';
    }
}
