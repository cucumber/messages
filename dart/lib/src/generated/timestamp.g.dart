// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Timestamp message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Timestamp.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class Timestamp {
  /// Represents seconds of UTC time since Unix epoch
  /// 1970-01-01T00:00:00Z. Must be from 0001-01-01T00:00:00Z to
  /// 9999-12-31T23:59:59Z inclusive.
  final int seconds;
  /// Non-negative fractions of a second at nanosecond resolution. Negative
  /// second values with fractions must still have non-negative nanos values
  /// that count forward in time. Must be from 0 to 999,999,999
  /// inclusive.
  final int nanos;

  /// Creates an instance of [Timestamp].
  const Timestamp({
    required this.seconds,
    required this.nanos,
  });

  /// Creates an instance of [Timestamp] from a JSON object.
  factory Timestamp.fromJson(Map<String, Object?> json) {
    return Timestamp(
      seconds: (_requireJsonNumber(json, 'seconds') as num).toInt(),
      nanos: (_requireJsonNumber(json, 'nanos') as num).toInt(),
    );
  }

  /// Converts this [Timestamp] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['seconds'] = seconds;
    json['nanos'] = nanos;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Timestamp &&
          runtimeType == other.runtimeType &&
          seconds == other.seconds &&
          nanos == other.nanos;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        seconds,
        nanos,
      ]);

  @override
  String toString() =>
      'Timestamp{seconds: ${seconds}, nanos: ${nanos}}';
}

