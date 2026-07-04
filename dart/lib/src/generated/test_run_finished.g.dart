// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TestRunFinished message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestRunFinished.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestRunFinished {
  /// An informative message about the test run. Typically additional information about failure, but not necessarily.
  final String? message;
  /// A test run is successful if all steps are either passed or skipped, all before/after hooks passed and no other exceptions where thrown.
  final bool success;
  /// Timestamp when the TestRun is finished
  final Timestamp timestamp;
  /// Any exception thrown during the test run, if any. Does not include exceptions thrown while executing steps.
  final Exception? exception;
  /// The `testRunStartedId` property.
  final String? testRunStartedId;

  /// Creates an instance of [TestRunFinished].
  const TestRunFinished({
    this.message,
    required this.success,
    required this.timestamp,
    this.exception,
    this.testRunStartedId,
  });

  /// Creates an instance of [TestRunFinished] from a JSON object.
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

  /// Converts this [TestRunFinished] to a JSON object.
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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestRunFinished &&
          runtimeType == other.runtimeType &&
          message == other.message &&
          success == other.success &&
          timestamp == other.timestamp &&
          exception == other.exception &&
          testRunStartedId == other.testRunStartedId;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        message,
        success,
        timestamp,
        exception,
        testRunStartedId,
      ]);

  @override
  String toString() =>
      'TestRunFinished{message: ${message}, success: ${success}, timestamp: ${timestamp}, exception: ${exception}, testRunStartedId: ${testRunStartedId}}';

  /// Creates a copy of this [TestRunFinished] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  TestRunFinished copyWith({
    String? message,
    bool? success,
    Timestamp? timestamp,
    Exception? exception,
    String? testRunStartedId,
  }) {
    return TestRunFinished(
      message: message ?? this.message,
      success: success ?? this.success,
      timestamp: timestamp ?? this.timestamp,
      exception: exception ?? this.exception,
      testRunStartedId: testRunStartedId ?? this.testRunStartedId,
    );
  }
}

