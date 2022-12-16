package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the StepMatchArgument message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * Represents a single argument extracted from a step match and passed to a step definition.
 * This is used for the following purposes:
 * - Construct an argument to pass to a step definition (possibly through a parameter type transform)
 * - Highlight the matched parameter in rich formatters such as the HTML formatter
 *
 * This message closely matches the `Argument` class in the `cucumber-expressions` library.
 */
// Generated code
@SuppressWarnings("unused")
public final class StepMatchArgument {
    private final Group group;
    private final String parameterTypeName;

    public StepMatchArgument(
        Group group,
        String parameterTypeName
    ) {
        this.group = requireNonNull(group, "StepMatchArgument.group cannot be null");
        this.parameterTypeName = parameterTypeName;
    }

    /**
     * Represents the outermost capture group of an argument. This message closely matches the
     * `Group` class in the `cucumber-expressions` library.
     */
    public Group getGroup() {
        return group;
    }

    public Optional<String> getParameterTypeName() {
        return Optional.ofNullable(parameterTypeName);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        StepMatchArgument that = (StepMatchArgument) o;
        return 
            group.equals(that.group) &&         
            Objects.equals(parameterTypeName, that.parameterTypeName);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            group,
            parameterTypeName
        );
    }

    @Override
    public String toString() {
        return "StepMatchArgument{" +
            "group=" + group +
            ", parameterTypeName=" + parameterTypeName +
            '}';
    }
}
