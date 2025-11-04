package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Scenario message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Scenario {
    private final Location location;
    private final List<Tag> tags;
    private final String keyword;
    private final String name;
    private final String description;
    private final List<Step> steps;
    private final List<Examples> examples;
    private final String id;

    public Scenario(
        Location location,
        List<Tag> tags,
        String keyword,
        String name,
        String description,
        List<Step> steps,
        List<Examples> examples,
        String id
    ) {
        this.location = requireNonNull(location, "Scenario.location cannot be null");
        this.tags = unmodifiableList(new ArrayList<>(requireNonNull(tags, "Scenario.tags cannot be null")));
        this.keyword = requireNonNull(keyword, "Scenario.keyword cannot be null");
        this.name = requireNonNull(name, "Scenario.name cannot be null");
        this.description = requireNonNull(description, "Scenario.description cannot be null");
        this.steps = unmodifiableList(new ArrayList<>(requireNonNull(steps, "Scenario.steps cannot be null")));
        this.examples = unmodifiableList(new ArrayList<>(requireNonNull(examples, "Scenario.examples cannot be null")));
        this.id = requireNonNull(id, "Scenario.id cannot be null");
    }

    /**
     * The location of the `Scenario` keyword
     */
    public Location getLocation() {
        return location;
    }

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

    public List<Step> getSteps() {
        return steps;
    }

    public List<Examples> getExamples() {
        return examples;
    }

    public String getId() {
        return id;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Scenario that = (Scenario) o;
        return 
            location.equals(that.location) &&         
            tags.equals(that.tags) &&         
            keyword.equals(that.keyword) &&         
            name.equals(that.name) &&         
            description.equals(that.description) &&         
            steps.equals(that.steps) &&         
            examples.equals(that.examples) &&         
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
            steps,
            examples,
            id
        );
    }

    @Override
    public String toString() {
        return "Scenario{" +
            "location=" + location +
            ", tags=" + tags +
            ", keyword=" + keyword +
            ", name=" + name +
            ", description=" + description +
            ", steps=" + steps +
            ", examples=" + examples +
            ", id=" + id +
            '}';
    }
}
