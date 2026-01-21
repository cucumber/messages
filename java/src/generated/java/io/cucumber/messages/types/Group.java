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
    private final @Nullable List<Group> children;
    private final @Nullable Integer start;
    private final @Nullable String value;

    public static Group of(List<Group> children) {
        return new Group(
            List.copyOf(requireNonNull(children, "Group.children cannot be null")),
            null,
            null
        );
    }

    public static Group of(Integer start) {
        return new Group(
            null,
            requireNonNull(start, "Group.start cannot be null"),
            null
        );
    }

    public static Group of(String value) {
        return new Group(
            null,
            null,
            requireNonNull(value, "Group.value cannot be null")
        );
    }

    public Group(
        @Nullable List<Group> children,
        @Nullable Integer start,
        @Nullable String value
    ) {
        this.children = children == null ? null : List.copyOf(children);
        this.start = start;
        this.value = value;
    }

    /**
     * The nested capture groups of an argument.
     * Absent if the group has no nested capture groups.
     */
    public Optional<List<Group>> getChildren() {
        return Optional.ofNullable(children);
    }

    public Optional<Integer> getStart() {
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
            Objects.equals(children, that.children) &&         
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
