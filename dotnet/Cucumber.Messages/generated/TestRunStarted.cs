using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TestRunStarted message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class TestRunStarted 
{
    public Timestamp Timestamp { get; private set; }
    public string Id { get; private set; }


    public TestRunStarted(
        Timestamp timestamp,
        string id
    ) 
    {
        RequireNonNull<Timestamp>(timestamp, "Timestamp", "TestRunStarted.Timestamp cannot be null");
        this.Timestamp = timestamp;
        this.Id = id;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TestRunStarted that = (TestRunStarted) o;
        return 
            Timestamp.Equals(that.Timestamp) &&         
            Object.Equals(Id, that.Id);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TestRunStarted{" +
            "timestamp=" + Timestamp +
            ", id=" + Id +
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
