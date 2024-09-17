
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Duration message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * The structure is pretty close of the Timestamp one. For clarity, a second type
 * of message is used.
 */

public sealed record Duration 
{
    public long Seconds { get; }
    /**
     * Non-negative fractions of a second at nanosecond resolution. Negative
     * second values with fractions must still have non-negative nanos values
     * that count forward in time. Must be from 0 to 999,999,999
     * inclusive.
     */
    public long Nanos { get; }


    public Duration(
        long seconds,
        long nanos
    ) 
    {
        Seconds = seconds;
        Nanos = nanos;
    }
}
