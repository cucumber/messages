// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class TestRunFinished {
  final String? message;
  final bool success;
  final Timestamp timestamp;
  final ExceptionMessage? exception;
  final String? testRunStartedId;

  const TestRunFinished({
    this.message,
    this.success = false,
    this.timestamp = const Timestamp(),
    this.exception,
    this.testRunStartedId,
  });

  factory TestRunFinished.fromJson(Map<String, Object?> json) {
    return TestRunFinished(
      message: json['message'] as String?,
      success: json['success'] as bool? ?? false,
      timestamp: json['timestamp'] == null
          ? const Timestamp()
          : Timestamp.fromJson(json['timestamp'] as Map<String, Object?>),
      exception: json['exception'] == null
          ? null
          : ExceptionMessage.fromJson(
              json['exception'] as Map<String, Object?>,
            ),
      testRunStartedId: json['testRunStartedId'] as String?,
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (message != null) {
      json['message'] = message;
    }
    json['success'] = success;
    json['timestamp'] = timestamp.toJson();
    if (exception != null) {
      json['exception'] = exception!.toJson();
    }
    if (testRunStartedId != null) {
      json['testRunStartedId'] = testRunStartedId;
    }
    return json;
  }
}
