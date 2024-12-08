from dataclasses import dataclass
from datetime import datetime, date
from enum import Enum
from typing import Optional, Sequence, List, Dict
import pytest
from cucumber_messages import JSONDataclassMixin


class TestEnum(Enum):
    VALUE1 = "value1"
    VALUE2 = "value2"


@dataclass
class SimpleModel(JSONDataclassMixin):
    string_field: str  # required
    int_field: int  # required
    float_field: float  # required
    bool_field: bool  # required
    enum_field: TestEnum  # required
    optional_field: Optional[str] = None


@dataclass
class NestedModel(JSONDataclassMixin):
    name: str
    simple: SimpleModel
    optional_simple: Optional[SimpleModel] = None


@dataclass
class CollectionsModel(JSONDataclassMixin):
    sequence_field: Sequence[str]
    list_field: List[SimpleModel]
    dict_field: Dict[str, SimpleModel]
    optional_sequence: Optional[Sequence[str]] = None


@dataclass
class DateTimeModel(JSONDataclassMixin):
    datetime_field: datetime
    date_field: date
    optional_datetime: Optional[datetime] = None


def test_simple_serialization():
    model = SimpleModel(
        string_field="test",
        int_field=42,
        float_field=3.14,
        bool_field=True,
        enum_field=TestEnum.VALUE1
    )

    dict_data = model.to_dict()
    assert dict_data["stringField"] == "test"
    assert dict_data["intField"] == 42
    assert dict_data["floatField"] == 3.14
    assert dict_data["boolField"] is True
    assert dict_data["enumField"] == "value1"
    assert "optionalField" not in dict_data

    json_data = model.to_json()
    # Parse JSON to compare values instead of exact string matching
    import json
    json_dict = json.loads(json_data)
    assert json_dict["stringField"] == "test"
    assert json_dict["intField"] == 42
    assert json_dict["floatField"] == 3.14
    assert json_dict["boolField"] is True
    assert json_dict["enumField"] == "value1"


def test_simple_deserialization():
    data = {
        "stringField": "test",
        "intField": 42,
        "floatField": 3.14,
        "boolField": True,
        "enumField": "value1",
        "optionalField": "optional"
    }

    model = SimpleModel.from_dict(data)
    assert model.string_field == "test"
    assert model.int_field == 42
    assert model.float_field == 3.14
    assert model.bool_field is True
    assert model.enum_field == TestEnum.VALUE1
    assert model.optional_field == "optional"


def test_nested_serialization():
    simple = SimpleModel(
        string_field="nested",
        int_field=42,
        float_field=3.14,
        bool_field=True,
        enum_field=TestEnum.VALUE1
    )
    model = NestedModel(name="test", simple=simple)

    dict_data = model.to_dict()
    assert dict_data["name"] == "test"
    assert dict_data["simple"]["stringField"] == "nested"
    assert "optionalSimple" not in dict_data


def test_nested_deserialization():
    data = {
        "name": "test",
        "simple": {
            "stringField": "nested",
            "intField": 42,
            "floatField": 3.14,
            "boolField": True,
            "enumField": "value1"
        }
    }

    model = NestedModel.from_dict(data)
    assert model.name == "test"
    assert model.simple.string_field == "nested"
    assert model.simple.int_field == 42
    assert model.optional_simple is None


def test_collections_serialization():
    simple = SimpleModel(
        string_field="item",
        int_field=42,
        float_field=3.14,
        bool_field=True,
        enum_field=TestEnum.VALUE1
    )

    model = CollectionsModel(
        sequence_field=["a", "b", "c"],
        list_field=[simple],
        dict_field={"key": simple}
    )

    dict_data = model.to_dict()
    assert dict_data["sequenceField"] == ["a", "b", "c"]
    assert len(dict_data["listField"]) == 1
    assert dict_data["listField"][0]["stringField"] == "item"
    assert dict_data["dictField"]["key"]["stringField"] == "item"


def test_collections_deserialization():
    data = {
        "sequenceField": ["a", "b", "c"],
        "listField": [{
            "stringField": "item",
            "intField": 42,
            "floatField": 3.14,
            "boolField": True,
            "enumField": "value1"
        }],
        "dictField": {
            "key": {
                "stringField": "item",
                "intField": 42,
                "floatField": 3.14,
                "boolField": True,
                "enumField": "value1"
            }
        }
    }

    model = CollectionsModel.from_dict(data)
    assert list(model.sequence_field) == ["a", "b", "c"]
    assert len(model.list_field) == 1
    assert model.list_field[0].string_field == "item"
    assert model.dict_field["key"].string_field == "item"


