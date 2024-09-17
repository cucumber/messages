
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the SourceReference message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
 * [Location](#io.cucumber.messages.Location) within that file.
 */

public sealed record SourceReference 
{
    public string? Uri { get; }
    public JavaMethod? JavaMethod { get; }
    public JavaStackTraceElement? JavaStackTraceElement { get; }
    public Location? Location { get; }


    public static SourceReference Create(string uri) 
    {
        return new SourceReference(
            uri ?? throw new ArgumentNullException("Uri", "SourceReference.Uri cannot be null"),
            null,
            null,
            null
        );
    }

    public static SourceReference Create(JavaMethod javaMethod) 
    {
        return new SourceReference(
            null,
            javaMethod ?? throw new ArgumentNullException("JavaMethod", "SourceReference.JavaMethod cannot be null"),
            null,
            null
        );
    }

    public static SourceReference Create(JavaStackTraceElement javaStackTraceElement) 
    {
        return new SourceReference(
            null,
            null,
            javaStackTraceElement ?? throw new ArgumentNullException("JavaStackTraceElement", "SourceReference.JavaStackTraceElement cannot be null"),
            null
        );
    }

    public static SourceReference Create(Location location) 
    {
        return new SourceReference(
            null,
            null,
            null,
            location ?? throw new ArgumentNullException("Location", "SourceReference.Location cannot be null")
        );
    }

    public SourceReference(
        string? uri,
        JavaMethod? javaMethod,
        JavaStackTraceElement? javaStackTraceElement,
        Location? location
    ) 
    {
        Uri = uri;
        JavaMethod = javaMethod;
        JavaStackTraceElement = javaStackTraceElement;
        Location = location;
    }
}
