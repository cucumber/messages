package io.cucumber.messages;

import io.cucumber.messages.types.Timestamp;

import java.util.Comparator;

/**
 * Orders timestamps by their natural order.
 */
public final class TimestampComparator implements Comparator<Timestamp> {
    @Override
    public int compare(Timestamp a, Timestamp b) {
        int c = a.getSeconds().compareTo(b.getSeconds());
        if (c != 0) {
            return c;
        }
        return a.getNanos().compareTo(b.getNanos());
    }
}
