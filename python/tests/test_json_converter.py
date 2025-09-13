import sys
from collections.abc import Sequence
from dataclasses import dataclass
from datetime import date, datetime
from enum import Enum
from typing import Optional

import pytest

from cucumber_messages.json_converter import (
    JsonDataclassConverter,
    camel_to_snake,
    snake_to_camel,
)


class SimpleEnum(Enum):
    VALUE1 = "value1"
    VALUE2 = "value2"


@dataclass
class SimpleModel:
    string_field: str
    int_field: int
    float_field: float
    bool_field: bool
    enum_field: SimpleEnum
    optional_field: Optional[str] = None


@dataclass
class NestedModel:
    name: str
    simple: SimpleModel
    optional_simple: Optional["SimpleModel"] = None


@dataclass
class CollectionsModel:
    sequence_field: Sequence[str]
    list_field: list[SimpleModel]
    dict_field: dict[str, SimpleModel]
    optional_sequence: Optional[Sequence["str"]] = None


@dataclass
class DateTimeModel:
    datetime_field: datetime
    date_field: date
    optional_datetime: Optional["datetime"] = None


@pytest.fixture
def serializer():
    return JsonDataclassConverter(module_scope=sys.modules[__name__])


def test_optional_field_types(serializer):
    # Testing deserialization with non-quoted and quoted types
    data = {
        "name": "test",
        "simple": {
            "stringField": "nested",
            "intField": 42,
            "floatField": 3.14,
            "boolField": True,
            "enumField": "value1",
        },
        "optionalSimple": {
            "stringField": "optional",
            "intField": 99,
            "floatField": 2.71,
            "boolField": False,
            "enumField": "value2",
        },
    }

    model = serializer.from_dict(data, NestedModel)

    # Verify main fields
    assert model.name == "test"
    assert model.simple.string_field == "nested"
    assert model.simple.int_field == 42

    # Verify optional fields are correctly deserialized
    assert model.optional_simple is not None
    assert model.optional_simple.string_field == "optional"
    assert model.optional_simple.int_field == 99

    # Verify types explicitly
    assert isinstance(model.optional_simple, SimpleModel)
    assert isinstance(model.optional_simple.string_field, str)
    assert isinstance(model.optional_simple.int_field, int)
    assert isinstance(model.optional_simple.float_field, float)
    assert isinstance(model.optional_simple.bool_field, bool)
    assert isinstance(model.optional_simple.enum_field, SimpleEnum)


def test_collections_with_optional_field_types(serializer):
    data = {
        "sequenceField": ["a", "b", "c"],
        "listField": [
            {
                "stringField": "item",
                "intField": 42,
                "floatField": 3.14,
                "boolField": True,
                "enumField": "value1",
            }
        ],
        "dictField": {
            "key": {
                "stringField": "dict_item",
                "intField": 84,
                "floatField": 6.28,
                "boolField": False,
                "enumField": "value2",
            }
        },
        "optionalSequence": ["x", "y", "z"],
    }

    model = serializer.from_dict(data, CollectionsModel)

    # Verify main fields
    assert list(model.sequence_field) == ["a", "b", "c"]
    assert len(model.list_field) == 1
    assert model.list_field[0].string_field == "item"
    assert model.dict_field["key"].string_field == "dict_item"

    # Verify optional fields
    assert model.optional_sequence is not None
    assert list(model.optional_sequence) == ["x", "y", "z"]

    # Verify types explicitly
    assert isinstance(model.optional_sequence, Sequence)
    assert all(isinstance(item, str) for item in model.optional_sequence)
    assert isinstance(model.list_field[0], SimpleModel)
    assert isinstance(model.dict_field["key"], SimpleModel)


def test_datetime_with_optional_field_types(serializer):
    data = {
        "datetimeField": "2024-01-01T12:00:00",
        "dateField": "2024-01-01",
        "optionalDatetime": "2024-01-01T13:00:00",
    }

    model = serializer.from_dict(data, DateTimeModel)

    # Verify fields
    assert model.datetime_field == datetime(2024, 1, 1, 12, 0)
    assert model.date_field == date(2024, 1, 1)
    assert model.optional_datetime == datetime(2024, 1, 1, 13, 0)

    # Verify types explicitly
    assert isinstance(model.datetime_field, datetime)
    assert isinstance(model.date_field, date)
    assert isinstance(model.optional_datetime, datetime)


def test_optional_field_absent(serializer):
    data = {
        "name": "test",
        "simple": {
            "stringField": "nested",
            "intField": 42,
            "floatField": 3.14,
            "boolField": True,
            "enumField": "value1",
        },
    }

    model = serializer.from_dict(data, NestedModel)

    # Verify optional fields are None when absent
    assert model.optional_simple is None

    # Verify types explicitly
    assert isinstance(model.simple, SimpleModel)
    assert model.optional_simple is None


@pytest.mark.parametrize(
    "input_str, expected",
    [
        ("test", "test"),
        ("test_test", "testTest"),
        ("Test_TeSt", "TestTest"),
        ("", ""),
        ("test123test4_5_6_test", "test123test456Test"),
        ("test-test", "test-test"),
    ],
)
def test_camelize(input_str, expected):
    assert snake_to_camel(input_str) == expected


@pytest.mark.parametrize(
    "expected, input_str",
    [
        ("test", "test"),
        ("test_test", "testTest"),
        ("test_test", "TestTest"),
        ("", ""),
        ("test123test456_test", "test123test456Test"),
        ("test-test", "test-test"),
    ],
)
def test_snaking(input_str, expected):
    assert camel_to_snake(input_str) == expected
