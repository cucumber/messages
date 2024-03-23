package io.cucumber.messages;

import io.cucumber.messages.types.Duration;
import io.cucumber.messages.types.Exception;
import io.cucumber.messages.types.Timestamp;
import org.junit.jupiter.api.Test;

import java.util.Optional;

import static org.junit.jupiter.api.Assertions.assertAll;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

class ConvertorTest {

    @Test
    void convertsExceptionToMessage() {
        Exception e = Convertor.toMessage(new RuntimeException());
        assertAll(
                () -> assertEquals(Optional.empty(), e.getMessage()),
                () -> assertEquals("java.lang.RuntimeException", e.getType()),
                () -> assertTrue(e.getStackTrace().isPresent())
        );
    }

    @Test
    void convertsExceptionWithMessageToMessage() {
        Exception e = Convertor.toMessage(new RuntimeException("Hello world!"));
        assertAll(
                () -> assertEquals(Optional.of("Hello world!"), e.getMessage()),
                () -> assertEquals("java.lang.RuntimeException", e.getType()),
                () -> assertTrue(e.getStackTrace().isPresent())
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
