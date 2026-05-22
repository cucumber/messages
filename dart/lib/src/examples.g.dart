// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

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
    this.location = const Location(),
    this.tags = const [],
    this.keyword = '',
    this.name = '',
    this.description = '',
    this.tableHeader,
    this.tableBody = const [],
    this.id = '',
  });

  factory Examples.fromJson(Map<String, Object?> json) {
    return Examples(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(json['location'] as Map<String, Object?>),
      tags:
          (json['tags'] as List<Object?>?)
              ?.map((item) => Tag.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
      keyword: json['keyword'] as String? ?? '',
      name: json['name'] as String? ?? '',
      description: json['description'] as String? ?? '',
      tableHeader: json['tableHeader'] == null
          ? null
          : TableRow.fromJson(json['tableHeader'] as Map<String, Object?>),
      tableBody:
          (json['tableBody'] as List<Object?>?)
              ?.map((item) => TableRow.fromJson(item as Map<String, Object?>))
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
    if (tableHeader != null) {
      json['tableHeader'] = tableHeader!.toJson();
    }
    json['tableBody'] = tableBody.map((item) => item.toJson()).toList();
    json['id'] = id;
    return json;
  }
}
