using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TestStepFinished message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class TestStepFinished {
    public string TestCaseStartedId { get; private set; }
    public string TestStepId { get; private set; }
    public TestStepResult TestStepResult { get; private set; }
    public Timestamp Timestamp { get; private set; }

    public TestStepFinished(
        string testCaseStartedId,
        string testStepId,
        TestStepResult testStepResult,
        Timestamp timestamp
    ) 
    {
        this.TestCaseStartedId = testCaseStartedId;
        this.TestStepId = testStepId;
        this.TestStepResult = testStepResult;
        this.Timestamp = timestamp;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestStepFinished that = (TestStepFinished) o;
        return 
            TestCaseStartedId.Equals(that.TestCaseStartedId) &&         
            TestStepId.Equals(that.TestStepId) &&         
            TestStepResult.Equals(that.TestStepResult) &&         
            Timestamp.Equals(that.Timestamp);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + TestCaseStartedId.GetHashCode();
        hash = hash * 31 + TestStepId.GetHashCode();
        hash = hash * 31 + TestStepResult.GetHashCode();
        hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "TestStepFinished{" +
            "testCaseStartedId=" + TestCaseStartedId +
            ", testStepId=" + TestStepId +
            ", testStepResult=" + TestStepResult +
            ", timestamp=" + Timestamp +
            '}';
    }
}
