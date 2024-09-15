
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TableCell message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A cell in a `TableRow`
 */

public sealed record TableCell 
{
    /**
     * The location of the cell
     */
    public Location Location { get; }
    /**
     * The value of the cell
     */
    public string Value { get; }


    public TableCell(
        Location location,
        string value
    ) 
    {
        Location = location ?? throw new ArgumentNullException("Location", "TableCell.Location cannot be null");
        Value = value ?? throw new ArgumentNullException("Value", "TableCell.Value cannot be null");
    }
}
