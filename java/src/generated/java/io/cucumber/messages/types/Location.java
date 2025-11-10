package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Location message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * Points to a line and a column in a text file
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Location {
    private final Integer line;
    private final @Nullable Integer column;

    public Location(
        Integer line,
        @Nullable Integer column
    ) {
        this.line = requireNonNull(line, "Location.line cannot be null");
        this.column = column;
    }

    public Integer getLine() {
        return line;
    }

    public Optional<Integer> getColumn() {
        return Optional.ofNullable(column);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Location that = (Location) o;
        return 
            line.equals(that.line) &&         
            Objects.equals(column, that.column);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            line,
            column
        );
    }

    @Override
    public String toString() {
        return "Location{" +
            "line=" + line +
            ", column=" + column +
            '}';
    }
}
