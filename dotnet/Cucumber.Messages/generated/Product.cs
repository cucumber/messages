
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Product message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Used to describe various properties of Meta
 */

public sealed record Product 
{
    /**
     * The product name
     */
    public string Name { get; }
    /**
     * The product version
     */
    public string? Version { get; }


    public Product(
        string name,
        string? version
    ) 
    {
        this.Name = name ?? throw new ArgumentNullException("Name", "Product.Name cannot be null");
        this.Version = version;
    }
}
