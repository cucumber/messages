// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Represents the Rule message in [Cucumber's message protocol](https://github.com/cucumber/messages).
class Rule {
  /// The location of the `Rule` keyword
  final Location location;
  /// All the tags placed above the `Rule` keyword
  final List<Tag> tags;
  /// The `keyword` property.
  final String keyword;
  /// The `name` property.
  final String name;
  /// The `description` property.
  final String description;
  /// The `children` property.
  final List<RuleChild> children;
  /// The `id` property.
  final String id;

  /// Creates an instance of [Rule].
  const Rule({
    required this.location,
    required this.tags,
    required this.keyword,
    required this.name,
    required this.description,
    required this.children,
    required this.id,
  });

  /// Creates an instance of [Rule] from a JSON object.
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

  /// Converts this [Rule] to a JSON object.
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

