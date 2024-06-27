using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TestCase message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * //// TestCases
 *
 * A `TestCase` contains a sequence of `TestStep`s.
 */
// Generated code
public sealed class TestCase {
    public string Id { get; private set; }
    /**
     * The ID of the `Pickle` this `TestCase` is derived from.
     */
    public string PickleId { get; private set; }
    public List<TestStep> TestSteps { get; private set; }

    public TestCase(
        string id,
        string pickleId,
        List<TestStep> testSteps
    ) 
    {
        this.Id = id;
        this.PickleId = pickleId;
        this.TestSteps = testSteps;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestCase that = (TestCase) o;
        return 
            Id.Equals(that.Id) &&         
            PickleId.Equals(that.PickleId) &&         
            TestSteps.Equals(that.TestSteps);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Id.GetHashCode();
        hash = hash * 31 + PickleId.GetHashCode();
        hash = hash * 31 + TestSteps.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "TestCase{" +
            "id=" + Id +
            ", pickleId=" + PickleId +
            ", testSteps=" + TestSteps +
            '}';
    }
}
