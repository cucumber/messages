package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Pickle message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A `Pickle` represents a template for a `TestCase`. It is typically derived
 * from another format, such as [GherkinDocument](#io.cucumber.messages.GherkinDocument).
 * In the future a `Pickle` may be derived from other formats such as Markdown or
 * Excel files.
 * <p>
 * By making `Pickle` the main data structure Cucumber uses for execution, the
 * implementation of Cucumber itself becomes simpler, as it doesn't have to deal
 * with the complex structure of a [GherkinDocument](#io.cucumber.messages.GherkinDocument).
 * <p>
 * Each `PickleStep` of a `Pickle` is matched with a `StepDefinition` to create a `TestCase`
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Pickle {
    private final String id;
    private final String uri;
    private final @Nullable Location location;
    private final String name;
    private final String language;
    private final List<PickleStep> steps;
    private final List<PickleTag> tags;
    private final List<String> astNodeIds;

    public Pickle(
        String id,
        String uri,
        @Nullable Location location,
        String name,
        String language,
        List<PickleStep> steps,
        List<PickleTag> tags,
        List<String> astNodeIds
    ) {
        this.id = requireNonNull(id, "Pickle.id cannot be null");
        this.uri = requireNonNull(uri, "Pickle.uri cannot be null");
        this.location = location;
        this.name = requireNonNull(name, "Pickle.name cannot be null");
        this.language = requireNonNull(language, "Pickle.language cannot be null");
        this.steps = List.copyOf(requireNonNull(steps, "Pickle.steps cannot be null"));
        this.tags = List.copyOf(requireNonNull(tags, "Pickle.tags cannot be null"));
        this.astNodeIds = List.copyOf(requireNonNull(astNodeIds, "Pickle.astNodeIds cannot be null"));
    }

    /**
     * A unique id for the pickle
     */
    public String getId() {
        return id;
    }

    /**
     * The uri of the source file
     */
    public String getUri() {
        return uri;
    }

    /**
      * The location of this pickle in source file. A pickle constructed from `Examples` will point to the example row.
     */
    public Optional<Location> getLocation() {
        return Optional.ofNullable(location);
    }

    /**
     * The name of the pickle
     */
    public String getName() {
        return name;
    }

    /**
     * The language of the pickle
     */
    public String getLanguage() {
        return language;
    }

    /**
     * One or more steps
     */
    public List<PickleStep> getSteps() {
        return steps;
    }

    /**
     * One or more tags. If this pickle is constructed from a Gherkin document,
     * It includes inherited tags from the `Feature` as well.
     */
    public List<PickleTag> getTags() {
        return tags;
    }

    /**
     * Points to the AST node locations of the pickle. The last one represents the unique
     * id of the pickle. A pickle constructed from `Examples` will have the first
     * id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.
     */
    public List<String> getAstNodeIds() {
        return astNodeIds;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pickle that = (Pickle) o;
        return 
            id.equals(that.id) &&         
            uri.equals(that.uri) &&         
            Objects.equals(location, that.location) &&         
            name.equals(that.name) &&         
            language.equals(that.language) &&         
            steps.equals(that.steps) &&         
            tags.equals(that.tags) &&         
            astNodeIds.equals(that.astNodeIds);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            id,
            uri,
            location,
            name,
            language,
            steps,
            tags,
            astNodeIds
        );
    }

    @Override
    public String toString() {
        return "Pickle{" +
            "id=" + id +
            ", uri=" + uri +
            ", location=" + location +
            ", name=" + name +
            ", language=" + language +
            ", steps=" + steps +
            ", tags=" + tags +
            ", astNodeIds=" + astNodeIds +
            '}';
    }
}
