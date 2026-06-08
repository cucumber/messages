package io.cucumber.messages;

import io.cucumber.messages.types.Duration;
import io.cucumber.messages.types.Envelope;
import io.cucumber.messages.types.Location;
import io.cucumber.messages.types.TestRunHookFinished;
import io.cucumber.messages.types.TestRunHookStarted;
import io.cucumber.messages.types.TestStepResult;
import io.cucumber.messages.types.TestStepResultStatus;
import io.cucumber.messages.types.Timestamp;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class MessagesTest {
    @Test
    @SuppressWarnings("NullAway")
    void message_is_invalid_when_required_fields_are_missing() {
        assertThrows(NullPointerException.class, () -> {
            new Location(null, null);
        }, "Attachment.body cannot be null");
    }

    @Test
    void message_is_valid_when_no_required_fields_are_missing() {
        new Location(1, null);
    }


    @Test
    void one_of_is_valid_with_out_any_fields() {
        new Envelope(
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null
        );
    }

    @Test
    void one_of_throws_on_multiple_fields() {
        var testRunHookStarted = new TestRunHookStarted("", "", "", null, new Timestamp(0L, 0));
        var testRunHookFinished = new TestRunHookFinished("", new TestStepResult(new Duration(0L, 0), null, TestStepResultStatus.FAILED, null), new Timestamp(0L, 0));

        var exception = assertThrows(IllegalArgumentException.class, () -> new Envelope(
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                null,
                testRunHookStarted,
                testRunHookFinished,
                null
        ));

        assertThat(exception).hasMessage("Envelope must be created with a single property but found 'testRunHookStarted' and 'testRunHookFinished'");
    }
}
