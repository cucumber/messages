package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the TableRow message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A row in a table
 */
// Generated code
@SuppressWarnings("unused")
public final class TableRow {
    private final Location location;
    private final java.util.List<TableCell> cells;
    private final String id;

    public TableRow(
        Location location,
        java.util.List<TableCell> cells,
        String id
    ) {
        this.location = requireNonNull(location, "TableRow.location cannot be null");
        this.cells = unmodifiableList(new ArrayList<>(requireNonNull(cells, "TableRow.cells cannot be null")));
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
    public java.util.List<TableCell> getCells() {
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
