// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestCaseFinished {
  final String testCaseStartedId;
  final Timestamp timestamp;
  final bool willBeRetried;

  const TestCaseFinished({
    required this.testCaseStartedId,
    required this.timestamp,
    required this.willBeRetried,
  });

  factory TestCaseFinished.fromJson(Map<String, Object?> json) {
    return TestCaseFinished(
      testCaseStartedId: _requireJsonString(json, 'testCaseStartedId'),
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
      willBeRetried: _requireJsonBool(json, 'willBeRetried'),
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

