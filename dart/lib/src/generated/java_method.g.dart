// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [JavaMethod message](https://github.com/cucumber/messages/blob/main/jsonschema/src/JavaMethod.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class JavaMethod {
  /// The `className` property.
  final String className;
  /// The `methodName` property.
  final String methodName;
  /// The `methodParameterTypes` property.
  final List<String> methodParameterTypes;

  /// Creates an instance of [JavaMethod].
  const JavaMethod({
    required this.className,
    required this.methodName,
    required this.methodParameterTypes,
  });

  /// Creates an instance of [JavaMethod] from a JSON object.
  factory JavaMethod.fromJson(Map<String, Object?> json) {
    return JavaMethod(
      className: _requireJsonString(json, 'className'),
      methodName: _requireJsonString(json, 'methodName'),
      methodParameterTypes: _requireJsonList(json, 'methodParameterTypes')
              .map((item) => item as String)
              .toList(),
    );
  }

  /// Converts this [JavaMethod] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['className'] = className;
    json['methodName'] = methodName;
    json['methodParameterTypes'] = methodParameterTypes;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is JavaMethod &&
          runtimeType == other.runtimeType &&
          className == other.className &&
          methodName == other.methodName &&
          _listEquals(methodParameterTypes, other.methodParameterTypes);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        className,
        methodName,
        Object.hashAll(methodParameterTypes),
      ]);

  @override
  String toString() =>
      'JavaMethod{className: $className, methodName: $methodName, methodParameterTypes: $methodParameterTypes}';
}

