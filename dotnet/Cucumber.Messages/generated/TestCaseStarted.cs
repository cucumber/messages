
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestCaseStarted message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed record TestCaseStarted 
{
    /**
     * The first attempt should have value 0, and for each retry the value
     * should increase by 1.
     */
    public long Attempt { get; }
    /**
     * Because a `TestCase` can be run multiple times (in case of a retry),
     * we use this field to group messages relating to the same attempt.
     */
    public string Id { get; }
    public string TestCaseId { get; }
    /**
     * An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.
     */
    public string? WorkerId { get; }
    public Timestamp Timestamp { get; }


    public TestCaseStarted(
        long attempt,
        string id,
        string testCaseId,
        string? workerId,
        Timestamp timestamp
    ) 
    {
        Attempt = attempt;
        Id = id ?? throw new ArgumentNullException("Id", "TestCaseStarted.Id cannot be null");
        TestCaseId = testCaseId ?? throw new ArgumentNullException("TestCaseId", "TestCaseStarted.TestCaseId cannot be null");
        WorkerId = workerId;
        Timestamp = timestamp ?? throw new ArgumentNullException("Timestamp", "TestCaseStarted.Timestamp cannot be null");
    }
}
