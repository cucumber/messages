// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class TestRunStarted {
  final Timestamp timestamp;
  final String? id;

  const TestRunStarted({
    this.timestamp = const Timestamp(),
    this.id,
  });

  factory TestRunStarted.fromJson(Map<String, Object?> json) {
    return TestRunStarted(
      timestamp: json['timestamp'] == null
          ? const Timestamp()
          : Timestamp.fromJson(
              json['timestamp'] as Map<String, Object?>,
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
