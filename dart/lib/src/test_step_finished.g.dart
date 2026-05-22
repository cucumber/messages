// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestStepFinished {
  final String testCaseStartedId;
  final String testStepId;
  final TestStepResult testStepResult;
  final Timestamp timestamp;

  const TestStepFinished({
    required this.testCaseStartedId,
    required this.testStepId,
    required this.testStepResult,
    required this.timestamp,
  });

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

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['testCaseStartedId'] = testCaseStartedId;
    json['testStepId'] = testStepId;
    json['testStepResult'] = testStepResult.toJson();
    json['timestamp'] = timestamp.toJson();
    return json;
  }
}

