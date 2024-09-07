# This code was generated using the code generator from cucumber-messages.
# Manual changes will be lost if the code is regenerated.
# Generator: cucumber-messages-python

from __future__ import annotations
from dataclasses import dataclass
from enum import Enum
from typing import Optional


class AttachmentContentEncoding(Enum):
    identity = "IDENTITY"
    base64 = "BASE64"


class HookType(Enum):
    before_test_run = "BEFORE_TEST_RUN"
    after_test_run = "AFTER_TEST_RUN"
    before_test_case = "BEFORE_TEST_CASE"
    after_test_case = "AFTER_TEST_CASE"
    before_test_step = "BEFORE_TEST_STEP"
    after_test_step = "AFTER_TEST_STEP"


class PickleStepType(Enum):
    unknown = "Unknown"
    context = "Context"
    action = "Action"
    outcome = "Outcome"


class SourceMediaType(Enum):
    text_x_cucumber_gherkin_plain = "text/x.cucumber.gherkin+plain"
    text_x_cucumber_gherkin_markdown = "text/x.cucumber.gherkin+markdown"


class StepDefinitionPatternType(Enum):
    cucumber_expression = "CUCUMBER_EXPRESSION"
    regular_expression = "REGULAR_EXPRESSION"


class StepKeywordType(Enum):
    unknown = "Unknown"
    context = "Context"
    action = "Action"
    outcome = "Outcome"
    conjunction = "Conjunction"


class TestStepResultStatus(Enum):
    unknown = "UNKNOWN"
    passed = "PASSED"
    skipped = "SKIPPED"
    pending = "PENDING"
    undefined = "UNDEFINED"
    ambiguous = "AMBIGUOUS"
    failed = "FAILED"


