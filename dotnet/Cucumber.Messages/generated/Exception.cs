using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Exception message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A simplified representation of an exception
 */

public sealed class Exception 
{
    /**
     * The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
     */
    public string Type { get; private set; }
    /**
     * The message of exception that caused this result. E.g. expected: "a" but was: "b"
     */
    public string Message { get; private set; }
    /**
     * The stringified stack trace of the exception that caused this result
     */
    public string StackTrace { get; private set; }


    public Exception(
        string type,
        string message,
        string stackTrace
    ) 
    {
        RequireNonNull<string>(type, "Type", "Exception.Type cannot be null");
        this.Type = type;
              this.Message = message;
              this.StackTrace = stackTrace;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Exception that = (Exception) o;
        return 
            Type.Equals(that.Type) &&         
            Object.Equals(Message, that.Message) &&         
            Object.Equals(StackTrace, that.StackTrace);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Type != null)
          hash = hash * 31 + Type.GetHashCode();
        if (Message != null)
          hash = hash * 31 + Message.GetHashCode();
        if (StackTrace != null)
          hash = hash * 31 + StackTrace.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Exception{" +
            "type=" + Type +
            ", message=" + Message +
            ", stackTrace=" + StackTrace +
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
