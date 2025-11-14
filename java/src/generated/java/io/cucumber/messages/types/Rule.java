package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Rule message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Rule {
    private final Location location;
    private final List<Tag> tags;
    private final String keyword;
    private final String name;
    private final String description;
    private final List<RuleChild> children;
    private final String id;

    public Rule(
        Location location,
        List<Tag> tags,
        String keyword,
        String name,
        String description,
        List<RuleChild> children,
        String id
    ) {
        this.location = requireNonNull(location, "Rule.location cannot be null");
        this.tags = List.copyOf(requireNonNull(tags, "Rule.tags cannot be null"));
        this.keyword = requireNonNull(keyword, "Rule.keyword cannot be null");
        this.name = requireNonNull(name, "Rule.name cannot be null");
        this.description = requireNonNull(description, "Rule.description cannot be null");
        this.children = List.copyOf(requireNonNull(children, "Rule.children cannot be null"));
        this.id = requireNonNull(id, "Rule.id cannot be null");
    }

    /**
     * The location of the `Rule` keyword
     */
    public Location getLocation() {
        return location;
    }

    /**
     * All the tags placed above the `Rule` keyword
     */
    public List<Tag> getTags() {
        return tags;
    }

    public String getKeyword() {
        return keyword;
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public List<RuleChild> getChildren() {
        return children;
    }

    public String getId() {
        return id;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Rule that = (Rule) o;
        return 
            location.equals(that.location) &&         
            tags.equals(that.tags) &&         
            keyword.equals(that.keyword) &&         
            name.equals(that.name) &&         
            description.equals(that.description) &&         
            children.equals(that.children) &&         
            id.equals(that.id);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            location,
            tags,
            keyword,
            name,
            description,
            children,
            id
        );
    }

    @Override
    public String toString() {
        return "Rule{" +
            "location=" + location +
            ", tags=" + tags +
            ", keyword=" + keyword +
            ", name=" + name +
            ", description=" + description +
            ", children=" + children +
            ", id=" + id +
            '}';
    }
}
