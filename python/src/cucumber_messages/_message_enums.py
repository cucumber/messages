# This code was generated using the code generator from cucumber-messages.
# Manual changes will be lost if the code is regenerated.
# Generator: cucumber-messages-python

from enum import Enum


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
