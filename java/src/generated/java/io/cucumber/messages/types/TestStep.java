package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the TestStep message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A `TestStep` is derived from either a `PickleStep` combined with a `StepDefinition`, or from a `Hook`.
 * <p>
 * When derived from a PickleStep:
 * * For `UNDEFINED` steps `stepDefinitionIds` and `stepMatchArgumentsLists` will be empty.
 * * For `AMBIGUOUS` steps, there will be multiple entries in `stepDefinitionIds` and `stepMatchArgumentsLists`. The first entry in the stepMatchArgumentsLists holds the list of arguments for the first matching step definition, the second entry for the second, etc
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class TestStep {
    private final @Nullable String hookId;
    private final String id;
    private final @Nullable String pickleStepId;
    private final @Nullable List<String> stepDefinitionIds;
    private final @Nullable List<StepMatchArgumentsList> stepMatchArgumentsLists;

    public TestStep(
        @Nullable String hookId,
        String id,
        @Nullable String pickleStepId,
        @Nullable List<String> stepDefinitionIds,
        @Nullable List<StepMatchArgumentsList> stepMatchArgumentsLists
    ) {
        this.hookId = hookId;
        this.id = requireNonNull(id, "TestStep.id cannot be null");
        this.pickleStepId = pickleStepId;
        this.stepDefinitionIds = stepDefinitionIds == null ? null : unmodifiableList(new ArrayList<>(stepDefinitionIds));
        this.stepMatchArgumentsLists = stepMatchArgumentsLists == null ? null : unmodifiableList(new ArrayList<>(stepMatchArgumentsLists));
    }

    /**
      * Pointer to the `Hook` (if derived from a Hook)
     */
    public Optional<String> getHookId() {
        return Optional.ofNullable(hookId);
    }

    public String getId() {
        return id;
    }

    /**
      * Pointer to the `PickleStep` (if derived from a `PickleStep`)
     */
    public Optional<String> getPickleStepId() {
        return Optional.ofNullable(pickleStepId);
    }

    /**
      * Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`).
     * <p>
     * Each element represents a matching step definition.
     */
    public Optional<List<String>> getStepDefinitionIds() {
        return Optional.ofNullable(stepDefinitionIds);
    }

    /**
      * A list of list of StepMatchArgument (if derived from a `PickleStep`).
     * <p>
     * Each element represents the arguments for a matching step definition.
     */
    public Optional<List<StepMatchArgumentsList>> getStepMatchArgumentsLists() {
        return Optional.ofNullable(stepMatchArgumentsLists);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestStep that = (TestStep) o;
        return 
            Objects.equals(hookId, that.hookId) &&         
            id.equals(that.id) &&         
            Objects.equals(pickleStepId, that.pickleStepId) &&         
            Objects.equals(stepDefinitionIds, that.stepDefinitionIds) &&         
            Objects.equals(stepMatchArgumentsLists, that.stepMatchArgumentsLists);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            hookId,
            id,
            pickleStepId,
            stepDefinitionIds,
            stepMatchArgumentsLists
        );
    }

    @Override
    public String toString() {
        return "TestStep{" +
            "hookId=" + hookId +
            ", id=" + id +
            ", pickleStepId=" + pickleStepId +
            ", stepDefinitionIds=" + stepDefinitionIds +
            ", stepMatchArgumentsLists=" + stepMatchArgumentsLists +
            '}';
    }
}
