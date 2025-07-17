package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Attachment message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * Attachments (parse errors, execution errors, screenshots, links...)
 * <p>
 * An attachment represents any kind of data associated with a line in a
 * [Source](#io.cucumber.messages.Source) file. It can be used for:
 * <p>
 * * Syntax errors during parse time
 * * Screenshots captured and attached during execution
 * * Logs captured and attached during execution
 * <p>
 * It is not to be used for runtime errors raised/thrown during execution. This
 * is captured in `TestResult`.
 */
// Generated code
@SuppressWarnings("unused")
public final class Attachment {
    private final String body;
    private final AttachmentContentEncoding contentEncoding;
    private final String fileName;
    private final String mediaType;
    private final Source source;
    private final String testCaseStartedId;
    private final String testStepId;
    private final String url;
    private final String testRunStartedId;
    private final String testRunHookStartedId;
    private final Timestamp timestamp;

    public Attachment(
        String body,
        AttachmentContentEncoding contentEncoding,
        String fileName,
        String mediaType,
        Source source,
        String testCaseStartedId,
        String testStepId,
        String url,
        String testRunStartedId,
        String testRunHookStartedId,
        Timestamp timestamp
    ) {
        this.body = requireNonNull(body, "Attachment.body cannot be null");
        this.contentEncoding = requireNonNull(contentEncoding, "Attachment.contentEncoding cannot be null");
        this.fileName = fileName;
        this.mediaType = requireNonNull(mediaType, "Attachment.mediaType cannot be null");
        this.source = source;
        this.testCaseStartedId = testCaseStartedId;
        this.testStepId = testStepId;
        this.url = url;
        this.testRunStartedId = testRunStartedId;
        this.testRunHookStartedId = testRunHookStartedId;
        this.timestamp = timestamp;
    }

    /**
     * The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
     * is simply the string. If it's `BASE64`, the string should be Base64 decoded to
     * obtain the attachment.
     */
    public String getBody() {
        return body;
    }

    /**
     * Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).
     * <p>
     * Content encoding is *not* determined by the media type, but rather by the type
     * of the object being attached:
     * <p>
     * - string: IDENTITY
     * - byte array: BASE64
     * - stream: BASE64
     */
    public AttachmentContentEncoding getContentEncoding() {
        return contentEncoding;
    }

    /**
      * Suggested file name of the attachment. (Provided by the user as an argument to `attach`)
     */
    public Optional<String> getFileName() {
        return Optional.ofNullable(fileName);
    }

    /**
     * The media type of the data. This can be any valid
     * [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
     * as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
     * and `text/x.cucumber.stacktrace+plain`
     */
    public String getMediaType() {
        return mediaType;
    }

    public Optional<Source> getSource() {
        return Optional.ofNullable(source);
    }

    /**
      * The identifier of the test case attempt if the attachment was created during the execution of a test step
     */
    public Optional<String> getTestCaseStartedId() {
        return Optional.ofNullable(testCaseStartedId);
    }

    /**
      * The identifier of the test step if the attachment was created during the execution of a test step
     */
    public Optional<String> getTestStepId() {
        return Optional.ofNullable(testStepId);
    }

    /**
      * A URL where the attachment can be retrieved. This field should not be set by Cucumber.
     * It should be set by a program that reads a message stream and does the following for
     * each Attachment message:
     * <p>
     * - Writes the body (after base64 decoding if necessary) to a new file.
     * - Sets `body` and `contentEncoding` to `null`
     * - Writes out the new attachment message
     * <p>
     * This will result in a smaller message stream, which can improve performance and
     * reduce bandwidth of message consumers. It also makes it easier to process and download attachments
     * separately from reports.
     */
    public Optional<String> getUrl() {
        return Optional.ofNullable(url);
    }

    /**
      * Not used; implementers should instead populate `testRunHookStartedId` if an attachment was created during the execution of a test run hook
     */
    public Optional<String> getTestRunStartedId() {
        return Optional.ofNullable(testRunStartedId);
    }

    /**
      * The identifier of the test run hook execution if the attachment was created during the execution of a test run hook
     */
    public Optional<String> getTestRunHookStartedId() {
        return Optional.ofNullable(testRunHookStartedId);
    }

    /**
      * When the attachment was created
     */
    public Optional<Timestamp> getTimestamp() {
        return Optional.ofNullable(timestamp);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Attachment that = (Attachment) o;
        return 
            body.equals(that.body) &&         
            contentEncoding.equals(that.contentEncoding) &&         
            Objects.equals(fileName, that.fileName) &&         
            mediaType.equals(that.mediaType) &&         
            Objects.equals(source, that.source) &&         
            Objects.equals(testCaseStartedId, that.testCaseStartedId) &&         
            Objects.equals(testStepId, that.testStepId) &&         
            Objects.equals(url, that.url) &&         
            Objects.equals(testRunStartedId, that.testRunStartedId) &&         
            Objects.equals(testRunHookStartedId, that.testRunHookStartedId) &&         
            Objects.equals(timestamp, that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            body,
            contentEncoding,
            fileName,
            mediaType,
            source,
            testCaseStartedId,
            testStepId,
            url,
            testRunStartedId,
            testRunHookStartedId,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "Attachment{" +
            "body=" + body +
            ", contentEncoding=" + contentEncoding +
            ", fileName=" + fileName +
            ", mediaType=" + mediaType +
            ", source=" + source +
            ", testCaseStartedId=" + testCaseStartedId +
            ", testStepId=" + testStepId +
            ", url=" + url +
            ", testRunStartedId=" + testRunStartedId +
            ", testRunHookStartedId=" + testRunHookStartedId +
            ", timestamp=" + timestamp +
            '}';
    }
}
