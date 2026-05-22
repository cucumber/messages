// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: cast_nullable_to_non_nullable, public_member_api_docs
// ignore_for_file: sort_constructors_first
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class DataTable {
  final Location location;
  final List<TableRow> rows;

  const DataTable({this.location = const Location(), this.rows = const []});

  factory DataTable.fromJson(Map<String, Object?> json) {
    return DataTable(
      location: json['location'] == null
          ? const Location()
          : Location.fromJson(json['location'] as Map<String, Object?>),
      rows: (json['rows'] as List<Object?>?)
              ?.map((item) => TableRow.fromJson(item as Map<String, Object?>))
              .toList() ??
          const [],
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['rows'] = rows.map((item) => item.toJson()).toList();
    return json;
  }
}
