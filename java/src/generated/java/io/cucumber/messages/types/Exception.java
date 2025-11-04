package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Exception message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A simplified representation of an exception
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Exception {
    private final String type;
    private final @Nullable String message;
    private final @Nullable String stackTrace;

    public Exception(
        String type,
        @Nullable String message,
        @Nullable String stackTrace
    ) {
        this.type = requireNonNull(type, "Exception.type cannot be null");
        this.message = message;
        this.stackTrace = stackTrace;
    }

    /**
     * The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
     */
    public String getType() {
        return type;
    }

    /**
      * The message of exception that caused this result. E.g. expected: "a" but was: "b"
     */
    public Optional<String> getMessage() {
        return Optional.ofNullable(message);
    }

    /**
      * The stringified stack trace of the exception that caused this result
     */
    public Optional<String> getStackTrace() {
        return Optional.ofNullable(stackTrace);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Exception that = (Exception) o;
        return 
            type.equals(that.type) &&         
            Objects.equals(message, that.message) &&         
            Objects.equals(stackTrace, that.stackTrace);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            type,
            message,
            stackTrace
        );
    }

    @Override
    public String toString() {
        return "Exception{" +
            "type=" + type +
            ", message=" + message +
            ", stackTrace=" + stackTrace +
            '}';
    }
}
