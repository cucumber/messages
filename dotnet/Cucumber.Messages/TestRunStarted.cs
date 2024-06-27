using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TestRunStarted message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class TestRunStarted {
    public Timestamp Timestamp { get; private set; }

    public TestRunStarted(
        Timestamp timestamp
    ) 
    {
        this.Timestamp = timestamp;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestRunStarted that = (TestRunStarted) o;
        return 
            Timestamp.Equals(that.Timestamp);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "TestRunStarted{" +
            "timestamp=" + Timestamp +
            '}';
    }
}
