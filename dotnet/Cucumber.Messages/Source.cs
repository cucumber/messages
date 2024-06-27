using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Source message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * //// Source
 *
 * A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
 */
// Generated code
public sealed class Source {
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
        this.Uri = uri;
        this.Data = data;
        this.MediaType = mediaType;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Source that = (Source) o;
        return 
            Uri.Equals(that.Uri) &&         
            Data.Equals(that.Data) &&         
            MediaType.Equals(that.MediaType);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Uri.GetHashCode();
        hash = hash * 31 + Data.GetHashCode();
        hash = hash * 31 + MediaType.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "Source{" +
            "uri=" + Uri +
            ", data=" + Data +
            ", mediaType=" + MediaType +
            '}';
    }
}
