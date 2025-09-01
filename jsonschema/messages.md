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
 
<h2><a name="Attachment.body"></a>.body</h2> 

* Type: string 
* Required: yes 

The body of the attachment. If `contentEncoding` is `IDENTITY`, the attachment
is simply the string. If it's `BASE64`, the string should be Base64 decoded to
obtain the attachment.
 
<h2><a name="Attachment.contentEncoding"></a>.contentEncoding</h2> 

* Type: [AttachmentContentEncoding](#attachmentcontentencoding) 
* Required: yes 

Whether to interpret `body` "as-is" (IDENTITY) or if it needs to be Base64-decoded (BASE64).

Content encoding is *not* determined by the media type, but rather by the type
of the object being attached:

- string: IDENTITY
- byte array: BASE64
- stream: BASE64
 
<h2><a name="Attachment.fileName"></a>.fileName</h2> 

* Type: string 
* Required: no 

Suggested file name of the attachment. (Provided by the user as an argument to `attach`)
 
<h2><a name="Attachment.mediaType"></a>.mediaType</h2> 

* Type: string 
* Required: yes 

The media type of the data. This can be any valid
[IANA Media Type](https://www.iana.org/assignments/media-types/media-types.xhtml)
as well as Cucumber-specific media types such as `text/x.cucumber.gherkin+plain`
and `text/x.cucumber.stacktrace+plain`
 
<h2><a name="Attachment.source"></a>.source</h2> 

* Type: [Source](#source) 
* Required: no 


 
<h2><a name="Attachment.testCaseStartedId"></a>.testCaseStartedId</h2> 

* Type: string 
* Required: no 

The identifier of the test case attempt if the attachment was created during the execution of a test step
 
<h2><a name="Attachment.testStepId"></a>.testStepId</h2> 

* Type: string 
* Required: no 

The identifier of the test step if the attachment was created during the execution of a test step
 
<h2><a name="Attachment.url"></a>.url</h2> 

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
 
<h2><a name="Attachment.testRunStartedId"></a>.testRunStartedId</h2> 

* Type: string 
* Required: no 

Not used; implementers should instead populate `testRunHookStartedId` if an attachment was created during the execution of a test run hook
 
<h2><a name="Attachment.testRunHookStartedId"></a>.testRunHookStartedId</h2> 

* Type: string 
* Required: no 

The identifier of the test run hook execution if the attachment was created during the execution of a test run hook
 
<h2><a name="Attachment.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: no 

When the attachment was created

## Duration

The structure is pretty close of the Timestamp one. For clarity, a second type
of message is used.
 
<h2><a name="Duration.seconds"></a>.seconds</h2> 

* Type: integer 
* Required: yes 


 
<h2><a name="Duration.nanos"></a>.nanos</h2> 

* Type: integer 
* Required: yes 

Non-negative fractions of a second at nanosecond resolution. Negative
second values with fractions must still have non-negative nanos values
that count forward in time. Must be from 0 to 999,999,999
inclusive.

## Envelope


 
<h2><a name="Envelope.attachment"></a>.attachment</h2> 

* Type: [Attachment](#attachment) 
* Required: no 


 
<h2><a name="Envelope.gherkinDocument"></a>.gherkinDocument</h2> 

* Type: [GherkinDocument](#gherkindocument) 
* Required: no 


 
<h2><a name="Envelope.hook"></a>.hook</h2> 

* Type: [Hook](#hook) 
* Required: no 


 
<h2><a name="Envelope.meta"></a>.meta</h2> 

* Type: [Meta](#meta) 
* Required: no 


 
<h2><a name="Envelope.parameterType"></a>.parameterType</h2> 

* Type: [ParameterType](#parametertype) 
* Required: no 


 
<h2><a name="Envelope.parseError"></a>.parseError</h2> 

* Type: [ParseError](#parseerror) 
* Required: no 


 
<h2><a name="Envelope.pickle"></a>.pickle</h2> 

* Type: [Pickle](#pickle) 
* Required: no 


 
<h2><a name="Envelope.source"></a>.source</h2> 

* Type: [Source](#source) 
* Required: no 


 
<h2><a name="Envelope.stepDefinition"></a>.stepDefinition</h2> 

* Type: [StepDefinition](#stepdefinition) 
* Required: no 


 
<h2><a name="Envelope.testCase"></a>.testCase</h2> 

* Type: [TestCase](#testcase) 
* Required: no 


 
<h2><a name="Envelope.testCaseFinished"></a>.testCaseFinished</h2> 

* Type: [TestCaseFinished](#testcasefinished) 
* Required: no 


 
<h2><a name="Envelope.testCaseStarted"></a>.testCaseStarted</h2> 

* Type: [TestCaseStarted](#testcasestarted) 
* Required: no 


 
<h2><a name="Envelope.testRunFinished"></a>.testRunFinished</h2> 

* Type: [TestRunFinished](#testrunfinished) 
* Required: no 


 
<h2><a name="Envelope.testRunStarted"></a>.testRunStarted</h2> 

* Type: [TestRunStarted](#testrunstarted) 
* Required: no 


 
<h2><a name="Envelope.testStepFinished"></a>.testStepFinished</h2> 

* Type: [TestStepFinished](#teststepfinished) 
* Required: no 


 
<h2><a name="Envelope.testStepStarted"></a>.testStepStarted</h2> 

* Type: [TestStepStarted](#teststepstarted) 
* Required: no 


 
<h2><a name="Envelope.testRunHookStarted"></a>.testRunHookStarted</h2> 

* Type: [TestRunHookStarted](#testrunhookstarted) 
* Required: no 


 
<h2><a name="Envelope.testRunHookFinished"></a>.testRunHookFinished</h2> 

* Type: [TestRunHookFinished](#testrunhookfinished) 
* Required: no 


 
<h2><a name="Envelope.undefinedParameterType"></a>.undefinedParameterType</h2> 

* Type: [UndefinedParameterType](#undefinedparametertype) 
* Required: no 



## Exception

A simplified representation of an exception
 
<h2><a name="Exception.type"></a>.type</h2> 

* Type: string 
* Required: yes 

The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
 
<h2><a name="Exception.message"></a>.message</h2> 

* Type: string 
* Required: no 

The message of exception that caused this result. E.g. expected: "a" but was: "b"
 
<h2><a name="Exception.stackTrace"></a>.stackTrace</h2> 

* Type: string 
* Required: no 

The stringified stack trace of the exception that caused this result

## GherkinDocument

The [AST](https://en.wikipedia.org/wiki/Abstract_syntax_tree) of a Gherkin document.
Cucumber implementations should *not* depend on `GherkinDocument` or any of its
children for execution - use [Pickle](#io.cucumber.messages.Pickle) instead.

The only consumers of `GherkinDocument` should only be formatters that produce
"rich" output, resembling the original Gherkin document.
 
<h2><a name="GherkinDocument.uri"></a>.uri</h2> 

* Type: string 
* Required: no 

The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
of the source, typically a file path relative to the root directory
 
<h2><a name="GherkinDocument.feature"></a>.feature</h2> 

* Type: [Feature](#feature) 
* Required: no 


 
<h2><a name="GherkinDocument.comments"></a>.comments</h2> 

* Type: [Comment](#comment)[] 
* Required: yes 

All the comments in the Gherkin document

## Background


 
<h2><a name="Background.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the `Background` keyword
 
<h2><a name="Background.keyword"></a>.keyword</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Background.name"></a>.name</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Background.description"></a>.description</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Background.steps"></a>.steps</h2> 

* Type: [Step](#step)[] 
* Required: yes 


 
<h2><a name="Background.id"></a>.id</h2> 

* Type: string 
* Required: yes 



## Comment

A comment in a Gherkin document
 
<h2><a name="Comment.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the comment
 
<h2><a name="Comment.text"></a>.text</h2> 

* Type: string 
* Required: yes 

The text of the comment

## DataTable


 
<h2><a name="DataTable.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 


 
<h2><a name="DataTable.rows"></a>.rows</h2> 

* Type: [TableRow](#tablerow)[] 
* Required: yes 



## DocString


 
<h2><a name="DocString.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 


 
<h2><a name="DocString.mediaType"></a>.mediaType</h2> 

* Type: string 
* Required: no 


 
<h2><a name="DocString.content"></a>.content</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="DocString.delimiter"></a>.delimiter</h2> 

* Type: string 
* Required: yes 



## Examples


 
<h2><a name="Examples.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the `Examples` keyword
 
<h2><a name="Examples.tags"></a>.tags</h2> 

* Type: [Tag](#tag)[] 
* Required: yes 


 
<h2><a name="Examples.keyword"></a>.keyword</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Examples.name"></a>.name</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Examples.description"></a>.description</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Examples.tableHeader"></a>.tableHeader</h2> 

* Type: [TableRow](#tablerow) 
* Required: no 


 
<h2><a name="Examples.tableBody"></a>.tableBody</h2> 

* Type: [TableRow](#tablerow)[] 
* Required: yes 


 
<h2><a name="Examples.id"></a>.id</h2> 

* Type: string 
* Required: yes 



## Feature


 
<h2><a name="Feature.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the `Feature` keyword
 
<h2><a name="Feature.tags"></a>.tags</h2> 

* Type: [Tag](#tag)[] 
* Required: yes 

All the tags placed above the `Feature` keyword
 
<h2><a name="Feature.language"></a>.language</h2> 

* Type: string 
* Required: yes 

The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document
 
<h2><a name="Feature.keyword"></a>.keyword</h2> 

* Type: string 
* Required: yes 

The text of the `Feature` keyword (in the language specified by `language`)
 
<h2><a name="Feature.name"></a>.name</h2> 

* Type: string 
* Required: yes 

The name of the feature (the text following the `keyword`)
 
<h2><a name="Feature.description"></a>.description</h2> 

* Type: string 
* Required: yes 

The line(s) underneath the line with the `keyword` that are used as description
 
<h2><a name="Feature.children"></a>.children</h2> 

* Type: [FeatureChild](#featurechild)[] 
* Required: yes 

Zero or more children

## FeatureChild

A child node of a `Feature` node
 
<h2><a name="FeatureChild.rule"></a>.rule</h2> 

* Type: [Rule](#rule) 
* Required: no 


 
<h2><a name="FeatureChild.background"></a>.background</h2> 

* Type: [Background](#background) 
* Required: no 


 
<h2><a name="FeatureChild.scenario"></a>.scenario</h2> 

* Type: [Scenario](#scenario) 
* Required: no 



## Rule


 
<h2><a name="Rule.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the `Rule` keyword
 
<h2><a name="Rule.tags"></a>.tags</h2> 

* Type: [Tag](#tag)[] 
* Required: yes 

All the tags placed above the `Rule` keyword
 
<h2><a name="Rule.keyword"></a>.keyword</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Rule.name"></a>.name</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Rule.description"></a>.description</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Rule.children"></a>.children</h2> 

* Type: [RuleChild](#rulechild)[] 
* Required: yes 


 
<h2><a name="Rule.id"></a>.id</h2> 

* Type: string 
* Required: yes 



## RuleChild

A child node of a `Rule` node
 
<h2><a name="RuleChild.background"></a>.background</h2> 

* Type: [Background](#background) 
* Required: no 


 
<h2><a name="RuleChild.scenario"></a>.scenario</h2> 

* Type: [Scenario](#scenario) 
* Required: no 



## Scenario


 
<h2><a name="Scenario.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the `Scenario` keyword
 
<h2><a name="Scenario.tags"></a>.tags</h2> 

* Type: [Tag](#tag)[] 
* Required: yes 


 
<h2><a name="Scenario.keyword"></a>.keyword</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Scenario.name"></a>.name</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Scenario.description"></a>.description</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Scenario.steps"></a>.steps</h2> 

* Type: [Step](#step)[] 
* Required: yes 


 
<h2><a name="Scenario.examples"></a>.examples</h2> 

* Type: [Examples](#examples)[] 
* Required: yes 


 
<h2><a name="Scenario.id"></a>.id</h2> 

* Type: string 
* Required: yes 



## Step

A step
 
<h2><a name="Step.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the steps' `keyword`
 
<h2><a name="Step.keyword"></a>.keyword</h2> 

* Type: string 
* Required: yes 

The actual keyword as it appeared in the source.
 
<h2><a name="Step.keywordType"></a>.keywordType</h2> 

* Type: [StepKeywordType](#stepkeywordtype) 
* Required: no 

The test phase signalled by the keyword: Context definition (Given), Action performance (When), Outcome assertion (Then). Other keywords signal Continuation (And and But) from a prior keyword. Please note that all translations which a dialect maps to multiple keywords (`*` is in this category for all dialects), map to 'Unknown'.
 
<h2><a name="Step.text"></a>.text</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Step.docString"></a>.docString</h2> 

* Type: [DocString](#docstring) 
* Required: no 


 
<h2><a name="Step.dataTable"></a>.dataTable</h2> 

* Type: [DataTable](#datatable) 
* Required: no 


 
<h2><a name="Step.id"></a>.id</h2> 

* Type: string 
* Required: yes 

Unique ID to be able to reference the Step from PickleStep

## TableCell

A cell in a `TableRow`
 
<h2><a name="TableCell.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the cell
 
<h2><a name="TableCell.value"></a>.value</h2> 

* Type: string 
* Required: yes 

The value of the cell

## TableRow

A row in a table
 
<h2><a name="TableRow.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

The location of the first cell in the row
 
<h2><a name="TableRow.cells"></a>.cells</h2> 

* Type: [TableCell](#tablecell)[] 
* Required: yes 

Cells in the row
 
<h2><a name="TableRow.id"></a>.id</h2> 

* Type: string 
* Required: yes 



## Tag

A tag
 
<h2><a name="Tag.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: yes 

Location of the tag
 
<h2><a name="Tag.name"></a>.name</h2> 

* Type: string 
* Required: yes 

The name of the tag (including the leading `@`)
 
<h2><a name="Tag.id"></a>.id</h2> 

* Type: string 
* Required: yes 

Unique ID to be able to reference the Tag from PickleTag

## Hook


 
<h2><a name="Hook.id"></a>.id</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Hook.name"></a>.name</h2> 

* Type: string 
* Required: no 


 
<h2><a name="Hook.sourceReference"></a>.sourceReference</h2> 

* Type: [SourceReference](#sourcereference) 
* Required: yes 


 
<h2><a name="Hook.tagExpression"></a>.tagExpression</h2> 

* Type: string 
* Required: no 


 
<h2><a name="Hook.type"></a>.type</h2> 

* Type: [HookType](#hooktype) 
* Required: no 



## Location

Points to a line and a column in a text file
 
<h2><a name="Location.line"></a>.line</h2> 

* Type: integer 
* Required: yes 


 
<h2><a name="Location.column"></a>.column</h2> 

* Type: integer 
* Required: no 



## Meta

This message contains meta information about the environment. Consumers can use
this for various purposes.
 
<h2><a name="Meta.protocolVersion"></a>.protocolVersion</h2> 

* Type: string 
* Required: yes 

The [SEMVER](https://semver.org/) version number of the protocol
 
<h2><a name="Meta.implementation"></a>.implementation</h2> 

* Type: [Product](#product) 
* Required: yes 

SpecFlow, Cucumber-JVM, Cucumber.js, Cucumber-Ruby, Behat etc.
 
<h2><a name="Meta.runtime"></a>.runtime</h2> 

* Type: [Product](#product) 
* Required: yes 

Java, Ruby, Node.js etc
 
<h2><a name="Meta.os"></a>.os</h2> 

* Type: [Product](#product) 
* Required: yes 

Windows, Linux, MacOS etc
 
<h2><a name="Meta.cpu"></a>.cpu</h2> 

* Type: [Product](#product) 
* Required: yes 

386, arm, amd64 etc
 
<h2><a name="Meta.ci"></a>.ci</h2> 

* Type: [Ci](#ci) 
* Required: no 



## Ci

CI environment
 
<h2><a name="Ci.name"></a>.name</h2> 

* Type: string 
* Required: yes 

Name of the CI product, e.g. "Jenkins", "CircleCI" etc.
 
<h2><a name="Ci.url"></a>.url</h2> 

* Type: string 
* Required: no 

Link to the build
 
<h2><a name="Ci.buildNumber"></a>.buildNumber</h2> 

* Type: string 
* Required: no 

The build number. Some CI servers use non-numeric build numbers, which is why this is a string
 
<h2><a name="Ci.git"></a>.git</h2> 

* Type: [Git](#git) 
* Required: no 



## Git

Information about Git, provided by the Build/CI server as environment
variables.
 
<h2><a name="Git.remote"></a>.remote</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Git.revision"></a>.revision</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="Git.branch"></a>.branch</h2> 

* Type: string 
* Required: no 


 
<h2><a name="Git.tag"></a>.tag</h2> 

* Type: string 
* Required: no 



## Product

Used to describe various properties of Meta
 
<h2><a name="Product.name"></a>.name</h2> 

* Type: string 
* Required: yes 

The product name
 
<h2><a name="Product.version"></a>.version</h2> 

* Type: string 
* Required: no 

The product version

## ParameterType


 
<h2><a name="ParameterType.name"></a>.name</h2> 

* Type: string 
* Required: yes 

The name is unique, so we don't need an id.
 
<h2><a name="ParameterType.regularExpressions"></a>.regularExpressions</h2> 

* Type: string[] 
* Required: yes 


 
<h2><a name="ParameterType.preferForRegularExpressionMatch"></a>.preferForRegularExpressionMatch</h2> 

* Type: boolean 
* Required: yes 


 
<h2><a name="ParameterType.useForSnippets"></a>.useForSnippets</h2> 

* Type: boolean 
* Required: yes 


 
<h2><a name="ParameterType.id"></a>.id</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="ParameterType.sourceReference"></a>.sourceReference</h2> 

* Type: [SourceReference](#sourcereference) 
* Required: no 



## ParseError


 
<h2><a name="ParseError.source"></a>.source</h2> 

* Type: [SourceReference](#sourcereference) 
* Required: yes 


 
<h2><a name="ParseError.message"></a>.message</h2> 

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
 
<h2><a name="Pickle.id"></a>.id</h2> 

* Type: string 
* Required: yes 

A unique id for the pickle
 
<h2><a name="Pickle.uri"></a>.uri</h2> 

* Type: string 
* Required: yes 

The uri of the source file
 
<h2><a name="Pickle.name"></a>.name</h2> 

* Type: string 
* Required: yes 

The name of the pickle
 
<h2><a name="Pickle.language"></a>.language</h2> 

* Type: string 
* Required: yes 

The language of the pickle
 
<h2><a name="Pickle.steps"></a>.steps</h2> 

* Type: [PickleStep](#picklestep)[] 
* Required: yes 

One or more steps
 
<h2><a name="Pickle.tags"></a>.tags</h2> 

* Type: [PickleTag](#pickletag)[] 
* Required: yes 

One or more tags. If this pickle is constructed from a Gherkin document,
It includes inherited tags from the `Feature` as well.
 
<h2><a name="Pickle.astNodeIds"></a>.astNodeIds</h2> 

* Type: string[] 
* Required: yes 

Points to the AST node locations of the pickle. The last one represents the unique
id of the pickle. A pickle constructed from `Examples` will have the first
id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.

## PickleDocString


 
<h2><a name="PickleDocString.mediaType"></a>.mediaType</h2> 

* Type: string 
* Required: no 


 
<h2><a name="PickleDocString.content"></a>.content</h2> 

* Type: string 
* Required: yes 



## PickleStep

An executable step
 
<h2><a name="PickleStep.argument"></a>.argument</h2> 

* Type: [PickleStepArgument](#picklestepargument) 
* Required: no 


 
<h2><a name="PickleStep.astNodeIds"></a>.astNodeIds</h2> 

* Type: string[] 
* Required: yes 

References the IDs of the source of the step. For Gherkin, this can be
the ID of a Step, and possibly also the ID of a TableRow
 
<h2><a name="PickleStep.id"></a>.id</h2> 

* Type: string 
* Required: yes 

A unique ID for the PickleStep
 
<h2><a name="PickleStep.type"></a>.type</h2> 

* Type: [PickleStepType](#picklesteptype) 
* Required: no 

The context in which the step was specified: context (Given), action (When) or outcome (Then).

Note that the keywords `But` and `And` inherit their meaning from prior steps and the `*` 'keyword' doesn't have specific meaning (hence Unknown)
 
<h2><a name="PickleStep.text"></a>.text</h2> 

* Type: string 
* Required: yes 



## PickleStepArgument

An optional argument
 
<h2><a name="PickleStepArgument.docString"></a>.docString</h2> 

* Type: [PickleDocString](#pickledocstring) 
* Required: no 


 
<h2><a name="PickleStepArgument.dataTable"></a>.dataTable</h2> 

* Type: [PickleTable](#pickletable) 
* Required: no 



## PickleTable


 
<h2><a name="PickleTable.rows"></a>.rows</h2> 

* Type: [PickleTableRow](#pickletablerow)[] 
* Required: yes 



## PickleTableCell


 
<h2><a name="PickleTableCell.value"></a>.value</h2> 

* Type: string 
* Required: yes 



## PickleTableRow


 
<h2><a name="PickleTableRow.cells"></a>.cells</h2> 

* Type: [PickleTableCell](#pickletablecell)[] 
* Required: yes 



## PickleTag

A tag
 
<h2><a name="PickleTag.name"></a>.name</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="PickleTag.astNodeId"></a>.astNodeId</h2> 

* Type: string 
* Required: yes 

Points to the AST node this was created from

## Source

A source file, typically a Gherkin document or Java/Ruby/JavaScript source code
 
<h2><a name="Source.uri"></a>.uri</h2> 

* Type: string 
* Required: yes 

The [URI](https://en.wikipedia.org/wiki/Uniform_Resource_Identifier)
of the source, typically a file path relative to the root directory
 
<h2><a name="Source.data"></a>.data</h2> 

* Type: string 
* Required: yes 

The contents of the file
 
<h2><a name="Source.mediaType"></a>.mediaType</h2> 

* Type: [SourceMediaType](#sourcemediatype) 
* Required: yes 

The media type of the file. Can be used to specify custom types, such as
text/x.cucumber.gherkin+plain

## SourceReference

Points to a [Source](#io.cucumber.messages.Source) identified by `uri` and a
[Location](#io.cucumber.messages.Location) within that file.
 
<h2><a name="SourceReference.uri"></a>.uri</h2> 

* Type: string 
* Required: no 


 
<h2><a name="SourceReference.javaMethod"></a>.javaMethod</h2> 

* Type: [JavaMethod](#javamethod) 
* Required: no 


 
<h2><a name="SourceReference.javaStackTraceElement"></a>.javaStackTraceElement</h2> 

* Type: [JavaStackTraceElement](#javastacktraceelement) 
* Required: no 


 
<h2><a name="SourceReference.location"></a>.location</h2> 

* Type: [Location](#location) 
* Required: no 



## JavaMethod


 
<h2><a name="JavaMethod.className"></a>.className</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="JavaMethod.methodName"></a>.methodName</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="JavaMethod.methodParameterTypes"></a>.methodParameterTypes</h2> 

* Type: string[] 
* Required: yes 



## JavaStackTraceElement


 
<h2><a name="JavaStackTraceElement.className"></a>.className</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="JavaStackTraceElement.fileName"></a>.fileName</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="JavaStackTraceElement.methodName"></a>.methodName</h2> 

* Type: string 
* Required: yes 



## StepDefinition


 
<h2><a name="StepDefinition.id"></a>.id</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="StepDefinition.pattern"></a>.pattern</h2> 

* Type: [StepDefinitionPattern](#stepdefinitionpattern) 
* Required: yes 


 
<h2><a name="StepDefinition.sourceReference"></a>.sourceReference</h2> 

* Type: [SourceReference](#sourcereference) 
* Required: yes 



## StepDefinitionPattern


 
<h2><a name="StepDefinitionPattern.source"></a>.source</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="StepDefinitionPattern.type"></a>.type</h2> 

* Type: [StepDefinitionPatternType](#stepdefinitionpatterntype) 
* Required: yes 



## TestCase

A `TestCase` contains a sequence of `TestStep`s.
 
<h2><a name="TestCase.id"></a>.id</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="TestCase.pickleId"></a>.pickleId</h2> 

* Type: string 
* Required: yes 

The ID of the `Pickle` this `TestCase` is derived from.
 
<h2><a name="TestCase.testSteps"></a>.testSteps</h2> 

* Type: [TestStep](#teststep)[] 
* Required: yes 


 
<h2><a name="TestCase.testRunStartedId"></a>.testRunStartedId</h2> 

* Type: string 
* Required: no 

Identifier for the test run that this test case belongs to

## Group


 
<h2><a name="Group.children"></a>.children</h2> 

* Type: [Group](#group)[] 
* Required: yes 


 
<h2><a name="Group.start"></a>.start</h2> 

* Type: integer 
* Required: no 


 
<h2><a name="Group.value"></a>.value</h2> 

* Type: string 
* Required: no 



## StepMatchArgument

Represents a single argument extracted from a step match and passed to a step definition.
This is used for the following purposes:
- Construct an argument to pass to a step definition (possibly through a parameter type transform)
- Highlight the matched parameter in rich formatters such as the HTML formatter

This message closely matches the `Argument` class in the `cucumber-expressions` library.
 
<h2><a name="StepMatchArgument.group"></a>.group</h2> 

* Type: [Group](#group) 
* Required: yes 

Represents the outermost capture group of an argument. This message closely matches the
`Group` class in the `cucumber-expressions` library.
 
<h2><a name="StepMatchArgument.parameterTypeName"></a>.parameterTypeName</h2> 

* Type: string 
* Required: no 



## StepMatchArgumentsList


 
<h2><a name="StepMatchArgumentsList.stepMatchArguments"></a>.stepMatchArguments</h2> 

* Type: [StepMatchArgument](#stepmatchargument)[] 
* Required: yes 



## TestStep

A `TestStep` is derived from either a `PickleStep`
combined with a `StepDefinition`, or from a `Hook`.
 
<h2><a name="TestStep.hookId"></a>.hookId</h2> 

* Type: string 
* Required: no 

Pointer to the `Hook` (if derived from a Hook)
 
<h2><a name="TestStep.id"></a>.id</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="TestStep.pickleStepId"></a>.pickleStepId</h2> 

* Type: string 
* Required: no 

Pointer to the `PickleStep` (if derived from a `PickleStep`)
 
<h2><a name="TestStep.stepDefinitionIds"></a>.stepDefinitionIds</h2> 

* Type: string[] 
* Required: no 

Pointer to all the matching `StepDefinition`s (if derived from a `PickleStep`)
Each element represents a matching step definition. A size of 0 means `UNDEFINED`,
and a size of 2+ means `AMBIGUOUS`
 
<h2><a name="TestStep.stepMatchArgumentsLists"></a>.stepMatchArgumentsLists</h2> 

* Type: [StepMatchArgumentsList](#stepmatchargumentslist)[] 
* Required: no 

A list of list of StepMatchArgument (if derived from a `PickleStep`).

## TestCaseFinished


 
<h2><a name="TestCaseFinished.testCaseStartedId"></a>.testCaseStartedId</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="TestCaseFinished.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: yes 


 
<h2><a name="TestCaseFinished.willBeRetried"></a>.willBeRetried</h2> 

* Type: boolean 
* Required: yes 



## TestCaseStarted


 
<h2><a name="TestCaseStarted.attempt"></a>.attempt</h2> 

* Type: integer 
* Required: yes 

The first attempt should have value 0, and for each retry the value
should increase by 1.
 
<h2><a name="TestCaseStarted.id"></a>.id</h2> 

* Type: string 
* Required: yes 

Because a `TestCase` can be run multiple times (in case of a retry),
we use this field to group messages relating to the same attempt.
 
<h2><a name="TestCaseStarted.testCaseId"></a>.testCaseId</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="TestCaseStarted.workerId"></a>.workerId</h2> 

* Type: string 
* Required: no 

An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.
 
<h2><a name="TestCaseStarted.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunFinished


 
<h2><a name="TestRunFinished.message"></a>.message</h2> 

* Type: string 
* Required: no 

An informative message about the test run. Typically additional information about failure, but not necessarily.
 
<h2><a name="TestRunFinished.success"></a>.success</h2> 

* Type: boolean 
* Required: yes 

A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.
 
<h2><a name="TestRunFinished.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: yes 

Timestamp when the TestRun is finished
 
<h2><a name="TestRunFinished.exception"></a>.exception</h2> 

* Type: [Exception](#exception) 
* Required: no 

Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.
 
<h2><a name="TestRunFinished.testRunStartedId"></a>.testRunStartedId</h2> 

* Type: string 
* Required: no 



## TestRunHookFinished


 
<h2><a name="TestRunHookFinished.testRunHookStartedId"></a>.testRunHookStartedId</h2> 

* Type: string 
* Required: yes 

Identifier for the hook execution that has finished
 
<h2><a name="TestRunHookFinished.result"></a>.result</h2> 

* Type: [TestStepResult](#teststepresult) 
* Required: yes 


 
<h2><a name="TestRunHookFinished.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunHookStarted


 
<h2><a name="TestRunHookStarted.id"></a>.id</h2> 

* Type: string 
* Required: yes 

Unique identifier for this hook execution
 
<h2><a name="TestRunHookStarted.testRunStartedId"></a>.testRunStartedId</h2> 

* Type: string 
* Required: yes 

Identifier for the test run that this hook execution belongs to
 
<h2><a name="TestRunHookStarted.hookId"></a>.hookId</h2> 

* Type: string 
* Required: yes 

Identifier for the hook that will be executed
 
<h2><a name="TestRunHookStarted.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestRunStarted


 
<h2><a name="TestRunStarted.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: yes 


 
<h2><a name="TestRunStarted.id"></a>.id</h2> 

* Type: string 
* Required: no 



## TestStepFinished


 
<h2><a name="TestStepFinished.testCaseStartedId"></a>.testCaseStartedId</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="TestStepFinished.testStepId"></a>.testStepId</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="TestStepFinished.testStepResult"></a>.testStepResult</h2> 

* Type: [TestStepResult](#teststepresult) 
* Required: yes 


 
<h2><a name="TestStepFinished.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## TestStepResult


 
<h2><a name="TestStepResult.duration"></a>.duration</h2> 

* Type: [Duration](#duration) 
* Required: yes 


 
<h2><a name="TestStepResult.message"></a>.message</h2> 

* Type: string 
* Required: no 

An arbitrary bit of information that explains this result. If there was an exception, this should include a stringified representation of it including type, message and stack trace (the exact format will vary by platform).
 
<h2><a name="TestStepResult.status"></a>.status</h2> 

* Type: [TestStepResultStatus](#teststepresultstatus) 
* Required: yes 


 
<h2><a name="TestStepResult.exception"></a>.exception</h2> 

* Type: [Exception](#exception) 
* Required: no 

Exception thrown while executing this step, if any.

## TestStepStarted


 
<h2><a name="TestStepStarted.testCaseStartedId"></a>.testCaseStartedId</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="TestStepStarted.testStepId"></a>.testStepId</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="TestStepStarted.timestamp"></a>.timestamp</h2> 

* Type: [Timestamp](#timestamp) 
* Required: yes 



## Timestamp


 
<h2><a name="Timestamp.seconds"></a>.seconds</h2> 

* Type: integer 
* Required: yes 

Represents seconds of UTC time since Unix epoch
1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
9999-12-31T23:59:59Z inclusive.
 
<h2><a name="Timestamp.nanos"></a>.nanos</h2> 

* Type: integer 
* Required: yes 

Non-negative fractions of a second at nanosecond resolution. Negative
second values with fractions must still have non-negative nanos values
that count forward in time. Must be from 0 to 999,999,999
inclusive.

## UndefinedParameterType


 
<h2><a name="UndefinedParameterType.expression"></a>.expression</h2> 

* Type: string 
* Required: yes 


 
<h2><a name="UndefinedParameterType.name"></a>.name</h2> 

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


