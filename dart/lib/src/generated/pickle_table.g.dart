// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Generated Dart representation of the [PickleTable message](https://github.com/cucumber/messages/blob/main/jsonschema/src/PickleTable.schema.json) in Cucumber's [message protocol](https://github.com/cucumber/messages).
class PickleTable {
  /// The `argumentIndex` property.
  final int? argumentIndex;
  /// The `rows` property.
  final List<PickleTableRow> rows;

  /// Creates an instance of [PickleTable].
  const PickleTable({
    this.argumentIndex,
    required this.rows,
  });

  /// Creates an instance of [PickleTable] from a JSON object.
  factory PickleTable.fromJson(Map<String, Object?> json) {
    return PickleTable(
      argumentIndex: (json['argumentIndex'] as num?)?.toInt(),
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
    if (argumentIndex != null) {
      json['argumentIndex'] = argumentIndex;
    }
    json['rows'] = rows.map((item) => item.toJson()).toList();
    return json;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is PickleTable &&
          runtimeType == other.runtimeType &&
          argumentIndex == other.argumentIndex &&
          _listEquals(rows, other.rows);

  @override
  int get hashCode => Object.hashAll(<Object?>[
        argumentIndex,
        (rows == null ? null : Object.hashAll(rows!)),
      ]);

  @override
  String toString() =>
      'PickleTable{argumentIndex: ${argumentIndex}, rows: ${rows}}';

  /// Creates a copy of this [PickleTable] with the given fields
  /// replaced by the given values. Fields left unspecified keep their current
  /// value.
  PickleTable copyWith({
    int? argumentIndex,
    List<PickleTableRow>? rows,
  }) {
    return PickleTable(
      argumentIndex: argumentIndex ?? this.argumentIndex,
      rows: rows ?? this.rows,
    );
  }
}

