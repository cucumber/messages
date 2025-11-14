package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the ParseError message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class ParseError {
    private final SourceReference source;
    private final String message;

    public ParseError(
        SourceReference source,
        String message
    ) {
        this.source = requireNonNull(source, "ParseError.source cannot be null");
        this.message = requireNonNull(message, "ParseError.message cannot be null");
    }

    public SourceReference getSource() {
        return source;
    }

    public String getMessage() {
        return message;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ParseError that = (ParseError) o;
        return 
            source.equals(that.source) &&         
            message.equals(that.message);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            source,
            message
        );
    }

    @Override
    public String toString() {
        return "ParseError{" +
            "source=" + source +
            ", message=" + message +
            '}';
    }
}
