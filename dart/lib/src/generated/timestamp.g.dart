// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Timestamp {
  final int seconds;
  final int nanos;

  const Timestamp({
    required this.seconds,
    required this.nanos,
  });

  factory Timestamp.fromJson(Map<String, Object?> json) {
    return Timestamp(
      seconds: (_requireJsonNumber(json, 'seconds') as num).toInt(),
      nanos: (_requireJsonNumber(json, 'nanos') as num).toInt(),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['seconds'] = seconds;
    json['nanos'] = nanos;
    return json;
  }
}

