package io.cucumber.messages.types;

import io.cucumber.messages.Property;
import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the PickleDocString message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class PickleDocString {
    private final @Nullable Integer argumentIndex;
    private final @Nullable String mediaType;
    private final String content;

    public PickleDocString(
        @Nullable @Property("argumentIndex") Integer argumentIndex,
        @Nullable @Property("mediaType") String mediaType,
        @Property("content") String content
    ) {
        this.argumentIndex = argumentIndex;
        this.mediaType = mediaType;
        this.content = requireNonNull(content, "PickleDocString.content cannot be null");
    }

    /**
     * The index of this argument. The value is 1 if it was declared before the data table, 2 if it was declared after.
     */
    public Optional<Integer> getArgumentIndex() {
        return Optional.ofNullable(argumentIndex);
    }

    public Optional<String> getMediaType() {
        return Optional.ofNullable(mediaType);
    }

    public String getContent() {
        return content;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        PickleDocString that = (PickleDocString) o;
        return 
            Objects.equals(argumentIndex, that.argumentIndex) &&         
            Objects.equals(mediaType, that.mediaType) &&         
            content.equals(that.content);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            argumentIndex,
            mediaType,
            content
        );
    }

    @Override
    public String toString() {
        return "PickleDocString{" +
            "argumentIndex=" + argumentIndex +
            ", mediaType=" + mediaType +
            ", content=" + content +
            '}';
    }
}
