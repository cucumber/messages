
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Pickle message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * //// Pickles
 *
 * A `Pickle` represents a template for a `TestCase`. It is typically derived
 * from another format, such as [GherkinDocument](#io.cucumber.messages.GherkinDocument).
 * In the future a `Pickle` may be derived from other formats such as Markdown or
 * Excel files.
 *
 * By making `Pickle` the main data structure Cucumber uses for execution, the
 * implementation of Cucumber itself becomes simpler, as it doesn't have to deal
 * with the complex structure of a [GherkinDocument](#io.cucumber.messages.GherkinDocument).
 *
 * Each `PickleStep` of a `Pickle` is matched with a `StepDefinition` to create a `TestCase`
 */

public sealed record Pickle 
{
    /**
     * A unique id for the pickle
     */
    public string Id { get; }
    /**
     * The uri of the source file
     */
    public string Uri { get; }
    /**
     * The name of the pickle
     */
    public string Name { get; }
    /**
     * The language of the pickle
     */
    public string Language { get; }
    /**
     * One or more steps
     */
    public ImmutableArray<PickleStep> Steps { get; }
    /**
     * One or more tags. If this pickle is constructed from a Gherkin document,
     * It includes inherited tags from the `Feature` as well.
     */
    public ImmutableArray<PickleTag> Tags { get; }
    /**
     * Points to the AST node locations of the pickle. The last one represents the unique
     * id of the pickle. A pickle constructed from `Examples` will have the first
     * id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.
     */
    public ImmutableArray<string> AstNodeIds { get; }


    public Pickle(
        string id,
        string uri,
        string name,
        string language,
        ImmutableArray<PickleStep> steps,
        ImmutableArray<PickleTag> tags,
        ImmutableArray<string> astNodeIds
    ) 
    {
        Id = id ?? throw new ArgumentNullException("Id", "Pickle.Id cannot be null");
        Uri = uri ?? throw new ArgumentNullException("Uri", "Pickle.Uri cannot be null");
        Name = name ?? throw new ArgumentNullException("Name", "Pickle.Name cannot be null");
        Language = language ?? throw new ArgumentNullException("Language", "Pickle.Language cannot be null");
        Steps = steps;
        Tags = tags;
        AstNodeIds = astNodeIds;
    }
}
