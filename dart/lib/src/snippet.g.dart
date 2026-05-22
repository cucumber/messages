// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class Snippet {
  final String language;
  final String code;

  const Snippet({this.language = '', this.code = ''});

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
