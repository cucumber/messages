// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class PickleTable {
  final List<PickleTableRow> rows;

  const PickleTable({
    required this.rows,
  });

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

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['rows'] = rows.map((item) => item.toJson()).toList();
    return json;
  }
}

