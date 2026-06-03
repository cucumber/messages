// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Represents the UndefinedParameterType message in [Cucumber's message protocol](https://github.com/cucumber/messages).
class UndefinedParameterType {
  /// The `expression` property.
  final String expression;
  /// The `name` property.
  final String name;

  /// Creates an instance of [UndefinedParameterType].
  const UndefinedParameterType({
    required this.expression,
    required this.name,
  });

  /// Creates an instance of [UndefinedParameterType] from a JSON object.
  factory UndefinedParameterType.fromJson(Map<String, Object?> json) {
    return UndefinedParameterType(
      expression: _requireJsonString(json, 'expression'),
      name: _requireJsonString(json, 'name'),
    );
  }

  /// Converts this [UndefinedParameterType] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['expression'] = expression;
    json['name'] = name;
    return json;
  }
}

