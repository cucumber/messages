package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the GlobalHookFinished message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class GlobalHookFinished {
    private final String testRunStartedId;
    private final String hookId;
    private final TestStepResult result;
    private final Timestamp timestamp;

    public GlobalHookFinished(
        String testRunStartedId,
        String hookId,
        TestStepResult result,
        Timestamp timestamp
    ) {
        this.testRunStartedId = requireNonNull(testRunStartedId, "GlobalHookFinished.testRunStartedId cannot be null");
        this.hookId = requireNonNull(hookId, "GlobalHookFinished.hookId cannot be null");
        this.result = requireNonNull(result, "GlobalHookFinished.result cannot be null");
        this.timestamp = requireNonNull(timestamp, "GlobalHookFinished.timestamp cannot be null");
    }

    /**
     * Identifier for the test run that this hook execution belongs to
     */
    public String getTestRunStartedId() {
        return testRunStartedId;
    }

    /**
     * Identifier for the hook that was executed
     */
    public String getHookId() {
        return hookId;
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
        GlobalHookFinished that = (GlobalHookFinished) o;
        return 
            testRunStartedId.equals(that.testRunStartedId) &&         
            hookId.equals(that.hookId) &&         
            result.equals(that.result) &&         
            timestamp.equals(that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            testRunStartedId,
            hookId,
            result,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "GlobalHookFinished{" +
            "testRunStartedId=" + testRunStartedId +
            ", hookId=" + hookId +
            ", result=" + result +
            ", timestamp=" + timestamp +
            '}';
    }
}
