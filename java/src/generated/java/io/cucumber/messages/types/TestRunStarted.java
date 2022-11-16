package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

// Generated code
@SuppressWarnings("unused")
public final class TestRunStarted {
    private final String id;
    private final Timestamp timestamp;

    public TestRunStarted(
        String id,
        Timestamp timestamp
    ) {
        this.id = requireNonNull(id, "TestRunStarted.id cannot be null");
        this.timestamp = requireNonNull(timestamp, "TestRunStarted.timestamp cannot be null");
    }

    public String getId() {
        return id;
    }

    public Timestamp getTimestamp() {
        return timestamp;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestRunStarted that = (TestRunStarted) o;
        return 
            id.equals(that.id) &&         
            timestamp.equals(that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            id,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "TestRunStarted{" +
            "id=" + id +
            ", timestamp=" + timestamp +
            '}';
    }
}
