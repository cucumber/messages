using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the PickleTable message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class PickleTable {
    public List<PickleTableRow> Rows { get; private set; }

    public PickleTable(
        List<PickleTableRow> rows
    ) 
    {
        this.Rows = rows;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleTable that = (PickleTable) o;
        return 
            Rows.Equals(that.Rows);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Rows.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "PickleTable{" +
            "rows=" + Rows +
            '}';
    }
}
