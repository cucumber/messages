// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestStepStarted {
  final String testCaseStartedId;
  final String testStepId;
  final Timestamp timestamp;

  const TestStepStarted({
    required this.testCaseStartedId,
    required this.testStepId,
    required this.timestamp,
  });

  factory TestStepStarted.fromJson(Map<String, Object?> json) {
    return TestStepStarted(
      testCaseStartedId: _requireJsonString(json, 'testCaseStartedId'),
      testStepId: _requireJsonString(json, 'testStepId'),
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['testCaseStartedId'] = testCaseStartedId;
    json['testStepId'] = testStepId;
    json['timestamp'] = timestamp.toJson();
    return json;
  }
}

