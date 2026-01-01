package io.cucumber.messages;

import io.cucumber.messages.types.Envelope;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Spliterator;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

import static java.nio.charset.StandardCharsets.UTF_8;
import static java.util.Objects.requireNonNull;
import static java.util.Spliterator.NONNULL;
import static java.util.Spliterator.ORDERED;
import static java.util.Spliterators.spliteratorUnknownSize;

/**
 * Reads messages from a stream.
 * 
 * <p>The stream should contain a a sequence of json objects separated
 * by a new line character. The objects will be deserialized to
 * {@link Envelope Envelopes}.
 */
public final class NdjsonToMessageReader implements AutoCloseable {
    private final BufferedReader reader;
    private final Deserializer deserializer;

    public NdjsonToMessageReader(InputStream inputStream, Deserializer deserializer) {
        this(
                createBufferedInputStreamReader(inputStream),
                requireNonNull(deserializer)
        );
    }

    private static BufferedReader createBufferedInputStreamReader(InputStream inputStream) {
        requireNonNull(inputStream);
        return new BufferedReader(new InputStreamReader(inputStream, UTF_8));
    }

    private NdjsonToMessageReader(BufferedReader reader, Deserializer deserializer) {
        this.reader = reader;
        this.deserializer = deserializer;
    }

    public Envelope readLine() throws IOException {
        String json = reader.readLine();
        if (json == null) {
            return null;
        }
        Envelope envelope = deserializer.readValue(json);
        if (envelope == null) {
            throw new IOException("inputStream may not contain 'null' values");
        }
        return envelope;
    }

    public Stream<Envelope> lines() {
        Iterator<Envelope> iterator = new Iterator<Envelope>() {
            private Envelope next;

            @Override
            public boolean hasNext() {
                if (next != null) {
                    return true;
                }
                try {
                    next = readLine();
                    return next != null;
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }

            @Override
            public Envelope next() {
                if (next != null || hasNext()) {
                    Envelope envelope = next;
                    next = null;
                    return envelope;
                }
                throw new NoSuchElementException();
            }
        };
        Spliterator<Envelope> spliterator = spliteratorUnknownSize(iterator, ORDERED | NONNULL);
        return StreamSupport.stream(spliterator, false);
    }

    @Override
    public void close() throws IOException {
        reader.close();
    }

    @FunctionalInterface
    public interface Deserializer {

        Envelope readValue(String json) throws IOException;

    }

}
