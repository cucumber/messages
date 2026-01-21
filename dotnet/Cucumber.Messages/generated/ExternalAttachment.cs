using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the ExternalAttachment message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * Represents an attachment that is stored externally rather than embedded in the message stream.
 *
 * This message type is used for large attachments (e.g., video files) that are already
 * on the filesystem and should not be loaded into memory. Instead of embedding the content,
 * only a URL reference is stored.
 *
 * A formatter or other consumer of messages may replace an Attachment with an ExternalAttachment if it makes sense to do so.
 */

public sealed class ExternalAttachment 
{
    /**
     * A URL where the attachment can be retrieved. This could be a file:// URL for
     * local filesystem paths, or an http(s):// URL for remote resources.
     */
    public string Url { get; private set; }
    /**
     * The media type of the data. This can be any valid
     * [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
     * as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
     * and `text/x.cucumber.stacktrace+plain`
     */
    public string MediaType { get; private set; }
    /**
     * The identifier of the test step if the attachment was created during the execution of a test step
     */
    public string TestStepId { get; private set; }
    /**
     * The identifier of the test case attempt if the attachment was created during the execution of a test step
     */
    public string TestCaseStartedId { get; private set; }
    /**
     * The identifier of the test run hook execution if the attachment was created during the execution of a test run hook
     */
    public string TestRunHookStartedId { get; private set; }
    /**
     * When the attachment was created
     */
    public Timestamp Timestamp { get; private set; }


    public ExternalAttachment(
        string url,
        string mediaType,
        string testStepId,
        string testCaseStartedId,
        string testRunHookStartedId,
        Timestamp timestamp
    ) 
    {
        RequireNonNull<string>(url, "Url", "ExternalAttachment.Url cannot be null");
        this.Url = url;
        RequireNonNull<string>(mediaType, "MediaType", "ExternalAttachment.MediaType cannot be null");
        this.MediaType = mediaType;
        this.TestStepId = testStepId;
        this.TestCaseStartedId = testCaseStartedId;
        this.TestRunHookStartedId = testRunHookStartedId;
        this.Timestamp = timestamp;
    }

    public override bool Equals(Object o) 
    {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        ExternalAttachment that = (ExternalAttachment) o;
        return 
            Url.Equals(that.Url) &&         
            MediaType.Equals(that.MediaType) &&         
            Object.Equals(TestStepId, that.TestStepId) &&         
            Object.Equals(TestCaseStartedId, that.TestCaseStartedId) &&         
            Object.Equals(TestRunHookStartedId, that.TestRunHookStartedId) &&         
            Object.Equals(Timestamp, that.Timestamp);        
    }

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Url != null)
          hash = hash * 31 + Url.GetHashCode();
        if (MediaType != null)
          hash = hash * 31 + MediaType.GetHashCode();
        if (TestStepId != null)
          hash = hash * 31 + TestStepId.GetHashCode();
        if (TestCaseStartedId != null)
          hash = hash * 31 + TestCaseStartedId.GetHashCode();
        if (TestRunHookStartedId != null)
          hash = hash * 31 + TestRunHookStartedId.GetHashCode();
        if (Timestamp != null)
          hash = hash * 31 + Timestamp.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
        return "ExternalAttachment{" +
            "url=" + Url +
            ", mediaType=" + MediaType +
            ", testStepId=" + TestStepId +
            ", testCaseStartedId=" + TestCaseStartedId +
            ", testRunHookStartedId=" + TestRunHookStartedId +
            ", timestamp=" + Timestamp +
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
