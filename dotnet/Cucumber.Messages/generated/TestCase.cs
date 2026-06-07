using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestCase message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A `TestCase` contains a sequence of `TestStep`s.
 */

public sealed class TestCase 
{
    public string Id { get; private set; }
    /**
     * The ID of the `Pickle` this `TestCase` is derived from.
     */
    public string PickleId { get; private set; }
    public List<TestStep> TestSteps { get; private set; }
    /**
     * Identifier for the test run that this test case belongs to
     */
    public string TestRunStartedId { get; private set; }


    public TestCase(
        string id,
        string pickleId,
        List<TestStep> testSteps,
        string testRunStartedId
    ) 
    {
        RequireNonNull<string>(id, "Id", "TestCase.Id cannot be null");
        this.Id = id;
        RequireNonNull<string>(pickleId, "PickleId", "TestCase.PickleId cannot be null");
        this.PickleId = pickleId;
        RequireNonNull<List<TestStep>>(testSteps, "TestSteps", "TestCase.TestSteps cannot be null");
        this.TestSteps = new List<TestStep>(testSteps);        
        this.TestRunStartedId = testRunStartedId;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestCase that = (TestCase) o;
        return 
            Id.Equals(that.Id) &&         
            PickleId.Equals(that.PickleId) &&         
            TestSteps.Equals(that.TestSteps) &&         
            Object.Equals(TestRunStartedId, that.TestRunStartedId);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        if (PickleId != null)
          hash = hash * 31 + PickleId.GetHashCode();
        if (TestSteps != null)
          hash = hash * 31 + TestSteps.GetHashCode();
        if (TestRunStartedId != null)
          hash = hash * 31 + TestRunStartedId.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestCase{" +
            "id=" + Id +
            ", pickleId=" + PickleId +
            ", testSteps=" + TestSteps +
            ", testRunStartedId=" + TestRunStartedId +
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
