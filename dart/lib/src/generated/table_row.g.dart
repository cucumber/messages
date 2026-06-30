// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [TableRow message](https://github.com/cucumber/messages/blob/main/jsonschema/src/TableRow.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
///
/// A row in a table
class TableRow {
  /// The location of the first cell in the row
  final Location location;
  /// Cells in the row
  final List<TableCell> cells;
  /// The `id` property.
  final String id;

  /// Creates an instance of [TableRow].
  const TableRow({
    required this.location,
    required this.cells,
    required this.id,
  });

  /// Creates an instance of [TableRow] from a JSON object.
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

  /// Converts this [TableRow] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['cells'] = cells.map((item) => item.toJson()).toList();
    json['id'] = id;
    return json;
  }
}

