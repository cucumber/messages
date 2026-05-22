// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class JavaStackTraceElement {
  final String className;
  final String fileName;
  final String methodName;

  const JavaStackTraceElement({
    required this.className,
    required this.fileName,
    required this.methodName,
  });

  factory JavaStackTraceElement.fromJson(Map<String, Object?> json) {
    return JavaStackTraceElement(
      className: _requireJsonString(json, 'className'),
      fileName: _requireJsonString(json, 'fileName'),
      methodName: _requireJsonString(json, 'methodName'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['className'] = className;
    json['fileName'] = fileName;
    json['methodName'] = methodName;
    return json;
  }
}

