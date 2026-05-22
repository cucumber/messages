// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class TableRow {
  final Location location;
  final List<TableCell> cells;
  final String id;

  const TableRow({
    this.location = const Location(),
    this.cells = const [],
    this.id = '',
  });

  factory TableRow.fromJson(Map<String, Object?> json) {
    return TableRow(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(json['location'] as Map<String, Object?>),
      cells: (json['cells'] as List<Object?>?)
              ?.map((item) => TableCell.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
      id: json['id'] as String? ?? '',
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['cells'] = cells.map((item) => item.toJson()).toList();
    json['id'] = id;
    return json;
  }
}
