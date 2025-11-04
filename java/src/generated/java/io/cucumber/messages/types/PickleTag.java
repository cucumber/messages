package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the PickleTag message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A tag
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class PickleTag {
    private final String name;
    private final String astNodeId;

    public PickleTag(
        String name,
        String astNodeId
    ) {
        this.name = requireNonNull(name, "PickleTag.name cannot be null");
        this.astNodeId = requireNonNull(astNodeId, "PickleTag.astNodeId cannot be null");
    }

    public String getName() {
        return name;
    }

    /**
     * Points to the AST node this was created from
     */
    public String getAstNodeId() {
        return astNodeId;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        PickleTag that = (PickleTag) o;
        return 
            name.equals(that.name) &&         
            astNodeId.equals(that.astNodeId);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            name,
            astNodeId
        );
    }

    @Override
    public String toString() {
        return "PickleTag{" +
            "name=" + name +
            ", astNodeId=" + astNodeId +
            '}';
    }
}
