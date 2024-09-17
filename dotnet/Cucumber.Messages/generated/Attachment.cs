
// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------
using System.Collections.Immutable;

namespace Io.Cucumber.Messages.Types;

/**
 * Represents the Attachment message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
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

public sealed record Attachment 
{
    /**
     * The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
     * is simply the string. If it's `BASE64`, the string should be Base64 decoded to
     * obtain the attachment.
     */
    public string Body { get; }
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
    public AttachmentContentEncoding ContentEncoding { get; }
    /**
     * Suggested file name of the attachment. (Provided by the user as an argument to `attach`)
     */
    public string? FileName { get; }
    /**
     * The media type of the data. This can be any valid
     * [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
     * as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
     * and `text/x.cucumber.stacktrace+plain`
     */
    public string MediaType { get; }
    public Source? Source { get; }
    public string? TestCaseStartedId { get; }
    public string? TestStepId { get; }
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
    public string? Url { get; }


    public Attachment(
        string body,
        AttachmentContentEncoding contentEncoding,
        string? fileName,
        string mediaType,
        Source? source,
        string? testCaseStartedId,
        string? testStepId,
        string? url
    ) 
    {
        Body = body ?? throw new ArgumentNullException("Body", "Attachment.Body cannot be null");
        ContentEncoding = contentEncoding;
        FileName = fileName;
        MediaType = mediaType ?? throw new ArgumentNullException("MediaType", "Attachment.MediaType cannot be null");
        Source = source;
        TestCaseStartedId = testCaseStartedId;
        TestStepId = testStepId;
        Url = url;
    }
}
