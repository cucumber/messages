// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class Tag {
  final Location location;
  final String name;
  final String id;

  const Tag({this.location = const Location(), this.name = '', this.id = ''});

  factory Tag.fromJson(Map<String, Object?> json) {
    return Tag(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(json['location'] as Map<String, Object?>),
      name: json['name'] as String? ?? '',
      id: json['id'] as String? ?? '',
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
