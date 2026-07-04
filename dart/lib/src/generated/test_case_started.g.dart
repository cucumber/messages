// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TestCaseStarted message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestCaseStarted.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestCaseStarted {
  /// The first attempt should have value 0, and for each retry the value
  /// should increase by 1.
  final int attempt;
  /// Because a `TestCase` can be run multiple times (in case of a retry),
  /// we use this field to group messages relating to the same attempt.
  final String id;
  /// The `testCaseId` property.
  final String testCaseId;
  /// An identifier for the worker process running this test case, if test cases are being run in parallel. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.
  final String? workerId;
  /// The `timestamp` property.
  final Timestamp timestamp;

  /// Creates an instance of [TestCaseStarted].
  const TestCaseStarted({
    required this.attempt,
    required this.id,
    required this.testCaseId,
    this.workerId,
    required this.timestamp,
  });

  /// Creates an instance of [TestCaseStarted] from a JSON object.
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

  /// Converts this [TestCaseStarted] to a JSON object.
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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestCaseStarted &&
          runtimeType == other.runtimeType &&
          attempt == other.attempt &&
          id == other.id &&
          testCaseId == other.testCaseId &&
          workerId == other.workerId &&
          timestamp == other.timestamp;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        attempt,
        id,
        testCaseId,
        workerId,
        timestamp,
      ]);

  @override
  String toString() =>
      'TestCaseStarted{attempt: ${attempt}, id: ${id}, testCaseId: ${testCaseId}, workerId: ${workerId}, timestamp: ${timestamp}}';

  /// Creates a copy of this [TestCaseStarted] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  TestCaseStarted copyWith({
    int? attempt,
    String? id,
    String? testCaseId,
    String? workerId,
    Timestamp? timestamp,
  }) {
    return TestCaseStarted(
      attempt: attempt ?? this.attempt,
      id: id ?? this.id,
      testCaseId: testCaseId ?? this.testCaseId,
      workerId: workerId ?? this.workerId,
      timestamp: timestamp ?? this.timestamp,
    );
  }
}

