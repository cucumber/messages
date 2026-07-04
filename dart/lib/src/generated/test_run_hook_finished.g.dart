// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TestRunHookFinished message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestRunHookFinished.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestRunHookFinished {
  /// Identifier for the hook execution that has finished
  final String testRunHookStartedId;
  /// The `result` property.
  final TestStepResult result;
  /// The `timestamp` property.
  final Timestamp timestamp;

  /// Creates an instance of [TestRunHookFinished].
  const TestRunHookFinished({
    required this.testRunHookStartedId,
    required this.result,
    required this.timestamp,
  });

  /// Creates an instance of [TestRunHookFinished] from a JSON object.
  factory TestRunHookFinished.fromJson(Map<String, Object?> json) {
    return TestRunHookFinished(
      testRunHookStartedId: _requireJsonString(json, 'testRunHookStartedId'),
      result: TestStepResult.fromJson(
              _requireJsonObject(json, 'result'),
            ),
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
    );
  }

  /// Converts this [TestRunHookFinished] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['testRunHookStartedId'] = testRunHookStartedId;
    json['result'] = result.toJson();
    json['timestamp'] = timestamp.toJson();
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestRunHookFinished &&
          runtimeType == other.runtimeType &&
          testRunHookStartedId == other.testRunHookStartedId &&
          result == other.result &&
          timestamp == other.timestamp;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        testRunHookStartedId,
        result,
        timestamp,
      ]);

  @override
  String toString() =>
      'TestRunHookFinished{testRunHookStartedId: ${testRunHookStartedId}, result: ${result}, timestamp: ${timestamp}}';

  /// Creates a copy of this [TestRunHookFinished] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  TestRunHookFinished copyWith({
    String? testRunHookStartedId,
    TestStepResult? result,
    Timestamp? timestamp,
  }) {
    return TestRunHookFinished(
      testRunHookStartedId: testRunHookStartedId ?? this.testRunHookStartedId,
      result: result ?? this.result,
      timestamp: timestamp ?? this.timestamp,
    );
  }
}

