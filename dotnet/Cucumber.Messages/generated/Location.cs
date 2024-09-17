
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Location message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Points to a line and a column in a text file
 */

public sealed record Location 
{
    public long Line { get; }
    public long? Column { get; }


    public Location(
        long line,
        long? column
    ) 
    {
        Line = line;
        Column = column;
    }
}
