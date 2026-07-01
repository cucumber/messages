package io.cucumber.messages.types;

import io.cucumber.messages.Property;
import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the PickleTable message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class PickleTable {
    private final @Nullable Long argumentIndex;
    private final List<PickleTableRow> rows;

    public PickleTable(
        @Nullable @Property("argumentIndex") Long argumentIndex,
        @Property("rows") List<PickleTableRow> rows
    ) {
        this.argumentIndex = argumentIndex;
        this.rows = List.copyOf(requireNonNull(rows, "PickleTable.rows cannot be null"));
    }

    public Optional<Long> getArgumentIndex() {
        return Optional.ofNullable(argumentIndex);
    }

    public List<PickleTableRow> getRows() {
        return rows;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        PickleTable that = (PickleTable) o;
        return 
            Objects.equals(argumentIndex, that.argumentIndex) &&         
            rows.equals(that.rows);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            argumentIndex,
            rows
        );
    }

    @Override
    public String toString() {
        return "PickleTable{" +
            "argumentIndex=" + argumentIndex +
            ", rows=" + rows +
            '}';
    }
}
