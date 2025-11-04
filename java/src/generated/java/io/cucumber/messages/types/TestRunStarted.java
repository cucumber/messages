package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the TestRunStarted message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class TestRunStarted {
    private final Timestamp timestamp;
    private final @Nullable String id;

    public TestRunStarted(
        Timestamp timestamp,
        @Nullable String id
    ) {
        this.timestamp = requireNonNull(timestamp, "TestRunStarted.timestamp cannot be null");
        this.id = id;
    }

    public Timestamp getTimestamp() {
        return timestamp;
    }

    public Optional<String> getId() {
        return Optional.ofNullable(id);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestRunStarted that = (TestRunStarted) o;
        return 
            timestamp.equals(that.timestamp) &&         
            Objects.equals(id, that.id);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            timestamp,
            id
        );
    }

    @Override
    public String toString() {
        return "TestRunStarted{" +
            "timestamp=" + timestamp +
            ", id=" + id +
            '}';
    }
}
