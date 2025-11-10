package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the TestCaseStarted message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class TestCaseStarted {
    private final Long attempt;
    private final String id;
    private final String testCaseId;
    private final String workerId;
    private final Timestamp timestamp;

    public TestCaseStarted(
        Long attempt,
        String id,
        String testCaseId,
        String workerId,
        Timestamp timestamp
    ) {
        this.attempt = requireNonNull(attempt, "TestCaseStarted.attempt cannot be null");
        this.id = requireNonNull(id, "TestCaseStarted.id cannot be null");
        this.testCaseId = requireNonNull(testCaseId, "TestCaseStarted.testCaseId cannot be null");
        this.workerId = workerId;
        this.timestamp = requireNonNull(timestamp, "TestCaseStarted.timestamp cannot be null");
    }

    /**
     * The first attempt should have value 0, and for each retry the value
     * should increase by 1.
     */
    public Long getAttempt() {
        return attempt;
    }

    /**
     * Because a `TestCase` can be run multiple times (in case of a retry),
     * we use this field to group messages relating to the same attempt.
     */
    public String getId() {
        return id;
    }

    public String getTestCaseId() {
        return testCaseId;
    }

    /**
     * An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.
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
        TestCaseStarted that = (TestCaseStarted) o;
        return 
            attempt.equals(that.attempt) &&         
            id.equals(that.id) &&         
            testCaseId.equals(that.testCaseId) &&         
            Objects.equals(workerId, that.workerId) &&         
            timestamp.equals(that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            attempt,
            id,
            testCaseId,
            workerId,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "TestCaseStarted{" +
            "attempt=" + attempt +
            ", id=" + id +
            ", testCaseId=" + testCaseId +
            ", workerId=" + workerId +
            ", timestamp=" + timestamp +
            '}';
    }
}
