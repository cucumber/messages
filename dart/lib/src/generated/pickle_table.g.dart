// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Represents the PickleTable message in [Cucumber's message protocol](https://github.com/cucumber/messages).
class PickleTable {
  /// The `rows` property.
  final List<PickleTableRow> rows;

  /// Creates an instance of [PickleTable].
  const PickleTable({
    required this.rows,
  });

  /// Creates an instance of [PickleTable] from a JSON object.
  factory PickleTable.fromJson(Map<String, Object?> json) {
    return PickleTable(
      rows: _requireJsonList(json, 'rows')
              .map(
                (item) => PickleTableRow.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
    );
  }

  /// Converts this [PickleTable] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['rows'] = rows.map((item) => item.toJson()).toList();
    return json;
  }
}

