package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the ParameterType message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class ParameterType {
    private final String name;
    private final java.util.List<String> regularExpressions;
    private final Boolean preferForRegularExpressionMatch;
    private final Boolean useForSnippets;
    private final String id;
    private final SourceReference sourceReference;

    public ParameterType(
        String name,
        java.util.List<String> regularExpressions,
        Boolean preferForRegularExpressionMatch,
        Boolean useForSnippets,
        String id,
        SourceReference sourceReference
    ) {
        this.name = requireNonNull(name, "ParameterType.name cannot be null");
        this.regularExpressions = unmodifiableList(new ArrayList<>(requireNonNull(regularExpressions, "ParameterType.regularExpressions cannot be null")));
        this.preferForRegularExpressionMatch = requireNonNull(preferForRegularExpressionMatch, "ParameterType.preferForRegularExpressionMatch cannot be null");
        this.useForSnippets = requireNonNull(useForSnippets, "ParameterType.useForSnippets cannot be null");
        this.id = requireNonNull(id, "ParameterType.id cannot be null");
        this.sourceReference = sourceReference;
    }

    /**
     * The name is unique, so we don't need an id.
     */
    public String getName() {
        return name;
    }

    public java.util.List<String> getRegularExpressions() {
        return regularExpressions;
    }

    public Boolean getPreferForRegularExpressionMatch() {
        return preferForRegularExpressionMatch;
    }

    public Boolean getUseForSnippets() {
        return useForSnippets;
    }

    public String getId() {
        return id;
    }

    public Optional<SourceReference> getSourceReference() {
        return Optional.ofNullable(sourceReference);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ParameterType that = (ParameterType) o;
        return 
            name.equals(that.name) &&         
            regularExpressions.equals(that.regularExpressions) &&         
            preferForRegularExpressionMatch.equals(that.preferForRegularExpressionMatch) &&         
            useForSnippets.equals(that.useForSnippets) &&         
            id.equals(that.id) &&         
            Objects.equals(sourceReference, that.sourceReference);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            name,
            regularExpressions,
            preferForRegularExpressionMatch,
            useForSnippets,
            id,
            sourceReference
        );
    }

    @Override
    public String toString() {
        return "ParameterType{" +
            "name=" + name +
            ", regularExpressions=" + regularExpressions +
            ", preferForRegularExpressionMatch=" + preferForRegularExpressionMatch +
            ", useForSnippets=" + useForSnippets +
            ", id=" + id +
            ", sourceReference=" + sourceReference +
            '}';
    }
}
