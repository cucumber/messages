package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Timestamp message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class Timestamp {
    private final Long seconds;
    private final Integer nanos;

    public Timestamp(
        Long seconds,
        Integer nanos
    ) {
        this.seconds = requireNonNull(seconds, "Timestamp.seconds cannot be null");
        this.nanos = requireNonNull(nanos, "Timestamp.nanos cannot be null");
    }

    /**
     * Represents seconds of UTC time since Unix epoch
     * 1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
     * 9999-12-31T23:59:59Z inclusive.
     */
    public Long getSeconds() {
        return seconds;
    }

    /**
     * Non-negative fractions of a second at nanosecond resolution. Negative
     * second values with fractions must still have non-negative nanos values
     * that count forward in time. Must be from 0 to 999,999,999
     * inclusive.
     */
    public Integer getNanos() {
        return nanos;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Timestamp that = (Timestamp) o;
        return 
            seconds.equals(that.seconds) &&         
            nanos.equals(that.nanos);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            seconds,
            nanos
        );
    }

    @Override
    public String toString() {
        return "Timestamp{" +
            "seconds=" + seconds +
            ", nanos=" + nanos +
            '}';
    }
}
