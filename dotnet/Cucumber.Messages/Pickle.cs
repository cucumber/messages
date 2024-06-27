using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

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
// Generated code
public sealed class Pickle {
    /**
     * A unique id for the pickle
     */
    public string Id { get; private set; }
    /**
     * The uri of the source file
     */
    public string Uri { get; private set; }
    /**
     * The name of the pickle
     */
    public string Name { get; private set; }
    /**
     * The language of the pickle
     */
    public string Language { get; private set; }
    /**
     * One or more steps
     */
    public List<PickleStep> Steps { get; private set; }
    /**
     * One or more tags. If this pickle is constructed from a Gherkin document,
     * It includes inherited tags from the `Feature` as well.
     */
    public List<PickleTag> Tags { get; private set; }
    /**
     * Points to the AST node locations of the pickle. The last one represents the unique
     * id of the pickle. A pickle constructed from `Examples` will have the first
     * id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.
     */
    public List<string> AstNodeIds { get; private set; }

    public Pickle(
        string id,
        string uri,
        string name,
        string language,
        List<PickleStep> steps,
        List<PickleTag> tags,
        List<string> astNodeIds
    ) 
    {
        this.Id = id;
        this.Uri = uri;
        this.Name = name;
        this.Language = language;
        this.Steps = steps;
        this.Tags = tags;
        this.AstNodeIds = astNodeIds;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Pickle that = (Pickle) o;
        return 
            Id.Equals(that.Id) &&         
            Uri.Equals(that.Uri) &&         
            Name.Equals(that.Name) &&         
            Language.Equals(that.Language) &&         
            Steps.Equals(that.Steps) &&         
            Tags.Equals(that.Tags) &&         
            AstNodeIds.Equals(that.AstNodeIds);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Id.GetHashCode();
        hash = hash * 31 + Uri.GetHashCode();
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + Language.GetHashCode();
        hash = hash * 31 + Steps.GetHashCode();
        hash = hash * 31 + Tags.GetHashCode();
        hash = hash * 31 + AstNodeIds.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "Pickle{" +
            "id=" + Id +
            ", uri=" + Uri +
            ", name=" + Name +
            ", language=" + Language +
            ", steps=" + Steps +
            ", tags=" + Tags +
            ", astNodeIds=" + AstNodeIds +
            '}';
    }
}
