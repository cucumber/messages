
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestRunFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record TestRunFinished 
{
    /**
     * An informative message about the test run. Typically additional information about failure, but not necessarily.
     */
    public string? Message { get; }
    /**
     * A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.
     */
    public bool Success { get; }
    /**
     * Timestamp when the TestRun is finished
     */
    public Timestamp Timestamp { get; }
    /**
     * Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.
     */
    public Exception? Exception { get; }


    public TestRunFinished(
        string? message,
        bool success,
        Timestamp timestamp,
        Exception? exception
    ) 
    {
        this.Message = message;
        this.Success = success;
        this.Timestamp = timestamp ?? throw new ArgumentNullException("Timestamp", "TestRunFinished.Timestamp cannot be null");
        this.Exception = exception;
    }
}
