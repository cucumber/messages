package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the GherkinDocument message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
 * Cucumber implementations should *not* depend on `GherkinDocument` or any of its
 * children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.
 * <p>
 * The only consumers of `GherkinDocument` should only be formatters that produce
 * "rich" output, resembling the original Gherkin document.
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class GherkinDocument {
    private final @Nullable String uri;
    private final @Nullable Feature feature;
    private final List<Comment> comments;

    public GherkinDocument(
        @Nullable String uri,
        @Nullable Feature feature,
        List<Comment> comments
    ) {
        this.uri = uri;
        this.feature = feature;
        this.comments = List.copyOf(requireNonNull(comments, "GherkinDocument.comments cannot be null"));
    }

    /**
     * The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
     * of the source, typically a file path relative to the root directory
     */
    public Optional<String> getUri() {
        return Optional.ofNullable(uri);
    }

    public Optional<Feature> getFeature() {
        return Optional.ofNullable(feature);
    }

    /**
     * All the comments in the Gherkin document
     */
    public List<Comment> getComments() {
        return comments;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        GherkinDocument that = (GherkinDocument) o;
        return 
            Objects.equals(uri, that.uri) &&         
            Objects.equals(feature, that.feature) &&         
            comments.equals(that.comments);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            uri,
            feature,
            comments
        );
    }

    @Override
    public String toString() {
        return "GherkinDocument{" +
            "uri=" + uri +
            ", feature=" + feature +
            ", comments=" + comments +
            '}';
    }
}
