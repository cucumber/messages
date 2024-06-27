using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Hook message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class Hook {
    public string Id { get; private set; };
    public string? Name { get; private set; };
    public SourceReference SourceReference { get; private set; };
    public string? TagExpression { get; private set; };

    public Hook(
        string id,
        string name,
        SourceReference sourceReference,
        string tagExpression
    ) 
    {
        this.Id = id;
        this.Name = name;
        this.SourceReference = sourceReference;
        this.TagExpression = tagExpression;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Hook that = (Hook) o;
        return 
            Id.Equals(that.Id) &&         
            Object.Equals(Name, that.Name) &&         
            SourceReference.Equals(that.SourceReference) &&         
            Object.Equals(TagExpression, that.TagExpression);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Id.GetHashCode();
        hash = hash * 31 + Name?.GetHashCode()?? 0;
        hash = hash * 31 + SourceReference.GetHashCode();
        hash = hash * 31 + TagExpression?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Hook{" +
            "id=" + Id +
            ", name=" + Name +
            ", sourceReference=" + SourceReference +
            ", tagExpression=" + TagExpression +
            '}';
    }
}
