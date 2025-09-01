# Cucumber Messages

Each message is an instance of [Envelope](#envelope). The `Envelope` message
will only have one of its fields set, which indicates the payload of the message.

## Attachment

Attachments (parse errors, execution errors, screenshots, links...)

An attachment represents any kind of data associated with a line in a
[Source](#io.cucumber.messages.Source) file. It can be used for:

* Syntax errors during parse time
* Screenshots captured and attached during execution
* Logs captured and attached during execution

It is not to be used for runtime errors raised/thrown during execution. This
is captured in `TestResult`.

### .body 

* Type: string 
* Required: yes 

The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
is simply the string. If it's `BASE64`, the string should be Base64 decoded to
obtain the attachment.

### .contentEncoding 

* Type: [AttachmentContentEncoding](#attachmentcontentencoding) 
* Required: yes 

Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).

Content encoding is *not* determined by the media type, but rather by the type
of the object being attached:

- string: IDENTITY
- byte array: BASE64
- stream: BASE64

### .fileName 

* Type: string 
* Required: no 

Suggested file name of the attachment. (Provided by the user as an argument to `attach`)

### .mediaType 

* Type: string 
* Required: yes 

The media type of the data. This can be any valid
[IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
and `text/x.cucumber.stacktrace+plain`

### .source 

* Type: [Source](#source) 
* Required: no 



### .testCaseStartedId 

* Type: string 
* Required: no 

The identifier of the test case attempt if the attachment was created during the execution of a test step

### .testStepId 

* Type: string 
* Required: no 

The identifier of the test step if the attachment was created during the execution of a test step

### .url 

* Type: string 
* Required: no 

A URL where the attachment can be retrieved. This field should not be set by Cucumber.
It should be set by a program that reads a message stream and does the following for
each Attachment message:

- Writes the body (after base64 decoding if necessary) to a new file.
- Sets `body` and `contentEncoding` to `null`
- Writes out the new attachment message

This will result in a smaller message stream, which can improve performance and
reduce bandwidth of message consumers. It also makes it easier to process and download attachments
separately from reports.

### .testRunStartedId 

* Type: string 
* Required: no 

Not used; implementers should instead populate `testRunHookStartedId` if an attachment was created during the execution of a test run hook

### .testRunHookStartedId 

* Type: string 
* Required: no 

The identifier of the test run hook execution if the attachment was created during the execution of a test run hook

### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: no 

When the attachment was created

## Duration

The structure is pretty close of the Timestamp one. For clarity, a second type
of message is used.

### .seconds 

* Type: integer 
* Required: yes 



### .nanos 

* Type: integer 
* Required: yes 

Non-negative fractions of a second at nanosecond resolution. Negative
second values with fractions must still have non-negative nanos values
that count forward in time. Must be from 0 to 999,999,999
inclusive.

## Envelope



### .attachment 

* Type: [Attachment](#attachment) 
* Required: no 



### .gherkinDocument 

* Type: [GherkinDocument](#gherkindocument) 
* Required: no 



### .hook 

* Type: [Hook](#hook) 
* Required: no 



### .meta 

* Type: [Meta](#meta) 
* Required: no 



### .parameterType 

* Type: [ParameterType](#parametertype) 
* Required: no 



### .parseError 

* Type: [ParseError](#parseerror) 
* Required: no 



### .pickle 

* Type: [Pickle](#pickle) 
* Required: no 



### .source 

* Type: [Source](#source) 
* Required: no 



### .stepDefinition 

* Type: [StepDefinition](#stepdefinition) 
* Required: no 



### .testCase 

* Type: [TestCase](#testcase) 
* Required: no 



### .testCaseFinished 

* Type: [TestCaseFinished](#testcasefinished) 
* Required: no 



### .testCaseStarted 

* Type: [TestCaseStarted](#testcasestarted) 
* Required: no 



### .testRunFinished 

* Type: [TestRunFinished](#testrunfinished) 
* Required: no 



### .testRunStarted 

* Type: [TestRunStarted](#testrunstarted) 
* Required: no 



### .testStepFinished 

* Type: [TestStepFinished](#teststepfinished) 
* Required: no 



### .testStepStarted 

* Type: [TestStepStarted](#teststepstarted) 
* Required: no 



### .testRunHookStarted 

* Type: [TestRunHookStarted](#testrunhookstarted) 
* Required: no 



### .testRunHookFinished 

* Type: [TestRunHookFinished](#testrunhookfinished) 
* Required: no 



### .undefinedParameterType 

* Type: [UndefinedParameterType](#undefinedparametertype) 
* Required: no 



## Exception

A simplified representation of an exception

### .type 

* Type: string 
* Required: yes 

The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"

### .message 

* Type: string 
* Required: no 

The message of exception that caused this result. E.g. expected: "a" but was: "b"

### .stackTrace 

* Type: string 
* Required: no 

The stringified stack trace of the exception that caused this result

## GherkinDocument

The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
Cucumber implementations should *not* depend on `GherkinDocument` or any of its
children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.

The only consumers of `GherkinDocument` should only be formatters that produce
"rich" output, resembling the original Gherkin document.

### .uri 

* Type: string 
* Required: no 

The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
of the source, typically a file path relative to the root directory

### .feature 

* Type: [Feature](#feature) 
* Required: no 



### .comments 

* Type: [Comment](#comment)[] 
* Required: yes 

All the comments in the Gherkin document

## Background



### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Background` keyword

### .keyword 

* Type: string 
* Required: yes 



### .name 

* Type: string 
* Required: yes 



### .description 

* Type: string 
* Required: yes 



### .steps 

* Type: [Step](#step)[] 
* Required: yes 



### .id 

* Type: string 
* Required: yes 



## Comment

A comment in a Gherkin document

### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the comment

### .text 

* Type: string 
* Required: yes 

The text of the comment

## DataTable



### .location 

* Type: [Location](#location) 
* Required: yes 



### .rows 

* Type: [TableRow](#tablerow)[] 
* Required: yes 



## DocString



### .location 

* Type: [Location](#location) 
* Required: yes 



### .mediaType 

* Type: string 
* Required: no 



### .content 

* Type: string 
* Required: yes 



### .delimiter 

* Type: string 
* Required: yes 



## Examples



### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Examples` keyword

### .tags 

* Type: [Tag](#tag)[] 
* Required: yes 



### .keyword 

* Type: string 
* Required: yes 



### .name 

* Type: string 
* Required: yes 



### .description 

* Type: string 
* Required: yes 



### .tableHeader 

* Type: [TableRow](#tablerow) 
* Required: no 



### .tableBody 

* Type: [TableRow](#tablerow)[] 
* Required: yes 



### .id 

* Type: string 
* Required: yes 



## Feature



### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Feature` keyword

### .tags 

* Type: [Tag](#tag)[] 
* Required: yes 

All the tags placed above the `Feature` keyword

### .language 

* Type: string 
* Required: yes 

The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document

### .keyword 

* Type: string 
* Required: yes 

The text of the `Feature` keyword (in the language specified by `language`)

### .name 

* Type: string 
* Required: yes 

The name of the feature (the text following the `keyword`)

### .description 

* Type: string 
* Required: yes 

The line(s) underneath the line with the `keyword` that are used as description

### .children 

* Type: [FeatureChild](#featurechild)[] 
* Required: yes 

Zero or more children

## FeatureChild

A child node of a `Feature` node

### .rule 

* Type: [Rule](#rule) 
* Required: no 



### .background 

* Type: [Background](#background) 
* Required: no 



### .scenario 

* Type: [Scenario](#scenario) 
* Required: no 



## Rule



### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Rule` keyword

### .tags 

* Type: [Tag](#tag)[] 
* Required: yes 

All the tags placed above the `Rule` keyword

### .keyword 

* Type: string 
* Required: yes 



### .name 

* Type: string 
* Required: yes 



### .description 

* Type: string 
* Required: yes 



### .children 

* Type: [RuleChild](#rulechild)[] 
* Required: yes 



### .id 

* Type: string 
* Required: yes 



## RuleChild

A child node of a `Rule` node

### .background 

* Type: [Background](#background) 
* Required: no 



### .scenario 

* Type: [Scenario](#scenario) 
* Required: no 



## Scenario



### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Scenario` keyword

### .tags 

* Type: [Tag](#tag)[] 
* Required: yes 



### .keyword 

* Type: string 
* Required: yes 



### .name 

* Type: string 
* Required: yes 



### .description 

* Type: string 
* Required: yes 



### .steps 

* Type: [Step](#step)[] 
* Required: yes 



### .examples 

* Type: [Examples](#examples)[] 
* Required: yes 



### .id 

* Type: string 
* Required: yes 



## Step

A step

### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the steps' `keyword`

### .keyword 

* Type: string 
* Required: yes 

The actual keyword as it appeared in the source.

### .keywordType 

* Type: [StepKeywordType](#stepkeywordtype) 
* Required: no 

The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.

### .text 

* Type: string 
* Required: yes 



### .docString 

* Type: [DocString](#docstring) 
* Required: no 



### .dataTable 

* Type: [DataTable](#datatable) 
* Required: no 



### .id 

* Type: string 
* Required: yes 

Unique ID to be able to reference the Step from PickleStep

## TableCell

A cell in a `TableRow`

### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the cell

### .value 

* Type: string 
* Required: yes 

The value of the cell

## TableRow

A row in a table

### .location 

* Type: [Location](#location) 
* Required: yes 

The location of the first cell in the row

### .cells 

* Type: [TableCell](#tablecell)[] 
* Required: yes 

Cells in the row

### .id 

* Type: string 
* Required: yes 



## Tag

A tag

### .location 

* Type: [Location](#location) 
* Required: yes 

Location of the tag

### .name 

* Type: string 
* Required: yes 

The name of the tag (including the leading `@`)

### .id 

* Type: string 
* Required: yes 

Unique ID to be able to reference the Tag from PickleTag

## Hook



### .id 

* Type: string 
* Required: yes 



### .name 

* Type: string 
* Required: no 



### .sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



### .tagExpression 

* Type: string 
* Required: no 



### .type 

* Type: [HookType](#hooktype) 
* Required: no 



## Location

Points to a line and a column in a text file

### .line 

* Type: integer 
* Required: yes 



### .column 

* Type: integer 
* Required: no 



## Meta

This message contains meta information about the environment. Consumers can use
this for various purposes.

### .protocolVersion 

* Type: string 
* Required: yes 

The [SEMVER](https://semver.org/) version number of the protocol

### .implementation 

* Type: [Product](#product) 
* Required: yes 

SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.

### .runtime 

* Type: [Product](#product) 
* Required: yes 

Java, Ruby, Node.js etc

### .os 

* Type: [Product](#product) 
* Required: yes 

Windows, Linux, MacOS etc

### .cpu 

* Type: [Product](#product) 
* Required: yes 

386, arm, amd64 etc

### .ci 

* Type: [Ci](#ci) 
* Required: no 



## Ci

CI environment

### .name 

* Type: string 
* Required: yes 

Name of the CI product, e.g. "Jenkins", "CircleCI" etc.

### .url 

* Type: string 
* Required: no 

Link to the build

### .buildNumber 

* Type: string 
* Required: no 

The build number. Some CI servers use non-numeric build numbers, which is why this is a string

### .git 

* Type: [Git](#git) 
* Required: no 



## Git

Information about Git, provided by the Build/CI server as environment
variables.

### .remote 

* Type: string 
* Required: yes 



### .revision 

* Type: string 
* Required: yes 



### .branch 

* Type: string 
* Required: no 



### .tag 

* Type: string 
* Required: no 



## Product

Used to describe various properties of Meta

### .name 

* Type: string 
* Required: yes 

The product name

### .version 

* Type: string 
* Required: no 

The product version

## ParameterType



### .name 

* Type: string 
* Required: yes 

The name is unique, so we don't need an id.

### .regularExpressions 

* Type: string[] 
* Required: yes 



### .preferForRegularExpressionMatch 

* Type: boolean 
* Required: yes 



### .useForSnippets 

* Type: boolean 
* Required: yes 



### .id 

* Type: string 
* Required: yes 



### .sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: no 



## ParseError



### .source 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



### .message 

* Type: string 
* Required: yes 



## Pickle

A `Pickle` represents a template for a `TestCase`. It is typically derived
from another format, such as [GherkinDocument](#io.cucumber.messages.GherkinDocument).
In the future a `Pickle` may be derived from other formats such as Markdown or
Excel files.

By making `Pickle` the main data structure Cucumber uses for execution, the
implementation of Cucumber itself becomes simpler, as it doesn't have to deal
with the complex structure of a [GherkinDocument](#io.cucumber.messages.GherkinDocument).

Each `PickleStep` of a `Pickle` is matched with a `StepDefinition` to create a `TestCase`

### .id 

* Type: string 
* Required: yes 

A unique id for the pickle

### .uri 

* Type: string 
* Required: yes 

The uri of the source file

### .name 

* Type: string 
* Required: yes 

The name of the pickle

### .language 

* Type: string 
* Required: yes 

The language of the pickle

### .steps 

* Type: [PickleStep](#picklestep)[] 
* Required: yes 

One or more steps

### .tags 

* Type: [PickleTag](#pickletag)[] 
* Required: yes 

One or more tags. If this pickle is constructed from a Gherkin document,
It includes inherited tags from the `Feature` as well.

### .astNodeIds 

* Type: string[] 
* Required: yes 

Points to the AST node locations of the pickle. The last one represents the unique
id of the pickle. A pickle constructed from `Examples` will have the first
id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.

## PickleDocString



### .mediaType 

* Type: string 
* Required: no 



### .content 

* Type: string 
* Required: yes 



## PickleStep

An executable step

### .argument 

* Type: [PickleStepArgument](#picklestepargument) 
* Required: no 



### .astNodeIds 

* Type: string[] 
* Required: yes 

References the IDs of the source of the step. For Gherkin, this can be
the ID of a Step, and possibly also the ID of a TableRow

### .id 

* Type: string 
* Required: yes 

A unique ID for the PickleStep

### .type 

* Type: [PickleStepType](#picklesteptype) 
* Required: no 

The context in which the step was specified: context (Given), action (When) or outcome (Then).

Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)

### .text 

* Type: string 
* Required: yes 



## PickleStepArgument

An optional argument

### .docString 

* Type: [PickleDocString](#pickledocstring) 
* Required: no 



### .dataTable 

* Type: [PickleTable](#pickletable) 
* Required: no 



## PickleTable



### .rows 

* Type: [PickleTableRow](#pickletablerow)[] 
* Required: yes 



## PickleTableCell



### .value 

* Type: string 
* Required: yes 



## PickleTableRow



### .cells 

* Type: [PickleTableCell](#pickletablecell)[] 
* Required: yes 



## PickleTag

A tag

### .name 

* Type: string 
* Required: yes 



### .astNodeId 

* Type: string 
* Required: yes 

Points to the AST node this was created from

## Source

A source file, typically a Gherkin document or Java/Ruby/JavaScript source code

### .uri 

* Type: string 
* Required: yes 

The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
of the source, typically a file path relative to the root directory

### .data 

* Type: string 
* Required: yes 

The contents of the file

### .mediaType 

* Type: [SourceMediaType](#sourcemediatype) 
* Required: yes 

The media type of the file. Can be used to specify custom types, such as
text/x.cucumber.gherkin+plain

## SourceReference

Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
[Location](#io.cucumber.messages.Location) within that file.

### .uri 

* Type: string 
* Required: no 



### .javaMethod 

* Type: [JavaMethod](#javamethod) 
* Required: no 



### .javaStackTraceElement 

* Type: [JavaStackTraceElement](#javastacktraceelement) 
* Required: no 



### .location 

* Type: [Location](#location) 
* Required: no 



## JavaMethod



### .className 

* Type: string 
* Required: yes 



### .methodName 

* Type: string 
* Required: yes 



### .methodParameterTypes 

* Type: string[] 
* Required: yes 



## JavaStackTraceElement



### .className 

* Type: string 
* Required: yes 



### .fileName 

* Type: string 
* Required: yes 



### .methodName 

* Type: string 
* Required: yes 



## StepDefinition



### .id 

* Type: string 
* Required: yes 



### .pattern 

* Type: [StepDefinitionPattern](#stepdefinitionpattern) 
* Required: yes 



### .sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



## StepDefinitionPattern



### .source 

* Type: string 
* Required: yes 



### .type 

* Type: [StepDefinitionPatternType](#stepdefinitionpatterntype) 
* Required: yes 



## TestCase

A `TestCase` contains a sequence of `TestStep`s.

### .id 

* Type: string 
* Required: yes 



### .pickleId 

* Type: string 
* Required: yes 

The ID of the `Pickle` this `TestCase` is derived from.

### .testSteps 

* Type: [TestStep](#teststep)[] 
* Required: yes 



### .testRunStartedId 

* Type: string 
* Required: no 

Identifier for the test run that this test case belongs to

## Group



### .children 

* Type: [Group](#group)[] 
* Required: yes 



### .start 

* Type: integer 
* Required: no 



### .value 

* Type: string 
* Required: no 



## StepMatchArgument

Represents a single argument extracted from a step match and passed to a step definition.
This is used for the following purposes:
- Construct an argument to pass to a step definition (possibly through a parameter type transform)
- Highlight the matched parameter in rich formatters such as the HTML formatter

This message closely matches the `Argument` class in the `cucumber-expressions` library.

### .group 

* Type: [Group](#group) 
* Required: yes 

Represents the outermost capture group of an argument. This message closely matches the
`Group` class in the `cucumber-expressions` library.

### .parameterTypeName 

* Type: string 
* Required: no 



## StepMatchArgumentsList



### .stepMatchArguments 

* Type: [StepMatchArgument](#stepmatchargument)[] 
* Required: yes 



## TestStep

A `TestStep` is derived from either a `PickleStep`
combined with a `StepDefinition`, or from a `Hook`.

### .hookId 

* Type: string 
* Required: no 

Pointer to the `Hook` (if derived from a Hook)

### .id 

* Type: string 
* Required: yes 



### .pickleStepId 

* Type: string 
* Required: no 

Pointer to the `PickleStep` (if derived from a `PickleStep`)

### .stepDefinitionIds 

* Type: string[] 
* Required: no 

Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`)
Each element represents a matching step definition. A size of 0 means `UNDEFINED`,
and a size of 2+ means `AMBIGUOUS`

### .stepMatchArgumentsLists 

* Type: [StepMatchArgumentsList](#stepmatchargumentslist)[] 
* Required: no 

A list of list of StepMatchArgument (if derived from a `PickleStep`).

## TestCaseFinished



### .testCaseStartedId 

* Type: string 
* Required: yes 



### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



### .willBeRetried 

* Type: boolean 
* Required: yes 



## TestCaseStarted



### .attempt 

* Type: integer 
* Required: yes 

The first attempt should have value 0, and for each retry the value
should increase by 1.

### .id 

* Type: string 
* Required: yes 

Because a `TestCase` can be run multiple times (in case of a retry),
we use this field to group messages relating to the same attempt.

### .testCaseId 

* Type: string 
* Required: yes 



### .workerId 

* Type: string 
* Required: no 

An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.

### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunFinished



### .message 

* Type: string 
* Required: no 

An informative message about the test run. Typically additional information about failure, but not necessarily.

### .success 

* Type: boolean 
* Required: yes 

A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.

### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 

Timestamp when the TestRun is finished

### .exception 

* Type: [Exception](#exception) 
* Required: no 

Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.

### .testRunStartedId 

* Type: string 
* Required: no 



## TestRunHookFinished



### .testRunHookStartedId 

* Type: string 
* Required: yes 

Identifier for the hook execution that has finished

### .result 

* Type: [TestStepResult](#teststepresult) 
* Required: yes 



### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunHookStarted



### .id 

* Type: string 
* Required: yes 

Unique identifier for this hook execution

### .testRunStartedId 

* Type: string 
* Required: yes 

Identifier for the test run that this hook execution belongs to

### .hookId 

* Type: string 
* Required: yes 

Identifier for the hook that will be executed

### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunStarted



### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



### .id 

* Type: string 
* Required: no 



## TestStepFinished



### .testCaseStartedId 

* Type: string 
* Required: yes 



### .testStepId 

* Type: string 
* Required: yes 



### .testStepResult 

* Type: [TestStepResult](#teststepresult) 
* Required: yes 



### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestStepResult



### .duration 

* Type: [Duration](#duration) 
* Required: yes 



### .message 

* Type: string 
* Required: no 

An arbitrary bit of information that explains this result. If there was an exception, this should include a stringified representation of it including type, message and stack trace (the exact format will vary by platform).

### .status 

* Type: [TestStepResultStatus](#teststepresultstatus) 
* Required: yes 



### .exception 

* Type: [Exception](#exception) 
* Required: no 

Exception thrown while executing this step, if any.

## TestStepStarted



### .testCaseStartedId 

* Type: string 
* Required: yes 



### .testStepId 

* Type: string 
* Required: yes 



### .timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## Timestamp



### .seconds 

* Type: integer 
* Required: yes 

Represents seconds of UTC time since Unix epoch
1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
9999-12-31T23:59:59Z inclusive.

### .nanos 

* Type: integer 
* Required: yes 

Non-negative fractions of a second at nanosecond resolution. Negative
second values with fractions must still have non-negative nanos values
that count forward in time. Must be from 0 to 999,999,999
inclusive.

## UndefinedParameterType



### .expression 

* Type: string 
* Required: yes 



### .name 

* Type: string 
* Required: yes 



## AttachmentContentEncoding

One of the following:

* `"IDENTITY"`
* `"BASE64"`


## HookType

One of the following:

* `"BEFORE_TEST_RUN"`
* `"AFTER_TEST_RUN"`
* `"BEFORE_TEST_CASE"`
* `"AFTER_TEST_CASE"`
* `"BEFORE_TEST_STEP"`
* `"AFTER_TEST_STEP"`


## PickleStepType

One of the following:

* `"Unknown"`
* `"Context"`
* `"Action"`
* `"Outcome"`


## SourceMediaType

One of the following:

* `"text/x.cucumber.gherkin+plain"`
* `"text/x.cucumber.gherkin+markdown"`


## StepDefinitionPatternType

One of the following:

* `"CUCUMBER_EXPRESSION"`
* `"REGULAR_EXPRESSION"`


## StepKeywordType

One of the following:

* `"Unknown"`
* `"Context"`
* `"Action"`
* `"Outcome"`
* `"Conjunction"`


## TestStepResultStatus

One of the following:

* `"UNKNOWN"`
* `"PASSED"`
* `"SKIPPED"`
* `"PENDING"`
* `"UNDEFINED"`
* `"AMBIGUOUS"`
* `"FAILED"`


