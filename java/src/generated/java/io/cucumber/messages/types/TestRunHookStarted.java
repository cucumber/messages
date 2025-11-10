package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the TestRunHookStarted message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class TestRunHookStarted {
    private final String id;
    private final String testRunStartedId;
    private final String hookId;
    private final String workerId;
    private final Timestamp timestamp;

    public TestRunHookStarted(
        String id,
        String testRunStartedId,
        String hookId,
        String workerId,
        Timestamp timestamp
    ) {
        this.id = requireNonNull(id, "TestRunHookStarted.id cannot be null");
        this.testRunStartedId = requireNonNull(testRunStartedId, "TestRunHookStarted.testRunStartedId cannot be null");
        this.hookId = requireNonNull(hookId, "TestRunHookStarted.hookId cannot be null");
        this.workerId = workerId;
        this.timestamp = requireNonNull(timestamp, "TestRunHookStarted.timestamp cannot be null");
    }

    /**
     * Unique identifier for this hook execution
     */
    public String getId() {
        return id;
    }

    /**
     * Identifier for the test run that this hook execution belongs to
     */
    public String getTestRunStartedId() {
        return testRunStartedId;
    }

    /**
     * Identifier for the hook that will be executed
     */
    public String getHookId() {
        return hookId;
    }

    /**
     * An identifier for the worker process running this hook, if parallel workers are in use. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.
     */
    public Optional<String> getWorkerId() {
        return Optional.ofNullable(workerId);
    }

    public Timestamp getTimestamp() {
        return timestamp;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestRunHookStarted that = (TestRunHookStarted) o;
        return 
            id.equals(that.id) &&         
            testRunStartedId.equals(that.testRunStartedId) &&         
            hookId.equals(that.hookId) &&         
            Objects.equals(workerId, that.workerId) &&         
            timestamp.equals(that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            id,
            testRunStartedId,
            hookId,
            workerId,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "TestRunHookStarted{" +
            "id=" + id +
            ", testRunStartedId=" + testRunStartedId +
            ", hookId=" + hookId +
            ", workerId=" + workerId +
            ", timestamp=" + timestamp +
            '}';
    }
}
