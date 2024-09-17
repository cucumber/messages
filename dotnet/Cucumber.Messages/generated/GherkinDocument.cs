
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the GherkinDocument message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
 * Cucumber implementations should *not* depend on `GherkinDocument` or any of its
 * children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.
 *
 * The only consumers of `GherkinDocument` should only be formatters that produce
 * "rich" output, resembling the original Gherkin document.
 */

public sealed record GherkinDocument 
{
    /**
     * The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
     * of the source, typically a file path relative to the root directory
     */
    public string? Uri { get; }
    public Feature? Feature { get; }
    /**
     * All the comments in the Gherkin document
     */
    public ImmutableArray<Comment> Comments { get; }


    public GherkinDocument(
        string? uri,
        Feature? feature,
        ImmutableArray<Comment> comments
    ) 
    {
        Uri = uri;
        Feature = feature;
        Comments = comments;
    }
}
