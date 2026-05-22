// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

class PickleTableRow {
  final List<PickleTableCell> cells;

  const PickleTableRow({
    required this.cells,
  });

  factory PickleTableRow.fromJson(Map<String, Object?> json) {
    return PickleTableRow(
      cells: _requireJsonList(json, 'cells')
              .map(
                (item) => PickleTableCell.fromJson(
                  item as Map<String, Object?>,
                ),
              )
              .toList(),
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['cells'] = cells.map((item) => item.toJson()).toList();
    return json;
  }
}

