using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the UndefinedParameterType message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class UndefinedParameterType {
    public string Expression { get; private set; }
    public string Name { get; private set; }

    public UndefinedParameterType(
        string expression,
        string name
    ) 
    {
        this.Expression = expression;
        this.Name = name;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        UndefinedParameterType that = (UndefinedParameterType) o;
        return 
            Expression.Equals(that.Expression) &&         
            Name.Equals(that.Name);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Expression.GetHashCode();
        hash = hash * 31 + Name.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "UndefinedParameterType{" +
            "expression=" + Expression +
            ", name=" + Name +
            '}';
    }
}
