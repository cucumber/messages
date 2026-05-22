// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Tag {
  final Location location;
  final String name;
  final String id;

  const Tag({
    required this.location,
    required this.name,
    required this.id,
  });

  factory Tag.fromJson(Map<String, Object?> json) {
    return Tag(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      name: _requireJsonString(json, 'name'),
      id: _requireJsonString(json, 'id'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['name'] = name;
    json['id'] = id;
    return json;
  }
}

