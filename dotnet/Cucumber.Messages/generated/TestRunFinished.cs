using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestRunFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class TestRunFinished 
{
    /**
     * An informative message about the test run. Typically additional information about failure, but not necessarily.
     */
    public string Message { get; private set; }
    /**
     * A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.
     */
    public bool Success { get; private set; }
    /**
     * Timestamp when the TestRun is finished
     */
    public Timestamp Timestamp { get; private set; }
    /**
     * Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.
     */
    public Exception Exception { get; private set; }


    public TestRunFinished(
        string message,
        bool success,
        Timestamp timestamp,
        Exception exception
    ) 
    {
              this.Message = message;
        RequireNonNull<bool>(success, "Success", "TestRunFinished.Success cannot be null");
        this.Success = success;
        RequireNonNull<Timestamp>(timestamp, "Timestamp", "TestRunFinished.Timestamp cannot be null");
        this.Timestamp = timestamp;
              this.Exception = exception;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestRunFinished that = (TestRunFinished) o;
        return 
            Object.Equals(Message, that.Message) &&         
            Success.Equals(that.Success) &&         
            Timestamp.Equals(that.Timestamp) &&         
            Object.Equals(Exception, that.Exception);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Message != null)
          hash = hash * 31 + Message.GetHashCode();
          hash = hash * 31 + Success.GetHashCode();  
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
        if (Exception != null)
          hash = hash * 31 + Exception.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestRunFinished{" +
            "message=" + Message +
            ", success=" + Success +
            ", timestamp=" + Timestamp +
            ", exception=" + Exception +
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
