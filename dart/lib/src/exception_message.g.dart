// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

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
