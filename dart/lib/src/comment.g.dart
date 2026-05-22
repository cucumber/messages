// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Comment {
  final Location location;
  final String text;

  const Comment({
    this.location = const Location(),
    this.text = '',
  });

  factory Comment.fromJson(Map<String, Object?> json) {
    return Comment(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(
              json['location'] as Map<String, Object?>,
            ),
      text: json['text'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['text'] = text;
    return json;
  }
}

