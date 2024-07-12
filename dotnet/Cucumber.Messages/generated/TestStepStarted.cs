using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestStepStarted message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class TestStepStarted 
{
    public string TestCaseStartedId { get; private set; }
    public string TestStepId { get; private set; }
    public Timestamp Timestamp { get; private set; }


    public TestStepStarted(
        string testCaseStartedId,
        string testStepId,
        Timestamp timestamp
    ) 
    {
              RequireNonNull<string>(testCaseStartedId, "TestCaseStartedId", "TestStepStarted.TestCaseStartedId cannot be null");
        this.TestCaseStartedId = testCaseStartedId;
              RequireNonNull<string>(testStepId, "TestStepId", "TestStepStarted.TestStepId cannot be null");
        this.TestStepId = testStepId;
              RequireNonNull<Timestamp>(timestamp, "Timestamp", "TestStepStarted.Timestamp cannot be null");
        this.Timestamp = timestamp;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestStepStarted that = (TestStepStarted) o;
        return 
            TestCaseStartedId.Equals(that.TestCaseStartedId) &&         
            TestStepId.Equals(that.TestStepId) &&         
            Timestamp.Equals(that.Timestamp);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (TestCaseStartedId != null)
          hash = hash * 31 + TestCaseStartedId.GetHashCode();
        if (TestStepId != null)
          hash = hash * 31 + TestStepId.GetHashCode();
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestStepStarted{" +
            "testCaseStartedId=" + TestCaseStartedId +
            ", testStepId=" + TestStepId +
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
