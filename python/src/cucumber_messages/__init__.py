from . import _messages, json_converter
from ._messages import *

message_converter: json_converter.JsonDataclassConverter = json_converter.JsonDataclassConverter(module_scope=_messages)
