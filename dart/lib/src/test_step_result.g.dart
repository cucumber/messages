// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

enum TestStepResultStatus {
  unknown('UNKNOWN'),
  passed('PASSED'),
  skipped('SKIPPED'),
  pending('PENDING'),
  undefined('UNDEFINED'),
  ambiguous('AMBIGUOUS'),
  failed('FAILED'),
  ;

  const TestStepResultStatus(this.value);
  final String value;

  static TestStepResultStatus fromValue(String value) => values.firstWhere((v) => v.value == value);
}

class TestStepResult {
  final Duration duration;
  final String? message;
  final TestStepResultStatus status;
  final Exception? exception;

  const TestStepResult({
    this.duration = const Duration(),
    this.message,
    this.status = TestStepResultStatus.unknown,
    this.exception,
  });

  factory TestStepResult.fromJson(Map<String, Object?> json) {
    return TestStepResult(
      duration: json['duration'] == null
          ? const Duration()
          : Duration.fromJson(
              json['duration'] as Map<String, Object?>,
            ),
      message: json['message'] as String?,
      status: json['status'] == null
          ? TestStepResultStatus.unknown
          : TestStepResultStatus.fromValue(
              json['status'] as String,
            ),
      exception: json['exception'] == null
          ? null
          : Exception.fromJson(
              json['exception'] as Map<String, Object?>,
            ),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['duration'] = duration.toJson();
    if (message != null) {
      json['message'] = message;
    }
    json['status'] = status.value;
    if (exception != null) {
      json['exception'] = exception!.toJson();
    }
    return json;
  }
}

