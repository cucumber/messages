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
    this.location = const Location(),
    this.tags = const [],
    this.language = '',
    this.keyword = '',
    this.name = '',
    this.description = '',
    this.children = const [],
  });

  factory Feature.fromJson(Map<String, Object?> json) {
    return Feature(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(
              json['location'] as Map<String, Object?>,
            ),
      tags: (json['tags'] as List<Object?>?)
              ?.map(
                (item) => Tag.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList() ??
          const [],
      language: json['language'] as String? ?? '',
      keyword: json['keyword'] as String? ?? '',
      name: json['name'] as String? ?? '',
      description: json['description'] as String? ?? '',
      children: (json['children'] as List<Object?>?)
              ?.map(
                (item) => FeatureChild.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList() ??
          const [],
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

