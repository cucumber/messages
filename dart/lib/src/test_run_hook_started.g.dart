// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

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
          : Timestamp.fromJson(
              json['timestamp'] as Map<String, Object?>,
            ),
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

