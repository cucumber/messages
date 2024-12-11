import json
import re
import sys
import types
import typing
from dataclasses import MISSING, Field, fields, is_dataclass
from datetime import date, datetime
from enum import Enum
from typing import (
    Any,
    ClassVar,
    Dict,
    List,
    Optional,
    Protocol,
    Sequence,
    Tuple,
    Type,
    TypeVar,
    Union,
    cast,
    get_args,
    get_origin,
)


class DataclassProtocol(Protocol):
    """Protocol defining the structure required for dataclass instances."""

    __dataclass_fields__: ClassVar[Dict[str, Field[Any]]]


def camel_to_snake(name: str) -> str:
    """Convert string from camelCase to snake_case."""
    if not name or not (name[0].isalpha() or name[0] == "_") or not all(c.isalnum() or c == "_" for c in name):
        raise ValueError(f"Invalid field name: {name}")
    pattern = re.compile(r"(?<!^)(?=[A-Z])")
    return pattern.sub("_", name).lower()


def snake_to_camel(name: str) -> str:
    """Convert string from snake_case to camelCase."""
    if not name or not (name[0].isalpha() or name[0] == "_") or not all(c.isalnum() or c == "_" for c in name):
        raise ValueError(f"Invalid field name: {name}")
    components = name.split("_")
    return components[0] + "".join(x.title() for x in components[1:])


class TypeResolver:
    """Resolves type annotations to their actual types."""

    def __init__(self, module_scope: types.ModuleType) -> None:
        self.module_scope = module_scope
        self._type_cache: Dict[str, Any] = {}

    def _get_sequence_type(self, type_str: str) -> Optional[Tuple[Any, str]]:
        sequence_match = re.match(r"Sequence\[(.*)\]", type_str)
        list_legacy_match = re.match(r"List\[(.*)\]", type_str)
        list_match = re.match(r"list\[(.*)\]", type_str)
        if sequence_match:
            return (Sequence, sequence_match.group(1))
        if list_legacy_match:
            return (List, list_legacy_match.group(1))
        if list_match:
            return (list, list_match.group(1))
        return None

    def resolve_type(self, type_hint: Any) -> Any:
        """Resolve a type hint to its concrete type."""
        if isinstance(type_hint, type):
            return type_hint

        if not isinstance(type_hint, str):
            return type_hint

        if type_hint == "Any":
            return Any

        if type_hint == "None":
            return type(None)

        if type_hint in self._type_cache:
            return self._type_cache[type_hint]

        if "|" in type_hint:
            types_str = [t.strip() for t in type_hint.split("|")]
            resolved_types = []
            for t in types_str:
                if t == "None":
                    resolved_types.append(type(None))
                else:
                    resolved = self.resolve_type(t)
                    if resolved is not None:
                        resolved_types.append(resolved)
            if resolved_types:
                return cast(Any, Union[tuple(resolved_types)])
            return Any

        sequence_info = self._get_sequence_type(type_hint)
        if sequence_info:
            base_type, inner_type = sequence_info
            resolved_inner = self.resolve_type(inner_type.strip())
            if resolved_inner is not None:
                result = base_type[resolved_inner]  # type: ignore
                self._type_cache[type_hint] = result
                return result
            return List[Any]

        if hasattr(self.module_scope, type_hint):
            resolved = getattr(self.module_scope, type_hint)
            if isinstance(resolved, type):
                self._type_cache[type_hint] = resolved
                return resolved

        try:
            resolved = eval(type_hint, self.module_scope.__dict__)  # noqa: PGH001
            if isinstance(resolved, type):
                self._type_cache[type_hint] = resolved
                return resolved
        except (NameError, SyntaxError):
            pass

        return Any


class DataclassJSONEncoder:
    """Handles encoding of dataclass instances to JSON-compatible dictionaries."""

    @classmethod
    def encode(cls, obj: Any) -> Any:
        """Convert a dataclass instance to a JSON-compatible dictionary."""
        if obj is None:
            return None

        if isinstance(obj, (str, int, float, bool)):
            return obj

        if isinstance(obj, (datetime, date)):
            return obj.isoformat()

        if isinstance(obj, Enum):
            return obj.value if hasattr(obj, "value") else str(obj)

        if isinstance(obj, (list, tuple, Sequence)):
            return [cls.encode(item) for item in obj]

        if isinstance(obj, dict):
            return {key: cls.encode(value) for key, value in obj.items()}

        if is_dataclass(obj):
            result: Dict[str, Any] = {}
            for field in fields(obj):
                value = getattr(obj, field.name)
                if value is not None:
                    try:
                        result[snake_to_camel(field.name)] = cls.encode(value)
                    except ValueError as e:
                        raise ValueError(f"Error encoding field {field.name}: {str(e)}")
            return result

        return str(obj)


