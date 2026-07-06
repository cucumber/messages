// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TestStepFinished message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestStepFinished.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestStepFinished {
  /// The `testCaseStartedId` property.
  final String testCaseStartedId;
  /// The `testStepId` property.
  final String testStepId;
  /// The `testStepResult` property.
  final TestStepResult testStepResult;
  /// The `timestamp` property.
  final Timestamp timestamp;

  /// Creates an instance of [TestStepFinished].
  const TestStepFinished({
    required this.testCaseStartedId,
    required this.testStepId,
    required this.testStepResult,
    required this.timestamp,
  });

  /// Creates an instance of [TestStepFinished] from a JSON object.
  factory TestStepFinished.fromJson(Map<String, Object?> json) {
    return TestStepFinished(
      testCaseStartedId: _requireJsonString(json, 'testCaseStartedId'),
      testStepId: _requireJsonString(json, 'testStepId'),
      testStepResult: TestStepResult.fromJson(
              _requireJsonObject(json, 'testStepResult'),
            ),
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
    );
  }

  /// Converts this [TestStepFinished] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['testCaseStartedId'] = testCaseStartedId;
    json['testStepId'] = testStepId;
    json['testStepResult'] = testStepResult.toJson();
    json['timestamp'] = timestamp.toJson();
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestStepFinished &&
          runtimeType == other.runtimeType &&
          testCaseStartedId == other.testCaseStartedId &&
          testStepId == other.testStepId &&
          testStepResult == other.testStepResult &&
          timestamp == other.timestamp;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        testCaseStartedId,
        testStepId,
        testStepResult,
        timestamp,
      ]);

  @override
  String toString() =>
      'TestStepFinished{testCaseStartedId: ${testCaseStartedId}, testStepId: ${testStepId}, testStepResult: ${testStepResult}, timestamp: ${timestamp}}';
}

