package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the TestRunHookFinished message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class TestRunHookFinished {
    private final String testRunHookStartedId;
    private final TestStepResult result;
    private final Timestamp timestamp;

    public TestRunHookFinished(
        String testRunHookStartedId,
        TestStepResult result,
        Timestamp timestamp
    ) {
        this.testRunHookStartedId = requireNonNull(testRunHookStartedId, "TestRunHookFinished.testRunHookStartedId cannot be null");
        this.result = requireNonNull(result, "TestRunHookFinished.result cannot be null");
        this.timestamp = requireNonNull(timestamp, "TestRunHookFinished.timestamp cannot be null");
    }

    /**
     * Identifier for the hook execution that has finished
     */
    public String getTestRunHookStartedId() {
        return testRunHookStartedId;
    }

    public TestStepResult getResult() {
        return result;
    }

    public Timestamp getTimestamp() {
        return timestamp;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestRunHookFinished that = (TestRunHookFinished) o;
        return 
            testRunHookStartedId.equals(that.testRunHookStartedId) &&         
            result.equals(that.result) &&         
            timestamp.equals(that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            testRunHookStartedId,
            result,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "TestRunHookFinished{" +
            "testRunHookStartedId=" + testRunHookStartedId +
            ", result=" + result +
            ", timestamp=" + timestamp +
            '}';
    }
}
