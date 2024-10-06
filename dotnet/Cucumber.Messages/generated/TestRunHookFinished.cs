using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestRunHookFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class TestRunHookFinished 
{
    /**
     * Identifier for the hook execution that has finished
     */
    public string TestRunHookStartedId { get; private set; }
    public TestStepResult Result { get; private set; }
    public Timestamp Timestamp { get; private set; }


    public TestRunHookFinished(
        string testRunHookStartedId,
        TestStepResult result,
        Timestamp timestamp
    ) 
    {
        RequireNonNull<string>(testRunHookStartedId, "TestRunHookStartedId", "TestRunHookFinished.TestRunHookStartedId cannot be null");
        this.TestRunHookStartedId = testRunHookStartedId;
        RequireNonNull<TestStepResult>(result, "Result", "TestRunHookFinished.Result cannot be null");
        this.Result = result;
        RequireNonNull<Timestamp>(timestamp, "Timestamp", "TestRunHookFinished.Timestamp cannot be null");
        this.Timestamp = timestamp;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestRunHookFinished that = (TestRunHookFinished) o;
        return 
            TestRunHookStartedId.Equals(that.TestRunHookStartedId) &&         
            Result.Equals(that.Result) &&         
            Timestamp.Equals(that.Timestamp);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (TestRunHookStartedId != null)
          hash = hash * 31 + TestRunHookStartedId.GetHashCode();
        if (Result != null)
          hash = hash * 31 + Result.GetHashCode();
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestRunHookFinished{" +
            "testRunHookStartedId=" + TestRunHookStartedId +
            ", result=" + Result +
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
