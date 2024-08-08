using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the SourceReference message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
 * [Location](#io.cucumber.messages.Location) within that file.
 */

public sealed class SourceReference 
{
    public string Uri { get; private set; }
    public JavaMethod JavaMethod { get; private set; }
    public JavaStackTraceElement JavaStackTraceElement { get; private set; }
    public Location Location { get; private set; }


    public static SourceReference Create(string uri) 
    {
        return new SourceReference(
            Require<string>(uri, "Uri", "SourceReference.Uri cannot be null"),
            null,
            null,
            null
        );
    }

    public static SourceReference Create(JavaMethod javaMethod) 
    {
        return new SourceReference(
            null,
            Require<JavaMethod>(javaMethod, "JavaMethod", "SourceReference.JavaMethod cannot be null"),
            null,
            null
        );
    }

    public static SourceReference Create(JavaStackTraceElement javaStackTraceElement) 
    {
        return new SourceReference(
            null,
            null,
            Require<JavaStackTraceElement>(javaStackTraceElement, "JavaStackTraceElement", "SourceReference.JavaStackTraceElement cannot be null"),
            null
        );
    }

    public static SourceReference Create(Location location) 
    {
        return new SourceReference(
            null,
            null,
            null,
            Require<Location>(location, "Location", "SourceReference.Location cannot be null")
        );
    }

    public SourceReference(
        string uri,
        JavaMethod javaMethod,
        JavaStackTraceElement javaStackTraceElement,
        Location location
    ) 
    {
              this.Uri = uri;
              this.JavaMethod = javaMethod;
              this.JavaStackTraceElement = javaStackTraceElement;
              this.Location = location;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        SourceReference that = (SourceReference) o;
        return 
            Object.Equals(Uri, that.Uri) &&         
            Object.Equals(JavaMethod, that.JavaMethod) &&         
            Object.Equals(JavaStackTraceElement, that.JavaStackTraceElement) &&         
            Object.Equals(Location, that.Location);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Uri != null)
          hash = hash * 31 + Uri.GetHashCode();
        if (JavaMethod != null)
          hash = hash * 31 + JavaMethod.GetHashCode();
        if (JavaStackTraceElement != null)
          hash = hash * 31 + JavaStackTraceElement.GetHashCode();
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "SourceReference{" +
            "uri=" + Uri +
            ", javaMethod=" + JavaMethod +
            ", javaStackTraceElement=" + JavaStackTraceElement +
            ", location=" + Location +
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
