using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the DataTable message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class DataTable {
    public Location Location { get; private set; };
    public List<TableRow> Rows { get; private set; };

    public DataTable(
        Location location,
        List<TableRow> rows
    ) 
    {
        this.Location = location;
        this.Rows = rows;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        DataTable that = (DataTable) o;
        return 
            Location.Equals(that.Location) &&         
            Rows.Equals(that.Rows);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Rows.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "DataTable{" +
            "location=" + Location +
            ", rows=" + Rows +
            '}';
    }
}
