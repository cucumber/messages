package io.cucumber.messages;

import io.cucumber.messages.types.Envelope;
import io.cucumber.messages.types.Source;
import io.cucumber.messages.types.TestRunStarted;
import io.cucumber.messages.types.Timestamp;
import org.junit.jupiter.api.Test;

import java.util.UUID;

import static io.cucumber.messages.Jackson.OBJECT_MAPPER;
import static io.cucumber.messages.types.SourceMediaType.TEXT_X_CUCUMBER_GHERKIN_PLAIN;
import static org.junit.jupiter.api.Assertions.assertEquals;

class JacksonTest {
    @Test
    void can_deserialize_enum() {
        Source source = new Source("hello.feature", "Feature: Hello", TEXT_X_CUCUMBER_GHERKIN_PLAIN);
        String json = OBJECT_MAPPER.writeValueAsString(source);
        assertEquals(source, OBJECT_MAPPER.readValue(json, Source.class));
    }

    @Test
    void serialize_enums_using_value() {
        assertEquals("\"text/x.cucumber.gherkin+plain\"",
                OBJECT_MAPPER.writeValueAsString(TEXT_X_CUCUMBER_GHERKIN_PLAIN));
    }

    @Test
    void can_deserialize_envelope() {
        Envelope source = Envelope.of(new TestRunStarted(new Timestamp(3L, 14), UUID.randomUUID().toString()));
        String json = OBJECT_MAPPER.writeValueAsString(source);
        assertEquals(source, OBJECT_MAPPER.readValue(json, Envelope.class));
    }
}
