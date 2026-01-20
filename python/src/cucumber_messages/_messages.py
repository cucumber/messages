# This code was generated using the code generator from cucumber-messages.
# Manual changes will be lost if the code is regenerated.
# Generator: cucumber-messages-python

from __future__ import annotations
from dataclasses import dataclass
from typing import Optional

from ._message_enums import *

@dataclass
class Attachment:
    """
    Attachments (parse errors, execution errors, screenshots, links...)

    An attachment represents any kind of data associated with a line in a
    [Source](#io.cucumber.messages.Source) file. It can be used for:

    * Syntax errors during parse time
    * Screenshots captured and attached during execution
    * Logs captured and attached during execution

    It is not to be used for runtime errors raised/thrown during execution. This
    is captured in `TestResult`.
    """
    body: str
    """
    The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
    is simply the string. If it's `BASE64`, the string should be Base64 decoded to
    obtain the attachment.
    """

    content_encoding: AttachmentContentEncoding
    """
    Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).

    Content encoding is *not* determined by the media type, but rather by the type
    of the object being attached:

    - string: IDENTITY
    - byte array: BASE64
    - stream: BASE64
    """

    media_type: str
    """
    The media type of the data. This can be any valid
    [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
    as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
    and `text/x.cucumber.stacktrace+plain`
    """

    file_name: Optional[str] = None  # Suggested file name of the attachment. (Provided by the user as an argument to `attach`)
    source: Optional[Source] = None
    test_case_started_id: Optional[str] = None  # The identifier of the test case attempt if the attachment was created during the execution of a test step
    test_run_hook_started_id: Optional[str] = None  # The identifier of the test run hook execution if the attachment was created during the execution of a test run hook
    test_run_started_id: Optional[str] = None  # Not used; implementers should instead populate `testRunHookStartedId` if an attachment was created during the execution of a test run hook
    test_step_id: Optional[str] = None  # The identifier of the test step if the attachment was created during the execution of a test step
    timestamp: Optional[Timestamp] = None  # When the attachment was created
    url: Optional[str] = None
    """
    A URL where the attachment can be retrieved. This field should not be set by Cucumber.
    It should be set by a program that reads a message stream and does the following for
    each Attachment message:

    - Writes the body (after base64 decoding if necessary) to a new file.
    - Sets `body` and `contentEncoding` to `null`
    - Writes out the new attachment message

    This will result in a smaller message stream, which can improve performance and
    reduce bandwidth of message consumers. It also makes it easier to process and download attachments
    separately from reports.
    """



@dataclass
class Duration:
    """
    The structure is pretty close of the Timestamp one. For clarity, a second type
    of message is used.
    """
    nanos: int
    """
    Non-negative fractions of a second at nanosecond resolution. Negative
    second values with fractions must still have non-negative nanos values
    that count forward in time. Must be from 0 to 999,999,999
    inclusive.
    """

    seconds: int


@dataclass
class Envelope:
    attachment: Optional[Attachment] = None
    external_attachment: Optional[ExternalAttachment] = None
    gherkin_document: Optional[GherkinDocument] = None
    hook: Optional[Hook] = None
    meta: Optional[Meta] = None
    parameter_type: Optional[ParameterType] = None
    parse_error: Optional[ParseError] = None
    pickle: Optional[Pickle] = None
    source: Optional[Source] = None
    step_definition: Optional[StepDefinition] = None
    suggestion: Optional[Suggestion] = None
    test_case: Optional[TestCase] = None
    test_case_finished: Optional[TestCaseFinished] = None
    test_case_started: Optional[TestCaseStarted] = None
    test_run_finished: Optional[TestRunFinished] = None
    test_run_hook_finished: Optional[TestRunHookFinished] = None
    test_run_hook_started: Optional[TestRunHookStarted] = None
    test_run_started: Optional[TestRunStarted] = None
    test_step_finished: Optional[TestStepFinished] = None
    test_step_started: Optional[TestStepStarted] = None
    undefined_parameter_type: Optional[UndefinedParameterType] = None


