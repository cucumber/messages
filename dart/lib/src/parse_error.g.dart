// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class ParseError {
  final SourceReference source;
  final String message;

  const ParseError({this.source = const SourceReference(), this.message = ''});

  factory ParseError.fromJson(Map<String, Object?> json) {
    return ParseError(
      source: json['source'] == null
          ? const SourceReference()
          : SourceReference.fromJson(json['source'] as Map<String, Object?>),
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
