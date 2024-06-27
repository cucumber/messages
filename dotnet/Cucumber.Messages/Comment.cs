using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Comment message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * A comment in a Gherkin document
 */
// Generated code
public sealed class Comment {
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
        this.Location = location;
        this.Text = text;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Comment that = (Comment) o;
        return 
            Location.Equals(that.Location) &&         
            Text.Equals(that.Text);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Location.GetHashCode();
        hash = hash * 31 + Text.GetHashCode();
        return hash;
    }

    public override string ToString() {
        return "Comment{" +
            "location=" + Location +
            ", text=" + Text +
            '}';
    }
}
