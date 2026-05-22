// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestCaseStarted {
  final int attempt;
  final String id;
  final String testCaseId;
  final String? workerId;
  final Timestamp timestamp;

  const TestCaseStarted({
    required this.attempt,
    required this.id,
    required this.testCaseId,
    this.workerId,
    required this.timestamp,
  });

  factory TestCaseStarted.fromJson(Map<String, Object?> json) {
    return TestCaseStarted(
      attempt: (_requireJsonNumber(json, 'attempt') as num).toInt(),
      id: _requireJsonString(json, 'id'),
      testCaseId: _requireJsonString(json, 'testCaseId'),
      workerId: json['workerId'] as String?,
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['attempt'] = attempt;
    json['id'] = id;
    json['testCaseId'] = testCaseId;
    if (workerId != null) {
      json['workerId'] = workerId;
    }
    json['timestamp'] = timestamp.toJson();
    return json;
  }
}

