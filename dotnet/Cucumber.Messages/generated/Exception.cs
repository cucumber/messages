
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

public sealed record Exception 
{
    /**
     * The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
     */
    public string Type { get; }
    /**
     * The message of exception that caused this result. E.g. expected: "a" but was: "b"
     */
    public string? Message { get; }
    /**
     * The stringified stack trace of the exception that caused this result
     */
    public string? StackTrace { get; }


    public Exception(
        string type,
        string? message,
        string? stackTrace
    ) 
    {
        this.Type = type ?? throw new ArgumentNullException("Type", "Exception.Type cannot be null");
        this.Message = message;
        this.StackTrace = stackTrace;
    }
}
