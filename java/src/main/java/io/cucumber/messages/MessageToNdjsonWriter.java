package io.cucumber.messages;

import io.cucumber.messages.types.Envelope;

import java.io.BufferedWriter;
import java.io.Flushable;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;

import static java.nio.charset.StandardCharsets.UTF_8;
import static java.util.Objects.requireNonNull;

/**
 * Writes messages read to a stream.
 *
 * <p>The stream will contain a a sequence of json objects separated
 * by a {@code \n} character. The objects written are the serialized
 * representation of {@link Envelope Envelopes}.
 */
public final class MessageToNdjsonWriter implements AutoCloseable, Flushable {
    private final Writer writer;
    private final Serializer serializer;

    public MessageToNdjsonWriter(OutputStream outputStream, Serializer serializer) {
        this(
                createBufferedOutputStreamWriter(outputStream),
                requireNonNull(serializer)
        );
    }

    private static BufferedWriter createBufferedOutputStreamWriter(OutputStream outputStream) {
        requireNonNull(outputStream);
        return new BufferedWriter(new OutputStreamWriter(outputStream, UTF_8));
    }

    private MessageToNdjsonWriter(Writer writer, Serializer serializer) {
        this.writer = writer;
        this.serializer = serializer;
    }

    public void write(Envelope message) throws IOException {
        requireNonNull(message);
        serializer.writeValue(writer, message);
        writer.write("\n");
    }

    @Override
    public void close() throws IOException {
        writer.close();
    }

    @Override
    public void flush() throws IOException {
        writer.flush();
    }

    @FunctionalInterface
    public interface Serializer {

        void writeValue(Writer writer, Envelope value) throws IOException;

    }
}
