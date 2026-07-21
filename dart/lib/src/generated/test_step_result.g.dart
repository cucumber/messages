// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Values for the `status` property.
enum TestStepResultStatus {
  /// The `UNKNOWN` value.
  unknown('UNKNOWN'),
  /// The `PASSED` value.
  passed('PASSED'),
  /// The `SKIPPED` value.
  skipped('SKIPPED'),
  /// The `PENDING` value.
  pending('PENDING'),
  /// The `UNDEFINED` value.
  undefined('UNDEFINED'),
  /// The `AMBIGUOUS` value.
  ambiguous('AMBIGUOUS'),
  /// The `FAILED` value.
  failed('FAILED'),
  ;

  /// Creates an instance of [TestStepResultStatus] from its wire [value].
  const TestStepResultStatus(this.value);

  /// The wire value used in message JSON.
  final String value;

  /// Returns the [TestStepResultStatus] matching [value].
  static TestStepResultStatus fromValue(String value) => values.firstWhere((v) => v.value == value);
}

/// Generated Dart representation of the [TestStepResult message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestStepResult.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestStepResult {
  /// The `duration` property.
  final Duration duration;
  /// An arbitrary bit of information that explains this result. If there was an exception, this should include a stringified representation of it including type, message and stack trace (the exact format will vary by platform).
  final String? message;
  /// The `status` property.
  final TestStepResultStatus status;
  /// Exception thrown while executing this step, if any.
  final Exception? exception;

  /// Creates an instance of [TestStepResult].
  const TestStepResult({
    required this.duration,
    this.message,
    required this.status,
    this.exception,
  });

  /// Creates an instance of [TestStepResult] from a JSON object.
  factory TestStepResult.fromJson(Map<String, Object?> json) {
    return TestStepResult(
      duration: Duration.fromJson(
              _requireJsonObject(json, 'duration'),
            ),
      message: json['message'] as String?,
      status: TestStepResultStatus.fromValue(
              _requireJsonString(json, 'status'),
            ),
      exception: json['exception'] == null
          ? null
          : Exception.fromJson(
              json['exception'] as Map<String, Object?>,
            ),
    );
  }

  /// Converts this [TestStepResult] to a JSON object.
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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestStepResult &&
          runtimeType == other.runtimeType &&
          duration == other.duration &&
          message == other.message &&
          status == other.status &&
          exception == other.exception;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        duration,
        message,
        status,
        exception,
      ]);

  @override
  String toString() =>
      'TestStepResult{duration: $duration, message: $message, status: $status, exception: $exception}';
}

