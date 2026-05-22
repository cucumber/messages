// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

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
    this.id = '',
    this.uri = '',
    this.location,
    this.name = '',
    this.language = '',
    this.steps = const [],
    this.tags = const [],
    this.astNodeIds = const [],
  });

  factory Pickle.fromJson(Map<String, Object?> json) {
    return Pickle(
      id: json['id'] as String? ?? '',
      uri: json['uri'] as String? ?? '',
      location: json['location'] == null
          ? null
          : Location.fromJson(json['location'] as Map<String, Object?>),
      name: json['name'] as String? ?? '',
      language: json['language'] as String? ?? '',
      steps: (json['steps'] as List<Object?>?)
              ?.map((item) => PickleStep.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
      tags: (json['tags'] as List<Object?>?)
              ?.map((item) => PickleTag.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
      astNodeIds: (json['astNodeIds'] as List<Object?>?)
              ?.map((item) => item as String)
              .toList() ??
          const [],
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
