package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Source message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Source {
    private final String uri;
    private final String data;
    private final SourceMediaType mediaType;

    public Source(
        String uri,
        String data,
        SourceMediaType mediaType
    ) {
        this.uri = requireNonNull(uri, "Source.uri cannot be null");
        this.data = requireNonNull(data, "Source.data cannot be null");
        this.mediaType = requireNonNull(mediaType, "Source.mediaType cannot be null");
    }

    /**
     * The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
     * of the source, typically a file path relative to the root directory
     */
    public String getUri() {
        return uri;
    }

    /**
     * The contents of the file
     */
    public String getData() {
        return data;
    }

    /**
     * The media type of the file. Can be used to specify custom types, such as
     * text/x.cucumber.gherkin+plain
     */
    public SourceMediaType getMediaType() {
        return mediaType;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Source that = (Source) o;
        return 
            uri.equals(that.uri) &&         
            data.equals(that.data) &&         
            mediaType.equals(that.mediaType);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            uri,
            data,
            mediaType
        );
    }

    @Override
    public String toString() {
        return "Source{" +
            "uri=" + uri +
            ", data=" + data +
            ", mediaType=" + mediaType +
            '}';
    }
}
