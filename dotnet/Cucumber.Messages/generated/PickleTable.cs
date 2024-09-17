
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTable message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record PickleTable 
{
    public ImmutableArray<PickleTableRow> Rows { get; }


    public PickleTable(
        ImmutableArray<PickleTableRow> rows
    ) 
    {
        Rows = rows;
    }
}
