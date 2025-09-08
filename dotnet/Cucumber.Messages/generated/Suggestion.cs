using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Suggestion message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A suggested fragment of code to implement an undefined step
 */

public sealed class Suggestion 
{
    /**
     * A unique id for this suggestion
     */
    public string Id { get; private set; }
    /**
     * The ID of the `PickleStep` this `Suggestion` was created for.
     */
    public string PickleStepId { get; private set; }
    /**
     * A collection of code snippets that could implement the undefined step
     */
    public List<Snippet> Snippets { get; private set; }


    public Suggestion(
        string id,
        string pickleStepId,
        List<Snippet> snippets
    ) 
    {
        RequireNonNull<string>(id, "Id", "Suggestion.Id cannot be null");
        this.Id = id;
        RequireNonNull<string>(pickleStepId, "PickleStepId", "Suggestion.PickleStepId cannot be null");
        this.PickleStepId = pickleStepId;
        RequireNonNull<List<Snippet>>(snippets, "Snippets", "Suggestion.Snippets cannot be null");
        this.Snippets = new List<Snippet>(snippets);        
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Suggestion that = (Suggestion) o;
        return 
            Id.Equals(that.Id) &&         
            PickleStepId.Equals(that.PickleStepId) &&         
            Snippets.Equals(that.Snippets);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (PickleStepId != null)
          hash = hash * 31 + PickleStepId.GetHashCode();
        if (Snippets != null)
          hash = hash * 31 + Snippets.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Suggestion{" +
            "id=" + Id +
            ", pickleStepId=" + PickleStepId +
            ", snippets=" + Snippets +
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
