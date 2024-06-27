using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the ParseError message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class ParseError {
    public SourceReference Source { get; private set; }
    public string Message { get; private set; }

    public ParseError(
        SourceReference source,
        string message
    ) 
    {
        this.Source = source;
        this.Message = message;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        ParseError that = (ParseError) o;
        return 
            Source.Equals(that.Source) &&         
            Message.Equals(that.Message);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Source.GetHashCode();
        hash = hash * 31 + Message.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "ParseError{" +
            "source=" + Source +
            ", message=" + Message +
            '}';
    }
}
