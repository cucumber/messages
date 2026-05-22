// This code was generated using the code generator from cucumber-messages.
// Manual changes will be lost if the code is regenerated.
// ignore_for_file: unnecessary_null_in_if_null_operators

part of 'messages.dart';

class PickleTableRow {
  final List<PickleTableCell> cells;

  const PickleTableRow({this.cells = const []});

  factory PickleTableRow.fromJson(Map<String, Object?> json) {
    return PickleTableRow(
      cells:
          (json['cells'] as List<Object?>?)
              ?.map(
                (item) =>
                    PickleTableCell.fromJson(item as Map<String, Object?>),
              )
              .toList() ??
          const [],
    );
  }

  Map<String, Object?> toJson() {
    final json = <String, Object?>{};
    json['cells'] = cells.map((item) => item.toJson()).toList();
    return json;
  }
}
