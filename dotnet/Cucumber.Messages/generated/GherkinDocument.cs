using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

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

public sealed class GherkinDocument 
{
    /**
     * The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
     * of the source, typically a file path relative to the root directory
     */
    public string Uri { get; private set; }
    public Feature Feature { get; private set; }
    /**
     * All the comments in the Gherkin document
     */
    public List<Comment> Comments { get; private set; }


    public GherkinDocument(
        string uri,
        Feature feature,
        List<Comment> comments
    ) 
    {
              this.Uri = uri;
              this.Feature = feature;
              RequireNonNull<List<Comment>>(comments, "Comments", "GherkinDocument.Comments cannot be null");
        this.Comments = comments == null ? new List<Comment>() : new List<Comment>(comments);
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        GherkinDocument that = (GherkinDocument) o;
        return 
            Object.Equals(Uri, that.Uri) &&         
            Object.Equals(Feature, that.Feature) &&         
            Comments.Equals(that.Comments);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Uri != null)
          hash = hash * 31 + Uri.GetHashCode();
        if (Feature != null)
          hash = hash * 31 + Feature.GetHashCode();
        if (Comments != null)
          hash = hash * 31 + Comments.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "GherkinDocument{" +
            "uri=" + Uri +
            ", feature=" + Feature +
            ", comments=" + Comments +
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
