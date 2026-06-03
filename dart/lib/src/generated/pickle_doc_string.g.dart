// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [PickleDocString message](https://github.com/cucumber/messages/blob/main/jsonschema/src/PickleDocString.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class PickleDocString {
  /// The `mediaType` property.
  final String? mediaType;
  /// The `content` property.
  final String content;

  /// Creates an instance of [PickleDocString].
  const PickleDocString({
    this.mediaType,
    required this.content,
  });

  /// Creates an instance of [PickleDocString] from a JSON object.
  factory PickleDocString.fromJson(Map<String, Object?> json) {
    return PickleDocString(
      mediaType: json['mediaType'] as String?,
      content: _requireJsonString(json, 'content'),
    );
  }

  /// Converts this [PickleDocString] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    if (mediaType != null) {
      json['mediaType'] = mediaType;
    }
    json['content'] = content;
    return json;
  }
}

