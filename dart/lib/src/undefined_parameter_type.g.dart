// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class UndefinedParameterType {
  final String expression;
  final String name;

  const UndefinedParameterType({
    this.expression = '',
    this.name = '',
  });

  factory UndefinedParameterType.fromJson(Map<String, Object?> json) {
    return UndefinedParameterType(
      expression: json['expression'] as String? ?? '',
      name: json['name'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['expression'] = expression;
    json['name'] = name;
    return json;
  }
}

