
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTableRow message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record PickleTableRow 
{
    public ImmutableArray<PickleTableCell> Cells { get; }


    public PickleTableRow(
        ImmutableArray<PickleTableCell> cells
    ) 
    {
        Cells = cells;
    }
}
