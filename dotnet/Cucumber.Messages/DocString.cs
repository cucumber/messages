using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the DocString message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class DocString {
    public Location Location { get; private set; }
    public string? MediaType { get; private set; }
    public string Content { get; private set; }
    public string Delimiter { get; private set; }

    public DocString(
        Location location,
        string mediaType,
        string content,
        string delimiter
    ) 
    {
        this.Location = location;
        this.MediaType = mediaType;
        this.Content = content;
        this.Delimiter = delimiter;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        DocString that = (DocString) o;
        return 
            Location.Equals(that.Location) &&         
            Object.Equals(MediaType, that.MediaType) &&         
            Content.Equals(that.Content) &&         
            Delimiter.Equals(that.Delimiter);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + MediaType?.GetHashCode()?? 0;
        hash = hash * 31 + Content.GetHashCode();
        hash = hash * 31 + Delimiter.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "DocString{" +
            "location=" + Location +
            ", mediaType=" + MediaType +
            ", content=" + Content +
            ", delimiter=" + Delimiter +
            '}';
    }
}
