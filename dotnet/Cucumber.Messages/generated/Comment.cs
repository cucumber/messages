
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

public sealed record Comment 
{
    /**
     * The location of the comment
     */
    public Location Location { get; }
    /**
     * The text of the comment
     */
    public string Text { get; }


    public Comment(
        Location location,
        string text
    ) 
    {
        this.Location = location ?? throw new ArgumentNullException("Location", "Comment.Location cannot be null");
        this.Text = text ?? throw new ArgumentNullException("Text", "Comment.Text cannot be null");
    }
}
