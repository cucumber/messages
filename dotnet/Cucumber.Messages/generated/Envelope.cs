
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

public sealed record Envelope 
{
    public Attachment? Attachment { get; }
    public GherkinDocument? GherkinDocument { get; }
    public Hook? Hook { get; }
    public Meta? Meta { get; }
    public ParameterType? ParameterType { get; }
    public ParseError? ParseError { get; }
    public Pickle? Pickle { get; }
    public Source? Source { get; }
    public StepDefinition? StepDefinition { get; }
    public TestCase? TestCase { get; }
    public TestCaseFinished? TestCaseFinished { get; }
    public TestCaseStarted? TestCaseStarted { get; }
    public TestRunFinished? TestRunFinished { get; }
    public TestRunStarted? TestRunStarted { get; }
    public TestStepFinished? TestStepFinished { get; }
    public TestStepStarted? TestStepStarted { get; }
    public UndefinedParameterType? UndefinedParameterType { get; }


    public static Envelope Create(Attachment attachment) 
    {
        return new Envelope(
            attachment ?? throw new ArgumentNullException("Attachment", "Envelope.Attachment cannot be null"),
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
            gherkinDocument ?? throw new ArgumentNullException("GherkinDocument", "Envelope.GherkinDocument cannot be null"),
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
            hook ?? throw new ArgumentNullException("Hook", "Envelope.Hook cannot be null"),
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
            meta ?? throw new ArgumentNullException("Meta", "Envelope.Meta cannot be null"),
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
            parameterType ?? throw new ArgumentNullException("ParameterType", "Envelope.ParameterType cannot be null"),
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
            parseError ?? throw new ArgumentNullException("ParseError", "Envelope.ParseError cannot be null"),
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
            pickle ?? throw new ArgumentNullException("Pickle", "Envelope.Pickle cannot be null"),
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
            source ?? throw new ArgumentNullException("Source", "Envelope.Source cannot be null"),
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
            stepDefinition ?? throw new ArgumentNullException("StepDefinition", "Envelope.StepDefinition cannot be null"),
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
            testCase ?? throw new ArgumentNullException("TestCase", "Envelope.TestCase cannot be null"),
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
            testCaseFinished ?? throw new ArgumentNullException("TestCaseFinished", "Envelope.TestCaseFinished cannot be null"),
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
            testCaseStarted ?? throw new ArgumentNullException("TestCaseStarted", "Envelope.TestCaseStarted cannot be null"),
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
            testRunFinished ?? throw new ArgumentNullException("TestRunFinished", "Envelope.TestRunFinished cannot be null"),
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
            testRunStarted ?? throw new ArgumentNullException("TestRunStarted", "Envelope.TestRunStarted cannot be null"),
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
            testStepFinished ?? throw new ArgumentNullException("TestStepFinished", "Envelope.TestStepFinished cannot be null"),
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
            testStepStarted ?? throw new ArgumentNullException("TestStepStarted", "Envelope.TestStepStarted cannot be null"),
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
            undefinedParameterType ?? throw new ArgumentNullException("UndefinedParameterType", "Envelope.UndefinedParameterType cannot be null")
        );
    }

    public Envelope(
        Attachment? attachment,
        GherkinDocument? gherkinDocument,
        Hook? hook,
        Meta? meta,
        ParameterType? parameterType,
        ParseError? parseError,
        Pickle? pickle,
        Source? source,
        StepDefinition? stepDefinition,
        TestCase? testCase,
        TestCaseFinished? testCaseFinished,
        TestCaseStarted? testCaseStarted,
        TestRunFinished? testRunFinished,
        TestRunStarted? testRunStarted,
        TestStepFinished? testStepFinished,
        TestStepStarted? testStepStarted,
        UndefinedParameterType? undefinedParameterType
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
}