@dataclass
class Exception:
    """
    A simplified representation of an exception
    """
    type: str  # The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
    message: Optional[str] = None  # The message of exception that caused this result. E.g. expected: "a" but was: "b"
    stack_trace: Optional[str] = None  # The stringified stack trace of the exception that caused this result


@dataclass
class ExternalAttachment:
    """
    Represents an attachment that is stored externally rather than embedded in the message stream.

    This message type is used for large attachments (e.g., video files) that are already
    on the filesystem and should not be loaded into memory. Instead of embedding the content,
    only a URL reference is stored.

    A formatter or other consumer of messages may replace an Attachment with an ExternalAttachment if it makes sense to do so.
    """
    media_type: str
    """
    The media type of the data. This can be any valid
    [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
    as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
    and `text/x.cucumber.stacktrace+plain`
    """

    url: str
    """
    A URL where the attachment can be retrieved. This could be a file:// URL for
    local filesystem paths, or an http(s):// URL for remote resources.
    """

    test_case_started_id: Optional[str] = None  # The identifier of the test case attempt if the attachment was created during the execution of a test step
    test_run_hook_started_id: Optional[str] = None  # The identifier of the test run hook execution if the attachment was created during the execution of a test run hook
    test_step_id: Optional[str] = None  # The identifier of the test step if the attachment was created during the execution of a test step
    timestamp: Optional[Timestamp] = None  # When the attachment was created


@dataclass
class GherkinDocument:
    """
    The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
    Cucumber implementations should *not* depend on `GherkinDocument` or any of its
    children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.

    The only consumers of `GherkinDocument` should only be formatters that produce
    "rich" output, resembling the original Gherkin document.
    """
    comments: list[Comment]  # All the comments in the Gherkin document
    feature: Optional[Feature] = None
    uri: Optional[str] = None
    """
    The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
    of the source, typically a file path relative to the root directory
    """



@dataclass
class Background:
    description: str
    id: str
    keyword: str
    location: Location  # The location of the `Background` keyword
    name: str
    steps: list[Step]


@dataclass
class Comment:
    """
    A comment in a Gherkin document
    """
    location: Location  # The location of the comment
    text: str  # The text of the comment


@dataclass
class DataTable:
    location: Location
    rows: list[TableRow]


@dataclass
class DocString:
    content: str
    delimiter: str
    location: Location
    media_type: Optional[str] = None


@dataclass
class Examples:
    description: str
    id: str
    keyword: str
    location: Location  # The location of the `Examples` keyword
    name: str
    table_body: list[TableRow]
    tags: list[Tag]
    table_header: Optional[TableRow] = None


@dataclass
class Feature:
    children: list[FeatureChild]  # Zero or more children
    description: str  # The line(s) underneath the line with the `keyword` that are used as description
    keyword: str  # The text of the `Feature` keyword (in the language specified by `language`)
    language: str  # The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document
    location: Location  # The location of the `Feature` keyword
    name: str  # The name of the feature (the text following the `keyword`)
    tags: list[Tag]  # All the tags placed above the `Feature` keyword


@dataclass
class FeatureChild:
    """
    A child node of a `Feature` node
    """
    background: Optional[Background] = None
    rule: Optional[Rule] = None
    scenario: Optional[Scenario] = None


@dataclass
class Rule:
    children: list[RuleChild]
    description: str
    id: str
    keyword: str
    location: Location  # The location of the `Rule` keyword
    name: str
    tags: list[Tag]  # All the tags placed above the `Rule` keyword


@dataclass
class RuleChild:
    """
    A child node of a `Rule` node
    """
    background: Optional[Background] = None
    scenario: Optional[Scenario] = None


@dataclass
class Scenario:
    description: str
    examples: list[Examples]
    id: str
    keyword: str
    location: Location  # The location of the `Scenario` keyword
    name: str
    steps: list[Step]
    tags: list[Tag]


