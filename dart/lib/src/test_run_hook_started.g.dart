// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestRunHookStarted {
  final String id;
  final String testRunStartedId;
  final String hookId;
  final String? workerId;
  final Timestamp timestamp;

  const TestRunHookStarted({
    required this.id,
    required this.testRunStartedId,
    required this.hookId,
    this.workerId,
    required this.timestamp,
  });

  factory TestRunHookStarted.fromJson(Map<String, Object?> json) {
    return TestRunHookStarted(
      id: _requireJsonString(json, 'id'),
      testRunStartedId: _requireJsonString(json, 'testRunStartedId'),
      hookId: _requireJsonString(json, 'hookId'),
      workerId: json['workerId'] as String?,
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
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

