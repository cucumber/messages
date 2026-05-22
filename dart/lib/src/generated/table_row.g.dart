// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class TableRow {
  final Location location;
  final List<TableCell> cells;
  final String id;

  const TableRow({
    required this.location,
    required this.cells,
    required this.id,
  });

  factory TableRow.fromJson(Map<String, Object?> json) {
    return TableRow(
      location: Location.fromJson(
              _requireJsonObject(json, 'location'),
            ),
      cells: _requireJsonList(json, 'cells')
              .map(
                (item) => TableCell.fromJson(
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
    json['cells'] = cells.map((item) => item.toJson()).toList();
    json['id'] = id;
    return json;
  }
}

