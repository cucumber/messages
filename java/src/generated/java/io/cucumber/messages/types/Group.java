package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Group message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Group {
    private final List<Group> children;
    private final @Nullable Long start;
    private final @Nullable String value;

    public Group(
        List<Group> children,
        @Nullable Long start,
        @Nullable String value
    ) {
        this.children = List.copyOf(requireNonNull(children, "Group.children cannot be null"));
        this.start = start;
        this.value = value;
    }

    public List<Group> getChildren() {
        return children;
    }

    public Optional<Long> getStart() {
        return Optional.ofNullable(start);
    }

    public Optional<String> getValue() {
        return Optional.ofNullable(value);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Group that = (Group) o;
        return 
            children.equals(that.children) &&         
            Objects.equals(start, that.start) &&         
            Objects.equals(value, that.value);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            children,
            start,
            value
        );
    }

    @Override
    public String toString() {
        return "Group{" +
            "children=" + children +
            ", start=" + start +
            ", value=" + value +
            '}';
    }
}
