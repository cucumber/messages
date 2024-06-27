using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the SourceReference message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
 * [Location](#io.cucumber.messages.Location) within that file.
 */
// Generated code
public sealed class SourceReference {
    public string? Uri { get; private set; }
    public JavaMethod? JavaMethod { get; private set; }
    public JavaStackTraceElement? JavaStackTraceElement { get; private set; }
    public Location? Location { get; private set; }

    public static SourceReference Create(string uri) {
        return new SourceReference(
            uri,
            null,
            null,
            null
        );
    }

    public static SourceReference Create(JavaMethod javaMethod) {
        return new SourceReference(
            null,
            javaMethod,
            null,
            null
        );
    }

    public static SourceReference Create(JavaStackTraceElement javaStackTraceElement) {
        return new SourceReference(
            null,
            null,
            javaStackTraceElement,
            null
        );
    }

    public static SourceReference Create(Location location) {
        return new SourceReference(
            null,
            null,
            null,
            location
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

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        SourceReference that = (SourceReference) o;
        return 
            Object.Equals(Uri, that.Uri) &&         
            Object.Equals(JavaMethod, that.JavaMethod) &&         
            Object.Equals(JavaStackTraceElement, that.JavaStackTraceElement) &&         
            Object.Equals(Location, that.Location);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Uri?.GetHashCode()?? 0;
        hash = hash * 31 + JavaMethod?.GetHashCode()?? 0;
        hash = hash * 31 + JavaStackTraceElement?.GetHashCode()?? 0;
        hash = hash * 31 + Location?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "SourceReference{" +
            "uri=" + Uri +
            ", javaMethod=" + JavaMethod +
            ", javaStackTraceElement=" + JavaStackTraceElement +
            ", location=" + Location +
            '}';
    }
}
