// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Represents the Examples message in [Cucumber's message protocol](https://github.com/cucumber/messages).
class Examples {
  /// The location of the `Examples` keyword
  final Location location;
  /// The `tags` property.
  final List<Tag> tags;
  /// The `keyword` property.
  final String keyword;
  /// The `name` property.
  final String name;
  /// The `description` property.
  final String description;
  /// The `tableHeader` property.
  final TableRow? tableHeader;
  /// The `tableBody` property.
  final List<TableRow> tableBody;
  /// The `id` property.
  final String id;

  /// Creates an instance of [Examples].
  const Examples({
    required this.location,
    required this.tags,
    required this.keyword,
    required this.name,
    required this.description,
    this.tableHeader,
    required this.tableBody,
    required this.id,
  });

  /// Creates an instance of [Examples] from a JSON object.
  factory Examples.fromJson(Map<String, Object?> json) {
    return Examples(
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
      tableHeader: json['tableHeader'] == null
          ? null
          : TableRow.fromJson(
              json['tableHeader'] as Map<String, Object?>,
            ),
      tableBody: _requireJsonList(json, 'tableBody')
              .map(
                (item) => TableRow.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
      id: _requireJsonString(json, 'id'),
    );
  }

  /// Converts this [Examples] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['tags'] = tags.map((item) => item.toJson()).toList();
    json['keyword'] = keyword;
    json['name'] = name;
    json['description'] = description;
    if (tableHeader != null) {
      json['tableHeader'] = tableHeader!.toJson();
    }
    json['tableBody'] = tableBody.map((item) => item.toJson()).toList();
    json['id'] = id;
    return json;
  }
}

