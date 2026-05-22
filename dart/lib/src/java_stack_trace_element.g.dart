// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class JavaStackTraceElement {
  final String className;
  final String fileName;
  final String methodName;

  const JavaStackTraceElement({
    this.className = '',
    this.fileName = '',
    this.methodName = '',
  });

  factory JavaStackTraceElement.fromJson(Map<String, Object?> json) {
    return JavaStackTraceElement(
      className: json['className'] as String? ?? '',
      fileName: json['fileName'] as String? ?? '',
      methodName: json['methodName'] as String? ?? '',
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

