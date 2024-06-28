using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Source message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * //// Source
 *
 * A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
 */
// Generated code
public sealed class Source 
{
    /**
     * The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
     * of the source, typically a file path relative to the root directory
     */
    public string Uri { get; private set; }
    /**
     * The contents of the file
     */
    public string Data { get; private set; }
    /**
     * The media type of the file. Can be used to specify custom types, such as
     * text/x.cucumber.gherkin+plain
     */
    public SourceMediaType MediaType { get; private set; }


    public Source(
        string uri,
        string data,
        SourceMediaType mediaType
    ) 
    {
              RequireNonNull<string>(uri, "Uri", "Source.Uri cannot be null");
        this.Uri = uri;
              RequireNonNull<string>(data, "Data", "Source.Data cannot be null");
        this.Data = data;
              RequireNonNull<SourceMediaType>(mediaType, "MediaType", "Source.MediaType cannot be null");
        this.MediaType = mediaType;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Source that = (Source) o;
        return 
            Uri.Equals(that.Uri) &&         
            Data.Equals(that.Data) &&         
            MediaType.Equals(that.MediaType);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Uri != null)
          hash = hash * 31 + Uri.GetHashCode();
        if (Data != null)
          hash = hash * 31 + Data.GetHashCode();
        if (MediaType != null)
          hash = hash * 31 + MediaType.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Source{" +
            "uri=" + Uri +
            ", data=" + Data +
            ", mediaType=" + MediaType +
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
