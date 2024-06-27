using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Timestamp message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class Timestamp {
    /**
     * Represents seconds of UTC time since Unix epoch
     * 1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
     * 9999-12-31T23:59:59Z inclusive.
     */
    public long Seconds { get; private set; }
    /**
     * Non-negative fractions of a second at nanosecond resolution. Negative
     * second values with fractions must still have non-negative nanos values
     * that count forward in time. Must be from 0 to 999,999,999
     * inclusive.
     */
    public long Nanos { get; private set; }

    public Timestamp(
        long seconds,
        long nanos
    ) 
    {
        this.Seconds = seconds;
        this.Nanos = nanos;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Timestamp that = (Timestamp) o;
        return 
            Seconds.Equals(that.Seconds) &&         
            Nanos.Equals(that.Nanos);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Seconds.GetHashCode();
        hash = hash * 31 + Nanos.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "Timestamp{" +
            "seconds=" + Seconds +
            ", nanos=" + Nanos +
            '}';
    }
}
