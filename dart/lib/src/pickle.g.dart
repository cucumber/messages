// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Pickle {
  final String id;
  final String uri;
  final Location? location;
  final String name;
  final String language;
  final List<PickleStep> steps;
  final List<PickleTag> tags;
  final List<String> astNodeIds;

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
}

