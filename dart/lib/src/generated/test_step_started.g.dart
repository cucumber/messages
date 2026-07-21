// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [TestStepStarted message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestStepStarted.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestStepStarted {
  /// The `testCaseStartedId` property.
  final String testCaseStartedId;
  /// The `testStepId` property.
  final String testStepId;
  /// The `timestamp` property.
  final Timestamp timestamp;

  /// Creates an instance of [TestStepStarted].
  const TestStepStarted({
    required this.testCaseStartedId,
    required this.testStepId,
    required this.timestamp,
  });

  /// Creates an instance of [TestStepStarted] from a JSON object.
  factory TestStepStarted.fromJson(Map<String, Object?> json) {
    return TestStepStarted(
      testCaseStartedId: _requireJsonString(json, 'testCaseStartedId'),
      testStepId: _requireJsonString(json, 'testStepId'),
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
    );
  }

  /// Converts this [TestStepStarted] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['testCaseStartedId'] = testCaseStartedId;
    json['testStepId'] = testStepId;
    json['timestamp'] = timestamp.toJson();
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestStepStarted &&
          runtimeType == other.runtimeType &&
          testCaseStartedId == other.testCaseStartedId &&
          testStepId == other.testStepId &&
          timestamp == other.timestamp;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        testCaseStartedId,
        testStepId,
        timestamp,
      ]);

  @override
  String toString() =>
      'TestStepStarted{testCaseStartedId: $testCaseStartedId, testStepId: $testStepId, timestamp: $timestamp}';
}

