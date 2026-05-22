// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TestRunStarted {
  final Timestamp timestamp;
  final String? id;

  const TestRunStarted({
    required this.timestamp,
    this.id,
  });

  factory TestRunStarted.fromJson(Map<String, Object?> json) {
    return TestRunStarted(
      timestamp: Timestamp.fromJson(
              _requireJsonObject(json, 'timestamp'),
            ),
      id: json['id'] as String?,
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['timestamp'] = timestamp.toJson();
    if (id != null) {
      json['id'] = id;
    }
    return json;
  }
}

