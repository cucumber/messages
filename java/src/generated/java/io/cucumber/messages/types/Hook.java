package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Hook message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class Hook {
    private final String id;
    private final String name;
    private final SourceReference sourceReference;
    private final String tagExpression;
    private final HookType type;

    public Hook(
        String id,
        String name,
        SourceReference sourceReference,
        String tagExpression,
        HookType type
    ) {
        this.id = requireNonNull(id, "Hook.id cannot be null");
        this.name = name;
        this.sourceReference = requireNonNull(sourceReference, "Hook.sourceReference cannot be null");
        this.tagExpression = tagExpression;
        this.type = type;
    }

    public String getId() {
        return id;
    }

    public Optional<String> getName() {
        return Optional.ofNullable(name);
    }

    public SourceReference getSourceReference() {
        return sourceReference;
    }

    public Optional<String> getTagExpression() {
        return Optional.ofNullable(tagExpression);
    }

    public Optional<HookType> getType() {
        return Optional.ofNullable(type);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Hook that = (Hook) o;
        return 
            id.equals(that.id) &&         
            Objects.equals(name, that.name) &&         
            sourceReference.equals(that.sourceReference) &&         
            Objects.equals(tagExpression, that.tagExpression) &&         
            Objects.equals(type, that.type);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            id,
            name,
            sourceReference,
            tagExpression,
            type
        );
    }

    @Override
    public String toString() {
        return "Hook{" +
            "id=" + id +
            ", name=" + name +
            ", sourceReference=" + sourceReference +
            ", tagExpression=" + tagExpression +
            ", type=" + type +
            '}';
    }
}
