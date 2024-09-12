using System;
using System.Collections.Generic;

// ------------------------------------------------------------------------------
// This code was generated based on the Cucumber JSON schema
// Changes to this file may cause incorrect behavior and will be lost if 
// the code is regenerated.
// ------------------------------------------------------------------------------

namespace Io.Cucumber.Messages.Types;

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

public sealed class Envelope 
{
    public Attachment Attachment { get; private set; }
    public GherkinDocument GherkinDocument { get; private set; }
    public Hook Hook { get; private set; }
    public Meta Meta { get; private set; }
    public ParameterType ParameterType { get; private set; }
    public ParseError ParseError { get; private set; }
    public Pickle Pickle { get; private set; }
    public Source Source { get; private set; }
    public StepDefinition StepDefinition { get; private set; }
    public TestCase TestCase { get; private set; }
    public TestCaseFinished TestCaseFinished { get; private set; }
    public TestCaseStarted TestCaseStarted { get; private set; }
    public TestRunFinished TestRunFinished { get; private set; }
    public TestRunStarted TestRunStarted { get; private set; }
    public TestStepFinished TestStepFinished { get; private set; }
    public TestStepStarted TestStepStarted { get; private set; }
    public UndefinedParameterType UndefinedParameterType { get; private set; }


    public static Envelope Create(Attachment attachment) 
    {
        return new Envelope(
            Require<Attachment>(attachment, "Attachment", "Envelope.Attachment cannot be null"),
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

    public static Envelope Create(GherkinDocument gherkinDocument) 
    {
        return new Envelope(
            null,
            Require<GherkinDocument>(gherkinDocument, "GherkinDocument", "Envelope.GherkinDocument cannot be null"),
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

    public static Envelope Create(Hook hook) 
    {
        return new Envelope(
            null,
            null,
            Require<Hook>(hook, "Hook", "Envelope.Hook cannot be null"),
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

    public static Envelope Create(Meta meta) 
    {
        return new Envelope(
            null,
            null,
            null,
            Require<Meta>(meta, "Meta", "Envelope.Meta cannot be null"),
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

    public static Envelope Create(ParameterType parameterType) 
    {
        return new Envelope(
            null,
            null,
            null,
            null,
            Require<ParameterType>(parameterType, "ParameterType", "Envelope.ParameterType cannot be null"),
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

    public static Envelope Create(ParseError parseError) 
    {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            Require<ParseError>(parseError, "ParseError", "Envelope.ParseError cannot be null"),
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

    public static Envelope Create(Pickle pickle) 
    {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            Require<Pickle>(pickle, "Pickle", "Envelope.Pickle cannot be null"),
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

    public static Envelope Create(Source source) 
    {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            Require<Source>(source, "Source", "Envelope.Source cannot be null"),
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

    public static Envelope Create(StepDefinition stepDefinition) 
    {
        return new Envelope(
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            null,
            Require<StepDefinition>(stepDefinition, "StepDefinition", "Envelope.StepDefinition cannot be null"),
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

    public static Envelope Create(TestCase testCase) 
    {
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
            Require<TestCase>(testCase, "TestCase", "Envelope.TestCase cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestCaseFinished testCaseFinished) 
    {
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
            Require<TestCaseFinished>(testCaseFinished, "TestCaseFinished", "Envelope.TestCaseFinished cannot be null"),
            null,
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestCaseStarted testCaseStarted) 
    {
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
            Require<TestCaseStarted>(testCaseStarted, "TestCaseStarted", "Envelope.TestCaseStarted cannot be null"),
            null,
            null,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestRunFinished testRunFinished) 
    {
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
            Require<TestRunFinished>(testRunFinished, "TestRunFinished", "Envelope.TestRunFinished cannot be null"),
            null,
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestRunStarted testRunStarted) 
    {
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
            Require<TestRunStarted>(testRunStarted, "TestRunStarted", "Envelope.TestRunStarted cannot be null"),
            null,
            null,
            null
        );
    }

    public static Envelope Create(TestStepFinished testStepFinished) 
    {
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
            Require<TestStepFinished>(testStepFinished, "TestStepFinished", "Envelope.TestStepFinished cannot be null"),
            null,
            null
        );
    }

    public static Envelope Create(TestStepStarted testStepStarted) 
    {
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
            Require<TestStepStarted>(testStepStarted, "TestStepStarted", "Envelope.TestStepStarted cannot be null"),
            null
        );
    }

    public static Envelope Create(UndefinedParameterType undefinedParameterType) 
    {
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
            Require<UndefinedParameterType>(undefinedParameterType, "UndefinedParameterType", "Envelope.UndefinedParameterType cannot be null")
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

    public override bool Equals(Object o) 
    {
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

    public override int GetHashCode() 
    {
        int hash = 17;
        if (Attachment != null)
          hash = hash * 31 + Attachment.GetHashCode();
        if (GherkinDocument != null)
          hash = hash * 31 + GherkinDocument.GetHashCode();
        if (Hook != null)
          hash = hash * 31 + Hook.GetHashCode();
        if (Meta != null)
          hash = hash * 31 + Meta.GetHashCode();
        if (ParameterType != null)
          hash = hash * 31 + ParameterType.GetHashCode();
        if (ParseError != null)
          hash = hash * 31 + ParseError.GetHashCode();
        if (Pickle != null)
          hash = hash * 31 + Pickle.GetHashCode();
        if (Source != null)
          hash = hash * 31 + Source.GetHashCode();
        if (StepDefinition != null)
          hash = hash * 31 + StepDefinition.GetHashCode();
        if (TestCase != null)
          hash = hash * 31 + TestCase.GetHashCode();
        if (TestCaseFinished != null)
          hash = hash * 31 + TestCaseFinished.GetHashCode();
        if (TestCaseStarted != null)
          hash = hash * 31 + TestCaseStarted.GetHashCode();
        if (TestRunFinished != null)
          hash = hash * 31 + TestRunFinished.GetHashCode();
        if (TestRunStarted != null)
          hash = hash * 31 + TestRunStarted.GetHashCode();
        if (TestStepFinished != null)
          hash = hash * 31 + TestStepFinished.GetHashCode();
        if (TestStepStarted != null)
          hash = hash * 31 + TestStepStarted.GetHashCode();
        if (UndefinedParameterType != null)
          hash = hash * 31 + UndefinedParameterType.GetHashCode();
        return hash;
    }

    public override string ToString() 
    {
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

    private static T Require<T>(T property, string propertyName, string errorMessage)
    {
      RequireNonNull<T>(property, propertyName, errorMessage);
      return property;
    }
    private static void RequireNonNull<T>(T property, string propertyName, string errorMessage) 
    {
      if (property == null) throw new ArgumentNullException(propertyName, errorMessage);
    }
}
