// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Tag message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Tag.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A tag
class Tag {
  /// Location of the tag
  final Location location;
  /// The name of the tag (including the leading `@`)
  final String name;
  /// Unique ID to be able to reference the Tag from PickleTag
  final String id;

  /// Creates an instance of [Tag].
  const Tag({
    required this.location,
    required this.name,
    required this.id,
  });

  /// Creates an instance of [Tag] from a JSON object.
  factory Tag.fromJson(Map<String, Object?> json) {
    return Tag(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      name: _requireJsonString(json, 'name'),
      id: _requireJsonString(json, 'id'),
    );
  }

  /// Converts this [Tag] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['name'] = name;
    json['id'] = id;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Tag &&
          runtimeType == other.runtimeType &&
          location == other.location &&
          name == other.name &&
          id == other.id;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        location,
        name,
        id,
      ]);

  @override
  String toString() =>
      'Tag{location: ${location}, name: ${name}, id: ${id}}';
}

