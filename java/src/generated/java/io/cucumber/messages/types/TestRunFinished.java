package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

// Generated code
@SuppressWarnings("unused")
public final class TestRunFinished {
    private final String message;
    private final Boolean success;
    private final Timestamp timestamp;
    private final String testRunStartedId;

    public TestRunFinished(
        String message,
        Boolean success,
        Timestamp timestamp,
        String testRunStartedId
    ) {
        this.message = message;
        this.success = requireNonNull(success, "TestRunFinished.success cannot be null");
        this.timestamp = requireNonNull(timestamp, "TestRunFinished.timestamp cannot be null");
        this.testRunStartedId = testRunStartedId;
    }

    public Optional<String> getMessage() {
        return Optional.ofNullable(message);
    }

    public Boolean getSuccess() {
        return success;
    }

    public Timestamp getTimestamp() {
        return timestamp;
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
            Objects.equals(testRunStartedId, that.testRunStartedId);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            message,
            success,
            timestamp,
            testRunStartedId
        );
    }

    @Override
    public String toString() {
        return "TestRunFinished{" +
            "message=" + message +
            ", success=" + success +
            ", timestamp=" + timestamp +
            ", testRunStartedId=" + testRunStartedId +
            '}';
    }
}
