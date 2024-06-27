using System;
using System.Collections.Generic;

namespace io.cucumber.messages.types;

/**
 * Represents the Envelope message in Cucumber's message protocol
 * @see <a href="https://github.com/cucumber/messages" >Github - Cucumber - Messages</a>
 *
 * When removing a field, replace it with reserved, rather than deleting the line.
 * When adding a field, add it to the end and increment the number by one.
 * See https://developers.google.com/protocol-buffers/docs/proto#updating for details
 *
 * All the messages that are passed between different components/processes are Envelope
 * messages.
 */
// Generated code
public sealed class Envelope {
    public Attachment? Attachment { get; private set; }
    public GherkinDocument? GherkinDocument { get; private set; }
    public Hook? Hook { get; private set; }
    public Meta? Meta { get; private set; }
    public ParameterType? ParameterType { get; private set; }
    public ParseError? ParseError { get; private set; }
    public Pickle? Pickle { get; private set; }
    public Source? Source { get; private set; }
    public StepDefinition? StepDefinition { get; private set; }
    public TestCase? TestCase { get; private set; }
    public TestCaseFinished? TestCaseFinished { get; private set; }
    public TestCaseStarted? TestCaseStarted { get; private set; }
    public TestRunFinished? TestRunFinished { get; private set; }
    public TestRunStarted? TestRunStarted { get; private set; }
    public TestStepFinished? TestStepFinished { get; private set; }
    public TestStepStarted? TestStepStarted { get; private set; }
    public UndefinedParameterType? UndefinedParameterType { get; private set; }