class JSONDataclassMixin(DataclassProtocol):
    """Mixin class to add JSON conversion capabilities to dataclasses."""

    def to_json(self) -> str:
        """Convert instance to JSON string."""
        return json.dumps(self.to_dict())

    def to_dict(self) -> Dict[str, Any]:
        """Convert instance to dictionary."""
        return cast(Dict[str, Any], DataclassJSONEncoder.encode(self))

    @classmethod
    def from_json(cls, json_str: str, module_scope: Optional[types.ModuleType] = None) -> "JSONDataclassMixin":
        """Create instance from JSON string."""
        data = json.loads(json_str)
        # Add type annotation for decoder variable
        decoder: "DataclassJSONDecoder[JSONDataclassMixin]" = DataclassJSONDecoder(
            module_scope or sys.modules[cls.__module__]
        )
        return cast("JSONDataclassMixin", decoder.decode(data, cls))

    @classmethod
    def from_dict(cls, data: Dict[str, Any], module_scope: Optional[types.ModuleType] = None) -> "JSONDataclassMixin":
        """Create instance from dictionary."""
        decoder: "DataclassJSONDecoder[JSONDataclassMixin]" = DataclassJSONDecoder(
            module_scope or sys.modules[cls.__module__]
        )
        return cast("JSONDataclassMixin", decoder.decode(data, cls))


D = TypeVar("D", bound=JSONDataclassMixin)


class DataclassJSONDecoder(typing.Generic[D]):
    """Handles decoding of JSON data to dataclass instances."""

    def __init__(self, module_scope: Optional[types.ModuleType] = None) -> None:
        self.module_scope = module_scope or sys.modules[__name__]
        self.type_resolver = TypeResolver(self.module_scope)

    def decode(self, data: Any, target_type: Any) -> Any:
        """Decode JSON data into a target type."""
        if data is None:
            return None

        if isinstance(target_type, str):
            target_type = self.type_resolver.resolve_type(target_type)

        origin = get_origin(target_type)
        args = get_args(target_type)

        if origin is Union:
            non_none_types = [t for t in args if t is not type(None)]
            if not non_none_types:
                return data
            last_error: Optional[Exception] = None
            for t in non_none_types:
                try:
                    return self.decode(data, t)
                except (ValueError, TypeError) as e:
                    last_error = e
            raise ValueError(f"Could not decode value as any of the expected types. Last error: {str(last_error)}")

        if origin in (list, List, Sequence) or (isinstance(origin, type) and issubclass(origin, (list, Sequence))):
            item_type = args[0] if args else Any
            if isinstance(data, str):
                return [data]
            if not isinstance(data, list):
                data = [data] if data is not None else []
            return [self.decode(item, item_type) for item in data]

        if origin in (dict, Dict) or (isinstance(origin, type) and issubclass(origin, dict)):
            if not isinstance(data, dict):
                raise TypeError(f"Expected dict but got {type(data)}")
            key_type = args[0] if args else str
            value_type = args[1] if len(args) > 1 else Any
            return {self.decode(k, key_type): self.decode(v, value_type) for k, v in data.items()}

        if is_dataclass(target_type):
            return self._decode_dataclass(data, cast(Type[D], target_type))

        if isinstance(target_type, type):
            if issubclass(target_type, Enum):
                try:
                    if isinstance(data, str) and hasattr(target_type, data):
                        return getattr(target_type, data)
                    return target_type(data)
                except ValueError:
                    valid_values = [e.value for e in target_type]
                    raise TypeError(
                        f"Invalid value for {target_type.__name__}: {data}. Valid values are: {valid_values}"
                    )

            if issubclass(target_type, (datetime, date)):
                return target_type.fromisoformat(data) if data else None

        return data

    def _decode_dataclass(self, data: Dict[str, Any], target_class: Type[D]) -> D:
        """Decode a dictionary into a dataclass instance."""
        if not isinstance(data, dict):
            raise TypeError(f"Expected dict but got {type(data)}")

        protocol_class = cast(DataclassProtocol, target_class)
        class_fields = {field.name: field for field in fields(protocol_class)}
        field_values: Dict[str, Any] = {}

        field_mapping: Dict[str, str] = {}
        for field_name in class_fields:
            try:
                camel_name = snake_to_camel(field_name)
                field_mapping[camel_name] = field_name
                field_mapping[field_name] = field_name
            except ValueError:
                continue

        for key, value in data.items():
            mapped_name = None
            if key in field_mapping:
                mapped_name = field_mapping[key]
            else:
                try:
                    snake_key = camel_to_snake(key)
                    if snake_key in class_fields:
                        mapped_name = snake_key
                except ValueError:
                    continue

            if mapped_name and mapped_name in class_fields:
                field = class_fields[mapped_name]
                try:
                    field_type = self.type_resolver.resolve_type(field.type)
                    field_values[mapped_name] = self.decode(value, field_type)
                except Exception as e:
                    raise TypeError(f"Error decoding field {key}: {str(e)}")

        missing_required = [
            name
            for name, field in class_fields.items()
            if name not in field_values and field.default is MISSING and field.default_factory is MISSING
        ]

        if missing_required:
            raise TypeError(f"Missing required arguments: {', '.join(missing_required)}")

        self._apply_default_values(field_values, class_fields)

        try:
            instance = target_class(**field_values)
            return instance
        except Exception as e:
            raise TypeError(f"Error creating instance of {target_class.__name__}: {str(e)}")

    def _apply_default_values(self, field_values: Dict[str, Any], class_fields: Dict[str, Field[Any]]) -> None:
        """Apply default values to fields."""
        for field_name, field in class_fields.items():
            if field_name not in field_values:
                if field.default is not MISSING:
                    field_values[field_name] = field.default
                elif field.default_factory is not MISSING:  # type: ignore
                    field_values[field_name] = field.default_factory()  # type: ignore
