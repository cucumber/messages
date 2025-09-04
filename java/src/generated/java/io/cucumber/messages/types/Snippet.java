package io.cucumber.messages.types;

import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

import static java.util.Collections.unmodifiableList;
import static java.util.Objects.requireNonNull;

/**
 * Represents the Snippet message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings("unused")
public final class Snippet {
    private final String language;
    private final String code;

    public Snippet(
        String language,
        String code
    ) {
        this.language = requireNonNull(language, "Snippet.language cannot be null");
        this.code = requireNonNull(code, "Snippet.code cannot be null");
    }

    /**
     * The programming language of the code
     */
    public String getLanguage() {
        return language;
    }

    /**
     * A snippet of code
     */
    public String getCode() {
        return code;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Snippet that = (Snippet) o;
        return 
            language.equals(that.language) &&         
            code.equals(that.code);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            language,
            code
        );
    }

    @Override
    public String toString() {
        return "Snippet{" +
            "language=" + language +
            ", code=" + code +
            '}';
    }
}
