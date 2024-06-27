using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the JavaStackTraceElement message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class JavaStackTraceElement {
    public string ClassName { get; private set; }
    public string FileName { get; private set; }
    public string MethodName { get; private set; }

    public JavaStackTraceElement(
        string className,
        string fileName,
        string methodName
    ) 
    {
        this.ClassName = className;
        this.FileName = fileName;
        this.MethodName = methodName;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        JavaStackTraceElement that = (JavaStackTraceElement) o;
        return 
            ClassName.Equals(that.ClassName) &&         
            FileName.Equals(that.FileName) &&         
            MethodName.Equals(that.MethodName);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + ClassName.GetHashCode();
        hash = hash * 31 + FileName.GetHashCode();
        hash = hash * 31 + MethodName.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "JavaStackTraceElement{" +
            "className=" + ClassName +
            ", fileName=" + FileName +
            ", methodName=" + MethodName +
            '}';
    }
}
