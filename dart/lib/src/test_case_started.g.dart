// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

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
          : Timestamp.fromJson(json['timestamp'] as Map<String, Object?>),
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
