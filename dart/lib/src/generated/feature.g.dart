// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Feature message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Feature.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class Feature {
  /// The location of the `Feature` keyword
  final Location location;
  /// All the tags placed above the `Feature` keyword
  final List<Tag> tags;
  /// The [ISO 639-1](https://en.wikipedia.org/wiki/ISO_639-1) language code of the Gherkin document
  final String language;
  /// The text of the `Feature` keyword (in the language specified by `language`)
  final String keyword;
  /// The name of the feature (the text following the `keyword`)
  final String name;
  /// The line(s) underneath the line with the `keyword` that are used as description
  final String description;
  /// Zero or more children
  final List<FeatureChild> children;

  /// Creates an instance of [Feature].
  const Feature({
    required this.location,
    required this.tags,
    required this.language,
    required this.keyword,
    required this.name,
    required this.description,
    required this.children,
  });

  /// Creates an instance of [Feature] from a JSON object.
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

  /// Converts this [Feature] to a JSON object.
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

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Feature &&
          runtimeType == other.runtimeType &&
          location == other.location &&
          _listEquals(tags, other.tags) &&
          language == other.language &&
          keyword == other.keyword &&
          name == other.name &&
          description == other.description &&
          _listEquals(children, other.children);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        location,
        Object.hashAll(tags),
        language,
        keyword,
        name,
        description,
        Object.hashAll(children),
      ]);

  @override
  String toString() =>
      'Feature{location: $location, tags: $tags, language: $language, keyword: $keyword, name: $name, description: $description, children: $children}';
}

