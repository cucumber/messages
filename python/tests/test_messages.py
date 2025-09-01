import pytest

from cucumber_messages import (
    Attachment,
    AttachmentContentEncoding,
    Envelope,
    SourceMediaType,
)
from cucumber_messages import TestStepResultStatus as TTestStepResultStatus
from cucumber_messages import message_converter as default_converter


@pytest.fixture
def converter():
    return default_converter


def test_basic_attachment_serialization(converter):
    data = {
        "body": "some body",
        "contentEncoding": "IDENTITY",
        "mediaType": "text/plain",
        "fileName": "myfile.txt",
    }

    attachment = converter.from_dict(data, Attachment)
    assert attachment.body == "some body"
    assert attachment.content_encoding == AttachmentContentEncoding.identity
    assert attachment.media_type == "text/plain"
    assert attachment.file_name == "myfile.txt"

    # Round-trip serialization
    serialized = converter.to_dict(attachment)
    assert serialized == data


def test_envelope_with_attachment(converter):
    data = {
        "attachment": {
            "body": "some body",
            "contentEncoding": "BASE64",
            "mediaType": "text/x.cucumber.gherkin+plain",
        }
    }

    envelope = converter.from_dict(data, Envelope)
    assert envelope.attachment is not None
    assert envelope.attachment.body == "some body"
    assert envelope.attachment.content_encoding == AttachmentContentEncoding.base64
    assert envelope.attachment.media_type == "text/x.cucumber.gherkin+plain"

    # Round-trip serialization
    serialized = converter.to_dict(envelope)
    assert serialized == data


def test_envelope_with_source(converter):
    data = {
        "source": {
            "data": "Feature: Sample\nScenario: Test\n",
            "mediaType": "text/x.cucumber.gherkin+plain",
            "uri": "features/sample.feature",
        }
    }

    envelope = converter.from_dict(data, Envelope)
    assert envelope.source is not None
    assert envelope.source.data == "Feature: Sample\nScenario: Test\n"
    assert envelope.source.media_type == SourceMediaType.text_x_cucumber_gherkin_plain
    assert envelope.source.uri == "features/sample.feature"

    serialized = converter.to_dict(envelope)
    assert serialized == data


def test_test_run_finished_with_optional_fields(converter):
    data = {
        "testRunFinished": {
            "success": True,
            "timestamp": {"seconds": 1700000000, "nanos": 123456789},
            # exception and message are omitted, should be None after deserialization
        }
    }

    envelope = converter.from_dict(data, Envelope)
    assert envelope.test_run_finished is not None
    assert envelope.test_run_finished.success is True
    assert envelope.test_run_finished.timestamp.seconds == 1700000000
    assert envelope.test_run_finished.timestamp.nanos == 123456789
    assert envelope.test_run_finished.exception is None
    assert envelope.test_run_finished.message is None

    # Round-trip serialization
    serialized = converter.to_dict(envelope)
    assert serialized == data


def test_test_case_finished(converter):
    data = {
        "testCaseFinished": {
            "testCaseStartedId": "some_test_case_started_id",
            "timestamp": {"seconds": 1600000000, "nanos": 500},
            "willBeRetried": False,
        }
    }

    envelope = converter.from_dict(data, Envelope)
    assert envelope.test_case_finished is not None
    assert envelope.test_case_finished.test_case_started_id == "some_test_case_started_id"
    assert envelope.test_case_finished.timestamp.seconds == 1600000000
    assert envelope.test_case_finished.timestamp.nanos == 500
    assert envelope.test_case_finished.will_be_retried is False

    serialized = converter.to_dict(envelope)
    assert serialized == data


def test_exception_serialization(converter):
    data = {
        "testRunFinished": {
            "success": False,
            "timestamp": {"seconds": 1700000001, "nanos": 1000},
            "exception": {
                "type": "AssertionError",
                "message": "Expected 'X' but got 'Y'",
                "stackTrace": "Traceback (most recent call last): ...",
            },
        }
    }

    envelope = converter.from_dict(data, Envelope)
    assert envelope.test_run_finished is not None
    exc = envelope.test_run_finished.exception
    assert exc is not None
    assert exc.type == "AssertionError"
    assert exc.message == "Expected 'X' but got 'Y'"
    assert exc.stack_trace.startswith("Traceback (most recent call last)")

    serialized = converter.to_dict(envelope)
    assert serialized == data


def test_test_step_result(converter):
    data = {
        "testStepFinished": {
            "testCaseStartedId": "tcs_id_123",
            "testStepId": "ts_id_456",
            "testStepResult": {
                "duration": {"seconds": 3, "nanos": 500000000},
                "status": "PASSED",
                "message": "Step executed successfully",
            },
            "timestamp": {"seconds": 1700000020, "nanos": 0},
        }
    }

    envelope = converter.from_dict(data, Envelope)
    assert envelope.test_step_finished is not None
    result = envelope.test_step_finished.test_step_result
    assert result.status == TTestStepResultStatus.passed
    assert result.duration.seconds == 3
    assert result.duration.nanos == 500000000
    assert result.message == "Step executed successfully"

    serialized = converter.to_dict(envelope)
    assert serialized == data


def test_missing_optional_fields(converter):
    # No optional fields set, serializer should handle defaults
    data = {
        "attachment": {
            "body": "no optional fields",
            "contentEncoding": "IDENTITY",
            "mediaType": "text/plain",
        }
    }

    envelope = converter.from_dict(data, Envelope)
    assert envelope.attachment is not None
    assert envelope.attachment.file_name is None
    assert envelope.attachment.source is None
    assert envelope.attachment.url is None

    serialized = converter.to_dict(envelope)
    assert serialized == data
