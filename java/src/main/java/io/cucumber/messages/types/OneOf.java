package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.Objects;
import java.util.Optional;

/**
 * Just good enough implementation of a <a href="https://en.wikipedia.org/wiki/Tagged_union">Tagged Union</a>.
 */
final class OneOf {

    private final @Nullable String propertyName;
    private final @Nullable Object value;

    static OneOf of(String type, @Nullable Object... propertyPairs) {
        String propertyName = null;
        Object value = null;
        for (int i = 0; i < propertyPairs.length; i += 2) {
            String candidatePropertyName = (String) propertyPairs[i];
            Object candidate = propertyPairs[i + 1];
            if (candidate != null) {
                if (value != null) {
                    throw new IllegalArgumentException("%s must be created with a single property but found '%s' and '%s'".formatted(type, propertyName, candidatePropertyName));
                }
                propertyName = candidatePropertyName;
                value = candidate;
            }
        }
        return new OneOf(propertyName, value);
    }

    OneOf(@Nullable String propertyName, @Nullable Object value) {
        this.propertyName = propertyName;
        this.value = value;
    }

    @SuppressWarnings("unchecked")
    <T> Optional<T> get(String propertyName) {
        if (propertyName.equals(this.propertyName)) {
            return Optional.ofNullable((T) value);
        }
        return Optional.empty();
    }

    boolean isEmpty() {
        return value == null;
    }

    @Override
    public boolean equals(@Nullable Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        OneOf oneOf = (OneOf) o;
        return Objects.equals(propertyName, oneOf.propertyName) && Objects.equals(value, oneOf.value);
    }

    @Override
    public int hashCode() {
        return Objects.hash(propertyName, value);
    }

    @Override
    public String toString() {
        if (isEmpty()) {
            return "";
        }
        return propertyName + "=\"" + value + "\"";
    }
}
