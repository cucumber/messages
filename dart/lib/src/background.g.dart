// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Background {
  final Location location;
  final String keyword;
  final String name;
  final String description;
  final List<Step> steps;
  final String id;

  const Background({
    required this.location,
    required this.keyword,
    required this.name,
    required this.description,
    required this.steps,
    required this.id,
  });

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
}

