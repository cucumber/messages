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

#### Attachment.body 

* Type: string 
* Required: yes 

The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
is simply the string. If it's `BASE64`, the string should be Base64 decoded to
obtain the attachment.

#### Attachment.contentEncoding 

* Type: [AttachmentContentEncoding](#attachmentcontentencoding) 
* Required: yes 

Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).

Content encoding is *not* determined by the media type, but rather by the type
of the object being attached:

- string: IDENTITY
- byte array: BASE64
- stream: BASE64

#### Attachment.fileName 

* Type: string 
* Required: no 

Suggested file name of the attachment. (Provided by the user as an argument to `attach`)

#### Attachment.mediaType 

* Type: string 
* Required: yes 

The media type of the data. This can be any valid
[IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
and `text/x.cucumber.stacktrace+plain`

#### Attachment.source 

* Type: [Source](#source) 
* Required: no 



#### Attachment.testCaseStartedId 

* Type: string 
* Required: no 

The identifier of the test case attempt if the attachment was created during the execution of a test step

#### Attachment.testStepId 

* Type: string 
* Required: no 

The identifier of the test step if the attachment was created during the execution of a test step

#### Attachment.url 

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

#### Attachment.testRunStartedId 

* Type: string 
* Required: no 

Not used; implementers should instead populate `testRunHookStartedId` if an attachment was created during the execution of a test run hook

#### Attachment.testRunHookStartedId 

* Type: string 
* Required: no 

The identifier of the test run hook execution if the attachment was created during the execution of a test run hook

#### Attachment.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: no 

When the attachment was created

## Duration

The structure is pretty close of the Timestamp one. For clarity, a second type
of message is used.

#### Duration.seconds 

* Type: integer 
* Required: yes 



#### Duration.nanos 

* Type: integer 
* Required: yes 

Non-negative fractions of a second at nanosecond resolution. Negative
second values with fractions must still have non-negative nanos values
that count forward in time. Must be from 0 to 999,999,999
inclusive.

## Envelope



#### Envelope.attachment 

* Type: [Attachment](#attachment) 
* Required: no 



#### Envelope.gherkinDocument 

* Type: [GherkinDocument](#gherkindocument) 
* Required: no 



#### Envelope.hook 

* Type: [Hook](#hook) 
* Required: no 



#### Envelope.meta 

* Type: [Meta](#meta) 
* Required: no 



#### Envelope.parameterType 

* Type: [ParameterType](#parametertype) 
* Required: no 



#### Envelope.parseError 

* Type: [ParseError](#parseerror) 
* Required: no 



#### Envelope.pickle 

* Type: [Pickle](#pickle) 
* Required: no 



#### Envelope.source 

* Type: [Source](#source) 
* Required: no 



#### Envelope.stepDefinition 

* Type: [StepDefinition](#stepdefinition) 
* Required: no 



#### Envelope.testCase 

* Type: [TestCase](#testcase) 
* Required: no 



#### Envelope.testCaseFinished 

* Type: [TestCaseFinished](#testcasefinished) 
* Required: no 



#### Envelope.testCaseStarted 

* Type: [TestCaseStarted](#testcasestarted) 
* Required: no 



#### Envelope.testRunFinished 

* Type: [TestRunFinished](#testrunfinished) 
* Required: no 



#### Envelope.testRunStarted 

* Type: [TestRunStarted](#testrunstarted) 
* Required: no 



#### Envelope.testStepFinished 

* Type: [TestStepFinished](#teststepfinished) 
* Required: no 



#### Envelope.testStepStarted 

* Type: [TestStepStarted](#teststepstarted) 
* Required: no 



#### Envelope.testRunHookStarted 

* Type: [TestRunHookStarted](#testrunhookstarted) 
* Required: no 



#### Envelope.testRunHookFinished 

* Type: [TestRunHookFinished](#testrunhookfinished) 
* Required: no 



#### Envelope.undefinedParameterType 

* Type: [UndefinedParameterType](#undefinedparametertype) 
* Required: no 



## Exception

A simplified representation of an exception

#### Exception.type 

* Type: string 
* Required: yes 

The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"

#### Exception.message 

* Type: string 
* Required: no 

The message of exception that caused this result. E.g. expected: "a" but was: "b"

#### Exception.stackTrace 

* Type: string 
* Required: no 

The stringified stack trace of the exception that caused this result

## GherkinDocument

The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
Cucumber implementations should *not* depend on `GherkinDocument` or any of its
children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.

The only consumers of `GherkinDocument` should only be formatters that produce
"rich" output, resembling the original Gherkin document.

#### GherkinDocument.uri 

* Type: string 
* Required: no 

The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
of the source, typically a file path relative to the root directory

#### GherkinDocument.feature 

* Type: [Feature](#feature) 
* Required: no 



#### GherkinDocument.comments 

* Type: [Comment](#comment)[] 
* Required: yes 

All the comments in the Gherkin document

## Background



#### Background.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Background` keyword

#### Background.keyword 

* Type: string 
* Required: yes 



#### Background.name 

* Type: string 
* Required: yes 



#### Background.description 

* Type: string 
* Required: yes 



#### Background.steps 

* Type: [Step](#step)[] 
* Required: yes 



#### Background.id 

* Type: string 
* Required: yes 



## Comment

A comment in a Gherkin document

#### Comment.location 

* Type: [Location](#location) 
* Required: yes 

The location of the comment

#### Comment.text 

* Type: string 
* Required: yes 

The text of the comment

## DataTable



#### DataTable.location 

* Type: [Location](#location) 
* Required: yes 



#### DataTable.rows 

* Type: [TableRow](#tablerow)[] 
* Required: yes 



## DocString



#### DocString.location 

* Type: [Location](#location) 
* Required: yes 



#### DocString.mediaType 

* Type: string 
* Required: no 



#### DocString.content 

* Type: string 
* Required: yes 



#### DocString.delimiter 

* Type: string 
* Required: yes 



## Examples



#### Examples.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Examples` keyword

#### Examples.tags 

* Type: [Tag](#tag)[] 
* Required: yes 



#### Examples.keyword 

* Type: string 
* Required: yes 



#### Examples.name 

* Type: string 
* Required: yes 



#### Examples.description 

* Type: string 
* Required: yes 



#### Examples.tableHeader 

* Type: [TableRow](#tablerow) 
* Required: no 



#### Examples.tableBody 

* Type: [TableRow](#tablerow)[] 
* Required: yes 



#### Examples.id 

* Type: string 
* Required: yes 



## Feature



#### Feature.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Feature` keyword

#### Feature.tags 

* Type: [Tag](#tag)[] 
* Required: yes 

All the tags placed above the `Feature` keyword

#### Feature.language 

* Type: string 
* Required: yes 

The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document

#### Feature.keyword 

* Type: string 
* Required: yes 

The text of the `Feature` keyword (in the language specified by `language`)

#### Feature.name 

* Type: string 
* Required: yes 

The name of the feature (the text following the `keyword`)

#### Feature.description 

* Type: string 
* Required: yes 

The line(s) underneath the line with the `keyword` that are used as description

#### Feature.children 

* Type: [FeatureChild](#featurechild)[] 
* Required: yes 

Zero or more children

## FeatureChild

A child node of a `Feature` node

#### FeatureChild.rule 

* Type: [Rule](#rule) 
* Required: no 



#### FeatureChild.background 

* Type: [Background](#background) 
* Required: no 



#### FeatureChild.scenario 

* Type: [Scenario](#scenario) 
* Required: no 



## Rule



#### Rule.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Rule` keyword

#### Rule.tags 

* Type: [Tag](#tag)[] 
* Required: yes 

All the tags placed above the `Rule` keyword

#### Rule.keyword 

* Type: string 
* Required: yes 



#### Rule.name 

* Type: string 
* Required: yes 



#### Rule.description 

* Type: string 
* Required: yes 



#### Rule.children 

* Type: [RuleChild](#rulechild)[] 
* Required: yes 



#### Rule.id 

* Type: string 
* Required: yes 



## RuleChild

A child node of a `Rule` node

#### RuleChild.background 

* Type: [Background](#background) 
* Required: no 



#### RuleChild.scenario 

* Type: [Scenario](#scenario) 
* Required: no 



## Scenario



#### Scenario.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Scenario` keyword

#### Scenario.tags 

* Type: [Tag](#tag)[] 
* Required: yes 



#### Scenario.keyword 

* Type: string 
* Required: yes 



#### Scenario.name 

* Type: string 
* Required: yes 



#### Scenario.description 

* Type: string 
* Required: yes 



#### Scenario.steps 

* Type: [Step](#step)[] 
* Required: yes 



#### Scenario.examples 

* Type: [Examples](#examples)[] 
* Required: yes 



#### Scenario.id 

* Type: string 
* Required: yes 



## Step

A step

#### Step.location 

* Type: [Location](#location) 
* Required: yes 

The location of the steps' `keyword`

#### Step.keyword 

* Type: string 
* Required: yes 

The actual keyword as it appeared in the source.

#### Step.keywordType 

* Type: [StepKeywordType](#stepkeywordtype) 
* Required: no 

The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.

#### Step.text 

* Type: string 
* Required: yes 



#### Step.docString 

* Type: [DocString](#docstring) 
* Required: no 



#### Step.dataTable 

* Type: [DataTable](#datatable) 
* Required: no 



#### Step.id 

* Type: string 
* Required: yes 

Unique ID to be able to reference the Step from PickleStep

## TableCell

A cell in a `TableRow`

#### TableCell.location 

* Type: [Location](#location) 
* Required: yes 

The location of the cell

#### TableCell.value 

* Type: string 
* Required: yes 

The value of the cell

## TableRow

A row in a table

#### TableRow.location 

* Type: [Location](#location) 
* Required: yes 

The location of the first cell in the row

#### TableRow.cells 

* Type: [TableCell](#tablecell)[] 
* Required: yes 

Cells in the row

#### TableRow.id 

* Type: string 
* Required: yes 



## Tag

A tag

#### Tag.location 

* Type: [Location](#location) 
* Required: yes 

Location of the tag

#### Tag.name 

* Type: string 
* Required: yes 

The name of the tag (including the leading `@`)

#### Tag.id 

* Type: string 
* Required: yes 

Unique ID to be able to reference the Tag from PickleTag

## Hook



#### Hook.id 

* Type: string 
* Required: yes 



#### Hook.name 

* Type: string 
* Required: no 



#### Hook.sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



#### Hook.tagExpression 

* Type: string 
* Required: no 



#### Hook.type 

* Type: [HookType](#hooktype) 
* Required: no 



## Location

Points to a line and a column in a text file

#### Location.line 

* Type: integer 
* Required: yes 



#### Location.column 

* Type: integer 
* Required: no 



## Meta

This message contains meta information about the environment. Consumers can use
this for various purposes.

#### Meta.protocolVersion 

* Type: string 
* Required: yes 

The [SEMVER](https://semver.org/) version number of the protocol

#### Meta.implementation 

* Type: [Product](#product) 
* Required: yes 

SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.

#### Meta.runtime 

* Type: [Product](#product) 
* Required: yes 

Java, Ruby, Node.js etc

#### Meta.os 

* Type: [Product](#product) 
* Required: yes 

Windows, Linux, MacOS etc

#### Meta.cpu 

* Type: [Product](#product) 
* Required: yes 

386, arm, amd64 etc

#### Meta.ci 

* Type: [Ci](#ci) 
* Required: no 



## Ci

CI environment

#### Ci.name 

* Type: string 
* Required: yes 

Name of the CI product, e.g. "Jenkins", "CircleCI" etc.

#### Ci.url 

* Type: string 
* Required: no 

Link to the build

#### Ci.buildNumber 

* Type: string 
* Required: no 

The build number. Some CI servers use non-numeric build numbers, which is why this is a string

#### Ci.git 

* Type: [Git](#git) 
* Required: no 



## Git

Information about Git, provided by the Build/CI server as environment
variables.

#### Git.remote 

* Type: string 
* Required: yes 



#### Git.revision 

* Type: string 
* Required: yes 



#### Git.branch 

* Type: string 
* Required: no 



#### Git.tag 

* Type: string 
* Required: no 



## Product

Used to describe various properties of Meta

#### Product.name 

* Type: string 
* Required: yes 

The product name

#### Product.version 

* Type: string 
* Required: no 

The product version

## ParameterType



#### ParameterType.name 

* Type: string 
* Required: yes 

The name is unique, so we don't need an id.

#### ParameterType.regularExpressions 

* Type: string[] 
* Required: yes 



#### ParameterType.preferForRegularExpressionMatch 

* Type: boolean 
* Required: yes 



#### ParameterType.useForSnippets 

* Type: boolean 
* Required: yes 



#### ParameterType.id 

* Type: string 
* Required: yes 



#### ParameterType.sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: no 



## ParseError



#### ParseError.source 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



#### ParseError.message 

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

#### Pickle.id 

* Type: string 
* Required: yes 

A unique id for the pickle

#### Pickle.uri 

* Type: string 
* Required: yes 

The uri of the source file

#### Pickle.name 

* Type: string 
* Required: yes 

The name of the pickle

#### Pickle.language 

* Type: string 
* Required: yes 

The language of the pickle

#### Pickle.steps 

* Type: [PickleStep](#picklestep)[] 
* Required: yes 

One or more steps

#### Pickle.tags 

* Type: [PickleTag](#pickletag)[] 
* Required: yes 

One or more tags. If this pickle is constructed from a Gherkin document,
It includes inherited tags from the `Feature` as well.

#### Pickle.astNodeIds 

* Type: string[] 
* Required: yes 

Points to the AST node locations of the pickle. The last one represents the unique
id of the pickle. A pickle constructed from `Examples` will have the first
id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.

## PickleDocString



#### PickleDocString.mediaType 

* Type: string 
* Required: no 



#### PickleDocString.content 

* Type: string 
* Required: yes 



## PickleStep

An executable step

#### PickleStep.argument 

* Type: [PickleStepArgument](#picklestepargument) 
* Required: no 



#### PickleStep.astNodeIds 

* Type: string[] 
* Required: yes 

References the IDs of the source of the step. For Gherkin, this can be
the ID of a Step, and possibly also the ID of a TableRow

#### PickleStep.id 

* Type: string 
* Required: yes 

A unique ID for the PickleStep

#### PickleStep.type 

* Type: [PickleStepType](#picklesteptype) 
* Required: no 

The context in which the step was specified: context (Given), action (When) or outcome (Then).

Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)

#### PickleStep.text 

* Type: string 
* Required: yes 



## PickleStepArgument

An optional argument

#### PickleStepArgument.docString 

* Type: [PickleDocString](#pickledocstring) 
* Required: no 



#### PickleStepArgument.dataTable 

* Type: [PickleTable](#pickletable) 
* Required: no 



## PickleTable



#### PickleTable.rows 

* Type: [PickleTableRow](#pickletablerow)[] 
* Required: yes 



## PickleTableCell



#### PickleTableCell.value 

* Type: string 
* Required: yes 



## PickleTableRow



#### PickleTableRow.cells 

* Type: [PickleTableCell](#pickletablecell)[] 
* Required: yes 



## PickleTag

A tag

#### PickleTag.name 

* Type: string 
* Required: yes 



#### PickleTag.astNodeId 

* Type: string 
* Required: yes 

Points to the AST node this was created from

## Source

A source file, typically a Gherkin document or Java/Ruby/JavaScript source code

#### Source.uri 

* Type: string 
* Required: yes 

The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
of the source, typically a file path relative to the root directory

#### Source.data 

* Type: string 
* Required: yes 

The contents of the file

#### Source.mediaType 

* Type: [SourceMediaType](#sourcemediatype) 
* Required: yes 

The media type of the file. Can be used to specify custom types, such as
text/x.cucumber.gherkin+plain

## SourceReference

Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
[Location](#io.cucumber.messages.Location) within that file.

#### SourceReference.uri 

* Type: string 
* Required: no 



#### SourceReference.javaMethod 

* Type: [JavaMethod](#javamethod) 
* Required: no 



#### SourceReference.javaStackTraceElement 

* Type: [JavaStackTraceElement](#javastacktraceelement) 
* Required: no 



#### SourceReference.location 

* Type: [Location](#location) 
* Required: no 



## JavaMethod



#### JavaMethod.className 

* Type: string 
* Required: yes 



#### JavaMethod.methodName 

* Type: string 
* Required: yes 



#### JavaMethod.methodParameterTypes 

* Type: string[] 
* Required: yes 



## JavaStackTraceElement



#### JavaStackTraceElement.className 

* Type: string 
* Required: yes 



#### JavaStackTraceElement.fileName 

* Type: string 
* Required: yes 



#### JavaStackTraceElement.methodName 

* Type: string 
* Required: yes 



## StepDefinition



#### StepDefinition.id 

* Type: string 
* Required: yes 



#### StepDefinition.pattern 

* Type: [StepDefinitionPattern](#stepdefinitionpattern) 
* Required: yes 



#### StepDefinition.sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



## StepDefinitionPattern



#### StepDefinitionPattern.source 

* Type: string 
* Required: yes 



#### StepDefinitionPattern.type 

* Type: [StepDefinitionPatternType](#stepdefinitionpatterntype) 
* Required: yes 



## TestCase

A `TestCase` contains a sequence of `TestStep`s.

#### TestCase.id 

* Type: string 
* Required: yes 



#### TestCase.pickleId 

* Type: string 
* Required: yes 

The ID of the `Pickle` this `TestCase` is derived from.

#### TestCase.testSteps 

* Type: [TestStep](#teststep)[] 
* Required: yes 



#### TestCase.testRunStartedId 

* Type: string 
* Required: no 

Identifier for the test run that this test case belongs to

## Group



#### Group.children 

* Type: [Group](#group)[] 
* Required: yes 



#### Group.start 

* Type: integer 
* Required: no 



#### Group.value 

* Type: string 
* Required: no 



## StepMatchArgument

Represents a single argument extracted from a step match and passed to a step definition.
This is used for the following purposes:
- Construct an argument to pass to a step definition (possibly through a parameter type transform)
- Highlight the matched parameter in rich formatters such as the HTML formatter

This message closely matches the `Argument` class in the `cucumber-expressions` library.

#### StepMatchArgument.group 

* Type: [Group](#group) 
* Required: yes 

Represents the outermost capture group of an argument. This message closely matches the
`Group` class in the `cucumber-expressions` library.

#### StepMatchArgument.parameterTypeName 

* Type: string 
* Required: no 



## StepMatchArgumentsList



#### StepMatchArgumentsList.stepMatchArguments 

* Type: [StepMatchArgument](#stepmatchargument)[] 
* Required: yes 



## TestStep

A `TestStep` is derived from either a `PickleStep`
combined with a `StepDefinition`, or from a `Hook`.

#### TestStep.hookId 

* Type: string 
* Required: no 

Pointer to the `Hook` (if derived from a Hook)

#### TestStep.id 

* Type: string 
* Required: yes 



#### TestStep.pickleStepId 

* Type: string 
* Required: no 

Pointer to the `PickleStep` (if derived from a `PickleStep`)

#### TestStep.stepDefinitionIds 

* Type: string[] 
* Required: no 

Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`)
Each element represents a matching step definition. A size of 0 means `UNDEFINED`,
and a size of 2+ means `AMBIGUOUS`

#### TestStep.stepMatchArgumentsLists 

* Type: [StepMatchArgumentsList](#stepmatchargumentslist)[] 
* Required: no 

A list of list of StepMatchArgument (if derived from a `PickleStep`). There is one list for each matched step definition. A size of 0 means `UNDEFINED`,
and a size of 2+ means `AMBIGUOUS`

## TestCaseFinished



#### TestCaseFinished.testCaseStartedId 

* Type: string 
* Required: yes 



#### TestCaseFinished.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



#### TestCaseFinished.willBeRetried 

* Type: boolean 
* Required: yes 



## TestCaseStarted



#### TestCaseStarted.attempt 

* Type: integer 
* Required: yes 

The first attempt should have value 0, and for each retry the value
should increase by 1.

#### TestCaseStarted.id 

* Type: string 
* Required: yes 

Because a `TestCase` can be run multiple times (in case of a retry),
we use this field to group messages relating to the same attempt.

#### TestCaseStarted.testCaseId 

* Type: string 
* Required: yes 



#### TestCaseStarted.workerId 

* Type: string 
* Required: no 

An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.

#### TestCaseStarted.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunFinished



#### TestRunFinished.message 

* Type: string 
* Required: no 

An informative message about the test run. Typically additional information about failure, but not necessarily.

#### TestRunFinished.success 

* Type: boolean 
* Required: yes 

A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.

#### TestRunFinished.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 

Timestamp when the TestRun is finished

#### TestRunFinished.exception 

* Type: [Exception](#exception) 
* Required: no 

Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.

#### TestRunFinished.testRunStartedId 

* Type: string 
* Required: no 



## TestRunHookFinished



#### TestRunHookFinished.testRunHookStartedId 

* Type: string 
* Required: yes 

Identifier for the hook execution that has finished

#### TestRunHookFinished.result 

* Type: [TestStepResult](#teststepresult) 
* Required: yes 



#### TestRunHookFinished.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunHookStarted



#### TestRunHookStarted.id 

* Type: string 
* Required: yes 

Unique identifier for this hook execution

#### TestRunHookStarted.testRunStartedId 

* Type: string 
* Required: yes 

Identifier for the test run that this hook execution belongs to

#### TestRunHookStarted.hookId 

* Type: string 
* Required: yes 

Identifier for the hook that will be executed

#### TestRunHookStarted.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunStarted



#### TestRunStarted.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



#### TestRunStarted.id 

* Type: string 
* Required: no 



## TestStepFinished



#### TestStepFinished.testCaseStartedId 

* Type: string 
* Required: yes 



#### TestStepFinished.testStepId 

* Type: string 
* Required: yes 



#### TestStepFinished.testStepResult 

* Type: [TestStepResult](#teststepresult) 
* Required: yes 



#### TestStepFinished.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestStepResult



#### TestStepResult.duration 

* Type: [Duration](#duration) 
* Required: yes 



#### TestStepResult.message 

* Type: string 
* Required: no 

An arbitrary bit of information that explains this result. If there was an exception, this should include a stringified representation of it including type, message and stack trace (the exact format will vary by platform).

#### TestStepResult.status 

* Type: [TestStepResultStatus](#teststepresultstatus) 
* Required: yes 



#### TestStepResult.exception 

* Type: [Exception](#exception) 
* Required: no 

Exception thrown while executing this step, if any.

## TestStepStarted



#### TestStepStarted.testCaseStartedId 

* Type: string 
* Required: yes 



#### TestStepStarted.testStepId 

* Type: string 
* Required: yes 



#### TestStepStarted.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## Timestamp



#### Timestamp.seconds 

* Type: integer 
* Required: yes 

Represents seconds of UTC time since Unix epoch
1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
9999-12-31T23:59:59Z inclusive.

#### Timestamp.nanos 

* Type: integer 
* Required: yes 

Non-negative fractions of a second at nanosecond resolution. Negative
second values with fractions must still have non-negative nanos values
that count forward in time. Must be from 0 to 999,999,999
inclusive.

## UndefinedParameterType



#### UndefinedParameterType.expression 

* Type: string 
* Required: yes 



#### UndefinedParameterType.name 

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


