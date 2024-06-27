using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the PickleStepArgument message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * An optional argument
 */
// Generated code
public sealed class PickleStepArgument {
    public PickleDocString? DocString { get; private set; }
    public PickleTable? DataTable { get; private set; }

    public static PickleStepArgument Create(PickleDocString docString) {
        return new PickleStepArgument(
            docString,
            null
        );
    }

    public static PickleStepArgument Create(PickleTable dataTable) {
        return new PickleStepArgument(
            null,
            dataTable
        );
    }

    public PickleStepArgument(
        PickleDocString docString,
        PickleTable dataTable
    ) 
    {
        this.DocString = docString;
        this.DataTable = dataTable;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleStepArgument that = (PickleStepArgument) o;
        return 
            Object.Equals(DocString, that.DocString) &&         
            Object.Equals(DataTable, that.DataTable);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + DocString?.GetHashCode()?? 0;
        hash = hash * 31 + DataTable?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "PickleStepArgument{" +
            "docString=" + DocString +
            ", dataTable=" + DataTable +
            '}';
    }
}
