// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class JavaMethod {
  final String className;
  final String methodName;
  final List<String> methodParameterTypes;

  const JavaMethod({
    this.className = '',
    this.methodName = '',
    this.methodParameterTypes = const [],
  });

  factory JavaMethod.fromJson(Map<String, Object?> json) {
    return JavaMethod(
      className: json['className'] as String? ?? '',
      methodName: json['methodName'] as String? ?? '',
      methodParameterTypes:
          (json['methodParameterTypes'] as List<Object?>?)
              ?.map((item) => item as String)
              .toList() ??
          const [],
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
