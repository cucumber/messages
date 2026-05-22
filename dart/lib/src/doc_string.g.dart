// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.

part of 'messages.dart';

class DocString {
  final Location location;
  final String? mediaType;
  final String content;
  final String delimiter;

  const DocString({
    this.location = const Location(),
    this.mediaType,
    this.content = '',
    this.delimiter = '',
  });

  factory DocString.fromJson(Map<String, Object?> json) {
    return DocString(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(
              json['location'] as Map<String, Object?>,
            ),
      mediaType: json['mediaType'] as String?,
      content: json['content'] as String? ?? '',
      delimiter: json['delimiter'] as String? ?? '',
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

