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

### <a name="Attachment.body"></a>.body 

* Type: string 
* Required: yes 

The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
is simply the string. If it's `BASE64`, the string should be Base64 decoded to
obtain the attachment.

### <a name="Attachment.contentEncoding"></a>.contentEncoding 

* Type: [AttachmentContentEncoding](#attachmentcontentencoding) 
* Required: yes 

Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).

Content encoding is *not* determined by the media type, but rather by the type
of the object being attached:

- string: IDENTITY
- byte array: BASE64
- stream: BASE64

### <a name="Attachment.fileName"></a>.fileName 

* Type: string 
* Required: no 

Suggested file name of the attachment. (Provided by the user as an argument to `attach`)

### <a name="Attachment.mediaType"></a>.mediaType 

* Type: string 
* Required: yes 

The media type of the data. This can be any valid
[IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
and `text/x.cucumber.stacktrace+plain`

### <a name="Attachment.source"></a>.source 

* Type: [Source](#source) 
* Required: no 



### <a name="Attachment.testCaseStartedId"></a>.testCaseStartedId 

* Type: string 
* Required: no 

The identifier of the test case attempt if the attachment was created during the execution of a test step

### <a name="Attachment.testStepId"></a>.testStepId 

* Type: string 
* Required: no 

The identifier of the test step if the attachment was created during the execution of a test step

### <a name="Attachment.url"></a>.url 

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

### <a name="Attachment.testRunStartedId"></a>.testRunStartedId 

* Type: string 
* Required: no 

Not used; implementers should instead populate `testRunHookStartedId` if an attachment was created during the execution of a test run hook

### <a name="Attachment.testRunHookStartedId"></a>.testRunHookStartedId 

* Type: string 
* Required: no 

The identifier of the test run hook execution if the attachment was created during the execution of a test run hook

### <a name="Attachment.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: no 

When the attachment was created

## Duration

The structure is pretty close of the Timestamp one. For clarity, a second type
of message is used.

### <a name="Duration.seconds"></a>.seconds 

* Type: integer 
* Required: yes 



### <a name="Duration.nanos"></a>.nanos 

* Type: integer 
* Required: yes 

Non-negative fractions of a second at nanosecond resolution. Negative
second values with fractions must still have non-negative nanos values
that count forward in time. Must be from 0 to 999,999,999
inclusive.

## Envelope



### <a name="Envelope.attachment"></a>.attachment 

* Type: [Attachment](#attachment) 
* Required: no 



### <a name="Envelope.gherkinDocument"></a>.gherkinDocument 

* Type: [GherkinDocument](#gherkindocument) 
* Required: no 



### <a name="Envelope.hook"></a>.hook 

* Type: [Hook](#hook) 
* Required: no 



### <a name="Envelope.meta"></a>.meta 

* Type: [Meta](#meta) 
* Required: no 



### <a name="Envelope.parameterType"></a>.parameterType 

* Type: [ParameterType](#parametertype) 
* Required: no 



### <a name="Envelope.parseError"></a>.parseError 

* Type: [ParseError](#parseerror) 
* Required: no 



### <a name="Envelope.pickle"></a>.pickle 

* Type: [Pickle](#pickle) 
* Required: no 



### <a name="Envelope.source"></a>.source 

* Type: [Source](#source) 
* Required: no 



### <a name="Envelope.stepDefinition"></a>.stepDefinition 

* Type: [StepDefinition](#stepdefinition) 
* Required: no 



### <a name="Envelope.testCase"></a>.testCase 

* Type: [TestCase](#testcase) 
* Required: no 



### <a name="Envelope.testCaseFinished"></a>.testCaseFinished 

* Type: [TestCaseFinished](#testcasefinished) 
* Required: no 



### <a name="Envelope.testCaseStarted"></a>.testCaseStarted 

* Type: [TestCaseStarted](#testcasestarted) 
* Required: no 



### <a name="Envelope.testRunFinished"></a>.testRunFinished 

* Type: [TestRunFinished](#testrunfinished) 
* Required: no 



### <a name="Envelope.testRunStarted"></a>.testRunStarted 

* Type: [TestRunStarted](#testrunstarted) 
* Required: no 



### <a name="Envelope.testStepFinished"></a>.testStepFinished 

* Type: [TestStepFinished](#teststepfinished) 
* Required: no 



### <a name="Envelope.testStepStarted"></a>.testStepStarted 

* Type: [TestStepStarted](#teststepstarted) 
* Required: no 



### <a name="Envelope.testRunHookStarted"></a>.testRunHookStarted 

* Type: [TestRunHookStarted](#testrunhookstarted) 
* Required: no 



### <a name="Envelope.testRunHookFinished"></a>.testRunHookFinished 

* Type: [TestRunHookFinished](#testrunhookfinished) 
* Required: no 



### <a name="Envelope.undefinedParameterType"></a>.undefinedParameterType 

* Type: [UndefinedParameterType](#undefinedparametertype) 
* Required: no 



## Exception

A simplified representation of an exception

### <a name="Exception.type"></a>.type 

* Type: string 
* Required: yes 

The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"

### <a name="Exception.message"></a>.message 

* Type: string 
* Required: no 

The message of exception that caused this result. E.g. expected: "a" but was: "b"

### <a name="Exception.stackTrace"></a>.stackTrace 

* Type: string 
* Required: no 

The stringified stack trace of the exception that caused this result

## GherkinDocument

The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
Cucumber implementations should *not* depend on `GherkinDocument` or any of its
children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.

The only consumers of `GherkinDocument` should only be formatters that produce
"rich" output, resembling the original Gherkin document.

### <a name="GherkinDocument.uri"></a>.uri 

* Type: string 
* Required: no 

The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
of the source, typically a file path relative to the root directory

### <a name="GherkinDocument.feature"></a>.feature 

* Type: [Feature](#feature) 
* Required: no 



### <a name="GherkinDocument.comments"></a>.comments 

* Type: [Comment](#comment)[] 
* Required: yes 

All the comments in the Gherkin document

## Background



### <a name="Background.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Background` keyword

### <a name="Background.keyword"></a>.keyword 

* Type: string 
* Required: yes 



### <a name="Background.name"></a>.name 

* Type: string 
* Required: yes 



### <a name="Background.description"></a>.description 

* Type: string 
* Required: yes 



### <a name="Background.steps"></a>.steps 

* Type: [Step](#step)[] 
* Required: yes 



### <a name="Background.id"></a>.id 

* Type: string 
* Required: yes 



## Comment

A comment in a Gherkin document

### <a name="Comment.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the comment

### <a name="Comment.text"></a>.text 

* Type: string 
* Required: yes 

The text of the comment

## DataTable



### <a name="DataTable.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 



### <a name="DataTable.rows"></a>.rows 

* Type: [TableRow](#tablerow)[] 
* Required: yes 



## DocString



### <a name="DocString.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 



### <a name="DocString.mediaType"></a>.mediaType 

* Type: string 
* Required: no 



### <a name="DocString.content"></a>.content 

* Type: string 
* Required: yes 



### <a name="DocString.delimiter"></a>.delimiter 

* Type: string 
* Required: yes 



## Examples



### <a name="Examples.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Examples` keyword

### <a name="Examples.tags"></a>.tags 

* Type: [Tag](#tag)[] 
* Required: yes 



### <a name="Examples.keyword"></a>.keyword 

* Type: string 
* Required: yes 



### <a name="Examples.name"></a>.name 

* Type: string 
* Required: yes 



### <a name="Examples.description"></a>.description 

* Type: string 
* Required: yes 



### <a name="Examples.tableHeader"></a>.tableHeader 

* Type: [TableRow](#tablerow) 
* Required: no 



### <a name="Examples.tableBody"></a>.tableBody 

* Type: [TableRow](#tablerow)[] 
* Required: yes 



### <a name="Examples.id"></a>.id 

* Type: string 
* Required: yes 



## Feature



### <a name="Feature.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Feature` keyword

### <a name="Feature.tags"></a>.tags 

* Type: [Tag](#tag)[] 
* Required: yes 

All the tags placed above the `Feature` keyword

### <a name="Feature.language"></a>.language 

* Type: string 
* Required: yes 

The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document

### <a name="Feature.keyword"></a>.keyword 

* Type: string 
* Required: yes 

The text of the `Feature` keyword (in the language specified by `language`)

### <a name="Feature.name"></a>.name 

* Type: string 
* Required: yes 

The name of the feature (the text following the `keyword`)

### <a name="Feature.description"></a>.description 

* Type: string 
* Required: yes 

The line(s) underneath the line with the `keyword` that are used as description

### <a name="Feature.children"></a>.children 

* Type: [FeatureChild](#featurechild)[] 
* Required: yes 

Zero or more children

## FeatureChild

A child node of a `Feature` node

### <a name="FeatureChild.rule"></a>.rule 

* Type: [Rule](#rule) 
* Required: no 



### <a name="FeatureChild.background"></a>.background 

* Type: [Background](#background) 
* Required: no 



### <a name="FeatureChild.scenario"></a>.scenario 

* Type: [Scenario](#scenario) 
* Required: no 



## Rule



### <a name="Rule.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Rule` keyword

### <a name="Rule.tags"></a>.tags 

* Type: [Tag](#tag)[] 
* Required: yes 

All the tags placed above the `Rule` keyword

### <a name="Rule.keyword"></a>.keyword 

* Type: string 
* Required: yes 



### <a name="Rule.name"></a>.name 

* Type: string 
* Required: yes 



### <a name="Rule.description"></a>.description 

* Type: string 
* Required: yes 



### <a name="Rule.children"></a>.children 

* Type: [RuleChild](#rulechild)[] 
* Required: yes 



### <a name="Rule.id"></a>.id 

* Type: string 
* Required: yes 



## RuleChild

A child node of a `Rule` node

### <a name="RuleChild.background"></a>.background 

* Type: [Background](#background) 
* Required: no 



### <a name="RuleChild.scenario"></a>.scenario 

* Type: [Scenario](#scenario) 
* Required: no 



## Scenario



### <a name="Scenario.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the `Scenario` keyword

### <a name="Scenario.tags"></a>.tags 

* Type: [Tag](#tag)[] 
* Required: yes 



### <a name="Scenario.keyword"></a>.keyword 

* Type: string 
* Required: yes 



### <a name="Scenario.name"></a>.name 

* Type: string 
* Required: yes 



### <a name="Scenario.description"></a>.description 

* Type: string 
* Required: yes 



### <a name="Scenario.steps"></a>.steps 

* Type: [Step](#step)[] 
* Required: yes 



### <a name="Scenario.examples"></a>.examples 

* Type: [Examples](#examples)[] 
* Required: yes 



### <a name="Scenario.id"></a>.id 

* Type: string 
* Required: yes 



## Step

A step

### <a name="Step.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the steps' `keyword`

### <a name="Step.keyword"></a>.keyword 

* Type: string 
* Required: yes 

The actual keyword as it appeared in the source.

### <a name="Step.keywordType"></a>.keywordType 

* Type: [StepKeywordType](#stepkeywordtype) 
* Required: no 

The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.

### <a name="Step.text"></a>.text 

* Type: string 
* Required: yes 



### <a name="Step.docString"></a>.docString 

* Type: [DocString](#docstring) 
* Required: no 



### <a name="Step.dataTable"></a>.dataTable 

* Type: [DataTable](#datatable) 
* Required: no 



### <a name="Step.id"></a>.id 

* Type: string 
* Required: yes 

Unique ID to be able to reference the Step from PickleStep

## TableCell

A cell in a `TableRow`

### <a name="TableCell.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the cell

### <a name="TableCell.value"></a>.value 

* Type: string 
* Required: yes 

The value of the cell

## TableRow

A row in a table

### <a name="TableRow.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

The location of the first cell in the row

### <a name="TableRow.cells"></a>.cells 

* Type: [TableCell](#tablecell)[] 
* Required: yes 

Cells in the row

### <a name="TableRow.id"></a>.id 

* Type: string 
* Required: yes 



## Tag

A tag

### <a name="Tag.location"></a>.location 

* Type: [Location](#location) 
* Required: yes 

Location of the tag

### <a name="Tag.name"></a>.name 

* Type: string 
* Required: yes 

The name of the tag (including the leading `@`)

### <a name="Tag.id"></a>.id 

* Type: string 
* Required: yes 

Unique ID to be able to reference the Tag from PickleTag

## Hook



### <a name="Hook.id"></a>.id 

* Type: string 
* Required: yes 



### <a name="Hook.name"></a>.name 

* Type: string 
* Required: no 



### <a name="Hook.sourceReference"></a>.sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



### <a name="Hook.tagExpression"></a>.tagExpression 

* Type: string 
* Required: no 



### <a name="Hook.type"></a>.type 

* Type: [HookType](#hooktype) 
* Required: no 



## Location

Points to a line and a column in a text file

### <a name="Location.line"></a>.line 

* Type: integer 
* Required: yes 



### <a name="Location.column"></a>.column 

* Type: integer 
* Required: no 



## Meta

This message contains meta information about the environment. Consumers can use
this for various purposes.

### <a name="Meta.protocolVersion"></a>.protocolVersion 

* Type: string 
* Required: yes 

The [SEMVER](https://semver.org/) version number of the protocol

### <a name="Meta.implementation"></a>.implementation 

* Type: [Product](#product) 
* Required: yes 

SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.

### <a name="Meta.runtime"></a>.runtime 

* Type: [Product](#product) 
* Required: yes 

Java, Ruby, Node.js etc

### <a name="Meta.os"></a>.os 

* Type: [Product](#product) 
* Required: yes 

Windows, Linux, MacOS etc

### <a name="Meta.cpu"></a>.cpu 

* Type: [Product](#product) 
* Required: yes 

386, arm, amd64 etc

### <a name="Meta.ci"></a>.ci 

* Type: [Ci](#ci) 
* Required: no 



## Ci

CI environment

### <a name="Ci.name"></a>.name 

* Type: string 
* Required: yes 

Name of the CI product, e.g. "Jenkins", "CircleCI" etc.

### <a name="Ci.url"></a>.url 

* Type: string 
* Required: no 

Link to the build

### <a name="Ci.buildNumber"></a>.buildNumber 

* Type: string 
* Required: no 

The build number. Some CI servers use non-numeric build numbers, which is why this is a string

### <a name="Ci.git"></a>.git 

* Type: [Git](#git) 
* Required: no 



## Git

Information about Git, provided by the Build/CI server as environment
variables.

### <a name="Git.remote"></a>.remote 

* Type: string 
* Required: yes 



### <a name="Git.revision"></a>.revision 

* Type: string 
* Required: yes 



### <a name="Git.branch"></a>.branch 

* Type: string 
* Required: no 



### <a name="Git.tag"></a>.tag 

* Type: string 
* Required: no 



## Product

Used to describe various properties of Meta

### <a name="Product.name"></a>.name 

* Type: string 
* Required: yes 

The product name

### <a name="Product.version"></a>.version 

* Type: string 
* Required: no 

The product version

## ParameterType



### <a name="ParameterType.name"></a>.name 

* Type: string 
* Required: yes 

The name is unique, so we don't need an id.

### <a name="ParameterType.regularExpressions"></a>.regularExpressions 

* Type: string[] 
* Required: yes 



### <a name="ParameterType.preferForRegularExpressionMatch"></a>.preferForRegularExpressionMatch 

* Type: boolean 
* Required: yes 



### <a name="ParameterType.useForSnippets"></a>.useForSnippets 

* Type: boolean 
* Required: yes 



### <a name="ParameterType.id"></a>.id 

* Type: string 
* Required: yes 



### <a name="ParameterType.sourceReference"></a>.sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: no 



## ParseError



### <a name="ParseError.source"></a>.source 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



### <a name="ParseError.message"></a>.message 

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

### <a name="Pickle.id"></a>.id 

* Type: string 
* Required: yes 

A unique id for the pickle

### <a name="Pickle.uri"></a>.uri 

* Type: string 
* Required: yes 

The uri of the source file

### <a name="Pickle.name"></a>.name 

* Type: string 
* Required: yes 

The name of the pickle

### <a name="Pickle.language"></a>.language 

* Type: string 
* Required: yes 

The language of the pickle

### <a name="Pickle.steps"></a>.steps 

* Type: [PickleStep](#picklestep)[] 
* Required: yes 

One or more steps

### <a name="Pickle.tags"></a>.tags 

* Type: [PickleTag](#pickletag)[] 
* Required: yes 

One or more tags. If this pickle is constructed from a Gherkin document,
It includes inherited tags from the `Feature` as well.

### <a name="Pickle.astNodeIds"></a>.astNodeIds 

* Type: string[] 
* Required: yes 

Points to the AST node locations of the pickle. The last one represents the unique
id of the pickle. A pickle constructed from `Examples` will have the first
id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.

## PickleDocString



### <a name="PickleDocString.mediaType"></a>.mediaType 

* Type: string 
* Required: no 



### <a name="PickleDocString.content"></a>.content 

* Type: string 
* Required: yes 



## PickleStep

An executable step

### <a name="PickleStep.argument"></a>.argument 

* Type: [PickleStepArgument](#picklestepargument) 
* Required: no 



### <a name="PickleStep.astNodeIds"></a>.astNodeIds 

* Type: string[] 
* Required: yes 

References the IDs of the source of the step. For Gherkin, this can be
the ID of a Step, and possibly also the ID of a TableRow

### <a name="PickleStep.id"></a>.id 

* Type: string 
* Required: yes 

A unique ID for the PickleStep

### <a name="PickleStep.type"></a>.type 

* Type: [PickleStepType](#picklesteptype) 
* Required: no 

The context in which the step was specified: context (Given), action (When) or outcome (Then).

Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)

### <a name="PickleStep.text"></a>.text 

* Type: string 
* Required: yes 



## PickleStepArgument

An optional argument

### <a name="PickleStepArgument.docString"></a>.docString 

* Type: [PickleDocString](#pickledocstring) 
* Required: no 



### <a name="PickleStepArgument.dataTable"></a>.dataTable 

* Type: [PickleTable](#pickletable) 
* Required: no 



## PickleTable



### <a name="PickleTable.rows"></a>.rows 

* Type: [PickleTableRow](#pickletablerow)[] 
* Required: yes 



## PickleTableCell



### <a name="PickleTableCell.value"></a>.value 

* Type: string 
* Required: yes 



## PickleTableRow



### <a name="PickleTableRow.cells"></a>.cells 

* Type: [PickleTableCell](#pickletablecell)[] 
* Required: yes 



## PickleTag

A tag

### <a name="PickleTag.name"></a>.name 

* Type: string 
* Required: yes 



### <a name="PickleTag.astNodeId"></a>.astNodeId 

* Type: string 
* Required: yes 

Points to the AST node this was created from

## Source

A source file, typically a Gherkin document or Java/Ruby/JavaScript source code

### <a name="Source.uri"></a>.uri 

* Type: string 
* Required: yes 

The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
of the source, typically a file path relative to the root directory

### <a name="Source.data"></a>.data 

* Type: string 
* Required: yes 

The contents of the file

### <a name="Source.mediaType"></a>.mediaType 

* Type: [SourceMediaType](#sourcemediatype) 
* Required: yes 

The media type of the file. Can be used to specify custom types, such as
text/x.cucumber.gherkin+plain

## SourceReference

Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
[Location](#io.cucumber.messages.Location) within that file.

### <a name="SourceReference.uri"></a>.uri 

* Type: string 
* Required: no 



### <a name="SourceReference.javaMethod"></a>.javaMethod 

* Type: [JavaMethod](#javamethod) 
* Required: no 



### <a name="SourceReference.javaStackTraceElement"></a>.javaStackTraceElement 

* Type: [JavaStackTraceElement](#javastacktraceelement) 
* Required: no 



### <a name="SourceReference.location"></a>.location 

* Type: [Location](#location) 
* Required: no 



## JavaMethod



### <a name="JavaMethod.className"></a>.className 

* Type: string 
* Required: yes 



### <a name="JavaMethod.methodName"></a>.methodName 

* Type: string 
* Required: yes 



### <a name="JavaMethod.methodParameterTypes"></a>.methodParameterTypes 

* Type: string[] 
* Required: yes 



## JavaStackTraceElement



### <a name="JavaStackTraceElement.className"></a>.className 

* Type: string 
* Required: yes 



### <a name="JavaStackTraceElement.fileName"></a>.fileName 

* Type: string 
* Required: yes 



### <a name="JavaStackTraceElement.methodName"></a>.methodName 

* Type: string 
* Required: yes 



## StepDefinition



### <a name="StepDefinition.id"></a>.id 

* Type: string 
* Required: yes 



### <a name="StepDefinition.pattern"></a>.pattern 

* Type: [StepDefinitionPattern](#stepdefinitionpattern) 
* Required: yes 



### <a name="StepDefinition.sourceReference"></a>.sourceReference 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



## StepDefinitionPattern



### <a name="StepDefinitionPattern.source"></a>.source 

* Type: string 
* Required: yes 



### <a name="StepDefinitionPattern.type"></a>.type 

* Type: [StepDefinitionPatternType](#stepdefinitionpatterntype) 
* Required: yes 



## TestCase

A `TestCase` contains a sequence of `TestStep`s.

### <a name="TestCase.id"></a>.id 

* Type: string 
* Required: yes 



### <a name="TestCase.pickleId"></a>.pickleId 

* Type: string 
* Required: yes 

The ID of the `Pickle` this `TestCase` is derived from.

### <a name="TestCase.testSteps"></a>.testSteps 

* Type: [TestStep](#teststep)[] 
* Required: yes 



### <a name="TestCase.testRunStartedId"></a>.testRunStartedId 

* Type: string 
* Required: no 

Identifier for the test run that this test case belongs to

## Group



### <a name="Group.children"></a>.children 

* Type: [Group](#group)[] 
* Required: yes 



### <a name="Group.start"></a>.start 

* Type: integer 
* Required: no 



### <a name="Group.value"></a>.value 

* Type: string 
* Required: no 



## StepMatchArgument

Represents a single argument extracted from a step match and passed to a step definition.
This is used for the following purposes:
- Construct an argument to pass to a step definition (possibly through a parameter type transform)
- Highlight the matched parameter in rich formatters such as the HTML formatter

This message closely matches the `Argument` class in the `cucumber-expressions` library.

### <a name="StepMatchArgument.group"></a>.group 

* Type: [Group](#group) 
* Required: yes 

Represents the outermost capture group of an argument. This message closely matches the
`Group` class in the `cucumber-expressions` library.

### <a name="StepMatchArgument.parameterTypeName"></a>.parameterTypeName 

* Type: string 
* Required: no 



## StepMatchArgumentsList



### <a name="StepMatchArgumentsList.stepMatchArguments"></a>.stepMatchArguments 

* Type: [StepMatchArgument](#stepmatchargument)[] 
* Required: yes 



## TestStep

A `TestStep` is derived from either a `PickleStep`
combined with a `StepDefinition`, or from a `Hook`.

### <a name="TestStep.hookId"></a>.hookId 

* Type: string 
* Required: no 

Pointer to the `Hook` (if derived from a Hook)

### <a name="TestStep.id"></a>.id 

* Type: string 
* Required: yes 



### <a name="TestStep.pickleStepId"></a>.pickleStepId 

* Type: string 
* Required: no 

Pointer to the `PickleStep` (if derived from a `PickleStep`)

### <a name="TestStep.stepDefinitionIds"></a>.stepDefinitionIds 

* Type: string[] 
* Required: no 

Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`)
Each element represents a matching step definition. A size of 0 means `UNDEFINED`,
and a size of 2+ means `AMBIGUOUS`

### <a name="TestStep.stepMatchArgumentsLists"></a>.stepMatchArgumentsLists 

* Type: [StepMatchArgumentsList](#stepmatchargumentslist)[] 
* Required: no 

A list of list of StepMatchArgument (if derived from a `PickleStep`).

## TestCaseFinished



### <a name="TestCaseFinished.testCaseStartedId"></a>.testCaseStartedId 

* Type: string 
* Required: yes 



### <a name="TestCaseFinished.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



### <a name="TestCaseFinished.willBeRetried"></a>.willBeRetried 

* Type: boolean 
* Required: yes 



## TestCaseStarted



### <a name="TestCaseStarted.attempt"></a>.attempt 

* Type: integer 
* Required: yes 

The first attempt should have value 0, and for each retry the value
should increase by 1.

### <a name="TestCaseStarted.id"></a>.id 

* Type: string 
* Required: yes 

Because a `TestCase` can be run multiple times (in case of a retry),
we use this field to group messages relating to the same attempt.

### <a name="TestCaseStarted.testCaseId"></a>.testCaseId 

* Type: string 
* Required: yes 



### <a name="TestCaseStarted.workerId"></a>.workerId 

* Type: string 
* Required: no 

An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.

### <a name="TestCaseStarted.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunFinished



### <a name="TestRunFinished.message"></a>.message 

* Type: string 
* Required: no 

An informative message about the test run. Typically additional information about failure, but not necessarily.

### <a name="TestRunFinished.success"></a>.success 

* Type: boolean 
* Required: yes 

A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.

### <a name="TestRunFinished.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 

Timestamp when the TestRun is finished

### <a name="TestRunFinished.exception"></a>.exception 

* Type: [Exception](#exception) 
* Required: no 

Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.

### <a name="TestRunFinished.testRunStartedId"></a>.testRunStartedId 

* Type: string 
* Required: no 



## TestRunHookFinished



### <a name="TestRunHookFinished.testRunHookStartedId"></a>.testRunHookStartedId 

* Type: string 
* Required: yes 

Identifier for the hook execution that has finished

### <a name="TestRunHookFinished.result"></a>.result 

* Type: [TestStepResult](#teststepresult) 
* Required: yes 



### <a name="TestRunHookFinished.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunHookStarted



### <a name="TestRunHookStarted.id"></a>.id 

* Type: string 
* Required: yes 

Unique identifier for this hook execution

### <a name="TestRunHookStarted.testRunStartedId"></a>.testRunStartedId 

* Type: string 
* Required: yes 

Identifier for the test run that this hook execution belongs to

### <a name="TestRunHookStarted.hookId"></a>.hookId 

* Type: string 
* Required: yes 

Identifier for the hook that will be executed

### <a name="TestRunHookStarted.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunStarted



### <a name="TestRunStarted.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



### <a name="TestRunStarted.id"></a>.id 

* Type: string 
* Required: no 



## TestStepFinished



### <a name="TestStepFinished.testCaseStartedId"></a>.testCaseStartedId 

* Type: string 
* Required: yes 



### <a name="TestStepFinished.testStepId"></a>.testStepId 

* Type: string 
* Required: yes 



### <a name="TestStepFinished.testStepResult"></a>.testStepResult 

* Type: [TestStepResult](#teststepresult) 
* Required: yes 



### <a name="TestStepFinished.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestStepResult



### <a name="TestStepResult.duration"></a>.duration 

* Type: [Duration](#duration) 
* Required: yes 



### <a name="TestStepResult.message"></a>.message 

* Type: string 
* Required: no 

An arbitrary bit of information that explains this result. If there was an exception, this should include a stringified representation of it including type, message and stack trace (the exact format will vary by platform).

### <a name="TestStepResult.status"></a>.status 

* Type: [TestStepResultStatus](#teststepresultstatus) 
* Required: yes 



### <a name="TestStepResult.exception"></a>.exception 

* Type: [Exception](#exception) 
* Required: no 

Exception thrown while executing this step, if any.

## TestStepStarted



### <a name="TestStepStarted.testCaseStartedId"></a>.testCaseStartedId 

* Type: string 
* Required: yes 



### <a name="TestStepStarted.testStepId"></a>.testStepId 

* Type: string 
* Required: yes 



### <a name="TestStepStarted.timestamp"></a>.timestamp 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## Timestamp



### <a name="Timestamp.seconds"></a>.seconds 

* Type: integer 
* Required: yes 

Represents seconds of UTC time since Unix epoch
1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
9999-12-31T23:59:59Z inclusive.

### <a name="Timestamp.nanos"></a>.nanos 

* Type: integer 
* Required: yes 

Non-negative fractions of a second at nanosecond resolution. Negative
second values with fractions must still have non-negative nanos values
that count forward in time. Must be from 0 to 999,999,999
inclusive.

## UndefinedParameterType



### <a name="UndefinedParameterType.expression"></a>.expression 

* Type: string 
* Required: yes 



### <a name="UndefinedParameterType.name"></a>.name 

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


