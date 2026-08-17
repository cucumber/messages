// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [ParseError message](https://github.com/cucumber/messages/blob/main/jsonschema/src/ParseError.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class ParseError {
  /// The `source` property.
  final SourceReference source;
  /// The `message` property.
  final String message;

  /// Creates an instance of [ParseError].
  const ParseError({
    required this.source,
    required this.message,
  });

  /// Creates an instance of [ParseError] from a JSON object.
  factory ParseError.fromJson(Map<String, Object?> json) {
    return ParseError(
      source: SourceReference.fromJson(
              _requireJsonObject(json, 'source'),
            ),
      message: _requireJsonString(json, 'message'),
    );
  }

  /// Converts this [ParseError] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['source'] = source.toJson();
    json['message'] = message;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is ParseError &&
          runtimeType == other.runtimeType &&
          source == other.source &&
          message == other.message;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        source,
        message,
      ]);

  @override
  String toString() =>
      'ParseError{source: $source, message: $message}';
}

