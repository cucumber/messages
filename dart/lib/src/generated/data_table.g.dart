// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [DataTable message](https://github.com/cucumber/messages/blob/main/jsonschema/src/DataTable.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class DataTable {
  /// The `location` property.
  final Location location;
  /// The `rows` property.
  final List<TableRow> rows;

  /// Creates an instance of [DataTable].
  const DataTable({
    required this.location,
    required this.rows,
  });

  /// Creates an instance of [DataTable] from a JSON object.
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

  /// Converts this [DataTable] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['location'] = location.toJson();
    json['rows'] = rows.map((item) => item.toJson()).toList();
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is DataTable &&
          runtimeType == other.runtimeType &&
          location == other.location &&
          _listEquals(rows, other.rows);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        location,
        (rows == null ? null : Object.hashAll(rows!)),
      ]);

  @override
  String toString() =>
      'DataTable{location: ${location}, rows: ${rows}}';
}

