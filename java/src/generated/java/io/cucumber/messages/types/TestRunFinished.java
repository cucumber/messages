package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the TestRunFinished message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class TestRunFinished {
    private final String message;
    private final Boolean success;
    private final Timestamp timestamp;
    private final Exception exception;
    private final String testRunStartedId;

    public TestRunFinished(
        String message,
        Boolean success,
        Timestamp timestamp,
        Exception exception,
        String testRunStartedId
    ) {
        this.message = message;
        this.success = requireNonNull(success, "TestRunFinished.success cannot be null");
        this.timestamp = requireNonNull(timestamp, "TestRunFinished.timestamp cannot be null");
        this.exception = exception;
        this.testRunStartedId = testRunStartedId;
    }

    /**
     * An informative message about the test run. Typically additional information about failure, but not necessarily.
     */
    public Optional<String> getMessage() {
        return Optional.ofNullable(message);
    }

    /**
     * A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.
     */
    public Boolean getSuccess() {
        return success;
    }

    /**
     * Timestamp when the TestRun is finished
     */
    public Timestamp getTimestamp() {
        return timestamp;
    }

    /**
     * Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.
     */
    public Optional<Exception> getException() {
        return Optional.ofNullable(exception);
    }

    public Optional<String> getTestRunStartedId() {
        return Optional.ofNullable(testRunStartedId);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestRunFinished that = (TestRunFinished) o;
        return 
            Objects.equals(message, that.message) &&         
            success.equals(that.success) &&         
            timestamp.equals(that.timestamp) &&         
            Objects.equals(exception, that.exception) &&         
            Objects.equals(testRunStartedId, that.testRunStartedId);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            message,
            success,
            timestamp,
            exception,
            testRunStartedId
        );
    }

    @Override
    public String toString() {
        return "TestRunFinished{" +
            "message=" + message +
            ", success=" + success +
            ", timestamp=" + timestamp +
            ", exception=" + exception +
            ", testRunStartedId=" + testRunStartedId +
            '}';
    }
}
