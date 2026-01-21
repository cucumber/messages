package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the ExternalAttachment message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * Represents an attachment that is stored externally rather than embedded in the message stream.
 * <p>
 * This message type is used for large attachments (e.g., video files) that are already
 * on the filesystem and should not be loaded into memory. Instead of embedding the content,
 * only a URL reference is stored.
 * <p>
 * A formatter or other consumer of messages may replace an Attachment with an ExternalAttachment if it makes sense to do so.
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class ExternalAttachment {
    private final String url;
    private final String mediaType;
    private final @Nullable String testStepId;
    private final @Nullable String testCaseStartedId;
    private final @Nullable String testRunHookStartedId;
    private final @Nullable Timestamp timestamp;

    public ExternalAttachment(
        String url,
        String mediaType,
        @Nullable String testStepId,
        @Nullable String testCaseStartedId,
        @Nullable String testRunHookStartedId,
        @Nullable Timestamp timestamp
    ) {
        this.url = requireNonNull(url, "ExternalAttachment.url cannot be null");
        this.mediaType = requireNonNull(mediaType, "ExternalAttachment.mediaType cannot be null");
        this.testStepId = testStepId;
        this.testCaseStartedId = testCaseStartedId;
        this.testRunHookStartedId = testRunHookStartedId;
        this.timestamp = timestamp;
    }

    /**
     * A URL where the attachment can be retrieved. This could be a file:// URL for
     * local filesystem paths, or an http(s):// URL for remote resources.
     */
    public String getUrl() {
        return url;
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

    /**
     * The identifier of the test step if the attachment was created during the execution of a test step
     */
    public Optional<String> getTestStepId() {
        return Optional.ofNullable(testStepId);
    }

    /**
     * The identifier of the test case attempt if the attachment was created during the execution of a test step
     */
    public Optional<String> getTestCaseStartedId() {
        return Optional.ofNullable(testCaseStartedId);
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
        ExternalAttachment that = (ExternalAttachment) o;
        return 
            url.equals(that.url) &&         
            mediaType.equals(that.mediaType) &&         
            Objects.equals(testStepId, that.testStepId) &&         
            Objects.equals(testCaseStartedId, that.testCaseStartedId) &&         
            Objects.equals(testRunHookStartedId, that.testRunHookStartedId) &&         
            Objects.equals(timestamp, that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            url,
            mediaType,
            testStepId,
            testCaseStartedId,
            testRunHookStartedId,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "ExternalAttachment{" +
            "url=" + url +
            ", mediaType=" + mediaType +
            ", testStepId=" + testStepId +
            ", testCaseStartedId=" + testCaseStartedId +
            ", testRunHookStartedId=" + testRunHookStartedId +
            ", timestamp=" + timestamp +
            '}';
    }
}
