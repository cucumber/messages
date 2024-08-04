using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the GlobalHookFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class GlobalHookFinished 
{
    /**
     * Identifier for the test run that this hook execution belongs to
     */
    public string TestRunStartedId { get; private set; }
    /**
     * Identifier for the hook that was executed
     */
    public string HookId { get; private set; }
    public TestStepResult Result { get; private set; }
    public Timestamp Timestamp { get; private set; }


    public GlobalHookFinished(
        string testRunStartedId,
        string hookId,
        TestStepResult result,
        Timestamp timestamp
    ) 
    {
              RequireNonNull<string>(testRunStartedId, "TestRunStartedId", "GlobalHookFinished.TestRunStartedId cannot be null");
        this.TestRunStartedId = testRunStartedId;
              RequireNonNull<string>(hookId, "HookId", "GlobalHookFinished.HookId cannot be null");
        this.HookId = hookId;
              RequireNonNull<TestStepResult>(result, "Result", "GlobalHookFinished.Result cannot be null");
        this.Result = result;
              RequireNonNull<Timestamp>(timestamp, "Timestamp", "GlobalHookFinished.Timestamp cannot be null");
        this.Timestamp = timestamp;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        GlobalHookFinished that = (GlobalHookFinished) o;
        return 
            TestRunStartedId.Equals(that.TestRunStartedId) &&         
            HookId.Equals(that.HookId) &&         
            Result.Equals(that.Result) &&         
            Timestamp.Equals(that.Timestamp);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (TestRunStartedId != null)
          hash = hash * 31 + TestRunStartedId.GetHashCode();
        if (HookId != null)
          hash = hash * 31 + HookId.GetHashCode();
        if (Result != null)
          hash = hash * 31 + Result.GetHashCode();
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "GlobalHookFinished{" +
            "testRunStartedId=" + TestRunStartedId +
            ", hookId=" + HookId +
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
