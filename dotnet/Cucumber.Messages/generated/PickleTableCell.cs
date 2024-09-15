
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTableCell message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record PickleTableCell 
{
    public string Value { get; }


    public PickleTableCell(
        string value
    ) 
    {
        this.Value = value ?? throw new ArgumentNullException("Value", "PickleTableCell.Value cannot be null");
    }
}
