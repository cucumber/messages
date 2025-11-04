package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Feature message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Feature {
    private final Location location;
    private final List<Tag> tags;
    private final String language;
    private final String keyword;
    private final String name;
    private final String description;
    private final List<FeatureChild> children;

    public Feature(
        Location location,
        List<Tag> tags,
        String language,
        String keyword,
        String name,
        String description,
        List<FeatureChild> children
    ) {
        this.location = requireNonNull(location, "Feature.location cannot be null");
        this.tags = unmodifiableList(new ArrayList<>(requireNonNull(tags, "Feature.tags cannot be null")));
        this.language = requireNonNull(language, "Feature.language cannot be null");
        this.keyword = requireNonNull(keyword, "Feature.keyword cannot be null");
        this.name = requireNonNull(name, "Feature.name cannot be null");
        this.description = requireNonNull(description, "Feature.description cannot be null");
        this.children = unmodifiableList(new ArrayList<>(requireNonNull(children, "Feature.children cannot be null")));
    }

    /**
     * The location of the `Feature` keyword
     */
    public Location getLocation() {
        return location;
    }

    /**
     * All the tags placed above the `Feature` keyword
     */
    public List<Tag> getTags() {
        return tags;
    }

    /**
     * The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document
     */
    public String getLanguage() {
        return language;
    }

    /**
     * The text of the `Feature` keyword (in the language specified by `language`)
     */
    public String getKeyword() {
        return keyword;
    }

    /**
     * The name of the feature (the text following the `keyword`)
     */
    public String getName() {
        return name;
    }

    /**
     * The line(s) underneath the line with the `keyword` that are used as description
     */
    public String getDescription() {
        return description;
    }

    /**
     * Zero or more children
     */
    public List<FeatureChild> getChildren() {
        return children;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Feature that = (Feature) o;
        return 
            location.equals(that.location) &&         
            tags.equals(that.tags) &&         
            language.equals(that.language) &&         
            keyword.equals(that.keyword) &&         
            name.equals(that.name) &&         
            description.equals(that.description) &&         
            children.equals(that.children);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            location,
            tags,
            language,
            keyword,
            name,
            description,
            children
        );
    }

    @Override
    public String toString() {
        return "Feature{" +
            "location=" + location +
            ", tags=" + tags +
            ", language=" + language +
            ", keyword=" + keyword +
            ", name=" + name +
            ", description=" + description +
            ", children=" + children +
            '}';
    }
}
