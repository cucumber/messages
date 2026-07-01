package io.cucumber.messages.types;

import io.cucumber.messages.Property;
import org.jspecify.annotations.Nullable;

import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the RuleChild message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A child node of a `Rule` node
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class RuleChild {

    private final OneOf oneOf;

    public static RuleChild of(Background background) {
        return new RuleChild(
            requireNonNull(background, "RuleChild.background cannot be null"),
            null
        );
    }

    public static RuleChild of(Scenario scenario) {
        return new RuleChild(
            null,
            requireNonNull(scenario, "RuleChild.scenario cannot be null")
        );
    }

    public RuleChild(
        @Nullable @Property("background") Background background,
        @Nullable @Property("scenario") Scenario scenario
    ) {
        this.oneOf = OneOf.of(
            "RuleChild",
            "background", background,
            "scenario", scenario
        );
    }

    public Optional<Background> getBackground() {
        return oneOf.get("background");
    }

    public Optional<Scenario> getScenario() {
        return oneOf.get("scenario");
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        RuleChild that = (RuleChild) o;
        return Objects.equals(oneOf, that.oneOf);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(oneOf);
    }

    @Override
    public String toString() {
        return "RuleChild{" + oneOf + "}";
    }
}
