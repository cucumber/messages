import collections.abc
import types
from dataclasses import MISSING, fields, is_dataclass
from datetime import date, datetime
from enum import Enum
from types import GenericAlias
from typing import Any, Optional, Union, cast, get_args, get_origin


def camel_to_snake(s: str) -> str:
    """Convert a camelCase string to snake_case."""
    if not s:
        return s
    result = [s[0].lower()]
    for char in s[1:]:
        if char.isupper():
            result.extend(["_", char.lower()])
        else:
            result.append(char)
    return "".join(result)


def snake_to_camel(s: str) -> str:
    """Convert a snake_case string to camelCase."""
    if not s:
        return s
    components = s.split("_")
    return components[0] + "".join(x.title() for x in components[1:])


class TypeResolver:
    """Resolves type hints to their concrete types using the module scope."""

    def __init__(self, module_scope: types.ModuleType):
        self.module_scope = module_scope
        self._type_cache: dict[str, Any] = {}

    def _resolve_forward_ref(self, type_hint: Any) -> Any:
        """Handle forward reference types."""
        if not hasattr(type_hint, "__forward_arg__"):
            return None
        forward_arg = type_hint.__forward_arg__
        return getattr(self.module_scope, forward_arg, Any)

    def _resolve_union(self, type_hint: Any) -> Any:
        """Handle Union types including Optional."""
        args = get_args(type_hint)
        resolved_args = tuple(self.resolve_type(arg) for arg in args)
        return Union[resolved_args]

    def _resolve_string_optional(self, type_str: str) -> Any:
        """Handle Optional types defined as strings."""
        if not type_str.startswith("Optional["):
            return None
        inner_type = type_str[9:-1].strip("'\"")
        resolved_inner = self.resolve_type(inner_type)
        return Union[resolved_inner, type(None)]

    def _resolve_generic_collection(self, type_str: str) -> Any:
        """Handle generic collection types like List[T] and Dict[K, V]."""
        if "[" not in type_str:
            return None

        base_type, inner = type_str.split("[", 1)
        inner = inner.rstrip("]").strip()

        if base_type.lower() in {"list", "sequence"}:
            resolved_type = self.resolve_type(inner.strip("'\""))
            return GenericAlias(list, (resolved_type,))

        if base_type.lower() == "dict":
            key_type_str, value_type_str = map(str.strip, inner.split(",", 1))
            resolved_key = self.resolve_type(key_type_str.strip("'\""))
            resolved_value = self.resolve_type(value_type_str.strip("'\""))
            return GenericAlias(dict, (resolved_key, resolved_value))

        return Any

    def resolve_type(self, type_hint: Any) -> Any:
        """Resolve a type hint to its concrete type."""
        if isinstance(type_hint, type):
            return type_hint

        resolved_forward = self._resolve_forward_ref(type_hint)
        if resolved_forward is not None:
            return resolved_forward

        if get_origin(type_hint) is Union:
            return self._resolve_union(type_hint)

        if not isinstance(type_hint, str):
            return type_hint

        if type_hint in self._type_cache:
            return self._type_cache[type_hint]

        clean_hint = type_hint.strip("'\"")

        resolved_optional = self._resolve_string_optional(clean_hint)
        if resolved_optional is not None:
            self._type_cache[type_hint] = resolved_optional
            return resolved_optional

        resolved_collection = self._resolve_generic_collection(clean_hint)
        if resolved_collection is not None:
            self._type_cache[type_hint] = resolved_collection
            return resolved_collection

        if hasattr(self.module_scope, clean_hint):
            resolved = getattr(self.module_scope, clean_hint)
            if isinstance(resolved, type):
                self._type_cache[type_hint] = resolved
                return resolved

        return Any


