// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Rule {
  final Location location;
  final List<Tag> tags;
  final String keyword;
  final String name;
  final String description;
  final List<RuleChild> children;
  final String id;

  const Rule({
    required this.location,
    required this.tags,
    required this.keyword,
    required this.name,
    required this.description,
    required this.children,
    required this.id,
  });

  factory Rule.fromJson(Map<String, Object?> json) {
    return Rule(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      tags: _requireJsonList(json, 'tags')
              .map(
                (item) => Tag.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      keyword: _requireJsonString(json, 'keyword'),
      name: _requireJsonString(json, 'name'),
      description: _requireJsonString(json, 'description'),
      children: _requireJsonList(json, 'children')
              .map(
                (item) => RuleChild.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      id: _requireJsonString(json, 'id'),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['tags'] = tags.map((item) => item.toJson()).toList();
    json['keyword'] = keyword;
    json['name'] = name;
    json['description'] = description;
    json['children'] = children.map((item) => item.toJson()).toList();
    json['id'] = id;
    return json;
  }
}

