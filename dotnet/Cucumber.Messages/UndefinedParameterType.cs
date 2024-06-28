using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the UndefinedParameterType message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class UndefinedParameterType 
{
    public string Expression { get; private set; }
    public string Name { get; private set; }


    public UndefinedParameterType(
        string expression,
        string name
    ) 
    {
              RequireNonNull<string>(expression, "Expression", "UndefinedParameterType.Expression cannot be null");
        this.Expression = expression;
              RequireNonNull<string>(name, "Name", "UndefinedParameterType.Name cannot be null");
        this.Name = name;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        UndefinedParameterType that = (UndefinedParameterType) o;
        return 
            Expression.Equals(that.Expression) &&         
            Name.Equals(that.Name);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Expression != null)
          hash = hash * 31 + Expression.GetHashCode();
        if (Name != null)
          hash = hash * 31 + Name.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "UndefinedParameterType{" +
            "expression=" + Expression +
            ", name=" + Name +
            '}';
    }

    private static T Require<T>(T property, string propertyName, string errorMessage)
    {
      RequireNonNull<T>(property, propertyName, errorMessage);
      return property;
    }
    private static void RequireNonNull<T>(T property, string propertyName, string errorMessage) 
    {
      if (property == null) throw new ArgumentNullException(propertyName, errorMessage);
    }
}