@dataclass
class Step:
    """
    A step
    """
    id: str  # Unique ID to be able to reference the Step from PickleStep
    keyword: str  # The actual keyword as it appeared in the source.
    location: Location  # The location of the steps' `keyword`
    text: str
    data_table: Optional[DataTable] = None
    doc_string: Optional[DocString] = None
    keyword_type: Optional[StepKeywordType] = None  # The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.


@dataclass
class TableCell:
    """
    A cell in a `TableRow`
    """
    location: Location  # The location of the cell
    value: str  # The value of the cell


@dataclass
class TableRow:
    """
    A row in a table
    """
    cells: list[TableCell]  # Cells in the row
    id: str
    location: Location  # The location of the first cell in the row


@dataclass
class Tag:
    """
    A tag
    """
    id: str  # Unique ID to be able to reference the Tag from PickleTag
    location: Location  # Location of the tag
    name: str  # The name of the tag (including the leading `@`)


@dataclass
class Hook:
    id: str
    source_reference: SourceReference
    name: Optional[str] = None
    tag_expression: Optional[str] = None
    type: Optional[HookType] = None


@dataclass
class Location:
    """
    Points to a line and a column in a text file
    """
    line: int
    column: Optional[int] = None


@dataclass
class Meta:
    """
    This message contains meta information about the environment. Consumers can use
    this for various purposes.
    """
    cpu: Product  # 386, arm, amd64 etc
    implementation: Product  # SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.
    os: Product  # Windows, Linux, MacOS etc
    protocol_version: str  # The [SEMVER](https://semver.org/) version number of the protocol
    runtime: Product  # Java, Ruby, Node.js etc
    ci: Optional[Ci] = None


@dataclass
class Ci:
    """
    CI environment
    """
    name: str  # Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
    build_number: Optional[str] = None  # The build number. Some CI servers use non-numeric build numbers, which is why this is a string
    git: Optional[Git] = None
    url: Optional[str] = None  # Link to the build


@dataclass
class Git:
    """
    Information about Git, provided by the Build/CI server as environment
    variables.
    """
    remote: str
    revision: str
    branch: Optional[str] = None
    tag: Optional[str] = None


@dataclass
class Product:
    """
    Used to describe various properties of Meta
    """
    name: str  # The product name
    version: Optional[str] = None  # The product version


@dataclass
class ParameterType:
    id: str
    name: str  # The name is unique, so we don't need an id.
    prefer_for_regular_expression_match: bool
    regular_expressions: list[str]
    use_for_snippets: bool
    source_reference: Optional[SourceReference] = None


@dataclass
class ParseError:
    message: str
    source: SourceReference


@dataclass
class Pickle:
    """
    A `Pickle` represents a template for a `TestCase`. It is typically derived
    from another format, such as [GherkinDocument](#io.cucumber.messages.GherkinDocument).
    In the future a `Pickle` may be derived from other formats such as Markdown or
    Excel files.

    By making `Pickle` the main data structure Cucumber uses for execution, the
    implementation of Cucumber itself becomes simpler, as it doesn't have to deal
    with the complex structure of a [GherkinDocument](#io.cucumber.messages.GherkinDocument).

    Each `PickleStep` of a `Pickle` is matched with a `StepDefinition` to create a `TestCase`
    """
    ast_node_ids: list[str]
    """
    Points to the AST node locations of the pickle. The last one represents the unique
    id of the pickle. A pickle constructed from `Examples` will have the first
    id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.
    """

    id: str  # A unique id for the pickle
    language: str  # The language of the pickle
    name: str  # The name of the pickle
    steps: list[PickleStep]  # One or more steps
    tags: list[PickleTag]
    """
    One or more tags. If this pickle is constructed from a Gherkin document,
    It includes inherited tags from the `Feature` as well.
    """

    uri: str  # The uri of the source file
    location: Optional[Location] = None  # The location of this pickle in source file. A pickle constructed from `Examples` will point to the example row.


