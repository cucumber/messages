// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [Pickle message](https://github.com/cucumber/messages/blob/main/jsonschema/src/Pickle.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A `Pickle` represents a template for a `TestCase`. It is typically derived
/// from another format, such as [GherkinDocument](#io.cucumber.messages.GherkinDocument).
/// In the future a `Pickle` may be derived from other formats such as Markdown or
/// Excel files.
///
/// By making `Pickle` the main data structure Cucumber uses for execution, the
/// implementation of Cucumber itself becomes simpler, as it doesn't have to deal
/// with the complex structure of a [GherkinDocument](#io.cucumber.messages.GherkinDocument).
///
/// Each `PickleStep` of a `Pickle` is matched with a `StepDefinition` to create a `TestCase`
class Pickle {
  /// A unique id for the pickle
  final String id;
  /// The uri of the source file
  final String uri;
  /// The location of this pickle in source file. A pickle constructed from `Examples` will point to the example row.
  final Location? location;
  /// The name of the pickle
  final String name;
  /// The language of the pickle
  final String language;
  /// One or more steps
  final List<PickleStep> steps;
  /// One or more tags. If this pickle is constructed from a Gherkin document,
  /// It includes inherited tags from the `Feature` as well.
  final List<PickleTag> tags;
  /// Points to the AST node locations of the pickle. The last one represents the unique
  /// id of the pickle. A pickle constructed from `Examples` will have the first
  /// id originating from the `Scenario` AST node, and the second from the `TableRow` AST node.
  final List<String> astNodeIds;

  /// Creates an instance of [Pickle].
  const Pickle({
    required this.id,
    required this.uri,
    this.location,
    required this.name,
    required this.language,
    required this.steps,
    required this.tags,
    required this.astNodeIds,
  });

  /// Creates an instance of [Pickle] from a JSON object.
  factory Pickle.fromJson(Map<String, Object?> json) {
    return Pickle(
      id: _requireJsonString(json, 'id'),
      uri: _requireJsonString(json, 'uri'),
      location: json['location'] == null
          ? null
          : Location.fromJson(
              json['location'] as Map<String, Object?>,
            ),
      name: _requireJsonString(json, 'name'),
      language: _requireJsonString(json, 'language'),
      steps: _requireJsonList(json, 'steps')
              .map(
                (item) => PickleStep.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      tags: _requireJsonList(json, 'tags')
              .map(
                (item) => PickleTag.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      astNodeIds: _requireJsonList(json, 'astNodeIds')
              .map((item) => item as String)
              .toList(),
    );
  }

  /// Converts this [Pickle] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['id'] = id;
    json['uri'] = uri;
    if (location != null) {
      json['location'] = location!.toJson();
    }
    json['name'] = name;
    json['language'] = language;
    json['steps'] = steps.map((item) => item.toJson()).toList();
    json['tags'] = tags.map((item) => item.toJson()).toList();
    json['astNodeIds'] = astNodeIds;
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Pickle &&
          runtimeType == other.runtimeType &&
          id == other.id &&
          uri == other.uri &&
          location == other.location &&
          name == other.name &&
          language == other.language &&
          _listEquals(steps, other.steps) &&
          _listEquals(tags, other.tags) &&
          _listEquals(astNodeIds, other.astNodeIds);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        id,
        uri,
        location,
        name,
        language,
        Object.hashAll(steps),
        Object.hashAll(tags),
        Object.hashAll(astNodeIds),
      ]);

  @override
  String toString() =>
      'Pickle{id: $id, uri: $uri, location: $location, name: $name, language: $language, steps: $steps, tags: $tags, astNodeIds: $astNodeIds}';
}

