using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TableRow message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A row in a table
 */
// Generated code
public sealed class TableRow {
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
        this.Location = location;
        this.Cells = cells;
        this.Id = id;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TableRow that = (TableRow) o;
        return 
            Location.Equals(that.Location) &&         
            Cells.Equals(that.Cells) &&         
            Id.Equals(that.Id);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Cells.GetHashCode();
        hash = hash * 31 + Id.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "TableRow{" +
            "location=" + Location +
            ", cells=" + Cells +
            ", id=" + Id +
            '}';
    }
}