@dataclass
class Attachment:
    """
    //// Attachments (parse errors, execution errors, screenshots, links...)

    *
     An attachment represents any kind of data associated with a line in a
     [Source](#io.cucumber.messages.Source) file. It can be used for:

     * Syntax errors during parse time
     * Screenshots captured and attached during execution
     * Logs captured and attached during execution

     It is not to be used for runtime errors raised/thrown during execution. This
     is captured in `TestResult`.
    """
    """
    *
     The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
     is simply the string. If it's `BASE64`, the string should be Base64 decoded to
     obtain the attachment.
    """
    body: str
    """
    *
     Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).

     Content encoding is *not* determined by the media type, but rather by the type
     of the object being attached:

     - string: IDENTITY
     - byte array: BASE64
     - stream: BASE64
    """
    content_encoding: "AttachmentContentEncoding"
    """
    *
     The media type of the data. This can be any valid
     [IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
     as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
     and `text/x.cucumber.stacktrace+plain`
    """
    media_type: str
    """
    *
     Suggested file name of the attachment. (Provided by the user as an argument to `attach`)
    """
    file_name: Optional[str] = None
    source: Optional["Source"] = None
    test_case_started_id: Optional[str] = None
    test_run_started_id: Optional[str] = None
    test_step_id: Optional[str] = None
    """
    *
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
    url: Optional[str] = None


@dataclass
class Duration:
    """
    The structure is pretty close of the Timestamp one. For clarity, a second type
     of message is used.
    """
    """
    Non-negative fractions of a second at nanosecond resolution. Negative
     second values with fractions must still have non-negative nanos values
     that count forward in time. Must be from 0 to 999,999,999
     inclusive.
    """
    nanos: int
    seconds: int


@dataclass
class Envelope:
    """
    When removing a field, replace it with reserved, rather than deleting the line.
     When adding a field, add it to the end and increment the number by one.
     See https://developers.google.com/protocol-buffers/docs/proto#updating for details

    *
     All the messages that are passed between different components/processes are Envelope
     messages.
    """
    attachment: Optional["Attachment"] = None
    gherkin_document: Optional["GherkinDocument"] = None
    hook: Optional["Hook"] = None
    meta: Optional["Meta"] = None
    parameter_type: Optional["ParameterType"] = None
    parse_error: Optional["ParseError"] = None
    pickle: Optional["Pickle"] = None
    source: Optional["Source"] = None
    step_definition: Optional["StepDefinition"] = None
    test_case: Optional["TestCase"] = None
    test_case_finished: Optional["TestCaseFinished"] = None
    test_case_started: Optional["TestCaseStarted"] = None
    test_run_finished: Optional["TestRunFinished"] = None
    test_run_hook_finished: Optional["TestRunHookFinished"] = None
    test_run_hook_started: Optional["TestRunHookStarted"] = None
    test_run_started: Optional["TestRunStarted"] = None
    test_step_finished: Optional["TestStepFinished"] = None
    test_step_started: Optional["TestStepStarted"] = None
    undefined_parameter_type: Optional["UndefinedParameterType"] = None


@dataclass
class Exception:
    """
    A simplified representation of an exception
    """
    """
    The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
    """
    type: str
    """
    The message of exception that caused this result. E.g. expected: "a" but was: "b"
    """
    message: Optional[str] = None
    """
    The stringified stack trace of the exception that caused this result
    """
    stack_trace: Optional[str] = None


@dataclass
class GherkinDocument:
    """
    *
     The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
     Cucumber implementations should *not* depend on `GherkinDocument` or any of its
     children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.

     The only consumers of `GherkinDocument` should only be formatters that produce
     "rich" output, resembling the original Gherkin document.
    """
    """
    All the comments in the Gherkin document
    """
    comments: list["Comment"]
    feature: Optional["Feature"] = None
    """
    *
     The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
     of the source, typically a file path relative to the root directory
    """
    uri: Optional[str] = None


@dataclass
class Background:
    description: str
    id: str
    keyword: str
    """
    The location of the `Background` keyword
    """
    location: "Location"
    name: str
    steps: list["Step"]


@dataclass
class Comment:
    """
    *
     A comment in a Gherkin document
    """
    """
    The location of the comment
    """
    location: "Location"
    """
    The text of the comment
    """
    text: str


@dataclass
class DataTable:
    location: "Location"
    rows: list["TableRow"]


@dataclass
class DocString:
    content: str
    delimiter: str
    location: "Location"
    media_type: Optional[str] = None


@dataclass
class Examples:
    description: str
    id: str
    keyword: str
    """
    The location of the `Examples` keyword
    """
    location: "Location"
    name: str
    table_body: list["TableRow"]
    tags: list["Tag"]
    table_header: Optional["TableRow"] = None


@dataclass
class Feature:
    """
    Zero or more children
    """
    children: list["FeatureChild"]
    """
    The line(s) underneath the line with the `keyword` that are used as description
    """
    description: str
    """
    The text of the `Feature` keyword (in the language specified by `language`)
    """
    keyword: str
    """
    The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document
    """
    language: str
    """
    The location of the `Feature` keyword
    """
    location: "Location"
    """
    The name of the feature (the text following the `keyword`)
    """
    name: str
    """
    All the tags placed above the `Feature` keyword
    """
    tags: list["Tag"]


@dataclass
class FeatureChild:
    """
    *
     A child node of a `Feature` node
    """
    background: Optional["Background"] = None
    rule: Optional["Rule"] = None
    scenario: Optional["Scenario"] = None


@dataclass
class Rule:
    children: list["RuleChild"]
    description: str
    id: str
    keyword: str
    """
    The location of the `Rule` keyword
    """
    location: "Location"
    name: str
    """
    All the tags placed above the `Rule` keyword
    """
    tags: list["Tag"]


@dataclass
class RuleChild:
    """
    *
     A child node of a `Rule` node
    """
    background: Optional["Background"] = None
    scenario: Optional["Scenario"] = None


@dataclass
class Scenario:
    description: str
    examples: list["Examples"]
    id: str
    keyword: str
    """
    The location of the `Scenario` keyword
    """
    location: "Location"
    name: str
    steps: list["Step"]
    tags: list["Tag"]


@dataclass
class Step:
    """
    A step
    """
    """
    Unique ID to be able to reference the Step from PickleStep
    """
    id: str
    """
    The actual keyword as it appeared in the source.
    """
    keyword: str
    """
    The location of the steps' `keyword`
    """
    location: "Location"
    text: str
    data_table: Optional["DataTable"] = None
    doc_string: Optional["DocString"] = None
    """
    The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.
    """
    keyword_type: Optional["StepKeywordType"] = None


@dataclass
class TableCell:
    """
    A cell in a `TableRow`
    """
    """
    The location of the cell
    """
    location: "Location"
    """
    The value of the cell
    """
    value: str


@dataclass
class TableRow:
    """
    A row in a table
    """
    """
    Cells in the row
    """
    cells: list["TableCell"]
    id: str
    """
    The location of the first cell in the row
    """
    location: "Location"


@dataclass
class Tag:
    """
    *
     A tag
    """
    """
    Unique ID to be able to reference the Tag from PickleTag
    """
    id: str
    """
    Location of the tag
    """
    location: "Location"
    """
    The name of the tag (including the leading `@`)
    """
    name: str


@dataclass
class Hook:
    id: str
    source_reference: "SourceReference"
    name: Optional[str] = None
    tag_expression: Optional[str] = None
    type: Optional["HookType"] = None


@dataclass
class Location:
    """
    *
     Points to a line and a column in a text file
    """
    line: int
    column: Optional[int] = None


@dataclass
class Meta:
    """
    *
     This message contains meta information about the environment. Consumers can use
     this for various purposes.
    """
    """
    386, arm, amd64 etc
    """
    cpu: "Product"
    """
    SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.
    """
    implementation: "Product"
    """
    Windows, Linux, MacOS etc
    """
    os: "Product"
    """
    *
     The [SEMVER](https://semver.org/) version number of the protocol
    """
    protocol_version: str
    """
    Java, Ruby, Node.js etc
    """
    runtime: "Product"
    ci: Optional["Ci"] = None


@dataclass
class Ci:
    """
    CI environment
    """
    """
    Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
    """
    name: str
    """
    The build number. Some CI servers use non-numeric build numbers, which is why this is a string
    """
    build_number: Optional[str] = None
    git: Optional["Git"] = None
    """
    Link to the build
    """
    url: Optional[str] = None


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
    """
    The product name
    """
    name: str
    """
    The product version
    """
    version: Optional[str] = None


@dataclass
class ParameterType:
    id: str
    """
    The name is unique, so we don't need an id.
    """
    name: str
    prefer_for_regular_expression_match: bool
    regular_expressions: list[str]
    use_for_snippets: bool
    source_reference: Optional["SourceReference"] = None


@dataclass
class ParseError:
    message: str
    source: "SourceReference"


@dataclass
class Pickle:
    """
    //// Pickles

    *
     A `Pickle` represents a template for a `TestCase`. It is typically derived
     from another format, such as [GherkinDocument](#io.cucumber.messages.GherkinDocument).
     In the future a `Pickle` may be derived from other formats such as Markdown or
     Excel files.

     By making `Pickle` the main data structure Cucumber uses for execution, the
     implementation of Cucumber itself becomes simpler, as it doesn't have to deal
     with the complex structure of a [GherkinDocument](#io.cucumber.messages.GherkinDocument).

     Each `PickleStep` of a `Pickle` is matched with a `StepDefinition` to create a `TestCase`
    """
    """
    *
     Points to the AST node locations of the pickle. The last one represents the unique
     id of the pickle. A pickle constructed from `Examples` will have the first
     id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.
    """
    ast_node_ids: list[str]
    """
    *
     A unique id for the pickle
    """
    id: str
    """
    The language of the pickle
    """
    language: str
    """
    The name of the pickle
    """
    name: str
    """
    One or more steps
    """
    steps: list["PickleStep"]
    """
    *
     One or more tags. If this pickle is constructed from a Gherkin document,
     It includes inherited tags from the `Feature` as well.
    """
    tags: list["PickleTag"]
    """
    The uri of the source file
    """
    uri: str


@dataclass
class PickleDocString:
    content: str
    media_type: Optional[str] = None


@dataclass
class PickleStep:
    """
    *
     An executable step
    """
    """
    References the IDs of the source of the step. For Gherkin, this can be
     the ID of a Step, and possibly also the ID of a TableRow
    """
    ast_node_ids: list[str]
    """
    A unique ID for the PickleStep
    """
    id: str
    text: str
    argument: Optional["PickleStepArgument"] = None
    """
    The context in which the step was specified: context (Given), action (When) or outcome (Then).

    Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
    """
    type: Optional["PickleStepType"] = None


@dataclass
class PickleStepArgument:
    """
    An optional argument
    """
    data_table: Optional["PickleTable"] = None
    doc_string: Optional["PickleDocString"] = None


@dataclass
class PickleTable:
    rows: list["PickleTableRow"]


@dataclass
class PickleTableCell:
    value: str


@dataclass
class PickleTableRow:
    cells: list["PickleTableCell"]


@dataclass
class PickleTag:
    """
    *
     A tag
    """
    """
    Points to the AST node this was created from
    """
    ast_node_id: str
    name: str


@dataclass
class Source:
    """
    //// Source

    *
     A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
    """
    """
    The contents of the file
    """
    data: str
    """
    The media type of the file. Can be used to specify custom types, such as
     text/x.cucumber.gherkin+plain
    """
    media_type: "SourceMediaType"
    """
    *
     The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
     of the source, typically a file path relative to the root directory
    """
    uri: str


@dataclass
class SourceReference:
    """
    *
     Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
     [Location](#io.cucumber.messages.Location) within that file.
    """
    java_method: Optional["JavaMethod"] = None
    java_stack_trace_element: Optional["JavaStackTraceElement"] = None
    location: Optional["Location"] = None
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
    pattern: "StepDefinitionPattern"
    source_reference: "SourceReference"


@dataclass
class StepDefinitionPattern:
    source: str
    type: "StepDefinitionPatternType"


@dataclass
class TestCase:
    """
    //// TestCases

    *
     A `TestCase` contains a sequence of `TestStep`s.
    """
    id: str
    """
    The ID of the `Pickle` this `TestCase` is derived from.
    """
    pickle_id: str
    test_steps: list["TestStep"]
    """
    Identifier for the test run that this test case belongs to
    """
    test_run_started_id: Optional[str] = None


@dataclass
class Group:
    children: list["Group"]
    start: Optional[int] = None
    value: Optional[str] = None


@dataclass
class StepMatchArgument:
    """
    *
     Represents a single argument extracted from a step match and passed to a step definition.
     This is used for the following purposes:
     - Construct an argument to pass to a step definition (possibly through a parameter type transform)
     - Highlight the matched parameter in rich formatters such as the HTML formatter

     This message closely matches the `Argument` class in the `cucumber-expressions` library.
    """
    """
    *
     Represents the outermost capture group of an argument. This message closely matches the
     `Group` class in the `cucumber-expressions` library.
    """
    group: "Group"
    parameter_type_name: Optional[str] = None


@dataclass
class StepMatchArgumentsList:
    step_match_arguments: list["StepMatchArgument"]


@dataclass
class TestStep:
    """
    *
     A `TestStep` is derived from either a `PickleStep`
     combined with a `StepDefinition`, or from a `Hook`.
    """
    id: str
    """
    Pointer to the `Hook` (if derived from a Hook)
    """
    hook_id: Optional[str] = None
    """
    Pointer to the `PickleStep` (if derived from a `PickleStep`)
    """
    pickle_step_id: Optional[str] = None
    """
    Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`)
     Each element represents a matching step definition. A size of 0 means `UNDEFINED`,
     and a size of 2+ means `AMBIGUOUS`
    """
    step_definition_ids: Optional[list[str]] = None
    """
    A list of list of StepMatchArgument (if derived from a `PickleStep`).
    """
    step_match_arguments_lists: Optional[list["StepMatchArgumentsList"]] = None


@dataclass
class TestCaseFinished:
    test_case_started_id: str
    timestamp: "Timestamp"
    will_be_retried: bool


@dataclass
class TestCaseStarted:
    """
    *
     The first attempt should have value 0, and for each retry the value
     should increase by 1.
    """
    attempt: int
    """
    *
     Because a `TestCase` can be run multiple times (in case of a retry),
     we use this field to group messages relating to the same attempt.
    """
    id: str
    test_case_id: str
    timestamp: "Timestamp"
    """
    An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.
    """
    worker_id: Optional[str] = None


@dataclass
class TestRunFinished:
    """
    A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.
    """
    success: bool
    """
    Timestamp when the TestRun is finished
    """
    timestamp: "Timestamp"
    """
    Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.
    """
    exception: Optional["Exception"] = None
    """
    An informative message about the test run. Typically additional information about failure, but not necessarily.
    """
    message: Optional[str] = None
    test_run_started_id: Optional[str] = None


@dataclass
class TestRunHookFinished:
    result: "TestStepResult"
    """
    Identifier for the hook execution that has finished
    """
    test_run_hook_started_id: str
    timestamp: "Timestamp"


@dataclass
class TestRunHookStarted:
    """
    Identifier for the hook that will be executed
    """
    hook_id: str
    """
    Unique identifier for this hook execution
    """
    id: str
    """
    Identifier for the test run that this hook execution belongs to
    """
    test_run_started_id: str
    timestamp: "Timestamp"


@dataclass
class TestRunStarted:
    timestamp: "Timestamp"
    id: Optional[str] = None


@dataclass
class TestStepFinished:
    test_case_started_id: str
    test_step_id: str
    test_step_result: "TestStepResult"
    timestamp: "Timestamp"


@dataclass
class TestStepResult:
    duration: "Duration"
    status: "TestStepResultStatus"
    """
    Exception thrown while executing this step, if any.
    """
    exception: Optional["Exception"] = None
    """
    An arbitrary bit of information that explains this result. This can be a stack trace of anything else.
    """
    message: Optional[str] = None


@dataclass
class TestStepStarted:
    test_case_started_id: str
    test_step_id: str
    timestamp: "Timestamp"


@dataclass
class Timestamp:
    """
    Non-negative fractions of a second at nanosecond resolution. Negative
     second values with fractions must still have non-negative nanos values
     that count forward in time. Must be from 0 to 999,999,999
     inclusive.
    """
    nanos: int
    """
    Represents seconds of UTC time since Unix epoch
     1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
     9999-12-31T23:59:59Z inclusive.
    """
    seconds: int


@dataclass
class UndefinedParameterType:
    expression: str
    name: str
