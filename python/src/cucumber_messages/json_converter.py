import json
import re
import sys
import types
import typing
from dataclasses import fields, is_dataclass, Field, MISSING
from datetime import datetime, date
from enum import Enum
from typing import Any, Dict, List, Optional, Union, get_args, get_origin, TypeVar, Type as TypingType, Tuple

T = TypeVar('T')

def camel_to_snake(name: str) -> str:
    """Convert string from camelCase to snake_case."""
    # Validate field name - must start with letter or underscore and contain only alphanumeric and underscore
    if not name or not (name[0].isalpha() or name[0] == '_') or not all(c.isalnum() or c == '_' for c in name):
        raise ValueError(f"Invalid field name: {name}")

    # Convert camelCase to snake_case
    pattern = re.compile(r'(?<!^)(?=[A-Z])')
    return pattern.sub('_', name).lower()


def snake_to_camel(name: str) -> str:
    """Convert string from snake_case to camelCase."""
    # Validate field name - must start with letter or underscore and contain only alphanumeric and underscore
    if not name or not (name[0].isalpha() or name[0] == '_') or not all(c.isalnum() or c == '_' for c in name):
        raise ValueError(f"Invalid field name: {name}")

    # Convert snake_case to camelCase
    components = name.split('_')
    return components[0] + ''.join(x.title() for x in components[1:])


class GenericTypeResolver:
    """Handles resolution of generic type hints and container types."""

    def __init__(self, module_scope: types.ModuleType):
        self.module_scope = module_scope
        self.type_cache = {}

    def resolve_container_type(self, container_name: str) -> TypingType:
        container_types = {
            'Sequence': typing.Sequence,
            'List': list,
            'Set': typing.Set,
            'FrozenSet': typing.FrozenSet,
            'Deque': typing.Deque
        }
        if container_name not in container_types:
            raise ValueError(f"Unsupported container type: {container_name}")
        return container_types[container_name]

    def parse_generic_type(self, type_str: str) -> Tuple[TypingType, List[TypingType]]:
        container_name = type_str[:type_str.index('[')].strip()
        args_str = type_str[type_str.index('[') + 1:type_str.rindex(']')]

        container_type = self.resolve_container_type(container_name)

        if ',' in args_str:
            arg_types = [self.resolve_type(arg.strip()) for arg in args_str.split(',')]
        else:
            arg_types = [self.resolve_type(args_str.strip())]

        return container_type, arg_types

    def resolve_type(self, type_str: str) -> TypingType:
        if type_str in self.type_cache:
            return self.type_cache[type_str]

        if type_str in {'str', 'int', 'float', 'bool', 'Any'}:
            resolved = Any if type_str == 'Any' else eval(type_str)
        elif '[' in type_str:
            container_type, arg_types = self.parse_generic_type(type_str)
            resolved = container_type[tuple(arg_types) if len(arg_types) > 1 else arg_types[0]]
        elif '|' in type_str:
            resolved = self._resolve_union_type(type_str)
        elif hasattr(self.module_scope, type_str):
            resolved = getattr(self.module_scope, type_str)
        else:
            raise ValueError(f"Could not resolve type: {type_str}")

        self.type_cache[type_str] = resolved
        return resolved

    def _resolve_union_type(self, type_str: str) -> TypingType:
        types_str = [t.strip() for t in type_str.split('|')]
        resolved_types = [
            self.resolve_type(t)
            for t in types_str
            if t != 'None'
        ]
        return resolved_types[0] if len(resolved_types) == 1 else Union[tuple(resolved_types)]


class DataclassJSONEncoder:
    """Handles encoding of dataclass instances to JSON-compatible dictionaries."""

    @classmethod
    def encode(cls, obj: Any) -> Any:
        if is_dataclass(obj):
            return cls._encode_dataclass(obj)
        return cls._encode_value(obj)

    @classmethod
    def _encode_value(cls, value: Any) -> Any:
        if isinstance(value, list):
            return [cls.encode(item) for item in value]
        if isinstance(value, dict):
            return {key: cls.encode(val) for key, val in value.items()}
        if isinstance(value, (datetime, date)):
            return value.isoformat()
        if isinstance(value, Enum):
            return value.value
        if isinstance(value, (str, int, float, bool, type(None))):
            return value
        raise TypeError(f"Object of type {type(value)} is not JSON serializable")

    @classmethod
    def _encode_dataclass(cls, obj: Any) -> Dict[str, Any]:
        result = {}
        for field in fields(obj):
            value = getattr(obj, field.name)
            if value is not None:
                try:
                    result[snake_to_camel(field.name)] = cls.encode(value)
                except ValueError as e:
                    raise ValueError(f"Error encoding field {field.name}: {str(e)}")
        return result


