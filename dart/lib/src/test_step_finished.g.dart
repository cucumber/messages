// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class TestStepFinished {
  final String testCaseStartedId;
  final String testStepId;
  final TestStepResult testStepResult;
  final Timestamp timestamp;

  const TestStepFinished({
    this.testCaseStartedId = '',
    this.testStepId = '',
    this.testStepResult = const TestStepResult(),
    this.timestamp = const Timestamp(),
  });

  factory TestStepFinished.fromJson(Map<String, Object?> json) {
    return TestStepFinished(
      testCaseStartedId: json['testCaseStartedId'] as String? ?? '',
      testStepId: json['testStepId'] as String? ?? '',
      testStepResult: json['testStepResult'] == null
          ? const TestStepResult()
          : TestStepResult.fromJson(
              json['testStepResult'] as Map<String, Object?>,
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
    json['testCaseStartedId'] = testCaseStartedId;
    json['testStepId'] = testStepId;
    json['testStepResult'] = testStepResult.toJson();
    json['timestamp'] = timestamp.toJson();
    return json;
  }
}

