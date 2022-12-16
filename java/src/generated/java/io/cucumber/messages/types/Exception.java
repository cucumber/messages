package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Exception message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A simplified representation of an exception
 */
// Generated code
@SuppressWarnings("unused")
public final class Exception {
    private final String type;
    private final String message;

    public Exception(
        String type,
        String message
    ) {
        this.type = requireNonNull(type, "Exception.type cannot be null");
        this.message = message;
    }

    /**
     * The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
     */
    public String getType() {
        return type;
    }

    /**
      * The message of exception that caused this result. E.g. expected: <"a"> but was: <"b">
     */
    public Optional<String> getMessage() {
        return Optional.ofNullable(message);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Exception that = (Exception) o;
        return 
            type.equals(that.type) &&         
            Objects.equals(message, that.message);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            type,
            message
        );
    }

    @Override
    public String toString() {
        return "Exception{" +
            "type=" + type +
            ", message=" + message +
            '}';
    }
}
