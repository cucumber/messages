using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestCaseFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class TestCaseFinished 
{
    public string TestCaseStartedId { get; private set; }
    public Timestamp Timestamp { get; private set; }
    public bool WillBeRetried { get; private set; }


    public TestCaseFinished(
        string testCaseStartedId,
        Timestamp timestamp,
        bool willBeRetried
    ) 
    {
              RequireNonNull<string>(testCaseStartedId, "TestCaseStartedId", "TestCaseFinished.TestCaseStartedId cannot be null");
        this.TestCaseStartedId = testCaseStartedId;
              RequireNonNull<Timestamp>(timestamp, "Timestamp", "TestCaseFinished.Timestamp cannot be null");
        this.Timestamp = timestamp;
              RequireNonNull<bool>(willBeRetried, "WillBeRetried", "TestCaseFinished.WillBeRetried cannot be null");
        this.WillBeRetried = willBeRetried;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestCaseFinished that = (TestCaseFinished) o;
        return 
            TestCaseStartedId.Equals(that.TestCaseStartedId) &&         
            Timestamp.Equals(that.Timestamp) &&         
            WillBeRetried.Equals(that.WillBeRetried);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (TestCaseStartedId != null)
          hash = hash * 31 + TestCaseStartedId.GetHashCode();
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
          hash = hash * 31 + WillBeRetried.GetHashCode();  
        return hash;
    }

    public override string ToString() 
    {
        return "TestCaseFinished{" +
            "testCaseStartedId=" + TestCaseStartedId +
            ", timestamp=" + Timestamp +
            ", willBeRetried=" + WillBeRetried +
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
