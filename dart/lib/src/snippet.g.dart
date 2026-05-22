// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class Snippet {
  final String language;
  final String code;

  const Snippet({
    this.language = '',
    this.code = '',
  });

  factory Snippet.fromJson(Map<String, Object?> json) {
    return Snippet(
      language: json['language'] as String? ?? '',
      code: json['code'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['language'] = language;
    json['code'] = code;
    return json;
  }
}

