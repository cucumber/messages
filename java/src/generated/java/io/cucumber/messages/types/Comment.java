package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Comment message in Cucumber's message protocol
 * @see <a href=https://github.com/cucumber/messages>Github - Cucumber - Messages</a>
 *
 * A comment in a Gherkin document
 */
// Generated code
@SuppressWarnings("unused")
public final class Comment {
    private final Location location;
    private final String text;

    public Comment(
        Location location,
        String text
    ) {
        this.location = requireNonNull(location, "Comment.location cannot be null");
        this.text = requireNonNull(text, "Comment.text cannot be null");
    }

    /**
     * The location of the comment
     */
    public Location getLocation() {
        return location;
    }

    /**
     * The text of the comment
     */
    public String getText() {
        return text;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Comment that = (Comment) o;
        return 
            location.equals(that.location) &&         
            text.equals(that.text);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            location,
            text
        );
    }

    @Override
    public String toString() {
        return "Comment{" +
            "location=" + location +
            ", text=" + text +
            '}';
    }
}
