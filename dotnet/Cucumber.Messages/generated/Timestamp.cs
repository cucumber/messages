using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Timestamp message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class Timestamp 
{
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
        RequireNonNull<long>(seconds, "Seconds", "Timestamp.Seconds cannot be null");
        this.Seconds = seconds;
        RequireNonNull<long>(nanos, "Nanos", "Timestamp.Nanos cannot be null");
        this.Nanos = nanos;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Timestamp that = (Timestamp) o;
        return 
            Seconds.Equals(that.Seconds) &&         
            Nanos.Equals(that.Nanos);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
          hash = hash * 31 + Seconds.GetHashCode();  
          hash = hash * 31 + Nanos.GetHashCode();  
        return hash;
    }

    public override string ToString() 
    {
        return "Timestamp{" +
            "seconds=" + Seconds +
            ", nanos=" + Nanos +
            '}';
    }

    private static T Require<T>(T property, string propertyName, string errorMessage)
    {
      RequireNonNull<T>(property, propertyName, errorMessage);
      return property;
    }
    private static void RequireNonNull<T>(T property, string propertyName, string errorMessage) 
    {
      if (property == null) throw new ArgumentNullException(propertyName, errorMessage);
    }
}
