package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the DataTable message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class DataTable {
    private final Location location;
    private final List<TableRow> rows;

    public DataTable(
        Location location,
        List<TableRow> rows
    ) {
        this.location = requireNonNull(location, "DataTable.location cannot be null");
        this.rows = List.copyOf(requireNonNull(rows, "DataTable.rows cannot be null"));
    }

    public Location getLocation() {
        return location;
    }

    public List<TableRow> getRows() {
        return rows;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        DataTable that = (DataTable) o;
        return 
            location.equals(that.location) &&         
            rows.equals(that.rows);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            location,
            rows
        );
    }

    @Override
    public String toString() {
        return "DataTable{" +
            "location=" + location +
            ", rows=" + rows +
            '}';
    }
}
