# Cucumber Messages  

All relationships where an entity is referenced by `id`.

Notes:
 * The left side cardinality of the relationship is always rendered as one-or-more, but may also be exactly-one. This can't be extracted from the json schema easily.
 * Worker is not actually an entity in the message protocol, but is referenced by id.
 * `AstNode` is not actually an entity in the message protocol, but does reference an element in the `GherkinDocument`. 

```mermaid
---
title: Entity relationships  - by id
config:
    layout: elk
---
erDiagram
Attachment }|..o| TestCaseStarted: testCaseStartedId
Attachment }|..o| TestStep: testStepId
Attachment }|..o| TestRunStarted: testRunStartedId
Attachment }|..o| TestRunHookStarted: testRunHookStartedId
Pickle }|..|{ AstNode: astNodeIds
PickleStep }|..|{ AstNode: astNodeIds
PickleTag }|..|| AstNode: astNodeId
TestCase }|..|| Pickle: pickleId
TestCase }|..o| TestRunStarted: testRunStartedId
TestStep }|..o| Hook: hookId
TestStep }|..o| PickleStep: pickleStepId
TestStep }|..o{ StepDefinition: stepDefinitionIds
TestCaseFinished }|..|| TestCaseStarted: testCaseStartedId
TestCaseStarted }|..|| TestCase: testCaseId
TestCaseStarted }|..o| Worker: workerId
TestRunFinished }|..o| TestRunStarted: testRunStartedId
TestRunHookFinished }|..|| TestRunHookStarted: testRunHookStartedId
TestRunHookStarted }|..|| TestRunStarted: testRunStartedId
TestRunHookStarted }|..|| Hook: hookId
TestRunHookStarted }|..o| Worker: workerId
TestStepFinished }|..|| TestCaseStarted: testCaseStartedId
TestStepFinished }|..|| TestStep: testStepId
TestStepStarted }|..|| TestCaseStarted: testCaseStartedId
TestStepStarted }|..|| TestStep: testStepId
```

And all has-a relationships, excluding `Envelope`:

```mermaid
---
title: Entity relationships - has a  
config:
    layout: elk
---
erDiagram
Attachment ||..o| Source: "has a"
Attachment ||..o| Timestamp: "has a"
GherkinDocument ||..o| Feature: "has a"
GherkinDocument ||..|{ Comment: "has"
Background ||..|| Location: "has a"
Background ||..|{ Step: "has"
Comment ||..|| Location: "has a"
DataTable ||..|| Location: "has a"
DataTable ||..|{ TableRow: "has"
DocString ||..|| Location: "has a"
Examples ||..|| Location: "has a"
Examples ||..|{ Tag: "has"
Examples ||..o| TableRow: "has a"
Examples ||..|{ TableRow: "has"
Feature ||..|| Location: "has a"
Feature ||..|{ Tag: "has"
Feature ||..|{ FeatureChild: "has"
FeatureChild ||..o| Rule: "has a"
FeatureChild ||..o| Background: "has a"
FeatureChild ||..o| Scenario: "has a"
Rule ||..|| Location: "has a"
Rule ||..|{ Tag: "has"
Rule ||..|{ RuleChild: "has"
RuleChild ||..o| Background: "has a"
RuleChild ||..o| Scenario: "has a"
Scenario ||..|| Location: "has a"
Scenario ||..|{ Tag: "has"
Scenario ||..|{ Step: "has"
Scenario ||..|{ Examples: "has"
Step ||..|| Location: "has a"
Step ||..o| DocString: "has a"
Step ||..o| DataTable: "has a"
TableCell ||..|| Location: "has a"
TableRow ||..|| Location: "has a"
TableRow ||..|{ TableCell: "has"
Tag ||..|| Location: "has a"
Hook ||..|| SourceReference: "has a"
Meta ||..|| Product: "has a"
Meta ||..|| Product: "has a"
Meta ||..|| Product: "has a"
Meta ||..|| Product: "has a"
Meta ||..o| Ci: "has a"
Ci ||..o| Git: "has a"
ParameterType ||..o| SourceReference: "has a"
ParseError ||..|| SourceReference: "has a"
Pickle ||..|{ PickleStep: "has"
Pickle ||..|{ PickleTag: "has"
PickleStep ||..o| PickleStepArgument: "has a"
PickleStepArgument ||..o| PickleDocString: "has a"
PickleStepArgument ||..o| PickleTable: "has a"
PickleTable ||..|{ PickleTableRow: "has"
PickleTableRow ||..|{ PickleTableCell: "has"
SourceReference ||..o| JavaMethod: "has a"
SourceReference ||..o| JavaStackTraceElement: "has a"
SourceReference ||..o| Location: "has a"
StepDefinition ||..|| StepDefinitionPattern: "has a"
StepDefinition ||..|| SourceReference: "has a"
TestCase ||..|{ TestStep: "has"
Group ||..|{ Group: "has"
StepMatchArgument ||..|| Group: "has a"
StepMatchArgumentsList ||..|{ StepMatchArgument: "has"
TestStep ||..o{ StepMatchArgumentsList: "has"
TestCaseFinished ||..|| Timestamp: "has a"
TestCaseStarted ||..|| Timestamp: "has a"
TestRunFinished ||..|| Timestamp: "has a"
TestRunFinished ||..o| Exception: "has a"
TestRunHookFinished ||..|| TestStepResult: "has a"
TestRunHookFinished ||..|| Timestamp: "has a"
TestRunHookStarted ||..|| Timestamp: "has a"
TestRunStarted ||..|| Timestamp: "has a"
TestStepFinished ||..|| TestStepResult: "has a"
TestStepFinished ||..|| Timestamp: "has a"
TestStepResult ||..|| Duration: "has a"
TestStepResult ||..o| Exception: "has a"
TestStepStarted ||..|| Timestamp: "has a"
```
