// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class DataTable {
  final Location location;
  final List<TableRow> rows;

  const DataTable({
    required this.location,
    required this.rows,
  });

  factory DataTable.fromJson(Map<String, Object?> json) {
    return DataTable(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      rows: _requireJsonList(json, 'rows')
              .map(
                (item) => TableRow.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['rows'] = rows.map((item) => item.toJson()).toList();
    return json;
  }
}

