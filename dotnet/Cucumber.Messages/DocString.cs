using System;
using System.Collections.Generic;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the DocString message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */
// Generated code
public sealed class DocString 
{
    public Location Location { get; private set; }
    public string MediaType { get; private set; }
    public string Content { get; private set; }
    public string Delimiter { get; private set; }


    public DocString(
        Location location,
        string mediaType,
        string content,
        string delimiter
    ) 
    {
              RequireNonNull<Location>(location, "Location", "DocString.Location cannot be null");
        this.Location = location;
              this.MediaType = mediaType;
              RequireNonNull<string>(content, "Content", "DocString.Content cannot be null");
        this.Content = content;
              RequireNonNull<string>(delimiter, "Delimiter", "DocString.Delimiter cannot be null");
        this.Delimiter = delimiter;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        DocString that = (DocString) o;
        return 
            Location.Equals(that.Location) &&         
            Object.Equals(MediaType, that.MediaType) &&         
            Content.Equals(that.Content) &&         
            Delimiter.Equals(that.Delimiter);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (MediaType != null)
          hash = hash * 31 + MediaType.GetHashCode();
        if (Content != null)
          hash = hash * 31 + Content.GetHashCode();
        if (Delimiter != null)
          hash = hash * 31 + Delimiter.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "DocString{" +
            "location=" + Location +
            ", mediaType=" + MediaType +
            ", content=" + Content +
            ", delimiter=" + Delimiter +
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
