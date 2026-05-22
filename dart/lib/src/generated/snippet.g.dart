// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Snippet {
  final String language;
  final String code;

  const Snippet({
    required this.language,
    required this.code,
  });

  factory Snippet.fromJson(Map<String, Object?> json) {
    return Snippet(
      language: _requireJsonString(json, 'language'),
      code: _requireJsonString(json, 'code'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['language'] = language;
    json['code'] = code;
    return json;
  }
}

