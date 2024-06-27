using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the PickleDocString message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class PickleDocString {
    public string? MediaType { get; private set; }
    public string Content { get; private set; }

    public PickleDocString(
        string mediaType,
        string content
    ) 
    {
        this.MediaType = mediaType;
        this.Content = content;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleDocString that = (PickleDocString) o;
        return 
            Object.Equals(MediaType, that.MediaType) &&         
            Content.Equals(that.Content);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + MediaType?.GetHashCode()?? 0;
        hash = hash * 31 + Content.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "PickleDocString{" +
            "mediaType=" + MediaType +
            ", content=" + Content +
            '}';
    }
}
