package io.cucumber.messages;

import io.cucumber.messages.types.Duration;

import java.util.Comparator;

/**
 * Orders durations by their natural order.
 */
public final class DurationComparator implements Comparator<Duration> {
    @Override
    public int compare(Duration a, Duration b) {
        int c = a.getSeconds().compareTo(b.getSeconds());
        if (c != 0) {
            return c;
        }
        return a.getNanos().compareTo(b.getNanos());
    }
}
