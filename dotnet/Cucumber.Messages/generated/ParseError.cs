
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the ParseError message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record ParseError 
{
    public SourceReference Source { get; }
    public string Message { get; }


    public ParseError(
        SourceReference source,
        string message
    ) 
    {
        Source = source ?? throw new ArgumentNullException("Source", "ParseError.Source cannot be null");
        Message = message ?? throw new ArgumentNullException("Message", "ParseError.Message cannot be null");
    }
}