class DataclassJSONDecoder:
    """Handles decoding of JSON data to dataclass instances."""

    def __init__(self, module_scope: Optional[types.ModuleType] = None):
        self.module_scope = module_scope or sys.modules[__name__]
        self.type_resolver = GenericTypeResolver(self.module_scope)

    def decode(self, data: Any, target_type: Any) -> Any:
        if data is None:
            return None

        if isinstance(target_type, str):
            target_type = self.type_resolver.resolve_type(target_type)

        origin, type_args = self._get_type_info(target_type)

        if origin is Union:
            return self._decode_union(data, type_args)

        if self._is_sequence_type(target_type):
            return self._decode_sequence(data, type_args)

        if origin is dict:
            return self._decode_dict(data, type_args)

        if is_dataclass(target_type):
            return self._decode_dataclass(data, target_type)

        if origin is datetime or target_type is datetime:
            return datetime.fromisoformat(data)

        if origin is date or target_type is date:
            return date.fromisoformat(data)

        if isinstance(target_type, type) and issubclass(target_type, Enum):
            try:
                return target_type(data)
            except ValueError as e:
                raise ValueError(f"{str(e)}. Valid values are: {[e.value for e in target_type]}")

        return data

    def _get_type_info(self, type_hint: Any) -> Tuple[Any, Tuple]:
        origin = get_origin(type_hint)
        args = get_args(type_hint)
        if origin is None and isinstance(type_hint, type):
            origin = type_hint
        return origin, args

    def _is_sequence_type(self, type_hint: Any) -> bool:
        origin = get_origin(type_hint)
        return (
                origin is list or
                origin is typing.Sequence or
                (isinstance(origin, type) and issubclass(origin, typing.Sequence))
        )

    def _decode_sequence(self, data: Any, type_args: Tuple) -> List:
        item_type = type_args[0] if type_args else Any
        if not isinstance(data, list):
            data = [data] if data is not None else []
        return [self.decode(item, item_type) for item in data]

    def _decode_union(self, data: Any, union_types: Tuple) -> Any:
        types = [t for t in union_types if t is not type(None)]
        if not types:
            return data
        if len(types) == 1:
            return self.decode(data, types[0])

        for t in types:
            try:
                return self.decode(data, t)
            except (ValueError, TypeError):
                continue
        raise ValueError(f"Could not decode {data} as any type in {types}")

    def _decode_dict(self, data: Dict, type_args: Tuple) -> Dict:
        if not isinstance(data, dict):
            raise TypeError(f"Expected dict but got {type(data)}")
        key_type = type_args[0] if type_args else str
        value_type = type_args[1] if len(type_args) > 1 else Any
        return {
            self.decode(k, key_type): self.decode(v, value_type)
            for k, v in data.items()
        }

    def _decode_dataclass(self, data: Dict[str, Any], target_class: Any) -> Any:
        """Decode dictionary into a dataclass instance."""
        if not isinstance(data, dict):
            raise TypeError(f"Expected dict but got {type(data)}")

        field_values = {}
        class_fields = {field.name: field for field in fields(target_class)}

        # Create a mapping for both camelCase and original field names
        field_mapping = {}
        for field_name in class_fields:
            try:
                camel_name = snake_to_camel(field_name)
                field_mapping[camel_name] = field_name
                field_mapping[field_name] = field_name
            except ValueError:
                continue

        # Process input fields
        for key, value in data.items():
            # Try to map the input key to a field name
            field_name = None

            # First try direct mapping
            if key in field_mapping:
                field_name = field_mapping[key]
            else:
                # Try converting the key
                try:
                    snake_key = camel_to_snake(key)
                    if snake_key in class_fields:
                        field_name = snake_key
                except ValueError:
                    continue

            if field_name and field_name in class_fields:
                field = class_fields[field_name]
                try:
                    field_values[field_name] = self.decode(value, field.type)
                except Exception as e:
                    raise TypeError(f"Error decoding field {key}: {str(e)}")

        # Check for missing required fields
        missing_required = [
            name for name, field in class_fields.items()
            if name not in field_values
               and field.default is MISSING
               and field.default_factory is MISSING
        ]

        if missing_required:
            raise TypeError(f"Missing required arguments: {', '.join(missing_required)}")

        # Add default values for missing optional fields
        self._apply_default_values(field_values, class_fields)
        return target_class(**field_values)

    def _apply_default_values(self, field_values: Dict[str, Any], class_fields: Dict[str, Field]) -> None:
        for field_name, field in class_fields.items():
            if field_name not in field_values:
                if field.default is not Field:
                    field_values[field_name] = field.default
                elif field.default_factory is not Field:
                    field_values[field_name] = field.default_factory()


class JSONDataclassMixin:
    """Mixin class to add JSON conversion capabilities to dataclasses."""

    def to_json(self) -> str:
        return json.dumps(self.to_dict())

    def to_dict(self) -> Dict[str, Any]:
        return DataclassJSONEncoder.encode(self)

    @classmethod
    def from_json(cls: TypingType[T], json_str: str, module_scope: Optional[types.ModuleType] = None) -> T:
        data = json.loads(json_str)
        return cls.from_dict(data, module_scope)

    @classmethod
    def from_dict(cls: TypingType[T], data: Dict[str, Any], module_scope: Optional[types.ModuleType] = None) -> T:
        decoder = DataclassJSONDecoder(module_scope or sys.modules[cls.__module__])
        return decoder.decode(data, cls)