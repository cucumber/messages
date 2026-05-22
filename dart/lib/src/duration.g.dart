// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Duration {
  final int seconds;
  final int nanos;

  const Duration({
    this.seconds = 0,
    this.nanos = 0,
  });

  factory Duration.fromJson(Map<String, Object?> json) {
    return Duration(
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

