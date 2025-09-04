using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Snippet message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class Snippet 
{
    /**
     * The programming language of the code
     */
    public string Language { get; private set; }
    /**
     * A snippet of code
     */
    public string Code { get; private set; }


    public Snippet(
        string language,
        string code
    ) 
    {
        RequireNonNull<string>(language, "Language", "Snippet.Language cannot be null");
        this.Language = language;
        RequireNonNull<string>(code, "Code", "Snippet.Code cannot be null");
        this.Code = code;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Snippet that = (Snippet) o;
        return 
            Language.Equals(that.Language) &&         
            Code.Equals(that.Code);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Language != null)
          hash = hash * 31 + Language.GetHashCode();
        if (Code != null)
          hash = hash * 31 + Code.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Snippet{" +
            "language=" + Language +
            ", code=" + Code +
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
