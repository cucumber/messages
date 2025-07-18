package io.cucumber.messages;

import io.cucumber.messages.types.Location;

import java.util.Comparator;

/**
 * Orders locations by their natural order. 
 * <p>
 * Locations on the same line, but with a missing column come before locations
 * with a column.
 */
public final class LocationComparator implements Comparator<Location> {
    @Override
    public int compare(Location a, Location b) {
        int c = a.getLine().compareTo(b.getLine());
        if (c != 0) {
            return c;
        }
        Long aColumn = a.getColumn().orElse(null);
        Long bColumn = b.getColumn().orElse(null);
        // null first.
        return aColumn == null ? bColumn == null ? 0 : -1 : bColumn == null ? 1 : aColumn.compareTo(bColumn);
    }
}
