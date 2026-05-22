// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class TestRunHookStarted {
  final String id;
  final String testRunStartedId;
  final String hookId;
  final String? workerId;
  final Timestamp timestamp;

  const TestRunHookStarted({
    this.id = '',
    this.testRunStartedId = '',
    this.hookId = '',
    this.workerId,
    this.timestamp = const Timestamp(),
  });

  factory TestRunHookStarted.fromJson(Map<String, Object?> json) {
    return TestRunHookStarted(
      id: json['id'] as String? ?? '',
      testRunStartedId: json['testRunStartedId'] as String? ?? '',
      hookId: json['hookId'] as String? ?? '',
      workerId: json['workerId'] as String?,
      timestamp: json['timestamp'] == null
          ? const Timestamp()
          : Timestamp.fromJson(json['timestamp'] as Map<String, Object?>),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['id'] = id;
    json['testRunStartedId'] = testRunStartedId;
    json['hookId'] = hookId;
    if (workerId != null) {
      json['workerId'] = workerId;
    }
    json['timestamp'] = timestamp.toJson();
    return json;
  }
}
