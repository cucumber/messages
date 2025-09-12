package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Suggestion message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A suggested fragment of code to implement an undefined step
 */
// Generated code
@SuppressWarnings("unused")
public final class Suggestion {
    private final String id;
    private final String pickleStepId;
    private final java.util.List<Snippet> snippets;

    public Suggestion(
        String id,
        String pickleStepId,
        java.util.List<Snippet> snippets
    ) {
        this.id = requireNonNull(id, "Suggestion.id cannot be null");
        this.pickleStepId = requireNonNull(pickleStepId, "Suggestion.pickleStepId cannot be null");
        this.snippets = unmodifiableList(new ArrayList<>(requireNonNull(snippets, "Suggestion.snippets cannot be null")));
    }

    /**
     * A unique id for this suggestion
     */
    public String getId() {
        return id;
    }

    /**
     * The ID of the `PickleStep` this `Suggestion` was created for.
     */
    public String getPickleStepId() {
        return pickleStepId;
    }

    /**
     * A collection of code snippets that could implement the undefined step
     */
    public java.util.List<Snippet> getSnippets() {
        return snippets;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Suggestion that = (Suggestion) o;
        return 
            id.equals(that.id) &&         
            pickleStepId.equals(that.pickleStepId) &&         
            snippets.equals(that.snippets);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            id,
            pickleStepId,
            snippets
        );
    }

    @Override
    public String toString() {
        return "Suggestion{" +
            "id=" + id +
            ", pickleStepId=" + pickleStepId +
            ", snippets=" + snippets +
            '}';
    }
}
