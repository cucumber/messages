
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TableRow message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A row in a table
 */

public sealed record TableRow 
{
    /**
     * The location of the first cell in the row
     */
    public Location Location { get; }
    /**
     * Cells in the row
     */
    public List<TableCell> Cells { get; }
    public string Id { get; }


    public TableRow(
        Location location,
        List<TableCell> cells,
        string id
    ) 
    {
        this.Location = location ?? throw new ArgumentNullException("Location", "TableRow.Location cannot be null");
        this.Cells = cells ?? throw new ArgumentNullException("Cells", "TableRow.Cells cannot be null");
        this.Id = id ?? throw new ArgumentNullException("Id", "TableRow.Id cannot be null");
    }
}
