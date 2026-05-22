// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class UndefinedParameterType {
  final String expression;
  final String name;

  const UndefinedParameterType({
    required this.expression,
    required this.name,
  });

  factory UndefinedParameterType.fromJson(Map<String, Object?> json) {
    return UndefinedParameterType(
      expression: _requireJsonString(json, 'expression'),
      name: _requireJsonString(json, 'name'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['expression'] = expression;
    json['name'] = name;
    return json;
  }
}

