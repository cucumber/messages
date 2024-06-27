using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the TableCell message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A cell in a `TableRow`
 */
// Generated code
public sealed class TableCell {
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
        this.Location = location;
        this.Value = value;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        TableCell that = (TableCell) o;
        return 
            Location.Equals(that.Location) &&         
            Value.Equals(that.Value);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Value.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "TableCell{" +
            "location=" + Location +
            ", value=" + Value +
            '}';
    }
}
