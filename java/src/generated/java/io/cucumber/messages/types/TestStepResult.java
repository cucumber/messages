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
    private final TestStepResultStatus status;
    private final String exceptionType;
    private final String exceptionMessage;

    public TestStepResult(
        Duration duration,
        String message,
        TestStepResultStatus status,
        String exceptionType,
        String exceptionMessage
    ) {
        this.duration = requireNonNull(duration, "TestStepResult.duration cannot be null");
        this.message = message;
        this.status = requireNonNull(status, "TestStepResult.status cannot be null");
        this.exceptionType = exceptionType;
        this.exceptionMessage = exceptionMessage;
    }

    public Duration getDuration() {
        return duration;
    }

    public Optional<String> getMessage() {
        return Optional.ofNullable(message);
    }

    public TestStepResultStatus getStatus() {
        return status;
    }

    public Optional<String> getExceptionType() {
        return Optional.ofNullable(exceptionType);
    }

    public Optional<String> getExceptionMessage() {
        return Optional.ofNullable(exceptionMessage);
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
            Objects.equals(exceptionType, that.exceptionType) &&         
            Objects.equals(exceptionMessage, that.exceptionMessage);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            duration,
            message,
            status,
            exceptionType,
            exceptionMessage
        );
    }

    @Override
    public String toString() {
        return "TestStepResult{" +
            "duration=" + duration +
            ", message=" + message +
            ", status=" + status +
            ", exceptionType=" + exceptionType +
            ", exceptionMessage=" + exceptionMessage +
            '}';
    }
}
