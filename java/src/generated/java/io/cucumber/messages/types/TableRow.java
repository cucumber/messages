package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the TableRow message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A row in a table
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class TableRow {
    private final Location location;
    private final List<TableCell> cells;
    private final String id;

    public TableRow(
        Location location,
        List<TableCell> cells,
        String id
    ) {
        this.location = requireNonNull(location, "TableRow.location cannot be null");
        this.cells = List.copyOf(requireNonNull(cells, "TableRow.cells cannot be null"));
        this.id = requireNonNull(id, "TableRow.id cannot be null");
    }

    /**
     * The location of the first cell in the row
     */
    public Location getLocation() {
        return location;
    }

    /**
     * Cells in the row
     */
    public List<TableCell> getCells() {
        return cells;
    }

    public String getId() {
        return id;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TableRow that = (TableRow) o;
        return 
            location.equals(that.location) &&         
            cells.equals(that.cells) &&         
            id.equals(that.id);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            location,
            cells,
            id
        );
    }

    @Override
    public String toString() {
        return "TableRow{" +
            "location=" + location +
            ", cells=" + cells +
            ", id=" + id +
            '}';
    }
}