    public static Envelope Create(Attachment attachment) {
        return new Envelope(
            attachment,
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

    public static Envelope Create(GherkinDocument gherkinDocument) {
        return new Envelope(
            null,
            gherkinDocument,
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

    public static Envelope Create(Hook hook) {
        return new Envelope(
            null,
            null,
            hook,
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

    public static Envelope Create(Meta meta) {
        return new Envelope(
            null,
            null,
            null,
            meta,
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

    public static Envelope Create(ParameterType parameterType) {
        return new Envelope(
            null,
            null,
            null,
            null,
            parameterType,
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

    public static Envelope Create(ParseError parseError) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            parseError,
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

    public static Envelope Create(Pickle pickle) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            pickle,
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

    public static Envelope Create(Source source) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            source,
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

    public static Envelope Create(StepDefinition stepDefinition) {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            stepDefinition,
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

    public static Envelope Create(TestCase testCase) {
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
            testCase,
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestCaseFinished testCaseFinished) {
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
            testCaseFinished,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestCaseStarted testCaseStarted) {
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
            testCaseStarted,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestRunFinished testRunFinished) {
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
            testRunFinished,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestRunStarted testRunStarted) {
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
            testRunStarted,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestStepFinished testStepFinished) {
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
            testStepFinished,
            null,
            null
        );
    }

    public static Envelope Create(TestStepStarted testStepStarted) {
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
            testStepStarted,
            null
        );
    }

    public static Envelope Create(UndefinedParameterType undefinedParameterType) {
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
            undefinedParameterType
        );
    }

    public Envelope(
        Attachment attachment,
        GherkinDocument gherkinDocument,
        Hook hook,
        Meta meta,
        ParameterType parameterType,
        ParseError parseError,
        Pickle pickle,
        Source source,
        StepDefinition stepDefinition,
        TestCase testCase,
        TestCaseFinished testCaseFinished,
        TestCaseStarted testCaseStarted,
        TestRunFinished testRunFinished,
        TestRunStarted testRunStarted,
        TestStepFinished testStepFinished,
        TestStepStarted testStepStarted,
        UndefinedParameterType undefinedParameterType
    ) 
    {
        this.Attachment = attachment;
        this.GherkinDocument = gherkinDocument;
        this.Hook = hook;
        this.Meta = meta;
        this.ParameterType = parameterType;
        this.ParseError = parseError;
        this.Pickle = pickle;
        this.Source = source;
        this.StepDefinition = stepDefinition;
        this.TestCase = testCase;
        this.TestCaseFinished = testCaseFinished;
        this.TestCaseStarted = testCaseStarted;
        this.TestRunFinished = testRunFinished;
        this.TestRunStarted = testRunStarted;
        this.TestStepFinished = testStepFinished;
        this.TestStepStarted = testStepStarted;
        this.UndefinedParameterType = undefinedParameterType;
    }

    public override bool Equals(Object o) {
        if (this == o) return true;
        if (o == null || this.GetType() != o.GetType()) return false;
        Envelope that = (Envelope) o;
        return 
            Object.Equals(Attachment, that.Attachment) &&         
            Object.Equals(GherkinDocument, that.GherkinDocument) &&         
            Object.Equals(Hook, that.Hook) &&         
            Object.Equals(Meta, that.Meta) &&         
            Object.Equals(ParameterType, that.ParameterType) &&         
            Object.Equals(ParseError, that.ParseError) &&         
            Object.Equals(Pickle, that.Pickle) &&         
            Object.Equals(Source, that.Source) &&         
            Object.Equals(StepDefinition, that.StepDefinition) &&         
            Object.Equals(TestCase, that.TestCase) &&         
            Object.Equals(TestCaseFinished, that.TestCaseFinished) &&         
            Object.Equals(TestCaseStarted, that.TestCaseStarted) &&         
            Object.Equals(TestRunFinished, that.TestRunFinished) &&         
            Object.Equals(TestRunStarted, that.TestRunStarted) &&         
            Object.Equals(TestStepFinished, that.TestStepFinished) &&         
            Object.Equals(TestStepStarted, that.TestStepStarted) &&         
            Object.Equals(UndefinedParameterType, that.UndefinedParameterType);        
    }

    public override int GetHashCode() {
        int hash = 17;
        hash = hash * 31 + Attachment?.GetHashCode()?? 0;
        hash = hash * 31 + GherkinDocument?.GetHashCode()?? 0;
        hash = hash * 31 + Hook?.GetHashCode()?? 0;
        hash = hash * 31 + Meta?.GetHashCode()?? 0;
        hash = hash * 31 + ParameterType?.GetHashCode()?? 0;
        hash = hash * 31 + ParseError?.GetHashCode()?? 0;
        hash = hash * 31 + Pickle?.GetHashCode()?? 0;
        hash = hash * 31 + Source?.GetHashCode()?? 0;
        hash = hash * 31 + StepDefinition?.GetHashCode()?? 0;
        hash = hash * 31 + TestCase?.GetHashCode()?? 0;
        hash = hash * 31 + TestCaseFinished?.GetHashCode()?? 0;
        hash = hash * 31 + TestCaseStarted?.GetHashCode()?? 0;
        hash = hash * 31 + TestRunFinished?.GetHashCode()?? 0;
        hash = hash * 31 + TestRunStarted?.GetHashCode()?? 0;
        hash = hash * 31 + TestStepFinished?.GetHashCode()?? 0;
        hash = hash * 31 + TestStepStarted?.GetHashCode()?? 0;
        hash = hash * 31 + UndefinedParameterType?.GetHashCode()?? 0;
        return hash;
    }

    public override string ToString() {
        return "Envelope{" +
            "attachment=" + Attachment +
            ", gherkinDocument=" + GherkinDocument +
            ", hook=" + Hook +
            ", meta=" + Meta +
            ", parameterType=" + ParameterType +
            ", parseError=" + ParseError +
            ", pickle=" + Pickle +
            ", source=" + Source +
            ", stepDefinition=" + StepDefinition +
            ", testCase=" + TestCase +
            ", testCaseFinished=" + TestCaseFinished +
            ", testCaseStarted=" + TestCaseStarted +
            ", testRunFinished=" + TestRunFinished +
            ", testRunStarted=" + TestRunStarted +
            ", testStepFinished=" + TestStepFinished +
            ", testStepStarted=" + TestStepStarted +
            ", undefinedParameterType=" + UndefinedParameterType +
            '}';
    }
}