@dataclass
class PickleDocString:
    content: str
    media_type: Optional[str] = None


@dataclass
class PickleStep:
    """
    An executable step
    """
    ast_node_ids: list[str]
    """
    References the IDs of the source of the step. For Gherkin, this can be
    the ID of a Step, and possibly also the ID of a TableRow
    """

    id: str  # A unique ID for the PickleStep
    text: str
    argument: Optional[PickleStepArgument] = None
    type: Optional[PickleStepType] = None
    """
    The context in which the step was specified: context (Given), action (When) or outcome (Then).

    Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
    """



@dataclass
class PickleStepArgument:
    """
    An optional argument
    """
    data_table: Optional[PickleTable] = None
    doc_string: Optional[PickleDocString] = None


@dataclass
class PickleTable:
    rows: list[PickleTableRow]


@dataclass
class PickleTableCell:
    value: str


@dataclass
class PickleTableRow:
    cells: list[PickleTableCell]


@dataclass
class PickleTag:
    """
    A tag
    """
    ast_node_id: str  # Points to the AST node this was created from
    name: str


@dataclass
class Source:
    """
    A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
    """
    data: str  # The contents of the file
    media_type: SourceMediaType
    """
    The media type of the file. Can be used to specify custom types, such as
    text/x.cucumber.gherkin+plain
    """

    uri: str
    """
    The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
    of the source, typically a file path relative to the root directory
    """



@dataclass
class SourceReference:
    """
    Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
    [Location](#io.cucumber.messages.Location) within that file.
    """
    java_method: Optional[JavaMethod] = None
    java_stack_trace_element: Optional[JavaStackTraceElement] = None
    location: Optional[Location] = None
    uri: Optional[str] = None


@dataclass
class JavaMethod:
    class_name: str
    method_name: str
    method_parameter_types: list[str]


@dataclass
class JavaStackTraceElement:
    class_name: str
    file_name: str
    method_name: str


@dataclass
class StepDefinition:
    id: str
    pattern: StepDefinitionPattern
    source_reference: SourceReference


@dataclass
class StepDefinitionPattern:
    source: str
    type: StepDefinitionPatternType


@dataclass
class Suggestion:
    """
    A suggested fragment of code to implement an undefined step
    """
    id: str  # A unique id for this suggestion
    pickle_step_id: str  # The ID of the `PickleStep` this `Suggestion` was created for.
    snippets: list[Snippet]  # A collection of code snippets that could implement the undefined step


@dataclass
class Snippet:
    code: str  # A snippet of code
    language: str
    """
    The programming language of the code.

    This must be formatted as an all lowercase identifier such that syntax highlighters like [Prism](https://prismjs.com/#supported-languages) or [Highlight.js](https://github.com/highlightjs/highlight.js/blob/main/SUPPORTED_LANGUAGES.md) can recognize it.
    For example: `cpp`, `cs`, `go`, `java`, `javascript`, `php`, `python`, `ruby`, `scala`.
    """



@dataclass
class TestCase:
    """
    A `TestCase` contains a sequence of `TestStep`s.
    """
    id: str
    pickle_id: str  # The ID of the `Pickle` this `TestCase` is derived from.
    test_steps: list[TestStep]
    test_run_started_id: Optional[str] = None  # Identifier for the test run that this test case belongs to


@dataclass
class Group:
    children: list[Group]
    start: Optional[int] = None
    value: Optional[str] = None


@dataclass
class StepMatchArgument:
    """
    Represents a single argument extracted from a step match and passed to a step definition.
    This is used for the following purposes:
    - Construct an argument to pass to a step definition (possibly through a parameter type transform)
    - Highlight the matched parameter in rich formatters such as the HTML formatter

    This message closely matches the `Argument` class in the `cucumber-expressions` library.
    """
    group: Group
    """
    Represents the outermost capture group of an argument. This message closely matches the
    `Group` class in the `cucumber-expressions` library.
    """

    parameter_type_name: Optional[str] = None


