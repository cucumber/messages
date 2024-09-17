
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestCaseFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record TestCaseFinished 
{
    public string TestCaseStartedId { get; }
    public Timestamp Timestamp { get; }
    public bool WillBeRetried { get; }


    public TestCaseFinished(
        string testCaseStartedId,
        Timestamp timestamp,
        bool willBeRetried
    ) 
    {
        TestCaseStartedId = testCaseStartedId ?? throw new ArgumentNullException("TestCaseStartedId", "TestCaseFinished.TestCaseStartedId cannot be null");
        Timestamp = timestamp ?? throw new ArgumentNullException("Timestamp", "TestCaseFinished.Timestamp cannot be null");
        WillBeRetried = willBeRetried;
    }
}
