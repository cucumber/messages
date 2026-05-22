// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class PickleDocString {
  final String? mediaType;
  final String content;

  const PickleDocString({
    this.mediaType,
    required this.content,
  });

  factory PickleDocString.fromJson(Map<String, Object?> json) {
    return PickleDocString(
      mediaType: json['mediaType'] as String?,
      content: _requireJsonString(json, 'content'),
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

