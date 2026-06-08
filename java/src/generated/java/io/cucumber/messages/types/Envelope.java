package io.cucumber.messages.types;

import io.cucumber.messages.Property;
import org.jspecify.annotations.Nullable;

import java.util.Objects;
import java.util.Optional;

import static java.util.Objects.requireNonNull;

/**
 * Represents the Envelope message in <a href=https://github.com/cucumber/messages>Cucumber's message protocol</a>
 */
// Generated code
@SuppressWarnings({"unused", "JavaLangClash"})
public final class Envelope {

    private final OneOf oneOf;

    public static Envelope of(Attachment attachment) {
        return new Envelope(
            requireNonNull(attachment, "Envelope.attachment cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(ExternalAttachment externalAttachment) {
        return new Envelope(
            null,
            requireNonNull(externalAttachment, "Envelope.externalAttachment cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(GherkinDocument gherkinDocument) {
        return new Envelope(
            null,
            null,
            requireNonNull(gherkinDocument, "Envelope.gherkinDocument cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(Hook hook) {
        return new Envelope(
            null,
            null,
            null,
            requireNonNull(hook, "Envelope.hook cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(Meta meta) {
        return new Envelope(
            null,
            null,
            null,
            null,
            requireNonNull(meta, "Envelope.meta cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(ParameterType parameterType) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            requireNonNull(parameterType, "Envelope.parameterType cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(ParseError parseError) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(parseError, "Envelope.parseError cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(Pickle pickle) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(pickle, "Envelope.pickle cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(Suggestion suggestion) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(suggestion, "Envelope.suggestion cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(Source source) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(source, "Envelope.source cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(StepDefinition stepDefinition) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(stepDefinition, "Envelope.stepDefinition cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(TestCase testCase) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testCase, "Envelope.testCase cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(TestCaseFinished testCaseFinished) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testCaseFinished, "Envelope.testCaseFinished cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(TestCaseStarted testCaseStarted) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testCaseStarted, "Envelope.testCaseStarted cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(TestRunFinished testRunFinished) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testRunFinished, "Envelope.testRunFinished cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(TestRunStarted testRunStarted) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testRunStarted, "Envelope.testRunStarted cannot be null"),
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(TestStepFinished testStepFinished) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testStepFinished, "Envelope.testStepFinished cannot be null"),
            null,
            null,
            null,
            null
        );
    }

    public static Envelope of(TestStepStarted testStepStarted) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testStepStarted, "Envelope.testStepStarted cannot be null"),
            null,
            null,
            null
        );
    }

    public static Envelope of(TestRunHookStarted testRunHookStarted) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testRunHookStarted, "Envelope.testRunHookStarted cannot be null"),
            null,
            null
        );
    }

    public static Envelope of(TestRunHookFinished testRunHookFinished) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(testRunHookFinished, "Envelope.testRunHookFinished cannot be null"),
            null
        );
    }

    public static Envelope of(UndefinedParameterType undefinedParameterType) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            requireNonNull(undefinedParameterType, "Envelope.undefinedParameterType cannot be null")
        );
    }

    public Envelope(
        @Nullable @Property("attachment") Attachment attachment,
        @Nullable @Property("externalAttachment") ExternalAttachment externalAttachment,
        @Nullable @Property("gherkinDocument") GherkinDocument gherkinDocument,
        @Nullable @Property("hook") Hook hook,
        @Nullable @Property("meta") Meta meta,
        @Nullable @Property("parameterType") ParameterType parameterType,
        @Nullable @Property("parseError") ParseError parseError,
        @Nullable @Property("pickle") Pickle pickle,
        @Nullable @Property("suggestion") Suggestion suggestion,
        @Nullable @Property("source") Source source,
        @Nullable @Property("stepDefinition") StepDefinition stepDefinition,
        @Nullable @Property("testCase") TestCase testCase,
        @Nullable @Property("testCaseFinished") TestCaseFinished testCaseFinished,
        @Nullable @Property("testCaseStarted") TestCaseStarted testCaseStarted,
        @Nullable @Property("testRunFinished") TestRunFinished testRunFinished,
        @Nullable @Property("testRunStarted") TestRunStarted testRunStarted,
        @Nullable @Property("testStepFinished") TestStepFinished testStepFinished,
        @Nullable @Property("testStepStarted") TestStepStarted testStepStarted,
        @Nullable @Property("testRunHookStarted") TestRunHookStarted testRunHookStarted,
        @Nullable @Property("testRunHookFinished") TestRunHookFinished testRunHookFinished,
        @Nullable @Property("undefinedParameterType") UndefinedParameterType undefinedParameterType
    ) {
        this.oneOf = OneOf.of(
            "Envelope",
            "attachment", attachment,
            "externalAttachment", externalAttachment,
            "gherkinDocument", gherkinDocument,
            "hook", hook,
            "meta", meta,
            "parameterType", parameterType,
            "parseError", parseError,
            "pickle", pickle,
            "suggestion", suggestion,
            "source", source,
            "stepDefinition", stepDefinition,
            "testCase", testCase,
            "testCaseFinished", testCaseFinished,
            "testCaseStarted", testCaseStarted,
            "testRunFinished", testRunFinished,
            "testRunStarted", testRunStarted,
            "testStepFinished", testStepFinished,
            "testStepStarted", testStepStarted,
            "testRunHookStarted", testRunHookStarted,
            "testRunHookFinished", testRunHookFinished,
            "undefinedParameterType", undefinedParameterType
        );
    }

    public Optional<Attachment> getAttachment() {
        return oneOf.get("attachment");
    }

    public Optional<ExternalAttachment> getExternalAttachment() {
        return oneOf.get("externalAttachment");
    }

    public Optional<GherkinDocument> getGherkinDocument() {
        return oneOf.get("gherkinDocument");
    }

    public Optional<Hook> getHook() {
        return oneOf.get("hook");
    }

    public Optional<Meta> getMeta() {
        return oneOf.get("meta");
    }

    public Optional<ParameterType> getParameterType() {
        return oneOf.get("parameterType");
    }

    public Optional<ParseError> getParseError() {
        return oneOf.get("parseError");
    }

    public Optional<Pickle> getPickle() {
        return oneOf.get("pickle");
    }

    public Optional<Suggestion> getSuggestion() {
        return oneOf.get("suggestion");
    }

    public Optional<Source> getSource() {
        return oneOf.get("source");
    }

    public Optional<StepDefinition> getStepDefinition() {
        return oneOf.get("stepDefinition");
    }

    public Optional<TestCase> getTestCase() {
        return oneOf.get("testCase");
    }

    public Optional<TestCaseFinished> getTestCaseFinished() {
        return oneOf.get("testCaseFinished");
    }

    public Optional<TestCaseStarted> getTestCaseStarted() {
        return oneOf.get("testCaseStarted");
    }

    public Optional<TestRunFinished> getTestRunFinished() {
        return oneOf.get("testRunFinished");
    }

    public Optional<TestRunStarted> getTestRunStarted() {
        return oneOf.get("testRunStarted");
    }

    public Optional<TestStepFinished> getTestStepFinished() {
        return oneOf.get("testStepFinished");
    }

    public Optional<TestStepStarted> getTestStepStarted() {
        return oneOf.get("testStepStarted");
    }

    public Optional<TestRunHookStarted> getTestRunHookStarted() {
        return oneOf.get("testRunHookStarted");
    }

    public Optional<TestRunHookFinished> getTestRunHookFinished() {
        return oneOf.get("testRunHookFinished");
    }

    public Optional<UndefinedParameterType> getUndefinedParameterType() {
        return oneOf.get("undefinedParameterType");
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Envelope envelope = (Envelope) o;
        return Objects.equals(oneOf, envelope.oneOf);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(oneOf);
    }

    @Override
    public String toString() {
        return "Envelope{" + oneOf + "}";
    }
}