class JsonDataclassConverter:
    def __init__(self, module_scope: types.ModuleType):
        self.type_resolver = TypeResolver(module_scope)

    def _convert_datetime(self, value: Any, target_type: Any) -> Any:
        """Convert datetime and date values."""
        if target_type in (datetime, date) and isinstance(value, str):
            return target_type.fromisoformat(value)
        return None

    def _convert_enum(self, value: Any, target_type: Any) -> Any:
        """Convert enum values."""
        if isinstance(target_type, type) and issubclass(target_type, Enum):
            return target_type(value)
        return None

    def _convert_sequence(self, value: Any, target_type: Any, field_name: Optional[str]) -> Any:
        """Convert sequence values."""
        origin = get_origin(target_type)
        if not (origin is not None and isinstance(origin, type) and issubclass(origin, collections.abc.Sequence)):
            return None

        if isinstance(value, str):
            return value

        args = get_args(target_type)
        item_type = args[0] if args else Any
        return [self._convert_value(item, item_type, field_name) for item in value]

    def _convert_dict(self, value: Any, target_type: Any, field_name: Optional[str]) -> Any:
        """Convert dictionary values."""
        if get_origin(target_type) is not dict:
            return None

        key_type, value_type = get_args(target_type)
        return {
            self._convert_value(k, key_type, field_name): self._convert_value(v, value_type, field_name)
            for k, v in value.items()
        }

    def _convert_dataclass(self, value: Any, target_type: Any) -> Any:
        """Convert nested dataclass values."""
        if is_dataclass(target_type) and isinstance(value, dict):
            # Cast target_type to Type[Any] to satisfy Mypy
            return self.from_dict(value, cast(type[Any], target_type))
        return None

    def _convert_optional(self, value: Any, target_type: Any, field_name: Optional[str]) -> Any:
        """Convert Optional/Union values."""
        if get_origin(target_type) is not Union:
            return None

        args = get_args(target_type)
        if value is None and type(None) in args:
            return None

        actual_type = next((t for t in args if t is not type(None)), Any)
        return self._convert_value(value, actual_type, field_name)

    def _convert_value(self, value: Any, target_type: Any, field_name: Optional[str] = None) -> Any:
        """Convert a single value to the target type."""
        if value is None:
            return None

        return (
            self._convert_optional(value, target_type, field_name)
            or self._convert_datetime(value, target_type)
            or self._convert_enum(value, target_type)
            or self._convert_sequence(value, target_type, field_name)
            or self._convert_dict(value, target_type, field_name)
            or self._convert_dataclass(value, target_type)
            or value
        )

    def from_dict(self, data: Any, target_class: type[Any]) -> Any:
        """Convert a dictionary to a dataclass instance."""
        if data is None:
            return None

        if not is_dataclass(target_class):
            return self._convert_value(data, target_class, None)

        if not isinstance(data, dict):
            raise TypeError(f"Expected dict but got {type(data)}")

        class_fields = {field.name: field for field in fields(target_class)}
        init_kwargs = {}

        for key, value in data.items():
            field_name = camel_to_snake(key)
            if field_name not in class_fields:
                continue

            field = class_fields[field_name]
            field_type = self.type_resolver.resolve_type(field.type)

            try:
                init_kwargs[field_name] = self._convert_value(value, field_type, field_name)
            except Exception as e:
                raise TypeError(f"Error converting field {key}: {str(e)}") from e

        missing_required = [
            name
            for name, field in class_fields.items()
            if name not in init_kwargs and field.default is MISSING and field.default_factory is MISSING
        ]

        if missing_required:
            raise TypeError(f"Missing required fields: {', '.join(missing_required)}")

        return target_class(**init_kwargs)

    def to_dict(self, obj: Any) -> Any:
        """Convert a dataclass instance to a dictionary."""
        if obj is None:
            return None

        if isinstance(obj, (str, int, float, bool)):
            return obj

        if isinstance(obj, Enum):
            return obj.value

        if isinstance(obj, (datetime, date)):
            return obj.isoformat()

        if isinstance(obj, (list, tuple)):
            return [self.to_dict(item) for item in obj]

        if isinstance(obj, dict):
            return {snake_to_camel(str(key)): self.to_dict(value) for key, value in obj.items()}

        if is_dataclass(obj):
            return {
                snake_to_camel(field.name): self.to_dict(getattr(obj, field.name))
                for field in fields(obj)
                if getattr(obj, field.name) is not None
            }

        return str(obj)
