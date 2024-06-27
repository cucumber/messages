using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Location message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * Points to a line and a column in a text file
 */
// Generated code
public sealed class Location {
    public long Line { get; private set; }
    public long? Column { get; private set; }

    public Location(
        long line,
        long column
    ) 
    {
        this.Line = line;
        this.Column = column;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Location that = (Location) o;
        return 
            Line.Equals(that.Line) &&         
            Object.Equals(Column, that.Column);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Line.GetHashCode();
        hash = hash * 31 + Column?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Location{" +
            "line=" + Line +
            ", column=" + Column +
            '}';
    }
}
