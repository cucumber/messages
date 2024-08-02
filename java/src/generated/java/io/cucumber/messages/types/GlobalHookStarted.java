package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the GlobalHookStarted message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class GlobalHookStarted {
    private final String testRunStartedId;
    private final String hookId;
    private final Timestamp timestamp;

    public GlobalHookStarted(
        String testRunStartedId,
        String hookId,
        Timestamp timestamp
    ) {
        this.testRunStartedId = requireNonNull(testRunStartedId, "GlobalHookStarted.testRunStartedId cannot be null");
        this.hookId = requireNonNull(hookId, "GlobalHookStarted.hookId cannot be null");
        this.timestamp = requireNonNull(timestamp, "GlobalHookStarted.timestamp cannot be null");
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

    public Timestamp getTimestamp() {
        return timestamp;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        GlobalHookStarted that = (GlobalHookStarted) o;
        return 
            testRunStartedId.equals(that.testRunStartedId) &&         
            hookId.equals(that.hookId) &&         
            timestamp.equals(that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            testRunStartedId,
            hookId,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "GlobalHookStarted{" +
            "testRunStartedId=" + testRunStartedId +
            ", hookId=" + hookId +
            ", timestamp=" + timestamp +
            '}';
    }
}
