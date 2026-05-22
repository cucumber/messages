// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Feature {
  final Location location;
  final List<Tag> tags;
  final String language;
  final String keyword;
  final String name;
  final String description;
  final List<FeatureChild> children;

  const Feature({
    required this.location,
    required this.tags,
    required this.language,
    required this.keyword,
    required this.name,
    required this.description,
    required this.children,
  });

  factory Feature.fromJson(Map<String, Object?> json) {
    return Feature(
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
      language: _requireJsonString(json, 'language'),
      keyword: _requireJsonString(json, 'keyword'),
      name: _requireJsonString(json, 'name'),
      description: _requireJsonString(json, 'description'),
      children: _requireJsonList(json, 'children')
              .map(
                (item) => FeatureChild.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['tags'] = tags.map((item) => item.toJson()).toList();
    json['language'] = language;
    json['keyword'] = keyword;
    json['name'] = name;
    json['description'] = description;
    json['children'] = children.map((item) => item.toJson()).toList();
    return json;
  }
}

