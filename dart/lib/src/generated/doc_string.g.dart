// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Represents the DocString message in [Cucumber's message protocol](https://github.com/cucumber/messages).
class DocString {
  /// The `location` property.
  final Location location;
  /// The `mediaType` property.
  final String? mediaType;
  /// The `content` property.
  final String content;
  /// The `delimiter` property.
  final String delimiter;

  /// Creates an instance of [DocString].
  const DocString({
    required this.location,
    this.mediaType,
    required this.content,
    required this.delimiter,
  });

  /// Creates an instance of [DocString] from a JSON object.
  factory DocString.fromJson(Map<String, Object?> json) {
    return DocString(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      mediaType: json['mediaType'] as String?,
      content: _requireJsonString(json, 'content'),
      delimiter: _requireJsonString(json, 'delimiter'),
    );
  }

  /// Converts this [DocString] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    if (mediaType != null) {
      json['mediaType'] = mediaType;
    }
    json['content'] = content;
    json['delimiter'] = delimiter;
    return json;
  }
}

