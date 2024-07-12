using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the DataTable message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class DataTable 
{
    public Location Location { get; private set; }
    public List<TableRow> Rows { get; private set; }


    public DataTable(
        Location location,
        List<TableRow> rows
    ) 
    {
              RequireNonNull<Location>(location, "Location", "DataTable.Location cannot be null");
        this.Location = location;
              RequireNonNull<List<TableRow>>(rows, "Rows", "DataTable.Rows cannot be null");
        this.Rows = new List<TableRow>(rows);
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        DataTable that = (DataTable) o;
        return 
            Location.Equals(that.Location) &&         
            Rows.Equals(that.Rows);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Rows != null)
          hash = hash * 31 + Rows.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "DataTable{" +
            "location=" + Location +
            ", rows=" + Rows +
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
