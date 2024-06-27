using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TestRunFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class TestRunFinished {
    /**
     * An informative message about the test run. Typically additional information about failure, but not necessarily.
     */
    public string? Message { get; private set; }
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
    public Exception? Exception { get; private set; }

    public TestRunFinished(
        string message,
        bool success,
        Timestamp timestamp,
        Exception exception
    ) 
    {
        this.Message = message;
        this.Success = success;
        this.Timestamp = timestamp;
        this.Exception = exception;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestRunFinished that = (TestRunFinished) o;
        return 
            Object.Equals(Message, that.Message) &&         
            Success.Equals(that.Success) &&         
            Timestamp.Equals(that.Timestamp) &&         
            Object.Equals(Exception, that.Exception);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Message?.GetHashCode()?? 0;
        hash = hash * 31 + Success.GetHashCode();
        hash = hash * 31 + Timestamp.GetHashCode();
        hash = hash * 31 + Exception?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "TestRunFinished{" +
            "message=" + Message +
            ", success=" + Success +
            ", timestamp=" + Timestamp +
            ", exception=" + Exception +
            '}';
    }
}
