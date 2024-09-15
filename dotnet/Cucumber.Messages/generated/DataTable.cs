
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the DataTable message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record DataTable 
{
    public Location Location { get; }
    public List<TableRow> Rows { get; }


    public DataTable(
        Location location,
        List<TableRow> rows
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "DataTable.Location cannot be null");
        Rows = rows ?? throw new ArgumentNullException("Rows", "DataTable.Rows cannot be null");
    }
}
