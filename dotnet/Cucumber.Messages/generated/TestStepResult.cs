using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestStepResult message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class TestStepResult 
{
    public Duration Duration { get; private set; }
    /**
     * An arbitrary bit of information that explains this result. This can be a stack trace of anything else.
     */
    public string Message { get; private set; }
    public TestStepResultStatus Status { get; private set; }
    /**
     * Exception thrown while executing this step, if any.
     */
    public Exception Exception { get; private set; }


    public TestStepResult(
        Duration duration,
        string message,
        TestStepResultStatus status,
        Exception exception
    ) 
    {
              RequireNonNull<Duration>(duration, "Duration", "TestStepResult.Duration cannot be null");
        this.Duration = duration;
              this.Message = message;
              RequireNonNull<TestStepResultStatus>(status, "Status", "TestStepResult.Status cannot be null");
        this.Status = status;
              this.Exception = exception;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestStepResult that = (TestStepResult) o;
        return 
            Duration.Equals(that.Duration) &&         
            Object.Equals(Message, that.Message) &&         
            Status.Equals(that.Status) &&         
            Object.Equals(Exception, that.Exception);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Duration != null)
          hash = hash * 31 + Duration.GetHashCode();
        if (Message != null)
          hash = hash * 31 + Message.GetHashCode();
          hash = hash * 31 + Status.GetHashCode();  
        if (Exception != null)
          hash = hash * 31 + Exception.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestStepResult{" +
            "duration=" + Duration +
            ", message=" + Message +
            ", status=" + Status +
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
