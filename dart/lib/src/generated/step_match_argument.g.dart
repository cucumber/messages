// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [StepMatchArgument message](https://github.com/cucumber/messages/blob/main/jsonschema/src/StepMatchArgument.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// Represents a single argument extracted from a step match and passed to a step definition.
/// This is used for the following purposes:
/// - Construct an argument to pass to a step definition (possibly through a parameter type transform)
/// - Highlight the matched parameter in rich formatters such as the HTML formatter
///
/// This message closely matches the `Argument` class in the `cucumber-expressions` library.
class StepMatchArgument {
  /// Represents the outermost capture group of an argument. This message closely matches the
  /// `Group` class in the `cucumber-expressions` library.
  final Group group;
  /// The `parameterTypeName` property.
  final String? parameterTypeName;

  /// Creates an instance of [StepMatchArgument].
  const StepMatchArgument({
    required this.group,
    this.parameterTypeName,
  });

  /// Creates an instance of [StepMatchArgument] from a JSON object.
  factory StepMatchArgument.fromJson(Map<String, Object?> json) {
    return StepMatchArgument(
      group: Group.fromJson(
              _requireJsonObject(json, 'group'),
            ),
      parameterTypeName: json['parameterTypeName'] as String?,
    );
  }

  /// Converts this [StepMatchArgument] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['group'] = group.toJson();
    if (parameterTypeName != null) {
      json['parameterTypeName'] = parameterTypeName;
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is StepMatchArgument &&
          runtimeType == other.runtimeType &&
          group == other.group &&
          parameterTypeName == other.parameterTypeName;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        group,
        parameterTypeName,
      ]);

  @override
  String toString() =>
      'StepMatchArgument{group: ${group}, parameterTypeName: ${parameterTypeName}}';

  /// Creates a copy of this [StepMatchArgument] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  StepMatchArgument copyWith({
    Group? group,
    String? parameterTypeName,
  }) {
    return StepMatchArgument(
      group: group ?? this.group,
      parameterTypeName: parameterTypeName ?? this.parameterTypeName,
    );
  }
}

