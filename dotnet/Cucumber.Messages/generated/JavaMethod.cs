using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the JavaMethod message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class JavaMethod 
{
    public string ClassName { get; private set; }
    public string MethodName { get; private set; }
    public List<string> MethodParameterTypes { get; private set; }


    public JavaMethod(
        string className,
        string methodName,
        List<string> methodParameterTypes
    ) 
    {
        RequireNonNull<string>(className, "ClassName", "JavaMethod.ClassName cannot be null");
        this.ClassName = className;
        RequireNonNull<string>(methodName, "MethodName", "JavaMethod.MethodName cannot be null");
        this.MethodName = methodName;
        RequireNonNull<List<string>>(methodParameterTypes, "MethodParameterTypes", "JavaMethod.MethodParameterTypes cannot be null");
        this.MethodParameterTypes = new List<string>(methodParameterTypes);        
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        JavaMethod that = (JavaMethod) o;
        return 
            ClassName.Equals(that.ClassName) &&         
            MethodName.Equals(that.MethodName) &&         
            MethodParameterTypes.Equals(that.MethodParameterTypes);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (ClassName != null)
          hash = hash * 31 + ClassName.GetHashCode();
        if (MethodName != null)
          hash = hash * 31 + MethodName.GetHashCode();
        if (MethodParameterTypes != null)
          hash = hash * 31 + MethodParameterTypes.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "JavaMethod{" +
            "className=" + ClassName +
            ", methodName=" + MethodName +
            ", methodParameterTypes=" + MethodParameterTypes +
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
