package io.cucumber.messages.types;

import org.jspecify.annotations.Nullable;

import java.util.List;
import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Ci message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * CI environment
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Ci {
    private final String name;
    private final @Nullable String url;
    private final @Nullable String buildNumber;
    private final @Nullable Git git;

    public Ci(
        String name,
        @Nullable String url,
        @Nullable String buildNumber,
        @Nullable Git git
    ) {
        this.name = requireNonNull(name, "Ci.name cannot be null");
        this.url = url;
        this.buildNumber = buildNumber;
        this.git = git;
    }

    /**
     * Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
     */
    public String getName() {
        return name;
    }

    /**
     * Link to the build
     */
    public Optional<String> getUrl() {
        return Optional.ofNullable(url);
    }

    /**
     * The build number. Some CI servers use non-numeric build numbers, which is why this is a string
     */
    public Optional<String> getBuildNumber() {
        return Optional.ofNullable(buildNumber);
    }

    public Optional<Git> getGit() {
        return Optional.ofNullable(git);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Ci that = (Ci) o;
        return 
            name.equals(that.name) &&         
            Objects.equals(url, that.url) &&         
            Objects.equals(buildNumber, that.buildNumber) &&         
            Objects.equals(git, that.git);        
    }

    @Override
    public int hashCode() {
        return Objects.hash(
            name,
            url,
            buildNumber,
            git
        );
    }

    @Override
    public String toString() {
        return "Ci{" +
            "name=" + name +
            ", url=" + url +
            ", buildNumber=" + buildNumber +
            ", git=" + git +
            '}';
    }
}
