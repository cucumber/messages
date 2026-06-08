package io.cucumber.messages.types;

import io.cucumber.messages.Property;
import org.jspecify.annotations.Nullable;

import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the FeatureChild message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 * <p>
 * A child node of a `Feature` node
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class FeatureChild {

    private final OneOf oneOf;

    public static FeatureChild of(Rule rule) {
        return new FeatureChild(
            requireNonNull(rule, "FeatureChild.rule cannot be null"),
            null,
            null
        );
    }

    public static FeatureChild of(Background background) {
        return new FeatureChild(
            null,
            requireNonNull(background, "FeatureChild.background cannot be null"),
            null
        );
    }

    public static FeatureChild of(Scenario scenario) {
        return new FeatureChild(
            null,
            null,
            requireNonNull(scenario, "FeatureChild.scenario cannot be null")
        );
    }

    public FeatureChild(
        @Nullable @Property("rule") Rule rule,
        @Nullable @Property("background") Background background,
        @Nullable @Property("scenario") Scenario scenario
    ) {
        this.oneOf = OneOf.of(
            "FeatureChild",
            "rule", rule,
            "background", background,
            "scenario", scenario
        );
    }

    public Optional<Rule> getRule() {
        return oneOf.get("rule");
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
        FeatureChild that = (FeatureChild) o;
        return Objects.equals(oneOf, that.oneOf);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(oneOf);
    }

    @Override
    public String toString() {
        return "FeatureChild{" + oneOf + "}";
    }
}
