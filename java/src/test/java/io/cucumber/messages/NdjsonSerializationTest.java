package io.cucumber.messages;

import io.cucumber.messages.types.AttachmentContentEncoding;
import io.cucumber.messages.types.Envelope;
import io.cucumber.messages.types.Source;
import io.cucumber.messages.types.SourceMediaType;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.nio.charset.StandardCharsets;
import java.util.Iterator;

import static java.nio.charset.StandardCharsets.UTF_8;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;

class NdjsonSerializationTest {
    static MessageToNdjsonWriter createMessageWriter(OutputStream output) {
        return new MessageToNdjsonWriter(output, Jackson.OBJECT_MAPPER::writeValue);
    }

    static NdjsonToMessageReader createMessageReader(InputStream input) {
        return new NdjsonToMessageReader(input, json -> Jackson.OBJECT_MAPPER.readValue(json, Envelope.class));
    }

    @Test
    void writes_source_envelope() throws IOException {
        ByteArrayOutputStream output = new ByteArrayOutputStream();
        try (MessageToNdjsonWriter writer = createMessageWriter(output)) {
            writer.write(Envelope.of(new Source("uri", "data", SourceMediaType.TEXT_X_CUCUMBER_GHERKIN_PLAIN)));    
        }
        
        String json = new String(output.toByteArray(), StandardCharsets.UTF_8);
        assertEquals(
                "{\"source\":{\"uri\":\"uri\",\"data\":\"data\",\"mediaType\":\"text/x.cucumber.gherkin+plain\"}}\n",
                json);
    }

    @Test
    void does_not_serialize_null_fields() throws IOException {
        ByteArrayOutputStream output = new ByteArrayOutputStream();
        OutputStreamWriter writer = new OutputStreamWriter(output, StandardCharsets.UTF_8);
        Jackson.OBJECT_MAPPER.writeValue(writer, new Envelope(
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
        ));
        writer.flush();
        assertEquals("{}", new String(output.toByteArray(), UTF_8));
    }

    @Test
    void ignores_missing_fields() {
        InputStream input = new ByteArrayInputStream("{\"unused\": 99}\n".getBytes(UTF_8));
        Iterator<Envelope> iterator = createMessageReader(input).lines().iterator();
        assertTrue(iterator.hasNext());
        Envelope envelope = iterator.next();
        assertEquals(new Envelope(
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
        ), envelope);
        assertFalse(iterator.hasNext());
    }

    @Test
    void handles_enums() {
        InputStream input = new ByteArrayInputStream(
                "{\"attachment\":{\"contentEncoding\":\"BASE64\", \"body\":\"the-body\", \"mediaType\":\"text/plain\"}}\n".getBytes(
                        UTF_8));
        Iterator<Envelope> iterator = createMessageReader(input).lines().iterator();
        assertTrue(iterator.hasNext());
        Envelope envelope = iterator.next();
        assertEquals(AttachmentContentEncoding.BASE64, envelope.getAttachment().get().getContentEncoding());
        assertFalse(iterator.hasNext());
    }

    @Test
    void complains_about_null_ndjson() {
        InputStream input = new ByteArrayInputStream("null\n".getBytes(UTF_8));
        NdjsonToMessageReader incomingMessages = createMessageReader(input);
        IOException exception = assertThrows(IOException.class, () -> {
            incomingMessages.readLine();
        });
        Assertions.assertThat(exception).hasMessage("inputStream may not contain 'null' values");
    }
}
