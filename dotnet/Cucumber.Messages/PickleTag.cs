using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the PickleTag message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A tag
 */
// Generated code
public sealed class PickleTag {
    public string Name { get; private set; };
    /**
     * Points to the AST node this was created from
     */
    public string AstNodeId { get; private set; };

    public PickleTag(
        string name,
        string astNodeId
    ) 
    {
        this.Name = name;
        this.AstNodeId = astNodeId;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleTag that = (PickleTag) o;
        return 
            Name.Equals(that.Name) &&         
            AstNodeId.Equals(that.AstNodeId);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Name.GetHashCode();
        hash = hash * 31 + AstNodeId.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "PickleTag{" +
            "name=" + Name +
            ", astNodeId=" + AstNodeId +
            '}';
    }
}
