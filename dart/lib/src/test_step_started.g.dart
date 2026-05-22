// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class TestStepStarted {
  final String testCaseStartedId;
  final String testStepId;
  final Timestamp timestamp;

  const TestStepStarted({
    this.testCaseStartedId = '',
    this.testStepId = '',
    this.timestamp = const Timestamp(),
  });

  factory TestStepStarted.fromJson(Map<String, Object?> json) {
    return TestStepStarted(
      testCaseStartedId: json['testCaseStartedId'] as String? ?? '',
      testStepId: json['testStepId'] as String? ?? '',
      timestamp: json['timestamp'] == null
          ? const Timestamp()
          : Timestamp.fromJson(json['timestamp'] as Map<String, Object?>),
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
