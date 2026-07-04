// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Comment message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Comment.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A comment in a Gherkin document
class Comment {
  /// The location of the comment
  final Location location;
  /// The text of the comment
  final String text;

  /// Creates an instance of [Comment].
  const Comment({
    required this.location,
    required this.text,
  });

  /// Creates an instance of [Comment] from a JSON object.
  factory Comment.fromJson(Map<String, Object?> json) {
    return Comment(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      text: _requireJsonString(json, 'text'),
    );
  }

  /// Converts this [Comment] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['text'] = text;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Comment &&
          runtimeType == other.runtimeType &&
          location == other.location &&
          text == other.text;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        location,
        text,
      ]);

  @override
  String toString() =>
      'Comment{location: ${location}, text: ${text}}';

  /// Creates a copy of this [Comment] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  Comment copyWith({
    Location? location,
    String? text,
  }) {
    return Comment(
      location: location ?? this.location,
      text: text ?? this.text,
    );
  }
}

