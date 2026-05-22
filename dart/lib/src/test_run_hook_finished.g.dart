// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class TestRunHookFinished {
  final String testRunHookStartedId;
  final TestStepResult result;
  final Timestamp timestamp;

  const TestRunHookFinished({
    this.testRunHookStartedId = '',
    this.result = const TestStepResult(),
    this.timestamp = const Timestamp(),
  });

  factory TestRunHookFinished.fromJson(Map<String, Object?> json) {
    return TestRunHookFinished(
      testRunHookStartedId: json['testRunHookStartedId'] as String? ?? '',
      result: json['result'] == null
          ? const TestStepResult()
          : TestStepResult.fromJson(
              json['result'] as Map<String, Object?>,
            ),
      timestamp: json['timestamp'] == null
          ? const Timestamp()
          : Timestamp.fromJson(
              json['timestamp'] as Map<String, Object?>,
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

