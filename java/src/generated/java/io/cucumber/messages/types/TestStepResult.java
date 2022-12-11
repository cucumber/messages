package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

// Generated code
@SuppressWarnings("unused")
public final class TestStepResult {
    private final Duration duration;
    private final String message;
    private final String exceptionType;
    private final String exceptionMessage;
    private final TestStepResultStatus status;

    public TestStepResult(
        Duration duration,
        String message,
        String exceptionType,
        String exceptionMessage,
        TestStepResultStatus status
    ) {
        this.duration = requireNonNull(duration, "TestStepResult.duration cannot be null");
        this.message = message;
        this.exceptionType = exceptionType;
        this.exceptionMessage = exceptionMessage;
        this.status = requireNonNull(status, "TestStepResult.status cannot be null");
    }

    public Duration getDuration() {
        return duration;
    }

    public Optional<String> getMessage() {
        return Optional.ofNullable(message);
    }

    public Optional<String> getExceptionType() {
        return Optional.ofNullable(exceptionType);
    }

    public Optional<String> getExceptionMessage() {
        return Optional.ofNullable(exceptionMessage);
    }

    public TestStepResultStatus getStatus() {
        return status;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestStepResult that = (TestStepResult) o;
        return 
            duration.equals(that.duration) &&         
            Objects.equals(message, that.message) &&         
            Objects.equals(exceptionType, that.exceptionType) &&         
            Objects.equals(exceptionMessage, that.exceptionMessage) &&         
            status.equals(that.status);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            duration,
            message,
            exceptionType,
            exceptionMessage,
            status
        );
    }

    @Override
    public String toString() {
        return "TestStepResult{" +
            "duration=" + duration +
            ", message=" + message +
            ", exceptionType=" + exceptionType +
            ", exceptionMessage=" + exceptionMessage +
            ", status=" + status +
            '}';
    }
}
