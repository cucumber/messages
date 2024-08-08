using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the JavaStackTraceElement message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class JavaStackTraceElement 
{
    public string ClassName { get; private set; }
    public string FileName { get; private set; }
    public string MethodName { get; private set; }


    public JavaStackTraceElement(
        string className,
        string fileName,
        string methodName
    ) 
    {
              RequireNonNull<string>(className, "ClassName", "JavaStackTraceElement.ClassName cannot be null");
        this.ClassName = className;
              RequireNonNull<string>(fileName, "FileName", "JavaStackTraceElement.FileName cannot be null");
        this.FileName = fileName;
              RequireNonNull<string>(methodName, "MethodName", "JavaStackTraceElement.MethodName cannot be null");
        this.MethodName = methodName;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        JavaStackTraceElement that = (JavaStackTraceElement) o;
        return 
            ClassName.Equals(that.ClassName) &&         
            FileName.Equals(that.FileName) &&         
            MethodName.Equals(that.MethodName);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (ClassName != null)
          hash = hash * 31 + ClassName.GetHashCode();
        if (FileName != null)
          hash = hash * 31 + FileName.GetHashCode();
        if (MethodName != null)
          hash = hash * 31 + MethodName.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "JavaStackTraceElement{" +
            "className=" + ClassName +
            ", fileName=" + FileName +
            ", methodName=" + MethodName +
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
