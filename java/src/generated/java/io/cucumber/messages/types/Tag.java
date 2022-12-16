package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Tag message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A tag
 */
// Generated code
@SuppressWarnings("unused")
public final class Tag {
    private final Location location;
    private final String name;
    private final String id;

    public Tag(
        Location location,
        String name,
        String id
    ) {
        this.location = requireNonNull(location, "Tag.location cannot be null");
        this.name = requireNonNull(name, "Tag.name cannot be null");
        this.id = requireNonNull(id, "Tag.id cannot be null");
    }

    /**
     * Location of the tag
     */
    public Location getLocation() {
        return location;
    }

    /**
     * The name of the tag (including the leading `@`)
     */
    public String getName() {
        return name;
    }

    /**
     * Unique ID to be able to reference the Tag from PickleTag
     */
    public String getId() {
        return id;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Tag that = (Tag) o;
        return 
            location.equals(that.location) &&         
            name.equals(that.name) &&         
            id.equals(that.id);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            location,
            name,
            id
        );
    }

    @Override
    public String toString() {
        return "Tag{" +
            "location=" + location +
            ", name=" + name +
            ", id=" + id +
            '}';
    }
}
