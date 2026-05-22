// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class Scenario {
  final Location location;
  final List<Tag> tags;
  final String keyword;
  final String name;
  final String description;
  final List<Step> steps;
  final List<Examples> examples;
  final String id;

  const Scenario({
    this.location = const Location(),
    this.tags = const [],
    this.keyword = '',
    this.name = '',
    this.description = '',
    this.steps = const [],
    this.examples = const [],
    this.id = '',
  });

  factory Scenario.fromJson(Map<String, Object?> json) {
    return Scenario(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(json['location'] as Map<String, Object?>),
      tags: (json['tags'] as List<Object?>?)
              ?.map((item) => Tag.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
      keyword: json['keyword'] as String? ?? '',
      name: json['name'] as String? ?? '',
      description: json['description'] as String? ?? '',
      steps: (json['steps'] as List<Object?>?)
              ?.map((item) => Step.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
      examples: (json['examples'] as List<Object?>?)
              ?.map((item) => Examples.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
      id: json['id'] as String? ?? '',
    );
  }

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
