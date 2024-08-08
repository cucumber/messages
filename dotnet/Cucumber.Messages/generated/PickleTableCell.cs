using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleTableCell message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class PickleTableCell 
{
    public string Value { get; private set; }


    public PickleTableCell(
        string value
    ) 
    {
              RequireNonNull<string>(value, "Value", "PickleTableCell.Value cannot be null");
        this.Value = value;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleTableCell that = (PickleTableCell) o;
        return 
            Value.Equals(that.Value);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Value != null)
          hash = hash * 31 + Value.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "PickleTableCell{" +
            "value=" + Value +
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
