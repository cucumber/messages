using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TestStepResult message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class TestStepResult {
    public Duration Duration { get; private set; }
    /**
     * An arbitrary bit of information that explains this result. This can be a stack trace of anything else.
     */
    public string? Message { get; private set; }
    public TestStepResultStatus Status { get; private set; }
    /**
     * Exception thrown while executing this step, if any.
     */
    public Exception? Exception { get; private set; }

    public TestStepResult(
        Duration duration,
        string message,
        TestStepResultStatus status,
        Exception exception
    ) 
    {
        this.Duration = duration;
        this.Message = message;
        this.Status = status;
        this.Exception = exception;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestStepResult that = (TestStepResult) o;
        return 
            Duration.Equals(that.Duration) &&         
            Object.Equals(Message, that.Message) &&         
            Status.Equals(that.Status) &&         
            Object.Equals(Exception, that.Exception);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Duration.GetHashCode();
        hash = hash * 31 + Message?.GetHashCode()?? 0;
        hash = hash * 31 + Status.GetHashCode();
        hash = hash * 31 + Exception?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "TestStepResult{" +
            "duration=" + Duration +
            ", message=" + Message +
            ", status=" + Status +
            ", exception=" + Exception +
            '}';
    }
}
