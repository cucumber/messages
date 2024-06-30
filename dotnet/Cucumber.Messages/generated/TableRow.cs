using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the TableRow message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A row in a table
 */
// Generated code
public sealed class TableRow 
{
    /**
     * The location of the first cell in the row
     */
    public Location Location { get; private set; }
    /**
     * Cells in the row
     */
    public List<TableCell> Cells { get; private set; }
    public string Id { get; private set; }


    public TableRow(
        Location location,
        List<TableCell> cells,
        string id
    ) 
    {
              RequireNonNull<Location>(location, "Location", "TableRow.Location cannot be null");
        this.Location = location;
              RequireNonNull<List<TableCell>>(cells, "Cells", "TableRow.Cells cannot be null");
        this.Cells = new List<TableCell>(cells);
              RequireNonNull<string>(id, "Id", "TableRow.Id cannot be null");
        this.Id = id;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TableRow that = (TableRow) o;
        return 
            Location.Equals(that.Location) &&         
            Cells.Equals(that.Cells) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Cells != null)
          hash = hash * 31 + Cells.GetHashCode();
        if (Id != null)
          hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "TableRow{" +
            "location=" + Location +
            ", cells=" + Cells +
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
