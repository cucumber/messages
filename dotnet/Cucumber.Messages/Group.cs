using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Group message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class Group {
    public List<Group> Children { get; private set; };
    public long? Start { get; private set; };
    public string? Value { get; private set; };

    public Group(
        List<Group> children,
        long start,
        string value
    ) 
    {
        this.Children = children;
        this.Start = start;
        this.Value = value;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Group that = (Group) o;
        return 
            Children.Equals(that.Children) &&         
            Object.Equals(Start, that.Start) &&         
            Object.Equals(Value, that.Value);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Children.GetHashCode();
        hash = hash * 31 + Start?.GetHashCode()?? 0;
        hash = hash * 31 + Value?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Group{" +
            "children=" + Children +
            ", start=" + Start +
            ", value=" + Value +
            '}';
    }
}
