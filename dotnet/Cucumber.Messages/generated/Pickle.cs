using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

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

public sealed class Pickle 
{
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
              RequireNonNull<string>(id, "Id", "Pickle.Id cannot be null");
        this.Id = id;
              RequireNonNull<string>(uri, "Uri", "Pickle.Uri cannot be null");
        this.Uri = uri;
              RequireNonNull<string>(name, "Name", "Pickle.Name cannot be null");
        this.Name = name;
              RequireNonNull<string>(language, "Language", "Pickle.Language cannot be null");
        this.Language = language;
              RequireNonNull<List<PickleStep>>(steps, "Steps", "Pickle.Steps cannot be null");
        this.Steps = new List<PickleStep>(steps);
              RequireNonNull<List<PickleTag>>(tags, "Tags", "Pickle.Tags cannot be null");
        this.Tags = new List<PickleTag>(tags);
              RequireNonNull<List<string>>(astNodeIds, "AstNodeIds", "Pickle.AstNodeIds cannot be null");
        this.AstNodeIds = new List<string>(astNodeIds);
    }

    public override bool Equals(Object o) 
    {
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

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (Uri != null)
          hash = hash * 31 + Uri.GetHashCode();
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        if (Language != null)
          hash = hash * 31 + Language.GetHashCode();
        if (Steps != null)
          hash = hash * 31 + Steps.GetHashCode();
        if (Tags != null)
          hash = hash * 31 + Tags.GetHashCode();
        if (AstNodeIds != null)
          hash = hash * 31 + AstNodeIds.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
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

    private static T Require<T>(T property, string propertyName, string errorMessage)
    {
      RequireNonNull<T>(property, propertyName, errorMessage);
      return property;
    }
    private static void RequireNonNull<T>(T property, string propertyName, string errorMessage) 
    {
      if (property == null) throw new ArgumentNullException(propertyName, errorMessage);
    }
}
