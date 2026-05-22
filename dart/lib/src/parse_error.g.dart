// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class ParseError {
  final SourceReference source;
  final String message;

  const ParseError({
    this.source = const SourceReference(),
    this.message = '',
  });

  factory ParseError.fromJson(Map<String, Object?> json) {
    return ParseError(
      source: json['source'] == null
          ? const SourceReference()
          : SourceReference.fromJson(
              json['source'] as Map<String, Object?>,
            ),
      message: json['message'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['source'] = source.toJson();
    json['message'] = message;
    return json;
  }
}

