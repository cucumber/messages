using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the ParseError message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class ParseError 
{
    public SourceReference Source { get; private set; }
    public string Message { get; private set; }


    public ParseError(
        SourceReference source,
        string message
    ) 
    {
              RequireNonNull<SourceReference>(source, "Source", "ParseError.Source cannot be null");
        this.Source = source;
              RequireNonNull<string>(message, "Message", "ParseError.Message cannot be null");
        this.Message = message;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        ParseError that = (ParseError) o;
        return 
            Source.Equals(that.Source) &&         
            Message.Equals(that.Message);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Source != null)
          hash = hash * 31 + Source.GetHashCode();
        if (Message != null)
          hash = hash * 31 + Message.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "ParseError{" +
            "source=" + Source +
            ", message=" + Message +
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
