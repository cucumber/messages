package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the StepMatchArgumentsList message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class StepMatchArgumentsList {
    private final List<StepMatchArgument> stepMatchArguments;

    public StepMatchArgumentsList(
        List<StepMatchArgument> stepMatchArguments
    ) {
        this.stepMatchArguments = List.copyOf(requireNonNull(stepMatchArguments, "StepMatchArgumentsList.stepMatchArguments cannot be null"));
    }

    public List<StepMatchArgument> getStepMatchArguments() {
        return stepMatchArguments;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        StepMatchArgumentsList that = (StepMatchArgumentsList) o;
        return 
            stepMatchArguments.equals(that.stepMatchArguments);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            stepMatchArguments
        );
    }

    @Override
    public String toString() {
        return "StepMatchArgumentsList{" +
            "stepMatchArguments=" + stepMatchArguments +
            '}';
    }
}
