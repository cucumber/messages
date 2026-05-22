// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestRunFinished {
  final String? message;
  final bool success;
  final Timestamp timestamp;
  final Exception? exception;
  final String? testRunStartedId;

  const TestRunFinished({
    this.message,
    required this.success,
    required this.timestamp,
    this.exception,
    this.testRunStartedId,
  });

  factory TestRunFinished.fromJson(Map<String, Object?> json) {
    return TestRunFinished(
      message: json['message'] as String?,
      success: _requireJsonBool(json, 'success'),
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
      exception: json['exception'] == null
          ? null
          : Exception.fromJson(
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

