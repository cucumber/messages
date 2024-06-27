using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Exception message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A simplified representation of an exception
 */
// Generated code
public sealed class Exception {
    /**
     * The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
     */
    public string Type { get; private set; }
    /**
     * The message of exception that caused this result. E.g. expected: "a" but was: "b"
     */
    public string? Message { get; private set; }
    /**
     * The stringified stack trace of the exception that caused this result
     */
    public string? StackTrace { get; private set; }

    public Exception(
        string type,
        string message,
        string stackTrace
    ) 
    {
        this.Type = type;
        this.Message = message;
        this.StackTrace = stackTrace;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Exception that = (Exception) o;
        return 
            Type.Equals(that.Type) &&         
            Object.Equals(Message, that.Message) &&         
            Object.Equals(StackTrace, that.StackTrace);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Type.GetHashCode();
        hash = hash * 31 + Message?.GetHashCode()?? 0;
        hash = hash * 31 + StackTrace?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Exception{" +
            "type=" + Type +
            ", message=" + Message +
            ", stackTrace=" + StackTrace +
            '}';
    }
}
