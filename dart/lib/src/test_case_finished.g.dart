// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestCaseFinished {
  final String testCaseStartedId;
  final Timestamp timestamp;
  final bool willBeRetried;

  const TestCaseFinished({
    this.testCaseStartedId = '',
    this.timestamp = const Timestamp(),
    this.willBeRetried = false,
  });

  factory TestCaseFinished.fromJson(Map<String, Object?> json) {
    return TestCaseFinished(
      testCaseStartedId: json['testCaseStartedId'] as String? ?? '',
      timestamp: json['timestamp'] == null
          ? const Timestamp()
          : Timestamp.fromJson(
              json['timestamp'] as Map<String, Object?>,
            ),
      willBeRetried: json['willBeRetried'] as bool? ?? false,
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['testCaseStartedId'] = testCaseStartedId;
    json['timestamp'] = timestamp.toJson();
    json['willBeRetried'] = willBeRetried;
    return json;
  }
}

