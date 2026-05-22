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
    this.attempt = 0,
    this.id = '',
    this.testCaseId = '',
    this.workerId,
    this.timestamp = const Timestamp(),
  });

  factory TestCaseStarted.fromJson(Map<String, Object?> json) {
    return TestCaseStarted(
      attempt: (json['attempt'] as num?)?.toInt() ?? 0,
      id: json['id'] as String? ?? '',
      testCaseId: json['testCaseId'] as String? ?? '',
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

