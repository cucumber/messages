package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the TestStepResult message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class TestStepResult {
    private final Duration duration;
    private final @Nullable String message;
    private final TestStepResultStatus status;
    private final @Nullable Exception exception;

    public TestStepResult(
        Duration duration,
        @Nullable String message,
        TestStepResultStatus status,
        @Nullable Exception exception
    ) {
        this.duration = requireNonNull(duration, "TestStepResult.duration cannot be null");
        this.message = message;
        this.status = requireNonNull(status, "TestStepResult.status cannot be null");
        this.exception = exception;
    }

    public Duration getDuration() {
        return duration;
    }

    /**
      * An arbitrary bit of information that explains this result. If there was an exception, this should include a stringified representation of it including type, message and stack trace (the exact format will vary by platform).
     */
    public Optional<String> getMessage() {
        return Optional.ofNullable(message);
    }

    public TestStepResultStatus getStatus() {
        return status;
    }

    /**
      * Exception thrown while executing this step, if any.
     */
    public Optional<Exception> getException() {
        return Optional.ofNullable(exception);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestStepResult that = (TestStepResult) o;
        return 
            duration.equals(that.duration) &&         
            Objects.equals(message, that.message) &&         
            status.equals(that.status) &&         
            Objects.equals(exception, that.exception);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            duration,
            message,
            status,
            exception
        );
    }

    @Override
    public String toString() {
        return "TestStepResult{" +
            "duration=" + duration +
            ", message=" + message +
            ", status=" + status +
            ", exception=" + exception +
            '}';
    }
}
