
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestStepFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record TestStepFinished 
{
    public string TestCaseStartedId { get; }
    public string TestStepId { get; }
    public TestStepResult TestStepResult { get; }
    public Timestamp Timestamp { get; }


    public TestStepFinished(
        string testCaseStartedId,
        string testStepId,
        TestStepResult testStepResult,
        Timestamp timestamp
    ) 
    {
        TestCaseStartedId = testCaseStartedId ?? throw new ArgumentNullException("TestCaseStartedId", "TestStepFinished.TestCaseStartedId cannot be null");
        TestStepId = testStepId ?? throw new ArgumentNullException("TestStepId", "TestStepFinished.TestStepId cannot be null");
        TestStepResult = testStepResult ?? throw new ArgumentNullException("TestStepResult", "TestStepFinished.TestStepResult cannot be null");
        Timestamp = timestamp ?? throw new ArgumentNullException("Timestamp", "TestStepFinished.Timestamp cannot be null");
    }
}