def test_datetime_serialization():
    dt = datetime(2024, 1, 1, 12, 0)
    d = date(2024, 1, 1)
    model = DateTimeModel(datetime_field=dt, date_field=d)

    dict_data = model.to_dict()
    assert dict_data["datetimeField"] == "2024-01-01T12:00:00"
    assert dict_data["dateField"] == "2024-01-01"


def test_datetime_deserialization():
    data = {
        "datetimeField": "2024-01-01T12:00:00",
        "dateField": "2024-01-01"
    }

    model = DateTimeModel.from_dict(data)
    assert model.datetime_field == datetime(2024, 1, 1, 12, 0)
    assert model.date_field == date(2024, 1, 1)


def test_json_roundtrip():
    original = SimpleModel(
        string_field="test",
        int_field=42,
        float_field=3.14,
        bool_field=True,
        enum_field=TestEnum.VALUE1,
        optional_field="optional"
    )

    json_str = original.to_json()
    restored = SimpleModel.from_json(json_str)

    assert restored == original


def test_optional_fields():
    model = SimpleModel(
        string_field="test",
        int_field=42,
        float_field=3.14,
        bool_field=True,
        enum_field=TestEnum.VALUE1
    )

    dict_data = model.to_dict()
    assert "optionalField" not in dict_data

    model = SimpleModel.from_dict(dict_data)
    assert model.optional_field is None


def test_single_item_sequence():
    data = {
        "sequenceField": "single",
        "listField": [{
            "stringField": "item",
            "intField": 42,
            "floatField": 3.14,
            "boolField": True,
            "enumField": "value1"
        }],
        "dictField": {
            "key": {
                "stringField": "item",
                "intField": 42,
                "floatField": 3.14,
                "boolField": True,
                "enumField": "value1"
            }
        }
    }

    model = CollectionsModel.from_dict(data)
    assert list(model.sequence_field) == ["single"]


def test_error_handling():
    # Test invalid input type
    with pytest.raises(TypeError, match="Expected dict but got"):
        SimpleModel.from_dict(["not", "a", "dict"])

    # Test invalid enum value
    with pytest.raises(TypeError, match="Error decoding field enumField"):
        SimpleModel.from_dict({
            "stringField": "test",
            "intField": 42,
            "floatField": 3.14,
            "boolField": True,
            "enumField": "invalid_value"
        })

    # Test missing required fields with only optional field
    with pytest.raises(TypeError, match="Missing required arguments:"):
        SimpleModel.from_dict({
            "optionalField": "only optional field provided"
        })

def test_camel_snake_case_conversion():
    data = {
        "string_field": "test",  # snake_case
        "intField": 42,  # camelCase
        "floatField": 3.14,  # camelCase
        "boolField": True,  # camelCase
        "enumField": "value1"  # camelCase
    }

    model = SimpleModel.from_dict(data)
    assert model.string_field == "test"
    assert model.int_field == 42
    assert model.float_field == 3.14
    assert model.bool_field is True
    assert model.enum_field == TestEnum.VALUE1

    dict_data = model.to_dict()
    assert all(not "_" in key for key in dict_data.keys())


def test_invalid_field_names():
    # Using completely invalid field names
    data = {
        "string.field-with.dots": "test",
        "int space @ field": 42,
        "@#invalid!": "value",
        "optionalField": "this is valid but optional"
    }

    # Should skip invalid fields and fail due to missing required fields
    with pytest.raises(TypeError,
                       match="Missing required arguments: string_field, int_field, float_field, bool_field, enum_field"):
        SimpleModel.from_dict(data)

    # Test with mix of valid and invalid fields
    data = {
        "stringField": "test",  # valid
        "int@field": 42,  # invalid
        "float field": 3.14,  # invalid
        "bool.field": True,  # invalid
        "@enum": "value1"  # invalid
    }

    # Should still fail due to missing required fields
    with pytest.raises(TypeError, match="Missing required arguments: int_field, float_field, bool_field, enum_field"):
        SimpleModel.from_dict(data)