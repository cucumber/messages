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
     * The programming language of the code.
     * <p>
     * This must be formatted as an all lowercase identifier such that syntax highlighters like [Prism](https://prismjs.com/#supported-languages) or [Highlight.js](https://github.com/highlightjs/highlight.js/blob/main/SUPPORTED_LANGUAGES.md) can recognize it.
     * For example: `cpp`, `cs`, `go`, `java`, `javascript`, `php`, `python`, `ruby`, `scala`.
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
