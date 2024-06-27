using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TestCaseFinished message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class TestCaseFinished {
    public string TestCaseStartedId { get; private set; }
    public Timestamp Timestamp { get; private set; }
    public bool WillBeRetried { get; private set; }

    public TestCaseFinished(
        string testCaseStartedId,
        Timestamp timestamp,
        bool willBeRetried
    ) 
    {
        this.TestCaseStartedId = testCaseStartedId;
        this.Timestamp = timestamp;
        this.WillBeRetried = willBeRetried;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestCaseFinished that = (TestCaseFinished) o;
        return 
            TestCaseStartedId.Equals(that.TestCaseStartedId) &&         
            Timestamp.Equals(that.Timestamp) &&         
            WillBeRetried.Equals(that.WillBeRetried);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + TestCaseStartedId.GetHashCode();
        hash = hash * 31 + Timestamp.GetHashCode();
        hash = hash * 31 + WillBeRetried.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "TestCaseFinished{" +
            "testCaseStartedId=" + TestCaseStartedId +
            ", timestamp=" + Timestamp +
            ", willBeRetried=" + WillBeRetried +
            '}';
    }
}
