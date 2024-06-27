using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TestStepStarted message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class TestStepStarted {
    public string TestCaseStartedId { get; private set; }
    public string TestStepId { get; private set; }
    public Timestamp Timestamp { get; private set; }

    public TestStepStarted(
        string testCaseStartedId,
        string testStepId,
        Timestamp timestamp
    ) 
    {
        this.TestCaseStartedId = testCaseStartedId;
        this.TestStepId = testStepId;
        this.Timestamp = timestamp;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestStepStarted that = (TestStepStarted) o;
        return 
            TestCaseStartedId.Equals(that.TestCaseStartedId) &&         
            TestStepId.Equals(that.TestStepId) &&         
            Timestamp.Equals(that.Timestamp);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + TestCaseStartedId.GetHashCode();
        hash = hash * 31 + TestStepId.GetHashCode();
        hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "TestStepStarted{" +
            "testCaseStartedId=" + TestCaseStartedId +
            ", testStepId=" + TestStepId +
            ", timestamp=" + Timestamp +
            '}';
    }
}
