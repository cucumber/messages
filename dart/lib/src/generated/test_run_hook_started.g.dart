// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TestRunHookStarted message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestRunHookStarted.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestRunHookStarted {
  /// Unique identifier for this hook execution
  final String id;
  /// Identifier for the test run that this hook execution belongs to
  final String testRunStartedId;
  /// Identifier for the hook that will be executed
  final String hookId;
  /// An identifier for the worker process running this hook, if parallel workers are in use. The identifier will be unique per worker, but no particular format is defined - it could be an index, uuid, machine name etc - and as such should be assumed that it's not human readable.
  final String? workerId;
  /// The `timestamp` property.
  final Timestamp timestamp;

  /// Creates an instance of [TestRunHookStarted].
  const TestRunHookStarted({
    required this.id,
    required this.testRunStartedId,
    required this.hookId,
    this.workerId,
    required this.timestamp,
  });

  /// Creates an instance of [TestRunHookStarted] from a JSON object.
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

  /// Converts this [TestRunHookStarted] to a JSON object.
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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestRunHookStarted &&
          runtimeType == other.runtimeType &&
          id == other.id &&
          testRunStartedId == other.testRunStartedId &&
          hookId == other.hookId &&
          workerId == other.workerId &&
          timestamp == other.timestamp;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        id,
        testRunStartedId,
        hookId,
        workerId,
        timestamp,
      ]);

  @override
  String toString() =>
      'TestRunHookStarted{id: ${id}, testRunStartedId: ${testRunStartedId}, hookId: ${hookId}, workerId: ${workerId}, timestamp: ${timestamp}}';

  /// Creates a copy of this [TestRunHookStarted] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  TestRunHookStarted copyWith({
    String? id,
    String? testRunStartedId,
    String? hookId,
    String? workerId,
    Timestamp? timestamp,
  }) {
    return TestRunHookStarted(
      id: id ?? this.id,
      testRunStartedId: testRunStartedId ?? this.testRunStartedId,
      hookId: hookId ?? this.hookId,
      workerId: workerId ?? this.workerId,
      timestamp: timestamp ?? this.timestamp,
    );
  }
}

