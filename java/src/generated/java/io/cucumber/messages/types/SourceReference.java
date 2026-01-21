package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the SourceReference message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
 * [Location](#io.cucumber.messages.Location) within that file.
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class SourceReference {
    private final @Nullable String uri;
    private final @Nullable JavaMethod javaMethod;
    private final @Nullable JavaStackTraceElement javaStackTraceElement;
    private final @Nullable Location location;

    public static SourceReference of(String uri) {
        return new SourceReference(
            requireNonNull(uri, "SourceReference.uri cannot be null"),
            null,
            null,
            null
        );
    }

    public static SourceReference of(JavaMethod javaMethod) {
        return new SourceReference(
            null,
            requireNonNull(javaMethod, "SourceReference.javaMethod cannot be null"),
            null,
            null
        );
    }

    public static SourceReference of(JavaStackTraceElement javaStackTraceElement) {
        return new SourceReference(
            null,
            null,
            requireNonNull(javaStackTraceElement, "SourceReference.javaStackTraceElement cannot be null"),
            null
        );
    }

    public static SourceReference of(Location location) {
        return new SourceReference(
            null,
            null,
            null,
            requireNonNull(location, "SourceReference.location cannot be null")
        );
    }

    public SourceReference(
        @Nullable String uri,
        @Nullable JavaMethod javaMethod,
        @Nullable JavaStackTraceElement javaStackTraceElement,
        @Nullable Location location
    ) {
        this.uri = uri;
        this.javaMethod = javaMethod;
        this.javaStackTraceElement = javaStackTraceElement;
        this.location = location;
    }

    public Optional<String> getUri() {
        return Optional.ofNullable(uri);
    }

    public Optional<JavaMethod> getJavaMethod() {
        return Optional.ofNullable(javaMethod);
    }

    public Optional<JavaStackTraceElement> getJavaStackTraceElement() {
        return Optional.ofNullable(javaStackTraceElement);
    }

    public Optional<Location> getLocation() {
        return Optional.ofNullable(location);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        SourceReference that = (SourceReference) o;
        return 
            Objects.equals(uri, that.uri) &&         
            Objects.equals(javaMethod, that.javaMethod) &&         
            Objects.equals(javaStackTraceElement, that.javaStackTraceElement) &&         
            Objects.equals(location, that.location);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            uri,
            javaMethod,
            javaStackTraceElement,
            location
        );
    }

    @Override
    public String toString() {
        return "SourceReference{" +
            "uri=" + uri +
            ", javaMethod=" + javaMethod +
            ", javaStackTraceElement=" + javaStackTraceElement +
            ", location=" + location +
            '}';
    }
}
