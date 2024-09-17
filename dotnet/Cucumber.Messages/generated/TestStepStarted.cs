
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestStepStarted message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record TestStepStarted 
{
    public string TestCaseStartedId { get; }
    public string TestStepId { get; }
    public Timestamp Timestamp { get; }


    public TestStepStarted(
        string testCaseStartedId,
        string testStepId,
        Timestamp timestamp
    ) 
    {
        TestCaseStartedId = testCaseStartedId ?? throw new ArgumentNullException("TestCaseStartedId", "TestStepStarted.TestCaseStartedId cannot be null");
        TestStepId = testStepId ?? throw new ArgumentNullException("TestStepId", "TestStepStarted.TestStepId cannot be null");
        Timestamp = timestamp ?? throw new ArgumentNullException("Timestamp", "TestStepStarted.Timestamp cannot be null");
    }
}
