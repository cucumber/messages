// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

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
