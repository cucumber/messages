// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [TestRunStarted message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TestRunStarted.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class TestRunStarted {
  /// The `timestamp` property.
  final Timestamp timestamp;
  /// The `id` property.
  final String? id;

  /// Creates an instance of [TestRunStarted].
  const TestRunStarted({
    required this.timestamp,
    this.id,
  });

  /// Creates an instance of [TestRunStarted] from a JSON object.
  factory TestRunStarted.fromJson(Map<String, Object?> json) {
    return TestRunStarted(
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
      id: json['id'] as String?,
    );
  }

  /// Converts this [TestRunStarted] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['timestamp'] = timestamp.toJson();
    if (id != null) {
      json['id'] = id;
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is TestRunStarted &&
          runtimeType == other.runtimeType &&
          timestamp == other.timestamp &&
          id == other.id;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        timestamp,
        id,
      ]);

  @override
  String toString() =>
      'TestRunStarted{timestamp: $timestamp, id: $id}';
}

