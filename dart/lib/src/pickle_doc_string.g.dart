// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class PickleDocString {
  final String? mediaType;
  final String content;

  const PickleDocString({
    this.mediaType,
    this.content = '',
  });

  factory PickleDocString.fromJson(Map<String, Object?> json) {
    return PickleDocString(
      mediaType: json['mediaType'] as String?,
      content: json['content'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (mediaType != null) {
      json['mediaType'] = mediaType;
    }
    json['content'] = content;
    return json;
  }
}
