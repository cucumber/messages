// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Exception message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Exception.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A simplified representation of an exception
class Exception {
  /// The type of the exception that caused this result. E.g. "Error" or "org.opentest4j.AssertionFailedError"
  final String type;
  /// The message of exception that caused this result. E.g. expected: "a" but was: "b"
  final String? message;
  /// The stringified stack trace of the exception that caused this result
  final String? stackTrace;

  /// Creates an instance of [Exception].
  const Exception({
    required this.type,
    this.message,
    this.stackTrace,
  });

  /// Creates an instance of [Exception] from a JSON object.
  factory Exception.fromJson(Map<String, Object?> json) {
    return Exception(
      type: _requireJsonString(json, 'type'),
      message: json['message'] as String?,
      stackTrace: json['stackTrace'] as String?,
    );
  }

  /// Converts this [Exception] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['type'] = type;
    if (message != null) {
      json['message'] = message;
    }
    if (stackTrace != null) {
      json['stackTrace'] = stackTrace;
    }
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Exception &&
          runtimeType == other.runtimeType &&
          type == other.type &&
          message == other.message &&
          stackTrace == other.stackTrace;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        type,
        message,
        stackTrace,
      ]);

  @override
  String toString() =>
      'Exception{type: $type, message: $message, stackTrace: $stackTrace}';
}

