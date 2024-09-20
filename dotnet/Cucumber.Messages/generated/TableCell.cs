using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TableCell message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A cell in a `TableRow`
 */

public sealed class TableCell 
{
    /**
     * The location of the cell
     */
    public Location Location { get; private set; }
    /**
     * The value of the cell
     */
    public string Value { get; private set; }


    public TableCell(
        Location location,
        string value
    ) 
    {
        RequireNonNull<Location>(location, "Location", "TableCell.Location cannot be null");
        this.Location = location;
        RequireNonNull<string>(value, "Value", "TableCell.Value cannot be null");
        this.Value = value;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TableCell that = (TableCell) o;
        return 
            Location.Equals(that.Location) &&         
            Value.Equals(that.Value);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Value != null)
          hash = hash * 31 + Value.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TableCell{" +
            "location=" + Location +
            ", value=" + Value +
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
