using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleStepArgument message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * An optional argument
 */

public sealed class PickleStepArgument 
{
    public PickleDocString DocString { get; private set; }
    public PickleTable DataTable { get; private set; }


    public static PickleStepArgument Create(PickleDocString docString) 
    {
        return new PickleStepArgument(
            Require<PickleDocString>(docString, "DocString", "PickleStepArgument.DocString cannot be null"),
            null
        );
    }

    public static PickleStepArgument Create(PickleTable dataTable) 
    {
        return new PickleStepArgument(
            null,
            Require<PickleTable>(dataTable, "DataTable", "PickleStepArgument.DataTable cannot be null")
        );
    }

    public PickleStepArgument(
        PickleDocString docString,
        PickleTable dataTable
    ) 
    {
              this.DocString = docString;
              this.DataTable = dataTable;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleStepArgument that = (PickleStepArgument) o;
        return 
            Object.Equals(DocString, that.DocString) &&         
            Object.Equals(DataTable, that.DataTable);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (DocString != null)
          hash = hash * 31 + DocString.GetHashCode();
        if (DataTable != null)
          hash = hash * 31 + DataTable.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "PickleStepArgument{" +
            "docString=" + DocString +
            ", dataTable=" + DataTable +
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
