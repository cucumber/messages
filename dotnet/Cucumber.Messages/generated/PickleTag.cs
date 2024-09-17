
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTag message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A tag
 */

public sealed record PickleTag 
{
    public string Name { get; }
    /**
     * Points to the AST node this was created from
     */
    public string AstNodeId { get; }


    public PickleTag(
        string name,
        string astNodeId
    ) 
    {
        Name = name ?? throw new ArgumentNullException("Name", "PickleTag.Name cannot be null");
        AstNodeId = astNodeId ?? throw new ArgumentNullException("AstNodeId", "PickleTag.AstNodeId cannot be null");
    }
}
