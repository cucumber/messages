// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class Examples {
  final Location location;
  final List<Tag> tags;
  final String keyword;
  final String name;
  final String description;
  final TableRow? tableHeader;
  final List<TableRow> tableBody;
  final String id;

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

