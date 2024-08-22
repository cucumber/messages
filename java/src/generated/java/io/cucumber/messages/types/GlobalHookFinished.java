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
    private final String globalHookStartedId;
    private final TestStepResult result;
    private final Timestamp timestamp;

    public GlobalHookFinished(
        String globalHookStartedId,
        TestStepResult result,
        Timestamp timestamp
    ) {
        this.globalHookStartedId = requireNonNull(globalHookStartedId, "GlobalHookFinished.globalHookStartedId cannot be null");
        this.result = requireNonNull(result, "GlobalHookFinished.result cannot be null");
        this.timestamp = requireNonNull(timestamp, "GlobalHookFinished.timestamp cannot be null");
    }

    /**
     * Identifier for the hook execution that has finished
     */
    public String getGlobalHookStartedId() {
        return globalHookStartedId;
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
            globalHookStartedId.equals(that.globalHookStartedId) &&         
            result.equals(that.result) &&         
            timestamp.equals(that.timestamp);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            globalHookStartedId,
            result,
            timestamp
        );
    }

    @Override
    public String toString() {
        return "GlobalHookFinished{" +
            "globalHookStartedId=" + globalHookStartedId +
            ", result=" + result +
            ", timestamp=" + timestamp +
            '}';
    }
}
