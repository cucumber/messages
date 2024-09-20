using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestRunHookStarted message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class TestRunHookStarted 
{
    /**
     * Unique identifier for this hook execution
     */
    public string Id { get; private set; }
    /**
     * Identifier for the test run that this hook execution belongs to
     */
    public string TestRunStartedId { get; private set; }
    /**
     * Identifier for the hook that will be executed
     */
    public string HookId { get; private set; }
    public Timestamp Timestamp { get; private set; }


    public TestRunHookStarted(
        string id,
        string testRunStartedId,
        string hookId,
        Timestamp timestamp
    ) 
    {
              RequireNonNull<string>(id, "Id", "TestRunHookStarted.Id cannot be null");
        this.Id = id;
              RequireNonNull<string>(testRunStartedId, "TestRunStartedId", "TestRunHookStarted.TestRunStartedId cannot be null");
        this.TestRunStartedId = testRunStartedId;
              RequireNonNull<string>(hookId, "HookId", "TestRunHookStarted.HookId cannot be null");
        this.HookId = hookId;
              RequireNonNull<Timestamp>(timestamp, "Timestamp", "TestRunHookStarted.Timestamp cannot be null");
        this.Timestamp = timestamp;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestRunHookStarted that = (TestRunHookStarted) o;
        return 
            Id.Equals(that.Id) &&         
            TestRunStartedId.Equals(that.TestRunStartedId) &&         
            HookId.Equals(that.HookId) &&         
            Timestamp.Equals(that.Timestamp);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (TestRunStartedId != null)
          hash = hash * 31 + TestRunStartedId.GetHashCode();
        if (HookId != null)
          hash = hash * 31 + HookId.GetHashCode();
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestRunHookStarted{" +
            "id=" + Id +
            ", testRunStartedId=" + TestRunStartedId +
            ", hookId=" + HookId +
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
