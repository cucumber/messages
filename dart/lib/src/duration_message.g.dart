// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class DurationMessage {
  final int seconds;
  final int nanos;

  const DurationMessage({
    this.seconds = 0,
    this.nanos = 0,
  });

  factory DurationMessage.fromJson(Map<String, Object?> json) {
    return DurationMessage(
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

