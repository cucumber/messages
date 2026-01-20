package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the TestCase message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A `TestCase` contains a sequence of `TestStep`s.
 */
// Generated code
@SuppressWarnings("unused")
public final class TestCase {
    private final String id;
    private final String pickleId;
    private final java.util.List<TestStep> testSteps;
    private final String testRunStartedId;

    public TestCase(
        String id,
        String pickleId,
        java.util.List<TestStep> testSteps,
        String testRunStartedId
    ) {
        this.id = requireNonNull(id, "TestCase.id cannot be null");
        this.pickleId = requireNonNull(pickleId, "TestCase.pickleId cannot be null");
        this.testSteps = unmodifiableList(new ArrayList<>(requireNonNull(testSteps, "TestCase.testSteps cannot be null")));
        this.testRunStartedId = testRunStartedId;
    }

    public String getId() {
        return id;
    }

    /**
     * The ID of the `Pickle` this `TestCase` is derived from.
     */
    public String getPickleId() {
        return pickleId;
    }

    public java.util.List<TestStep> getTestSteps() {
        return testSteps;
    }

    /**
     * Identifier for the test run that this test case belongs to
     */
    public Optional<String> getTestRunStartedId() {
        return Optional.ofNullable(testRunStartedId);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TestCase that = (TestCase) o;
        return 
            id.equals(that.id) &&         
            pickleId.equals(that.pickleId) &&         
            testSteps.equals(that.testSteps) &&         
            Objects.equals(testRunStartedId, that.testRunStartedId);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            id,
            pickleId,
            testSteps,
            testRunStartedId
        );
    }

    @Override
    public String toString() {
        return "TestCase{" +
            "id=" + id +
            ", pickleId=" + pickleId +
            ", testSteps=" + testSteps +
            ", testRunStartedId=" + testRunStartedId +
            '}';
    }
}
