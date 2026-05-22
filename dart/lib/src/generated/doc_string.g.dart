// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class DocString {
  final Location location;
  final String? mediaType;
  final String content;
  final String delimiter;

  const DocString({
    required this.location,
    this.mediaType,
    required this.content,
    required this.delimiter,
  });

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

