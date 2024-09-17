
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Source message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * //// Source
 *
 * A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
 */

public sealed record Source 
{
    /**
     * The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
     * of the source, typically a file path relative to the root directory
     */
    public string Uri { get; }
    /**
     * The contents of the file
     */
    public string Data { get; }
    /**
     * The media type of the file. Can be used to specify custom types, such as
     * text/x.cucumber.gherkin+plain
     */
    public SourceMediaType MediaType { get; }


    public Source(
        string uri,
        string data,
        SourceMediaType mediaType
    ) 
    {
        Uri = uri ?? throw new ArgumentNullException("Uri", "Source.Uri cannot be null");
        Data = data ?? throw new ArgumentNullException("Data", "Source.Data cannot be null");
        MediaType = mediaType;
    }
}
