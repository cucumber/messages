using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the PickleTableCell message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class PickleTableCell {
    public string Value { get; private set; }

    public PickleTableCell(
        string value
    ) 
    {
        this.Value = value;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleTableCell that = (PickleTableCell) o;
        return 
            Value.Equals(that.Value);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Value.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "PickleTableCell{" +
            "value=" + Value +
            '}';
    }
}
