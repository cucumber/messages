// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// dart format off

part of 'messages.dart';

/// Represents the PickleTableRow message in [Cucumber's message protocol](https://github.com/cucumber/messages).
class PickleTableRow {
  /// The `cells` property.
  final List<PickleTableCell> cells;

  /// Creates an instance of [PickleTableRow].
  const PickleTableRow({
    required this.cells,
  });

  /// Creates an instance of [PickleTableRow] from a JSON object.
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

  /// Converts this [PickleTableRow] to a JSON object.
  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['cells'] = cells.map((item) => item.toJson()).toList();
    return json;
  }
}

