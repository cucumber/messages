using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Comment message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A comment in a Gherkin document
 */

public sealed class Comment 
{
    /**
     * The location of the comment
     */
    public Location Location { get; private set; }
    /**
     * The text of the comment
     */
    public string Text { get; private set; }


    public Comment(
        Location location,
        string text
    ) 
    {
              RequireNonNull<Location>(location, "Location", "Comment.Location cannot be null");
        this.Location = location;
              RequireNonNull<string>(text, "Text", "Comment.Text cannot be null");
        this.Text = text;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Comment that = (Comment) o;
        return 
            Location.Equals(that.Location) &&         
            Text.Equals(that.Text);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Location != null)
          hash = hash * 31 + Location.GetHashCode();
        if (Text != null)
          hash = hash * 31 + Text.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "Comment{" +
            "location=" + Location +
            ", text=" + Text +
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
