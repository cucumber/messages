package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the TableCell message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A cell in a `TableRow`
 */
// Generated code
@SuppressWarnings("unused")
public final class TableCell {
    private final Location location;
    private final String value;

    public TableCell(
        Location location,
        String value
    ) {
        this.location = requireNonNull(location, "TableCell.location cannot be null");
        this.value = requireNonNull(value, "TableCell.value cannot be null");
    }

    /**
     * The location of the cell
     */
    public Location getLocation() {
        return location;
    }

    /**
     * The value of the cell
     */
    public String getValue() {
        return value;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TableCell that = (TableCell) o;
        return 
            location.equals(that.location) &&         
            value.equals(that.value);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            location,
            value
        );
    }

    @Override
    public String toString() {
        return "TableCell{" +
            "location=" + location +
            ", value=" + value +
            '}';
    }
}
