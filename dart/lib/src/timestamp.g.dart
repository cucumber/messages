// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class Timestamp {
  final int seconds;
  final int nanos;

  const Timestamp({this.seconds = 0, this.nanos = 0});

  factory Timestamp.fromJson(Map<String, Object?> json) {
    return Timestamp(
      seconds: (json['seconds'] as num?)?.toInt() ?? 0,
      nanos: (json['nanos'] as num?)?.toInt() ?? 0,
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['seconds'] = seconds;
    json['nanos'] = nanos;
    return json;
  }
}
