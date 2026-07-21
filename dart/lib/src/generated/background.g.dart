// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.g.dart';

/// Generated Dart representation of the [Background message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Background.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class Background {
  /// The location of the `Background` keyword
  final Location location;
  /// The `keyword` property.
  final String keyword;
  /// The `name` property.
  final String name;
  /// The `description` property.
  final String description;
  /// The `steps` property.
  final List<Step> steps;
  /// The `id` property.
  final String id;

  /// Creates an instance of [Background].
  const Background({
    required this.location,
    required this.keyword,
    required this.name,
    required this.description,
    required this.steps,
    required this.id,
  });

  /// Creates an instance of [Background] from a JSON object.
  factory Background.fromJson(Map<String, Object?> json) {
    return Background(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
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
      id: _requireJsonString(json, 'id'),
    );
  }

  /// Converts this [Background] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['keyword'] = keyword;
    json['name'] = name;
    json['description'] = description;
    json['steps'] = steps.map((item) => item.toJson()).toList();
    json['id'] = id;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Background &&
          runtimeType == other.runtimeType &&
          location == other.location &&
          keyword == other.keyword &&
          name == other.name &&
          description == other.description &&
          _listEquals(steps, other.steps) &&
          id == other.id;

  @override
  int get hashCode => Object.hashAll(<Object?>[
        location,
        keyword,
        name,
        description,
        Object.hashAll(steps),
        id,
      ]);

  @override
  String toString() =>
      'Background{location: $location, keyword: $keyword, name: $name, description: $description, steps: $steps, id: $id}';
}

