// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class ParseError {
  final SourceReference source;
  final String message;

  const ParseError({
    required this.source,
    required this.message,
  });

  factory ParseError.fromJson(Map<String, Object?> json) {
    return ParseError(
      source: SourceReference.fromJson(
              _requireJsonObject(json, 'source'),
            ),
      message: _requireJsonString(json, 'message'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['source'] = source.toJson();
    json['message'] = message;
    return json;
  }
}

