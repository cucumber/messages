using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the JavaMethod message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class JavaMethod {
    public string ClassName { get; private set; };
    public string MethodName { get; private set; };
    public List<string> MethodParameterTypes { get; private set; };

    public JavaMethod(
        string className,
        string methodName,
        List<string> methodParameterTypes
    ) 
    {
        this.ClassName = className;
        this.MethodName = methodName;
        this.MethodParameterTypes = methodParameterTypes;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        JavaMethod that = (JavaMethod) o;
        return 
            ClassName.Equals(that.ClassName) &&         
            MethodName.Equals(that.MethodName) &&         
            MethodParameterTypes.Equals(that.MethodParameterTypes);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + ClassName.GetHashCode();
        hash = hash * 31 + MethodName.GetHashCode();
        hash = hash * 31 + MethodParameterTypes.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "JavaMethod{" +
            "className=" + ClassName +
            ", methodName=" + MethodName +
            ", methodParameterTypes=" + MethodParameterTypes +
            '}';
    }
}
