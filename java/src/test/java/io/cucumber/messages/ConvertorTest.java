package io.cucumber.messages;

import io.cucumber.messages.types.Duration;
import io.cucumber.messages.types.Exception;
import io.cucumber.messages.types.Timestamp;
import org.junit.jupiter.api.Test;

import java.util.Optional;

import static org.junit.jupiter.api.Assertions.assertAll;
import static org.junit.jupiter.api.Assertions.assertEquals;

class ConvertorTest {

    @Test
    void convertsExceptionToMessage() {
        Exception e = Convertor.toMessage(new RuntimeException("Hello world!"));
        Exception e2 = Convertor.toMessage(new RuntimeException());
        assertAll(
                () -> assertEquals(Optional.of("Hello world!"), e.getMessage()),
                () -> assertEquals(Optional.empty(), e2.getMessage()),
                () -> assertEquals("java.lang.RuntimeException", e.getType()),
                () -> assertEquals("java.lang.RuntimeException", e2.getType())
        );
    }

    @Test
    void convertsToAndFromTimestamp() {
        java.time.Instant javaInstant = java.time.Instant.now();
        Timestamp timestamp = Convertor.toMessage(javaInstant);
        java.time.Instant javaInstantAgain = Convertor.toInstant(timestamp);

        assertEquals(javaInstant, javaInstantAgain);
    }

    @Test
    void convertsToAndFromDuration() {
        java.time.Duration javaDuration = java.time.Duration.ofSeconds(3, 161000);
        Duration duration = Convertor.toMessage(javaDuration);
        java.time.Duration javaDurationAgain = Convertor.toDuration(duration);

        assertEquals(javaDuration, javaDurationAgain);
    }

}
