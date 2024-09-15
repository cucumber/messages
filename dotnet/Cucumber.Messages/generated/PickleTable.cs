
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTable message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record PickleTable 
{
    public List<PickleTableRow> Rows { get; }


    public PickleTable(
        List<PickleTableRow> rows
    ) 
    {
        Rows = rows ?? throw new ArgumentNullException("Rows", "PickleTable.Rows cannot be null");
    }
}
