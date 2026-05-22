// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Comment {
  final Location location;
  final String text;

  const Comment({
    required this.location,
    required this.text,
  });

  factory Comment.fromJson(Map<String, Object?> json) {
    return Comment(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      text: _requireJsonString(json, 'text'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['text'] = text;
    return json;
  }
}

