// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestRunHookFinished {
  final String testRunHookStartedId;
  final TestStepResult result;
  final Timestamp timestamp;

  const TestRunHookFinished({
    required this.testRunHookStartedId,
    required this.result,
    required this.timestamp,
  });

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

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['testRunHookStartedId'] = testRunHookStartedId;
    json['result'] = result.toJson();
    json['timestamp'] = timestamp.toJson();
    return json;
  }
}

