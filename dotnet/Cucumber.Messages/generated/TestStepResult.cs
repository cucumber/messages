
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestStepResult message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record TestStepResult 
{
    public Duration Duration { get; }
    /**
     * An arbitrary bit of information that explains this result. This can be a stack trace of anything else.
     */
    public string? Message { get; }
    public TestStepResultStatus Status { get; }
    /**
     * Exception thrown while executing this step, if any.
     */
    public Exception? Exception { get; }


    public TestStepResult(
        Duration duration,
        string? message,
        TestStepResultStatus status,
        Exception? exception
    ) 
    {
        Duration = duration ?? throw new ArgumentNullException("Duration", "TestStepResult.Duration cannot be null");
        Message = message;
        Status = status;
        Exception = exception;
    }
}
