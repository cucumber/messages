// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TestCaseFinished message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestCaseFinished.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestCaseFinished {
  /// The `testCaseStartedId` property.
  final String testCaseStartedId;
  /// The `timestamp` property.
  final Timestamp timestamp;
  /// The `willBeRetried` property.
  final bool willBeRetried;

  /// Creates an instance of [TestCaseFinished].
  const TestCaseFinished({
    required this.testCaseStartedId,
    required this.timestamp,
    required this.willBeRetried,
  });

  /// Creates an instance of [TestCaseFinished] from a JSON object.
  factory TestCaseFinished.fromJson(Map<String, Object?> json) {
    return TestCaseFinished(
      testCaseStartedId: _requireJsonString(json, 'testCaseStartedId'),
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
      willBeRetried: _requireJsonBool(json, 'willBeRetried'),
    );
  }

  /// Converts this [TestCaseFinished] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['testCaseStartedId'] = testCaseStartedId;
    json['timestamp'] = timestamp.toJson();
    json['willBeRetried'] = willBeRetried;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestCaseFinished &&
          runtimeType == other.runtimeType &&
          testCaseStartedId == other.testCaseStartedId &&
          timestamp == other.timestamp &&
          willBeRetried == other.willBeRetried;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        testCaseStartedId,
        timestamp,
        willBeRetried,
      ]);

  @override
  String toString() =>
      'TestCaseFinished{testCaseStartedId: $testCaseStartedId, timestamp: $timestamp, willBeRetried: $willBeRetried}';
}

