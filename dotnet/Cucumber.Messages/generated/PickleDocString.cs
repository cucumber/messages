using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the PickleDocString message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 */

public sealed class PickleDocString 
{
    public Nullable<long> ArgumentIndex { get; private set; }
    public string MediaType { get; private set; }
    public string Content { get; private set; }


    public PickleDocString(
        Nullable<long> argumentIndex,
        string mediaType,
        string content
    ) 
    {
        this.ArgumentIndex = argumentIndex;
        this.MediaType = mediaType;
        RequireNonNull<string>(content, "Content", "PickleDocString.Content cannot be null");
        this.Content = content;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        PickleDocString that = (PickleDocString) o;
        return 
            Object.Equals(ArgumentIndex, that.ArgumentIndex) &&         
            Object.Equals(MediaType, that.MediaType) &&         
            Content.Equals(that.Content);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (ArgumentIndex.HasValue)
          hash = hash * 31 + ArgumentIndex.Value.GetHashCode();
        if (MediaType != null)
          hash = hash * 31 + MediaType.GetHashCode();
        if (Content != null)
          hash = hash * 31 + Content.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "PickleDocString{" +
            (ArgumentIndex.HasValue ? "argumentIndex=" + ArgumentIndex.Value : "") +
            ", mediaType=" + MediaType +
            ", content=" + Content +
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
