// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class ExceptionMessage {
  final String type;
  final String? message;
  final String? stackTrace;

  const ExceptionMessage({
    this.type = '',
    this.message,
    this.stackTrace,
  });

  factory ExceptionMessage.fromJson(Map<String, Object?> json) {
    return ExceptionMessage(
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

