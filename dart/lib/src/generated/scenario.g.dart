// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Scenario message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Scenario.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class Scenario {
  /// The location of the `Scenario` keyword
  final Location location;
  /// The `tags` property.
  final List<Tag> tags;
  /// The `keyword` property.
  final String keyword;
  /// The `name` property.
  final String name;
  /// The `description` property.
  final String description;
  /// The `steps` property.
  final List<Step> steps;
  /// The `examples` property.
  final List<Examples> examples;
  /// The `id` property.
  final String id;

  /// Creates an instance of [Scenario].
  const Scenario({
    required this.location,
    required this.tags,
    required this.keyword,
    required this.name,
    required this.description,
    required this.steps,
    required this.examples,
    required this.id,
  });

  /// Creates an instance of [Scenario] from a JSON object.
  factory Scenario.fromJson(Map<String, Object?> json) {
    return Scenario(
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
      steps: _requireJsonList(json, 'steps')
              .map(
                (item) => Step.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      examples: _requireJsonList(json, 'examples')
              .map(
                (item) => Examples.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      id: _requireJsonString(json, 'id'),
    );
  }

  /// Converts this [Scenario] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['tags'] = tags.map((item) => item.toJson()).toList();
    json['keyword'] = keyword;
    json['name'] = name;
    json['description'] = description;
    json['steps'] = steps.map((item) => item.toJson()).toList();
    json['examples'] = examples.map((item) => item.toJson()).toList();
    json['id'] = id;
    return json;
  }
}