@dataclass
class StepMatchArgumentsList:
    step_match_arguments: list[StepMatchArgument]


@dataclass
class TestStep:
    """
    A `TestStep` is derived from either a `PickleStep` combined with a `StepDefinition`, or from a `Hook`.

    When derived from a PickleStep:
     * For `UNDEFINED` steps `stepDefinitionIds` and `stepMatchArgumentsLists` will be empty.
     * For `AMBIGUOUS` steps, there will be multiple entries in `stepDefinitionIds` and `stepMatchArgumentsLists`. The first entry in the stepMatchArgumentsLists holds the list of arguments for the first matching step definition, the second entry for the second, etc
    """
    id: str
    hook_id: Optional[str] = None  # Pointer to the `Hook` (if derived from a Hook)
    pickle_step_id: Optional[str] = None  # Pointer to the `PickleStep` (if derived from a `PickleStep`)
    step_definition_ids: Optional[list[str]] = None
    """
    Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`).

    Each element represents a matching step definition.
    """

    step_match_arguments_lists: Optional[list[StepMatchArgumentsList]] = None
    """
    A list of list of StepMatchArgument (if derived from a `PickleStep`).

    Each element represents the arguments for a matching step definition.
    """



@dataclass
class TestCaseFinished:
    test_case_started_id: str
    timestamp: Timestamp
    will_be_retried: bool


@dataclass
class TestCaseStarted:
    attempt: int
    """
    The first attempt should have value 0, and for each retry the value
    should increase by 1.
    """

    id: str
    """
    Because a `TestCase` can be run multiple times (in case of a retry),
    we use this field to group messages relating to the same attempt.
    """

    test_case_id: str
    timestamp: Timestamp
    worker_id: Optional[str] = None  # An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.


@dataclass
class TestRunFinished:
    success: bool  # A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.
    timestamp: Timestamp  # Timestamp when the TestRun is finished
    exception: Optional[Exception] = None  # Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.
    message: Optional[str] = None  # An informative message about the test run. Typically additional information about failure, but not necessarily.
    test_run_started_id: Optional[str] = None


@dataclass
class TestRunHookFinished:
    result: TestStepResult
    test_run_hook_started_id: str  # Identifier for the hook execution that has finished
    timestamp: Timestamp


@dataclass
class TestRunHookStarted:
    hook_id: str  # Identifier for the hook that will be executed
    id: str  # Unique identifier for this hook execution
    test_run_started_id: str  # Identifier for the test run that this hook execution belongs to
    timestamp: Timestamp
    worker_id: Optional[str] = None  # An identifier for the worker process running this hook, if parallel workers are in use. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.


@dataclass
class TestRunStarted:
    timestamp: Timestamp
    id: Optional[str] = None


@dataclass
class TestStepFinished:
    test_case_started_id: str
    test_step_id: str
    test_step_result: TestStepResult
    timestamp: Timestamp


@dataclass
class TestStepResult:
    duration: Duration
    status: TestStepResultStatus
    exception: Optional[Exception] = None  # Exception thrown while executing this step, if any.
    message: Optional[str] = None  # An arbitrary bit of information that explains this result. If there was an exception, this should include a stringified representation of it including type, message and stack trace (the exact format will vary by platform).


@dataclass
class TestStepStarted:
    test_case_started_id: str
    test_step_id: str
    timestamp: Timestamp


@dataclass
class Timestamp:
    nanos: int
    """
    Non-negative fractions of a second at nanosecond resolution. Negative
    second values with fractions must still have non-negative nanos values
    that count forward in time. Must be from 0 to 999,999,999
    inclusive.
    """

    seconds: int
    """
    Represents seconds of UTC time since Unix epoch
    1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
    9999-12-31T23:59:59Z inclusive.
    """



@dataclass
class UndefinedParameterType:
    expression: str
    name: str
