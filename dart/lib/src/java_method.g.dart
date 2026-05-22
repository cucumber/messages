// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class JavaMethod {
  final String className;
  final String methodName;
  final List<String> methodParameterTypes;

  const JavaMethod({
    required this.className,
    required this.methodName,
    required this.methodParameterTypes,
  });

  factory JavaMethod.fromJson(Map<String, Object?> json) {
    return JavaMethod(
      className: _requireJsonString(json, 'className'),
      methodName: _requireJsonString(json, 'methodName'),
      methodParameterTypes: _requireJsonList(json, 'methodParameterTypes')
              .map((item) => item as String)
              .toList(),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['className'] = className;
    json['methodName'] = methodName;
    json['methodParameterTypes'] = methodParameterTypes;
    return json;
  }
}

