using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Attachment message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * //// Attachments (parse errors, execution errors, screenshots, links...)
 *
 * An attachment represents any kind of data associated with a line in a
 * [Source](#io.cucumber.messages.Source) file. It can be used for:
 *
 * * Syntax errors during parse time
 * * Screenshots captured and attached during execution
 * * Logs captured and attached during execution
 *
 * It is not to be used for runtime errors raised/thrown during execution. This
 * is captured in `TestResult`.
 */
// Generated code
public sealed class Attachment {
    /**
     * The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
     * is simply the string. If it's `BASE64`, the string should be Base64 decoded to
     * obtain the attachment.
     */
    public string Body { get; private set; }
    /**
     * Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).
     *
     * Content encoding is *not* determined by the media type, but rather by the type
     * of the object being attached:
     *
     * - string: IDENTITY
     * - byte array: BASE64
     * - stream: BASE64
     */
    public AttachmentContentEncoding ContentEncoding { get; private set; }
    /**
     * Suggested file name of the attachment. (Provided by the user as an argument to `attach`)
     */
    public string? FileName { get; private set; }
    /**
     * The media type of the data. This can be any valid
     * [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
     * as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
     * and `text/x.cucumber.stacktrace+plain`
     */
    public string MediaType { get; private set; }
    public Source? Source { get; private set; }
    public string? TestCaseStartedId { get; private set; }
    public string? TestStepId { get; private set; }
    /**
     * A URL where the attachment can be retrieved. This field should not be set by Cucumber.
     * It should be set by a program that reads a message stream and does the following for
     * each Attachment message:
     *
     * - Writes the body (after base64 decoding if necessary) to a new file.
     * - Sets `body` and `contentEncoding` to `null`
     * - Writes out the new attachment message
     *
     * This will result in a smaller message stream, which can improve performance and
     * reduce bandwidth of message consumers. It also makes it easier to process and download attachments
     * separately from reports.
     */
    public string? Url { get; private set; }

    public Attachment(
        string body,
        AttachmentContentEncoding contentEncoding,
        string fileName,
        string mediaType,
        Source source,
        string testCaseStartedId,
        string testStepId,
        string url
    ) 
    {
        this.Body = body;
        this.ContentEncoding = contentEncoding;
        this.FileName = fileName;
        this.MediaType = mediaType;
        this.Source = source;
        this.TestCaseStartedId = testCaseStartedId;
        this.TestStepId = testStepId;
        this.Url = url;
    }

    public override boolean Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Attachment that = (Attachment) o;
        return 
            Body.Equals(that.Body) &&         
            ContentEncoding.Equals(that.ContentEncoding) &&         
            Object.Equals(FileName, that.FileName) &&         
            MediaType.Equals(that.MediaType) &&         
            Object.Equals(Source, that.Source) &&         
            Object.Equals(TestCaseStartedId, that.TestCaseStartedId) &&         
            Object.Equals(TestStepId, that.TestStepId) &&         
            Object.Equals(Url, that.Url);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Body.GetHashCode();
        hash = hash * 31 + ContentEncoding.GetHashCode();
        hash = hash * 31 + FileName?.GetHashCode()?? 0;
        hash = hash * 31 + MediaType.GetHashCode();
        hash = hash * 31 + Source?.GetHashCode()?? 0;
        hash = hash * 31 + TestCaseStartedId?.GetHashCode()?? 0;
        hash = hash * 31 + TestStepId?.GetHashCode()?? 0;
        hash = hash * 31 + Url?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Attachment{" +
            "body=" + Body +
            ", contentEncoding=" + ContentEncoding +
            ", fileName=" + FileName +
            ", mediaType=" + MediaType +
            ", source=" + Source +
            ", testCaseStartedId=" + TestCaseStartedId +
            ", testStepId=" + TestStepId +
            ", url=" + Url +
            '}';
    }
}
