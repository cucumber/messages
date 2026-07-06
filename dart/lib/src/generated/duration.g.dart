// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Duration message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Duration.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// The structure is pretty close of the Timestamp one. For clarity, a second type
/// of message is used.
class Duration {
  /// The `seconds` property.
  final int seconds;
  /// Non-negative fractions of a second at nanosecond resolution. Negative
  /// second values with fractions must still have non-negative nanos values
  /// that count forward in time. Must be from 0 to 999,999,999
  /// inclusive.
  final int nanos;

  /// Creates an instance of [Duration].
  const Duration({
    required this.seconds,
    required this.nanos,
  });

  /// Creates an instance of [Duration] from a JSON object.
  factory Duration.fromJson(Map<String, Object?> json) {
    return Duration(
      seconds: (_requireJsonNumber(json, 'seconds') as num).toInt(),
      nanos: (_requireJsonNumber(json, 'nanos') as num).toInt(),
    );
  }

  /// Converts this [Duration] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['seconds'] = seconds;
    json['nanos'] = nanos;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Duration &&
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
      'Duration{seconds: ${seconds}, nanos: ${nanos}}';
}

