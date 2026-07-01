package io.cucumber.messages.types;

import io.cucumber.messages.Property;
import org.jspecify.annotations.Nullable;

import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the PickleStepArgument message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * An optional argument
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class PickleStepArgument {

    private final OneOf oneOf;

    public static PickleStepArgument of(PickleDocString docString) {
        return new PickleStepArgument(
            requireNonNull(docString, "PickleStepArgument.docString cannot be null"),
            null
        );
    }

    public static PickleStepArgument of(PickleTable dataTable) {
        return new PickleStepArgument(
            null,
            requireNonNull(dataTable, "PickleStepArgument.dataTable cannot be null")
        );
    }

    public PickleStepArgument(
        @Nullable @Property("docString") PickleDocString docString,
        @Nullable @Property("dataTable") PickleTable dataTable
    ) {
        this.oneOf = OneOf.of(
            "PickleStepArgument",
            "docString", docString,
            "dataTable", dataTable
        );
    }

    public Optional<PickleDocString> getDocString() {
        return oneOf.get("docString");
    }

    public Optional<PickleTable> getDataTable() {
        return oneOf.get("dataTable");
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        PickleStepArgument that = (PickleStepArgument) o;
        return Objects.equals(oneOf, that.oneOf);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(oneOf);
    }

    @Override
    public String toString() {
        return "PickleStepArgument{" + oneOf + "}";
    }
}
