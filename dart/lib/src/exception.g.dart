// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Exception {
  final String type;
  final String? message;
  final String? stackTrace;

  const Exception({
    this.type = '',
    this.message,
    this.stackTrace,
  });

  factory Exception.fromJson(Map<String, Object?> json) {
    return Exception(
      type: json['type'] as String? ?? '',
      message: json['message'] as String?,
      stackTrace: json['stackTrace'] as String?,
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['type'] = type;
    if (message != null) {
      json['message'] = message;
    }
    if (stackTrace != null) {
      json['stackTrace'] = stackTrace;
    }
    return json;
  }
}

