
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTableRow message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record PickleTableRow 
{
    public List<PickleTableCell> Cells { get; }


    public PickleTableRow(
        List<PickleTableCell> cells
    ) 
    {
        this.Cells = cells ?? throw new ArgumentNullException("Cells", "PickleTableRow.Cells cannot be null");
    }
}
