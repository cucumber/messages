using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the PickleTableRow message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class PickleTableRow {
    public List<PickleTableCell> Cells { get; private set; };

    public PickleTableRow(
        List<PickleTableCell> cells
    ) 
    {
        this.Cells = cells;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleTableRow that = (PickleTableRow) o;
        return 
            Cells.Equals(that.Cells);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Cells.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "PickleTableRow{" +
            "cells=" + Cells +
            '}';
    }
}
