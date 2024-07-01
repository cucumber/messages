using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestCaseStarted message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class TestCaseStarted 
{
    /**
     * The first attempt should have value 0, and for each retry the value
     * should increase by 1.
     */
    public long Attempt { get; private set; }
    /**
     * Because a `TestCase` can be run multiple times (in case of a retry),
     * we use this field to group messages relating to the same attempt.
     */
    public string Id { get; private set; }
    public string TestCaseId { get; private set; }
    /**
     * An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.
     */
    public string WorkerId { get; private set; }
    public Timestamp Timestamp { get; private set; }


    public TestCaseStarted(
        long attempt,
        string id,
        string testCaseId,
        string workerId,
        Timestamp timestamp
    ) 
    {
              RequireNonNull<long>(attempt, "Attempt", "TestCaseStarted.Attempt cannot be null");
        this.Attempt = attempt;
              RequireNonNull<string>(id, "Id", "TestCaseStarted.Id cannot be null");
        this.Id = id;
              RequireNonNull<string>(testCaseId, "TestCaseId", "TestCaseStarted.TestCaseId cannot be null");
        this.TestCaseId = testCaseId;
              this.WorkerId = workerId;
              RequireNonNull<Timestamp>(timestamp, "Timestamp", "TestCaseStarted.Timestamp cannot be null");
        this.Timestamp = timestamp;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestCaseStarted that = (TestCaseStarted) o;
        return 
            Attempt.Equals(that.Attempt) &&         
            Id.Equals(that.Id) &&         
            TestCaseId.Equals(that.TestCaseId) &&         
            Object.Equals(WorkerId, that.WorkerId) &&         
            Timestamp.Equals(that.Timestamp);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
          hash = hash * 31 + Attempt.GetHashCode();  
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (TestCaseId != null)
          hash = hash * 31 + TestCaseId.GetHashCode();
        if (WorkerId != null)
          hash = hash * 31 + WorkerId.GetHashCode();
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestCaseStarted{" +
            "attempt=" + Attempt +
            ", id=" + Id +
            ", testCaseId=" + TestCaseId +
            ", workerId=" + WorkerId +
            ", timestamp=" + Timestamp +
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
